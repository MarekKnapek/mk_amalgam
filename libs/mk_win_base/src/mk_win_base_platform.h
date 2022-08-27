#ifndef mk_include_guard_win_base_platform
#define mk_include_guard_win_base_platform


#define mk_win_base_platform_arch_x8616 1000
#define mk_win_base_platform_arch_x8632 1001
#define mk_win_base_platform_arch_x8664 1002
#define mk_win_base_platform_arch_ia64 1003
#define mk_win_base_platform_arch_alpha 1004
#define mk_win_base_platform_arch_ppc 1005
#define mk_win_base_platform_arch_mips 1006
#define mk_win_base_platform_arch_arm 1007
#define mk_win_base_platform_arch_arm64 1008
#ifndef mk_win_base_platform_arch
#ifdef _M_ARM64
#define mk_win_base_platform_arch mk_win_base_platform_arch_arm64
#else
#ifdef _M_ARM
#define mk_win_base_platform_arch mk_win_base_platform_arch_arm
#else
#ifdef _M_MRX000
#define mk_win_base_platform_arch mk_win_base_platform_arch_mips
#else
#if defined(_M_PPC) || defined(_M_MPPC)
#define mk_win_base_platform_arch mk_win_base_platform_arch_ppc
#else
#ifdef _M_ALPHA
#define mk_win_base_platform_arch mk_win_base_platform_arch_alpha
#else
#ifdef _M_IA64
#define mk_win_base_platform_arch mk_win_base_platform_arch_ia64
#else
#if defined(_M_X64) || defined(_M_AMD64) || defined(__amd64__)
#define mk_win_base_platform_arch mk_win_base_platform_arch_x8664
#else
#if (defined(_M_IX86) && !defined(_M_I86)) || defined(__i386__)
#define mk_win_base_platform_arch mk_win_base_platform_arch_x8632
#else
#if defined(_M_I86) || defined(M_I86)
#define mk_win_base_platform_arch mk_win_base_platform_arch_x8616
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


#define mk_win_base_platform_os_win16 2000
#define mk_win_base_platform_os_win32 2001
#define mk_win_base_platform_os_win64 2002
#ifndef mk_win_base_platform_os
#if mk_win_base_platform_arch == mk_win_base_platform_arch_x8616
#define mk_win_base_platform_os mk_win_base_platform_os_win16
#elif mk_win_base_platform_arch == mk_win_base_platform_arch_x8632 || mk_win_base_platform_arch == mk_win_base_platform_arch_alpha || mk_win_base_platform_arch == mk_win_base_platform_arch_ppc || mk_win_base_platform_arch == mk_win_base_platform_arch_mips || mk_win_base_platform_arch == mk_win_base_platform_arch_arm
#define mk_win_base_platform_os mk_win_base_platform_os_win32
#elif mk_win_base_platform_arch == mk_win_base_platform_arch_x8664 || mk_win_base_platform_arch == mk_win_base_platform_arch_ia64 || mk_win_base_platform_arch == mk_win_base_platform_arch_arm64
#define mk_win_base_platform_os mk_win_base_platform_os_win64
#endif
#endif


#define mk_win_base_platform_osver_30 3000
#define mk_win_base_platform_osver_31 3001
#define mk_win_base_platform_osver_35 3002
#define mk_win_base_platform_osver_40 3003
#define mk_win_base_platform_osver_50 3004
#define mk_win_base_platform_osver_51 3005
#ifndef mk_win_base_platform_osver
#if mk_win_base_platform_os == mk_win_base_platform_os_win16
#define mk_win_base_platform_osver mk_win_base_platform_osver_30
#elif mk_win_base_platform_os == mk_win_base_platform_os_win32
#define mk_win_base_platform_osver mk_win_base_platform_osver_31
#elif mk_win_base_platform_os == mk_win_base_platform_os_win64
#define mk_win_base_platform_osver mk_win_base_platform_osver_51
#endif
#endif


#endif
