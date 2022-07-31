#include <limits.h> /* CHAR_BIT USHRT_MAX */


#if CHAR_BIT == 8
#if USHRT_MAX == 0xffff
#include "../base/mk_uint_macro_base_short.h"
#define mk_uint_small_bits 16
#define mk_uint16_c(a) {a}
#endif
#endif


#define mk_uint_bits 16
#define mk_uint_t struct mk_uint16_s


#include "mk_uint_macro_exact.h"
