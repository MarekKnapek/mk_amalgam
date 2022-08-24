#ifndef mk_include_guard_uint_base_char
#define mk_include_guard_uint_base_char


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#define mk_uint_base_tn char
#define mk_uint_base_t unsigned char

#include "../inl/mk_uint_base.inl.h"

#undef mk_uint_base_tn
#undef mk_uint_base_t


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif
