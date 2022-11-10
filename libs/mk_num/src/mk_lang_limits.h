#ifndef mk_detail_include_guard_lang_limits
#define mk_detail_include_guard_lang_limits


#if defined(__cplusplus)
#include <climits> /* CHAR_BIT UCHAR_MAX USHRT_MAX UINT_MAX ULONG_MAX ULLONG_MAX */
#else
#include <limits.h> /* CHAR_BIT UCHAR_MAX USHRT_MAX UINT_MAX ULONG_MAX ULLONG_MAX */
#endif


#define mk_lang_limits_ucharmax UCHAR_MAX
#define mk_lang_limits_ushortmax USHRT_MAX
#define mk_lang_limits_uintmax UINT_MAX
#define mk_lang_limits_ulongmax ULONG_MAX


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
#define mk_lang_limits_ullongmax ((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(1)) << (sizeof(unsigned long int) * CHAR_BIT - 1))) - 1)) << 1)) + 1))
#endif

#undef mk_lang_limits_ullongmax_has


#if defined(__cplusplus) && __cplusplus >= 201103l
#define mk_lang_limits_sizemax_has 1
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901l
#define mk_lang_limits_sizemax_has 1
#else
#define mk_lang_limits_sizemax_has 0
#endif

#if mk_lang_limits_sizemax_has != 0
#if defined(__cplusplus)
#include <cstdint> /* SIZE_MAX */
#else
#include <stdint.h> /* SIZE_MAX */
#endif
#define mk_lang_limits_sizemax SIZE_MAX
#else
#if defined(__cplusplus)
#include <cstddef> /* size_t */
#else
#include <stddef.h> /* size_t */
#endif
#define mk_lang_limits_sizemax ((size_t)(((size_t)(((size_t)(((size_t)(((size_t)(1)) << (sizeof(size_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1))
#endif

#undef mk_lang_limits_sizemax_has


#if defined(__cplusplus) && __cplusplus >= 201103l
#define mk_lang_limits_uintmaxmax_has 1
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901l
#define mk_lang_limits_uintmaxmax_has 1
#else
#define mk_lang_limits_uintmaxmax_has 0
#endif

#if mk_lang_limits_uintmaxmax_has != 0
#if defined(__cplusplus)
#include <cstdint> /* UINTMAX_MAX */
#else
#include <stdint.h> /* UINTMAX_MAX */
#endif
#define mk_lang_limits_uintmaxmax UINTMAX_MAX
#else
#define mk_lang_limits_uintmaxmax ((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(1)) << (sizeof(unsigned long int) * CHAR_BIT - 1))) - 1)) << 1)) + 1))
#endif

#undef mk_lang_limits_uintmaxmax_has


#endif
