#include "mk_uint_128.h"


#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic" /* warning: ISO C does not support '__int128' types [-Wpedantic] */
#endif


#define mk_uint_bits 128
#include "mk_uint_n.inl.c"


#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
