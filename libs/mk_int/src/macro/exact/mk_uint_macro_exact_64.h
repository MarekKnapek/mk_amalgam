#include "../../../../mk_utils/src/mk_setup.h"

#include <limits.h> /* CHAR_BIT ULLONG_MAX */


#if CHAR_BIT == 8
#if mk_has_long_long
#if ULLONG_MAX == 0xffffffffffffffff
#include "../base/mk_uint_macro_base_llong.h"
#define mk_uint_small_bits 64
#define mk_uint64_c(a, b) {(((unsigned long long)a) << 32) | (((unsigned long long)b) << 0)}
#endif
#else
#if ULONG_MAX == 0xffffffff
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#define mk_uint64_c(a, b) {{b, a}}
#endif
#endif
#endif


#define mk_uint_bits 64
#define mk_uint_t struct mk_uint64_s


#include "mk_uint_macro_exact.h"
