#ifndef mk_include_guard_uint_base_short
#define mk_include_guard_uint_base_short


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#define mk_uint_tn short
#define mk_uint_t unsigned short

#include "../inl/mk_uint_base.inl.h"

#undef mk_uint_tn
#undef mk_uint_t


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif
