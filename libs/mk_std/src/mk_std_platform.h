#ifndef mk_include_guard_std_platform
#define mk_include_guard_std_platform


#define mk_std_platform_arch_x8616 1000
#define mk_std_platform_arch_x8632 1001
#define mk_std_platform_arch_x8664 1002
#define mk_std_platform_arch_ia64 1003
#define mk_std_platform_arch_alpha 1004
#define mk_std_platform_arch_ppc 1005
#define mk_std_platform_arch_mips 1006
#define mk_std_platform_arch_arm 1007
#define mk_std_platform_arch_arm64 1008
#ifndef mk_std_platform_arch
#ifdef _M_ARM64
#define mk_std_platform_arch mk_std_platform_arch_arm64
#else
#ifdef _M_ARM
#define mk_std_platform_arch mk_std_platform_arch_arm
#else
#ifdef _M_MRX000
#define mk_std_platform_arch mk_std_platform_arch_mips
#else
#if defined(_M_PPC) || defined(_M_MPPC)
#define mk_std_platform_arch mk_std_platform_arch_ppc
#else
#ifdef _M_ALPHA
#define mk_std_platform_arch mk_std_platform_arch_alpha
#else
#ifdef _M_IA64
#define mk_std_platform_arch mk_std_platform_arch_ia64
#else
#if defined(_M_X64) || defined(_M_AMD64) || defined(__amd64__)
#define mk_std_platform_arch mk_std_platform_arch_x8664
#else
#if (defined(_M_IX86) && !defined(_M_I86)) || defined(__i386__)
#define mk_std_platform_arch mk_std_platform_arch_x8632
#else
#if defined(_M_I86) || defined(M_I86)
#define mk_std_platform_arch mk_std_platform_arch_x8616
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif


#define mk_std_platform_os_16 2000
#define mk_std_platform_os_32 2001
#define mk_std_platform_os_64 2002
#ifndef mk_std_platform_os
#if mk_std_platform_arch == mk_std_platform_arch_x8616
#define mk_std_platform_os mk_std_platform_os_16
#elif mk_std_platform_arch == mk_std_platform_arch_x8632 || mk_std_platform_arch == mk_std_platform_arch_alpha || mk_std_platform_arch == mk_std_platform_arch_ppc || mk_std_platform_arch == mk_std_platform_arch_mips || mk_std_platform_arch == mk_std_platform_arch_arm
#define mk_std_platform_os mk_std_platform_os_32
#elif mk_std_platform_arch == mk_std_platform_arch_x8664 || mk_std_platform_arch == mk_std_platform_arch_ia64 || mk_std_platform_arch == mk_std_platform_arch_arm64
#define mk_std_platform_os mk_std_platform_os_64
#endif
#endif


#define mk_std_platform_mm_tiny 3000
#define mk_std_platform_mm_small 3001
#define mk_std_platform_mm_compact 3002
#define mk_std_platform_mm_medium 3003
#define mk_std_platform_mm_large 3004
#define mk_std_platform_mm_huge 3005
#if defined(_M_I86TM)
#define mk_std_platform_mm mk_std_platform_mm_tiny
#elif defined(_M_I86SM)
#define mk_std_platform_mm mk_std_platform_mm_small
#elif defined(_M_I86CM)
#define mk_std_platform_mm mk_std_platform_mm_compact
#elif defined(_M_I86MM)
#define mk_std_platform_mm mk_std_platform_mm_medium
#elif defined(_M_I86LM)
#define mk_std_platform_mm mk_std_platform_mm_large
#elif defined(_M_I86HM)
#define mk_std_platform_mm mk_std_platform_mm_huge
#endif


#endif
