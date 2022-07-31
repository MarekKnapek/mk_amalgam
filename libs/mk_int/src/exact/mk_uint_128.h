#ifndef mk_include_guard_uint_128
#define mk_include_guard_uint_128


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif


#include "../macro/exact/mk_uint_macro_exact_128.h"


#include "../inl/mk_uint.h.inl"


#include "../macro/exact/mk_uint_macro_exact_undef.h"


#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif


#endif
