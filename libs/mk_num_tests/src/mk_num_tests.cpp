#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif
#include "../../../libs/mk_num/src/mk_lang_bool.h"
#include "../../../libs/mk_num/src/mk_lang_charbit.h"
#include "../../../libs/mk_num/src/mk_lang_cpp.h"
#include "../../../libs/mk_num/src/mk_lang_crash.h"
#include "../../../libs/mk_num/src/mk_lang_limits.h"
#include "../../../libs/mk_num/src/mk_lang_lllong.h"
#include "../../../libs/mk_num/src/mk_lang_llong.h"
#include "../../../libs/mk_num/src/mk_lang_memcmp.h"
#include "../../../libs/mk_num/src/mk_lang_memcpy.h"
#include "../../../libs/mk_num/src/mk_lang_sizeof.h"
#include "../../../libs/mk_num/src/mk_lang_sizet.h"
#include "../../../libs/mk_num/src/mk_lang_uintmaxt.h"
#include "../../../libs/mk_num/src/mk_num_basic_uints.h"
#include "../../../libs/mk_num/src/mk_num_composite_uints.h"
#define mk_num_composite_bits 25
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.h"
#define mk_num_composite_bits 6656
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.h"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#if mk_lang_llong_has != 0
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#endif
#if mk_lang_lllong_has != 0
#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ulong
#define mk_num_div_mod_small_type unsigned long int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ulong
#define mk_num_div_mod_small_type unsigned long int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.h"
#endif
#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#pragma warning(disable:5045) /* warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified */
#endif


#define test(x) do{ if(!(x)){ mk_lang_crash(); } }while(0)


void test_basic_types_max(void)
{
	unsigned char uchar;
	unsigned short int ushort;
	unsigned int uint;
	unsigned long int ulong;
	mk_lang_ullong_t ullong;
	mk_lang_size_t usize;
	mk_lang_uintmax_t umax;

	uchar = ((unsigned char)(((unsigned char)(((unsigned char)(((unsigned char)(((unsigned char)(1)) << (sizeof(unsigned char) * mk_lang_charbit - 1))) - 1)) << 1)) + 1));
	ushort = ((unsigned short int)(((unsigned short int)(((unsigned short int)(((unsigned short int)(((unsigned short int)(1)) << (sizeof(unsigned short int) * mk_lang_charbit - 1))) - 1)) << 1)) + 1));
	uint = ((unsigned int)(((unsigned int)(((unsigned int)(((unsigned int)(((unsigned int)(1)) << (sizeof(unsigned int) * mk_lang_charbit - 1))) - 1)) << 1)) + 1));
	ulong = ((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(((unsigned long int)(1)) << (sizeof(unsigned long int) * mk_lang_charbit - 1))) - 1)) << 1)) + 1));
	ullong = ((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(((mk_lang_ullong_t)(1)) << (sizeof(mk_lang_ullong_t) * mk_lang_charbit - 1))) - 1)) << 1)) + 1));
	usize = ((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(((mk_lang_size_t)(1)) << (sizeof(mk_lang_size_t) * mk_lang_charbit - 1))) - 1)) << 1)) + 1));
	umax = ((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(((mk_lang_uintmax_t)(1)) << (sizeof(mk_lang_uintmax_t) * mk_lang_charbit - 1))) - 1)) << 1)) + 1));

	test(uchar == UCHAR_MAX);
	test(ushort == USHRT_MAX);
	test(uint == UINT_MAX);
	test(ulong == ULONG_MAX);
	test(ullong == mk_lang_limits_ullongmax);
	test(usize == mk_lang_limits_sizemax);
	test(umax == mk_lang_limits_uintmaxmax);
}

void test_factorial_800(void)
{
	static unsigned char const s_factorial_800_be[] = {0x86, 0xfe, 0x52, 0x70, 0x5c, 0xaf, 0x49, 0xd4, 0x58, 0x35, 0x48, 0x24, 0x18, 0x95, 0xe9, 0x86, 0xd0, 0x6e, 0x8f, 0x92, 0x7c, 0x96, 0xba, 0x41, 0x40, 0x47, 0x2e, 0xe8, 0xf9, 0x22, 0xf2, 0x80, 0xe1, 0x06, 0x34, 0xf6, 0x69, 0x9b, 0x3c, 0x49, 0x22, 0x3b, 0x2b, 0x3b, 0x32, 0xcc, 0x1f, 0x24, 0xb7, 0x49, 0x94, 0xc2, 0x4d, 0x05, 0xae, 0xff, 0x5f, 0x8b, 0x83, 0xed, 0xed, 0x2a, 0xb3, 0xf9, 0x2a, 0x56, 0x3d, 0xd7, 0x16, 0x47, 0x7c, 0xc1, 0x26, 0xea, 0x0c, 0x0a, 0x5e, 0x99, 0x6d, 0x6c, 0x1b, 0x91, 0x7b, 0x69, 0xf6, 0x34, 0xa3, 0x22, 0x77, 0xe0, 0x24, 0x36, 0x7d, 0x98, 0x1c, 0xb2, 0xa7, 0xa1, 0x24, 0xa8, 0xc0, 0x5a, 0x95, 0x71, 0x7e, 0xfb, 0x84, 0x47, 0x46, 0x94, 0xa3, 0xb9, 0xe2, 0x66, 0x8c, 0x03, 0xb2, 0x7c, 0x95, 0x42, 0xe7, 0xef, 0x60, 0x27, 0xfa, 0x46, 0xc0, 0x45, 0x58, 0xa8, 0xd7, 0x9d, 0x9b, 0x0f, 0xf2, 0x07, 0x15, 0x58, 0xec, 0x92, 0x3a, 0x41, 0x15, 0x3c, 0xec, 0x6e, 0x7c, 0x70, 0xcc, 0xc9, 0xd5, 0x87, 0xde, 0x17, 0xa9, 0x88, 0x67, 0x26, 0x19, 0x69, 0x31, 0xda, 0x40, 0xd7, 0xab, 0xdf, 0x1b, 0x3f, 0x44, 0x37, 0xfb, 0x5f, 0x03, 0x49, 0x0a, 0x1e, 0x0b, 0x4d, 0x08, 0x59, 0xe1, 0x5b, 0x01, 0x17, 0x6a, 0x0e, 0x96, 0xd2, 0x4e, 0x30, 0x0d, 0x31, 0x29, 0x49, 0x96, 0xbb, 0x3d, 0xab, 0x60, 0x39, 0x0e, 0x60, 0xb4, 0xbb, 0xc3, 0x14, 0x8e, 0x1d, 0xa0, 0x34, 0x1f, 0xca, 0x48, 0x39, 0x60, 0xdf, 0xb1, 0xd1, 0xde, 0x8d, 0x84, 0x6d, 0x75, 0xa7, 0x7b, 0xb7, 0x54, 0xce, 0x7b, 0xbd, 0xdf, 0x18, 0xad, 0xa1, 0x61, 0xc8, 0xa8, 0x1d, 0x7d, 0xd8, 0x75, 0x7c, 0x9e, 0xd8, 0xeb, 0xb5, 0x5e, 0x81, 0x5c, 0x78, 0x5e, 0x4e, 0x68, 0x50, 0x74, 0xf4, 0xd7, 0x4a, 0x14, 0x45, 0xcf, 0x94, 0x19, 0xb8, 0x77, 0x6f, 0xa2, 0xc8, 0xbf, 0xca, 0x06, 0xd8, 0x76, 0x11, 0xb8, 0x95, 0xff, 0x60, 0x4c, 0xd9, 0x6b, 0x90, 0x5f, 0xa6, 0x08, 0xb8, 0xab, 0x0c, 0x1a, 0x16, 0xad, 0x22, 0xd1, 0xa6, 0x7a, 0x44, 0x76, 0x63, 0xfe, 0xfa, 0x22, 0x1c, 0xbb, 0xb8, 0x3b, 0x82, 0xcf, 0xf3, 0x22, 0xb9, 0xd5, 0xd1, 0x09, 0x12, 0x26, 0xd3, 0x44, 0x1c, 0x72, 0xd7, 0x1c, 0x24, 0xaa, 0x7a, 0x37, 0x4c, 0xf4, 0x17, 0x97, 0x7c, 0xa3, 0xc6, 0xd4, 0x12, 0x46, 0xb4, 0x4c, 0xcd, 0x7e, 0x83, 0x8b, 0xeb, 0x27, 0xc4, 0x03, 0x3c, 0xcc, 0xc7, 0x13, 0x88, 0x80, 0x9a, 0x72, 0x8c, 0x95, 0x3d, 0x70, 0xa9, 0x05, 0xbc, 0x70, 0xc0, 0x94, 0xe2, 0x66, 0x11, 0xf4, 0xcb, 0xfd, 0x8a, 0x96, 0xe5, 0x52, 0xf9, 0x2a, 0x30, 0x34, 0x86, 0x29, 0x7c, 0xac, 0x6b, 0x06, 0x9c, 0x8b, 0xd7, 0xb2, 0x83, 0x04, 0xdd, 0x26, 0x40, 0x44, 0x51, 0x4a, 0x5a, 0x68, 0xca, 0xd6, 0x10, 0x7e, 0xb9, 0x2a, 0xdd, 0xe3, 0x18, 0x27, 0x53, 0xd2, 0xbe, 0xd6, 0x7b, 0x39, 0x9d, 0x75, 0x3e, 0x66, 0x23, 0xda, 0xfa, 0x83, 0x79, 0x87, 0xf1, 0x71, 0x8b, 0x21, 0x90, 0x0f, 0xe3, 0x35, 0x23, 0xab, 0xfb, 0x61, 0x7b, 0xb4, 0xf4, 0xa2, 0x7c, 0x57, 0xeb, 0xf7, 0x41, 0x1f, 0xcd, 0xfb, 0x58, 0x30, 0x13, 0x21, 0x89, 0x54, 0x3d, 0x6c, 0x99, 0x6e, 0x60, 0x89, 0x60, 0x2a, 0x91, 0x6a, 0x59, 0x97, 0xe4, 0x3a, 0xd9, 0x37, 0xdf, 0x64, 0x92, 0x80, 0x30, 0x60, 0xef, 0x47, 0xfe, 0xd0, 0xe8, 0x45, 0x18, 0x90, 0x23, 0x44, 0x5b, 0x31, 0x3a, 0xe3, 0xe1, 0x22, 0xd0, 0xb1, 0x11, 0xcc, 0xd3, 0x2e, 0xb7, 0x5c, 0x29, 0xd9, 0x0c, 0xc9, 0x87, 0x33, 0x97, 0xa4, 0xce, 0x8c, 0xb0, 0x85, 0x9c, 0xae, 0xae, 0xca, 0xc6, 0xbf, 0x46, 0x9b, 0x3c, 0xc6, 0x1c, 0xcf, 0xe0, 0xd9, 0x43, 0x9b, 0xc5, 0xca, 0xde, 0x80, 0x7e, 0x38, 0xad, 0x0b, 0xbc, 0xfe, 0xa0, 0x91, 0xd1, 0x86, 0x91, 0xfd, 0x5c, 0x61, 0x5a, 0x6c, 0xb1, 0xe6, 0x6a, 0x8e, 0xf3, 0x07, 0x51, 0x8c, 0x43, 0x82, 0xaf, 0xa8, 0xda, 0x60, 0x0d, 0x0f, 0x17, 0x78, 0x08, 0x13, 0x19, 0xa7, 0xa8, 0x19, 0xf0, 0x8a, 0xfa, 0x91, 0xdd, 0xca, 0x26, 0x29, 0x7c, 0x18, 0xee, 0x05, 0x2d, 0xff, 0xf7, 0xa1, 0x20, 0x0c, 0xfa, 0xfc, 0x99, 0xb7, 0x35, 0xd9, 0xd9, 0x64, 0xc9, 0x55, 0x95, 0x96, 0x0c, 0x0b, 0x58, 0xfc, 0xd8, 0x43, 0x1b, 0x29, 0xa6, 0x2f, 0x09, 0xc7, 0x5d, 0xad, 0x0f, 0xe2, 0x9e, 0x1d, 0x26, 0x88, 0xc7, 0xff, 0x60, 0xcc, 0x81, 0x87, 0x22, 0x2c, 0x33, 0x66, 0x8b, 0x9c, 0x46, 0xaf, 0xca, 0xbc, 0xdb, 0x1d, 0x70, 0x9b, 0x00, 0x53, 0x8e, 0xee, 0xda, 0x13, 0x48, 0x83, 0xf6, 0xaa, 0x1c, 0x2e, 0xce, 0xc7, 0xc5, 0x62, 0xd8, 0xb9, 0x0e, 0x9b, 0xf6, 0xf5, 0xbc, 0x41, 0xe4, 0xfd, 0x9c, 0xdb, 0x9a, 0x0d, 0xc2, 0xee, 0xae, 0x59, 0x06, 0x25, 0xad, 0x46, 0xa6, 0xe3, 0x2a, 0xea, 0xf5, 0xa2, 0x01, 0xad, 0x6c, 0x43, 0x5f, 0xd8, 0x8c, 0xfa, 0x55, 0xd1, 0x41, 0x6f, 0xbd, 0xfb, 0x46, 0x57, 0x4b, 0x71, 0x39, 0x6d, 0xbd, 0x17, 0xf2, 0xca, 0x1d, 0x16, 0x34, 0x10, 0xdc, 0xdf, 0x19, 0x8e, 0xf8, 0x76, 0x94, 0xb0, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	int n;
	mk_num_composite_u6656_t a;
	mk_num_composite_u6656_t b;
	int i;
	unsigned char buff[6656 / mk_lang_charbit];

	n = 800;
	mk_num_composite_u6656_set_one(&a);
	b = a;
	for(i = 0; i != n - 1; ++i)
	{
		mk_num_composite_u6656_inc(&b);
		mk_num_composite_u6656_mul3_wrap_cid_cod(&a, &b, &a);
	}
	mk_num_composite_u6656_to_buff_be(&a, buff);
	test(mk_lang_memcmp(buff + (sizeof(buff) - sizeof(s_factorial_800_be)), s_factorial_800_be, sizeof(s_factorial_800_be)) == 0);
}

void test_division_long(unsigned char const* data, size_t size)
{
	#if mk_lang_charbit == 8

	unsigned long int bx;
	unsigned long int by;
	unsigned long int bresdiv;
	unsigned long int bresmod;

	if(!(data)) return;
	if(!(size >= 2 * 4)) return;
	bx = 0;
	by = 0;
	mk_lang_memcpy(&bx, data, 4);
	mk_lang_memcpy(&by, data + 4, 4);
	if(by == 0)
	{
		bresdiv = 0;
		--bresdiv;
		bresmod = 0;
		--bresmod;
	}
	else
	{
		bresdiv = bx / by;
		bresmod = bx % by;
	}
	{
		int i;
		unsigned char mx[4];
		unsigned char my[4];
		unsigned char mresdiv[4];
		unsigned char mresmod[4];
		unsigned long int mresdiv_;
		unsigned long int mresmod_;
		for(i = 0; i != 4; ++i)
		{
			mx[i] = (bx >> (i * mk_lang_charbit)) & 0xfful;
		}
		for(i = 0; i != 4; ++i)
		{
			my[i] = (by >> (i * mk_lang_charbit)) & 0xfful;
		}
		mk_num_div_mod_uchar_4_4_r3d2(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 4; ++i)
		{
			mresdiv_ |= ((unsigned long int)(mresdiv[i])) << (i * mk_lang_charbit);
		}
		for(i = 0; i != 4; ++i)
		{
			mresmod_ |= ((unsigned long int)(mresmod[i])) << (i * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	{
		int i;
		unsigned char mx[4];
		unsigned char my[4];
		unsigned char mresdiv[4];
		unsigned char mresmod[4];
		unsigned long int mresdiv_;
		unsigned long int mresmod_;
		for(i = 0; i != 4; ++i)
		{
			mx[i] = (bx >> (i * mk_lang_charbit)) & 0xfful;
		}
		for(i = 0; i != 4; ++i)
		{
			my[i] = (by >> (i * mk_lang_charbit)) & 0xfful;
		}
		mk_num_div_mod_uchar_4_4_r2d1(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 4; ++i)
		{
			mresdiv_ |= ((unsigned long int)(mresdiv[i])) << (i * mk_lang_charbit);
		}
		for(i = 0; i != 4; ++i)
		{
			mresmod_ |= ((unsigned long int)(mresmod[i])) << (i * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	#else
	((void)(data));
	((void)(size));
	#endif
}

void test_division_llong(unsigned char const* data, size_t size)
{
	#if mk_lang_charbit == 8 && mk_lang_llong_has != 0

	mk_lang_ullong_t bx;
	mk_lang_ullong_t by;
	mk_lang_ullong_t bresdiv;
	mk_lang_ullong_t bresmod;

	if(!(data)) return;
	if(!(size >= 2 * 8)) return;
	bx = 0;
	by = 0;
	mk_lang_memcpy(&bx, data, 8);
	mk_lang_memcpy(&by, data + 8, 8);
	if(by == 0)
	{
		bresdiv = 0;
		--bresdiv;
		bresmod = 0;
		--bresmod;
	}
	else
	{
		bresdiv = bx / by;
		bresmod = bx % by;
	}
	{
		int i;
		unsigned char mx[8];
		unsigned char my[8];
		unsigned char mresdiv[8];
		unsigned char mresmod[8];
		mk_lang_ullong_t mresdiv_;
		mk_lang_ullong_t mresmod_;
		for(i = 0; i != 8; ++i)
		{
			mx[i] = (bx >> (i * mk_lang_charbit)) & 0xfful;
		}
		for(i = 0; i != 8; ++i)
		{
			my[i] = (by >> (i * mk_lang_charbit)) & 0xfful;
		}
		mk_num_div_mod_uchar_8_8_r3d2(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 8; ++i)
		{
			mresdiv_ |= ((mk_lang_ullong_t)(mresdiv[i])) << (i * mk_lang_charbit);
		}
		for(i = 0; i != 8; ++i)
		{
			mresmod_ |= ((mk_lang_ullong_t)(mresmod[i])) << (i * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	{
		int i;
		unsigned char mx[8];
		unsigned char my[8];
		unsigned char mresdiv[8];
		unsigned char mresmod[8];
		mk_lang_ullong_t mresdiv_;
		mk_lang_ullong_t mresmod_;
		for(i = 0; i != 8; ++i)
		{
			mx[i] = (bx >> (i * mk_lang_charbit)) & 0xfful;
		}
		for(i = 0; i != 8; ++i)
		{
			my[i] = (by >> (i * mk_lang_charbit)) & 0xfful;
		}
		mk_num_div_mod_uchar_8_8_r2d1(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 8; ++i)
		{
			mresdiv_ |= ((mk_lang_ullong_t)(mresdiv[i])) << (i * mk_lang_charbit);
		}
		for(i = 0; i != 8; ++i)
		{
			mresmod_ |= ((mk_lang_ullong_t)(mresmod[i])) << (i * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	{
		int i;
		unsigned short int mx[4];
		unsigned short int my[4];
		unsigned short int mresdiv[4];
		unsigned short int mresmod[4];
		mk_lang_ullong_t mresdiv_;
		mk_lang_ullong_t mresmod_;
		for(i = 0; i != 4; ++i)
		{
			mx[i] = (bx >> (i * 2 * mk_lang_charbit)) & 0xfffful;
		}
		for(i = 0; i != 4; ++i)
		{
			my[i] = (by >> (i * 2 * mk_lang_charbit)) & 0xfffful;
		}
		mk_num_div_mod_ushort_4_4_r3d2(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 4; ++i)
		{
			mresdiv_ |= ((mk_lang_ullong_t)(mresdiv[i])) << (i * 2 * mk_lang_charbit);
		}
		for(i = 0; i != 4; ++i)
		{
			mresmod_ |= ((mk_lang_ullong_t)(mresmod[i])) << (i * 2 * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	{
		int i;
		unsigned short int mx[4];
		unsigned short int my[4];
		unsigned short int mresdiv[4];
		unsigned short int mresmod[4];
		mk_lang_ullong_t mresdiv_;
		mk_lang_ullong_t mresmod_;
		for(i = 0; i != 4; ++i)
		{
			mx[i] = (bx >> (i * 2 * mk_lang_charbit)) & 0xfffful;
		}
		for(i = 0; i != 4; ++i)
		{
			my[i] = (by >> (i * 2 * mk_lang_charbit)) & 0xfffful;
		}
		mk_num_div_mod_ushort_4_4_r2d1(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 4; ++i)
		{
			mresdiv_ |= ((mk_lang_ullong_t)(mresdiv[i])) << (i * 2 * mk_lang_charbit);
		}
		for(i = 0; i != 4; ++i)
		{
			mresmod_ |= ((mk_lang_ullong_t)(mresmod[i])) << (i * 2 * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	#else
	((void)(data));
	((void)(size));
	#endif
}

void test_division_lllong(unsigned char const* data, size_t size)
{
	#if mk_lang_charbit == 8 && mk_lang_lllong_has != 0

	mk_lang_ulllong_t bx;
	mk_lang_ulllong_t by;
	mk_lang_ulllong_t bresdiv;
	mk_lang_ulllong_t bresmod;

	if(!(data)) return;
	if(!(size >= 2 * 16)) return;
	bx = 0;
	by = 0;
	mk_lang_memcpy(&bx, data, 16);
	mk_lang_memcpy(&by, data + 16, 16);
	if(by == 0)
	{
		bresdiv = 0;
		--bresdiv;
		bresmod = 0;
		--bresmod;
	}
	else
	{
		bresdiv = bx / by;
		bresmod = bx % by;
	}
	{
		int i;
		unsigned char mx[16];
		unsigned char my[16];
		unsigned char mresdiv[16];
		unsigned char mresmod[16];
		mk_lang_ulllong_t mresdiv_;
		mk_lang_ulllong_t mresmod_;
		for(i = 0; i != 16; ++i)
		{
			mx[i] = (bx >> (i * mk_lang_charbit)) & 0xfful;
		}
		for(i = 0; i != 16; ++i)
		{
			my[i] = (by >> (i * mk_lang_charbit)) & 0xfful;
		}
		mk_num_div_mod_uchar_16_16_r3d2(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 16; ++i)
		{
			mresdiv_ |= ((mk_lang_ulllong_t)(mresdiv[i])) << (i * mk_lang_charbit);
		}
		for(i = 0; i != 16; ++i)
		{
			mresmod_ |= ((mk_lang_ulllong_t)(mresmod[i])) << (i * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	{
		int i;
		unsigned char mx[16];
		unsigned char my[16];
		unsigned char mresdiv[16];
		unsigned char mresmod[16];
		mk_lang_ulllong_t mresdiv_;
		mk_lang_ulllong_t mresmod_;
		for(i = 0; i != 16; ++i)
		{
			mx[i] = (bx >> (i * mk_lang_charbit)) & 0xfful;
		}
		for(i = 0; i != 16; ++i)
		{
			my[i] = (by >> (i * mk_lang_charbit)) & 0xfful;
		}
		mk_num_div_mod_uchar_16_16_r2d1(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 16; ++i)
		{
			mresdiv_ |= ((mk_lang_ulllong_t)(mresdiv[i])) << (i * mk_lang_charbit);
		}
		for(i = 0; i != 16; ++i)
		{
			mresmod_ |= ((mk_lang_ulllong_t)(mresmod[i])) << (i * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	{
		int i;
		unsigned short int mx[8];
		unsigned short int my[8];
		unsigned short int mresdiv[8];
		unsigned short int mresmod[8];
		mk_lang_ulllong_t mresdiv_;
		mk_lang_ulllong_t mresmod_;
		for(i = 0; i != 8; ++i)
		{
			mx[i] = (bx >> (i * 2 * mk_lang_charbit)) & 0xfffful;
		}
		for(i = 0; i != 8; ++i)
		{
			my[i] = (by >> (i * 2 * mk_lang_charbit)) & 0xfffful;
		}
		mk_num_div_mod_ushort_8_8_r3d2(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 8; ++i)
		{
			mresdiv_ |= ((mk_lang_ulllong_t)(mresdiv[i])) << (i * 2 * mk_lang_charbit);
		}
		for(i = 0; i != 8; ++i)
		{
			mresmod_ |= ((mk_lang_ulllong_t)(mresmod[i])) << (i * 2 * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	{
		int i;
		unsigned short int mx[8];
		unsigned short int my[8];
		unsigned short int mresdiv[8];
		unsigned short int mresmod[8];
		mk_lang_ulllong_t mresdiv_;
		mk_lang_ulllong_t mresmod_;
		for(i = 0; i != 8; ++i)
		{
			mx[i] = (bx >> (i * 2 * mk_lang_charbit)) & 0xfffful;
		}
		for(i = 0; i != 8; ++i)
		{
			my[i] = (by >> (i * 2 * mk_lang_charbit)) & 0xfffful;
		}
		mk_num_div_mod_ushort_8_8_r2d1(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 8; ++i)
		{
			mresdiv_ |= ((mk_lang_ulllong_t)(mresdiv[i])) << (i * 2 * mk_lang_charbit);
		}
		for(i = 0; i != 8; ++i)
		{
			mresmod_ |= ((mk_lang_ulllong_t)(mresmod[i])) << (i * 2 * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	{
		int i;
		unsigned long int mx[4];
		unsigned long int my[4];
		unsigned long int mresdiv[4];
		unsigned long int mresmod[4];
		mk_lang_ulllong_t mresdiv_;
		mk_lang_ulllong_t mresmod_;
		for(i = 0; i != 4; ++i)
		{
			mx[i] = (bx >> (i * 4 * mk_lang_charbit)) & 0xfffffffful;
		}
		for(i = 0; i != 4; ++i)
		{
			my[i] = (by >> (i * 4 * mk_lang_charbit)) & 0xfffffffful;
		}
		mk_num_div_mod_ulong_4_4_r3d2(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 4; ++i)
		{
			mresdiv_ |= ((mk_lang_ulllong_t)(mresdiv[i])) << (i * 4 * mk_lang_charbit);
		}
		for(i = 0; i != 4; ++i)
		{
			mresmod_ |= ((mk_lang_ulllong_t)(mresmod[i])) << (i * 4 * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	{
		int i;
		unsigned long int mx[4];
		unsigned long int my[4];
		unsigned long int mresdiv[4];
		unsigned long int mresmod[4];
		mk_lang_ulllong_t mresdiv_;
		mk_lang_ulllong_t mresmod_;
		for(i = 0; i != 4; ++i)
		{
			mx[i] = (bx >> (i * 4 * mk_lang_charbit)) & 0xfffffffful;
		}
		for(i = 0; i != 4; ++i)
		{
			my[i] = (by >> (i * 4 * mk_lang_charbit)) & 0xfffffffful;
		}
		mk_num_div_mod_ulong_4_4_r2d1(mx, my, mresdiv, mresmod);
		mresdiv_ = 0;
		mresmod_ = 0;
		for(i = 0; i != 4; ++i)
		{
			mresdiv_ |= ((mk_lang_ulllong_t)(mresdiv[i])) << (i * 4 * mk_lang_charbit);
		}
		for(i = 0; i != 4; ++i)
		{
			mresmod_ |= ((mk_lang_ulllong_t)(mresmod[i])) << (i * 4 * mk_lang_charbit);
		}
		test(mresdiv_ == bresdiv);
		test(mresmod_ == bresmod);
	}
	#else
	((void)(data));
	((void)(size));
	#endif
}

void test_arithmetics(unsigned char const* data, size_t size)
{
	unsigned int bits;
	unsigned int bytes;
	unsigned long int ba;
	unsigned long int bb;
	unsigned long int bc;
	unsigned long int bm;
	mk_num_composite_u25_t ma;
	mk_num_composite_u25_t mb;
	mk_num_composite_u25_t mc;
	unsigned char shift_;
	int shift;

	bits = 25;
	bytes = (bits + (mk_lang_charbit - 1)) / mk_lang_charbit;
	if(!(size >= 2 * bytes + 1)) return;
	ba = 0;
	bb = 0;
	bm = (((((unsigned long int)(1)) << (bits - 1)) - 1) << 1) + 1;
	shift_ = 0;
	mk_lang_memcpy(&ba, data, bytes); ba = ba & bm;
	mk_lang_memcpy(&bb, data + bytes, bytes); bb = bb & bm;
	mk_lang_memcpy(&shift_, data + 2 * bytes, 1); shift = ((int)(shift_));
	if(!(shift >= 0 && shift < ((int)(bits)))) return;

	mk_num_composite_u25_from_ulong(&ma, ba); test(mk_num_composite_u25_to_ulong(&ma) == ba);
	mk_num_composite_u25_from_ulong(&mb, bb); test(mk_num_composite_u25_to_ulong(&mb) == bb);

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
}

void test_once()
{
	static mk_lang_bool_t g_once = mk_lang_false;

	if(g_once) return;
	if(!g_once) g_once = mk_lang_true;

	test(mk_lang_sizeof_test());
	test_basic_types_max();
	test_factorial_800();
}

void test_multiple(unsigned char const* data, size_t size)
{
	test_division_long(data, size);
	test_division_llong(data, size);
	test_division_lllong(data, size);
	test_arithmetics(data, size);
}

mk_lang_extern_c int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size)
{
	test_once();
	test_multiple(data, size);
	return 0;
}


#undef test


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
		tested = LLVMFuzzerTestOneInput(buff, sizeof(buff)); ((void)(tested));
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
#pragma warning(disable:4514) /* warning C4514: 'xxx': unreferenced inline function has been removed */
#endif
#include "../../../libs/mk_num/src/mk_lang_crash.c"
#include "../../../libs/mk_num/src/mk_lang_memcmp.c"
#include "../../../libs/mk_num/src/mk_lang_memcpy.c"
#include "../../../libs/mk_num/src/mk_lang_sizeof.c"
#include "../../../libs/mk_num/src/mk_num_basic_uints.c"
#include "../../../libs/mk_num/src/mk_num_composite_uints.c"
#define mk_num_composite_bits 25
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.c"
#define mk_num_composite_bits 6656
#include "../../../libs/mk_num/src/mk_num_composite_guess_base.h"
#include "../../../libs/mk_num/src/mk_num_composite_uint.inl.c"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#define mk_num_div_mod_big_type unsigned long int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#if mk_lang_llong_has != 0
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#define mk_num_div_mod_big_type unsigned long int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned long int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_mid_type unsigned long int
#define mk_num_div_mod_big_type mk_lang_ullong_t
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_mid_type unsigned long int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#endif
#if mk_lang_lllong_has != 0
#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#define mk_num_div_mod_big_type unsigned long int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_mid_type unsigned long int
#define mk_num_div_mod_big_type mk_lang_ullong_t
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_mid_type unsigned long int
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ulong
#define mk_num_div_mod_small_type unsigned long int
#define mk_num_div_mod_mid_type mk_lang_ullong_t
#define mk_num_div_mod_big_type mk_lang_ulllong_t
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ulong
#define mk_num_div_mod_small_type unsigned long int
#define mk_num_div_mod_mid_type mk_lang_ullong_t
#include "../../../libs/mk_num/src/mk_num_div_mod.inl.c"
#endif
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
