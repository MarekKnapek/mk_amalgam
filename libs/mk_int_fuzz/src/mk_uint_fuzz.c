#include "mk_uint_fuzz_8.h"
#include "mk_uint_fuzz_16.h"
#include "mk_uint_fuzz_32.h"
#include "mk_uint_fuzz_64.h"
#include "mk_uint_fuzz_128.h"

#include <stddef.h> /* size_t */


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size)
{
	if(size != 2 * 16)
	{
		return 0;
	}

	mk_uint_fuzz_8(data);
	mk_uint_fuzz_16(data);
	mk_uint_fuzz_32(data);
	mk_uint_fuzz_64(data);
	mk_uint_fuzz_128(data);

	return 0;
}


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
