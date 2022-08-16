#include "../../../mk_utils/src/mk_assert.h"
#include "../../../mk_utils/src/mk_jumbo.h"

#include <stddef.h> /* size_t */


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
#pragma warning(disable:4701) /* warning C4701: potentially uninitialized local variable 'xxx' used */
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


mk_jumbo void mk_uint_zero(mk_uint_t* out)
{
	int i;

	mk_assert(out);

	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_zero(out->m_data + i);
	}
}

mk_jumbo void mk_uint_one(mk_uint_t* out)
{
	int i;

	mk_assert(out);

	mk_uint_small_one(out->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		mk_uint_small_zero(out->m_data + i);
	}
}

mk_jumbo void mk_uint_from_int(mk_uint_t* out, unsigned in)
{
	int parts;
	int i;

	mk_assert(out);

	parts = sizeof(in) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		mk_uint_small_from_int(out->m_data + i, in >> (i * mk_uint_small_bits));
	}
	for(i = parts; i != mk_uint_parts; ++i)
	{
		mk_uint_small_zero(out->m_data + i);
	}
}

mk_jumbo unsigned mk_uint_to_int(mk_uint_t const* x)
{
	unsigned r;
	int parts;
	int i;

	mk_assert(x);

	r = 0;
	parts = sizeof(unsigned) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		r |= mk_uint_small_to_int(x->m_data + i) << (i * mk_uint_small_bits);
	}

	return r;
}

mk_jumbo void mk_uint_from_long(mk_uint_t* out, unsigned long in)
{
	int parts;
	int i;

	mk_assert(out);

	parts = sizeof(in) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		mk_uint_small_from_long(out->m_data + i, in >> (i * mk_uint_small_bits));
	}
	for(i = parts; i != mk_uint_parts; ++i)
	{
		mk_uint_small_zero(out->m_data + i);
	}
}

mk_jumbo unsigned long mk_uint_to_long(mk_uint_t const* x)
{
	unsigned r;
	int parts;
	int i;

	mk_assert(x);

	r = 0;
	parts = sizeof(unsigned long) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		r |= mk_uint_small_to_long(x->m_data + i) << (i * mk_uint_small_bits);
	}

	return r;
}

mk_jumbo void mk_uint_from_sizet(mk_uint_t* out, size_t in)
{
	int parts;
	int i;

	mk_assert(out);

	parts = sizeof(in) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		mk_uint_small_from_sizet(out->m_data + i, in >> (i * mk_uint_small_bits));
	}
	for(i = parts; i != mk_uint_parts; ++i)
	{
		mk_uint_small_zero(out->m_data + i);
	}
}

mk_jumbo size_t mk_uint_to_sizet(mk_uint_t const* x)
{
	size_t r;
	int parts;
	int i;

	mk_assert(x);

	r = 0;
	parts = sizeof(size_t) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		r |= mk_uint_small_to_sizet(x->m_data + i) << (i * mk_uint_small_bits);
	}

	return r;
}

mk_jumbo void mk_uint_from_buff_le(mk_uint_t* out, void const* buff)
{
	int i;
	unsigned char const* input;

	mk_assert(out);
	mk_assert(buff);

	input = (unsigned char const*)buff;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_from_buff_le(out->m_data + i, input + i * sizeof(mk_uint_small_t));
	}
}

mk_jumbo void mk_uint_to_buff_le(mk_uint_t const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);

	output = (unsigned char*)buff;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_to_buff_le(x->m_data + i, output + i * sizeof(mk_uint_small_t));
	}
}

mk_jumbo void mk_uint_from_buff_be(mk_uint_t* out, void const* buff)
{
	int i;
	unsigned char const* input;

	mk_assert(out);
	mk_assert(buff);

	input = (unsigned char const*)buff;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_from_buff_be(out->m_data + mk_uint_parts - 1 - i, input + i * sizeof(mk_uint_small_t));
	}
}

mk_jumbo void mk_uint_to_buff_be(mk_uint_t const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);

	output = (unsigned char*)buff;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_to_buff_be(x->m_data + mk_uint_parts - 1 - i, output + i * sizeof(mk_uint_small_t));
	}
}


mk_jumbo int mk_uint_is_zero(mk_uint_t const* x)
{
	int i;
	int r;

	mk_assert(x);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		r = mk_uint_small_is_zero(x->m_data + i);
		if(!r)
		{
			return r;
		}
	}
	r = mk_uint_small_is_zero(x->m_data + mk_uint_parts - 1);
	return r;
}

mk_jumbo int mk_uint_is_max(mk_uint_t const* x)
{
	int i;
	int r;

	mk_assert(x);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		r = mk_uint_small_is_max(x->m_data + i);
		if(!r)
		{
			return r;
		}
	}
	r = mk_uint_small_is_max(x->m_data + mk_uint_parts - 1);
	return r;
}


mk_jumbo void mk_uint_cmplmnt(mk_uint_t* out, mk_uint_t const* x)
{
	int i;

	mk_assert(out);
	mk_assert(x);

	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_cmplmnt(out->m_data + i, x->m_data + i);
	}
}

mk_jumbo void mk_uint_or(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_or(r.m_data + i, a->m_data + i, b->m_data + i);
	}

	*out = r;
}

mk_jumbo void mk_uint_and(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;
	
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_and(r.m_data + i, a->m_data + i, b->m_data + i);
	}

	*out = r;
}

mk_jumbo void mk_uint_xor(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_xor(r.m_data + i, a->m_data + i, b->m_data + i);
	}

	*out = r;
}


mk_jumbo void mk_uint_shl(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;
	int parts;
	int bits;
	int rem;
	int i;
	mk_uint_small_t tmp;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < mk_uint_bits);

	parts = n / mk_uint_small_bits;
	bits = n % mk_uint_small_bits;
	for(i = 0; i != parts; ++i)
	{
		mk_uint_small_zero(r.m_data + i);
	}
	if(bits == 0)
	{
		for(i = parts; i != mk_uint_parts; ++i)
		{
			r.m_data[i] = x->m_data[i - parts];
		}
		*out = r;
		return;
	}
	rem = mk_uint_small_bits - bits;
	mk_uint_small_shl(r.m_data + parts, x->m_data + 0, bits);
	for(i = parts + 1; i != mk_uint_parts; ++i)
	{
		mk_uint_small_shl(r.m_data + i, x->m_data + i - parts, bits);
		mk_uint_small_shr(&tmp, x->m_data + i - parts - 1, rem);
		mk_uint_small_or(r.m_data + i, r.m_data + i, &tmp);
	}

	*out = r;
}

mk_jumbo void mk_uint_shr(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;
	int parts;
	int bits;
	int rem;
	int i;
	mk_uint_small_t tmp;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < mk_uint_bits);

	parts = n / mk_uint_small_bits;
	bits = n % mk_uint_small_bits;
	for(i = 0; i != parts; ++i)
	{
		mk_uint_small_zero(r.m_data + mk_uint_parts - 1 - i);
	}
	if(bits == 0)
	{
		for(i = parts; i != mk_uint_parts; ++i)
		{
			r.m_data[mk_uint_parts - 1 - i] = x->m_data[mk_uint_parts - 1 - i + parts];
		}
		*out = r;
		return;
	}
	rem = mk_uint_small_bits - bits;
	mk_uint_small_shr(r.m_data + mk_uint_parts - 1 - parts, x->m_data + mk_uint_parts - 1, bits);
	for(i = parts + 1; i != mk_uint_parts; ++i)
	{
		mk_uint_small_shr(r.m_data + mk_uint_parts - 1 - i, x->m_data + mk_uint_parts - 1 - i + parts, bits);
		mk_uint_small_shl(&tmp, x->m_data + mk_uint_parts - 1 - i + parts + 1, rem);
		mk_uint_small_or(r.m_data + mk_uint_parts - 1 - i, r.m_data + mk_uint_parts - 1 - i, &tmp);
	}

	*out = r;
}

mk_jumbo void mk_uint_rotl(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;
	mk_uint_t tmp;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n > 0 && n < mk_uint_bits);

	mk_uint_shl(&r, x, n);
	mk_uint_shr(&tmp, x, mk_uint_bits - n);
	mk_uint_or(&r, &r, &tmp);

	*out = r;
}

mk_jumbo void mk_uint_rotr(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;
	mk_uint_t tmp;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n > 0 && n < mk_uint_bits);

	mk_uint_shr(&r, x, n);
	mk_uint_shl(&tmp, x, mk_uint_bits - n);
	mk_uint_or(&r, &r, &tmp);

	*out = r;
}


mk_jumbo int mk_uint_eq(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		r = mk_uint_small_eq(a->m_data + i, b->m_data + i);
		if(!r)
		{
			return r;
		}
	}
	r = mk_uint_small_eq(a->m_data + mk_uint_parts - 1, b->m_data + mk_uint_parts - 1);
	return r;
}

mk_jumbo int mk_uint_neq(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		r = mk_uint_small_neq(a->m_data + i, b->m_data + i);
		if(r)
		{
			return r;
		}
	}
	r = mk_uint_small_neq(a->m_data + mk_uint_parts - 1, b->m_data + mk_uint_parts - 1);
	return r;
}

mk_jumbo int mk_uint_lt(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;
	int lt;
	int gt;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		lt = mk_uint_small_lt(a->m_data + mk_uint_parts - 1 - i, b->m_data + mk_uint_parts - 1 - i);
		if(lt)
		{
			return lt;
		}
		gt = mk_uint_small_lt(b->m_data + mk_uint_parts - 1 - i, a->m_data + mk_uint_parts - 1 - i);
		if(gt)
		{
			return !gt;
		}
	}
	r = mk_uint_small_lt(a->m_data + 0, b->m_data + 0);

	return r;
}

mk_jumbo int mk_uint_le(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;
	int lt;
	int gt;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		lt = mk_uint_small_lt(a->m_data + mk_uint_parts - 1 - i, b->m_data + mk_uint_parts - 1 - i);
		if(lt)
		{
			return lt;
		}
		gt = mk_uint_small_lt(b->m_data + mk_uint_parts - 1 - i, a->m_data + mk_uint_parts - 1 - i);
		if(gt)
		{
			return !gt;
		}
	}
	r = mk_uint_small_le(a->m_data + 0, b->m_data + 0);

	return r;
}

mk_jumbo int mk_uint_gt(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;
	int lt;
	int gt;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		lt = mk_uint_small_gt(a->m_data + mk_uint_parts - 1 - i, b->m_data + mk_uint_parts - 1 - i);
		if(lt)
		{
			return lt;
		}
		gt = mk_uint_small_gt(b->m_data + mk_uint_parts - 1 - i, a->m_data + mk_uint_parts - 1 - i);
		if(gt)
		{
			return !gt;
		}
	}
	r = mk_uint_small_gt(a->m_data + 0, b->m_data + 0);

	return r;
}

mk_jumbo int mk_uint_ge(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;
	int lt;
	int gt;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		lt = mk_uint_small_gt(a->m_data + mk_uint_parts - 1 - i, b->m_data + mk_uint_parts - 1 - i);
		if(lt)
		{
			return lt;
		}
		gt = mk_uint_small_gt(b->m_data + mk_uint_parts - 1 - i, a->m_data + mk_uint_parts - 1 - i);
		if(gt)
		{
			return !gt;
		}
	}
	r = mk_uint_small_ge(a->m_data + 0, b->m_data + 0);

	return r;
}


mk_jumbo void mk_uint_inc(mk_uint_t* x)
{
	int i;
	int o;

	mk_assert(x);

	mk_uint_small_inc(x->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		o = mk_uint_small_is_zero(x->m_data + i - 1);
		if(o)
		{
			mk_uint_small_inc(x->m_data + i);
		}
		else
		{
			break;
		}
	}
}

mk_jumbo void mk_uint_dec(mk_uint_t* x)
{
	int i;
	int u;

	mk_assert(x);

	mk_uint_small_dec(x->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		u = mk_uint_small_is_max(x->m_data + i - 1);
		if(u)
		{
			mk_uint_small_dec(x->m_data + i);
		}
		else
		{
			break;
		}
	}
}


mk_jumbo void mk_uint_add(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;
	int overflow;
	mk_uint_small_t one;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	overflow = 0;
	mk_uint_small_add(r.m_data + 0, a->m_data + 0, b->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		overflow =
			overflow == 0 ?
			(
				mk_uint_small_lt(r.m_data + i - 1, a->m_data + i - 1) ||
				mk_uint_small_lt(r.m_data + i - 1, b->m_data + i - 1)
			) :
			(
				mk_uint_small_le(r.m_data + i - 1, a->m_data + i - 1) ||
				mk_uint_small_le(r.m_data + i - 1, b->m_data + i - 1)
			);
		mk_uint_small_add(r.m_data + i, a->m_data + i, b->m_data + i);
		if(overflow)
		{
			mk_uint_small_one(&one);
			mk_uint_small_add(r.m_data + i, r.m_data + i, &one);
		}
	}

	*out = r;
}

mk_jumbo void mk_uint_sub(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;
	int overflow;
	mk_uint_small_t one;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	overflow = 0;
	mk_uint_small_sub(r.m_data + 0, a->m_data + 0, b->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		overflow =
			overflow == 0 ?
			mk_uint_small_lt(a->m_data + i - 1, b->m_data + i - 1) :
			mk_uint_small_le(a->m_data + i - 1, b->m_data + i - 1);
		mk_uint_small_sub(r.m_data + i, a->m_data + i, b->m_data + i);
		if(overflow)
		{
			mk_uint_small_one(&one);
			mk_uint_small_sub(r.m_data + i, r.m_data + i, &one);
		}
	}

	*out = r;
}

mk_jumbo void mk_uint_mul(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;
	int j;
	int k;
	mk_uint_t tmp;

	mk_uint_zero(&r);
	for(i = 0; i != mk_uint_parts; ++i)
	{
		for(j = 0; j != mk_uint_parts - i - 1; ++j)
		{
			for(k = 0; k != j + i; ++k)
			{
				mk_uint_small_zero(&tmp.m_data[k]);
			}
			mk_uint_small_mul(&tmp.m_data[i + j + 0], &a->m_data[i], &b->m_data[j]);
			mk_uint_small_mulhi(&tmp.m_data[i + j + 1], &a->m_data[i], &b->m_data[j]);
			for(k = j + i + 2; k != mk_uint_parts; ++k)
			{
				mk_uint_small_zero(&tmp.m_data[k]);
			}
			mk_uint_add(&r, &r, &tmp);
		}
		for(k = 0; k != j + i; ++k)
		{
			mk_uint_small_zero(&tmp.m_data[k]);
		}
		mk_uint_small_mul(&tmp.m_data[i + j + 0], &a->m_data[i], &b->m_data[j]);
		mk_uint_add(&r, &r, &tmp);
	}
	*out = r;
}

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

mk_jumbo void mk_uint_div(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t mod;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_is_zero(b));

	mk_uint_divmod(out, &mod, a, b);
}

mk_jumbo void mk_uint_mod(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t div;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_is_zero(b));

	mk_uint_divmod(&div, out, a, b);
}


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
