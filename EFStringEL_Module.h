// -------------------------------------------------------------------------
//    @FileName         :    EFHighEL_Module.h
//    @Author           :    FeiFei.Yang
//    @Date             :	 2017-08-15
//    @Module           :   EFHighEL_Module
//	  @Version			:    1.0.0
// -------------------------------------------------------------------------

#ifndef EFStringEL_MODULE_H
#define EFStringEL_MODULE_H
#include "EFComm/EFPluginModule/EFIModule.h"
#include "EFComm/EFPluginModule/EFIFxComModule.h"
#include "Controller/LogicController.h"

#include "View/Login.h"


class EFStringEL_Module:public EFIModule
{

public:
    EFStringEL_Module(EFIPluginManager *p);
    virtual ~EFStringEL_Module(){}

    virtual bool Awake();
    virtual bool Init();
    virtual bool Shut();

    virtual bool BeforeShut();
    virtual bool AfterInit();

    virtual bool Execute();

private:

    LogicController *    m_pController;


    bool  m_bQuit;

};

#endif // EFHighELAndLook_MODULE_H
