#include "../../../mk_utils/src/mk_assert.h"
#include "../../../mk_utils/src/mk_jumbo.h"

#include <string.h> /* memcpy */


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#pragma warning(disable:5045) /* warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified */
#endif


#define mk_concat_(a, b) a ## b
#define mk_concat(a, b) mk_concat_(a, b)


mk_jumbo int mk_concat(mk_concat(mk_uint_to_string_dec, _), mk_uint_str_suffix)(mk_uint_t const* x, mk_char_t* str, int str_len)
{
	#define worst_case_len (mk_uint_bits == 8 ? 3 : mk_uint_bits == 16 ? 5 : mk_uint_bits == 32 ? 10 : mk_uint_bits == 64 ? 20 : mk_uint_bits == 128 ? 39 : -1)

	static mk_char_t const s_symbols[] =
	{
		mk_char_c('0'),
		mk_char_c('1'),
		mk_char_c('2'),
		mk_char_c('3'),
		mk_char_c('4'),
		mk_char_c('5'),
		mk_char_c('6'),
		mk_char_c('7'),
		mk_char_c('8'),
		mk_char_c('9'),
	};

	int i;
	mk_uint_t base;
	mk_uint_t a;
	mk_uint_t b;
	mk_uint_t c;
	unsigned m;
	mk_char_t tmp[worst_case_len];

	mk_assert(x);
	mk_assert(str || str_len == 0);
	mk_assert(str_len >= 0);

	i = worst_case_len;
	mk_uint_from_int(&base, 10);
	a = *x;
	for(;;)
	{
		mk_uint_div(&b, &a, &base);
		mk_uint_mod(&c, &a, &base);
		m = mk_uint_to_int(&c);
		tmp[--i] = s_symbols[m];
		if(mk_uint_is_zero(&b))
		{
			break;
		}
		a = b;
	}
	i = worst_case_len - i;
	if(i > str_len)
	{
		return -i;
	}
	memcpy(str, tmp + worst_case_len - i, i * sizeof(mk_char_t));
	return i;

	#undef worst_case_len
}

mk_jumbo int mk_concat(mk_concat(mk_uint_to_string_hex, _), mk_uint_str_suffix)(mk_uint_t const* x, mk_char_t* str, int str_len)
{
	#define worst_case_len (mk_uint_bits / 4)

	static mk_char_t const s_zero = mk_char_c('0');

	mk_char_t tmp[worst_case_len];
	int i;
	int zeros;
	int symbols;

	mk_concat(mk_concat(mk_uint_to_string_hex_full, _), mk_uint_str_suffix)(x, tmp);
	for(i = 0; i != worst_case_len - 1; ++i)
	{
		if(tmp[i] != s_zero)
		{
			break;
		}
	}
	zeros = i;
	symbols = worst_case_len - zeros;
	if(symbols > str_len)
	{
		return -symbols;
	}
	memcpy(str, tmp + zeros, symbols * sizeof(mk_char_t));
	return symbols;

	#undef worst_case_len
}

mk_jumbo void mk_concat(mk_concat(mk_uint_to_string_hex_full, _), mk_uint_str_suffix)(mk_uint_t const* x, mk_char_t* str)
{
	static mk_char_t const s_symbols[] =
	{
		mk_char_c('0'),
		mk_char_c('1'),
		mk_char_c('2'),
		mk_char_c('3'),
		mk_char_c('4'),
		mk_char_c('5'),
		mk_char_c('6'),
		mk_char_c('7'),
		mk_char_c('8'),
		mk_char_c('9'),
		mk_char_c('a'),
		mk_char_c('b'),
		mk_char_c('c'),
		mk_char_c('d'),
		mk_char_c('e'),
		mk_char_c('f'),
	};

	mk_uint_t a;
	mk_char_t* output;
	int i;
	unsigned m;
	unsigned idx;

	a = *x;
	output = str + mk_uint_bits / 4;
	for(i = 0; i != mk_uint_bits / 8; ++i)
	{
		m = mk_uint_to_int(&a) & 0xff;
		idx = m & 0x0f;
		--output;
		*output = s_symbols[idx];
		idx = m >> 4;
		--output;
		*output = s_symbols[idx];
		#if mk_uint_bits > 8
		mk_uint_shr(&a, &a, 8);
		#endif
	}
}


#undef mk_concat_
#undef mk_concat


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
