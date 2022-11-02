#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif
#include "../../../libs/mk_num/src/mk_lang_cpp.h"
#include "../../../libs/mk_num/src/mk_lang_crash.h"
#include "../../../libs/mk_num/src/mk_lang_limits.h"
#include "../../../libs/mk_num/src/mk_lang_llong.h"
#include "../../../libs/mk_num/src/mk_lang_uintmaxt.h"
#include "../../../libs/mk_num/src/mk_lang_sizet.h"
#include "../../../libs/mk_num/src/mk_num_basic_uints.h"
#include "../../../libs/mk_num/src/mk_num_composite_uints.h"
#define mk_num_composite_bits 25
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.h"
#if defined(_MSC_VER)
#pragma warning(pop)
#endif

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:5045) /* warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified */
#endif


int test_basic_types(void)
{
	int ret;
	unsigned char uchar;
	unsigned short int ushort;
	unsigned int uint;
	unsigned long int ulong;
	mk_lang_ullong_t ullong;
	mk_lang_size_t usize;
	mk_lang_uintmax_t umax;

	ret = 1;
	uchar = ((unsigned char)(((unsigned char)(((unsigned char)(((unsigned char)(((unsigned char)(1)) << (sizeof(unsigned char) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	ushort = ((unsigned short int)(((unsigned short int)(((unsigned short int)(((unsigned short int)(((unsigned short int)(1)) << (sizeof(unsigned short int) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	uint = ((unsigned int)(((unsigned int)(((unsigned int)(((unsigned int)(((unsigned int)(1)) << (sizeof(unsigned int) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	ulong = ((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(1)) << (sizeof(unsigned long int) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	ullong = ((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(1)) << (sizeof(mk_lang_ullong_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	usize = ((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(1)) << (sizeof(mk_lang_size_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	umax = ((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(1)) << (sizeof(mk_lang_uintmax_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	ret = ret & (uchar == UCHAR_MAX);
	ret = ret & (ushort == USHRT_MAX);
	ret = ret & (uint == UINT_MAX);
	ret = ret & (ulong == ULONG_MAX);
	ret = ret & (ullong == mk_lang_limits_ullongmax);
	ret = ret & (usize == mk_lang_limits_sizemax);
	ret = ret & (umax == mk_lang_limits_uintmaxmax);
	return ret;
}


mk_lang_extern_c int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size)
{
	#define test(x) do{ if(!(x)){ mk_lang_crash(); } }while(0)

	unsigned long ba;
	unsigned long bb;
	unsigned long bc;
	unsigned long bm;
	mk_num_composite_u25_t ma;
	mk_num_composite_u25_t mb;
	mk_num_composite_u25_t mc;
	unsigned short int shift_;
	int shift;

	test(test_basic_types());

	if(!(size == 10)) return 0;
	ba = 0;
	bb = 0;
	bm = (((1ul << (25 - 1)) - 1) << 1) + 1;
	shift_ = 0;
	memcpy(&ba, data + 0, 4); ba = ba & bm;
	memcpy(&bb, data + 4, 4); bb = bb & bm;
	memcpy(&shift_, data + 8, 2); shift = ((int)(shift_));
	if(!(shift >= 0 && shift < 25)) return 0;
	mk_num_composite_u25_from_ulong(&ma, ba);
	mk_num_composite_u25_from_ulong(&mb, bb);
	test(mk_num_composite_u25_to_ulong(&ma) == ba);
	test(mk_num_composite_u25_to_ulong(&mb) == bb);

	test(mk_num_composite_u25_is_zero(&ma) == !ba);
	test(mk_num_composite_u25_eq(&ma, &mb) == (ba == bb));
	test(mk_num_composite_u25_ne(&ma, &mb) == (ba != bb));
	test(mk_num_composite_u25_lt(&ma, &mb) == (ba < bb));
	test(mk_num_composite_u25_le(&ma, &mb) == (ba <= bb));
	test(mk_num_composite_u25_gt(&ma, &mb) == (ba > bb));
	test(mk_num_composite_u25_ge(&ma, &mb) == (ba >= bb));
	(void)bc;(void)mc;
	++ba; ba = ba & bm; mk_num_composite_u25_inc(&ma); test(mk_num_composite_u25_to_ulong(&ma) == ba);
	--ba; ba = ba & bm; mk_num_composite_u25_dec(&ma); test(mk_num_composite_u25_to_ulong(&ma) == ba);

	bc = ~ba; bc = bc & bm; mk_num_composite_u25_not2(&ma, &mc); test(mk_num_composite_u25_to_ulong(&mc) == bc);
	bc = ba | bb; bc = bc & bm; mk_num_composite_u25_or3(&ma, &mb, &mc); test(mk_num_composite_u25_to_ulong(&mc) == bc);
	bc = ba & bb; bc = bc & bm; mk_num_composite_u25_and3(&ma, &mb, &mc); test(mk_num_composite_u25_to_ulong(&mc) == bc);
	bc = ba ^ bb; bc = bc & bm; mk_num_composite_u25_xor3(&ma, &mb, &mc); test(mk_num_composite_u25_to_ulong(&mc) == bc);

	bc = ba << shift; bc = bc & bm; mk_num_composite_u25_shl3(&ma, shift, &mc); test(mk_num_composite_u25_to_ulong(&mc) == bc);
	bc = ba >> shift; bc = bc & bm; mk_num_composite_u25_shr3(&ma, shift, &mc); test(mk_num_composite_u25_to_ulong(&mc) == bc);

	bc = ba + bb; bc = bc & bm; mk_num_composite_u25_add3_wrap_cid_cod(&ma, &mb, &mc); test(mk_num_composite_u25_to_ulong(&mc) == bc);
	bc = ba - bb; bc = bc & bm; mk_num_composite_u25_sub3_wrap_cid_cod(&ma, &mb, &mc); test(mk_num_composite_u25_to_ulong(&mc) == bc);

	return 0;

	#undef test
}

#if defined(mk_lang_generate_main)
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	static long int const rep = 1000000;
	unsigned char buff[10];
	long int i;
	int j;
	int tested;
	srand((unsigned int)time(NULL));
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


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif
#include "../../../libs/mk_num/src/mk_num_basic_uints.c"
#include "../../../libs/mk_num/src/mk_num_composite_uints.c"
#include "../../../libs/mk_num/src/mk_lang_crash.c"
#define mk_num_composite_bits 25
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.c"
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
