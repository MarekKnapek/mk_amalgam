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


#if defined(__cplusplus)
#define mk_extern_c extern "C"
#else
#define mk_extern_c
#endif


mk_extern_c int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size)
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


#ifdef mk_generate_main
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	static long const rep = 1000000;
	unsigned char buff[32];
	long i;
	int j;
	int tested;
	srand((unsigned)time(NULL));
	for(i = 0; i != rep; ++i)
	{
		for(j = 0; j != (int)sizeof(buff); ++j)
		{
			buff[j] = (unsigned char)rand();
		}
		tested = LLVMFuzzerTestOneInput(buff, sizeof(buff));
		(void)tested;
	}
	printf("%s\n", "Not crashed.");
	return 0;
}
#endif


#undef mk_extern_c


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
