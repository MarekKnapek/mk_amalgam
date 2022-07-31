#include "mk_uint_fuzz_128.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../../mk_utils/src/mk_setup.h"


#if mk_uint_has_128bit_int

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic" /* warning: ISO C does not support '__int128' types [-Wpedantic] */
#endif

#define mk_uint_n 128
#define uint128_t unsigned __int128
#include "mk_uint_fuzz.c.inl"
#undef mk_uint_n
#undef uint128_t

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#else


void mk_uint_fuzz_128(unsigned char const* data)
{
	(void)data;
}


#endif


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
