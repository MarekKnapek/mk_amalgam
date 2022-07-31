#define mk_uint_concat_2(a, b) mk_uint_ ## a ## _ ## b
#define mk_uint_concat_1(a, b) mk_uint_concat_2(a, b)
#define mk_uint_concat(a) mk_uint_concat_1(mk_uint_small_tn, a)


#define mk_uint_small_zero mk_uint_concat(zero)
#define mk_uint_small_one mk_uint_concat(one)
#define mk_uint_small_from_int mk_uint_concat(from_int)
#define mk_uint_small_to_int mk_uint_concat(to_int)
#define mk_uint_small_from_long mk_uint_concat(from_long)
#define mk_uint_small_to_long mk_uint_concat(to_long)
#define mk_uint_small_from_sizet mk_uint_concat(from_sizet)
#define mk_uint_small_to_sizet mk_uint_concat(to_sizet)
#define mk_uint_small_from_buff_le mk_uint_concat(from_buff_le)
#define mk_uint_small_to_buff_le mk_uint_concat(to_buff_le)
#define mk_uint_small_from_buff_be mk_uint_concat(from_buff_be)
#define mk_uint_small_to_buff_be mk_uint_concat(to_buff_be)

#define mk_uint_small_is_zero mk_uint_concat(is_zero)
#define mk_uint_small_is_max mk_uint_concat(is_max)

#define mk_uint_small_cmplmnt mk_uint_concat(cmplmnt)
#define mk_uint_small_or mk_uint_concat(or)
#define mk_uint_small_and mk_uint_concat(and)
#define mk_uint_small_xor mk_uint_concat(xor)

#define mk_uint_small_shl mk_uint_concat(shl)
#define mk_uint_small_shr mk_uint_concat(shr)
#define mk_uint_small_rotl mk_uint_concat(rotl)
#define mk_uint_small_rotr mk_uint_concat(rotr)

#define mk_uint_small_eq mk_uint_concat(eq)
#define mk_uint_small_neq mk_uint_concat(neq)
#define mk_uint_small_lt mk_uint_concat(lt)
#define mk_uint_small_le mk_uint_concat(le)
#define mk_uint_small_gt mk_uint_concat(gt)
#define mk_uint_small_ge mk_uint_concat(ge)

#define mk_uint_small_inc mk_uint_concat(inc)
#define mk_uint_small_dec mk_uint_concat(dec)

#define mk_uint_small_add mk_uint_concat(add)
#define mk_uint_small_sub mk_uint_concat(sub)
#define mk_uint_small_mul mk_uint_concat(mul)
#define mk_uint_small_mulhi mk_uint_concat(mulhi)
#define mk_uint_small_div mk_uint_concat(div)
#define mk_uint_small_mod mk_uint_concat(mod)
