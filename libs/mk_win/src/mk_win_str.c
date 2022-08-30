#include "mk_win_str.h"


#include "mk_win_char.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_platform.h"

#include "../../mk_std/src/mk_std_str_convertor.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


mk_jumbo int mk_win_str_get_len(mk_win_strc_t str, size_t* len)
{
	size_t n;

	n = 0;
	if(str)
	{
		while(*str++) ++n;
	}
	*len = n;

	return 0;
}

mk_jumbo int mk_win_str_to_wide_z(mk_win_strc_t in, int idx, wchar_t const** out)
{
	#if mk_win_char == mk_win_char_narrow
	mk_try(mk_std_str_convertor_narrow_to_wide_z(in, idx, out));
	#elif mk_win_char == mk_win_char_wide
	(void)idx;
	*out = in;
	#endif
	return 0;
}

mk_jumbo int mk_win_str_to_narrow_z(mk_win_strc_t in, int idx, char const mk_win_base_keywords_far** out)
{
	#if mk_win_char == mk_win_char_narrow
	(void)idx;
	*out = in;
	#elif mk_win_char == mk_win_char_wide
	mk_try(mk_std_str_convertor_wide_to_narrow_z(in, idx, out));
	#endif
	return 0;
}

mk_jumbo int mk_win_str_from_wide_z(wchar_t const* in, int idx, mk_win_strc_t* out)
{
	#if mk_win_char == mk_win_char_narrow
	mk_try(mk_std_str_convertor_wide_to_narrow_z(in, idx, out));
	#elif mk_win_char == mk_win_char_wide
	(void)idx;
	*out = in;
	#endif
	return 0;
}

mk_jumbo int mk_win_str_from_narrow_z(char const mk_win_base_keywords_far* in, int idx, mk_win_strc_t* out)
{
	#if mk_win_char == mk_win_char_narrow && mk_win_base_platform_os == mk_win_base_platform_os_win16
	mk_try(mk_std_str_convertor_narrow_to_narrow_z(in, idx, out));
	#elif mk_win_char == mk_win_char_narrow && mk_win_base_platform_os != mk_win_base_platform_os_win16
	(void)idx;
	*out = in;
	#elif mk_win_char == mk_win_char_wide
	mk_try(mk_std_str_convertor_narrow_to_wide_z(in, idx, out));
	#endif
	return 0;
}


mk_jumbo int mk_win_str_to_wide_zz(mk_win_strc_t in, int idx, wchar_t const** out)
{
	#if mk_win_char == mk_win_char_narrow
	mk_try(mk_std_str_convertor_narrow_to_wide_zz(in, idx, out));
	#elif mk_win_char == mk_win_char_wide
	(void)idx;
	*out = in;
	#endif
	return 0;
}

mk_jumbo int mk_win_str_to_narrow_zz(mk_win_strc_t in, int idx, char const mk_win_base_keywords_far** out)
{
	#if mk_win_char == mk_win_char_narrow
	(void)idx;
	*out = in;
	#elif mk_win_char == mk_win_char_wide
	mk_try(mk_std_str_convertor_wide_to_narrow_zz(in, idx, out));
	#endif
	return 0;
}

mk_jumbo int mk_win_str_from_wide_zz(wchar_t const* in, int idx, mk_win_strc_t* out)
{
	#if mk_win_char == mk_win_char_narrow
	mk_try(mk_std_str_convertor_wide_to_narrow_zz(in, idx, out));
	#elif mk_win_char == mk_win_char_wide
	(void)idx;
	*out = in;
	#endif
	return 0;
}

mk_jumbo int mk_win_str_from_narrow_zz(char const mk_win_base_keywords_far* in, int idx, mk_win_strc_t* out)
{
	#if mk_win_char == mk_win_char_narrow && mk_win_base_platform_os == mk_win_base_platform_os_win16
	mk_try(mk_std_str_convertor_narrow_to_narrow_zz(in, idx, out));
	#elif mk_win_char == mk_win_char_narrow && mk_win_base_platform_os != mk_win_base_platform_os_win16
	(void)idx;
	*out = in;
	#elif mk_win_char == mk_win_char_wide
	mk_try(mk_std_str_convertor_narrow_to_wide_zz(in, idx, out));
	#endif
	return 0;
}


mk_jumbo int mk_win_str_to_wide_s(mk_win_strc_t in, size_t length, int idx, wchar_t const** out)
{
	#if mk_win_char == mk_win_char_narrow
	mk_try(mk_std_str_convertor_narrow_to_wide_s(in, length, idx, out));
	#elif mk_win_char == mk_win_char_wide
	(void)length;
	(void)idx;
	*out = in;
	#endif
	return 0;
}

mk_jumbo int mk_win_str_to_narrow_s(mk_win_strc_t in, size_t length, int idx, char const mk_win_base_keywords_far** out)
{
	#if mk_win_char == mk_win_char_narrow
	(void)length;
	(void)idx;
	*out = in;
	#elif mk_win_char == mk_win_char_wide
	mk_try(mk_std_str_convertor_wide_to_narrow_s(in, length, idx, out));
	#endif
	return 0;
}

mk_jumbo int mk_win_str_from_wide_s(wchar_t const* in, size_t length, int idx, mk_win_strc_t* out)
{
	#if mk_win_char == mk_win_char_narrow
	mk_try(mk_std_str_convertor_wide_to_narrow_s(in, length, idx, out));
	#elif mk_win_char == mk_win_char_wide
	(void)idx;
	(void)length;
	*out = in;
	#endif
	return 0;
}

mk_jumbo int mk_win_str_from_narrow_s(char const mk_win_base_keywords_far* in, size_t length, int idx, mk_win_strc_t* out)
{
	#if mk_win_char == mk_win_char_narrow && mk_win_base_platform_os == mk_win_base_platform_os_win16
	mk_try(mk_std_str_convertor_narrow_to_narrow_s(in, length, idx, out));
	#elif mk_win_char == mk_win_char_narrow && mk_win_base_platform_os != mk_win_base_platform_os_win16
	(void)length;
	(void)idx;
	*out = in;
	#elif mk_win_char == mk_win_char_wide
	mk_try(mk_std_str_convertor_narrow_to_wide_s(in, length, idx, out));
	#endif
	return 0;
}
