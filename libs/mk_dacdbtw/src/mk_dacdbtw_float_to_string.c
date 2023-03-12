#include "mk_dacdbtw_float_to_string.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"


#if defined NDEBUG
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4701) /* warning C4701: potentially uninitialized local variable 'xxx' used */
#endif
#define mk_lang_jumbo_want 1
#define mk_sl_flt_name double
#define mk_sl_flt_bits 64
#define mk_sl_flt_fraction_bits 52
#include "../../../3rdparty/mk_clib/mk_clib/src/mk_sl_flt_inl_fileh.h"
#include "../../../3rdparty/mk_clib/mk_clib/src/mk_sl_flt_inl_filec.h"
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
#else
#include <stdio.h>
#endif


mk_jumbo int mk_dacdbtw_float_to_string_get_max_size(void)
{
#if defined NDEBUG
	return mk_sl_flt_double_to_string_dec_basic_len_v;
#else
	return 256;
#endif
}

mk_jumbo int mk_dacdbtw_float_to_string_get_string(double const* const flt, char* const str, int const str_len)
{
#if defined NDEBUG
	int r;

	mk_assert(flt);
	mk_assert(str);
	mk_assert(str_len >= mk_sl_flt_double_to_string_dec_basic_len_v);

	r = mk_sl_flt_double_to_string_dec_basic_n(flt, str, str_len);
	mk_assert(r > 0 && r <= mk_sl_flt_double_to_string_dec_basic_len_v);
	return r;
#else
	int r;

	mk_assert(flt);
	mk_assert(str);
	mk_assert(str_len >= 256);

	r = sprintf(str, "%g", *flt);
	mk_assert(r > 0);
	return r;
#endif
}
