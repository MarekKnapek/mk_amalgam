#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizet.h"
#include "mk_lang_uintmaxt.h"


#include "mk_num_composite_uint_def.h"


struct mk_num_composite_un_s
{
	mk_num_composite_base_type m_parts[mk_num_composite_un_parts];
};
typedef struct mk_num_composite_un_s mk_num_composite_un_t;


mk_lang_jumbo void mk_num_composite_un_set_zero(mk_num_composite_un_t* x);
mk_lang_jumbo void mk_num_composite_un_set_one(mk_num_composite_un_t* x);
mk_lang_jumbo void mk_num_composite_un_set_mask(mk_num_composite_un_t* x, int bits);

mk_lang_jumbo void mk_num_composite_un_from_buff_le(mk_num_composite_un_t* x, void const* buff);
mk_lang_jumbo void mk_num_composite_un_from_buff_be(mk_num_composite_un_t* x, void const* buff);
mk_lang_jumbo void mk_num_composite_un_to_buff_le(mk_num_composite_un_t const* x, void* buff);
mk_lang_jumbo void mk_num_composite_un_to_buff_be(mk_num_composite_un_t const* x, void* buff);

mk_lang_jumbo void mk_num_composite_un_from_char(mk_num_composite_un_t* x, char src);
mk_lang_jumbo void mk_num_composite_un_from_uchar(mk_num_composite_un_t* x, unsigned char src);
mk_lang_jumbo void mk_num_composite_un_from_schar(mk_num_composite_un_t* x, signed char src);
mk_lang_jumbo void mk_num_composite_un_from_ushort(mk_num_composite_un_t* x, unsigned short int src);
mk_lang_jumbo void mk_num_composite_un_from_sshort(mk_num_composite_un_t* x, signed short int src);
mk_lang_jumbo void mk_num_composite_un_from_uint(mk_num_composite_un_t* x, unsigned int src);
mk_lang_jumbo void mk_num_composite_un_from_sint(mk_num_composite_un_t* x, signed int src);
mk_lang_jumbo void mk_num_composite_un_from_ulong(mk_num_composite_un_t* x, unsigned long int src);
mk_lang_jumbo void mk_num_composite_un_from_slong(mk_num_composite_un_t* x, signed long int src);
mk_lang_jumbo void mk_num_composite_un_from_ullong(mk_num_composite_un_t* x, mk_lang_ullong_t src);
mk_lang_jumbo void mk_num_composite_un_from_sllong(mk_num_composite_un_t* x, mk_lang_sllong_t src);
mk_lang_jumbo void mk_num_composite_un_from_ulllong(mk_num_composite_un_t* x, mk_lang_ulllong_t src);
mk_lang_jumbo void mk_num_composite_un_from_slllong(mk_num_composite_un_t* x, mk_lang_slllong_t src);
mk_lang_jumbo void mk_num_composite_un_from_sizet(mk_num_composite_un_t* x, mk_lang_size_t src);
mk_lang_jumbo void mk_num_composite_un_from_umaxt(mk_num_composite_un_t* x, mk_lang_uintmax_t src);
mk_lang_jumbo void mk_num_composite_un_from_smaxt(mk_num_composite_un_t* x, mk_lang_sintmax_t src);

mk_lang_nodiscard mk_lang_jumbo char mk_num_composite_un_to_char(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo unsigned char mk_num_composite_un_to_uchar(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo signed char mk_num_composite_un_to_schar(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo unsigned short int mk_num_composite_un_to_ushort(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo signed short int mk_num_composite_un_to_sshort(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo unsigned int mk_num_composite_un_to_uint(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo signed int mk_num_composite_un_to_sint(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo unsigned long int mk_num_composite_un_to_ulong(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo signed long int mk_num_composite_un_to_slong(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_ullong_t mk_num_composite_un_to_ullong(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_sllong_t mk_num_composite_un_to_sllong(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_ulllong_t mk_num_composite_un_to_ulllong(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_slllong_t mk_num_composite_un_to_slllong(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_num_composite_un_to_sizet(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_uintmax_t mk_num_composite_un_to_umaxt(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_sintmax_t mk_num_composite_un_to_smaxt(mk_num_composite_un_t const* x);

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_is_zero(mk_num_composite_un_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_eq(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_ne(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_lt(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_le(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_gt(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_ge(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y);

mk_lang_jumbo void mk_num_composite_un_inc(mk_num_composite_un_t* x);
mk_lang_jumbo void mk_num_composite_un_dec(mk_num_composite_un_t* x);

mk_lang_jumbo void mk_num_composite_un_not2(mk_num_composite_un_t const* x, mk_num_composite_un_t* y);
mk_lang_jumbo void mk_num_composite_un_not1(mk_num_composite_un_t* x);
mk_lang_jumbo void mk_num_composite_un_or3(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_or2(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_and3(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_and2(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_xor3(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_xor2(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);

mk_lang_jumbo void mk_num_composite_un_shl3(mk_num_composite_un_t const* x, int bits, mk_num_composite_un_t* y);
mk_lang_jumbo void mk_num_composite_un_shl2(mk_num_composite_un_t* x, int bits);
mk_lang_jumbo void mk_num_composite_un_shr3(mk_num_composite_un_t const* x, int bits, mk_num_composite_un_t* y);
mk_lang_jumbo void mk_num_composite_un_shr2(mk_num_composite_un_t* x, int bits);

mk_lang_jumbo void mk_num_composite_un_add3_wrap_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_add3_wrap_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add3_wrap_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_add3_wrap_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add3_sat_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_add3_sat_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add3_sat_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_add3_sat_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add3_crash_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_add3_crash_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add3_crash_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_add3_crash_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add2_wrap_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_add2_wrap_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add2_wrap_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_composite_un_add2_wrap_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add2_sat_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_add2_sat_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add2_sat_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_composite_un_add2_sat_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add2_crash_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_add2_crash_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_add2_crash_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_composite_un_add2_crash_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);

mk_lang_jumbo void mk_num_composite_un_sub3_wrap_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_sub3_wrap_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub3_wrap_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_sub3_wrap_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub3_sat_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_sub3_sat_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub3_sat_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_sub3_sat_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub3_crash_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_sub3_crash_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub3_crash_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_sub3_crash_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub2_wrap_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_sub2_wrap_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub2_wrap_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_composite_un_sub2_wrap_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub2_sat_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_sub2_sat_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub2_sat_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_composite_un_sub2_sat_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub2_crash_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_sub2_crash_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_composite_un_sub2_crash_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_composite_un_sub2_crash_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);

mk_lang_jumbo void mk_num_composite_un_mul3_wrap_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_mul3_wrap_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_num_composite_un_t* co);
mk_lang_jumbo void mk_num_composite_un_mul3_sat_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_mul3_sat_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_num_composite_un_t* co);
mk_lang_jumbo void mk_num_composite_un_mul3_crash(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z);
mk_lang_jumbo void mk_num_composite_un_mul2_wrap_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_mul2_wrap_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* co);
mk_lang_jumbo void mk_num_composite_un_mul2_sat_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_mul2_sat_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* co);
mk_lang_jumbo void mk_num_composite_un_mul2_crash(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);

mk_lang_jumbo void mk_num_composite_un_div3_wrap(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* res);
mk_lang_jumbo void mk_num_composite_un_mod3_wrap(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* res);
mk_lang_jumbo void mk_num_composite_un_divmod3_wrap(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* res_div, mk_num_composite_un_t* res_mod);
mk_lang_jumbo void mk_num_composite_un_div3_sat(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* res);
mk_lang_jumbo void mk_num_composite_un_mod3_sat(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* res);
mk_lang_jumbo void mk_num_composite_un_divmod3_sat(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* res_div, mk_num_composite_un_t* res_mod);
mk_lang_jumbo void mk_num_composite_un_div3_crash(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* res);
mk_lang_jumbo void mk_num_composite_un_mod3_crash(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* res);
mk_lang_jumbo void mk_num_composite_un_divmod3_crash(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* res_div, mk_num_composite_un_t* res_mod);
mk_lang_jumbo void mk_num_composite_un_div2_wrap(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_mod2_wrap(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_div2_sat(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_mod2_sat(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_div2_crash(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);
mk_lang_jumbo void mk_num_composite_un_mod2_crash(mk_num_composite_un_t* x, mk_num_composite_un_t const* y);


#include "mk_num_composite_uint_undef.h"


#undef mk_num_composite_bits
#undef mk_num_composite_base_type
#undef mk_num_composite_base_name
#undef mk_num_composite_base_bits
