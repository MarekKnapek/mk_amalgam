#ifndef mk_include_guard_std_size_max
#define mk_include_guard_std_size_max


#if defined(__cplusplus) && __cplusplus >= 201103L
#include <cstdint>
#define mk_std_size_max SIZE_MAX
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdint.h>
#define mk_std_size_max SIZE_MAX
#else
#include <stddef.h>
#define mk_std_size_max ((size_t)(65535))
#endif


#endif
