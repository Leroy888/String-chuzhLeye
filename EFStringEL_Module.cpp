#include "EFStringEL_Module.h"
#include "Tool/VarType.h"
#include "EFComm/EFPluginModule/EFIPluginManager.h"
#include "EFComm/EFPluginModule/EFILogModule.h"
#include "EFComm/EFPluginModule/EFIAlg230WModule.h"
#include "EFComm/EFPluginModule/EFIAlg2000WModule.h"
#include "EFComm/EFPluginModule/EFIToupCameraModule.h"
#include "EFComm/EFPluginModule/EFIMindVisionCameraModule.h"
#include<QApplication>
#include "Model/DefectBtnModel.h"
#include "View/MesLogin.h"
#pragma execution_character_set("utf-8")
EFStringEL_Module::EFStringEL_Module(EFIPluginManager *p)
    :m_bQuit(false),m_pController(nullptr)
{
     m_pPluginManager = p;
}

bool EFStringEL_Module::Awake()
{
    return true;
}

bool EFStringEL_Module::Init()
{

    m_pController = new LogicController;

    return true;
}

bool EFStringEL_Module::Shut()
{
    if(m_pController)
    {
        delete m_pController;
        m_pController = nullptr;
    }
    return true;
}

bool EFStringEL_Module::BeforeShut()
{
    return true;
}
#include <QDebug>
bool EFStringEL_Module::AfterInit()
{

    EFIFxComModule * pCom =  m_pPluginManager->FindModule<EFIFxComModule>();
    EFILogModule   * pLog = m_pPluginManager->FindModule<EFILogModule>();
    EFIMindVisionCameraModule * pMV = m_pPluginManager->FindModule<EFIMindVisionCameraModule>();
    EFIAlg230WModule    * p230W = m_pPluginManager->FindModule<EFIAlg230WModule>();

    assert(pMV&&pCom&&pLog&&p230W);

    //普通用户
    m_pController->OnInit(pCom, pLog,pMV,p230W);

    DefectBtnModel &df = DefectBtnModel::Instance();
//    if(df.m_bCheck)
//    {
//        MesLogin login;
//        int nRet = login.exec();
//        if(nRet == 1)
//        {
//            m_pController->OnShow(1);
//            m_pController->OnUser(login.m_strUser);
//        }
//        else
//        {
//            m_bQuit = true;
//        }
//    }
//    else
    {
        Login login;
        int nRet = login.exec();
        if(nRet == 1 ||nRet == 2)
        {
            m_pController->OnShow(nRet);

        }
        else
        {
            m_bQuit = true;
        }
    }



    return true;

}

bool EFStringEL_Module::Execute()
{
    if(m_bQuit)
    {
        qApp->quit();
    }

	m_pController->OnExecute();
    return true;
}
