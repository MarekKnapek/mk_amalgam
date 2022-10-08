#ifndef mk_include_guard_uint_128
#define mk_include_guard_uint_128


#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic" /* warning: ISO C does not support '__int128' types [-Wpedantic] */
#endif


#define mk_uint_bits 128
#include "mk_uint_n.inl.h"


#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif


#endif
