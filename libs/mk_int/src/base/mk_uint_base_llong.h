#ifndef mk_include_guard_uint_base_llong
#define mk_include_guard_uint_base_llong


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../../../mk_utils/src/mk_setup.h"


#if mk_has_long_long

#define mk_uint_base_tn llong
#define mk_uint_base_t unsigned long long int

#include "../inl/mk_uint_base.inl.h"

#undef mk_uint_base_tn
#undef mk_uint_base_t

#endif


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif
