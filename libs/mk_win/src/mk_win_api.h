#ifndef mk_include_guard_win_api
#define mk_include_guard_win_api


#include "../../mk_win_base/src/mk_win_base_platform.h"


#define mk_win_api_old 1000
#define mk_win_api_ansi 1001
#define mk_win_api_wide 1002
#define mk_win_api_both 1003
#ifndef mk_win_api
#if mk_win_base_platform_os == mk_win_base_platform_os_win16
#define mk_win_api mk_win_api_old
#elif mk_win_base_platform_os == mk_win_base_platform_os_win32 && mk_win_base_platform_arch == mk_win_base_platform_arch_x8632
#define mk_win_api mk_win_api_both
#elif mk_win_base_platform_os == mk_win_base_platform_os_win32 && mk_win_base_platform_arch != mk_win_base_platform_arch_x8632
#define mk_win_api mk_win_api_wide
#elif mk_win_base_platform_os == mk_win_base_platform_os_win64
#define mk_win_api mk_win_api_wide
#endif
#endif


#endif
