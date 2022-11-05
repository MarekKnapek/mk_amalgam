#ifndef mk_detail_include_guard_lang_limits
#define mk_detail_include_guard_lang_limits





#include "mk_lang_llong.h"

#if defined(__cplusplus)
#include <climits>
#else
#include <limits.h>
#endif

#if defined(__cplusplus) && __cplusplus >= 201103l
#define mk_lang_limits_ullongmax_has 1
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901l
#define mk_lang_limits_ullongmax_has 1
#else
#define mk_lang_limits_ullongmax_has 0
#endif

#if mk_lang_limits_ullongmax_has != 0
#define mk_lang_limits_ullongmax ULLONG_MAX
#else
#define mk_lang_limits_ullongmax ((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(1)) << (sizeof(mk_lang_ullong_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1))
#endif

#undef mk_lang_limits_ullongmax_has





#include "mk_lang_sizet.h"

#if defined(__cplusplus) && __cplusplus >= 201103l
#define mk_lang_limits_sizemax_has 1
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901l
#define mk_lang_limits_sizemax_has 1
#else
#define mk_lang_limits_sizemax_has 0
#endif

#if mk_lang_limits_sizemax_has != 0
#if defined(__cplusplus)
#include <cstdint>
#else
#include <stdint.h>
#endif
#define mk_lang_limits_sizemax SIZE_MAX
#else
#if defined(__cplusplus)
#include <climits>
#else
#include <limits.h>
#endif
#define mk_lang_limits_sizemax ((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(1)) << (sizeof(mk_lang_size_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1))
#endif

#undef mk_lang_limits_sizemax_has





#include "mk_lang_uintmaxt.h"

#if defined(__cplusplus) && __cplusplus >= 201103l
#define mk_lang_limits_uintmaxmax_has 1
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901l
#define mk_lang_limits_uintmaxmax_has 1
#else
#define mk_lang_limits_uintmaxmax_has 0
#endif

#if mk_lang_limits_uintmaxmax_has != 0
#if defined(__cplusplus)
#include <cstdint>
#else
#include <stdint.h>
#endif
#define mk_lang_limits_uintmaxmax UINTMAX_MAX
#else
#if defined(__cplusplus)
#include <climits>
#else
#include <limits.h>
#endif
#define mk_lang_limits_uintmaxmax ((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(1)) << (sizeof(mk_lang_uintmax_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1))
#endif

#undef mk_lang_limits_uintmaxmax_has





#endif
