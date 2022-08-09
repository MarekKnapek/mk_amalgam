#include "mk_win_user_cursor.h"

#include "mk_win_str.h"
#include "mk_win_unicode.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win_base/src/mk_win_base_user_functions.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_keywords.h"

#include <stddef.h>


mk_jumbo int mk_win_user_cursor_load_by_name(mk_win_base_types_hinstance_t instance, mk_win_strc_t name, mk_win_base_user_types_hcursor_t* cursor)
{
	#if mk_win_api == mk_win_api_old
	#define LoadCursorM LoadCursor
	#elif mk_win_api == mk_win_api_ansi
	#define LoadCursorM LoadCursorA
	#elif mk_win_api == mk_win_api_wide
	#define LoadCursorM LoadCursorW
	#endif

	mk_win_base_user_types_hcursor_t i;
	#if mk_win_api != mk_win_api_both
	mk_win_api_char_t const mk_win_base_keywords_far* name_m;
	mk_try(mk_win_str_to_api_z(name, 0, &name_m));
	i = LoadCursorM(instance, name_m);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		char const* name_a;
		mk_try(mk_win_str_to_narrow_z(name, 0, &name_a));
		i = LoadCursorA(instance, name_a);
	}
	else
	{
		wchar_t const* name_w;
		mk_try(mk_win_str_to_wide_z(name, 0, &name_w));
		i = LoadCursorW(instance, name_w);
	}
	#endif
	mk_assert(cursor);
	*cursor = i;
	return 0;

	#undef LoadCursorM
}

mk_jumbo int mk_win_user_cursor_load_by_id(unsigned short id, mk_win_base_user_types_hcursor_t* cursor)
{
	#if mk_win_api == mk_win_api_old
	#define LoadCursorA LoadCursor
	#endif

	mk_win_base_user_types_hcursor_t i;
	#if mk_win_api == mk_win_api_old || mk_win_api == mk_win_api_ansi
	i = LoadCursorA(NULL, mk_win_base_user_functions_make_int_resource_a(id));
	#elif mk_win_api == mk_win_api_wide
	i = LoadCursorW(NULL, mk_win_base_user_functions_make_int_resource_w(id));
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		i = LoadCursorA(NULL, mk_win_base_user_functions_make_int_resource_a(id));
	}
	else
	{
		i = LoadCursorW(NULL, mk_win_base_user_functions_make_int_resource_w(id));
	}
	#endif
	mk_assert(cursor);
	*cursor = i;
	return 0;

	#undef LoadCursorM
}
