#include <limits.h> /* CHAR_BIT UINT_MAX ULONG_MAX */


#if CHAR_BIT == 8
#if UINT_MAX == 0xffffffff
#include "../base/mk_uint_macro_base_int.h"
#define mk_uint_small_bits 32
#define mk_uint32_c(a) {a}
#elif ULONG_MAX == 0xffffffff
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#define mk_uint32_c(a) {a}
#endif
#endif


#define mk_uint_bits 32
#define mk_uint_t struct mk_uint32_s


#include "mk_uint_macro_exact.h"
