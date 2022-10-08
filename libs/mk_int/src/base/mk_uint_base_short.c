#include "mk_uint_base_short.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#define mk_uint_tn short
#define mk_uint_t unsigned short int

#include "../inl/mk_uint_base.inl.c"

#undef mk_uint_tn
#undef mk_uint_t


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
