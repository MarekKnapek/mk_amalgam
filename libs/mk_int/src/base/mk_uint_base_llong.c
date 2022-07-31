#include "mk_uint_base_llong.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../../../mk_utils/src/mk_setup.h"


#if mk_uint_has_long_long

#define mk_uint_tn llong
#define mk_uint_t unsigned long long

#include "../inl/mk_uint_base.c"

#undef mk_uint_tn
#undef mk_uint_t

#endif


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
