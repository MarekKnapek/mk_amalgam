#include "mk_uint_base_128.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic" /* warning: ISO C does not support '__int128' types [-Wpedantic] */
#endif


#include "../../../mk_utils/src/mk_setup.h"


#if mk_has_128bit_int

#define mk_uint_tn 128
#define mk_uint_t unsigned __int128

#include "../inl/mk_uint_base.inl.c"

#undef mk_uint_tn
#undef mk_uint_t

#endif


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
