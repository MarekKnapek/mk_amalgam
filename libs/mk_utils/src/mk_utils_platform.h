#ifndef mk_include_guard_utils_platform
#define mk_include_guard_utils_platform


#define mk_utils_platform_arch_x8616 1000
#define mk_utils_platform_arch_x8632 1001
#define mk_utils_platform_arch_x8664 1002
#define mk_utils_platform_arch_ia64 1003
#define mk_utils_platform_arch_alpha 1004
#define mk_utils_platform_arch_ppc 1005
#define mk_utils_platform_arch_mips 1006
#define mk_utils_platform_arch_arm 1007
#define mk_utils_platform_arch_arm64 1008
#if !defined(mk_utils_platform_arch)
#if defined(_M_ARM64)
#define mk_utils_platform_arch mk_utils_platform_arch_arm64
#elif defined(_M_ARM)
#define mk_utils_platform_arch mk_utils_platform_arch_arm
#elif defined( _M_MRX000)
#define mk_utils_platform_arch mk_utils_platform_arch_mips
#elif defined(_M_PPC) || defined(_M_MPPC)
#define mk_utils_platform_arch mk_utils_platform_arch_ppc
#elif defined(_M_ALPHA)
#define mk_utils_platform_arch mk_utils_platform_arch_alpha
#elif defined(_M_IA64)
#define mk_utils_platform_arch mk_utils_platform_arch_ia64
#elif defined(_M_X64) || defined(_M_AMD64) || defined(__amd64__)
#define mk_utils_platform_arch mk_utils_platform_arch_x8664
#elif (defined(_M_IX86) && !defined(_M_I86)) || defined(__i386__)
#define mk_utils_platform_arch mk_utils_platform_arch_x8632
#elif defined(_M_I86) || defined(M_I86)
#define mk_utils_platform_arch mk_utils_platform_arch_x8616
#endif
#endif


#define mk_utils_platform_os_16 2000
#define mk_utils_platform_os_32 2001
#define mk_utils_platform_os_64 2002
#if !defined(mk_utils_platform_os)
#if mk_utils_platform_arch == mk_utils_platform_arch_x8616
#define mk_utils_platform_os mk_utils_platform_os_16
#elif mk_utils_platform_arch == mk_utils_platform_arch_x8632 || mk_utils_platform_arch == mk_utils_platform_arch_alpha || mk_utils_platform_arch == mk_utils_platform_arch_ppc || mk_utils_platform_arch == mk_utils_platform_arch_mips || mk_utils_platform_arch == mk_utils_platform_arch_arm
#define mk_utils_platform_os mk_utils_platform_os_32
#elif mk_utils_platform_arch == mk_utils_platform_arch_x8664 || mk_utils_platform_arch == mk_utils_platform_arch_ia64 || mk_utils_platform_arch == mk_utils_platform_arch_arm64
#define mk_utils_platform_os mk_utils_platform_os_64
#endif
#endif


#define mk_utils_platform_mm_tiny 3000
#define mk_utils_platform_mm_small 3001
#define mk_utils_platform_mm_compact 3002
#define mk_utils_platform_mm_medium 3003
#define mk_utils_platform_mm_large 3004
#define mk_utils_platform_mm_huge 3005
#if !defined(mk_utils_platform_mm)
#if defined(_M_I86TM)
#define mk_utils_platform_mm mk_utils_platform_mm_tiny
#elif defined(_M_I86SM)
#define mk_utils_platform_mm mk_utils_platform_mm_small
#elif defined(_M_I86CM)
#define mk_utils_platform_mm mk_utils_platform_mm_compact
#elif defined(_M_I86MM)
#define mk_utils_platform_mm mk_utils_platform_mm_medium
#elif defined(_M_I86LM)
#define mk_utils_platform_mm mk_utils_platform_mm_large
#elif defined(_M_I86HM)
#define mk_utils_platform_mm mk_utils_platform_mm_huge
#endif
#endif


#endif
