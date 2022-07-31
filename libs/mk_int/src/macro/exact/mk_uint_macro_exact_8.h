#include <limits.h> /* CHAR_BIT UCHAR_MAX */


#if CHAR_BIT == 8
#if UCHAR_MAX == 0xff
#include "../base/mk_uint_macro_base_char.h"
#define mk_uint_small_bits 8
#define mk_uint8_c(a) {a}
#endif
#endif


#define mk_uint_bits 8
#define mk_uint_t struct mk_uint8_s


#include "mk_uint_macro_exact.h"
