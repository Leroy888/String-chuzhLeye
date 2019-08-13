#include "DebugController.h"
#include "Tool/TranslationES.h"
#include "View/NXDockWidget.h"
#include "Tool/EFStructDefineLoad.h"
#include <functional>
#include "Tool/Data.h"
#include <QToolBar>
#include <QMessageBox>
#include "View/FileNameDialog.h"
#include "Tool/Utility.h"
#include  "EFGui/EFGuiLib/EFProperty/EFTreeWidget.h"
#include "LogicController.h"
#pragma execution_character_set("utf-8")

DebugController::DebugController(QObject *parent)
    :QObject(parent),m_pCenterTabWidget(nullptr),m_pMainLogic(nullptr)
{
    OnInitModel();

    connect(&m_MainDlg, SIGNAL(sigClose()), this, SLOT(slot_Close_windows()));
}

void DebugController::OnInitAlg(EFIAlg2000WModule *p2000, EFIAlg230WModule *p230)
{
    m_pAlg2000 = p2000;
    m_pAlg230 = p230;
}

void DebugController::OnShow(const char *filePath, LogicController *pLogic)
{
    if(!filePath||!pLogic)
        return ;

    m_pMainLogic = pLogic;
    //加载数据
    m_Model.Close();
    m_Model.OnLoad(filePath);

    OnInitView();

    m_pPropertyView->GetTreeWidget()->show();
    m_pPropertyViewEL->GetTreeWidget()->show();
    m_pPropertyViewLook->GetTreeWidget()->show();
    //属性表绑定
    m_pPropertyParser->SetData(m_Model.GetObj(),m_pStruct, m_pDefine);
    m_pPropertyParserEL->SetData(m_Model.GetObj(),m_pELStruct,m_pELDefine);
    m_pPropertyParserLook->SetData(m_Model.GetObj(),m_pLookStruct, m_pLookDefine);

    //m_pPropertyParser->SetData(m_Model.GetObj(),m_pStruct, m_pDefine);

    m_MainDlg.show();
}

bool DebugController::IsActive()
{
    return !m_MainDlg.isHidden();
}

void DebugController::OnSave()
{
    m_Model.Save();
}

void DebugController::OnLoadImageEL(vector<void *> buffers, int nIndex)
{
    m_pELDebugWidget->OnInitLoadImage(buffers,nIndex);
}

void DebugController::OnLoadImageLook(vector<void *> buffers, int nIndex)
{
    m_pLookDebugWidget->OnInitLoadImage(buffers,nIndex);
}

void DebugController::OnInitModel()
{
    //读取通用
    m_pStruct = EFStructDefineLoad::ReadStructFile("ModuleConfig/struct.xml");
    m_pDefine = EFStructDefineLoad::ReadDefineFile("ModuleConfig/Define.xml");
    //读取EL识别算法属性
    m_pELStruct =  EFStructDefineLoad::ReadStructFile("ModuleConfig/el_struct.xml");
    m_pELDefine =  EFStructDefineLoad::ReadDefineFile("ModuleConfig/el_Define.xml");


    //读取外观识别算法属性
    m_pLookStruct =  EFStructDefineLoad::ReadStructFile("ModuleConfig/look_struct.xml");
    m_pLookDefine =  EFStructDefineLoad::ReadDefineFile("ModuleConfig/look_Define.xml");
}

void DebugController::OnInitView()
{
    if(m_pCenterTabWidget)
        return ;
    auto & Tr = TranslationES::Instance();
    m_pCenterTabWidget = new QTabWidget;
    m_pPropertyView = new EFPropertyView();
    m_pPropertyParser = new EFPropertyParser(m_pPropertyView);
    m_pPropertyDock = new NXDockWidget(Tr.GetTr("BaseSetW"));
    m_pPropertyView->SetFirstColumnRatio(0.4f);

    m_pPropertyDock->setWidget((QWidget *)m_pPropertyView->GetTreeWidget());
    m_pPropertyDock->setMinimumWidth(400);

    m_pLookDebugWidget = new DebugSelectCirc;
    m_pLookDebugWidget->OnInit(&m_Model,false);
    m_pLookDebugWidget->OnInitAlg(m_pAlg2000, m_pAlg230);
    m_pELDebugWidget = new DebugSelectCirc;
    m_pELDebugWidget->OnInit(&m_Model,true);
    m_pELDebugWidget->OnInitAlg(m_pAlg2000, m_pAlg230);

    m_pLookDebugWidget->setWindowTitle(Tr.GetTr("LookDebugW"));
    m_pELDebugWidget->setWindowTitle(Tr.GetTr("ELDebugW"));

    m_pCenterTabWidget->addTab(m_pELDebugWidget,Tr.GetTr("ELDebugW"));
  //  m_pCenterTabWidget->addTab(m_pLookDebugWidget,Tr.GetTr("LookDebugW"));

    //添加调试窗口
    m_pCenterTabWidget->addTab(&m_Debug1,"Debug1");
    m_pCenterTabWidget->addTab(&m_Debug2,"Debug2");
    m_pCenterTabWidget->addTab(&m_Debug3,"Debug3");
    m_pCenterTabWidget->addTab(&m_Debug4,"Debug4");
    m_pCenterTabWidget->addTab(&m_Debug5,"Debug5");

    m_MainDlg.setCentralWidget(m_pCenterTabWidget);

    m_MainDlg.setWindowTitle(Tr.GetTr("PicW3"));
    m_MainDlg.addDockWidget(Qt::RightDockWidgetArea,m_pPropertyDock);

    m_pPropertyViewEL = new EFPropertyView();
    m_pPropertyDockEL = new NXDockWidget(Tr.GetTr("ELSetW"));
    m_pPropertyParserEL = new EFPropertyParser(m_pPropertyViewEL);
    m_pPropertyDockEL->setWidget((QWidget *)m_pPropertyViewEL->GetTreeWidget());
     m_pPropertyViewEL->SetFirstColumnRatio(0.3f);
    m_pPropertyDockEL->setMinimumWidth(400);


    m_MainDlg.addDockWidget(Qt::RightDockWidgetArea,m_pPropertyDockEL);

    m_pPropertyViewLook = new EFPropertyView();
    m_pPropertyDockLook = new NXDockWidget(Tr.GetTr("LookSetW"));
    m_pPropertyParserLook = new EFPropertyParser(m_pPropertyViewLook);
    m_pPropertyDockLook->setWidget((QWidget *)m_pPropertyViewLook->GetTreeWidget());
        m_pPropertyViewLook->SetFirstColumnRatio(0.3f);
    m_pPropertyDockLook->setMinimumWidth(400);

   // m_MainDlg.addDockWidget(Qt::RightDockWidgetArea,m_pPropertyDockLook);

    //添加action
    QToolBar * pToolBar1 = m_MainDlg.addToolBar("1");
    QAction * pSave = new QAction(QIcon("://Resources/Image/save.png"), "&Save");
    connect(pSave, SIGNAL(triggered(bool)), this, SLOT(slot_save(bool)));

    pToolBar1->addAction(pSave);
    QAction * pSaveOter = new QAction(QIcon("://Resources/Image/saveother.png"), "&SaveOter");
    connect(pSaveOter, SIGNAL(triggered(bool)), this, SLOT(slot_save_other(bool)));
    pToolBar1->addAction(pSaveOter);



    auto  bFunc = std::bind(&DebugController::CallBackDataChanged, this, std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4);
    m_pPropertyParser->SetDataCallBack(bFunc);
    m_pPropertyParserEL->SetDataCallBack(bFunc);
    m_pPropertyParserLook->SetDataCallBack(bFunc);


}

void DebugController::CallBackDataChanged(string strKindType, Data *pData, string strID, string newValue)
{
    pData->SetValue(strID.c_str(),newValue.c_str());

}

void DebugController::slot_save(bool)
{
    m_Model.Save();
    QMessageBox::information(NULL, "Title", TranslationES::Instance().GetTr("SaveOK"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}

void DebugController::slot_save_other(bool)
{
    //另存为
    std::string strFileName;
    FileNameDialog dlg;
    dlg.SetFileString(&strFileName);
    dlg.exec();
    if(strFileName.empty())
        return ;
    QString strDir = "./ModuleConfig/formula/";
    strDir += strFileName.c_str();
    strDir += ".xml";

    std::string strOutPath;
    Utility:: Utf8ToGbk(strOutPath,strDir.toStdString().c_str());
    if(strOutPath.empty())
        return ;

    ControlModel newModel;
    newModel.SetFilePath(strOutPath.c_str());
    newModel.SetData(m_Model.GetData());
    newModel.Save();
    QMessageBox::information(NULL, "Title", TranslationES::Instance().GetTr("SaveOK"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void DebugController::slot_Close_windows()
{
    m_pPropertyView->GetTreeWidget()->hide();
    m_pPropertyViewEL->GetTreeWidget()->hide();
    m_pPropertyViewLook->GetTreeWidget()->hide();
    // m_pPropertyParser->SetData();
    // m_pPropertyParser->SetData(NULL,m_pStruct, m_pDefine);
    m_Model.Close();
    
    if(m_pMainLogic)
    {
        m_pMainLogic->OnStop(false);
    }
}
