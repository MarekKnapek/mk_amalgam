#define mk_uint_concat_2_(a, b) mk_uint ## a ## _ ## b
#define mk_uint_concat_1_(a, b) mk_uint_concat_2_(a, b)
#define mk_uint_concat_(a) mk_uint_concat_1_(mk_uint_bits, a)


#define mk_uint_zero mk_uint_concat_(zero)
#define mk_uint_one mk_uint_concat_(one)
#define mk_uint_from_int mk_uint_concat_(from_int)
#define mk_uint_to_int mk_uint_concat_(to_int)
#define mk_uint_from_long mk_uint_concat_(from_long)
#define mk_uint_to_long mk_uint_concat_(to_long)
#define mk_uint_from_sizet mk_uint_concat_(from_sizet)
#define mk_uint_to_sizet mk_uint_concat_(to_sizet)
#define mk_uint_from_buff_le mk_uint_concat_(from_buff_le)
#define mk_uint_to_buff_le mk_uint_concat_(to_buff_le)
#define mk_uint_from_buff_be mk_uint_concat_(from_buff_be)
#define mk_uint_to_buff_be mk_uint_concat_(to_buff_be)

#define mk_uint_is_zero mk_uint_concat_(is_zero)
#define mk_uint_is_max mk_uint_concat_(is_max)

#define mk_uint_cmplmnt mk_uint_concat_(cmplmnt)
#define mk_uint_or mk_uint_concat_(or)
#define mk_uint_and mk_uint_concat_(and)
#define mk_uint_xor mk_uint_concat_(xor)

#define mk_uint_shl mk_uint_concat_(shl)
#define mk_uint_shr mk_uint_concat_(shr)
#define mk_uint_rotl mk_uint_concat_(rotl)
#define mk_uint_rotr mk_uint_concat_(rotr)

#define mk_uint_eq mk_uint_concat_(eq)
#define mk_uint_neq mk_uint_concat_(neq)
#define mk_uint_lt mk_uint_concat_(lt)
#define mk_uint_le mk_uint_concat_(le)
#define mk_uint_gt mk_uint_concat_(gt)
#define mk_uint_ge mk_uint_concat_(ge)

#define mk_uint_inc mk_uint_concat_(inc)
#define mk_uint_dec mk_uint_concat_(dec)

#define mk_uint_add mk_uint_concat_(add)
#define mk_uint_sub mk_uint_concat_(sub)
#define mk_uint_mul mk_uint_concat_(mul)
#define mk_uint_div mk_uint_concat_(div)
#define mk_uint_mod mk_uint_concat_(mod)

#define mk_uint_to_string_dec_n mk_uint_concat_(to_string_dec_n)
#define mk_uint_to_string_dec_w mk_uint_concat_(to_string_dec_w)
#define mk_uint_to_string_hex_n mk_uint_concat_(to_string_hex_n)
#define mk_uint_to_string_hex_w mk_uint_concat_(to_string_hex_w)
#define mk_uint_to_string_hex_full_n mk_uint_concat_(to_string_hex_full_n)
#define mk_uint_to_string_hex_full_w mk_uint_concat_(to_string_hex_full_w)
