#ifndef mk_include_guard_int_c
#define mk_include_guard_int_c


#include "mk_int.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../../src/base/mk_uint_base_char.c"
#include "../../src/base/mk_uint_base_short.c"
#include "../../src/base/mk_uint_base_int.c"
#include "../../src/base/mk_uint_base_long.c"
#include "../../src/base/mk_uint_base_llong.c"
#include "../../src/base/mk_uint_base_128.c"
#include "../../src/exact/mk_uint_8.c"
#include "../../src/exact/mk_uint_16.c"
#include "../../src/exact/mk_uint_32.c"
#include "../../src/exact/mk_uint_64.c"
#include "../../src/exact/mk_uint_128.c"


#include "../../../mk_utils/projects/jumbo/mk_utils.c"


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif
