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
#include "mk_lang_lllong.h"
#define mk_lang_uintmax_t mk_lang_ulllong_t
#define mk_lang_sintmax_t mk_lang_slllong_t
#else
#if defined(__cplusplus)
#include <cstdint> /* uintmax_t intmax_t */
#else
#include <stdint.h> /* uintmax_t intmax_t */
#endif
#define mk_lang_uintmax_t uintmax_t
#define mk_lang_sintmax_t intmax_t
#endif


#endif
