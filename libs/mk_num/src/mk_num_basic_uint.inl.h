#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_llong.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizet.h"
#include "mk_lang_uintmaxt.h"


#include "mk_num_basic_uint_def.h"


mk_lang_jumbo void mk_num_set_zero(mk_detail_num_basic_ut_type* x);
mk_lang_jumbo void mk_num_set_one(mk_detail_num_basic_ut_type* x);
mk_lang_jumbo void mk_num_set_mask(mk_detail_num_basic_ut_type* x, int bits);

mk_lang_jumbo void mk_num_from_char(mk_detail_num_basic_ut_type* x, char src);
mk_lang_jumbo void mk_num_from_uchar(mk_detail_num_basic_ut_type* x, unsigned char src);
mk_lang_jumbo void mk_num_from_schar(mk_detail_num_basic_ut_type* x, signed char src);
mk_lang_jumbo void mk_num_from_ushort(mk_detail_num_basic_ut_type* x, unsigned short int src);
mk_lang_jumbo void mk_num_from_sshort(mk_detail_num_basic_ut_type* x, signed short int src);
mk_lang_jumbo void mk_num_from_uint(mk_detail_num_basic_ut_type* x, unsigned int src);
mk_lang_jumbo void mk_num_from_sint(mk_detail_num_basic_ut_type* x, signed int src);
mk_lang_jumbo void mk_num_from_ulong(mk_detail_num_basic_ut_type* x, unsigned long int src);
mk_lang_jumbo void mk_num_from_slong(mk_detail_num_basic_ut_type* x, signed long int src);
mk_lang_jumbo void mk_num_from_ullong(mk_detail_num_basic_ut_type* x, mk_lang_ullong_t src);
mk_lang_jumbo void mk_num_from_sllong(mk_detail_num_basic_ut_type* x, mk_lang_sllong_t src);
mk_lang_jumbo void mk_num_from_ulllong(mk_detail_num_basic_ut_type* x, mk_lang_ulllong_t src);
mk_lang_jumbo void mk_num_from_slllong(mk_detail_num_basic_ut_type* x, mk_lang_slllong_t src);
mk_lang_jumbo void mk_num_from_sizet(mk_detail_num_basic_ut_type* x, mk_lang_size_t src);
mk_lang_jumbo void mk_num_from_umaxt(mk_detail_num_basic_ut_type* x, mk_lang_uintmax_t src);
mk_lang_jumbo void mk_num_from_smaxt(mk_detail_num_basic_ut_type* x, mk_lang_sintmax_t src);

mk_lang_nodiscard mk_lang_jumbo char mk_num_to_char(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo unsigned char mk_num_to_uchar(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo signed char mk_num_to_schar(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo unsigned short int mk_num_to_ushort(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo signed short int mk_num_to_sshort(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo unsigned int mk_num_to_uint(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo signed int mk_num_to_sint(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo unsigned long int mk_num_to_ulong(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo signed long int mk_num_to_slong(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_ullong_t mk_num_to_ullong(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_sllong_t mk_num_to_sllong(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_ulllong_t mk_num_to_ulllong(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_slllong_t mk_num_to_slllong(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_num_to_sizet(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_uintmax_t mk_num_to_umaxt(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_sintmax_t mk_num_to_smaxt(mk_detail_num_basic_ut_type const* x);

mk_lang_jumbo void mk_num_from_uchars_le(mk_detail_num_basic_ut_type* x, unsigned char const* buff);
mk_lang_jumbo void mk_num_from_ushorts_le(mk_detail_num_basic_ut_type* x, unsigned short int const* buff);
mk_lang_jumbo void mk_num_from_uints_le(mk_detail_num_basic_ut_type* x, unsigned int const* buff);
mk_lang_jumbo void mk_num_from_ulongs_le(mk_detail_num_basic_ut_type* x, unsigned long int const* buff);
mk_lang_jumbo void mk_num_from_ullongs_le(mk_detail_num_basic_ut_type* x, mk_lang_ullong_t const* buff);
mk_lang_jumbo void mk_num_from_ulllongs_le(mk_detail_num_basic_ut_type* x, mk_lang_ulllong_t const* buff);
mk_lang_jumbo void mk_num_from_sizets_le(mk_detail_num_basic_ut_type* x, mk_lang_size_t const* buff);
mk_lang_jumbo void mk_num_from_umaxts_le(mk_detail_num_basic_ut_type* x, mk_lang_uintmax_t const* buff);

mk_lang_jumbo void mk_num_to_uchars_le(mk_detail_num_basic_ut_type const* x, unsigned char* buff);
mk_lang_jumbo void mk_num_to_ushorts_le(mk_detail_num_basic_ut_type const* x, unsigned short int* buff);
mk_lang_jumbo void mk_num_to_uints_le(mk_detail_num_basic_ut_type const* x, unsigned int* buff);
mk_lang_jumbo void mk_num_to_ulongs_le(mk_detail_num_basic_ut_type const* x, unsigned long int* buff);
mk_lang_jumbo void mk_num_to_ullongs_le(mk_detail_num_basic_ut_type const* x, mk_lang_ullong_t* buff);
mk_lang_jumbo void mk_num_to_ulllongs_le(mk_detail_num_basic_ut_type const* x, mk_lang_ulllong_t* buff);
mk_lang_jumbo void mk_num_to_sizets_le(mk_detail_num_basic_ut_type const* x, mk_lang_size_t* buff);
mk_lang_jumbo void mk_num_to_umaxts_le(mk_detail_num_basic_ut_type const* x, mk_lang_uintmax_t* buff);

mk_lang_jumbo void mk_num_from_uchars_be(mk_detail_num_basic_ut_type* x, unsigned char const* buff);
mk_lang_jumbo void mk_num_from_ushorts_be(mk_detail_num_basic_ut_type* x, unsigned short int const* buff);
mk_lang_jumbo void mk_num_from_uints_be(mk_detail_num_basic_ut_type* x, unsigned int const* buff);
mk_lang_jumbo void mk_num_from_ulongs_be(mk_detail_num_basic_ut_type* x, unsigned long int const* buff);
mk_lang_jumbo void mk_num_from_ullongs_be(mk_detail_num_basic_ut_type* x, mk_lang_ullong_t const* buff);
mk_lang_jumbo void mk_num_from_ulllongs_be(mk_detail_num_basic_ut_type* x, mk_lang_ulllong_t const* buff);
mk_lang_jumbo void mk_num_from_sizets_be(mk_detail_num_basic_ut_type* x, mk_lang_size_t const* buff);
mk_lang_jumbo void mk_num_from_umaxts_be(mk_detail_num_basic_ut_type* x, mk_lang_uintmax_t const* buff);

mk_lang_jumbo void mk_num_to_uchars_be(mk_detail_num_basic_ut_type const* x, unsigned char* buff);
mk_lang_jumbo void mk_num_to_ushorts_be(mk_detail_num_basic_ut_type const* x, unsigned short int* buff);
mk_lang_jumbo void mk_num_to_uints_be(mk_detail_num_basic_ut_type const* x, unsigned int* buff);
mk_lang_jumbo void mk_num_to_ulongs_be(mk_detail_num_basic_ut_type const* x, unsigned long int* buff);
mk_lang_jumbo void mk_num_to_ullongs_be(mk_detail_num_basic_ut_type const* x, mk_lang_ullong_t* buff);
mk_lang_jumbo void mk_num_to_ulllongs_be(mk_detail_num_basic_ut_type const* x, mk_lang_ulllong_t* buff);
mk_lang_jumbo void mk_num_to_sizets_be(mk_detail_num_basic_ut_type const* x, mk_lang_size_t* buff);
mk_lang_jumbo void mk_num_to_umaxts_be(mk_detail_num_basic_ut_type const* x, mk_lang_uintmax_t* buff);

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_is_zero(mk_detail_num_basic_ut_type const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_eq(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_ne(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_lt(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_le(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_gt(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_ge(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y);

mk_lang_jumbo void mk_num_inc(mk_detail_num_basic_ut_type* x);
mk_lang_jumbo void mk_num_dec(mk_detail_num_basic_ut_type* x);

mk_lang_jumbo void mk_num_not2(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type* y);
mk_lang_jumbo void mk_num_not1(mk_detail_num_basic_ut_type* x);
mk_lang_jumbo void mk_num_or3(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_or2(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_and3(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_and2(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_xor3(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_xor2(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);

mk_lang_jumbo void mk_num_shl3(mk_detail_num_basic_ut_type const* x, int bits, mk_detail_num_basic_ut_type* y);
mk_lang_jumbo void mk_num_shl2(mk_detail_num_basic_ut_type* x, int bits);
mk_lang_jumbo void mk_num_shr3(mk_detail_num_basic_ut_type const* x, int bits, mk_detail_num_basic_ut_type* y);
mk_lang_jumbo void mk_num_shr2(mk_detail_num_basic_ut_type* x, int bits);

mk_lang_jumbo void mk_num_add3_wrap_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_add3_wrap_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add3_wrap_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_add3_wrap_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add3_sat_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_add3_sat_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add3_sat_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_add3_sat_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add3_crash_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_add3_crash_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add3_crash_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_add3_crash_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add2_wrap_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_add2_wrap_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add2_wrap_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_add2_wrap_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add2_sat_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_add2_sat_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add2_sat_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_add2_sat_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add2_crash_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_add2_crash_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_add2_crash_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_add2_crash_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);

mk_lang_jumbo void mk_num_sub3_wrap_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_sub3_wrap_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub3_wrap_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_sub3_wrap_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub3_sat_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_sub3_sat_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub3_sat_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_sub3_sat_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub3_crash_cid_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_sub3_crash_cid_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub3_crash_cie_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_sub3_crash_cie_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_detail_num_basic_ut_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub2_wrap_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_sub2_wrap_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub2_wrap_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_sub2_wrap_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub2_sat_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_sub2_sat_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub2_sat_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_sub2_sat_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub2_crash_cid_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_sub2_crash_cid_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_sub2_crash_cie_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_sub2_crash_cie_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);

mk_lang_jumbo void mk_num_mul3_wrap_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_mul3_wrap_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_detail_num_basic_ut_type* co);
mk_lang_jumbo void mk_num_mul3_sat_cod(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_mul3_sat_coe(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z, mk_detail_num_basic_ut_type* co);
mk_lang_jumbo void mk_num_mul3_crash(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* z);
mk_lang_jumbo void mk_num_mul2_wrap_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_mul2_wrap_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* co);
mk_lang_jumbo void mk_num_mul2_sat_cod(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_mul2_sat_coe(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* co);
mk_lang_jumbo void mk_num_mul2_crash(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);

mk_lang_jumbo void mk_num_div3_wrap(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* res);
mk_lang_jumbo void mk_num_mod3_wrap(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* res);
mk_lang_jumbo void mk_num_divmod3_wrap(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* res_div, mk_detail_num_basic_ut_type* res_mod);
mk_lang_jumbo void mk_num_div3_sat(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* res);
mk_lang_jumbo void mk_num_mod3_sat(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* res);
mk_lang_jumbo void mk_num_divmod3_sat(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* res_div, mk_detail_num_basic_ut_type* res_mod);
mk_lang_jumbo void mk_num_div3_crash(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* res);
mk_lang_jumbo void mk_num_mod3_crash(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* res);
mk_lang_jumbo void mk_num_divmod3_crash(mk_detail_num_basic_ut_type const* x, mk_detail_num_basic_ut_type const* y, mk_detail_num_basic_ut_type* res_div, mk_detail_num_basic_ut_type* res_mod);
mk_lang_jumbo void mk_num_div2_wrap(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_mod2_wrap(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_div2_sat(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_mod2_sat(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_div2_crash(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);
mk_lang_jumbo void mk_num_mod2_crash(mk_detail_num_basic_ut_type* x, mk_detail_num_basic_ut_type const* y);

#include "mk_num_basic_uint_undef.h"


#undef mk_detail_num_basic_ut_type
#undef mk_detail_num_basic_ut_name
