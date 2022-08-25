#include "../../../mk_utils/src/mk_jumbo.h"


#define mk_uint_parts ((mk_uint_bits + (mk_uint_small_bits - 1)) / mk_uint_small_bits)


#if mk_uint_parts == 1


mk_uint_t
{
	mk_uint_small_t m_data;
};


#else


mk_uint_t
{
	mk_uint_small_t m_data[mk_uint_parts];
};


#endif


mk_jumbo void mk_uint_zero(mk_uint_t* out);
mk_jumbo void mk_uint_one(mk_uint_t* out);
mk_jumbo void mk_uint_from_int(mk_uint_t* out, unsigned in);
mk_jumbo unsigned mk_uint_to_int(mk_uint_t const* x);
mk_jumbo void mk_uint_from_long(mk_uint_t* out, unsigned long in);
mk_jumbo unsigned long mk_uint_to_long(mk_uint_t const* x);
mk_jumbo void mk_uint_from_sizet(mk_uint_t* out, size_t in);
mk_jumbo size_t mk_uint_to_sizet(mk_uint_t const* x);
mk_jumbo void mk_uint_from_buff_le(mk_uint_t* out, void const* buff);
mk_jumbo void mk_uint_to_buff_le(mk_uint_t const* x, void* buff);
mk_jumbo void mk_uint_from_buff_be(mk_uint_t* out, void const* buff);
mk_jumbo void mk_uint_to_buff_be(mk_uint_t const* x, void* buff);

mk_jumbo int mk_uint_is_zero(mk_uint_t const* x);
mk_jumbo int mk_uint_is_max(mk_uint_t const* x);

mk_jumbo void mk_uint_cmplmnt(mk_uint_t* out, mk_uint_t const* x);
mk_jumbo void mk_uint_or(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_and(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_xor(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);

mk_jumbo void mk_uint_shl(mk_uint_t* out, mk_uint_t const* x, int n);
mk_jumbo void mk_uint_shr(mk_uint_t* out, mk_uint_t const* x, int n);
mk_jumbo void mk_uint_rotl(mk_uint_t* out, mk_uint_t const* x, int n);
mk_jumbo void mk_uint_rotr(mk_uint_t* out, mk_uint_t const* x, int n);

mk_jumbo int mk_uint_eq(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_neq(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_lt(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_le(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_gt(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_ge(mk_uint_t const* a, mk_uint_t const* b);

mk_jumbo void mk_uint_inc(mk_uint_t* x);
mk_jumbo void mk_uint_dec(mk_uint_t* x);

mk_jumbo void mk_uint_add(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_sub(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_mul(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_divmod(mk_uint_t* div, mk_uint_t* mod, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_divmodsm(mk_uint_t* div, mk_uint_small_t* mod, mk_uint_t const* a, mk_uint_small_t const* b);
mk_jumbo void mk_uint_div(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_mod(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);

mk_jumbo int mk_uint_to_string_dec_n(mk_uint_t const* x, char* str, int str_len);
mk_jumbo int mk_uint_to_string_dec_w(mk_uint_t const* x, wchar_t* str, int str_len);
mk_jumbo int mk_uint_to_string_hex_n(mk_uint_t const* x, char* str, int str_len);
mk_jumbo int mk_uint_to_string_hex_w(mk_uint_t const* x, wchar_t* str, int str_len);
mk_jumbo void mk_uint_to_string_hex_full_n(mk_uint_t const* x, char* str);
mk_jumbo void mk_uint_to_string_hex_full_w(mk_uint_t const* x, wchar_t* str);


#undef mk_uint_parts
