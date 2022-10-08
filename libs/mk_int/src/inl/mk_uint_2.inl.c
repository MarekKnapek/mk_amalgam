#include "../../../mk_utils/src/mk_assert.h"
#include "../../../mk_utils/src/mk_jumbo.h"

#include <stddef.h> /* size_t */


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#pragma warning(disable:5045) /* warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified */
#endif


mk_jumbo void mk_uint_zero(mk_uint_t* out)
{
	mk_assert(out);

	mk_uint_small_zero(&out->m_data[0]);
	mk_uint_small_zero(&out->m_data[1]);
}

mk_jumbo void mk_uint_one(mk_uint_t* out)
{
	mk_assert(out);

	mk_uint_small_one(&out->m_data[0]);
	mk_uint_small_zero(&out->m_data[1]);
}

mk_jumbo void mk_uint_from_int(mk_uint_t* out, unsigned int in)
{
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#pragma warning(disable:4293) /* warning C4293: '>>' '<<': shift count negative or too big, undefined behavior */
	#endif
	#if defined(__GNUC__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left/right shift count >= width of type [-Wshift-count-overflow] */
	#endif
	if(mk_uint_small_bits < sizeof(unsigned int) * CHAR_BIT)
	{
		mk_uint_small_from_int(&out->m_data[0], in);
		mk_uint_small_from_int(&out->m_data[1], in >> mk_uint_small_bits);
	}
	else
	{
		mk_uint_small_from_int(&out->m_data[0], in);
		mk_uint_small_zero(&out->m_data[1]);
	}
	#if defined(__GNUC__)
	#pragma GCC diagnostic pop
	#endif
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
}

mk_jumbo unsigned int mk_uint_to_int(mk_uint_t const* x)
{
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#pragma warning(disable:4293) /* warning C4293: '>>' '<<': shift count negative or too big, undefined behavior */
	#endif
	#if defined(__GNUC__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left/right shift count >= width of type [-Wshift-count-overflow] */
	#endif
	if(mk_uint_small_bits < sizeof(unsigned int) * CHAR_BIT)
	{
		return mk_uint_small_to_int(&x->m_data[0]) | mk_uint_small_to_int(&x->m_data[1]) << mk_uint_small_bits;
	}
	else
	{
		return mk_uint_small_to_int(&x->m_data[0]);
	}
	#if defined(__GNUC__)
	#pragma GCC diagnostic pop
	#endif
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
}

mk_jumbo void mk_uint_from_long(mk_uint_t* out, unsigned long int in)
{
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#pragma warning(disable:4293) /* warning C4293: '>>' '<<': shift count negative or too big, undefined behavior */
	#endif
	#if defined(__GNUC__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left/right shift count >= width of type [-Wshift-count-overflow] */
	#endif
	if(mk_uint_small_bits < sizeof(unsigned long int) * CHAR_BIT)
	{
		mk_uint_small_from_long(&out->m_data[0], in);
		mk_uint_small_from_long(&out->m_data[1], in >> mk_uint_small_bits);
	}
	else
	{
		mk_uint_small_from_long(&out->m_data[0], in);
		mk_uint_small_zero(&out->m_data[1]);
	}
	#if defined(__GNUC__)
	#pragma GCC diagnostic pop
	#endif
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
}

mk_jumbo unsigned long int mk_uint_to_long(mk_uint_t const* x)
{
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#pragma warning(disable:4293) /* warning C4293: '>>' '<<': shift count negative or too big, undefined behavior */
	#endif
	#if defined(__GNUC__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left/right shift count >= width of type [-Wshift-count-overflow] */
	#endif
	if(mk_uint_small_bits < sizeof(unsigned long int) * CHAR_BIT)
	{
		return mk_uint_small_to_long(&x->m_data[0]) | mk_uint_small_to_long(&x->m_data[1]) << mk_uint_small_bits;
	}
	else
	{
		return mk_uint_small_to_long(&x->m_data[0]);
	}
	#if defined(__GNUC__)
	#pragma GCC diagnostic pop
	#endif
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
}

mk_jumbo void mk_uint_from_sizet(mk_uint_t* out, size_t in)
{
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#pragma warning(disable:4293) /* warning C4293: '>>' '<<': shift count negative or too big, undefined behavior */
	#endif
	#if defined(__GNUC__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left/right shift count >= width of type [-Wshift-count-overflow] */
	#endif
	if(mk_uint_small_bits < sizeof(size_t) * CHAR_BIT)
	{
		mk_uint_small_from_sizet(&out->m_data[0], in);
		mk_uint_small_from_sizet(&out->m_data[1], (in >> mk_uint_small_bits));
	}
	else
	{
		mk_uint_small_from_sizet(&out->m_data[0], in);
		mk_uint_small_zero(&out->m_data[1]);
	}
	#if defined(__GNUC__)
	#pragma GCC diagnostic pop
	#endif
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
}

mk_jumbo size_t mk_uint_to_sizet(mk_uint_t const* x)
{
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#pragma warning(disable:4293) /* warning C4293: '>>' '<<': shift count negative or too big, undefined behavior */
	#endif
	#if defined(__GNUC__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left/right shift count >= width of type [-Wshift-count-overflow] */
	#endif
	if(mk_uint_small_bits < sizeof(size_t) * CHAR_BIT)
	{
		return mk_uint_small_to_sizet(&x->m_data[0]) | mk_uint_small_to_sizet(&x->m_data[1]) << mk_uint_small_bits;
	}
	else
	{
		return mk_uint_small_to_sizet(&x->m_data[0]);
	}
	#if defined(__GNUC__)
	#pragma GCC diagnostic pop
	#endif
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
}

mk_jumbo void mk_uint_from_buff_le(mk_uint_t* out, void const* buff)
{
	mk_uint_small_from_buff_le(&out->m_data[0], ((unsigned char const*)buff) + 0 * sizeof(mk_uint_small_t));
	mk_uint_small_from_buff_le(&out->m_data[1], ((unsigned char const*)buff) + 1 * sizeof(mk_uint_small_t));
}

mk_jumbo void mk_uint_to_buff_le(mk_uint_t const* x, void* buff)
{
	mk_uint_small_to_buff_le(&x->m_data[0], ((unsigned char*)buff) + 0 * sizeof(mk_uint_small_t));
	mk_uint_small_to_buff_le(&x->m_data[1], ((unsigned char*)buff) + 1 * sizeof(mk_uint_small_t));
}

mk_jumbo void mk_uint_from_buff_be(mk_uint_t* out, void const* buff)
{
	mk_uint_small_from_buff_be(&out->m_data[1], ((unsigned char const*)buff) + 0 * sizeof(mk_uint_small_t));
	mk_uint_small_from_buff_be(&out->m_data[0], ((unsigned char const*)buff) + 1 * sizeof(mk_uint_small_t));
}

mk_jumbo void mk_uint_to_buff_be(mk_uint_t const* x, void* buff)
{
	mk_uint_small_to_buff_be(&x->m_data[1], ((unsigned char*)buff) + 0 * sizeof(mk_uint_small_t));
	mk_uint_small_to_buff_be(&x->m_data[0], ((unsigned char*)buff) + 1 * sizeof(mk_uint_small_t));
}


mk_jumbo int mk_uint_is_zero(mk_uint_t const* x)
{
	return mk_uint_small_is_zero(&x->m_data[0]) && mk_uint_small_is_zero(&x->m_data[1]);
}

mk_jumbo int mk_uint_is_max(mk_uint_t const* x)
{
	return mk_uint_small_is_max(&x->m_data[0]) && mk_uint_small_is_max(&x->m_data[1]);
}


mk_jumbo void mk_uint_cmplmnt(mk_uint_t* out, mk_uint_t const* x)
{
	mk_uint_small_cmplmnt(&out->m_data[0], &x->m_data[0]);
	mk_uint_small_cmplmnt(&out->m_data[1], &x->m_data[1]);
}

mk_jumbo void mk_uint_or(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_small_or(&out->m_data[0], &a->m_data[0], &b->m_data[0]);
	mk_uint_small_or(&out->m_data[1], &a->m_data[1], &b->m_data[1]);
}

mk_jumbo void mk_uint_and(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_small_and(&out->m_data[0], &a->m_data[0], &b->m_data[0]);
	mk_uint_small_and(&out->m_data[1], &a->m_data[1], &b->m_data[1]);
}

mk_jumbo void mk_uint_xor(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_small_xor(&out->m_data[0], &a->m_data[0], &b->m_data[0]);
	mk_uint_small_xor(&out->m_data[1], &a->m_data[1], &b->m_data[1]);
}


mk_jumbo void mk_uint_shl(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_small_t tmp;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < mk_uint_bits);

	if(n == 0)
	{
		*out = *x;
	}
	else if(n < mk_uint_small_bits)
	{
		mk_uint_small_shr(&tmp, &x->m_data[0], mk_uint_small_bits - n);
		mk_uint_small_shl(&out->m_data[0], &x->m_data[0], n);
		mk_uint_small_shl(&out->m_data[1], &x->m_data[1], n);
		mk_uint_small_or(&out->m_data[1], &out->m_data[1], &tmp);
	}
	else if(n == mk_uint_small_bits)
	{
		out->m_data[1] = x->m_data[0];
		mk_uint_small_zero(&out->m_data[0]);
	}
	else
	{
		mk_uint_small_shl(&out->m_data[1], &x->m_data[0], n - mk_uint_small_bits);
		mk_uint_small_zero(&out->m_data[0]);
	}
}

mk_jumbo void mk_uint_shr(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_small_t tmp;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < mk_uint_bits);

	if(n == 0)
	{
		*out = *x;
	}
	else if(n < mk_uint_small_bits)
	{
		mk_uint_small_shl(&tmp, &x->m_data[1], mk_uint_small_bits - n);
		mk_uint_small_shr(&out->m_data[0], &x->m_data[0], n);
		mk_uint_small_shr(&out->m_data[1], &x->m_data[1], n);
		mk_uint_small_or(&out->m_data[0], &out->m_data[0], &tmp);
	}
	else if(n == mk_uint_small_bits)
	{
		out->m_data[0] = x->m_data[1];
		mk_uint_small_zero(&out->m_data[1]);
	}
	else
	{
		mk_uint_small_shr(&out->m_data[0], &x->m_data[1], n - mk_uint_small_bits);
		mk_uint_small_zero(&out->m_data[1]);
	}
}

mk_jumbo void mk_uint_rotl(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t tmp1;
	mk_uint_t tmp2;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n > 0 && n < mk_uint_bits);

	mk_uint_shl(&tmp1, x, n);
	mk_uint_shr(&tmp2, x, mk_uint_bits - n);
	mk_uint_or(out, &tmp1, &tmp2);
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
	mk_assert(a);
	mk_assert(b);

	return mk_uint_small_eq(&a->m_data[0], &b->m_data[0]) && mk_uint_small_eq(&a->m_data[1], &b->m_data[1]);
}

mk_jumbo int mk_uint_neq(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return mk_uint_small_neq(&a->m_data[0], &b->m_data[0]) || mk_uint_small_neq(&a->m_data[1], &b->m_data[1]);
}

mk_jumbo int mk_uint_lt(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	if(mk_uint_small_lt(&a->m_data[1], &b->m_data[1]))
	{
		return 1;
	}
	else if(mk_uint_small_lt(&b->m_data[1], &a->m_data[1]))
	{
		return 0;
	}
	else
	{
		return mk_uint_small_lt(&a->m_data[0], &b->m_data[0]);
	}
}

mk_jumbo int mk_uint_le(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	if(mk_uint_small_lt(&a->m_data[1], &b->m_data[1]))
	{
		return 1;
	}
	else if(mk_uint_small_lt(&b->m_data[1], &a->m_data[1]))
	{
		return 0;
	}
	else
	{
		return mk_uint_small_le(&a->m_data[0], &b->m_data[0]);
	}
}

mk_jumbo int mk_uint_gt(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	if(mk_uint_small_gt(&a->m_data[1], &b->m_data[1]))
	{
		return 1;
	}
	else if(mk_uint_small_gt(&b->m_data[1], &a->m_data[1]))
	{
		return 0;
	}
	else
	{
		return mk_uint_small_gt(&a->m_data[0], &b->m_data[0]);
	}
}

mk_jumbo int mk_uint_ge(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	if(mk_uint_small_gt(&a->m_data[1], &b->m_data[1]))
	{
		return 1;
	}
	else if(mk_uint_small_gt(&b->m_data[1], &a->m_data[1]))
	{
		return 0;
	}
	else
	{
		return mk_uint_small_ge(&a->m_data[0], &b->m_data[0]);
	}
}


mk_jumbo void mk_uint_inc(mk_uint_t* x)
{
	mk_assert(x);

	mk_uint_small_inc(&x->m_data[0]);
	if(mk_uint_small_is_zero(&x->m_data[0]))
	{
		mk_uint_small_inc(&x->m_data[1]);
	}
}

mk_jumbo void mk_uint_dec(mk_uint_t* x)
{
	mk_assert(x);

	mk_uint_small_dec(&x->m_data[0]);
	if(mk_uint_small_is_max(&x->m_data[0]))
	{
		mk_uint_small_dec(&x->m_data[1]);
	}
}


mk_jumbo void mk_uint_add(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_small_t tmp;
	int overflow;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	
	mk_uint_small_add(&tmp, &a->m_data[0], &b->m_data[0]);
	overflow = mk_uint_small_lt(&tmp, &a->m_data[0]) || mk_uint_small_lt(&tmp, &b->m_data[0]);
	out->m_data[0] = tmp;
	mk_uint_small_add(&out->m_data[1], &a->m_data[1], &b->m_data[1]);
	if(overflow)
	{
		mk_uint_small_inc(&out->m_data[1]);
	}
}

mk_jumbo void mk_uint_sub(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	int overflow;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	
	overflow = mk_uint_small_lt(&a->m_data[0], &b->m_data[0]);
	mk_uint_small_sub(&out->m_data[0], &a->m_data[0], &b->m_data[0]);
	mk_uint_small_sub(&out->m_data[1], &a->m_data[1], &b->m_data[1]);
	if(overflow)
	{
		mk_uint_small_dec(&out->m_data[1]);
	}
}

mk_jumbo void mk_uint_mul(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_small_t abmilo;
	mk_uint_small_t bamilo;
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	mk_uint_small_mul(&r.m_data[0], &a->m_data[0], &b->m_data[0]);
	mk_uint_small_mulhi(&r.m_data[1], &a->m_data[0], &b->m_data[0]);
	mk_uint_small_mul(&abmilo, &a->m_data[0], &b->m_data[1]);
	mk_uint_small_mul(&bamilo, &a->m_data[1], &b->m_data[0]);

	mk_uint_small_add(&r.m_data[1], &r.m_data[1], &bamilo);
	mk_uint_small_add(&r.m_data[1], &r.m_data[1], &abmilo);
	*out = r;
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
