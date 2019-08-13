
// -------------------------------------------------------------------------
//    @FileName         :    EFStringEL_Plugin.h
//    @Author           :    FeiFei.Yang
//    @Date             :	 2017-06-27
//    @Module           :   EFStringEL_Plugin
//	  @Version			:    1.0.0
// -------------------------------------------------------------------------
#ifndef EFStringEL_PLUGIN_H
#define EFStringEL_PLUGIN_H

#include "EFComm/EFPluginModule/EFIPlugin.h"
#include "EFComm/EFPluginModule/EFIPluginManager.h"


class EFStringEL_Plugin:public EFIPlugin
{
public:
    EFStringEL_Plugin(EFIPluginManager * p)
    {
         m_pPluginManager = p;
    }

    //获取版本信息
    virtual  const int  GetPluginVersion();
    //获取插件名
    virtual const std::string GetPluginName();
    //安装
    virtual  void Install();
    //卸载
    virtual  void Uninstall();
};

#endif //
