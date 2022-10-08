#include "../../../../mk_utils/src/mk_setup.h"

#include <limits.h> /* UINT_MAX */


#define mk_uint_private_cast_to_long(x) ((unsigned long int)(x))
#define mk_uint_private_cast_to_long_32(x) mk_uint_private_cast_to_long(mk_uint_private_cast_to_long(x) & mk_uint_private_cast_to_long(0xfffffffful))

#define mk_uint_private_cast_to_llong(x) ((unsigned long long int)(x))
#define mk_uint_private_cast_to_llong_32(x) mk_uint_private_cast_to_llong(mk_uint_private_cast_to_llong(x) & mk_uint_private_cast_to_llong(0xfffffffful))
#define mk_uint_private_cast_to_llong_hi(x) mk_uint_private_cast_to_llong(mk_uint_private_cast_to_llong_32(x) << (1 * 32))
#define mk_uint_private_cast_to_llong_lo(x) mk_uint_private_cast_to_llong(mk_uint_private_cast_to_llong_32(x) << (0 * 32))

#define mk_uint_private_cast_to_128(x) ((unsigned __int128)(x))
#define mk_uint_private_cast_to_128_32(x) mk_uint_private_cast_to_128(mk_uint_private_cast_to_128(x) & mk_uint_private_cast_to_128(0xfffffffful))
#define mk_uint_private_cast_to_128_hihi(x) mk_uint_private_cast_to_128(mk_uint_private_cast_to_128_32(x) << (3 * 32))
#define mk_uint_private_cast_to_128_hilo(x) mk_uint_private_cast_to_128(mk_uint_private_cast_to_128_32(x) << (2 * 32))
#define mk_uint_private_cast_to_128_lohi(x) mk_uint_private_cast_to_128(mk_uint_private_cast_to_128_32(x) << (1 * 32))
#define mk_uint_private_cast_to_128_lolo(x) mk_uint_private_cast_to_128(mk_uint_private_cast_to_128_32(x) << (0 * 32))


#if mk_uint_bits <= 8
#include "../base/mk_uint_macro_base_char.h"
#define mk_uint_small_bits 8
#if mk_uint_bits == 8
#define mk_uint8_c(a) {((unsigned char)(mk_uint_private_cast_to_long_32(a)))}
#endif
#elif mk_uint_bits <= 16
#include "../base/mk_uint_macro_base_short.h"
#define mk_uint_small_bits 16
#if mk_uint_bits == 16
#define mk_uint16_c(a) {((unsigned short int)(mk_uint_private_cast_to_long_32(a)))}
#endif
#elif mk_uint_bits <= 32
#if UINT_MAX >= 0xfffffffful
#include "../base/mk_uint_macro_base_int.h"
#define mk_uint_small_bits 32
#if mk_uint_bits == 32
#define mk_uint32_c(a) {((unsigned int)(mk_uint_private_cast_to_long_32(a)))}
#endif
#else
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#if mk_uint_bits == 32
#define mk_uint32_c(a) {((unsigned long int)(mk_uint_private_cast_to_long_32(a)))}
#endif
#endif
#elif mk_uint_bits <= 64
#if mk_has_long_long
#include "../base/mk_uint_macro_base_llong.h"
#define mk_uint_small_bits 64
#if mk_uint_bits == 64
#define mk_uint64_c(a, b) {((unsigned long long int)(mk_uint_private_cast_to_llong(mk_uint_private_cast_to_llong_hi(a) | mk_uint_private_cast_to_llong_lo(b))))}
#endif
#elif UINT_MAX >= 0xfffffffful
#include "../base/mk_uint_macro_base_int.h"
#define mk_uint_small_bits 32
#if mk_uint_bits == 64
#define mk_uint64_c(a, b) {{((unsigned int)(mk_uint_private_cast_to_long_32(b))), ((unsigned int)(mk_uint_private_cast_to_long_32(a)))}}
#endif
#else
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#if mk_uint_bits == 64
#define mk_uint64_c(a, b) {{((unsigned long int)(mk_uint_private_cast_to_long_32(b))), ((unsigned long int)(mk_uint_private_cast_to_long_32(a)))}}
#endif
#endif
#elif mk_uint_bits <= 128
#if mk_has_128bit_int
#include "../base/mk_uint_macro_base_128.h"
#define mk_uint_small_bits 128
#if mk_uint_bits == 128
#define mk_uint128_c(a, b, c, d) {((unsigned __int128)(mk_uint_private_cast_to_128(mk_uint_private_cast_to_128_hihi(a) | mk_uint_private_cast_to_128_hilo(b) | mk_uint_private_cast_to_128_lohi(c) | mk_uint_private_cast_to_128_lolo(d))))}
#endif
#elif mk_has_long_long
#include "../base/mk_uint_macro_base_llong.h"
#define mk_uint_small_bits 64
#if mk_uint_bits == 128
#define mk_uint128_c(a, b, c, d) {{((unsigned long long int)(mk_uint_private_cast_to_llong(mk_uint_private_cast_to_llong_hi(c) | mk_uint_private_cast_to_llong_lo(d)))), ((unsigned long long int)(mk_uint_private_cast_to_llong(mk_uint_private_cast_to_llong_hi(a) | mk_uint_private_cast_to_llong_lo(b))))}}
#endif
#elif UINT_MAX >= 0xfffffffful
#include "../base/mk_uint_macro_base_int.h"
#define mk_uint_small_bits 32
#if mk_uint_bits == 128
#define mk_uint128_c(a, b, c, d) {{((unsigned int)(mk_uint_private_cast_to_long_32(d))), ((unsigned int)(mk_uint_private_cast_to_long_32(c))), ((unsigned int)(mk_uint_private_cast_to_long_32(b))), ((unsigned int)(mk_uint_private_cast_to_long_32(a)))}}
#endif
#else
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#if mk_uint_bits == 128
#define mk_uint128_c(a, b, c, d) {{((unsigned long int)(mk_uint_private_cast_to_long_32(d))), ((unsigned long int)(mk_uint_private_cast_to_long_32(c))), ((unsigned long int)(mk_uint_private_cast_to_long_32(b))), ((unsigned long int)(mk_uint_private_cast_to_long_32(a)))}}
#endif
#endif
#else
#if mk_has_128bit_int
#include "../base/mk_uint_macro_base_128.h"
#define mk_uint_small_bits 128
#elif mk_has_long_long
#include "../base/mk_uint_macro_base_llong.h"
#define mk_uint_small_bits 64
#elif UINT_MAX >= 0xfffffffful
#include "../base/mk_uint_macro_base_int.h"
#define mk_uint_small_bits 32
#else
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#endif
#endif


#define mk_uint_macro_exact_concat_impl(a, b) a ## b
#define mk_uint_macro_exact_concat(a, b) mk_uint_macro_exact_concat_impl(a, b)


#define mk_uint_t struct mk_uint_macro_exact_concat(mk_uint_macro_exact_concat(mk_uint, mk_uint_bits), _s)


#include "mk_uint_macro_exact.h"
