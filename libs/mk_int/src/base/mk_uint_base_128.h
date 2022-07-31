#ifndef mk_include_guard_uint_base_128
#define mk_include_guard_uint_base_128


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif


#include "../../../mk_utils/src/mk_setup.h"


#if mk_uint_has_128bit_int

#define mk_uint_tn 128
#define mk_uint_t unsigned __int128

#include "../inl/mk_uint_base.h.inl"

#undef mk_uint_tn
#undef mk_uint_t

#endif


#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif


#endif
