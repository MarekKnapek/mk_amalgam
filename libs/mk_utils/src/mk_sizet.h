#ifndef mk_include_guard_sizet
#define mk_include_guard_sizet


#include "mk_utils_platform.h"


#if mk_utils_platform_os == mk_utils_platform_os_16
typedef unsigned short int mk_size_t;
#elif mk_utils_platform_os == mk_utils_platform_os_32
typedef unsigned long int mk_size_t;
#elif mk_utils_platform_os == mk_utils_platform_os_64
typedef unsigned long long int mk_size_t;
#endif


#endif
