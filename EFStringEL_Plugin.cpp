#include "EFStringEL_Plugin.h"
#include "EFStringEL_Module.h"
#pragma execution_character_set("utf-8")

#ifdef EF_DYNAMIC_PLUGIN

EF_EXPORT void DllStartPlugin(EFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, EFStringEL_Plugin)
};

EF_EXPORT void DllStopPlugin(EFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, EFStringEL_Plugin)
};

#endif
const int EFStringEL_Plugin::GetPluginVersion()
{
    return 10000;
}

const std::string EFStringEL_Plugin::GetPluginName()
{
    return GET_CLASS_NAME(EFHighEL_Plugin);
}

void EFStringEL_Plugin::Install()
{
    REGISTER_MODULE(m_pPluginManager, EFIModule, EFStringEL_Module);
}

void EFStringEL_Plugin::Uninstall()
{
    UNREGISTER_MODULE(m_pPluginManager, EFIModule, EFStringEL_Module);
}



