#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizet.h"
#include "mk_lang_uintmaxt.h"


#include "mk_num_basic_uint_def.h"


mk_lang_jumbo void mk_num_basic_uint_set_zero(mk_num_basic_uint_type* x);
mk_lang_jumbo void mk_num_basic_uint_set_one(mk_num_basic_uint_type* x);
mk_lang_jumbo void mk_num_basic_uint_set_mask(mk_num_basic_uint_type* x, int bits);

mk_lang_jumbo void mk_num_basic_uint_from_char(mk_num_basic_uint_type* x, char const* src);
mk_lang_jumbo void mk_num_basic_uint_from_uchar(mk_num_basic_uint_type* x, unsigned char const* src);
mk_lang_jumbo void mk_num_basic_uint_from_schar(mk_num_basic_uint_type* x, signed char const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ushort(mk_num_basic_uint_type* x, unsigned short int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_sshort(mk_num_basic_uint_type* x, signed short int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_uint(mk_num_basic_uint_type* x, unsigned int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_sint(mk_num_basic_uint_type* x, signed int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ulong(mk_num_basic_uint_type* x, unsigned long int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_slong(mk_num_basic_uint_type* x, signed long int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ullong(mk_num_basic_uint_type* x, mk_lang_ullong_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_sllong(mk_num_basic_uint_type* x, mk_lang_sllong_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ulllong(mk_num_basic_uint_type* x, mk_lang_ulllong_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_slllong(mk_num_basic_uint_type* x, mk_lang_slllong_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_sizet(mk_num_basic_uint_type* x, mk_lang_size_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_umaxt(mk_num_basic_uint_type* x, mk_lang_uintmax_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_smaxt(mk_num_basic_uint_type* x, mk_lang_sintmax_t const* src);

mk_lang_jumbo void mk_num_basic_uint_to_char(mk_num_basic_uint_type const* x, char* dst);
mk_lang_jumbo void mk_num_basic_uint_to_uchar(mk_num_basic_uint_type const* x, unsigned char* dst);
mk_lang_jumbo void mk_num_basic_uint_to_schar(mk_num_basic_uint_type const* x, signed char* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ushort(mk_num_basic_uint_type const* x, unsigned short int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_sshort(mk_num_basic_uint_type const* x, signed short int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_uint(mk_num_basic_uint_type const* x, unsigned int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_sint(mk_num_basic_uint_type const* x, signed int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ulong(mk_num_basic_uint_type const* x, unsigned long int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_slong(mk_num_basic_uint_type const* x, signed long int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ullong(mk_num_basic_uint_type const* x, mk_lang_ullong_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_sllong(mk_num_basic_uint_type const* x, mk_lang_sllong_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ulllong(mk_num_basic_uint_type const* x, mk_lang_ulllong_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_slllong(mk_num_basic_uint_type const* x, mk_lang_slllong_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_sizet(mk_num_basic_uint_type const* x, mk_lang_size_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_umaxt(mk_num_basic_uint_type const* x, mk_lang_uintmax_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_smaxt(mk_num_basic_uint_type const* x, mk_lang_sintmax_t* dst);

mk_lang_jumbo void mk_num_basic_uint_from_uchars_le(mk_num_basic_uint_type* x, unsigned char const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ushorts_le(mk_num_basic_uint_type* x, unsigned short int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_uints_le(mk_num_basic_uint_type* x, unsigned int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ulongs_le(mk_num_basic_uint_type* x, unsigned long int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ullongs_le(mk_num_basic_uint_type* x, mk_lang_ullong_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ulllongs_le(mk_num_basic_uint_type* x, mk_lang_ulllong_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_sizets_le(mk_num_basic_uint_type* x, mk_lang_size_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_umaxts_le(mk_num_basic_uint_type* x, mk_lang_uintmax_t const* src);

mk_lang_jumbo void mk_num_basic_uint_to_uchars_le(mk_num_basic_uint_type const* x, unsigned char* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ushorts_le(mk_num_basic_uint_type const* x, unsigned short int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_uints_le(mk_num_basic_uint_type const* x, unsigned int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ulongs_le(mk_num_basic_uint_type const* x, unsigned long int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ullongs_le(mk_num_basic_uint_type const* x, mk_lang_ullong_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ulllongs_le(mk_num_basic_uint_type const* x, mk_lang_ulllong_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_sizets_le(mk_num_basic_uint_type const* x, mk_lang_size_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_umaxts_le(mk_num_basic_uint_type const* x, mk_lang_uintmax_t* dst);

mk_lang_jumbo void mk_num_basic_uint_from_uchars_be(mk_num_basic_uint_type* x, unsigned char const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ushorts_be(mk_num_basic_uint_type* x, unsigned short int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_uints_be(mk_num_basic_uint_type* x, unsigned int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ulongs_be(mk_num_basic_uint_type* x, unsigned long int const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ullongs_be(mk_num_basic_uint_type* x, mk_lang_ullong_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_ulllongs_be(mk_num_basic_uint_type* x, mk_lang_ulllong_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_sizets_be(mk_num_basic_uint_type* x, mk_lang_size_t const* src);
mk_lang_jumbo void mk_num_basic_uint_from_umaxts_be(mk_num_basic_uint_type* x, mk_lang_uintmax_t const* src);

mk_lang_jumbo void mk_num_basic_uint_to_uchars_be(mk_num_basic_uint_type const* x, unsigned char* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ushorts_be(mk_num_basic_uint_type const* x, unsigned short int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_uints_be(mk_num_basic_uint_type const* x, unsigned int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ulongs_be(mk_num_basic_uint_type const* x, unsigned long int* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ullongs_be(mk_num_basic_uint_type const* x, mk_lang_ullong_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_ulllongs_be(mk_num_basic_uint_type const* x, mk_lang_ulllong_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_sizets_be(mk_num_basic_uint_type const* x, mk_lang_size_t* dst);
mk_lang_jumbo void mk_num_basic_uint_to_umaxts_be(mk_num_basic_uint_type const* x, mk_lang_uintmax_t* dst);

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_basic_uint_is_zero(mk_num_basic_uint_type const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_basic_uint_eq(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_basic_uint_ne(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_basic_uint_lt(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_basic_uint_le(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_basic_uint_gt(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_basic_uint_ge(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y);

mk_lang_jumbo void mk_num_basic_uint_inc2(mk_num_basic_uint_type* x);
mk_lang_jumbo void mk_num_basic_uint_dec2(mk_num_basic_uint_type* x);
mk_lang_jumbo void mk_num_basic_uint_inc1(mk_num_basic_uint_type* x);
mk_lang_jumbo void mk_num_basic_uint_dec1(mk_num_basic_uint_type* x);

mk_lang_jumbo void mk_num_basic_uint_not2(mk_num_basic_uint_type const* x, mk_num_basic_uint_type* y);
mk_lang_jumbo void mk_num_basic_uint_not1(mk_num_basic_uint_type* x);

mk_lang_jumbo void mk_num_basic_uint_or3(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_and3(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_xor3(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_or2(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_and2(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_xor2(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);

mk_lang_jumbo void mk_num_basic_uint_shl3(mk_num_basic_uint_type const* x, int bits, mk_num_basic_uint_type* y);
mk_lang_jumbo void mk_num_basic_uint_shr3(mk_num_basic_uint_type const* x, int bits, mk_num_basic_uint_type* y);
mk_lang_jumbo void mk_num_basic_uint_shl2(mk_num_basic_uint_type* x, int bits);
mk_lang_jumbo void mk_num_basic_uint_shr2(mk_num_basic_uint_type* x, int bits);

mk_lang_jumbo void mk_num_basic_uint_add3_wrap_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_add3_wrap_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add3_wrap_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_add3_wrap_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add3_sat_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_add3_sat_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add3_sat_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_add3_sat_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add3_crash_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_add3_crash_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add3_crash_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_add3_crash_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add2_wrap_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_add2_wrap_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add2_wrap_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_basic_uint_add2_wrap_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add2_sat_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_add2_sat_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add2_sat_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_basic_uint_add2_sat_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add2_crash_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_add2_crash_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_add2_crash_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_basic_uint_add2_crash_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);

mk_lang_jumbo void mk_num_basic_uint_sub3_wrap_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_sub3_wrap_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub3_wrap_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_sub3_wrap_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub3_sat_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_sub3_sat_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub3_sat_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_sub3_sat_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub3_crash_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_sub3_crash_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub3_crash_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_sub3_crash_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub2_wrap_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_sub2_wrap_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub2_wrap_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_basic_uint_sub2_wrap_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub2_sat_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_sub2_sat_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub2_sat_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_basic_uint_sub2_sat_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub2_crash_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_sub2_crash_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co);
mk_lang_jumbo void mk_num_basic_uint_sub2_crash_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci);
mk_lang_jumbo void mk_num_basic_uint_sub2_crash_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co);

mk_lang_jumbo void mk_num_basic_uint_mul3_wrap_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_mul3_wrap_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_num_basic_uint_type* co);
mk_lang_jumbo void mk_num_basic_uint_mul3_sat_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_mul3_sat_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_num_basic_uint_type* co);
mk_lang_jumbo void mk_num_basic_uint_mul3_crash(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z);
mk_lang_jumbo void mk_num_basic_uint_mul2_wrap_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_mul2_wrap_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* co);
mk_lang_jumbo void mk_num_basic_uint_mul2_sat_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_mul2_sat_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* co);
mk_lang_jumbo void mk_num_basic_uint_mul2_crash(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);

mk_lang_jumbo void mk_num_basic_uint_div3_wrap(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res);
mk_lang_jumbo void mk_num_basic_uint_mod3_wrap(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res);
mk_lang_jumbo void mk_num_basic_uint_divmod3_wrap(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res_div, mk_num_basic_uint_type* res_mod);
mk_lang_jumbo void mk_num_basic_uint_div3_sat(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res);
mk_lang_jumbo void mk_num_basic_uint_mod3_sat(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res);
mk_lang_jumbo void mk_num_basic_uint_divmod3_sat(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res_div, mk_num_basic_uint_type* res_mod);
mk_lang_jumbo void mk_num_basic_uint_div3_crash(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res);
mk_lang_jumbo void mk_num_basic_uint_mod3_crash(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res);
mk_lang_jumbo void mk_num_basic_uint_divmod3_crash(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res_div, mk_num_basic_uint_type* res_mod);
mk_lang_jumbo void mk_num_basic_uint_div2_wrap(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_mod2_wrap(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_div2_sat(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_mod2_sat(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_div2_crash(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);
mk_lang_jumbo void mk_num_basic_uint_mod2_crash(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y);


#include "mk_num_basic_uint_undef.h"


#undef mk_num_basic_uint_type
#undef mk_num_basic_uint_name
