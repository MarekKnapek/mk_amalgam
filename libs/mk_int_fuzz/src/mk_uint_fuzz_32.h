#ifndef mk_include_guard_uint_fuzz_32
#define mk_include_guard_uint_fuzz_32


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#define mk_uint_n 32
#include "mk_uint_fuzz.inl.h"
#undef mk_uint_n


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif
