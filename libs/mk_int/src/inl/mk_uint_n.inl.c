#include "../../../mk_utils/src/mk_assert.h"
#include "../../../mk_utils/src/mk_clobber.h"
#include "../../../mk_utils/src/mk_inline.h"
#include "../../../mk_utils/src/mk_jumbo.h"

#include <stddef.h> /* size_t */


#if defined(_MSC_VER)
#pragma warning(push)
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

mk_jumbo void mk_uint_from_int(mk_uint_t* out, unsigned int in)
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

mk_jumbo unsigned int mk_uint_to_int(mk_uint_t const* x)
{
	unsigned int r;
	int parts;
	int i;

	mk_assert(x);

	r = 0;
	parts = sizeof(unsigned int) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		r |= mk_uint_small_to_int(x->m_data + i) << (i * mk_uint_small_bits);
	}

	return r;
}

mk_jumbo void mk_uint_from_long(mk_uint_t* out, unsigned long int in)
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

mk_jumbo unsigned long int mk_uint_to_long(mk_uint_t const* x)
{
	unsigned int r;
	int parts;
	int i;

	mk_assert(x);

	r = 0;
	parts = sizeof(unsigned long int) / sizeof(mk_uint_small_t);
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

	mk_clobber(&r);
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

	mk_clobber(&r);
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
	int overflow;
	int i;
	mk_uint_small_t aa;
	mk_uint_small_t bb;
	mk_uint_small_t cc;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	overflow = 0;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		aa = a->m_data[i];
		bb = b->m_data[i];
		mk_uint_small_add(&cc, &aa, &bb);
		if(overflow == 0)
		{
			overflow = mk_uint_small_lt(&cc, &aa) | mk_uint_small_lt(&cc, &bb);
		}
		else
		{
			mk_uint_small_inc(&cc);
			overflow = mk_uint_small_le(&cc, &aa) | mk_uint_small_le(&cc, &bb);
		}
		out->m_data[i] = cc;
	}
}

mk_jumbo void mk_uint_sub(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	int overflow;
	int i;
	mk_uint_small_t aa;
	mk_uint_small_t bb;
	mk_uint_small_t cc;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	overflow = 0;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		aa = a->m_data[i];
		bb = b->m_data[i];
		mk_uint_small_sub(&cc, &aa, &bb);
		if(overflow == 0)
		{
			overflow = mk_uint_small_lt(&aa, &bb);
		}
		else
		{
			mk_uint_small_dec(&cc);
			overflow = mk_uint_small_le(&aa, &bb);
		}
		out->m_data[i] = cc;
	}
}

static mk_inline void mk_uint_concat_(mul_restrict)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_small_t lo_mask;
	mk_uint_small_t hi_mask;
	int ai;
	mk_uint_small_t carry;
	mk_uint_small_t aa;
	int bi;
	int idx;
	mk_uint_small_t bb;
	mk_uint_small_t cc;
	mk_uint_small_t product;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	mk_assert(out != a);
	mk_assert(out != b);

	mk_uint_small_zero(&lo_mask);
	mk_uint_small_inc(&lo_mask);
	mk_uint_small_shl(&lo_mask, &lo_mask, mk_uint_small_bits / 2);
	mk_uint_small_dec(&lo_mask);
	mk_uint_small_cmplmnt(&hi_mask, &lo_mask);
	mk_uint_zero(out);
	for(ai = 0; ai != mk_uint_parts * 2; ++ai)
	{
		mk_uint_small_zero(&carry);
		if(ai % 2 == 0)
		{
			mk_uint_small_and(&aa, &a->m_data[ai / 2], &lo_mask);
		}
		else
		{
			mk_uint_small_shr(&aa, &a->m_data[ai / 2], mk_uint_small_bits / 2);
		}
		for(bi = 0; bi != mk_uint_parts * 2 - ai; ++bi)
		{
			idx = ai + bi;
			if(bi % 2 == 0)
			{
				mk_uint_small_and(&bb, &b->m_data[bi / 2], &lo_mask);
			}
			else
			{
				mk_uint_small_shr(&bb, &b->m_data[bi / 2], mk_uint_small_bits / 2);
			}
			if(idx % 2 == 0)
			{
				mk_uint_small_and(&cc, &out->m_data[idx / 2], &lo_mask);
			}
			else
			{
				mk_uint_small_shr(&cc, &out->m_data[idx / 2], mk_uint_small_bits / 2);
			}
			mk_uint_small_mul(&product, &aa, &bb);
			mk_uint_small_add(&product, &product, &carry);
			mk_uint_small_add(&product, &product, &cc);
			mk_uint_small_shr(&carry, &product, mk_uint_small_bits / 2);
			if(idx % 2 == 0)
			{
				mk_uint_small_and(&product, &product, &lo_mask);
				mk_uint_small_and(&bb, &out->m_data[idx / 2], &hi_mask);
				mk_uint_small_or(&out->m_data[idx / 2], &bb, &product);
			}
			else
			{
				mk_uint_small_shl(&product, &product, mk_uint_small_bits / 2);
				mk_uint_small_and(&bb, &out->m_data[idx / 2], &lo_mask);
				mk_uint_small_or(&out->m_data[idx / 2], &product, &bb);
			}
		}
	}
}

static mk_inline void mk_uint_concat_(mul_norestrict)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t res;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	mk_assert(out == a || out == b);

	mk_uint_concat_(mul_restrict)(&res, a, b);

	*out = res;
}

mk_jumbo void mk_uint_mul(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	if(out != a && out != b)
	{
		mk_uint_concat_(mul_restrict)(out, a, b);
	}
	else
	{
		mk_uint_concat_(mul_norestrict)(out, a, b);
	}
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
