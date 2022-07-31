#include "mk_uint_fuzz_16.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#define mk_uint_n 16
#include "mk_uint_fuzz.c.inl"
#undef mk_uint_n


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
