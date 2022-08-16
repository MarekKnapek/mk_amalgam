#if mk_uint_parts != 1


#include "../../../mk_utils/src/mk_assert.h"
#include "../../../mk_utils/src/mk_jumbo.h"


mk_jumbo void mk_uint_divmod(mk_uint_t* div, mk_uint_t* mod, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r_div;
	mk_uint_t r_mod;
	mk_uint_small_t one;
	mk_uint_t aa;
	mk_uint_t bb;
	int ai;
	int bi;
	int i;
	unsigned bit;
	int diff;

	mk_assert(div);
	mk_assert(mod);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_is_zero(b));

	mk_uint_zero(&r_div);
	r_mod = *a;
	if(mk_uint_ge(a, b))
	{
		mk_uint_small_one(&one);
		aa = *a;
		bb = *b;
		ai = 0;
		bi = 0;
		for(i = 0; i != mk_uint_bits - 1; ++i)
		{
			mk_uint_shr(&aa, &aa, 1);
			bit = mk_uint_to_int(&aa) & 0x01;
			if(bit != 0)
			{
				ai = i + 1;
			}
		}
		for(i = 0; i != mk_uint_bits - 1; ++i)
		{
			mk_uint_shr(&bb, &bb, 1);
			bit = mk_uint_to_int(&bb) & 0x01;
			if(bit != 0)
			{
				bi = i + 1;
			}
		}
		diff = ai - bi;
		aa = *a;
		mk_uint_shl(&bb, b, diff);
		for(i = 0; i != diff + 1; ++i)
		{
			mk_uint_shl(&r_div, &r_div, 1);
			if(mk_uint_ge(&aa, &bb))
			{
				mk_uint_sub(&aa, &aa, &bb);
				mk_uint_small_or(&r_div.m_data[0], &r_div.m_data[0], &one);
			}
			mk_uint_shr(&bb, &bb, 1);
			r_mod = aa;
		}
	}

	*div = r_div;
	*mod = r_mod;
}


#endif


#define mk_uint_str_suffix n
#define mk_char_t char
#define mk_char_c(x) x
#define mk_str_c(x) x
#include "mk_uint_any_str.inl.c"
#undef mk_uint_str_suffix
#undef mk_char_t
#undef mk_char_c
#undef mk_str_c


#define mk_uint_str_suffix w
#define mk_char_t wchar_t
#define mk_char_c(x) L ## x
#define mk_str_c(x) L ## x
#include "mk_uint_any_str.inl.c"
#undef mk_uint_str_suffix
#undef mk_char_t
#undef mk_char_c
#undef mk_str_c
