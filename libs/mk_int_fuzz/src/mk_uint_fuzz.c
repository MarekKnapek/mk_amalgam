#include "mk_uint_fuzz_8.h"
#include "mk_uint_fuzz_16.h"
#include "mk_uint_fuzz_32.h"
#include "mk_uint_fuzz_64.h"
#include "mk_uint_fuzz_128.h"
#define mk_uint_bits 8192
#include "../../mk_int/src/exact/mk_uint_n.inl.h"

#include <stddef.h> /* size_t */
#include <stdio.h>


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


#if defined(__cplusplus)
#define mk_extern_c extern "C"
#else
#define mk_extern_c
#endif


static int factorial;


void factorial_compute(void)
{
	static int const n = 800;

	struct mk_uint8192_s a;
	struct mk_uint8192_s b;
	int i;
	int len;
	char buff[2467+1];

	mk_uint8192_zero(&a);
	mk_uint8192_inc(&a);
	mk_uint8192_inc(&a);
	b = a;
	for(i = 0; i != n - 2; ++i)
	{
		mk_uint8192_inc(&b);
		mk_uint8192_mul(&a, &a, &b);
	}
	len = mk_uint8192_to_string_dec_n(&a, buff, (int)sizeof(buff));
	buff[len] = '\0';
	printf("%d! = %s\n", n, buff);
}


mk_extern_c int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size)
{
	if(size != 2 * 16)
	{
		return 0;
	}

	if(!factorial)
	{
		++factorial;
		factorial_compute();
	}

	return 0;
}

int main()
{
	static unsigned char const buff[2 * 16] = {0};

	LLVMFuzzerTestOneInput(buff, sizeof(buff));
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


#define mk_uint_bits 8192
#include "../../mk_int/src/exact/mk_uint_n.inl.c"
