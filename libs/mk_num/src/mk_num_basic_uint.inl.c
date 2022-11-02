#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_llong.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizet.h"
#include "mk_lang_uintmaxt.h"

#include <limits.h> /* CHAR_BIT */


#include "mk_num_basic_uint_def.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4514) /* warning C4514: 'xxx': unreferenced inline function has been removed */
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


mk_lang_jumbo void mk_num_set_zero(mk_detail_num_basic_ut_type* x)
{
	mk_lang_assert(x);

	*x = 0;
}

mk_lang_jumbo void mk_num_set_one(mk_detail_num_basic_ut_type* x)
{
	mk_lang_assert(x);

	*x = 1;
}

mk_lang_jumbo void mk_num_set_mask(mk_detail_num_basic_ut_type* x, int bits)
{
	#ifdef NDEBUG
	#else
	mk_detail_num_basic_ut_type tmp;
	#endif

	mk_lang_assert(x);
	mk_lang_assert(bits > 0 && bits <= ((int)(sizeof(mk_detail_num_basic_ut_type) * CHAR_BIT)));

	#ifdef NDEBUG
	*x = ((mk_detail_num_basic_ut_type)(((mk_detail_num_basic_ut_type)(((mk_detail_num_basic_ut_type)(((mk_detail_num_basic_ut_type)(((mk_detail_num_basic_ut_type)(1)) << (bits - 1))) - ((mk_detail_num_basic_ut_type)(1)))) << 1)) | ((mk_detail_num_basic_ut_type)(1))));
	#else
	tmp = ((mk_detail_num_basic_ut_type)(1));
	tmp = ((mk_detail_num_basic_ut_type)(tmp << (bits - 1)));
	tmp = ((mk_detail_num_basic_ut_type)(tmp - ((mk_detail_num_basic_ut_type)(1))));
	tmp = ((mk_detail_num_basic_ut_type)(tmp << 1));
	tmp = ((mk_detail_num_basic_ut_type)(tmp | ((mk_detail_num_basic_ut_type)(1))));
	*x = tmp;
	#endif
}


mk_lang_jumbo void mk_num_from_char(mk_detail_num_basic_ut_type* x, char src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_uchar(mk_detail_num_basic_ut_type* x, unsigned char src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_schar(mk_detail_num_basic_ut_type* x, signed char src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_ushort(mk_detail_num_basic_ut_type* x, unsigned short int src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_sshort(mk_detail_num_basic_ut_type* x, signed short int src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_uint(mk_detail_num_basic_ut_type* x, unsigned int src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_sint(mk_detail_num_basic_ut_type* x, signed int src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_ulong(mk_detail_num_basic_ut_type* x, unsigned long int src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_slong(mk_detail_num_basic_ut_type* x, signed long int src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_ullong(mk_detail_num_basic_ut_type* x, mk_lang_ullong_t src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_sllong(mk_detail_num_basic_ut_type* x, mk_lang_sllong_t src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_sizet(mk_detail_num_basic_ut_type* x, mk_lang_size_t src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_umaxt(mk_detail_num_basic_ut_type* x, mk_lang_uintmax_t src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}

mk_lang_jumbo void mk_num_from_smaxt(mk_detail_num_basic_ut_type* x, mk_lang_sintmax_t src)
{
	mk_lang_assert(x);

	*x = ((mk_detail_num_basic_ut_type)(src));
}


mk_lang_nodiscard mk_lang_jumbo char mk_num_to_char(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((char)(*x));
}

mk_lang_nodiscard mk_lang_jumbo unsigned char mk_num_to_uchar(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((unsigned char)(*x));
}

mk_lang_nodiscard mk_lang_jumbo signed char mk_num_to_schar(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((signed char)(*x));
}

mk_lang_nodiscard mk_lang_jumbo unsigned short int mk_num_to_ushort(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((unsigned short int)(*x));
}

mk_lang_nodiscard mk_lang_jumbo signed short int mk_num_to_sshort(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((signed short int)(*x));
}

mk_lang_nodiscard mk_lang_jumbo unsigned int mk_num_to_uint(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((unsigned int)(*x));
}

mk_lang_nodiscard mk_lang_jumbo signed int mk_num_to_sint(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((signed int)(*x));
}

mk_lang_nodiscard mk_lang_jumbo unsigned long int mk_num_to_ulong(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((unsigned long int)(*x));
}

mk_lang_nodiscard mk_lang_jumbo signed long int mk_num_to_slong(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((signed long int)(*x));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_ullong_t mk_num_to_ullong(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((mk_lang_ullong_t)(*x));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_sllong_t mk_num_to_sllong(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((mk_lang_sllong_t)(*x));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_num_to_sizet(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((mk_lang_size_t)(*x));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_uintmax_t mk_num_to_umaxt(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((mk_lang_uintmax_t)(*x));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_sintmax_t mk_num_to_smaxt(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return ((mk_lang_sintmax_t)(*x));
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_is_zero(mk_detail_num_basic_ut_type const* x)
{
	mk_lang_assert(x);

	return *x == 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_eq(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x == *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_ne(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x != *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_lt(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x < *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_le(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x <= *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_gt(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x > *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_ge(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x >= *y;
}


mk_lang_jumbo void mk_num_inc(mk_detail_num_basic_ut_type* x)
{
	mk_lang_assert(x);

	++*x;
}

mk_lang_jumbo void mk_num_dec(mk_detail_num_basic_ut_type* x)
{
	mk_lang_assert(x);

	--*x;
}


mk_lang_jumbo void mk_num_not2(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	*y = ((mk_detail_num_basic_ut_type)(~*x));
}

mk_lang_jumbo void mk_num_not1(mk_detail_num_basic_ut_type* x)
{
	mk_num_not2(x, x);
}

mk_lang_jumbo void mk_num_or3(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_detail_num_basic_ut_type)(*x | *y));
}

mk_lang_jumbo void mk_num_or2(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y)
{
	mk_num_or3(x, y, x);
}

mk_lang_jumbo void mk_num_and3(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_detail_num_basic_ut_type)(*x & *y));
}

mk_lang_jumbo void mk_num_and2(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y)
{
	mk_num_and3(x, y, x);
}

mk_lang_jumbo void mk_num_xor3(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_detail_num_basic_ut_type)(*x ^ *y));
}

mk_lang_jumbo void mk_num_xor2(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y)
{
	mk_num_xor3(x, y, x);
}


mk_lang_jumbo void mk_num_shl3(mk_detail_num_basic_ut_type const* x, int bits, mk_detail_num_basic_ut_type* y)
{
	mk_lang_assert(x);
	mk_lang_assert(bits >= 0 && bits < ((int)(sizeof(mk_detail_num_basic_ut_type) * CHAR_BIT)));
	mk_lang_assert(y);

	*y = ((mk_detail_num_basic_ut_type)(*x << bits));
}

mk_lang_jumbo void mk_num_shl2(mk_detail_num_basic_ut_type* x, int bits)
{
	mk_num_shl3(x, bits, x);
}

mk_lang_jumbo void mk_num_shr3(mk_detail_num_basic_ut_type const* x, int bits, mk_detail_num_basic_ut_type* y)
{
	mk_lang_assert(x);
	mk_lang_assert(bits >= 0 && bits < ((int)(sizeof(mk_detail_num_basic_ut_type) * CHAR_BIT)));
	mk_lang_assert(y);

	*y = ((mk_detail_num_basic_ut_type)(*x >> bits));
}

mk_lang_jumbo void mk_num_shr2(mk_detail_num_basic_ut_type* x, int bits)
{
	mk_num_shr3(x, bits, x);
}


mk_lang_jumbo void mk_num_add3_wrap_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_detail_num_basic_ut_type)(*x + *y));
}

mk_lang_jumbo void mk_num_add3_wrap_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_detail_num_basic_ut_type tmp;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(co);

	tmp = ((mk_detail_num_basic_ut_type)(*x + *y));
	*co = tmp < *x;
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_wrap_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_detail_num_basic_ut_type)(*x + *y + ci));
}

mk_lang_jumbo void mk_num_add3_wrap_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_detail_num_basic_ut_type tmp;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(co);

	tmp = ((mk_detail_num_basic_ut_type)(*x + *y + ci));
	*co = ci ? (tmp <= *x) : (tmp < *x);
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_sat_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_add3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		tmp = 0;
		--tmp;
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_sat_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_add3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		tmp = 0;
		--tmp;
	}
	*z = tmp;
	*co = b;
}

mk_lang_jumbo void mk_num_add3_sat_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_add3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		tmp = 0;
		--tmp;
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_sat_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_add3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		tmp = 0;
		--tmp;
	}
	*z = tmp;
	*co = b;
}

mk_lang_jumbo void mk_num_add3_crash_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_add3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		mk_lang_crash();
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_crash_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_add3_crash_cid_cod(x, y, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_add3_crash_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_add3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		mk_lang_crash();
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_crash_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_add3_crash_cie_cod(x, y, ci, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_add2_wrap_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y)
{
	mk_num_add3_wrap_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_add2_wrap_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co)
{
	mk_num_add3_wrap_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_add2_wrap_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci)
{
	mk_num_add3_wrap_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_add2_wrap_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_add3_wrap_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_add2_sat_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y)
{
	mk_num_add3_sat_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_add2_sat_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co)
{
	mk_num_add3_sat_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_add2_sat_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci)
{
	mk_num_add3_sat_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_add2_sat_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_add3_sat_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_add2_crash_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y)
{
	mk_num_add3_crash_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_add2_crash_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co)
{
	mk_num_add3_crash_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_add2_crash_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci)
{
	mk_num_add3_crash_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_add2_crash_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_add3_crash_cie_coe(x, y, ci, x, co);
}


mk_lang_jumbo void mk_num_sub3_wrap_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_detail_num_basic_ut_type)(*x - *y));
}

mk_lang_jumbo void mk_num_sub3_wrap_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(co);

	*co = *x < *y;
	*z = ((mk_detail_num_basic_ut_type)(*x - *y));
}

mk_lang_jumbo void mk_num_sub3_wrap_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_detail_num_basic_ut_type)(*x - *y - ci));
}

mk_lang_jumbo void mk_num_sub3_wrap_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(co);

	*co = ci ? (*x <= *y) : (*x < *y);
	*z = ((mk_detail_num_basic_ut_type)(*x - *y - ci));
}

mk_lang_jumbo void mk_num_sub3_sat_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_sub3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		tmp = 0;
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_sub3_sat_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_sub3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		tmp = 0;
	}
	*z = tmp;
	*co = b;
}

mk_lang_jumbo void mk_num_sub3_sat_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_sub3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		tmp = 0;
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_sub3_sat_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_sub3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		tmp = 0;
	}
	*z = tmp;
	*co = b;
}

mk_lang_jumbo void mk_num_sub3_crash_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_sub3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		mk_lang_crash();
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_sub3_crash_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_sub3_crash_cid_cod(x, y, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_sub3_crash_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z)
{
	mk_detail_num_basic_ut_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_sub3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		mk_lang_crash();
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_sub3_crash_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_sub3_crash_cie_cod(x, y, ci, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_sub2_wrap_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y)
{
	mk_num_sub3_wrap_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_sub2_wrap_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co)
{
	mk_num_sub3_wrap_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_sub2_wrap_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci)
{
	mk_num_sub3_wrap_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_sub2_wrap_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_sub3_wrap_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_sub2_sat_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y)
{
	mk_num_sub3_sat_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_sub2_sat_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co)
{
	mk_num_sub3_sat_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_sub2_sat_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci)
{
	mk_num_sub3_sat_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_sub2_sat_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_sub3_sat_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_sub2_crash_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y)
{
	mk_num_sub3_crash_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_sub2_crash_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co)
{
	mk_num_sub3_crash_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_sub2_crash_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci)
{
	mk_num_sub3_crash_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_sub2_crash_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_sub3_crash_cie_coe(x, y, ci, x, co);
}


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#include "mk_num_basic_uint_undef.h"


#undef mk_detail_num_basic_ut_type
#undef mk_detail_num_basic_ut_name
