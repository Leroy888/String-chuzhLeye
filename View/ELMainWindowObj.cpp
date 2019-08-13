#include "ELMainWindowObj.h"

#include "Tool/TranslationES.h"
#include "Controller/LogicController.h"
#include "Tool/EFStructDefineLoad.h"
#include "Model/DefectBtnModel.h"
#include <vector>
#pragma execution_character_set("utf-8")
using namespace  std;

ELMainWindowObj::ELMainWindowObj(QObject *parent) : QObject(parent),
    m_bInit(false),m_pLogic(nullptr),m_pPropertyParser(nullptr)
{
    m_Edit.setEnabled(false);
    //   this->setWindowFlags(this->windowFlags() &~ (Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint));
    m_ELTotal.setVisible(false);

}

void ELMainWindowObj::Show()
{

    //    m_MainW.setMinimumHeight(960);
    //    m_MainW.setMinimumWidth(1280);

    //    m_MainW.setMaximumHeight(540*2);
    //    m_MainW.setMaximumWidth(1920*2);
    //  m_MainW.setWindowFlags(this.windowFlags() &~ (Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint));

    m_MainW.showMaximized();
    //   m_MainW.show();
}

void ELMainWindowObj::InitModel()
{
    if(m_pLogic)
    {
        ControlModel * pModel =  m_pLogic->OnGetModel();
        Data * pObj = pModel->GetObj();
        if(pObj)
        {
m_SeeW.SetWRule(pObj->GetValue("RULER_W_B").GetString() == std::string("TRUE"), pObj->GetValue("RULER_W_C").GetString() == std::string("TRUE"), pObj->GetValue("RULER_W"));
m_SeeW.SetHRule(pObj->GetValue("RULER_H_B").GetString() == std::string("TRUE"), true, 6);
            if(m_pPropertyParser)
            {
                m_pPropertyParser->SetData(pObj, m_pStruct, m_pDefine);
            }
        }
    }

    m_pELCmdAction->InitModel();


}

void ELMainWindowObj::OnTotalMissRate()
{
    m_TotalAction.updateMissJudgeRate();
}

void ELMainWindowObj::OnTotalErrorRate()
{
    m_TotalAction.updateErrorJudgeRate();
}

void ELMainWindowObj::OnTotalNGRate()
{
    m_TotalAction.updateNGRate();
}

int ELMainWindowObj::getOkNum()
{
    return this->m_TotalAction.getOkNum();
}

int ELMainWindowObj::getNgNum()
{
    return m_TotalAction.getNgNum();
}

int ELMainWindowObj::getMissNum()
{
    return m_TotalAction.getMissNum();
}

int ELMainWindowObj::getErrorNum()
{
    return m_TotalAction.getErrorNum();
}

void ELMainWindowObj::addXhNum()
{
    m_TotalAction.addXhNum();
}

void ELMainWindowObj::addYlNum()
{
    m_TotalAction.addYlNum();
}

void ELMainWindowObj::addYlAndXhNum()
{
    m_TotalAction.addYlAndXhNum();
}

void ELMainWindowObj::addOtherNum()
{
    m_TotalAction.addOtherNum();
}

void ELMainWindowObj::SetController(LogicController *pLogic)
{
    InitUI();
    m_pLogic = pLogic;
    m_pStartAction->SetController(pLogic);
    m_pELCmdAction->SetController(pLogic);
    m_StateBar.SetController(pLogic);
    InitModel();
    //最后一个
    m_pSysAction->SetController(pLogic);

}

string ELMainWindowObj::GetBarCode()
{
    return m_StateBar.GetBarCode();
}

void ELMainWindowObj::EditBarCode()
{
    m_StateBar.EditBarCode();
}

void ELMainWindowObj::OnEnableBtn(bool bEnble)
{

    m_pELCmdAction->OnEnableBtnOKNG(bEnble);

}

void ELMainWindowObj::OnUpDateImage(QImage *pImage, bool Save_AB)
{
    m_SeeW.SetImage(pImage, Save_AB);
}

void ELMainWindowObj::OnUpDateVecs(int nIndex, std::vector<EL_ChipStrut> &vecs)
{
    //m_SeeW.SetELVecs(nIndex,vecs);
}

void ELMainWindowObj::OnUpdateStartBtn(bool bState)
{
    m_pStartAction->UpDataIcon(bState);
}

void ELMainWindowObj::OnELCamState(bool bOnline)
{
    m_StateBar.cameraELState(bOnline);
}



void ELMainWindowObj::OnPlcState(bool bOnline)
{
    m_StateBar.plcState(bOnline);
}

void ELMainWindowObj::OnPhotoState(int nState)
{
    m_StateBar.updateState(nState);
}
void ELMainWindowObj::OnAI_state(bool bOnline)
{
    m_StateBar.AI_state(bOnline);
}

void ELMainWindowObj::OnEnableSystem(bool bEnble)
{
    if(m_pSysAction)
    {
        m_pSysAction->OnEnable(bEnble);
    }
}

void ELMainWindowObj::OnGetELParams(vector<std::string> &points, vector<std::string> &stdCmd, vector<std::string> &strDetails)
{
    m_pELCmdAction->GetParams(points,stdCmd, strDetails);
}

string ELMainWindowObj::OnGetJKELParams()
{
    return m_pELCmdAction->GetJKParams();
}




void ELMainWindowObj::OnSetTextInfo(bool bState, const QString &text)
{
    m_Edit.setTextColor(bState ? QColor(0, 255, 0):QColor(255, 0, 0));
    //   QString str = QTextCodec::codecForName("UTF-8")->toUnicode(text);//把gb2312编码转换成unicode
    m_Edit.append(text);
}

void ELMainWindowObj::OnTotalOK()
{
    m_TotalAction.AddOK();
}

void ELMainWindowObj::clearExcelData()
{
    m_TotalAction.clearExcelData();
}

void ELMainWindowObj::OnTotalNG()
{
    m_TotalAction.AddNG();
}

void ELMainWindowObj::onTotalMissNum()
{
    m_TotalAction.addMissNum();
}

void ELMainWindowObj::onTotalErrorNum()
{
    m_TotalAction.addErrorNum();
}

int ELMainWindowObj::getYlNum()
{
    return m_TotalAction.getYlNum();
}

int ELMainWindowObj::getXhNum()
{
    return m_TotalAction.getXhNum();
}

int ELMainWindowObj::getYlAndXhNum()
{
    return m_TotalAction.getYlAndXhNum();
}

int ELMainWindowObj::getOtherNum()
{
    return m_TotalAction.getOtherNum();
}

QString ELMainWindowObj::getDute()
{
    return m_TotalAction.getDute();
}

void ELMainWindowObj::saveDute(QString dute)
{
    m_TotalAction.saveDute(dute);
}

int ELMainWindowObj::getExcelOkNum()
{
    return m_TotalAction.getOkNum();
}

int ELMainWindowObj::getExcelNgNum()
{
    return m_TotalAction.getNgNum();
}

void ELMainWindowObj::clearData()
{
    m_TotalAction.on_pushButton_Clear_clicked();
}

void ELMainWindowObj::clearElData()
{
    m_ELTotal.on_Btn_Clear_clicked();
}

void ELMainWindowObj::OnTotalEL(QString nCmd)
{
    m_ELTotal.AddValue(nCmd);
}
void ELMainWindowObj::OnSetBarCode(QString str)
{
    m_StateBar.SetBarCode(str);
}

void ELMainWindowObj::InitUI()
{
    if(m_bInit)
        return ;

    auto & Tr = TranslationES::Instance();

    m_MainW.setCentralWidget(&m_SeeW);

    QMenuBar * pMenu = new QMenuBar;
    m_MainW.setMenuBar(pMenu);
    QMenu *menu= new QMenu(Tr.GetTr("Tool"));
    QAction * pShow = new QAction(Tr.GetTr("ShowTool"));
    menu->addAction(pShow);
    connect(pShow,SIGNAL(triggered(bool)), this, SLOT(ShowToolBar(bool)));
    QAction * pHide = new QAction(Tr.GetTr("HideTool"));
    menu->addAction(pHide);
    connect(pHide, SIGNAL(triggered(bool)), this, SLOT(HideToolBar(bool)));
    pMenu->addMenu(menu);

    m_pPropertyView = new EFPropertyView();
    m_pPropertyDock = new NXDockWidget(tr("PropertyFrame"));
    m_pPropertyDock->setWidget((QWidget *)m_pPropertyView->GetTreeWidget());
    //      m_pPropertyDock->setMinimumSize(200,200);
    //      m_pPropertyDock->setMaximumSize(400,400);

    //文本输出
    m_pTextDock = new NXDockWidget(Tr.GetTr("OutFrame"));
    m_pTextDock->setWidget(&m_Edit);
    //     m_pTextDock->setMinimumWidth(200);

    m_pELDock  = new NXDockWidget(Tr.GetTr("ELTotalFrame"));
    m_pELDock->setWidget((QWidget *)&m_ELTotal);
    //     m_pELDock->setMinimumWidth(200);
    DefectBtnModel &db = DefectBtnModel::Instance();

    QStringList strELHeaders;
    strELHeaders<<"OK";
    strELHeaders<<"NG";
    for(int i = 0; i < db.m_EL_Titles.size(); ++i)
    {
        strELHeaders<<db.m_EL_Titles[i].c_str();

    }
    m_ELTotal.InitHeaders(strELHeaders);

    //统计模块
    m_pTotalDock = new NXDockWidget(Tr.GetTr("TotalFrame"));
    m_pTotalDock->setWidget(&m_TotalAction);
    //    m_pTotalDock->setMinimumSize(200,200);
    //    m_pTotalDock->setMaximumSize(200,200);

    m_pPropertyView->SetFirstColumnRatio(0.4f);
    m_pPropertyParser = new EFPropertyParser(m_pPropertyView);
    auto  bFunc = std::bind(&ELMainWindowObj::CallBackDataChanged, this, std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4);
    m_pPropertyParser->SetDataCallBack(bFunc);

    m_MainW.setWindowTitle(Tr.GetTr("PicW1"));
    m_MainW.addDockWidget(Qt::RightDockWidgetArea,m_pPropertyDock);
    m_MainW.addDockWidget(Qt::RightDockWidgetArea,m_pTotalDock);
    m_MainW.addDockWidget(Qt::RightDockWidgetArea,m_pELDock);
    m_MainW.addDockWidget(Qt::RightDockWidgetArea,m_pTextDock);
    InitToolBar();
    InitStateBar();

    //读取通用
    m_pStruct = EFStructDefineLoad::ReadStructFile("ModuleConfig/user_struct.xml");
    m_pDefine = EFStructDefineLoad::ReadDefineFile("ModuleConfig/user_Define.xml");

    //初始化属性表
    InitModel();


    m_bInit = true;
}

void ELMainWindowObj::ShowToolBar(bool)
{
    for(int i = 0;i<m_vTools.size(); ++i)
    {
        m_vTools[i]->setHidden(false);
    }
}

void ELMainWindowObj::HideToolBar(bool)
{
    for(int i = 0;i<m_vTools.size(); ++i)
    {
        m_vTools[i]->setHidden(true);
    }

}



void ELMainWindowObj::InitToolBar()
{
    QToolBar * pToolBar1 = m_MainW.addToolBar("1");
    m_vTools.push_back(pToolBar1);
    m_pStartAction = new StartAction;
    pToolBar1->addWidget(m_pStartAction);




    QToolBar * pToolBar3 = m_MainW.addToolBar("3");
    m_vTools.push_back(pToolBar3);
    m_pELCmdAction = new ELCmdAction;
    pToolBar3->addWidget(m_pELCmdAction);


    QToolBar * pToolBar2 = m_MainW.addToolBar("2");
    m_vTools.push_back(pToolBar2);
    m_pSysAction = new SysSetAction;
    pToolBar2->addWidget(m_pSysAction);



}

void ELMainWindowObj::InitStateBar()
{
    m_MainW.statusBar()->setMinimumHeight(40);
    m_MainW.statusBar()->addWidget(&m_StateBar);

}

void ELMainWindowObj::CallBackDataChanged(string strKindType, Data *pData, string strID, string newValue)
{
    pData->SetValue(strID.c_str(),newValue.c_str());
}


void ELMainWindowObj::SetEL_NG_cmd(bool cmd)
{
    if(cmd)
    {
        m_pELCmdAction->on_Btn_OK_clicked();
    }
    else
    {
        m_pELCmdAction->on_Btn_NG_clicked();
    }
}

bool ELMainWindowObj::getIsYl()
{
    return m_pSysAction->getIsYl();
}
bool ELMainWindowObj::getIsXh()
{
    return m_pSysAction->getIsXh();
}

bool ELMainWindowObj::getIsOther()
{
    return m_pSysAction->getIsOther();
}
