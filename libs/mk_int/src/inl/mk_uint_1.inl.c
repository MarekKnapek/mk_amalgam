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
	mk_assert(out);

	mk_uint_small_zero(&out->m_data);
}

mk_jumbo void mk_uint_one(mk_uint_t* out)
{
	mk_assert(out);

	mk_uint_small_one(&out->m_data);
}

mk_jumbo void mk_uint_from_int(mk_uint_t* out, unsigned in)
{
	mk_assert(out);

	mk_uint_small_from_int(&out->m_data, in);
}

mk_jumbo unsigned mk_uint_to_int(mk_uint_t const* x)
{
	mk_assert(x);

	return mk_uint_small_to_int(&x->m_data);
}

mk_jumbo void mk_uint_from_long(mk_uint_t* out, unsigned long in)
{
	mk_assert(out);

	mk_uint_small_from_long(&out->m_data, in);
}

mk_jumbo unsigned long mk_uint_to_long(mk_uint_t const* x)
{
	mk_assert(x);

	return mk_uint_small_to_long(&x->m_data);
}

mk_jumbo void mk_uint_from_sizet(mk_uint_t* out, size_t in)
{
	mk_assert(out);

	mk_uint_small_from_sizet(&out->m_data, in);
}

mk_jumbo size_t mk_uint_to_sizet(mk_uint_t const* x)
{
	mk_assert(x);

	return mk_uint_small_to_sizet(&x->m_data);
}

mk_jumbo void mk_uint_from_buff_le(mk_uint_t* out, void const* buff)
{
	mk_assert(out);
	mk_assert(buff);

	mk_uint_small_from_buff_le(&out->m_data, buff);
}

mk_jumbo void mk_uint_to_buff_le(mk_uint_t const* x, void* buff)
{
	mk_assert(x);
	mk_assert(buff);

	mk_uint_small_to_buff_le(&x->m_data, buff);
}

mk_jumbo void mk_uint_from_buff_be(mk_uint_t* out, void const* buff)
{
	mk_assert(out);
	mk_assert(buff);

	mk_uint_small_from_buff_be(&out->m_data, buff);
}

mk_jumbo void mk_uint_to_buff_be(mk_uint_t const* x, void* buff)
{
	mk_assert(x);
	mk_assert(buff);

	mk_uint_small_to_buff_be(&x->m_data, buff);
}


mk_jumbo int mk_uint_is_zero(mk_uint_t const* x)
{
	mk_assert(x);

	return mk_uint_small_is_zero(&x->m_data);
}

mk_jumbo int mk_uint_is_max(mk_uint_t const* x)
{
	mk_assert(x);

	return mk_uint_small_is_max(&x->m_data);
}


mk_jumbo void mk_uint_cmplmnt(mk_uint_t* out, mk_uint_t const* x)
{
	mk_assert(out);
	mk_assert(x);

	mk_uint_small_cmplmnt(&out->m_data, &x->m_data);
}

mk_jumbo void mk_uint_or(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	mk_uint_small_or(&out->m_data, &a->m_data, &b->m_data);
}

mk_jumbo void mk_uint_and(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	mk_uint_small_and(&out->m_data, &a->m_data, &b->m_data);
}

mk_jumbo void mk_uint_xor(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	mk_uint_small_xor(&out->m_data, &a->m_data, &b->m_data);
}


mk_jumbo void mk_uint_shl(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < mk_uint_bits);

	mk_uint_small_shl(&out->m_data, &x->m_data, n);
}

mk_jumbo void mk_uint_shr(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < mk_uint_bits);

	mk_uint_small_shr(&out->m_data, &x->m_data, n);
}

mk_jumbo void mk_uint_rotl(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < mk_uint_bits);

	mk_uint_small_rotl(&out->m_data, &x->m_data, n);
}

mk_jumbo void mk_uint_rotr(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < mk_uint_bits);

	mk_uint_small_rotr(&out->m_data, &x->m_data, n);
}


mk_jumbo int mk_uint_eq(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return mk_uint_small_eq(&a->m_data, &b->m_data);
}

mk_jumbo int mk_uint_neq(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return mk_uint_small_neq(&a->m_data, &b->m_data);
}

mk_jumbo int mk_uint_lt(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return mk_uint_small_lt(&a->m_data, &b->m_data);
}

mk_jumbo int mk_uint_le(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return mk_uint_small_le(&a->m_data, &b->m_data);
}

mk_jumbo int mk_uint_gt(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return mk_uint_small_gt(&a->m_data, &b->m_data);
}

mk_jumbo int mk_uint_ge(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return mk_uint_small_ge(&a->m_data, &b->m_data);
}


mk_jumbo void mk_uint_inc(mk_uint_t* x)
{
	mk_assert(x);

	mk_uint_small_inc(&x->m_data);
}

mk_jumbo void mk_uint_dec(mk_uint_t* x)
{
	mk_assert(x);

	mk_uint_small_dec(&x->m_data);
}


mk_jumbo void mk_uint_add(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	mk_uint_small_add(&out->m_data, &a->m_data, &b->m_data);
}

mk_jumbo void mk_uint_sub(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	mk_uint_small_sub(&out->m_data, &a->m_data, &b->m_data);
}

mk_jumbo void mk_uint_mul(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	mk_uint_small_mul(&out->m_data, &a->m_data, &b->m_data);
}

mk_jumbo void mk_uint_divmod(mk_uint_t* div, mk_uint_t* mod, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(div);
	mk_assert(mod);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_is_zero(b));

	mk_uint_small_divmod(&div->m_data, &mod->m_data, &a->m_data, &b->m_data);
}

mk_jumbo void mk_uint_divmodsm(mk_uint_t* div, mk_uint_small_t* mod, mk_uint_t const* a, mk_uint_small_t const* b)
{
	mk_assert(div);
	mk_assert(mod);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_small_is_zero(b));

	mk_uint_small_divmod(&div->m_data, mod, &a->m_data, b);
}

mk_jumbo void mk_uint_div(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_is_zero(b));

	mk_uint_small_div(&out->m_data, &a->m_data, &b->m_data);
}

mk_jumbo void mk_uint_mod(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	mk_assert(!mk_uint_is_zero(b));

	mk_uint_small_mod(&out->m_data, &a->m_data, &b->m_data);
}


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
