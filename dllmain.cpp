#include "EFComm/EFPluginModule/EFPlatform.h"

#if EF_PLATFORM == EF_PLATFORM_WIN
#pragma comment( lib, "Dbghelp.lib" )

#endif


#ifdef EF_DEBUG_MODE

#if EF_PLATFORM == EF_PLATFORM_WIN

#ifdef EF_DYNAMIC_PLUGIN
#pragma comment( lib, "EFGuiLib_d.lib" )
#else
#pragma comment( lib, "EFGuiLib_d.lib" )
#endif

//
#elif EF_PLATFORM == EF_PLATFORM_LINUX || EF_PLATFORM == EF_PLATFORM_ANDROID
#pragma comment( lib, "EFCore_d.a" )

#elif EF_PLATFORM == NF_PLATFORM_APPLE || EF_PLATFORM == NF_PLATFORM_APPLE_IOS
#endif

#else

#if EF_PLATFORM == EF_PLATFORM_WIN
#ifdef EF_DYNAMIC_PLUGIN
#pragma comment( lib, "EFGuiLib.lib" )

#else
#pragma comment( lib, "EFGuiLib.lib" )
#endif

//
#elif EF_PLATFORM == EF_PLATFORM_LINUX || EF_PLATFORM == EF_PLATFORM_ANDROID
#pragma comment( lib, "EFCore.a" )

#elif EF_PLATFORM == EF_PLATFORM_APPLE || EF_PLATFORM == EF_PLATFORM_APPLE_IOS
#endif

#endif
