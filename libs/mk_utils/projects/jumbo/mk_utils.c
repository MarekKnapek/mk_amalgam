#ifndef mk_include_guard_utils_c
#define mk_include_guard_utils_c


#include "mk_utils.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../../src/mk_break_point.c"
#include "../../src/mk_clobber.c"


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif
