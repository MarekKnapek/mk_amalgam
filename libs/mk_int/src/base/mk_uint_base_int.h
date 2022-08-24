#ifndef mk_include_guard_uint_base_int
#define mk_include_guard_uint_base_int


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#define mk_uint_base_tn int
#define mk_uint_base_t unsigned int

#include "../inl/mk_uint_base.inl.h"

#undef mk_uint_base_tn
#undef mk_uint_base_t


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif
