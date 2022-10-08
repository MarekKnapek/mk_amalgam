#define mk_uint_concat_1(a, b) mk_uint_ ## a ## _ ## b
#define mk_uint_concat(a, b) mk_uint_concat_1(a, b)


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../../../mk_utils/src/mk_assert.h"
#include "../../../mk_utils/src/mk_jumbo.h"

#include <stddef.h> /* size_t */
#include <limits.h> /* CHAR_BIT */


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


mk_jumbo void mk_uint_concat(mk_uint_tn, zero)(mk_uint_t* out)
{
	mk_assert(out);

	*out = 0;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, one)(mk_uint_t* out)
{
	mk_assert(out);

	*out = 1;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, from_int)(mk_uint_t* out, unsigned int in)
{
	mk_assert(out);

	*out = (mk_uint_t)in;
}

mk_jumbo unsigned int mk_uint_concat(mk_uint_tn, to_int)(mk_uint_t const* x)
{
	mk_assert(x);

	return (unsigned int)*x;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, from_long)(mk_uint_t* out, unsigned long int in)
{
	mk_assert(out);

	*out = (mk_uint_t)in;
}

mk_jumbo unsigned long int mk_uint_concat(mk_uint_tn, to_long)(mk_uint_t const* x)
{
	mk_assert(x);

	return (unsigned long int)*x;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, from_sizet)(mk_uint_t* out, size_t in)
{
	mk_assert(out);

	*out = (mk_uint_t)in;
}

mk_jumbo size_t mk_uint_concat(mk_uint_tn, to_sizet)(mk_uint_t const* x)
{
	mk_assert(x);

	return (size_t)*x;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, from_buff_le)(mk_uint_t* out, void const* buff)
{
	mk_uint_t r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(mk_uint_t); ++i)
	{
		r |= ((mk_uint_t)input[i]) << (i * CHAR_BIT);
	}

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, to_buff_le)(mk_uint_t const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(mk_uint_t); ++i)
	{
		output[i] = (unsigned char)((*x >> (i * CHAR_BIT)) & 0xff);
	}
}

mk_jumbo void mk_uint_concat(mk_uint_tn, from_buff_be)(mk_uint_t* out, void const* buff)
{
	mk_uint_t r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(mk_uint_t); ++i)
	{
		r |= ((mk_uint_t)input[i]) << ((sizeof(mk_uint_t) - 1 - i) * CHAR_BIT);
	}

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, to_buff_be)(mk_uint_t const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(mk_uint_t); ++i)
	{
		output[i] = (unsigned char)((*x >> ((sizeof(mk_uint_t) - 1 - i) * CHAR_BIT)) & 0xff);
	}
}


mk_jumbo int mk_uint_concat(mk_uint_tn, is_zero)(mk_uint_t const* x)
{
	mk_assert(x);

	return *x == 0;
}

mk_jumbo int mk_uint_concat(mk_uint_tn, is_max)(mk_uint_t const* x)
{
	mk_assert(x);

	return *x == (mk_uint_t)((mk_uint_t)0 - (mk_uint_t)1);
}


mk_jumbo void mk_uint_concat(mk_uint_tn, cmplmnt)(mk_uint_t* out, mk_uint_t const* x)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(x);

	r = (mk_uint_t)(~*x);

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, or)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a | *b);

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, and)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a & *b);

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, xor)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a ^ *b);

	*out = r;
}


mk_jumbo void mk_uint_concat(mk_uint_tn, shl)(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(mk_uint_t) * CHAR_BIT));

	r = (mk_uint_t)(*x << n);

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, shr)(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(mk_uint_t) * CHAR_BIT));

	r = (mk_uint_t)(*x >> n);

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, rotl)(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(mk_uint_t) * CHAR_BIT));

	r = (mk_uint_t)((*x << n) | (*x >> (sizeof (mk_uint_t) * CHAR_BIT - n)));

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, rotr)(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(mk_uint_t) * CHAR_BIT));

	r = (mk_uint_t)((*x >> n) | (*x << (sizeof (mk_uint_t) * CHAR_BIT - n)));

	*out = r;
}


mk_jumbo int mk_uint_concat(mk_uint_tn, eq)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a == *b;
}

mk_jumbo int mk_uint_concat(mk_uint_tn, neq)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a != *b;
}

mk_jumbo int mk_uint_concat(mk_uint_tn, lt)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a < *b;
}

mk_jumbo int mk_uint_concat(mk_uint_tn, le)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a <= *b;
}

mk_jumbo int mk_uint_concat(mk_uint_tn, gt)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a > *b;
}

mk_jumbo int mk_uint_concat(mk_uint_tn, ge)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a >= *b;
}


mk_jumbo void mk_uint_concat(mk_uint_tn, inc)(mk_uint_t* x)
{
	mk_assert(x);

	++*x;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, dec)(mk_uint_t* x)
{
	mk_assert(x);

	--*x;
}


mk_jumbo void mk_uint_concat(mk_uint_tn, add)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a + *b);

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, sub)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a - *b);

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, mul)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a * *b);

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, mulhi)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	#define shift ((((int)(sizeof(mk_uint_t))) * ((int)(CHAR_BIT))) / 2)
	#define one ((mk_uint_t)(1u))
	#define mask ((mk_uint_t)(((mk_uint_t)(one << shift)) - 1))

	mk_uint_t alo;
	mk_uint_t ahi;
	mk_uint_t blo;
	mk_uint_t bhi;
	mk_uint_t ablo;
	mk_uint_t abmi;
	mk_uint_t bami;
	mk_uint_t abhi;
	mk_uint_t r;

	mk_assert(a);
	mk_assert(b);
	mk_assert(out);

	alo = (mk_uint_t)((*a) & mask);
	ahi = (mk_uint_t)(((*a) >> shift) & mask);
	blo = (mk_uint_t)((*b) & mask);
	bhi = (mk_uint_t)(((*b) >> shift) & mask);

	ablo = (mk_uint_t)(alo * blo);
	abmi = (mk_uint_t)(alo * bhi);
	bami = (mk_uint_t)(ahi * blo);
	abhi = (mk_uint_t)(ahi * bhi);

	r =
		(mk_uint_t)
		(
			abhi +
			((mk_uint_t)(abmi >> shift)) +
			((mk_uint_t)(bami >> shift)) +
			(
				(mk_uint_t)
				(
					(
						(mk_uint_t)
						(
							((mk_uint_t)(abmi & mask)) +
							((mk_uint_t)(bami & mask)) +
							((mk_uint_t)(ablo >> shift))
						)
					) >> shift
				)
			)
		);

	*out = r;

	#undef shift
	#undef one
	#undef mask
}

mk_jumbo void mk_uint_concat(mk_uint_tn, divmod)(mk_uint_t* div, mk_uint_t* mod, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t aa;
	mk_uint_t bb;
	mk_uint_t d;
	mk_uint_t m;

	mk_assert(div);
	mk_assert(mod);
	mk_assert(a);
	mk_assert(b);
	mk_assert(*b != 0);

	aa = *a;
	bb = *b;
	d = (mk_uint_t)(aa / bb);
	m = (mk_uint_t)(aa % bb);

	*div = d;
	*mod = m;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, div)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	mk_assert(*b != 0);

	r = (mk_uint_t)(*a / *b);

	*out = r;
}

mk_jumbo void mk_uint_concat(mk_uint_tn, mod)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);
	mk_assert(*b != 0);

	r = (mk_uint_t)(*a % *b);

	*out = r;
}


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#undef mk_uint_concat_1
#undef mk_uint_concat
