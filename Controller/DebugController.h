#ifndef DEBUGCONTROLLER_H
#define DEBUGCONTROLLER_H
#include <QObject>

#include "View/NXMainWindow.h"
#include "EFProperty/EFPropertyView.h"
#include "EFProperty/EFPropertyParser.h"
#include <QGraphicsWidget>
#include "View/DebugSelectCirc.h"
#include "Model/ControlModel.h"
#include "EFComm/EFPluginModule/EFIAlg230WModule.h"
#include "EFComm/EFPluginModule/EFIAlg2000WModule.h"


class LogicController;
//参数调试类
class DebugController:QObject
{
    Q_OBJECT
public:
    explicit DebugController(QObject *parent = 0);

    //导入算法
    void OnInitAlg( EFIAlg2000WModule * p2000, EFIAlg230WModule * p230);

    //显示界面
    void  OnShow(const char * filePath,LogicController * pLogic);
    //是否激活
    bool  IsActive();
    //保存配置
    void  OnSave();

    //加载图片EL
    void  OnLoadImageEL(vector<void*> buffers,int nIndex);

    //加载外观图片
    void  OnLoadImageLook(vector<void*> buffers,int nIndex);

private:
    //数据初始化
    void        OnInitModel();
    //初始化界面
    void        OnInitView();
    //属性表回调
    void    CallBackDataChanged(string strKindType, Data *pData, string strID, string newValue);

private:
    //主窗口
    NXMainWindow        m_MainDlg;
    EFPropertyView   *  m_pPropertyView;
    EFPropertyParser *  m_pPropertyParser;
    NXDockWidget  *     m_pPropertyDock;

    EFPropertyView   *  m_pPropertyViewEL;
    EFPropertyParser *  m_pPropertyParserEL;
    NXDockWidget  *     m_pPropertyDockEL;

    EFPropertyView   *  m_pPropertyViewLook;
    EFPropertyParser *  m_pPropertyParserLook;
    NXDockWidget  *     m_pPropertyDockLook;
    //中间窗口
    QTabWidget  *       m_pCenterTabWidget;


    //外观调试显示界面
    DebugSelectCirc *   m_pLookDebugWidget;
    //EL调试显示界面
    DebugSelectCirc *   m_pELDebugWidget;

    //数据
    ControlModel        m_Model;
    //基础属性表
    IStruct        *    m_pStruct;
    IDefine        *    m_pDefine;

    //EL算法属性表
    IStruct        *    m_pELStruct;
    IDefine        *    m_pELDefine;

    //LOOK算法属性表
    IStruct       *     m_pLookStruct;
    IDefine       *     m_pLookDefine;

    //算法
    EFIAlg2000WModule  *         m_pAlg2000;
    EFIAlg230WModule   *         m_pAlg230;

    LogicController     *        m_pMainLogic;


    //调试窗口
    QWidget                 m_Debug1;
    QWidget                 m_Debug2;
    QWidget                 m_Debug3;
    QWidget                 m_Debug4;
    QWidget                 m_Debug5;
private:

private slots:
    //保存
    void    slot_save(bool);
    //另存为
    void    slot_save_other(bool);

    void    slot_Close_windows();

};

#endif // DEBUGCONTROLLER_H
