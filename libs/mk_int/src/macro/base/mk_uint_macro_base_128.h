#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif


#define mk_uint_small_t unsigned __int128
#define mk_uint_small_tn 128


#include "mk_uint_macro_base.h"


#undef mk_uint_tn


#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
