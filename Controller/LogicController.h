#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

#include <QObject>
#include <QTime>
#include <QTimer>


#include "Tool/IStruct.h"
#include "Tool/IDefine.h"
#include "Model/ControlModel.h"
#include "Model/TotolModel.h"
#include "Tool/Data.h"



//模块头文件
#include "EFComm/EFPluginModule/EFIFxComModule.h"
#include "EFComm/EFPluginModule/EFILogModule.h"
#include "EFComm/EFPluginModule/EFIAlg230WModule.h"
//#include "EFComm/EFPluginModule/EFIFlyCaptureCameraModule.h"
#include  "EFComm/EFPluginModule/EFIMindVisionCameraModule.h"
#include "DebugController.h"
#include "EFComm/Unity/IOTPPublic.h"

#include "View/ELMainWindowObj.h"

#include "Model/MesObj.h"

#include "MesTool/CurlFtpHelper.h"
#include "MesTool/JKMesClient.h"
#include "ai_save_work.h"

#include "View/ELCmdAction.h"
//
//#include "HalconCpp.h"
//#include "HDevThread.h"
//using namespace HalconCpp;
//
class LogicController : public QObject
{
    friend class Woker;
    friend class WorkerOriSave;


    enum  CHECK_STATE
    {
        CHECK_FREE,
        CHECK_BARCODE,  //获取条码状态
        CHECK_BEGIN,    //开始
        CHECK_POS1,     //获取到位信号1
        CHECK_PHOTO1,   //第一次拍照状态
        CHECK_DEFECT,   //分选状态
        CHECK_END,      //检测结束
    };

    Q_OBJECT

public:
    explicit LogicController(QObject *parent = 0);

    //传入参数
    bool    OnInit(EFIFxComModule * pCom, EFILogModule * pLog,EFIMindVisionCameraModule * pMV, EFIAlg230WModule * p230);

    //循环开启重连等
    bool    OnExecute();

    //开始
    bool    OnStart();

    //停止
    bool    OnStop(bool bCall = true);

	//获取属性
	ControlModel * OnGetModel();

    //默认配置
    bool    OnLoadFile(const std::string & str);


    //有条形码 开始往下走
    void    OnHasBarCode();

    //当前EL图片的高度
    int     m_nELCurHeight;


    //保存EL 原始图片
    void    OnSaveOriginalEL();


    QString   OnGetELPath();


    void    OnSetCode(QString strCode);

    //延时函数 jin
    void sleep(unsigned int msec);

    void OnQuerybutton();

    ELCmdAction     *   m_pELCmdAction;

public:
    //登入的权限
    void    OnShow(int nPermiss);

    void    OnUser(const std::string & strUser);

    //显示调试界面
    void    OnShowDebugDlg(const char * filepath);

    //进制状态
    void    OnDisableBtn();
    ///
     void    OnDrawELImage(int nIndex);
    void OnUpdateRate();


private:
    //初始化数据
    void    InitModel();
    //初始化界面
    void    InitView();
    //初始化控制数据
    void    InitController();
    //初始化算法
    void    InitAlg();

    //开始流程
    bool    StartLogic();
    //结束流程
    bool    StopLogic();

    //参数生效
    bool    InitParams();

    bool m_RSet=false;

//    //EL界面
//    ELMainWindowObj  m_ELUIObj;

public:

    void   TestDrawEL(vector<void*> buffers);


    //功能函数
    void OnAiormansave(int nCmd);
    bool OnAi_Condition_Defect();
    void huiduzhi();
    //void Void_Weld_Check(HObject ho_Image, HObject *ho_TransRegion, HTuple hv_Areascale, HTuple hv_Circularity);
    void PLC_Reset();
    void PLC_Left_Cylinder_down(bool n);
    void PLC_Right_Cylinder_down(bool n);
    void PLC_Left_Cylinder_Clamp(bool n);
    void PLC_Right_Cylinder_Clamp(bool n);
    void PLC_Start_Up(bool n);
    void PLC_start();
private:
   // void    OnDrawELImage(int nIndex);

    void    OnDrawLookImage(int nIndex);

    std::string  GetSavePath(const std::string & strPrex, const std::string & strClass, int nCmd,bool bEL, const string &header = "");

//view
private:
    //EL界面
    ELMainWindowObj     m_ELUIObj;
    //调试界面控制
    DebugController*     m_pDebugController;


    JKMesClient         m_MesClient;
    CurlFtpHelper       m_FtpHelper;
    //加载数据
    ControlModel        m_SystemModel;

    //MES对象
    MesObj              m_MesObj;


    QImage              m_ElImage;
    QImage              m_DrawElImage;

    //算法
    vector<HALREG>      m_mELRegs;
    Data                m_ELData;

    std::string         m_strFilePath;

    bool                m_bFlow;

    string              m_strCode;
    int                 code_num;
    //AB串保存
    QString        m_SAB;

    //AI
    vector<string> m_ElAIDefect;
    vector<string> m_ElAIPosition;

    vector<string> m_AISaveDefect;
    vector<string> m_AISavePosition;

    int AI_EL_num = 1;
    int AI_EL_NGnum = 1;
    bool AI_EL_makdir = true;
    bool AI_EL_NGmakdir = true;
    QString  ai_img_path;
    QString  ai_ng_img_path;

    bool AI_OK  = false;
    bool m_Ai_Open;

    //区分人工按下OKNG按钮，还是AI按下OKNG按钮
    //人工按下硬件按钮OKNG标记 = true
    bool m_AI_btn = false;

//model
private:
    CHECK_STATE                 m_nState;
    bool                        m_bElCamOver;

    bool                        m_bElDefect;
    int                         m_nElDefect;

    int                         m_nPermission;



    //模块
    EFIFxComModule        *      m_pFxComModule;
    EFILogModule          *      m_pLog;
   // EFIFlyCaptureCameraModule*   m_pFlyCamModule;
    EFIAlg230WModule   *         m_pAlg230;
    EFIMindVisionCameraModule *  m_pMVModule;

    int m_okNum;
    int m_ngNum;
    int m_missNum;
    int m_errorNum;
    //int m_lastHour;
//    float m_errorRate;
//    float m_missRate;

//Controller
private:
      //检测状态
      void OnCheckState();
      //设置拍照1
      void OnSetPhoto1();
      //查询拍照1
      void OnQueryPhoto1();
      //获取拍照1
      void OnGetPhoto1();
      //设置拍照信号
      void OnSetPhoto2();
      //查询拍照信号
      void OnQueryPhoto2();
      //获取拍照信号2
      void OnGetPhoto2();
       //设置拍照信号3
      void OnSetPhoto3();
       //查询拍照信号3
      void OnQueryPhoto3();
       //获取拍照信号3
      void OnGetPhoto3();
      //拍照完成
      void OnSetPhotoOK();
      //拍照
      void
      OnGrab();

  //回调
private:
      //检测是否分选结束
      void CheckDefectOver();
      //相机上下线
      void CallBackELCamera(int nSerial, bool bOnline);

      //垂直翻转
      void VerFilp(std::vector<void *> &buffers);
//相机
private:
      //灰点相机
      void  onMvCamBind();
      //拍照完毕回调
      void  OnMvCamCallImageOver();

      int OK_NUM;   //ok数目
      int NG_NUM;   //NG数目
      int wuPanNum; //误判数目
      int louPanNum;//漏判数目
      int sum;      //整个AI统计数目


//EL坐标点
private:
    vector<EL_ChipStrut> m_EL1;
    vector<EL_ChipStrut> m_EL2;
    vector<EL_ChipStrut> m_EL3;

 //图片原始图片缓存
private:
    vector<void*>   m_pVELCahceImages;

private:
      //相机定时检测
      QTimer    m_CamCheckTimer;
      QTime     m_time;



      void save_el(int nCmd);

      //AI数据保存
      void OnAi_save(const QImage &image, vector<string> ElDefect, vector<string> ElPosition, int nIndex, string strPath);
      void mkdir_path(QString path);
      void HorFilp(std::vector<void *> &buffers);
      QStringList GetELSavePaths(QStringList strListDefects);

      bool getElDefect(vector<string> ElDefect, string strDef);
signals:

     void       sig_camera_el_online(bool bOnline);
     void       sig_ImageOver();

     //把图片处理从线程扔出来
     void       sig_el_img_over(int nIndex);

public slots:
      //EL照片处理完毕
      void  slot_el_img_over(int nIndex);
      //相机定时检测
      void  slot_CamCheck_timer();
      //EL相机上下线回调
      void  slot_camera_el_online(bool bOnline);
      //图片完毕
      void  slot_ImageOver();
      //EL算法回调完毕
      void  slot_ELAlgOK(int n);

      //AI自动分选
      void OnAidefect();

      //EL命令分选
      void  slot_el_cmd(int nCmd, QStringList args);

      //关闭自动分选定时器
      void slot_stopElCmdTimer();

      //保存20190514
      void  OnSaveWPEL(int nCmd, QStringList args);

      //保存完毕
      void  slot_Save_Over(QString strPath);

      void SlotImage(const QImage &image, bool bOK, vector<string> ElDefect, vector<string> ElPosition, int nIndex);
      void slot_Ai_error();

private:
      int okNum;
      int ngNum;
      int errorNum;
      int missNum;
      bool isOk;
      int myIndex;
      int myNum = 0;
      int lastHour;

      bool m_bAi_Ok;//AI判断结果

      bool m_isYl;//AI判断是否为隐裂
      bool m_isXh;//AI判断是否为虚焊
      bool m_isOther;//AI判断是否为其他

      QTimer *elCmdTimer;
};

#endif // LOGICCONTROLLER_H
