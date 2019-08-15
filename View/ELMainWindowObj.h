#ifndef ELMAINWINDOWOBJ_H
#define ELMAINWINDOWOBJ_H

#include <QObject>
#include "View/NXMainWindow.h"
#include "View/NXDockWidget.h"
#include "View/SeeWidgetEL.h"
#include "EFStateBar.h"
#include <QToolBar>
#include "EFProperty/EFPropertyView.h"
#include "EFProperty/EFPropertyParser.h"

#include "StartAction.h"
#include "SysSetAction.h"
#include "ELCmdAction.h"
#include "EFComm/Unity/IOTPPublic.h"
#include <QTextEdit>
#include "View/TotalAction.h"
#include "View/ELTotal.h"

class LogicController;
class Data;
class ELMainWindowObj : public QObject
{
    Q_OBJECT
public:
    explicit ELMainWindowObj(QObject *parent = 0);

    //显示
    void    Show();

    void    InitModel();

    void    SetController(LogicController * pLogic);

    std::string  GetBarCode();
    //激活条形码
    void    EditBarCode();
    //激活按钮
    void    OnEnableBtn(bool bEnble);

    void OnUpDateImage(QImage * pImage,bool Save_AB = false);

    void  OnUpDateVecs(int nIndex, std::vector<EL_ChipStrut> &vecs);

    void  OnUpdateStartBtn(bool bState);

    void  OnELCamState(bool bOnline);

    void SetEL_NG_cmd(bool cmd);

    void  OnPlcState(bool bOnline);

    void  OnPhotoState(int nState); //-1, 0, 1, 2,3

    //禁止激活下拉框系统设置按钮
    void    OnEnableSystem(bool bEnble);

    //获取EL 选择坐标
    void OnGetELParams(vector<string> &points, std::vector<std::string> &stdCmd, std::vector<std::string> &strDetails);

    //回去JK EL
    string  OnGetJKELParams();


    void    OnSetTextInfo(bool bState,const QString & text);

    //统计
    void    OnTotalOK();

    void    OnTotalNG();
    void onTotalMissNum();
    void onTotalErrorNum();

    void OnTotalMissRate();
    void OnTotalErrorRate();
    void OnTotalNGRate();

    int getOkNum();
    int getNgNum();
    int getMissNum();
    int getErrorNum();

    void addXhNum();
    void addYlNum();
    void addYlAndXhNum();
    void addOtherNum();

    int getYlNum();
    int getXhNum();
    int getYlAndXhNum();
    int getOtherNum();

    QString getDute();
    void saveDute(QString dute);

    int getExcelOkNum();
    int getExcelNgNum();

    bool getIsYl();
    bool getIsXh();
    bool getIsOther();
    int getDelaySecs();

    //设置条码
    void    OnSetBarCode(QString str);
    void OnAI_state(bool bOnline);
    void OnTotalEL(QString nCmd);
    ELCmdAction     *   m_pELCmdAction;
    void clearExcelData(); //清除記錄Excel表格的數據
    void clearData();
    void clearElData();
private:

    //初始化UI
    void    InitUI();


    void    InitToolBar();
    void    InitStateBar();
    void    CallBackDataChanged(std::string strKindType, Data *pData, std::string strID, std::string newValue);
private:
    NXMainWindow  m_MainW;
    SeeWidgetEL     m_SeeW;
    EFStateBar    m_StateBar;
    bool          m_bInit;
    QVector<QToolBar*>  m_vTools;
    EFPropertyView   *  m_pPropertyView;
    QTextEdit           m_Edit;
    TotalAction         m_TotalAction;

    EFPropertyParser *  m_pPropertyParser;
    NXDockWidget  *     m_pPropertyDock;
    NXDockWidget   *     m_pTextDock;
    NXDockWidget    *     m_pELDock;

    NXDockWidget    *    m_pTotalDock;
    StartAction *       m_pStartAction;
    SysSetAction*       m_pSysAction;
    ELTotal             m_ELTotal;


    LogicController *   m_pLogic;

private:
    IStruct        *    m_pStruct;
    IDefine        *    m_pDefine;



signals:

public slots:
    //显示工具栏
    void    ShowToolBar(bool);
    void    HideToolBar(bool);

};

#endif // ELMAINWINDOWOBJ_H
