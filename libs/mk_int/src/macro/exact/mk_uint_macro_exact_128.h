#include "../../../../mk_utils/src/mk_setup.h"

#include <limits.h> /* CHAR_BIT ULLONG_MAX ULONG_MAX */


#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif


#if CHAR_BIT == 8
#if mk_uint_has_128bit_int
#include "../base/mk_uint_macro_base_128.h"
#define mk_uint_small_bits 128
#define mk_uint128_c(a, b, c, d) {(((unsigned __int128)a) << 96) | (((unsigned __int128)b) << 64) | (((unsigned __int128)c) << 32) | (((unsigned __int128)d) << 0)}
#else
#if mk_uint_has_long_long
#if ULLONG_MAX == 0xffffffffffffffff
#include "../base/mk_uint_macro_base_llong.h"
#define mk_uint_small_bits 64
#define mk_uint128_c(a, b, c, d) {{(((unsigned long long)c) << 32) | (((unsigned long long)d) << 0), (((unsigned long long)a) << 32) | (((unsigned long long)b) << 0)}}
#endif
#else
#if ULONG_MAX == 0xffffffff
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#define mk_uint128_c(a, b, c, d) {{d, c, b, a}}
#endif
#endif
#endif
#endif


#define mk_uint_bits 128
#define mk_uint_t struct mk_uint128_s


#include "mk_uint_macro_exact.h"


#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
