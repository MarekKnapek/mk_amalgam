#include "../../../mk_utils/src/mk_assert.h"
#include "../../../mk_utils/src/mk_jumbo.h"

#include <string.h> /* memcpy */


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#pragma warning(disable:5045) /* warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified */
#endif


#define mk_concat_q_(a, b) a ## b
#define mk_concat_q(a, b) mk_concat_q_(a, b)


mk_jumbo int mk_concat_q(mk_concat_q(mk_uint_to_string_dec, _), mk_uint_str_suffix)(mk_uint_t const* x, mk_char_t* str, int str_len)
{
	#define mk_private_to_uint(x) ((unsigned)(x))
	#define mk_private_to_long(x) ((long)(x))
	#define mk_private_le(x, y) (mk_private_to_long(x) <= mk_private_to_long(y))
	#define mk_private_mul(x, y) (mk_private_to_long(mk_private_to_long(x) * mk_private_to_long(y)))
	#define mk_private_shr(x, y) (mk_private_to_long(mk_private_to_long(x) >> mk_private_to_uint(y)))
	#define mk_private_add(x, y) (mk_private_to_long(mk_private_to_long(x) + mk_private_to_long(y)))
	#define mk_private_log_constant (19728l) /* floor(log_10(2) << 16) */
	#define mk_private_worst_case_len (mk_private_le(mk_uint_bits, 65536l) ? (mk_private_add(mk_private_shr(mk_private_mul(mk_uint_bits, mk_private_log_constant), 16u), 1)) : (mk_private_to_long(-1)))

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
	mk_uint_small_t base;
	mk_uint_t a;
	mk_uint_t b;
	mk_uint_small_t c;
	unsigned m;
	mk_char_t tmp[mk_private_worst_case_len];

	mk_assert(x);
	mk_assert(str || str_len == 0);
	mk_assert(str_len >= 0);

	i = mk_private_worst_case_len;
	mk_uint_small_from_int(&base, 10);
	a = *x;
	for(;;)
	{
		mk_uint_divmodsm(&b, &c, &a, &base);
		m = mk_uint_small_to_int(&c);
		tmp[--i] = s_symbols[m];
		if(mk_uint_is_zero(&b))
		{
			break;
		}
		a = b;
	}
	i = mk_private_worst_case_len - i;
	if(i > str_len)
	{
		return -i;
	}
	memcpy(str, tmp + mk_private_worst_case_len - i, i * sizeof(mk_char_t));
	return i;

	#undef mk_private_to_uint
	#undef mk_private_to_long
	#undef mk_private_le
	#undef mk_private_mul
	#undef mk_private_shr
	#undef mk_private_add
	#undef mk_private_log_constant 
	#undef mk_private_worst_case_len 
}

mk_jumbo int mk_concat_q(mk_concat_q(mk_uint_to_string_hex, _), mk_uint_str_suffix)(mk_uint_t const* x, mk_char_t* str, int str_len)
{
	#define mk_private_worst_case_len (mk_uint_bits / 4)

	static mk_char_t const s_zero = mk_char_c('0');

	mk_char_t tmp[mk_private_worst_case_len];
	int i;
	int zeros;
	int symbols;

	mk_concat_q(mk_concat_q(mk_uint_to_string_hex_full, _), mk_uint_str_suffix)(x, tmp);
	for(i = 0; i != mk_private_worst_case_len - 1; ++i)
	{
		if(tmp[i] != s_zero)
		{
			break;
		}
	}
	zeros = i;
	symbols = mk_private_worst_case_len - zeros;
	if(symbols > str_len)
	{
		return -symbols;
	}
	memcpy(str, tmp + zeros, symbols * sizeof(mk_char_t));
	return symbols;

	#undef mk_private_worst_case_len
}

mk_jumbo void mk_concat_q(mk_concat_q(mk_uint_to_string_hex_full, _), mk_uint_str_suffix)(mk_uint_t const* x, mk_char_t* str)
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


#undef mk_concat_q_
#undef mk_concat_q


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
