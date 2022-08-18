#include "../../../../mk_utils/src/mk_setup.h"

#include <limits.h> /* UINT_MAX ULONG_MAX */


#if mk_uint_bits <= 8
#include "../base/mk_uint_macro_base_char.h"
#define mk_uint_small_bits 8
#elif mk_uint_bits <= 16
#include "../base/mk_uint_macro_base_short.h"
#define mk_uint_small_bits 16
#elif mk_uint_bits <= 32
#if UINT_MAX >= 0xffffffffu
#include "../base/mk_uint_macro_base_int.h"
#define mk_uint_small_bits 32
#else
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#endif
#elif mk_uint_bits <= 64
#if ULONG_MAX >= 0xfffffffffffffffful
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 64
#elif mk_has_long_long
#include "../base/mk_uint_macro_base_llong.h"
#define mk_uint_small_bits 64
#elif UINT_MAX >= 0xffffffffu
#include "../base/mk_uint_macro_base_int.h"
#define mk_uint_small_bits 32
#else
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#endif
#elif mk_uint_bits <= 128
#if mk_has_128bit_int
#include "../base/mk_uint_macro_base_128.h"
#define mk_uint_small_bits 128
#elif ULONG_MAX >= 0xfffffffffffffffful
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 64
#elif mk_has_long_long
#include "../base/mk_uint_macro_base_llong.h"
#define mk_uint_small_bits 64
#elif UINT_MAX >= 0xffffffffu
#include "../base/mk_uint_macro_base_int.h"
#define mk_uint_small_bits 32
#else
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#endif
#else
#if mk_has_128bit_int
#include "../base/mk_uint_macro_base_128.h"
#define mk_uint_small_bits 128
#elif ULONG_MAX >= 0xfffffffffffffffful
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 64
#elif mk_has_long_long
#include "../base/mk_uint_macro_base_llong.h"
#define mk_uint_small_bits 64
#elif UINT_MAX >= 0xffffffffu
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
