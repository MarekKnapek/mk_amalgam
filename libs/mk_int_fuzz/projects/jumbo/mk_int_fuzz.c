#ifndef mk_include_guard_int_fuzz_c
#define mk_include_guard_int_fuzz_c


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../../src/mk_uint_fuzz.c"
#include "../../src/mk_uint_fuzz_8.c"
#include "../../src/mk_uint_fuzz_16.c"
#include "../../src/mk_uint_fuzz_32.c"
#include "../../src/mk_uint_fuzz_64.c"
#include "../../src/mk_uint_fuzz_128.c"

#include "../../../mk_int/projects/jumbo/mk_int.c"


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif
