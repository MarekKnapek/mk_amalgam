#include "mk_uint_base_int.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#define mk_uint_tn int
#define mk_uint_t unsigned int

#include "../inl/mk_uint_base.c.inl"

#undef mk_uint_tn
#undef mk_uint_t


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
