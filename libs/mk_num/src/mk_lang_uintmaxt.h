#ifndef mk_detail_include_guard_lang_uintmaxt
#define mk_detail_include_guard_lang_uintmaxt


#if defined(__cplusplus) && __cplusplus >= 201103l
#define mk_lang_uintmaxt_has 1
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901l
#define mk_lang_uintmaxt_has 1
#else
#define mk_lang_uintmaxt_has 0
#endif

#if mk_lang_uintmaxt_has == 0
#define mk_lang_uintmax_t unsigned long int
#define mk_lang_sintmax_t signed long int
#else
#if defined(__cplusplus)
#include <cstdint>
#else
#include <stdint.h>
#endif
#define mk_lang_uintmax_t uintmax_t
#define mk_lang_sintmax_t intmax_t
#endif


#endif
