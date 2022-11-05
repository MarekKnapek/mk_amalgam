#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif
#include "../../../libs/mk_num/src/mk_lang_bool.h"
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
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#pragma warning(disable:5045) /* warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified */
#endif


mk_lang_bool_t test_basic_types_max(void)
{
	mk_lang_bool_t ret;
	unsigned char uchar;
	unsigned short int ushort;
	unsigned int uint;
	unsigned long int ulong;
	mk_lang_ullong_t ullong;
	mk_lang_size_t usize;
	mk_lang_uintmax_t umax;

	ret = mk_lang_true;
	uchar = ((unsigned char)(((unsigned char)(((unsigned char)(((unsigned char)(((unsigned char)(1)) << (sizeof(unsigned char) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	ushort = ((unsigned short int)(((unsigned short int)(((unsigned short int)(((unsigned short int)(((unsigned short int)(1)) << (sizeof(unsigned short int) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	uint = ((unsigned int)(((unsigned int)(((unsigned int)(((unsigned int)(((unsigned int)(1)) << (sizeof(unsigned int) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	ulong = ((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(1)) << (sizeof(unsigned long int) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	ullong = ((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(1)) << (sizeof(mk_lang_ullong_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	usize = ((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(1)) << (sizeof(mk_lang_size_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	umax = ((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(1)) << (sizeof(mk_lang_uintmax_t) * CHAR_BIT - 1))) - 1)) << 1)) + 1));
	ret = ret && (uchar == UCHAR_MAX);
	ret = ret && (ushort == USHRT_MAX);
	ret = ret && (uint == UINT_MAX);
	ret = ret && (ulong == ULONG_MAX);
	ret = ret && (ullong == mk_lang_limits_ullongmax);
	ret = ret && (usize == mk_lang_limits_sizemax);
	ret = ret && (umax == mk_lang_limits_uintmaxmax);
	return ret;
}

mk_lang_bool_t test_basic_types_mul(unsigned char const* data, size_t size)
{
	unsigned short int u16x;
	unsigned short int u16y;
	unsigned short int u16z;
	unsigned short int u16c;
	unsigned long int u32x;
	unsigned long int u32y;
	unsigned long int u32z;
	unsigned long int u16z32;
	unsigned long int u16c32;
	unsigned long int u16r32;
	mk_lang_bool_t ret;

	if(!data) return mk_lang_true;
	if(!(size >= 2 * 2)) return mk_lang_true;

	u16x = 0;
	u16y = 0;
	memcpy(&u16x, data + 0 * 2, 2);
	memcpy(&u16y, data + 1 * 2, 2);
	mk_num_basic_ushort_mul3_wrap_cid_coe(&u16x, &u16y, &u16z, &u16c);
	u32x = u16x;
	u32y = u16y;
	u32z = u32x * u32y;
	u16z32 = u16z;
	u16c32 = u16c;
	u16r32 = (u16c32 << 16) + u16z32;
	ret = u32z == u16r32;
	return ret;
}

mk_lang_bool_t test_basic_types_mul_2(unsigned char const* data, size_t size)
{
	#if mk_lang_llong_has != 0

	unsigned int uintx;
	unsigned int uinty;
	unsigned int uintz;
	unsigned int uintc;
	unsigned long long int uintz64;
	unsigned long long int u64;
	mk_lang_bool_t ret;

	if(!data) return mk_lang_true;
	if(!(size >= 2 * 4)) return mk_lang_true;

	uintx = 0;
	uinty = 0;
	memcpy(&uintx, data + 0 * sizeof(unsigned int), sizeof(unsigned int));
	memcpy(&uinty, data + 1 * sizeof(unsigned int), sizeof(unsigned int));
	mk_num_basic_uint_mul3_wrap_cid_coe(&uintx, &uinty, &uintz, &uintc);
	uintz64 = ((unsigned long long int)(((unsigned long long int)(((unsigned long long int)(uintc)) << 32)) + ((unsigned long long int)(uintz))));
	u64 = ((unsigned long long int)(((unsigned long long int)(uintx)) * ((unsigned long long int)(uinty))));
	ret = uintz64 == u64;
	return ret;

	#else
	((void)(data));
	((void)(size));
	return mk_lang_true;
	#endif
}

mk_lang_bool_t test_basic_types(unsigned char const* data, size_t size)
{
	mk_lang_bool_t ret;

	ret = mk_lang_true;
	ret = ret && test_basic_types_max();
	ret = ret && test_basic_types_mul(data, size);
	ret = ret && test_basic_types_mul_2(data, size);
	return ret;
}


mk_lang_extern_c int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size)
{
	#define test(x) do{ if(!(x)){ mk_lang_crash(); } }while(0)

	unsigned bits;
	unsigned long int ba;
	unsigned long int bb;
	unsigned long int bc;
	unsigned long int bm;
	mk_num_composite_u25_t ma;
	mk_num_composite_u25_t mb;
	mk_num_composite_u25_t mc;
	unsigned short int shift_;
	int shift;

	mk_lang_assert(CHAR_BIT == 8);

	test(test_basic_types(data, size));

	bits = 25;
	if(!(size >= 2 * bits / CHAR_BIT + 2)) return 0;
	ba = 0;
	bb = 0;
	bm = (((((unsigned long int)(1)) << (bits - 1)) - 1) << 1) + 1;
	shift_ = 0;
	memcpy(&ba, data + 0, bits / CHAR_BIT); ba = ba & bm;
	memcpy(&bb, data + bits / CHAR_BIT, bits / CHAR_BIT); bb = bb & bm;
	memcpy(&shift_, data + 2 * bits / CHAR_BIT, 2); shift = ((int)(shift_));
	if(!(shift >= 0 && shift < ((int)(bits)))) return 0;

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
	bc = ba * bb; bc = bc & bm; mk_num_composite_u25_mul3_wrap_cid_cod(&ma, &mb, &mc); test(mk_num_composite_u25_to_ulong(&mc) == bc);

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
	unsigned char buff[32];
	long int i;
	int j;
	int tested;
	srand(((unsigned int)(time(NULL))));
	for(i = 0; i != rep; ++i)
	{
		for(j = 0; j != ((int)(sizeof(buff))); ++j)
		{
			buff[j] = ((unsigned char)(rand()));
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
