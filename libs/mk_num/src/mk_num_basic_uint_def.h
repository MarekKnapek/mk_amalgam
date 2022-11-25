#include "mk_lang_concat.h"


#define mk_num_set_zero mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _set_zero)
#define mk_num_set_one mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _set_one)
#define mk_num_set_mask mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _set_mask)

#define mk_num_from_char mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_char)
#define mk_num_from_uchar mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_uchar)
#define mk_num_from_schar mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_schar)
#define mk_num_from_ushort mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ushort)
#define mk_num_from_sshort mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_sshort)
#define mk_num_from_uint mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_uint)
#define mk_num_from_sint mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_sint)
#define mk_num_from_ulong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ulong)
#define mk_num_from_slong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_slong)
#define mk_num_from_ullong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ullong)
#define mk_num_from_sllong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_sllong)
#define mk_num_from_ulllong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ulllong)
#define mk_num_from_slllong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_slllong)
#define mk_num_from_sizet mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_sizet)
#define mk_num_from_umaxt mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_umaxt)
#define mk_num_from_smaxt mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_smaxt)

#define mk_num_to_char mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_char)
#define mk_num_to_uchar mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_uchar)
#define mk_num_to_schar mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_schar)
#define mk_num_to_ushort mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ushort)
#define mk_num_to_sshort mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_sshort)
#define mk_num_to_uint mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_uint)
#define mk_num_to_sint mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_sint)
#define mk_num_to_ulong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ulong)
#define mk_num_to_slong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_slong)
#define mk_num_to_ullong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ullong)
#define mk_num_to_sllong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_sllong)
#define mk_num_to_ulllong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ulllong)
#define mk_num_to_slllong mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_slllong)
#define mk_num_to_sizet mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_sizet)
#define mk_num_to_umaxt mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_umaxt)
#define mk_num_to_smaxt mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_smaxt)

#define mk_num_from_uchars_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_uchars_le)
#define mk_num_from_ushorts_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ushorts_le)
#define mk_num_from_uints_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_uints_le)
#define mk_num_from_ulongs_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ulongs_le)
#define mk_num_from_ullongs_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ullongs_le)
#define mk_num_from_ulllongs_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ulllongs_le)
#define mk_num_from_sizets_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_sizets_le)
#define mk_num_from_umaxts_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_umaxts_le)

#define mk_num_to_uchars_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_uchars_le)
#define mk_num_to_ushorts_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ushorts_le)
#define mk_num_to_uints_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_uints_le)
#define mk_num_to_ulongs_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ulongs_le)
#define mk_num_to_ullongs_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ullongs_le)
#define mk_num_to_ulllongs_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ulllongs_le)
#define mk_num_to_sizets_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_sizets_le)
#define mk_num_to_umaxts_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_umaxts_le)

#define mk_num_from_uchars_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_uchars_be)
#define mk_num_from_ushorts_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ushorts_be)
#define mk_num_from_uints_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_uints_be)
#define mk_num_from_ulongs_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ulongs_be)
#define mk_num_from_ullongs_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ullongs_be)
#define mk_num_from_ulllongs_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_ulllongs_be)
#define mk_num_from_sizets_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_sizets_be)
#define mk_num_from_umaxts_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _from_umaxts_be)

#define mk_num_to_uchars_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_uchars_be)
#define mk_num_to_ushorts_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ushorts_be)
#define mk_num_to_uints_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_uints_be)
#define mk_num_to_ulongs_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ulongs_be)
#define mk_num_to_ullongs_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ullongs_be)
#define mk_num_to_ulllongs_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_ulllongs_be)
#define mk_num_to_sizets_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_sizets_be)
#define mk_num_to_umaxts_be mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _to_umaxts_be)

#define mk_num_is_zero mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _is_zero)
#define mk_num_eq mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _eq)
#define mk_num_ne mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _ne)
#define mk_num_lt mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _lt)
#define mk_num_le mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _le)
#define mk_num_gt mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _gt)
#define mk_num_ge mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _ge)

#define mk_num_inc2 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _inc2)
#define mk_num_dec2 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _dec2)
#define mk_num_inc1 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _inc1)
#define mk_num_dec1 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _dec1)

#define mk_num_not2 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _not2)
#define mk_num_not1 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _not1)
#define mk_num_or3 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _or3)
#define mk_num_or2 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _or2)
#define mk_num_and3 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _and3)
#define mk_num_and2 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _and2)
#define mk_num_xor3 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _xor3)
#define mk_num_xor2 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _xor2)

#define mk_num_shl3 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _shl3)
#define mk_num_shl2 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _shl2)
#define mk_num_shr3 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _shr3)
#define mk_num_shr2 mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _shr2)

#define mk_num_add3_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_wrap_cid_cod)
#define mk_num_add3_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_wrap_cid_coe)
#define mk_num_add3_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_wrap_cie_cod)
#define mk_num_add3_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_wrap_cie_coe)
#define mk_num_add3_sat_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_sat_cid_cod)
#define mk_num_add3_sat_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_sat_cid_coe)
#define mk_num_add3_sat_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_sat_cie_cod)
#define mk_num_add3_sat_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_sat_cie_coe)
#define mk_num_add3_crash_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_crash_cid_cod)
#define mk_num_add3_crash_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_crash_cid_coe)
#define mk_num_add3_crash_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_crash_cie_cod)
#define mk_num_add3_crash_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add3_crash_cie_coe)
#define mk_num_add2_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_wrap_cid_cod)
#define mk_num_add2_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_wrap_cid_coe)
#define mk_num_add2_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_wrap_cie_cod)
#define mk_num_add2_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_wrap_cie_coe)
#define mk_num_add2_sat_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_sat_cid_cod)
#define mk_num_add2_sat_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_sat_cid_coe)
#define mk_num_add2_sat_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_sat_cie_cod)
#define mk_num_add2_sat_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_sat_cie_coe)
#define mk_num_add2_crash_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_crash_cid_cod)
#define mk_num_add2_crash_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_crash_cid_coe)
#define mk_num_add2_crash_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_crash_cie_cod)
#define mk_num_add2_crash_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _add2_crash_cie_coe)

#define mk_num_sub3_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_wrap_cid_cod)
#define mk_num_sub3_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_wrap_cid_coe)
#define mk_num_sub3_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_wrap_cie_cod)
#define mk_num_sub3_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_wrap_cie_coe)
#define mk_num_sub3_sat_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_sat_cid_cod)
#define mk_num_sub3_sat_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_sat_cid_coe)
#define mk_num_sub3_sat_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_sat_cie_cod)
#define mk_num_sub3_sat_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_sat_cie_coe)
#define mk_num_sub3_crash_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_crash_cid_cod)
#define mk_num_sub3_crash_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_crash_cid_coe)
#define mk_num_sub3_crash_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_crash_cie_cod)
#define mk_num_sub3_crash_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub3_crash_cie_coe)
#define mk_num_sub2_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_wrap_cid_cod)
#define mk_num_sub2_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_wrap_cid_coe)
#define mk_num_sub2_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_wrap_cie_cod)
#define mk_num_sub2_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_wrap_cie_coe)
#define mk_num_sub2_sat_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_sat_cid_cod)
#define mk_num_sub2_sat_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_sat_cid_coe)
#define mk_num_sub2_sat_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_sat_cie_cod)
#define mk_num_sub2_sat_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_sat_cie_coe)
#define mk_num_sub2_crash_cid_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_crash_cid_cod)
#define mk_num_sub2_crash_cid_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_crash_cid_coe)
#define mk_num_sub2_crash_cie_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_crash_cie_cod)
#define mk_num_sub2_crash_cie_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _sub2_crash_cie_coe)

#define mk_num_mul3_wrap_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul3_wrap_cod)
#define mk_num_mul3_wrap_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul3_wrap_coe)
#define mk_num_mul3_sat_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul3_sat_cod)
#define mk_num_mul3_sat_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul3_sat_coe)
#define mk_num_mul3_crash mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul3_crash)
#define mk_num_mul2_wrap_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul2_wrap_cod)
#define mk_num_mul2_wrap_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul2_wrap_coe)
#define mk_num_mul2_sat_cod mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul2_sat_cod)
#define mk_num_mul2_sat_coe mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul2_sat_coe)
#define mk_num_mul2_crash mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mul2_crash)

#define mk_num_div3_wrap mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _div3_wrap)
#define mk_num_mod3_wrap mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mod3_wrap)
#define mk_num_divmod3_wrap mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _divmod3_wrap)
#define mk_num_div3_sat mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _div3_sat)
#define mk_num_mod3_sat mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mod3_sat)
#define mk_num_divmod3_sat mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _divmod3_sat)
#define mk_num_div3_crash mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _div3_crash)
#define mk_num_mod3_crash mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mod3_crash)
#define mk_num_divmod3_crash mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _divmod3_crash)
#define mk_num_div2_wrap mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _div2_wrap)
#define mk_num_mod2_wrap mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mod2_wrap)
#define mk_num_div2_sat mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _div2_sat)
#define mk_num_mod2_sat mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mod2_sat)
#define mk_num_div2_crash mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _div2_crash)
#define mk_num_mod2_crash mk_lang_concat(mk_lang_concat(mk_num_basic_, mk_num_basic_uint_name), _mod2_crash)
