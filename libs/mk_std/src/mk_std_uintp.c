#include "mk_std_uintp.h"

#include "mk_std_platform.h"


#if mk_std_platform_os == mk_std_platform_os_16 && (mk_std_platform_mm == mk_std_platform_mm_tiny || mk_std_platform_mm == mk_std_platform_mm_small || mk_std_platform_mm == mk_std_platform_mm_compact)
#elif mk_std_platform_os == mk_std_platform_os_32 || (mk_std_platform_os == mk_std_platform_os_16 && (mk_std_platform_mm == mk_std_platform_mm_medium || mk_std_platform_mm == mk_std_platform_mm_large || mk_std_platform_mm == mk_std_platform_mm_huge))
#elif mk_std_platform_os == mk_std_platform_os_64
#endif
