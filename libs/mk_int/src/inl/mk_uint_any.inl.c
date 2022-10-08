#if mk_uint_parts != 1


#include "../../../mk_utils/src/mk_assert.h"
#include "../../../mk_utils/src/mk_inline.h"
#include "../../../mk_utils/src/mk_jumbo.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


static mk_inline void mk_uint_concat_(divmod_classic)(mk_uint_t* div, mk_uint_t* mod, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r_div;
	mk_uint_t r_mod;
	mk_uint_small_t one;
	mk_uint_t aa;
	mk_uint_t bb;
	int ai;
	int bi;
	int i;
	unsigned int bit;
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

static mk_inline void mk_uint_concat_(divmod_fast)(mk_uint_t* div, mk_uint_small_t* mod, mk_uint_t const* a, mk_uint_small_t const* b)
{
	mk_uint_small_t mask;
	int i;
	mk_uint_small_t smol;
	mk_uint_small_t digit;
	mk_uint_small_t m;
	mk_uint_t d;

	mk_assert(div);
	mk_assert(mod);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_small_is_zero(b));

	mk_uint_small_zero(&mask);
	mk_uint_small_inc(&mask);
	mk_uint_small_shl(&mask, &mask, mk_uint_small_bits / 2);
	mk_uint_small_dec(&mask);
	mk_uint_small_zero(&m);
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_shl(&m, &m, mk_uint_small_bits / 2);
		mk_uint_small_shr(&smol, &a->m_data[mk_uint_parts - 1 - i], mk_uint_small_bits / 2);
		mk_uint_small_or(&smol, &smol, &m);
		mk_uint_small_divmod(&smol, &m, &smol, b);
		mk_uint_small_shl(&digit, &smol, mk_uint_small_bits / 2);
		mk_uint_small_shl(&m, &m, mk_uint_small_bits / 2);
		mk_uint_small_and(&smol, &a->m_data[mk_uint_parts - 1 - i], &mask);
		mk_uint_small_or(&smol, &smol, &m);
		mk_uint_small_divmod(&smol, &m, &smol, b);
		mk_uint_small_or(&d.m_data[mk_uint_parts - 1 - i], &digit, &smol);
	}

	*div = d;
	*mod = m;
}

mk_jumbo void mk_uint_divmod(mk_uint_t* div, mk_uint_t* mod, mk_uint_t const* a, mk_uint_t const* b)
{
	int slow;
	int i;
	mk_uint_small_t smol;

	mk_assert(div);
	mk_assert(mod);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_is_zero(b));

	slow = 0;
	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		slow |= !mk_uint_small_is_zero(&b->m_data[1 + i]);
	}
	if(slow == 0)
	{
		mk_uint_small_zero(&smol);
		mk_uint_small_inc(&smol);
		mk_uint_small_shl(&smol, &smol, mk_uint_small_bits / 2);
		mk_uint_small_dec(&smol);
		if(!mk_uint_small_lt(&b->m_data[0], &smol))
		{
			++slow;
		}
	}
	if(slow == 0)
	{
		for(i = 0; i != mk_uint_parts - 1; ++i)
		{
			mk_uint_small_zero(&mod->m_data[1 + i]);
		}
		mk_uint_concat_(divmod_fast)(div, &mod->m_data[0], a, &b->m_data[0]);
	}
	else
	{
		mk_uint_concat_(divmod_classic)(div, mod, a, b);
	}
}

mk_jumbo void mk_uint_divmodsm(mk_uint_t* div, mk_uint_small_t* mod, mk_uint_t const* a, mk_uint_small_t const* b)
{
	mk_uint_small_t maxx;

	mk_assert(div);
	mk_assert(mod);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_small_is_zero(b));

	mk_uint_small_zero(&maxx);
	mk_uint_small_inc(&maxx);
	mk_uint_small_shl(&maxx, &maxx, mk_uint_small_bits / 2);
	mk_uint_small_dec(&maxx);
	mk_assert(mk_uint_small_lt(b, &maxx));

	mk_uint_concat_(divmod_fast)(div, mod, a, b);
}


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif


#include "../../../mk_utils/src/mk_assert.h"
#include "../../../mk_utils/src/mk_jumbo.h"

#if defined(_MSC_VER) && _MSC_VER >= 1400
#include <intrin.h>
#endif


mk_jumbo int mk_uint_log2(mk_uint_t const* x)
{
	#if defined(_MSC_VER) && _MSC_VER >= 1400 && (defined(_M_IA64) || defined(_M_AMD64) || defined(_M_ARM64) || defined(_M_X64)) && mk_uint_small_bits <= 64 && mk_uint_parts == 1
	unsigned __int64 mask;
	unsigned char bsr;
	unsigned long int index;
	int ret;

	mk_assert(x);

	mask = (unsigned __int64)(x->m_data);
	bsr = _BitScanReverse64(&index, mask);
	if(bsr == 0)
	{
		ret = -1;
	}
	else
	{
		mk_assert(index <= (mk_uint_small_bits - 1));
		ret = (int)index;
	}
	return ret;
	#elif defined(_MSC_VER) && _MSC_VER >= 1400 && (defined(_M_IA64) || defined(_M_AMD64) || defined(_M_ARM64) || defined(_M_X64)) && mk_uint_small_bits <= 64 && mk_uint_parts != 1
	int ret;
	int i;
	unsigned __int64 mask;
	unsigned char bsr;
	unsigned long int index;

	mk_assert(x);

	ret = -1;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mask = (unsigned __int64)(x->m_data[mk_uint_parts - 1 - i]);
		bsr = _BitScanReverse64(&index, mask);
		if(bsr != 0)
		{
			mk_assert(index <= (mk_uint_small_bits - 1));
			ret = ((int)(index)) + (mk_uint_parts - 1 - i) * mk_uint_small_bits;
			break;
		}
	}
	return ret;
	#elif defined(_MSC_VER) && _MSC_VER >= 1400 && mk_uint_small_bits <= 32 && mk_uint_parts == 1
	unsigned long int mask;
	unsigned char bsr;
	unsigned long int index;
	int ret;

	mk_assert(x);

	mask = (unsigned long int)(x->m_data);
	bsr = _BitScanReverse(&index, mask);
	if(bsr == 0)
	{
		ret = -1;
	}
	else
	{
		mk_assert(index <= (mk_uint_small_bits - 1));
		ret = (int)index;
	}
	return ret;
	#elif defined(_MSC_VER) && _MSC_VER >= 1400 && mk_uint_small_bits <= 32 && mk_uint_parts != 1
	int ret;
	int i;
	unsigned long int mask;
	unsigned char bsr;
	unsigned long int index;

	mk_assert(x);

	ret = -1;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mask = (unsigned long int)(x->m_data[mk_uint_parts - 1 - i]);
		bsr = _BitScanReverse(&index, mask);
		if(bsr != 0)
		{
			mk_assert(index <= (mk_uint_small_bits - 1));
			ret = ((int)(index)) + (mk_uint_parts - 1 - i) * mk_uint_small_bits;
			break;
		}
	}
	return ret;
	#else
	mk_uint_t n;
	int ret;
	int bits;
	mk_uint_t max;

	mk_assert(x);

	n = *x;
	ret = -mk_uint_is_zero(&n);
	bits = mk_uint_bits / 2;
	while(bits != 0)
	{
		mk_uint_zero(&max);
		mk_uint_inc(&max);
		mk_uint_shl(&max, &max, bits);
		if(mk_uint_ge(&n, &max))
		{
			ret += bits;
			mk_uint_shr(&n, &n, bits);
		}
		bits /= 2;
	}

	return ret;
	#endif
}


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
