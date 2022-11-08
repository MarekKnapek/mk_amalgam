#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif
#include "../../../libs/mk_num/src/mk_lang_bool.h"
#include "../../../libs/mk_num/src/mk_lang_cpp.h"
#include "../../../libs/mk_num/src/mk_lang_crash.h"
#include "../../../libs/mk_num/src/mk_lang_limits.h"
#include "../../../libs/mk_num/src/mk_lang_llong.h"
#include "../../../libs/mk_num/src/mk_lang_i128.h"
#include "../../../libs/mk_num/src/mk_lang_uintmaxt.h"
#include "../../../libs/mk_num/src/mk_lang_sizet.h"
#include "../../../libs/mk_num/src/mk_num_div_mod.h"
#include "../../../libs/mk_num/src/mk_num_basic_uints.h"
#include "../../../libs/mk_num/src/mk_num_composite_uints.h"
#define mk_num_composite_bits 25
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.h"
#define mk_num_composite_bits 6656
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.h"
#if defined(_MSC_VER)
#pragma warning(pop)
#endif

#include <limits.h>
#include <stddef.h>
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

mk_lang_bool_t test_basic_types_mul_3(void)
{
	static unsigned char const s_factorial_800_be[] = {0x86, 0xfe, 0x52, 0x70, 0x5c, 0xaf, 0x49, 0xd4, 0x58, 0x35, 0x48, 0x24, 0x18, 0x95, 0xe9, 0x86, 0xd0, 0x6e, 0x8f, 0x92, 0x7c, 0x96, 0xba, 0x41, 0x40, 0x47, 0x2e, 0xe8, 0xf9, 0x22, 0xf2, 0x80, 0xe1, 0x06, 0x34, 0xf6, 0x69, 0x9b, 0x3c, 0x49, 0x22, 0x3b, 0x2b, 0x3b, 0x32, 0xcc, 0x1f, 0x24, 0xb7, 0x49, 0x94, 0xc2, 0x4d, 0x05, 0xae, 0xff, 0x5f, 0x8b, 0x83, 0xed, 0xed, 0x2a, 0xb3, 0xf9, 0x2a, 0x56, 0x3d, 0xd7, 0x16, 0x47, 0x7c, 0xc1, 0x26, 0xea, 0x0c, 0x0a, 0x5e, 0x99, 0x6d, 0x6c, 0x1b, 0x91, 0x7b, 0x69, 0xf6, 0x34, 0xa3, 0x22, 0x77, 0xe0, 0x24, 0x36, 0x7d, 0x98, 0x1c, 0xb2, 0xa7, 0xa1, 0x24, 0xa8, 0xc0, 0x5a, 0x95, 0x71, 0x7e, 0xfb, 0x84, 0x47, 0x46, 0x94, 0xa3, 0xb9, 0xe2, 0x66, 0x8c, 0x03, 0xb2, 0x7c, 0x95, 0x42, 0xe7, 0xef, 0x60, 0x27, 0xfa, 0x46, 0xc0, 0x45, 0x58, 0xa8, 0xd7, 0x9d, 0x9b, 0x0f, 0xf2, 0x07, 0x15, 0x58, 0xec, 0x92, 0x3a, 0x41, 0x15, 0x3c, 0xec, 0x6e, 0x7c, 0x70, 0xcc, 0xc9, 0xd5, 0x87, 0xde, 0x17, 0xa9, 0x88, 0x67, 0x26, 0x19, 0x69, 0x31, 0xda, 0x40, 0xd7, 0xab, 0xdf, 0x1b, 0x3f, 0x44, 0x37, 0xfb, 0x5f, 0x03, 0x49, 0x0a, 0x1e, 0x0b, 0x4d, 0x08, 0x59, 0xe1, 0x5b, 0x01, 0x17, 0x6a, 0x0e, 0x96, 0xd2, 0x4e, 0x30, 0x0d, 0x31, 0x29, 0x49, 0x96, 0xbb, 0x3d, 0xab, 0x60, 0x39, 0x0e, 0x60, 0xb4, 0xbb, 0xc3, 0x14, 0x8e, 0x1d, 0xa0, 0x34, 0x1f, 0xca, 0x48, 0x39, 0x60, 0xdf, 0xb1, 0xd1, 0xde, 0x8d, 0x84, 0x6d, 0x75, 0xa7, 0x7b, 0xb7, 0x54, 0xce, 0x7b, 0xbd, 0xdf, 0x18, 0xad, 0xa1, 0x61, 0xc8, 0xa8, 0x1d, 0x7d, 0xd8, 0x75, 0x7c, 0x9e, 0xd8, 0xeb, 0xb5, 0x5e, 0x81, 0x5c, 0x78, 0x5e, 0x4e, 0x68, 0x50, 0x74, 0xf4, 0xd7, 0x4a, 0x14, 0x45, 0xcf, 0x94, 0x19, 0xb8, 0x77, 0x6f, 0xa2, 0xc8, 0xbf, 0xca, 0x06, 0xd8, 0x76, 0x11, 0xb8, 0x95, 0xff, 0x60, 0x4c, 0xd9, 0x6b, 0x90, 0x5f, 0xa6, 0x08, 0xb8, 0xab, 0x0c, 0x1a, 0x16, 0xad, 0x22, 0xd1, 0xa6, 0x7a, 0x44, 0x76, 0x63, 0xfe, 0xfa, 0x22, 0x1c, 0xbb, 0xb8, 0x3b, 0x82, 0xcf, 0xf3, 0x22, 0xb9, 0xd5, 0xd1, 0x09, 0x12, 0x26, 0xd3, 0x44, 0x1c, 0x72, 0xd7, 0x1c, 0x24, 0xaa, 0x7a, 0x37, 0x4c, 0xf4, 0x17, 0x97, 0x7c, 0xa3, 0xc6, 0xd4, 0x12, 0x46, 0xb4, 0x4c, 0xcd, 0x7e, 0x83, 0x8b, 0xeb, 0x27, 0xc4, 0x03, 0x3c, 0xcc, 0xc7, 0x13, 0x88, 0x80, 0x9a, 0x72, 0x8c, 0x95, 0x3d, 0x70, 0xa9, 0x05, 0xbc, 0x70, 0xc0, 0x94, 0xe2, 0x66, 0x11, 0xf4, 0xcb, 0xfd, 0x8a, 0x96, 0xe5, 0x52, 0xf9, 0x2a, 0x30, 0x34, 0x86, 0x29, 0x7c, 0xac, 0x6b, 0x06, 0x9c, 0x8b, 0xd7, 0xb2, 0x83, 0x04, 0xdd, 0x26, 0x40, 0x44, 0x51, 0x4a, 0x5a, 0x68, 0xca, 0xd6, 0x10, 0x7e, 0xb9, 0x2a, 0xdd, 0xe3, 0x18, 0x27, 0x53, 0xd2, 0xbe, 0xd6, 0x7b, 0x39, 0x9d, 0x75, 0x3e, 0x66, 0x23, 0xda, 0xfa, 0x83, 0x79, 0x87, 0xf1, 0x71, 0x8b, 0x21, 0x90, 0x0f, 0xe3, 0x35, 0x23, 0xab, 0xfb, 0x61, 0x7b, 0xb4, 0xf4, 0xa2, 0x7c, 0x57, 0xeb, 0xf7, 0x41, 0x1f, 0xcd, 0xfb, 0x58, 0x30, 0x13, 0x21, 0x89, 0x54, 0x3d, 0x6c, 0x99, 0x6e, 0x60, 0x89, 0x60, 0x2a, 0x91, 0x6a, 0x59, 0x97, 0xe4, 0x3a, 0xd9, 0x37, 0xdf, 0x64, 0x92, 0x80, 0x30, 0x60, 0xef, 0x47, 0xfe, 0xd0, 0xe8, 0x45, 0x18, 0x90, 0x23, 0x44, 0x5b, 0x31, 0x3a, 0xe3, 0xe1, 0x22, 0xd0, 0xb1, 0x11, 0xcc, 0xd3, 0x2e, 0xb7, 0x5c, 0x29, 0xd9, 0x0c, 0xc9, 0x87, 0x33, 0x97, 0xa4, 0xce, 0x8c, 0xb0, 0x85, 0x9c, 0xae, 0xae, 0xca, 0xc6, 0xbf, 0x46, 0x9b, 0x3c, 0xc6, 0x1c, 0xcf, 0xe0, 0xd9, 0x43, 0x9b, 0xc5, 0xca, 0xde, 0x80, 0x7e, 0x38, 0xad, 0x0b, 0xbc, 0xfe, 0xa0, 0x91, 0xd1, 0x86, 0x91, 0xfd, 0x5c, 0x61, 0x5a, 0x6c, 0xb1, 0xe6, 0x6a, 0x8e, 0xf3, 0x07, 0x51, 0x8c, 0x43, 0x82, 0xaf, 0xa8, 0xda, 0x60, 0x0d, 0x0f, 0x17, 0x78, 0x08, 0x13, 0x19, 0xa7, 0xa8, 0x19, 0xf0, 0x8a, 0xfa, 0x91, 0xdd, 0xca, 0x26, 0x29, 0x7c, 0x18, 0xee, 0x05, 0x2d, 0xff, 0xf7, 0xa1, 0x20, 0x0c, 0xfa, 0xfc, 0x99, 0xb7, 0x35, 0xd9, 0xd9, 0x64, 0xc9, 0x55, 0x95, 0x96, 0x0c, 0x0b, 0x58, 0xfc, 0xd8, 0x43, 0x1b, 0x29, 0xa6, 0x2f, 0x09, 0xc7, 0x5d, 0xad, 0x0f, 0xe2, 0x9e, 0x1d, 0x26, 0x88, 0xc7, 0xff, 0x60, 0xcc, 0x81, 0x87, 0x22, 0x2c, 0x33, 0x66, 0x8b, 0x9c, 0x46, 0xaf, 0xca, 0xbc, 0xdb, 0x1d, 0x70, 0x9b, 0x00, 0x53, 0x8e, 0xee, 0xda, 0x13, 0x48, 0x83, 0xf6, 0xaa, 0x1c, 0x2e, 0xce, 0xc7, 0xc5, 0x62, 0xd8, 0xb9, 0x0e, 0x9b, 0xf6, 0xf5, 0xbc, 0x41, 0xe4, 0xfd, 0x9c, 0xdb, 0x9a, 0x0d, 0xc2, 0xee, 0xae, 0x59, 0x06, 0x25, 0xad, 0x46, 0xa6, 0xe3, 0x2a, 0xea, 0xf5, 0xa2, 0x01, 0xad, 0x6c, 0x43, 0x5f, 0xd8, 0x8c, 0xfa, 0x55, 0xd1, 0x41, 0x6f, 0xbd, 0xfb, 0x46, 0x57, 0x4b, 0x71, 0x39, 0x6d, 0xbd, 0x17, 0xf2, 0xca, 0x1d, 0x16, 0x34, 0x10, 0xdc, 0xdf, 0x19, 0x8e, 0xf8, 0x76, 0x94, 0xb0, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	static int g_once = 0;

	int n;
	mk_num_composite_u6656_t a;
	mk_num_composite_u6656_t b;
	int i;
	unsigned char buff[6656 / CHAR_BIT];
	mk_lang_bool_t ret;

	if(g_once != 0) return mk_lang_true;
	if(g_once == 0) ++g_once;

	n = 800;
	mk_num_composite_u6656_set_one(&a);
	b = a;
	for(i = 0; i != n - 1; ++i)
	{
		mk_num_composite_u6656_inc(&b);
		mk_num_composite_u6656_mul3_wrap_cid_cod(&a, &b, &a);
	}
	mk_num_composite_u6656_to_buff_be(&a, buff);
	ret = memcmp(buff + (sizeof(buff) - sizeof(s_factorial_800_be)), s_factorial_800_be, sizeof(s_factorial_800_be)) == 0;
	return ret;
}

mk_lang_bool_t test_basic_types_div_l4(unsigned char const* data, size_t size)
{
	unsigned long int x;
	unsigned long int y;
	unsigned long int z;
	unsigned long int r;
	unsigned long int mz;
	unsigned long int mr;
	mk_lang_bool_t ret;

	if(!data) return mk_lang_true;
	if(!(size >= 8)) return mk_lang_true;
	x = 0;
	y = 0;
	memcpy(&x, data + 0, 4);
	memcpy(&y, data + 4, 4);
	if(!(y != 0)) return mk_lang_true;
	z = x / y;
	r = x % y;

	{
		unsigned char xx[4];
		unsigned char yy[4];
		unsigned char dd[4];
		unsigned char mm[4];

		xx[0] = (x >> (0 * 8)) & 0xff;
		xx[1] = (x >> (1 * 8)) & 0xff;
		xx[2] = (x >> (2 * 8)) & 0xff;
		xx[3] = (x >> (3 * 8)) & 0xff;
		yy[0] = (y >> (0 * 8)) & 0xff;
		yy[1] = (y >> (1 * 8)) & 0xff;
		yy[2] = (y >> (2 * 8)) & 0xff;
		yy[3] = (y >> (3 * 8)) & 0xff;
		mk_num_div_mod_uchar_4_4(xx, yy, dd, mm);
		mz =
			(((unsigned long int)(dd[0])) << (0 * 8)) |
			(((unsigned long int)(dd[1])) << (1 * 8)) |
			(((unsigned long int)(dd[2])) << (2 * 8)) |
			(((unsigned long int)(dd[3])) << (3 * 8));
		mr =
			(((unsigned long int)(mm[0])) << (0 * 8)) |
			(((unsigned long int)(mm[1])) << (1 * 8)) |
			(((unsigned long int)(mm[2])) << (2 * 8)) |
			(((unsigned long int)(mm[3])) << (3 * 8));
	}

	ret = mz == z && mr == r;
	return ret;
}

mk_lang_bool_t test_basic_types_div_ll8(unsigned char const* data, size_t size)
{
	#if mk_lang_llong_has != 0

	unsigned long long int x;
	unsigned long long int y;
	unsigned long long int z;
	unsigned long long int r;
	unsigned long long int mz;
	unsigned long long int mr;
	mk_lang_bool_t ret;

	if(!data) return mk_lang_true;
	if(!(size >= 16)) return mk_lang_true;
	x = 0;
	y = 0;
	memcpy(&x, data + 0, 8);
	memcpy(&y, data + 8, 8);
	if(!(y != 0)) return mk_lang_true;
	z = x / y;
	r = x % y;

	{
		unsigned char xx[8];
		unsigned char yy[8];
		unsigned char dd[8];
		unsigned char mm[8];

		xx[0] = (x >> (0 * 8)) & 0xff;
		xx[1] = (x >> (1 * 8)) & 0xff;
		xx[2] = (x >> (2 * 8)) & 0xff;
		xx[3] = (x >> (3 * 8)) & 0xff;
		xx[4] = (x >> (4 * 8)) & 0xff;
		xx[5] = (x >> (5 * 8)) & 0xff;
		xx[6] = (x >> (6 * 8)) & 0xff;
		xx[7] = (x >> (7 * 8)) & 0xff;
		yy[0] = (y >> (0 * 8)) & 0xff;
		yy[1] = (y >> (1 * 8)) & 0xff;
		yy[2] = (y >> (2 * 8)) & 0xff;
		yy[3] = (y >> (3 * 8)) & 0xff;
		yy[4] = (y >> (4 * 8)) & 0xff;
		yy[5] = (y >> (5 * 8)) & 0xff;
		yy[6] = (y >> (6 * 8)) & 0xff;
		yy[7] = (y >> (7 * 8)) & 0xff;
		mk_num_div_mod_uchar_8_8(xx, yy, dd, mm);
		mz =
			(((unsigned long long int)(dd[0])) << (0 * 8)) |
			(((unsigned long long int)(dd[1])) << (1 * 8)) |
			(((unsigned long long int)(dd[2])) << (2 * 8)) |
			(((unsigned long long int)(dd[3])) << (3 * 8)) |
			(((unsigned long long int)(dd[4])) << (4 * 8)) |
			(((unsigned long long int)(dd[5])) << (5 * 8)) |
			(((unsigned long long int)(dd[6])) << (6 * 8)) |
			(((unsigned long long int)(dd[7])) << (7 * 8));
		mr =
			(((unsigned long long int)(mm[0])) << (0 * 8)) |
			(((unsigned long long int)(mm[1])) << (1 * 8)) |
			(((unsigned long long int)(mm[2])) << (2 * 8)) |
			(((unsigned long long int)(mm[3])) << (3 * 8)) |
			(((unsigned long long int)(mm[4])) << (4 * 8)) |
			(((unsigned long long int)(mm[5])) << (5 * 8)) |
			(((unsigned long long int)(mm[6])) << (6 * 8)) |
			(((unsigned long long int)(mm[7])) << (7 * 8));
	}

	ret = mz == z && mr == r;
	return ret;

	#else
	((void)(data));
	((void)(size));
	return mk_lang_true;
	#endif
}

mk_lang_bool_t test_basic_types_div_ll4(unsigned char const* data, size_t size)
{
	#if mk_lang_llong_has != 0

	unsigned long long int x;
	unsigned long long int y;
	unsigned long long int z;
	unsigned long long int r;
	unsigned long long int mz;
	unsigned long long int mr;
	mk_lang_bool_t ret;

	if(!data) return mk_lang_true;
	if(!(size >= 16)) return mk_lang_true;
	x = 0;
	y = 0;
	memcpy(&x, data + 0, 8);
	memcpy(&y, data + 8, 8);
	if(!(y != 0)) return mk_lang_true;
	z = x / y;
	r = x % y;

	{
		unsigned short int xx[4];
		unsigned short int yy[4];
		unsigned short int dd[4];
		unsigned short int mm[4];

		xx[0] = (x >> (0 * 16)) & 0xffff;
		xx[1] = (x >> (1 * 16)) & 0xffff;
		xx[2] = (x >> (2 * 16)) & 0xffff;
		xx[3] = (x >> (3 * 16)) & 0xffff;
		yy[0] = (y >> (0 * 16)) & 0xffff;
		yy[1] = (y >> (1 * 16)) & 0xffff;
		yy[2] = (y >> (2 * 16)) & 0xffff;
		yy[3] = (y >> (3 * 16)) & 0xffff;
		mk_num_div_mod_ushort_4_4(xx, yy, dd, mm);
		mz =
			(((unsigned long long int)(dd[0])) << (0 * 16)) |
			(((unsigned long long int)(dd[1])) << (1 * 16)) |
			(((unsigned long long int)(dd[2])) << (2 * 16)) |
			(((unsigned long long int)(dd[3])) << (3 * 16));
		mr =
			(((unsigned long long int)(mm[0])) << (0 * 16)) |
			(((unsigned long long int)(mm[1])) << (1 * 16)) |
			(((unsigned long long int)(mm[2])) << (2 * 16)) |
			(((unsigned long long int)(mm[3])) << (3 * 16));
	}

	ret = mz == z && mr == r;
	return ret;

	#else
	((void)(data));
	((void)(size));
	return mk_lang_true;
	#endif
}

mk_lang_bool_t test_basic_types_div_lll16(unsigned char const* data, size_t size)
{
	#if mk_lang_i128_has != 0

	unsigned __int128 x;
	unsigned __int128 y;
	unsigned __int128 z;
	unsigned __int128 r;
	unsigned __int128 mz;
	unsigned __int128 mr;
	mk_lang_bool_t ret;

	if(!data) return mk_lang_true;
	if(!(size >= 32)) return mk_lang_true;
	x = 0;
	y = 0;
	memcpy(&x, data +  0, 16);
	memcpy(&y, data + 16, 16);
	if(!(y != 0)) return mk_lang_true;
	z = x / y;
	r = x % y;

	{
		unsigned char xx[16];
		unsigned char yy[16];
		unsigned char dd[16];
		unsigned char mm[16];

		xx[0] = (x >> (0 * 8)) & 0xff;
		xx[1] = (x >> (1 * 8)) & 0xff;
		xx[2] = (x >> (2 * 8)) & 0xff;
		xx[3] = (x >> (3 * 8)) & 0xff;
		xx[4] = (x >> (4 * 8)) & 0xff;
		xx[5] = (x >> (5 * 8)) & 0xff;
		xx[6] = (x >> (6 * 8)) & 0xff;
		xx[7] = (x >> (7 * 8)) & 0xff;
		xx[8] = (x >> (8 * 8)) & 0xff;
		xx[9] = (x >> (9 * 8)) & 0xff;
		xx[10] = (x >> (10 * 8)) & 0xff;
		xx[11] = (x >> (11 * 8)) & 0xff;
		xx[12] = (x >> (12 * 8)) & 0xff;
		xx[13] = (x >> (13 * 8)) & 0xff;
		xx[14] = (x >> (14 * 8)) & 0xff;
		xx[15] = (x >> (15 * 8)) & 0xff;
		yy[0] = (y >> (0 * 8)) & 0xff;
		yy[1] = (y >> (1 * 8)) & 0xff;
		yy[2] = (y >> (2 * 8)) & 0xff;
		yy[3] = (y >> (3 * 8)) & 0xff;
		yy[4] = (y >> (4 * 8)) & 0xff;
		yy[5] = (y >> (5 * 8)) & 0xff;
		yy[6] = (y >> (6 * 8)) & 0xff;
		yy[7] = (y >> (7 * 8)) & 0xff;
		yy[8] = (y >> (8 * 8)) & 0xff;
		yy[9] = (y >> (9 * 8)) & 0xff;
		yy[10] = (y >> (10 * 8)) & 0xff;
		yy[11] = (y >> (11 * 8)) & 0xff;
		yy[12] = (y >> (12 * 8)) & 0xff;
		yy[13] = (y >> (13 * 8)) & 0xff;
		yy[14] = (y >> (14 * 8)) & 0xff;
		yy[15] = (y >> (15 * 8)) & 0xff;
		mk_num_div_mod_uchar_16_16(xx, yy, dd, mm);
		mz =
			(((unsigned __int128)(dd[0])) << (0 * 8)) |
			(((unsigned __int128)(dd[1])) << (1 * 8)) |
			(((unsigned __int128)(dd[2])) << (2 * 8)) |
			(((unsigned __int128)(dd[3])) << (3 * 8)) |
			(((unsigned __int128)(dd[4])) << (4 * 8)) |
			(((unsigned __int128)(dd[5])) << (5 * 8)) |
			(((unsigned __int128)(dd[6])) << (6 * 8)) |
			(((unsigned __int128)(dd[7])) << (7 * 8)) |
			(((unsigned __int128)(dd[8])) << (8 * 8)) |
			(((unsigned __int128)(dd[9])) << (9 * 8)) |
			(((unsigned __int128)(dd[10])) << (10 * 8)) |
			(((unsigned __int128)(dd[11])) << (11 * 8)) |
			(((unsigned __int128)(dd[12])) << (12 * 8)) |
			(((unsigned __int128)(dd[13])) << (13 * 8)) |
			(((unsigned __int128)(dd[14])) << (14 * 8)) |
			(((unsigned __int128)(dd[15])) << (15 * 8));
		mr =
			(((unsigned __int128)(mm[0])) << (0 * 8)) |
			(((unsigned __int128)(mm[1])) << (1 * 8)) |
			(((unsigned __int128)(mm[2])) << (2 * 8)) |
			(((unsigned __int128)(mm[3])) << (3 * 8)) |
			(((unsigned __int128)(mm[4])) << (4 * 8)) |
			(((unsigned __int128)(mm[5])) << (5 * 8)) |
			(((unsigned __int128)(mm[6])) << (6 * 8)) |
			(((unsigned __int128)(mm[7])) << (7 * 8)) |
			(((unsigned __int128)(mm[8])) << (8 * 8)) |
			(((unsigned __int128)(mm[9])) << (9 * 8)) |
			(((unsigned __int128)(mm[10])) << (10 * 8)) |
			(((unsigned __int128)(mm[11])) << (11 * 8)) |
			(((unsigned __int128)(mm[12])) << (12 * 8)) |
			(((unsigned __int128)(mm[13])) << (13 * 8)) |
			(((unsigned __int128)(mm[14])) << (14 * 8)) |
			(((unsigned __int128)(mm[15])) << (15 * 8));
	}

	ret = mz == z && mr == r;
	return ret;

	#else
	((void)(data));
	((void)(size));
	return mk_lang_true;
	#endif
}

mk_lang_bool_t test_basic_types_div_lll8(unsigned char const* data, size_t size)
{
	#if mk_lang_i128_has != 0

	unsigned __int128 x;
	unsigned __int128 y;
	unsigned __int128 z;
	unsigned __int128 r;
	unsigned __int128 mz;
	unsigned __int128 mr;
	mk_lang_bool_t ret;

	if(!data) return mk_lang_true;
	if(!(size >= 32)) return mk_lang_true;
	x = 0;
	y = 0;
	memcpy(&x, data +  0, 16);
	memcpy(&y, data + 16, 16);
	if(!(y != 0)) return mk_lang_true;
	z = x / y;
	r = x % y;

	{
		unsigned short int xx[8];
		unsigned short int yy[8];
		unsigned short int dd[8];
		unsigned short int mm[8];

		xx[0] = (x >> (0 * 16)) & 0xffff;
		xx[1] = (x >> (1 * 16)) & 0xffff;
		xx[2] = (x >> (2 * 16)) & 0xffff;
		xx[3] = (x >> (3 * 16)) & 0xffff;
		xx[4] = (x >> (4 * 16)) & 0xffff;
		xx[5] = (x >> (5 * 16)) & 0xffff;
		xx[6] = (x >> (6 * 16)) & 0xffff;
		xx[7] = (x >> (7 * 16)) & 0xffff;
		yy[0] = (y >> (0 * 16)) & 0xffff;
		yy[1] = (y >> (1 * 16)) & 0xffff;
		yy[2] = (y >> (2 * 16)) & 0xffff;
		yy[3] = (y >> (3 * 16)) & 0xffff;
		yy[4] = (y >> (4 * 16)) & 0xffff;
		yy[5] = (y >> (5 * 16)) & 0xffff;
		yy[6] = (y >> (6 * 16)) & 0xffff;
		yy[7] = (y >> (7 * 16)) & 0xffff;
		mk_num_div_mod_ushort_8_8(xx, yy, dd, mm);
		mz =
			(((unsigned __int128)(dd[0])) << (0 * 16)) |
			(((unsigned __int128)(dd[1])) << (1 * 16)) |
			(((unsigned __int128)(dd[2])) << (2 * 16)) |
			(((unsigned __int128)(dd[3])) << (3 * 16)) |
			(((unsigned __int128)(dd[4])) << (4 * 16)) |
			(((unsigned __int128)(dd[5])) << (5 * 16)) |
			(((unsigned __int128)(dd[6])) << (6 * 16)) |
			(((unsigned __int128)(dd[7])) << (7 * 16));
		mr =
			(((unsigned __int128)(mm[0])) << (0 * 16)) |
			(((unsigned __int128)(mm[1])) << (1 * 16)) |
			(((unsigned __int128)(mm[2])) << (2 * 16)) |
			(((unsigned __int128)(mm[3])) << (3 * 16)) |
			(((unsigned __int128)(mm[4])) << (4 * 16)) |
			(((unsigned __int128)(mm[5])) << (5 * 16)) |
			(((unsigned __int128)(mm[6])) << (6 * 16)) |
			(((unsigned __int128)(mm[7])) << (7 * 16));
	}

	ret = mz == z && mr == r;
	return ret;

	#else
	((void)(data));
	((void)(size));
	return mk_lang_true;
	#endif
}

mk_lang_bool_t test_basic_types_div_lll4(unsigned char const* data, size_t size)
{
	#if mk_lang_i128_has != 0

	unsigned __int128 x;
	unsigned __int128 y;
	unsigned __int128 z;
	unsigned __int128 r;
	unsigned __int128 mz;
	unsigned __int128 mr;
	mk_lang_bool_t ret;

	if(!data) return mk_lang_true;
	if(!(size >= 32)) return mk_lang_true;
	x = 0;
	y = 0;
	memcpy(&x, data +  0, 16);
	memcpy(&y, data + 16, 16);
	if(!(y != 0)) return mk_lang_true;
	z = x / y;
	r = x % y;

	{
		unsigned long int xx[4];
		unsigned long int yy[4];
		unsigned long int dd[4];
		unsigned long int mm[4];

		xx[0] = (x >> (0 * 32)) & 0xfffffffful;
		xx[1] = (x >> (1 * 32)) & 0xfffffffful;
		xx[2] = (x >> (2 * 32)) & 0xfffffffful;
		xx[3] = (x >> (3 * 32)) & 0xfffffffful;
		yy[0] = (y >> (0 * 32)) & 0xfffffffful;
		yy[1] = (y >> (1 * 32)) & 0xfffffffful;
		yy[2] = (y >> (2 * 32)) & 0xfffffffful;
		yy[3] = (y >> (3 * 32)) & 0xfffffffful;
		mk_num_div_mod_ulong_4_4(xx, yy, dd, mm);
		mz =
			(((unsigned __int128)(dd[0])) << (0 * 32)) |
			(((unsigned __int128)(dd[1])) << (1 * 32)) |
			(((unsigned __int128)(dd[2])) << (2 * 32)) |
			(((unsigned __int128)(dd[3])) << (3 * 32));
		mr =
			(((unsigned __int128)(mm[0])) << (0 * 32)) |
			(((unsigned __int128)(mm[1])) << (1 * 32)) |
			(((unsigned __int128)(mm[2])) << (2 * 32)) |
			(((unsigned __int128)(mm[3])) << (3 * 32));
	}

	ret = mz == z && mr == r;
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
	ret = ret && test_basic_types_mul_3();
	ret = ret && test_basic_types_div_l4(data, size);
	ret = ret && test_basic_types_div_ll8(data, size);
	ret = ret && test_basic_types_div_ll4(data, size);
	ret = ret && test_basic_types_div_lll16(data, size);
	ret = ret && test_basic_types_div_lll8(data, size);
	ret = ret && test_basic_types_div_lll4(data, size);
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
	static long int const rep = 1000000l;
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
		((void)(tested));
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
#include "../../../libs/mk_num/src/mk_num_div_mod.c"
#include "../../../libs/mk_num/src/mk_num_basic_uints.c"
#include "../../../libs/mk_num/src/mk_num_composite_uints.c"
#include "../../../libs/mk_num/src/mk_lang_crash.c"
#define mk_num_composite_bits 25
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.c"
#define mk_num_composite_bits 6656
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.c"
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
