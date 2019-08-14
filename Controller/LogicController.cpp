#include "LogicController.h"
#include "Tool/TranslationES.h"
#include "Tool/VarType.h"
#include "Tool/EFStructDefineLoad.h"
#include "Tool/Data.h"
#include "Tool/Var.h"

#include "View/NXDockWidget.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <Windows.h>
#include "savewoker.h"
#include <QDir>
#include <QMessageBox>
#include <QPainter>
#include "View/Login.h"
#include "EFComm/Unity/IOStruct.h"

#include "Model/DefectBtnModel.h"
#include "WorkerOriSave.h"
#include "Model/DLClientInterface.h"

#include "woker.h"
#include "ExcelThread.h"
#include "AiExcelThread.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#pragma execution_character_set("utf-8")

LogicController::LogicController(QObject *parent) : QObject(parent)
  ,m_ElImage(600*6+15,600*2,QImage::Format_RGB888)
  ,m_bElCamOver(false)
  ,m_pDebugController(nullptr)
{
    code_num = 0;
    lastHour = QTime::currentTime().hour();

    //    //20190802
    //    int EL_zoomw12 = m_pAlg230->Algimg_zoomw12(&m_ELData);
    //    m_ElImage = QImage(EL_zoomw12, 1200, QImage::Format_RGB888);
    m_ElImage.fill(QColor(0, 0, 0));
    m_pVELCahceImages.resize(4,nullptr);

    elCmdTimer = new QTimer;
    connect(elCmdTimer, SIGNAL(timeout()),this,SLOT(OnAidefect()));

    for(int i = 0; i < 4; ++i)
    {
        m_pVELCahceImages[i] = new char[1920*1200];
    }
    connect(&DLClientInterface::Instance(), SIGNAL(sig_Img(QImage,bool,vector<string>,vector<string>,int,vector<string>)),
            this, SLOT(SlotImage(QImage,bool,vector<string>,vector<string>,int,vector<string>)));
    connect(&DLClientInterface::Instance(), SIGNAL(sig_Ai_error()), this, SLOT(slot_Ai_error()));

}

bool LogicController::OnInit(EFIFxComModule *pCom, EFILogModule *pLog, EFIMindVisionCameraModule *pMV, EFIAlg230WModule *p230)
{
    if(!pCom || !pLog || !pMV || !p230)
        return false;

    m_pFxComModule = pCom;
    m_pLog = pLog;
    m_pMVModule = pMV;
    m_pAlg230 = p230;
    m_pMVModule->Change_CameraModule(MindVision);
    //m_FtpHelper.OnInit();


    //数据初始化
    InitModel();
    //界面初始化
    InitView();

    //控制关系绑定
    InitController();


    return true;
}

bool LogicController::OnExecute()
{


    OnCheckState();

    return true;
}

bool LogicController::OnStart()
{

    m_nState = CHECK_FREE;
    StopLogic();
    StartLogic();
    //  m_ScanObj.GetCode();

    return true;
}

bool LogicController::OnStop(bool bCall)
{
    m_nState = CHECK_FREE;
    StopLogic();
    if(!bCall)
    {
        m_ELUIObj.OnUpdateStartBtn(false);
    }
    return true;
}

//获取数据
ControlModel * LogicController::OnGetModel()
{
    return &m_SystemModel;
}

bool LogicController::OnLoadFile(const string &str)
{
    m_strFilePath = str;
    m_SystemModel.Close();
    //加载默认配置
    m_SystemModel.OnLoad(m_strFilePath.c_str());

    //参数生效
    InitParams();
    m_ELUIObj.InitModel();

    return true;
}

void LogicController::OnHasBarCode()
{
    //获取条码检测是否好坏
    std::string  strBarCode =  m_ELUIObj.GetBarCode();

    if(strBarCode.empty())
        return ;

    {
        //田洪松
        //添加条码放入vector
        m_nState = CHECK_BEGIN;
        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "STATE:", "");
        OnQueryPhoto1();
        m_nELCurHeight = 0;
    }
}

void LogicController::OnSaveOriginalEL()
{
    WorkerOriSave * pWorker = new WorkerOriSave(this, true);
    connect(pWorker, SIGNAL(finished()), pWorker, SLOT(deleteLater()));
    pWorker->start();
}

QString LogicController::OnGetELPath()
{
    Data * pObj = m_SystemModel.GetObj();
    if(!pObj)
        return "";

    QString  strELPath= pObj->GetValue("EL_SAVE_DIR").GetString();

    return strELPath;
}

void LogicController::OnSetCode(QString strCode)
{
    m_strCode = strCode.toStdString();
}

void LogicController::OnDisableBtn()
{
    int EL_zoomw12 = m_pAlg230->Algimg_zoomw12(&m_ELData);


    m_ElImage = QImage(EL_zoomw12, 1200, QImage::Format_RGB888);
    m_ElImage.fill(QColor(0, 0, 0));

    m_pMVModule->OnAsynGrab();
}

void LogicController::OnShow(int nPermiss)
{
    m_nPermission = nPermiss;
    m_ELUIObj.Show();
}

void LogicController::OnUser(const string &strUser)
{
    m_MesObj.Login(strUser);
}

void LogicController::OnShowDebugDlg(const char *filepath)
{
    if(m_nPermission == 1)
    {
        Login login;
        int nRet = login.exec();
        if(nRet == 1)
        {
            //权限不够
            QMessageBox::information(NULL, "Title", TranslationES::Instance().GetTr("NoPermission"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        }
        else if(nRet == 2)
        {
            m_nPermission = 2;
            m_pDebugController->OnShow(filepath,this);
        }
        return ;

    }

    m_pDebugController->OnShow(filepath,this);
}

void LogicController::InitModel()
{


    TranslationES::Instance().SetFilePath("ModuleConfig/Translation.xml", ET_GBK);
    TranslationES::Instance().LoadTr();

    DefectBtnModel::Instance();

    //先登入
    // m_MesObj.Login("116780");
    //默认状态
    m_nState = CHECK_FREE;

}


void LogicController::InitView()
{

    m_pDebugController = new DebugController;
    m_pDebugController->OnInitAlg(nullptr, m_pAlg230);

}

void LogicController::InitController()
{


    m_ELUIObj.SetController(this);
    DefectBtnModel & db = DefectBtnModel::Instance();
    m_MesClient.OnInit(db.m_ftpAddr,db.m_strCenterWork,db.m_TestData,db.m_Url);

    //绑定
    connect(&m_CamCheckTimer,SIGNAL(timeout()), this, SLOT(slot_CamCheck_timer()));
    connect(this, SIGNAL(sig_el_img_over(int)), this, SLOT(slot_el_img_over(int)),Qt::QueuedConnection);
    //connect(this, SIGNAL(sig_lk_img_over(int)), this, SLOT(slot_lk_img_over(int)),Qt::QueuedConnection);
    connect(this, SIGNAL(sig_ImageOver()), this, SLOT(slot_ImageOver()),Qt::QueuedConnection);
    connect(this, SIGNAL(sig_camera_el_online(bool)), this, SLOT(slot_camera_el_online(bool)),Qt::QueuedConnection);
    // connect(this, SIGNAL(sig_camera_look_online(bool)), this, SLOT(slot_camera_look_online(bool)),Qt::QueuedConnection);

    //绑定条码枪回调
    // connect(&m_ScanObj, SIGNAL(Sig_Code(QString)), this, SLOT(slot_ScanCode(QString)));
}

//算法模块初始化
void LogicController::InitAlg()
{
    m_mELRegs = m_SystemModel.OnGetELRegs();

    m_ELData.Clear();
    m_ELData = *m_SystemModel.GetObj();
    m_ELData.SetAttribute("rects", &m_mELRegs);
    m_ELData.SetAttribute("ModuleLog", m_pLog);
    m_ELData.SetAttribute("DrawImage", &m_ElImage);
    m_ELData.SetAttribute("PaintImage", &m_DrawElImage);
    m_ELData.SetAttribute("Logic", this);
    m_ELData.SetAttribute("EL1", &m_EL1);
    m_ELData.SetAttribute("EL2", &m_EL2);
    m_ELData.SetAttribute("EL3", &m_EL3);
}

bool LogicController::StartLogic()
{
    m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "system [start]", "");

    // m_ELUIObj.OnUpdateStartBtn(true);

    OnLoadFile(m_strFilePath);
    //相机打开
    onMvCamBind();

    //PLC打开
    m_ELUIObj.OnPlcState( m_pFxComModule->OpenCom("COM1"));
    Data * pObj = m_SystemModel.GetObj();


    //打开条码枪
    // m_ScanObj.OpenCom("COM1");
    m_ELUIObj.EditBarCode();
    //初始化算法
    InitAlg();

    //下拉框禁止
    m_ELUIObj.OnEnableSystem(false);

    //开启相机检定时器
    m_CamCheckTimer.start(5000);

    AI_EL_num = 1;
    AI_EL_NGnum = 1;
    AI_EL_makdir = true;
    AI_EL_NGmakdir = true;

    //    m_AI_btn = false;//默认：AI自动按下OKNG标记

    //20190802
    int EL_zoomw12 = m_pAlg230->Algimg_zoomw12(&m_ELData);
    m_ElImage = QImage(EL_zoomw12, 1200, QImage::Format_RGB888);
    m_ElImage.fill(QColor(0, 0, 0));


    return true;
}

bool LogicController::StopLogic()
{
    m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "system [stop]", "");


    //关闭检测相机定时器
    m_CamCheckTimer.stop();

    //相机停止
    // m_pFlyCamModule->OnReleaseCams();
    m_pMVModule->OnRelease();

    //PLC关闭
    m_pFxComModule->CloseCom();


    m_ELUIObj.OnELCamState(false);
    m_ELUIObj.OnPlcState(false);

    //关闭数据
    m_SystemModel.Reload();

    //激活
    m_ELUIObj.OnEnableSystem(true);


    return true;
}

bool LogicController::InitParams()
{
    Data * pObj =  m_SystemModel.GetObj();

    if(pObj)
    {
        //        std::string str = pObj->GetValue("PLC_V").GetString();
        //        m_bFlow =  str!="FALSE";

        //        std::string strMesID =pObj->GetValue("user_mes_id").GetString();
        //        if(!strMesID.empty())
        //        {
        //          //  m_MesObj.Login(strMesID);
        //        }
    }

    return true;
}

void LogicController::TestDrawEL(vector<void *> buffers)
{

    int nIndex = 0;
        vector<void *>  CahceImags;
    //    Data * pObj = m_SystemModel.GetObj();
    //    //    if(pObj->GetValue("EL_VerFilp").GetString() == std::string("TRUE"))
    //    //    {
    //    //        //垂直翻转
    //    //        VerFilp(buffers);
    //    //    }
        if(1)
        {

            for(int i = 0; i < buffers.size(); ++i)
            {
                if(!m_pVELCahceImages[nIndex*4+i])
                {
                    m_pVELCahceImages[nIndex*4+i] = new char[1920*1200];
                }

                memcpy(m_pVELCahceImages[nIndex*4+i],buffers[i],1920*1200);
                CahceImags.push_back(m_pVELCahceImages[nIndex*4+i]);
            }
        }
    //    //调试模式
    if(m_pDebugController->IsActive())
    {
        m_pDebugController->OnLoadImageEL(buffers, nIndex);
    }
    else
    {

        //直接显示

        //正常模式
        m_ELData.SetAttribute("row", nIndex);
        m_ELData.SetAttribute("code",m_ELUIObj.GetBarCode().c_str());

        // m_pDebugController->OnLoadImageEL(buffers,nIndex);

        //        ofstream outf;
        //        outf.open("abc.txt");
        //        outf<<"pWorker"<<endl;
        Woker * pWorker = new Woker(buffers, &m_ELData);


        QThread::Priority nP = QThread::InheritPriority;
        if(nIndex == 1)
        {
            nP = QThread::TimeCriticalPriority;
        }
        else if (nIndex == 2)
        {
            nP = QThread::HighestPriority;
        }

        //        //ofstream outf;
        //        outf.open("abc.txt");
        //        outf<<"start"<<endl;
        //        outf.close();
        connect(pWorker,SIGNAL(resultReady(int)), this, SLOT(slot_ELAlgOK(int)),Qt::QueuedConnection);
        connect(pWorker, SIGNAL(finished()), pWorker, SLOT(deleteLater()));
        pWorker->start(nP);
    }
}

void LogicController::OnDrawELImage(int nIndex)
{
    vector<void*> buffers = m_pMVModule->OnImages();
    //    ofstream outf;
    //    outf.open("abc.txt");
    //    outf<<"OnDrawELImage"<<endl;
    //    outf.close();
    //    Data * pObj = m_SystemModel.GetObj();
    //    //图片垂直翻转
    //    if(pObj->GetValue("EL_vertical").GetString() == std::string("TRUE"))
    //    {
    //        //垂直翻转
    //        VerFilp(buffers);
    //    }
    //    if(pObj->GetValue("EL_Hor").GetString() == std::string("TRUE"))
    //    {
    //        //水平翻转
    //        HorFilp(buffers);
    //    }
    //    //拷贝图片

        vector<void *>  CahceImags;
        if(1)
        {

            for(int i = 0; i < buffers.size(); ++i)
            {
                if(!m_pVELCahceImages[nIndex*4+i])
                {
                    m_pVELCahceImages[nIndex*4+i] = new char[1920*1200];
                }

                memcpy(m_pVELCahceImages[nIndex*4+i], buffers[i], 1920*1200);
                CahceImags.push_back(m_pVELCahceImages[nIndex*4+i]);
            }
        }

    nIndex = 0;
    //    //调试模式
    if(m_pDebugController->IsActive())
    {
        m_pDebugController->OnLoadImageEL(buffers, nIndex);
    }
    else
    {

        //直接显示

        //正常模式
        m_ELData.SetAttribute("row", nIndex);
        m_ELData.SetAttribute("code", m_ELUIObj.GetBarCode().c_str());

        // m_pDebugController->OnLoadImageEL(buffers,nIndex);

        //        ofstream outf;
        //        outf.open("abc.txt");
        //        outf<<"pWorker"<<endl;
        Woker * pWorker = new Woker(buffers, &m_ELData);


        QThread::Priority nP = QThread::InheritPriority;
        if(nIndex == 1)
        {
            nP = QThread::TimeCriticalPriority;
        }
        else if (nIndex == 2)
        {
            nP = QThread::HighestPriority;
        }

        //        //ofstream outf;
        //        outf.open("abc.txt");
        //        outf<<"start"<<endl;
        //        outf.close();
        connect(pWorker,SIGNAL(resultReady(int)), this, SLOT(slot_ELAlgOK(int)), Qt::QueuedConnection);
        connect(pWorker, SIGNAL(finished()), pWorker, SLOT(deleteLater()));
        pWorker->start(nP);
    }

    //設置OK NG按鈕可點擊 lil
    // m_ELUIObj.OnEnableBtn(true);
}

//获取图像保存路径
string LogicController::GetSavePath(const string &strPrex, const string &strClass, int nCmd, bool bEL, const string & header)
{
    QString strPath = strPrex.c_str();

    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
        {
            QMessageBox::information(0,tr("not dir"),strPath);
            return "";
        }
    }
    strPath += "/";
    QDate  date = QDate::currentDate();
    QTime  time = QTime::currentTime();

    //夜班
    if(time.hour() <8)
    {
        date= date.addDays(-1);
    }

    QString strDate = date.toString("yyyyMMdd");
    strPath += strDate;
    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
        {
            QMessageBox::information(0,tr("not dir"),strPath);
            return "";
        }
    }

    strPath += "/";
    if(strClass.empty())
    {
        strPath += "A";
    }
    else
    {
        strPath += strClass.c_str();
    }
    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
        {
            QMessageBox::information(0,tr("not dir"),strPath);
            return "";
        }
    }
    strPath += "/"; //分AB串保存
    strPath += m_SAB;
    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
        {
            QMessageBox::information(0,tr("not dir"),strPath);
            return "";
        }
    }

    if(1) //晶科EL
    {
        DefectBtnModel & db = DefectBtnModel::Instance();
        QString strDefect = "";

        if(nCmd == 0)
        {
            strDefect = "OK";
        }
        else
        {
            if(bEL)
            {
                if(nCmd < db.m_EL_Titles.size())
                {
                    strDefect = db.m_EL_Titles[nCmd-1].c_str();
                }
            }
            else
            {
                if(nCmd < db.m_WG_Titles.size())
                {
                    strDefect = db.m_WG_Titles[nCmd-1].c_str();
                }
            }
        }
        strPath += "/";
        strPath += strDefect;
        if(!QDir(strPath).exists())
        {
            if(!QDir().mkdir(strPath))
            {
                QMessageBox::information(0,tr("not dir"),strPath);
                return "";
            }
        }

    }
    //    DefectBtnModel & db = DefectBtnModel::Instance();
    //    QString strNG = "NG";
    //    if(nCmd == 0)
    //    {
    //        strNG = "OK";
    //    }
    //    strPath += "/";
    //    strPath += strNG;
    //    if(!QDir(strPath).exists())
    //    {
    //        if(!QDir().mkdir(strPath))
    //        {
    //            QMessageBox::information(0,tr("not dir"),strPath);
    //            return "";
    //        }
    //    }
    //获取是否有该条码文件
    QDir  fileDir(strPath);
    fileDir.setFilter(QDir::Files | QDir::NoSymLinks);

    //  QString  strCodeName = m_ELUIObj.GetBarCode().c_str();
    QString  strCodeName = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");//日期保存
    QStringList filters;
    filters<<strCodeName+"*";
    fileDir.setNameFilters(filters);



    int nCount = fileDir.count();
    if(nCount)
    {
        strCodeName += "_";
        strCodeName += QString::number(nCount);

    }


    strPath += "/";
    strPath += strCodeName;
    strPath += ".jpg";
    return strPath.toStdString();
}

#include "p123_STR_class.h"
void LogicController::OnCheckState()
{
    if(m_nState == CHECK_FREE)
    {
        OnQueryPhoto1();
        //    return ;
    }
    if(m_nState == CHECK_BARCODE)
    {
        //检测
        OnQueryPhoto1();
        m_nELCurHeight = 0;
        //    m_nState == CHECK_BEGIN;
    }
    if(p123_STR_class::pSTR_M1367)//等待外部硬件信号
    {
        OnQuerybutton();
    }
    //    else if(m_nState == CHECK_BEGIN)
    //    {
    //    }
    //    else if(m_nState == CHECK_DEFECT)
    //    else if(m_nState == CHECK_DEFECT&&!m_defect&&m_ELData.GetValue("DEFECT_mod").GetString() == std::string("YingJian"))
}

void LogicController::OnSetPhoto1()
{
    //    //返回成功才设置
    //    if(m_pFxComModule->SetForceOn("M32",50))
    //    {

    //        m_ElImage = QImage(600*6,600*2,QImage::Format_RGB888);
    //        m_ElImage.fill(QColor(0, 0, 0));
    //        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "Set 32: TRUE", "");

    //        m_nState = CHECK_POS1;
    //    }

}

void LogicController::OnQueryPhoto1()
{
    //m_ELUIObj.OnSetTextInfo(true, "读拍照信号===");
    bool bRet1 = false;
    m_pFxComModule->GetDevice("M72", bRet1);
    if(bRet1)
    {
        int EL_zoomw12 = m_pAlg230->Algimg_zoomw12(&m_ELData);


        m_ElImage = QImage(EL_zoomw12, 1200, QImage::Format_RGB888);

        m_ElImage.fill(QColor(0, 0, 0));
        m_ELUIObj.OnSetTextInfo(true, "收到拍照信号======B");
        m_SAB = "B";
        m_nState = CHECK_PHOTO1;
        //     m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "Get Photo POS1: TRUE   B", "");
        //     m_time.start();
        //开始执行逻辑操作
        OnGetPhoto1();
        //定制
        m_ELUIObj.OnUpDateImage(nullptr);
    }
    bool bRet2 = false;
    m_pFxComModule->GetDevice("M73", bRet2);
    if(bRet2)
    {
        int EL_zoomw12 = m_pAlg230->Algimg_zoomw12(&m_ELData);


        m_ElImage = QImage(EL_zoomw12, 1200, QImage::Format_RGB888);

        m_ElImage.fill(QColor(0, 0, 0));
        m_ELUIObj.OnSetTextInfo(true, "收到拍照信号======A");
        m_SAB = "A";
        m_nState = CHECK_PHOTO1;
        //      m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "Get Photo POS1: TRUE  A", "");
        //       m_time.start();
        //开始执行逻辑操作
        OnGetPhoto1();
        //定制
        m_ELUIObj.OnUpDateImage(nullptr);//刷新显示空图
    }
    //   m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "Get Photo POS1: FALSE", "");
    //新添加 20190510 物理按钮测试
    //   OnQuerybutton();
    //      m_ELUIObj.OnSetTextInfo(true,"物理按钮测试======OK/NG！");

}

void LogicController::OnGetPhoto1()
{
    m_nState = CHECK_PHOTO1;
    m_ELUIObj.OnPhotoState(-1);
    OnGrab();

}

void LogicController::OnSetPhotoOK()
{
    m_nState = CHECK_DEFECT;
    m_bElDefect = false;
    m_ELUIObj.OnPhotoState(3);
    //启用OK NG分选按钮 20190514
    m_ELUIObj.OnEnableBtn(true);

    m_ELUIObj.OnPhotoState(2);
    if(m_pFxComModule->SetForceOn("M35", 100))
    {
        m_ELUIObj.OnSetTextInfo(true, "拍照信号发出==");
        //if(pObj->GetValue("EL_automatic").GetString() == std::string("TRUE"))
        //        if (m_ELData.GetValue("DEFECT_mod").GetString() == std::string("YingJian"))//硬件按钮=人工判断
        //        {
        //            m_pFxComModule->SetDevice("M100", false);//手动模式
        //            m_ELUIObj.OnSetTextInfo(true, "等待人工判断==");
        //        }
        //        else
        //        {
        //            m_pFxComModule->SetDevice("M100", true);//自动模式
        //            m_ELUIObj.OnSetTextInfo(true, "AI自动判断==");
        //        }

        //    m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "Set 35: TRUE", "");
        m_nState = CHECK_BEGIN; //在线
        //    m_nState = CHECK_FREE;
        m_bElDefect = false;
        //        m_ELUIObj.OnPhotoState(3);
        //       m_ELUIObj.OnEnableBtn(true);//离线
        //       m_bElDefect = true;
        //        m_ELUIObj.OnEnableBtn(false);
        //         CheckDefectOver();

        //     m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "total time:", m_time.elapsed());
        //      m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "BEGIN DEFECT", "");
    }
}

void LogicController::OnGrab()
{
    m_bElCamOver = false;

    //    m_AI_btn = false;//每次拍照默认：AI自动按下OKNG标记

    //等待上电
    //Sleep(300);
    //m_pFlyCamModule->OnAsynGrabs();

    m_pMVModule->OnAsynGrab();
}

void LogicController::PLC_Reset()
{
    m_pFxComModule->SetForceOn("M20", 100);
    m_ELUIObj.OnSetTextInfo(true, "PLC复位");
}

void LogicController::PLC_start()
{
    m_pFxComModule->SetForceOn("M26", 100);
    m_nState = CHECK_FREE;
    m_ELUIObj.OnSetTextInfo(true, "PLC一键拍照");
}

bool LogicController::getIsAutoJudge()
{
    return m_isAutoJudge;
}

void LogicController::PLC_Left_Cylinder_down(bool n)  //左下压
{
    if(n)
    {
        m_pFxComModule->SetForceOn("M21", 100);
        m_ELUIObj.OnSetTextInfo(true, "左侧气缸下压");
    }
    else
    {
        m_pFxComModule->SetForceOff("M21", 100);
        m_ELUIObj.OnSetTextInfo(true, "左侧气缸抬起");
    }
}

void LogicController::PLC_Right_Cylinder_down(bool n)//右下压
{
    if(n)
    {
        m_pFxComModule->SetForceOn("M23", 100);
        m_ELUIObj.OnSetTextInfo(true, "右侧气缸下压");
    }
    else
    {
        m_pFxComModule->SetForceOff("M23", 100);
        m_ELUIObj.OnSetTextInfo(true, "右侧气缸抬起");
    }
}

void LogicController::PLC_Left_Cylinder_Clamp(bool n)//左夹紧
{
    if(n)
    {
        m_pFxComModule->SetForceOn("M22", 100);
        m_ELUIObj.OnSetTextInfo(true, "左侧气缸夹紧");
    }
    else
    {
        m_pFxComModule->SetForceOff("M22", 100);
        m_ELUIObj.OnSetTextInfo(true, "左侧气缸放松");
    }
}

void LogicController::PLC_Right_Cylinder_Clamp(bool n)//右夹紧
{
    if(n)
    {
        m_pFxComModule->SetForceOn("M24", 100);
        m_ELUIObj.OnSetTextInfo(true, "右侧气缸夹紧");
    }
    else
    {
        m_pFxComModule->SetForceOff("M24", 100);
        m_ELUIObj.OnSetTextInfo(true, "右侧气缸放松");
    }
}
void LogicController::PLC_Start_Up(bool n)//手动上电
{
    if(n)
    {
        m_pFxComModule->SetForceOn("M25", 100);
        m_ELUIObj.OnSetTextInfo(true, "手动上电");
    }
    else
    {
        m_pFxComModule->SetForceOff("M25", 100);
        m_ELUIObj.OnSetTextInfo(true, "手动上电解除");
    }
}

void LogicController::CheckDefectOver()
{
    //分选完毕
    if(m_bElDefect)
    {
        m_nState = CHECK_BARCODE;
        //获取条形码
        m_ELUIObj.EditBarCode();
        m_ELUIObj.OnPhotoState(-1);
        //m_ScanObj.GetCode();

        if(m_nElDefect == 0)
        {
            m_pFxComModule->SetForceOn("M36", 100);
            //统计
            //   m_ELUIObj.OnTotalOK();
            m_ELUIObj.OnSetTextInfo(true, "set M36");
            //      m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "===========Defect OK", "");
        }
        else
        {
            if(m_ELUIObj.getIsYl() && m_isYl)
            {
                m_pFxComModule->SetForceOn("M37",100);
                //统计
                //    m_ELUIObj.OnTotalNG();
                m_ELUIObj.OnSetTextInfo(true, "YL: set M37");
                m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "===========Defect yinlie", "");
            }
            else if(m_ELUIObj.getIsXh() && m_isXh)
            {
                m_pFxComModule->SetForceOn("M37",100);
                //统计
                //  m_ELUIObj.OnTotalNG();
                m_ELUIObj.OnSetTextInfo(true, "XH: set M37");
                m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "===========Defect xuhan", "");
            }
            else if(m_ELUIObj.getIsOther() && m_isOther)
            {
                m_pFxComModule->SetForceOn("M37",100);
                //统计
                //   m_ELUIObj.OnTotalNG();
                m_ELUIObj.OnSetTextInfo(true, "QT: set M37");
                m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "===========Defect getIsOther", "");
            }
            else
            {
                m_pFxComModule->SetForceOn("M36",100);

                //QMessageBox::information(NULL, "Title", "收到M37NG信号", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                //  m_ELUIObj.OnTotalNG();
                m_ELUIObj.OnSetTextInfo(true, "Else: set M36");
                m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "============Defect qita", "");
            }

            // m_pFxComModule->SetForceOn("M37", 100);
            //  m_ELUIObj.OnSetTextInfo(true, "set M37");
            //QMessageBox::information(NULL, "Title", "收到M37NG信号", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            //   m_ELUIObj.OnTotalNG();
            //       m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "============Defect NG", "");
        }
    }
    else
    {
        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "=============NO Defect", "");
    }
}

void LogicController::CallBackELCamera(int nSerial, bool bOnline)
{
    emit sig_camera_el_online(bOnline);
}

void LogicController::VerFilp(std::vector<void *> &buffers)
{
    if(buffers.size() != 4)
        return;

    for(int i = 0; i < 4; ++i)
    {
        QImage image((uchar *)buffers[i],1920,1200,QImage::Format_Grayscale8);
        QImage vImage = image.mirrored(false,true);
        memcpy(buffers[i],vImage.constBits(), 1920*1200);
    }
}

void LogicController::HorFilp(std::vector<void *> &buffers)
{
    if(buffers.size() != 4)
        return;

    for(int i = 0; i < 4; ++i)
    {
        QImage image((uchar *)buffers[i],1920,1200,QImage::Format_Grayscale8);
        QImage vImage = image.mirrored(true,false);
        memcpy(buffers[i],vImage.constBits(), 1920*1200);
    }
}

void LogicController::onMvCamBind()
{
    ControlModel * pModel =  OnGetModel();
    Data * pObj =  pModel->GetObj();
    if(pObj->GetValue("CameraModule_class").GetString() == std::string("MindVision"))
    {
        m_pMVModule->Change_CameraModule(MindVision);
    }
    else if(pObj->GetValue("CameraModule_class").GetString()==std::string("FlyCapture"))
    {
        m_pMVModule->Change_CameraModule(FlyCapture);
    }
    else if(pObj->GetValue("CameraModule_class").GetString()==std::string("ELGalaxy"))
    {
        m_pMVModule->Change_CameraModule(ELGalaxy);
    }
    //相机绑定开启
    std::vector<string> vecs;
    std::vector<float> vecf;

    //    //2
    //    for(int i = 1; i<= 2; ++i)
    //    {
    //        QString str = QString("EL_CAM_%1").arg(i);
    //        string nCam1 =  m_SystemModel.GetObj()->GetValue(str.toStdString().c_str());
    //        vecs.push_back(nCam1);

    //        QString  strExp;
    //        if(m_bFlow)
    //        {
    //            strExp = QString("EL_CamET%1").arg(i);
    //        }
    //        else
    //        {
    //            strExp = QString("EL_L_CamET%1").arg(i);
    //        }
    //        float fCam1 = m_SystemModel.GetObj()->GetValue(strExp.toStdString().c_str());
    //        if(fCam1 <=2)
    //        {
    //            fCam1 = 3;
    //        }
    //        vecf.push_back(fCam1);
    //    }
    //4
    for(int i = 1; i<= 4; ++i)
    {
        QString str = QString("EL_CAM_%1").arg(i);
        string nCam1 =  m_SystemModel.GetObj()->GetValue(str.toStdString().c_str());
        vecs.push_back(nCam1);

        QString  strExp;
        if(m_bFlow)
        {
            strExp = QString("EL_CamET%1").arg(i);
        }
        else
        {
            strExp = QString("EL_L_CamET%1").arg(i);
        }
        float fCam1 = m_SystemModel.GetObj()->GetValue(strExp.toStdString().c_str());
        if(fCam1 <=3)
        {
            fCam1 = 5;
        }
        vecf.push_back(fCam1);
    }


    m_pMVModule->AfterInit();
    m_pMVModule->Set_GetData(m_SystemModel.GetObj());
    auto cb2 = std::bind(&LogicController::CallBackELCamera,this,std::placeholders::_1,std::placeholders::_2);

    m_pMVModule->SetCallBackCam(cb2);
    //获取曝光时间
    m_pMVModule->SetBindCams(vecs,vecf);
    //m_pFlyCamModule->OnBindCams(vecs,vecf);

    auto cb = std::bind(&LogicController::OnMvCamCallImageOver,this);
    m_pMVModule->SetCallBackGrabOver(cb);
}

//图像处理线程把信号发送出去
void LogicController::OnMvCamCallImageOver()
{

    m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "Fly Cam Image Over", "");
    int nIndex = 0;
    m_bElCamOver = true;

    emit sig_el_img_over(nIndex);
    //emit sig_ImageOver();
}

void LogicController::slot_el_img_over(int nIndex)
{
    std::ostringstream stream;
    stream <<"el img index:"<<nIndex;
    //   m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,stream);

    if (m_ELData.GetValue("DEFECT_mod").GetString() == std::string("YingJian"))//硬件按钮=人工判断
    {
        m_pFxComModule->SetForceOn("M100", 100);//手动模式
        m_ELUIObj.OnSetTextInfo(true, "等待人工判断==");
        m_AI_btn = true;//每次拍照默认：AI自动按下OKNG标记
    }
    else
    {
        m_pFxComModule->SetForceOff("M100", 100);//自动模式
        m_ELUIObj.OnSetTextInfo(true, "AI自动判断==");
        m_AI_btn = false;//每次拍照默认：AI自动按下OKNG标记
    }
    if(m_pFxComModule->SetForceOn("M35", 100))//拍照完成信号
    {
        m_ELUIObj.OnSetTextInfo(true, "拍照完成信号发出==");
        //     m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL, "Set 35: TRUE", "");

    }
    OnDrawELImage( nIndex);
}

void LogicController::slot_CamCheck_timer()
{
    // m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,"check cams","");
    //m_pFlyCamModule->OnCheck();
}

void LogicController::slot_camera_el_online(bool bOnline)
{
    m_ELUIObj.OnELCamState(bOnline);
}

void LogicController::slot_ImageOver()
{
    //图片里画
    if(m_nState == CHECK_PHOTO1)
    {
        OnSetPhotoOK();
    }
}

//#include "p123_STR_class.h"
//bool start_yingjianokng = false;//是否接收外部硬件按钮信号
void LogicController::slot_ELAlgOK(int n)
{

    Data * pObj = m_SystemModel.GetObj();
    DefectBtnModel & db = DefectBtnModel::Instance();
    //    int i= 5;
    //    if(pObj->GetValue("RULER_W").GetString() == std::string("10"))
    //    {
    //        i = 5;
    //    }
    //    else
    //    {
    //        i = 6;
    //    }
    int i = pObj->GetValue("RULER_W").GetInt();

    qDebug() << "NXDockWidget dtor111111111111==="<<i;
    QRect rect = m_ElImage.rect();
    QImage tempImg = m_ElImage.copy(rect);
    if(pObj->GetValue("AI_Open").GetString() == std::string("TRUE"))  //AI上传
    {
        //    if(i<20)
        //    {
        //DLClientInterface::Instance().OnPostImage(pObj, 0, tempImg.scaled(300*i, 1200), pObj->GetValue("AI_Url").GetString(), pObj->GetValue("RULER_W"));
        DLClientInterface::Instance().OnPostImage(pObj, 0, tempImg.scaled(tempImg.width(), tempImg.height()),
                                                  pObj->GetValue("AI_Url").GetString(), pObj->GetValue("RULER_W"));
        //    }
        //   else
        //    {
        //       //AI图像上传尺寸大小不一样 修改20190513
        //        //DLClientInterface::Instance().OnPostImage(pObj,0,m_ElImage.scaled(300*i/2,600*2), pObj->GetValue("AI_Url").GetString(),pObj->GetValue("RULER_W"));
        //       DLClientInterface::Instance().OnPostImage(pObj, 0, tempImg.scaled(3615, 1200), pObj->GetValue("AI_Url").GetString(), pObj->GetValue("RULER_W"));
        //    }
    }

    //    isOk=true;//硬件按钮默认OK
    p123_STR_class::pSTR_M1367=true;//接收外部硬件按钮信号

    //    else if(pObj->GetValue("EL_automatic").GetString() == std::string("TRUE")) //关闭AI  是否开启默认OK分选
    //    {
    //        //添加延时5S jin 20190410
    //        //sleep(20000);

    //        // m_ELUIObj.OnEnableBtn(true);
    //        m_bElDefect =  true;
    //        m_nElDefect = 0;
    //        save_el(0);
    //      //  CheckDefectOver();
    //    }
    m_ELUIObj.OnUpDateImage(&m_ElImage, m_SAB=="A");
    //启用OK NG分选按钮 20190514
    //注釋了  測試下
    m_ELUIObj.OnEnableBtn(true);
    //    if(pObj->GetValue("EL_Save_Original_Image").GetString() == std::string("TRUE"))
    //    {
    //        WorkerOriSave * pWorker = new WorkerOriSave(this, true);  //原图保存 4张图像
    //        connect(pWorker, SIGNAL(finished()), pWorker, SLOT(deleteLater()));
    //        pWorker->start();
    //    }
}

void LogicController::slot_Ai_error()
{
    m_ELUIObj.OnAI_state(false);
    m_Ai_Open = false;
}

void LogicController::SlotImage(const QImage &image, bool bOK, vector<string> ElDefect, vector<string> ElPosition, int nIndex, vector<string> resDefect)
{
    m_bAi_Ok = bOK;

    m_ELUIObj.OnAI_state(true);
    m_Ai_Open = true;
    if(nIndex == 0)
    {
        m_ElAIDefect.clear();
        m_ElAIPosition.clear();

        m_AISaveDefect.clear();
        m_AISavePosition.clear();
        m_resDefect.clear();
    }
//    vector<string> m_AISaveDefect;
//    vector<string> m_AISavePosition;
    m_AISaveDefect.insert(m_AISaveDefect.end(),ElDefect.begin(),ElDefect.end());
    m_AISavePosition.insert(m_AISavePosition.end(),ElPosition.begin(),ElPosition.end());
    m_resDefect.insert(m_resDefect.end(),resDefect.begin(), resDefect.end());

    Data * pObj = m_SystemModel.GetObj();
    QPainter painter(&m_ElImage);
    painter.drawImage(0, 0, image.scaled(m_ElImage.width(), m_ElImage.height()));
    painter.end();
    //    int i= 5;
    //    if(pObj->GetValue("RULER_W").GetString() == std::string("10"))
    //    {
    //        i = 5;
    //    }
    //    else
    //    {
    //        i = 6;
    //    }

    myIndex = nIndex;

    QImage asd = image;
    m_ELUIObj.OnUpDateImage(&m_ElImage, m_SAB=="A");
    //  OnAi_save(m_ElImage,ElDefect,ElPosition,nIndex);
  //  OnAidefect(bOK);  //Ai自动分选,注释掉，添加一个定时器调用该函数，是为了实现，3~5秒后，没有人工判断的情况下，定时器启动，调用该函数实现自动判断
    QSettings setting("mySettings.ini");
    int secs = setting.value("waitSecs").toInt();
    m_ELUIObj.OnSetTextInfo(true, QString("Wait time = ")+ QString::number(secs));
    elCmdTimer->start(secs);
    m_isAutoJudge = false;
}

void LogicController::mkdir_path(QString path)   //
{
    QStringList list = path.split("/");
    QString mkdir_path = "";
    for(int i = 0;i<list.size()-1;i++)
    {
        mkdir_path = mkdir_path +list[i];
        if(!QDir(mkdir_path).exists())
        {
            if(!QDir().mkdir(mkdir_path))
            {
                return;
            }
        }
        mkdir_path = mkdir_path +"/";
    }
}

//漏检率，误检率 NG率刷新
void LogicController::OnUpdateRate()
{
    //将计算的误判漏判率显示 每次计数后刷新一次
    m_ELUIObj.OnTotalErrorRate();
    m_ELUIObj.OnTotalMissRate();
    m_ELUIObj.OnTotalNGRate();
}

bool LogicController::getElDefect(vector<string> ElDefect, string strDef)
{
    vector<string>::iterator ret;
    ret = std::find(ElDefect.begin(), ElDefect.end(), strDef);
    if(ret == ElDefect.end())
        return false;
    else
        return true;
}

void LogicController::OnAi_save(const QImage &image, vector<string> ElDefect, vector<string> ElPosition, int nIndex, string strPath)
{
    m_isYl = false;
    m_isXh = false;
    m_isOther = false;

    Data * pObj = m_SystemModel.GetObj();
    QString  FacilityId;
    QString  StringEL_ID;

    QString  day = "白班";
    QString tmpDute = "day";
    m_ElAIDefect.clear();
    m_ElAIPosition.clear();
    QDate  date = QDate::currentDate();
    QTime  time = QTime::currentTime();
    QString strDute = m_ELUIObj.getDute();
    //夜班
    if(time.hour() <8||time.hour() >19)
    {
        tmpDute = "night";
        day = "夜班";
    }
    if(time.hour() <8)
    {
        date= date.addDays(-1);
    }
    if(strDute != tmpDute)
    {
        m_ELUIObj.clearExcelData();
    }
    m_ELUIObj.saveDute(tmpDute);

    //    if(pObj->GetValue("EL_automatic").GetString() == std::string("TRUE"))
    //    {
    pObj->SetAttribute("StringEL_AI_num",AI_EL_num);
    pObj->SetAttribute("StringEL_AI_EL_NGnum",AI_EL_NGnum);
    pObj->SetAttribute("StringEL_AI_SAB",m_SAB.toStdString().c_str());
    FacilityId = pObj->GetValue("StringEL_FacilityId").GetString();

    StringEL_ID = pObj->GetValue("StringEL_ID").GetString();
    //StringEL_ID = StringEL_ID +"/"+QDateTime::currentDateTime().toString("yyyy-MM-dd");
    StringEL_ID = StringEL_ID +"/"+date.toString("yyyy-MM-dd")+"/"+day;
    QString  el_path = pObj->GetValue("EL_SAVE_DIR").GetString();

    StringEL_ID = el_path +"/"+FacilityId+"_"+StringEL_ID;

    QString TotalCSV_Path = StringEL_ID + + "/"+ "TotalTable.csv"; //误判漏判路径

    QString totalPath = StringEL_ID + "/";

    QString strNgDefPath = "";
    bool bAiOk ;

    for(int i = 0;i<ElDefect.size(); i++)
    {
        QString defInfo = QString::fromStdString(ElDefect.at(i));
        m_ELUIObj.OnSetTextInfo(false, "DefInfo = "+defInfo);
    }

    // if(!ElDefect.empty() && !ElPosition.empty())
    if(m_bAi_Ok)
    {
      //  m_ElAIDefect.insert(m_ElAIDefect.end(),ElDefect.begin(),ElDefect.end());
      //  m_ElAIPosition.insert(m_ElAIPosition.end(),ElPosition.begin(),ElPosition.end());
        bAiOk = true;
        StringEL_ID = StringEL_ID + "/OK/";
        m_ELUIObj.OnTotalOK();
    }
    else
    {
        bAiOk = false;
        StringEL_ID = StringEL_ID + "/NG/";
        m_ELUIObj.OnTotalNG();
        if(getElDefect(m_resDefect, "隐裂") && getElDefect(m_resDefect, "虚焊"))
        {
            m_isYl = true;
            m_isXh = true;
            strNgDefPath = StringEL_ID + QStringLiteral("/YL&XH/");
            m_ELUIObj.addYlAndXhNum();
        }
        else if(getElDefect(m_resDefect, "隐裂"))
        {
            m_isYl = true;
            strNgDefPath = StringEL_ID + QStringLiteral("/YL/");
            m_ELUIObj.addYlNum();
        }
        else if(getElDefect(m_resDefect, "虚焊"))
        {
            m_isXh = true;
            strNgDefPath = StringEL_ID + QStringLiteral("/XH/");
            m_ELUIObj.addXhNum();
        }
        else
        {
            m_isOther = true;
            strNgDefPath = StringEL_ID + QStringLiteral("/QT/");
            m_ELUIObj.addOtherNum();
        }
    }

    int okNum = m_ELUIObj.getExcelOkNum();
    int ngNum = m_ELUIObj.getExcelNgNum();
    int ylNum = m_ELUIObj.getYlNum();
    int xhNum = m_ELUIObj.getXhNum();
    int ylAndXhNum = m_ELUIObj.getYlAndXhNum();
    int otherNum = m_ELUIObj.getOtherNum();

    m_ELUIObj.OnSetTextInfo(true, "ngDefPath = "+strNgDefPath);
    m_ELUIObj.OnSetTextInfo(true, "EL_Path = "+ StringEL_ID);
    m_ELUIObj.OnSetTextInfo(true, "TotalPath = "+ totalPath);

    QString strCode = QDateTime::currentDateTime().toString("yyyyMMdd-hhmmss");

    AiExcelThread *thd = new AiExcelThread(&m_ElImage,bAiOk,ElDefect,ElPosition,/*m_ELUIObj.GetBarCode().c_str()*/strCode.toStdString(), strNgDefPath, StringEL_ID, totalPath, okNum,ngNum,ylNum,xhNum,ylAndXhNum,otherNum);
    thd->setSAB(m_SAB);
    thd->setStringNum(QString::number(AI_EL_num));
    thd->start();

    if(!m_isAutoJudge)
    {
        //AI_OK=AI结果   isOK=人工结果
        //AI和人工硬件按钮都打开时，AI和人工对比，否则只记录OKNG数据
        if(pObj->GetValue("AI_Open").GetString() == std::string("TRUE"))
        {
            if(AI_OK==true && isOk==false && m_AI_btn==true)//AI结果OK 人工结果NG  AI漏检
            {
                m_ELUIObj.onTotalMissNum();

                m_okNum = m_ELUIObj.getOkNum();
                m_ngNum = m_ELUIObj.getNgNum();
                m_missNum = m_ELUIObj.getMissNum();
                m_errorNum = m_ELUIObj.getErrorNum();

                OnUpdateRate();

                ExcelThread *thd = new ExcelThread(AI_OK, m_okNum, m_ngNum, m_errorNum, m_missNum, TotalCSV_Path);
                thd->start();
                QStringList strArgs;
                strArgs<<"AI_MissJudge";
                OnSaveWPEL(3, strArgs);
                m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked AI Missed"));
            }
            else if(AI_OK==false && isOk==true && m_AI_btn==true)//AI结果NG 人工结果OK  AI误判
            {
                m_ELUIObj.onTotalErrorNum();

                m_okNum = m_ELUIObj.getOkNum();
                m_ngNum = m_ELUIObj.getNgNum();
                m_missNum = m_ELUIObj.getMissNum();
                m_errorNum = m_ELUIObj.getErrorNum();

                OnUpdateRate();

                ExcelThread *thd = new ExcelThread(AI_OK, m_okNum, m_ngNum, m_errorNum, m_missNum, TotalCSV_Path);//将数据保存到excel
                thd->start();
                QStringList strArgs;
                strArgs<<"WJ";
                OnSaveWPEL(4, strArgs);
                m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked AI Error"));
            }
        }
    }


    /*
    m_ELUIObj.OnSetTextInfo(true, QString("do OnAi_save ")+QString::number(myNum));
    QString  day = "NightWork";
    QDate  date = QDate::currentDate();
    QTime  time = QTime::currentTime();

    //夜班
    if(8 <= time.hour() && time.hour() <20 )
    {
       // m_ELUIObj.OnSetTextInfo(true, QString("Day = ")+QString(day));
        day = "DayWork";
    }
    if(time.hour() <8)
    {
        date= date.addDays(-1);
    }
   // m_ELUIObj.OnSetTextInfo(true, QString("day2 = ")+QString(day));
    QString tmpPath = date.toString("yyyyMMdd");
  //  m_ELUIObj.OnSetTextInfo(true, QString("tmpPath 1 = ")+QString(tmpPath));

    if((lastHour <20 && time.hour() == 20) || (lastHour < 8 && time.hour() == 8))
    {
        m_ELUIObj.clearExcelData();
    }
    lastHour = time.hour();

    Data * pObj = m_SystemModel.GetObj();
    QString TotalCSV_Path = pObj->GetValue("EL_SAVE_DIR").GetString();
    TotalCSV_Path = TotalCSV_Path+"/"+tmpPath + "/"+day + "/"+ "TotalTable.csv";


    //AI_OK=AI结果   isOK=人工结果
    //AI和人工硬件按钮都打开时，AI和人工对比，否则只记录OKNG数据
    if(pObj->GetValue("AI_Open").GetString() == std::string("TRUE"))
    {
        if(AI_OK==true)//AI结果OK
        {
            m_okNum = m_ELUIObj.getOkNum();
            m_ngNum = m_ELUIObj.getNgNum();
            m_missNum = m_ELUIObj.getMissNum();
            m_errorNum = m_ELUIObj.getErrorNum();

            OnUpdateRate();

            ExcelThread *thd = new ExcelThread(AI_OK, m_okNum, m_ngNum, m_errorNum, m_missNum, TotalCSV_Path);
            thd->start();
            m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked AI OK"));
        }
        else//AI结果NG
        {
            m_okNum = m_ELUIObj.getOkNum();
            m_ngNum = m_ELUIObj.getNgNum();
            m_missNum = m_ELUIObj.getMissNum();
            m_errorNum = m_ELUIObj.getErrorNum();

            OnUpdateRate();

            ExcelThread *thd = new ExcelThread(AI_OK, m_okNum, m_ngNum, m_errorNum, m_missNum, TotalCSV_Path);//将数据保存到excel
            thd->start();
            m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked AI NG"));
        }

        if(AI_OK==true && isOk==false && m_AI_btn==true)//AI结果OK 人工结果NG  AI漏检
        {
            m_ELUIObj.onTotalMissNum();

            m_okNum = m_ELUIObj.getOkNum();
            m_ngNum = m_ELUIObj.getNgNum();
            m_missNum = m_ELUIObj.getMissNum();
            m_errorNum = m_ELUIObj.getErrorNum();

            OnUpdateRate();

            ExcelThread *thd = new ExcelThread(AI_OK, m_okNum, m_ngNum, m_errorNum, m_missNum, TotalCSV_Path);
            thd->start();
            QStringList strArgs;
            strArgs<<"AI_MissJudge";
            OnSaveWPEL(3, strArgs);
            m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked AI Missed"));
        }
        else if(AI_OK==false && isOk==true && m_AI_btn==true)//AI结果NG 人工结果OK  AI误判
        {
            m_ELUIObj.onTotalErrorNum();

            m_okNum = m_ELUIObj.getOkNum();
            m_ngNum = m_ELUIObj.getNgNum();
            m_missNum = m_ELUIObj.getMissNum();
            m_errorNum = m_ELUIObj.getErrorNum();

            OnUpdateRate();

            ExcelThread *thd = new ExcelThread(AI_OK, m_okNum, m_ngNum, m_errorNum, m_missNum, TotalCSV_Path);//将数据保存到excel
            thd->start();
            QStringList strArgs;
            strArgs<<"WJ";
            OnSaveWPEL(4, strArgs);
            m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked AI Error"));
        }
    }
    else
    {
        if(isOk==true)//人工分选结果OK
        {
            m_okNum = m_ELUIObj.getOkNum();         //OK
            m_ngNum = m_ELUIObj.getNgNum();         //NG
            m_missNum = m_ELUIObj.getMissNum();     //漏检
            m_errorNum = m_ELUIObj.getErrorNum();   //误判

            OnUpdateRate();

            ExcelThread *thd = new ExcelThread(true, m_okNum, m_ngNum, m_errorNum, m_missNum, TotalCSV_Path);
            thd->start();
            m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked isOk OK"));
        }
        else
        {
            m_okNum = m_ELUIObj.getOkNum();
            m_ngNum = m_ELUIObj.getNgNum();
            m_missNum = m_ELUIObj.getMissNum();
            m_errorNum = m_ELUIObj.getErrorNum();

            OnUpdateRate();

            ExcelThread *thd = new ExcelThread(false, m_okNum, m_ngNum, m_errorNum, m_missNum, TotalCSV_Path);
            thd->start();
            m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked isOk NG"));
        }
    }
//    if(AI_OK==true)
//    {
//        m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked AI OK"));
//    }
//    else
//    {
//        m_ELUIObj.OnSetTextInfo(true, QString("On Btn Clicked AI Error"));
//    }
    m_okNum = this->m_ELUIObj.getOkNum();
    m_ngNum = this->m_ELUIObj.getNgNum();
    m_missNum = this->m_ELUIObj.getMissNum();
    m_errorNum = this->m_ELUIObj.getErrorNum();

//pObj->SetValue("EL_SAVE_DIR",dir.toStdString().c_str());
    QString ssPath = pObj->GetValue("EL_SAVE_DIR").GetString();
    m_ELUIObj.OnSetTextInfo(true, QString("EL_SAVE_DIR 1 = ")+QString(ssPath));

    QString  FacilityId;
    QString  StringEL_ID;


    m_ElAIDefect.clear();
    m_ElAIPosition.clear();

    ssPath = ssPath+"/"+tmpPath + "/"+day + "/"+ "統計表格.csv";

    m_ELUIObj.OnSetTextInfo(true, QString("ssPath 3 = ") + ssPath);

    //    if(pObj->GetValue("EL_automatic").GetString() == std::string("TRUE"))
    //    {
    pObj->SetAttribute("StringEL_AI_num",AI_EL_num);
    pObj->SetAttribute("StringEL_AI_EL_NGnum",AI_EL_NGnum);
    pObj->SetAttribute("StringEL_AI_SAB",m_SAB.toStdString().c_str());
    FacilityId = pObj->GetValue("StringEL_FacilityId").GetString();

    StringEL_ID = pObj->GetValue("StringEL_ID").GetString();
    //StringEL_ID = StringEL_ID +"/"+QDateTime::currentDateTime().toString("yyyy-MM-dd");
    StringEL_ID = StringEL_ID +"/"+date.toString("yyyy-MM-dd")+"/"+day;

    if(nIndex==0 && AI_EL_num==1 && AI_EL_makdir)
    {
        AI_EL_makdir = false;
        QString  strtime = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");//日期保存
        QString  ai_path = pObj->GetValue("StringEL_ai_path").GetString();
        QString ai_csv_path = ai_path +"/"+FacilityId+"_"+StringEL_ID+"/"+strtime+"/"+strtime+".csv";
        pObj->SetAttribute("StringEL_AI_path",ai_csv_path.toStdString().c_str());
        
        QString asd = ai_path +"/"+FacilityId+"_"+StringEL_ID+"/"+"AI_NG.csv";
        pObj->SetAttribute("StringEL_AI_all_ng_path",asd.toStdString().c_str());

        //新增 总统计数据路径 20190519
        QString ASd = ai_path +"/"+FacilityId+"_"+StringEL_ID+"/"+"Total.csv";
        pObj->SetAttribute("StringEL_Total_path",ASd.toStdString().c_str());


        QString AAA = ai_path +"/"+FacilityId+"_"+StringEL_ID+"/"+"AI_NG/";
        pObj->SetAttribute("StringEL_AI_all_ng_img_path",AAA.toStdString().c_str());
        ai_img_path = ai_path +"/"+FacilityId+"_"+StringEL_ID+"/"+strtime+"/";
    }
    m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,"AI_save","");
    QString img_path = ai_img_path+FacilityId+"_"+pObj->GetValue("StringEL_ID").GetString()+"_"+m_SAB+"_"+QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
    pObj->SetAttribute("StringEL_AIimg_path",img_path.toStdString().c_str());

    if(nIndex==0 && AI_EL_NGnum==1 && AI_EL_NGmakdir)
    {
        AI_EL_NGmakdir = false;
        QString  strtime = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");//日期保存
        QString  ai_path = pObj->GetValue("StringEL_ai_path").GetString();
        QString ai_csv_path = ai_path +"/"+FacilityId+"_"+StringEL_ID+"/"+"NG_"+strtime+"/"+strtime+".csv";
        pObj->SetAttribute("StringEL_AING_path",ai_csv_path.toStdString().c_str());
        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,ai_csv_path.toStdString().c_str(),"");

        QString asd = ai_path +"/"+FacilityId+"_"+StringEL_ID+"/"+"AI_NG.csv";
        //  pObj->SetAttribute("StringEL_AI_all_ng_path",asd.toStdString().c_str());
        QString AAA = ai_path +"/"+FacilityId+"_"+StringEL_ID+"/"+"AI_NG/";
        //  pObj->SetAttribute("StringEL_AI_all_ng_img_path",AAA.toStdString().c_str());

        ai_ng_img_path = ai_path +"/"+FacilityId+"_"+StringEL_ID+"/"+"NG_"+strtime+"/";
    }

    m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,"AI_save","");

    //？？？？
    QString ng_img_path = ai_ng_img_path+FacilityId+"_"+pObj->GetValue("StringEL_ID").GetString()+"_"+m_SAB+"_"+QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
    pObj->SetAttribute("StringEL_NGAIimg_path",ng_img_path.toStdString().c_str());

    //如果图像无缺陷
    if(!ElDefect.empty() && !ElPosition.empty())
    {
        m_ElAIDefect.insert(m_ElAIDefect.end(), ElDefect.begin(), ElDefect.end());
        m_ElAIPosition.insert(m_ElAIPosition.end(), ElPosition.begin(), ElPosition.end());
    }
    //新增OK NG信号 20190520
    m_pELCmdAction = new ELCmdAction;
    int FM=m_pELCmdAction->FalseMissed;

    //保存数据到CSV文件 20190515
    //    AI_save_work * pWorker = new AI_save_work(&m_ElImage,m_ElAIDefect,m_ElAIPosition,m_ELUIObj.GetBarCode().c_str(),AI_OK,AI_EL_num,pObj);
    QImage * tmpImage = new QImage;
    *tmpImage = m_ElImage.copy(m_ElImage.rect());
  //  *tmpImage = m_ElImage.scaled(3615, 1200);


    AI_save_work * pWorker = new AI_save_work(tmpImage, m_ElAIDefect, m_ElAIPosition, m_ELUIObj.GetBarCode().c_str(),
                                              AI_OK, m_okNum, m_ngNum, m_errorNum, m_missNum, ssPath.toStdString(), AI_EL_num,pObj);
    pWorker->start();


    */

    //    m_ELUIObj.OnSetTextInfo(true, QString("path  = ") + ssPath);
    //    ExcelThread *excelThread = new ExcelThread(AI_OK, okNum, ngNum, errorNum, missNum, ssPath);
    //    excelThread->start();

    /*
    if(AI_OK)
    {
        if(AI_EL_num==6)   //6串保存到一个文件夹
        {
            AI_EL_num =1;
            AI_EL_makdir = true;
        }
        else
        {
            AI_EL_num++;
        }
    }
    else
    {
        if(AI_EL_NGnum==6)   //6串保存到一个文件夹
        {
            AI_EL_NGnum =1;
            AI_EL_NGmakdir = true;
        }
        else
        {
            AI_EL_NGnum++;
        }
    }
    */
    //   }
}

bool LogicController::OnAi_Condition_Defect()
{
    Data * pObj = m_SystemModel.GetObj();
    if(m_ElAIDefect.empty())
    {
        return true;
    }
    if(pObj->GetValue("AI_Yinlie_Defect").GetString() == std::string("TRUE"))
    {

        for(int i=0 ; i<m_ElAIDefect.size(); ++i)
        {
            if(m_ElAIDefect[i] == "隐裂")
            {
                m_ELUIObj.OnSetTextInfo(true,"隐裂NG");
                return false;
            }
        }
    }
    else if(pObj->GetValue("AI_Xuhan_Defect").GetString() == std::string("TRUE"))
    {
        for(int i=0 ; i<m_ElAIDefect.size(); ++i)
        {
            if(m_ElAIDefect[i] == "虚焊")
            {
                m_ELUIObj.OnSetTextInfo(true,"虚焊NG");
                return false;
            }
        }
    }

    return true;
}

void LogicController::OnAidefect( )
{
    Data * pObj = m_SystemModel.GetObj();
    AI_OK = m_bAi_Ok;//false = AI返回NG
    // 关闭是否启动自动分选定时器
    elCmdTimer->stop();
    m_isAutoJudge = true;

    //    if(pObj->GetValue("EL_automatic").GetString() == std::string("TRUE"))//
    //    {
    if (m_ELData.GetValue("DEFECT_mod").GetString() == std::string("YingJian"))//硬件按钮=人工判断
    {
        //    start_yingjianokng=true;//是否接收外部硬件按钮信号
    }
    else if(m_Ai_Open)
    {
        //    start_yingjianokng=false;//是否接收外部硬件按钮信号
        //        m_bElDefect =  true;
        //        m_nElDefect = 0;
        //     //   CheckDefectOver();
        //        m_ELUIObj.OnSetTextInfo(true,"默认OK");
        //        m_ELUIObj.SetEL_NG_cmd(true); //按OK按鈕
        //    }
        //    else
        //    {
        //  if(OnAi_Condition_Defect())
        if(AI_OK==true)
        {
            //       m_bElDefect =  true;
            //    m_nElDefect = 0;
            //  CheckDefectOver();
            m_ELUIObj.OnSetTextInfo(true, "AI自动识别OK");
            m_ELUIObj.SetEL_NG_cmd(true); //按OK按鈕
            //           m_AI_btn = false;//AI自动按下OKNG标记
        }
        else
        {
            m_ELUIObj.OnSetTextInfo(true, "AI自动识别NG");
            //       m_bElDefect =  true;
            //    m_nElDefect = 1;
            //  CheckDefectOver();
            m_ELUIObj.SetEL_NG_cmd(false); //按OK按鈕
            //           m_AI_btn = false;//AI自动按下OKNG标记
        }
    }

    //    }
}

void LogicController::OnAiormansave(int nCmd)
{
    Data * pObj = m_SystemModel.GetObj();
    if(pObj->GetValue("AI_Open").GetString() == std::string("TRUE") && m_Ai_Open)  //AI上传
    {
        //AI_OK
        if(AI_OK==true & nCmd==1)//AI结果=OK 与 人工结果=NG时
        {
            QImage * pImage = new QImage;
            *pImage = m_ElImage.copy(m_ElImage.rect());
            //   *pImage = m_ElImage.scaled(3615, 1200);
            std::string strPath = GetSavePath(pObj->GetValue("EL_SAVE_DIR").GetString(), pObj->GetValue("user_class").GetString(), 2, true);
            int nW = 1920;
            int nH  = 1200;
            QStringList strArgs;
            //    SaveWoker * pWorker = new SaveWoker(pImage, NULL, strPath, strArgs, nW, nH, true);
            SaveWoker * pWorker = new SaveWoker(pImage, NULL, strPath, strArgs, m_ElImage.width(), m_ElImage.height(), true);//20190802
            connect(pWorker, SIGNAL(finished()), pWorker, SLOT(deleteLater()));
            connect(pWorker, SIGNAL(sig_Save_over(QString)), this, SLOT(slot_Save_Over(QString)), Qt::QueuedConnection);
            pWorker->start();
        }
        else if(AI_OK==false & nCmd==0)//AI结果NG 与 人工结果=OK时
        {
            QImage * pImage = new QImage;
            *pImage = m_ElImage.copy(m_ElImage.rect());
            //   *pImage = m_ElImage.scaled(3615, 1200);
            std::string strPath = GetSavePath(pObj->GetValue("EL_SAVE_DIR").GetString(), pObj->GetValue("user_class").GetString(), 3, true);
            int nW = 1920;
            int nH  = 1200;
            QStringList strArgs;
            //    SaveWoker * pWorker = new SaveWoker(pImage, NULL, strPath, strArgs, nW, nH, true);
            SaveWoker * pWorker = new SaveWoker(pImage, NULL, strPath, strArgs, m_ElImage.width(), m_ElImage.height(), true);//20190802
            connect(pWorker, SIGNAL(finished()), pWorker, SLOT(deleteLater()));
            connect(pWorker, SIGNAL(sig_Save_over(QString)), this, SLOT(slot_Save_Over(QString)), Qt::QueuedConnection);
            pWorker->start();
        }
    }
}

QStringList LogicController::GetELSavePaths(QStringList strListDefects)
{
    QStringList retList;
    Data * pObj = m_SystemModel.GetObj();
    if(!pObj)
        return retList;

    QString  strPath = pObj->GetValue("EL_SAVE_DIR").GetString();
    string strClass  = pObj->GetValue("user_class").GetString();


    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
        {
            QMessageBox::information(0,tr("not dir"),strPath);
            return retList;
        }
    }
    strPath += "/";
    QDate  date = QDate::currentDate();
    QTime  time = QTime::currentTime();

    //夜班
    if(time.hour() <8)
    {
        date= date.addDays(-1);
    }

    QString strDate = date.toString("yyyyMMdd");
    strPath += strDate;
    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
        {
            QMessageBox::information(0,tr("not dir"),strPath);
            return retList;
        }
    }

    strPath += "/";
    if(strClass.empty())
    {
        strPath += "A";
    }
    else
    {
        strPath += strClass.c_str();
    }


    if(!QDir(strPath).exists())
    {
        if(!QDir().mkdir(strPath))
        {
            QMessageBox::information(0,tr("not dir"),strPath);
            return retList;
        }
    }


    if(strListDefects.empty())
    {
        QString strFilePath = strPath + "/OK";

        if(!QDir(strFilePath).exists())
        {
            if(!QDir().mkdir(strFilePath))
            {
                QMessageBox::information(0,tr("not dir"),strFilePath);
                return retList;
            }
        }

        //获取是否有该条码文件
        QDir  fileDir(strFilePath);
        fileDir.setFilter(QDir::Files | QDir::NoSymLinks);

        //    QString  strCodeName = m_strCode.c_str();
        QString  strCodeName = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");//日期保存
        QStringList filters;
        filters<<strCodeName+"*";
        fileDir.setNameFilters(filters);

        int nCount = fileDir.count();
        if(nCount)
        {
            strCodeName += "_";
            strCodeName += QString::number(nCount);

        }


        strFilePath += "/";
        strFilePath += strCodeName;
        strFilePath += ".jpg";

        retList.push_back(strFilePath);


    }
    else
    {

        for(auto it:strListDefects)
        {
            QString strFilePath = strPath + "/";
            strFilePath+=it;


            if(!QDir(strFilePath).exists())
            {
                if(!QDir().mkdir(strFilePath))
                {
                    QMessageBox::information(0,tr("not dir"),strFilePath);
                    return retList;
                }
            }

            //获取是否有该条码文件
            QDir  fileDir(strFilePath);
            fileDir.setFilter(QDir::Files | QDir::NoSymLinks);

            //  QString  strCodeName = m_strCode.c_str();
            QString  strCodeName = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");//日期保存
            QStringList filters;
            filters<<strCodeName+"*";
            fileDir.setNameFilters(filters);

            int nCount = fileDir.count();
            if(nCount)
            {
                strCodeName += "_";
                strCodeName += QString::number(nCount);

            }


            strFilePath += "/";
            strFilePath += strCodeName;
            strFilePath += ".jpg";

            retList.push_back(strFilePath);

        }
    }




    return retList;


}

void LogicController::slot_el_cmd(int nCmd, QStringList args)
{
    isOk = args.contains("OK");//包含OK = true

    m_bElDefect = true;
    m_nElDefect = nCmd;
    OnAiormansave(nCmd);//nCmd=1 是NG
    Data * pObj = m_SystemModel.GetObj();
    std::string strPath;// = GetSavePath(pObj->GetValue("EL_SAVE_DIR").GetString(),pObj->GetValue("user_class").GetString(),nCmd,true);
    QStringList strListDefects = GetELSavePaths(args);
    //保存图片
    QImage * pImage = new QImage;
    *pImage = m_ElImage.copy(m_ElImage.rect());
    //  *pImage = m_ElImage.scaled(3615, 1200);
    for(int i = 0; i < args.size(); i++)
    {
        m_ELUIObj.OnTotalEL(args[i]);
    }
    //  m_ELUIObj.OnUpDateImage(nullptr);
    //获取像素
    int nW = 1920;
    int nH = 1200;
    QString  strResol = pObj->GetValue(EL_IMAGE_RESOL);
    QStringList strList = strResol.split("*");
    if(strList.count() == 2)
    {
        nW = strList.at(0).toInt();
        nH = strList.at(1).toInt();
    }

    std::ostringstream stream;
    stream <<"EL IMAG resoal w:"<<nW <<"h:"<<nH;
    //  m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,stream);

    //   SaveWoker * pWorker = new SaveWoker(pImage, NULL, strPath, strListDefects, nW, nH, true);
    SaveWoker * pWorker = new SaveWoker(pImage,NULL,strPath,strListDefects, m_ElImage.width(), m_ElImage.height(), true);//20190730
    connect(pWorker, SIGNAL(finished()), pWorker, SLOT(deleteLater()));
    connect(pWorker, SIGNAL(sig_Save_over(QString)), this, SLOT(slot_Save_Over(QString)), Qt::QueuedConnection);
    pWorker->start();

    //保存excel表格
    OnAi_save(m_ElImage, m_AISaveDefect, m_AISavePosition, myIndex, strPath);

    //MES系统分选
    std::ostringstream stream1;
    stream1 <<"EL PARAM cmd:"<<nCmd <<"Code:"<<m_ELUIObj.GetBarCode();
    //   m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,stream1);
    m_strCode = m_ELUIObj.GetBarCode();
    //判断是否结束
    CheckDefectOver();
}

void LogicController::slot_stopElCmdTimer()
{
    this->elCmdTimer->stop();
}

//误漏检照片收集
void LogicController::OnSaveWPEL(int nCmd, QStringList args)
{
    Data * pObj = m_SystemModel.GetObj();
    std::string strPath;
    QStringList  strListDefects= GetELSavePaths(args);
    //保存图片
    QImage * pImage = new QImage;
    *pImage = m_ElImage.copy(m_ElImage.rect());
    for(int i=0; i<args.size(); i++)
    {
        m_ELUIObj.OnTotalEL(args[i]);
    }
    //获取像素
    int nW = 1920;
    int nH  = 1200;
    QString  strResol =  pObj->GetValue(EL_IMAGE_RESOL);
    QStringList strList = strResol.split("*");
    if(strList.count() == 2)
    {
        nW = strList.at(0).toInt();
        nH = strList.at(1).toInt();
    }
    std::ostringstream stream;
    stream <<"EL IMAG resoal w:"<<nW <<"h:"<<nH;
    //  m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,stream);

    SaveWoker * pWorker = new SaveWoker(pImage,NULL,strPath,strListDefects,nW, nH, true);
    connect(pWorker, SIGNAL(finished()), pWorker, SLOT(deleteLater()));
    pWorker->start();
}

void LogicController::save_el(int nCmd)
{
    Data * pObj = m_SystemModel.GetObj();
    std::string strPath = GetSavePath(pObj->GetValue("EL_SAVE_DIR").GetString(),pObj->GetValue("user_class").GetString(),nCmd,true);
    //保存图片
    QImage * pImage = new QImage;
    *pImage = m_ElImage.copy(m_ElImage.rect());

    //获取像素
    int nW = 1920;
    int nH  = 1200;
    QString  strResol =  pObj->GetValue(EL_IMAGE_RESOL);
    QStringList strList = strResol.split("*");
    if(strList.count() == 2)
    {
        nW = strList.at(0).toInt();
        nH = strList.at(1).toInt();
    }

    std::ostringstream stream;
    stream <<"EL IMAG resoal w:"<<nW <<"h:"<<nH;
    //  m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,stream);
    QStringList strArgs;
    SaveWoker * pWorker = new SaveWoker(pImage,NULL,strPath,strArgs,nW, nH, true);
    connect(pWorker, SIGNAL(finished()), pWorker, SLOT(deleteLater()));
    connect(pWorker, SIGNAL(sig_Save_over( QString)), this, SLOT(slot_Save_Over( QString)),Qt::QueuedConnection);
    pWorker->start();

    //MES系统分选
    std::ostringstream stream1;
    stream1 <<"EL PARAM cmd:"<<nCmd <<"Code:"<<m_ELUIObj.GetBarCode();
    //   m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,stream1);
    m_strCode = m_ELUIObj.GetBarCode();
    //判断是否结束
    //CheckDefectOver();
}

void LogicController::slot_Save_Over(QString strPath)
{
    DefectBtnModel &df =DefectBtnModel::Instance();
    //MES系统分选
    if(df.m_bCheck)
    {
        //上传
        string strRes =  m_MesClient.OnCallELPictureAddress(m_strCode);

        string strFtpAddr = "res:"+strRes;
        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,strFtpAddr,"");

        int nIndex  = strRes.find(',');
        if(nIndex == -1)
        {
            //获取错误信息
            QString str = QString::fromLocal8Bit("获取地址失败:")+ QString::fromUtf8(strRes.c_str(), strRes.length());
            m_ELUIObj.OnSetTextInfo(false,str);
            return ;
        }


        string strFtpRemet = strRes.substr(0,nIndex);
        string strRementPath = strFtpRemet+m_strCode;
        strRementPath+=".jpg";
        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,strRementPath,"");


        string  strLocalPath = "localpath:";
        strLocalPath += strPath.toStdString();
        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,strLocalPath,"");

        m_ELUIObj.OnSetTextInfo(true,strPath);
        //上传
        bool bOK = m_FtpHelper.OnUpLoad(strRementPath, strPath.toStdString(),"ELTEST","123@qwe");
        if(!bOK)
        {
            QString  strText = QString::fromLocal8Bit("FTP上传失败");
            m_ELUIObj.OnSetTextInfo(false,strText);
            return ;
        }
        else
        {
            QString  strText = QString::fromLocal8Bit("FTP上传成功");
            m_ELUIObj.OnSetTextInfo(true,strText);
        }

        string  strDefect = m_ELUIObj.OnGetJKELParams();

        string  strLogDefect = "DefectCmd:";
        strLogDefect +=strDefect;
        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,strLogDefect,"");
        m_ELUIObj.OnSetTextInfo(true,QString::fromStdString(strLogDefect));

        string strReponse;
        string strRetDefect =   m_MesClient.OnCallELInfoMoveStd(m_strCode,strDefect,strReponse,strPath.toStdString());



        string strTextCode = "testData:"+ m_MesClient.m_strTestData;
        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,strTextCode,"");

        string strTextMsg = "resMsg:"+ strReponse;
        m_pLog->LogNormal(EFILogModule::NLL_INFO_NORMAL,strTextMsg,"");

        if(strRetDefect == "1")
        {

            QString strOK = "[";
            strOK += m_strCode.c_str();
            strOK +=  QString::fromLocal8Bit("]--MES上传成功");
            m_ELUIObj.OnSetTextInfo(true,strOK);
        }
        else
        {
            QString strErr = QString::fromLocal8Bit("MES上传失败->")+QString::fromUtf8(strReponse.c_str(), strReponse.length());
            m_ELUIObj.OnSetTextInfo(false,strErr);

        }
    }
}

//添加延时的函数 20190409
void LogicController::sleep(unsigned int msec)
{
    QTime reachTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

void LogicController::OnQuerybutton()
{
    //    if(m_ELData.GetValue("DEFECT_mod").GetString() == std::string("YingJian"))
    //    {
    //    if( start_yingjianokng=true) //收到外部硬件按钮信号
    //    {
    //      m_ELUIObj.OnSetTextInfo(true, "等待硬件按钮信号");
    bool bRet1 = false;
    m_pFxComModule->GetDevice("M136", bRet1);//PLC OK信号
    if(bRet1)
    {
        //         m_AI_btn = true;//人工按下硬件按钮OKNG标记
        p123_STR_class::pSTR_M1367=false;//关闭接收外部硬件按钮信号
        //开始执行逻辑操作
        m_ELUIObj.SetEL_NG_cmd(true); //按OK按鈕
        m_ELUIObj.OnSetTextInfo(true, "硬件按钮OK");
        //    m_pFxComModule->SetDevice("M36", bRet1);//PLC OK信号
        //    m_RSet=true;

        return ;
    }

    bool bRet2 = false;
    m_pFxComModule->GetDevice("M137", bRet2);//PLC NG信号
    if(bRet2)
    {
        //           m_AI_btn = true;//人工按下硬件按钮OKNG标记
        p123_STR_class::pSTR_M1367=false;//关闭接收外部硬件按钮信号
        //开始执行逻辑操作
        m_ELUIObj.SetEL_NG_cmd(false); //按NG按鈕
        m_ELUIObj.OnSetTextInfo(true, "硬件按钮NG");
        //    m_pFxComModule->SetDevice("M37", bRet2);//PLC NG信号
        //    m_RSet=true;

        return;
    }
    //    }
    //    }
}

