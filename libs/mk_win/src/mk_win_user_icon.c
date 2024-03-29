#include "mk_win_user_icon.h"

#include "mk_win_str.h"
#include "mk_win_unicode.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_user_functions.h"

#include <stddef.h>


mk_jumbo int mk_win_user_icon_load_by_name(mk_win_base_types_hinstance_t instance, mk_win_strc_t name, mk_win_base_user_types_hicon_t* icon)
{
	#if mk_win_api == mk_win_api_old
	#define LoadIconM LoadIcon
	#elif mk_win_api == mk_win_api_ansi
	#define LoadIconM LoadIconA
	#elif mk_win_api == mk_win_api_wide
	#define LoadIconM LoadIconW
	#endif

	mk_win_base_user_types_hicon_t i;
	#if mk_win_api != mk_win_api_both
	mk_win_api_char_t const mk_win_base_keywords_far* name_m;
	mk_try(mk_win_str_to_api_z(name, 0, &name_m));
	i = LoadIconM(instance, name_m);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		char const* name_a;
		mk_try(mk_win_str_to_narrow_z(name, 0, &name_a));
		i = LoadIconA(instance, name_a);
	}
	else
	{
		wchar_t const* name_w;
		mk_try(mk_win_str_to_wide_z(name, 0, &name_w));
		i = LoadIconW(instance, name_w);
	}
	#endif
	mk_assert(icon);
	*icon = i;
	return 0;

	#undef LoadIconM
}

mk_jumbo int mk_win_user_icon_load_by_id(unsigned short id, mk_win_base_user_types_hicon_t* icon)
{
	#if mk_win_api == mk_win_api_old
	#define LoadIconA LoadIcon
	#endif

	mk_win_base_user_types_hicon_t i;
	#if mk_win_api == mk_win_api_old || mk_win_api == mk_win_api_ansi
	i = LoadIconA(((mk_win_base_types_hinstance_t)(mk_win_base_types_null)), mk_win_base_user_functions_make_int_resource_a(id));
	#elif mk_win_api == mk_win_api_wide
	i = LoadIconW(((mk_win_base_types_hinstance_t)(mk_win_base_types_null)), mk_win_base_user_functions_make_int_resource_w(id));
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		i = LoadIconA(((mk_win_base_types_hinstance_t)(mk_win_base_types_null)), mk_win_base_user_functions_make_int_resource_a(id));
	}
	else
	{
		i = LoadIconW(((mk_win_base_types_hinstance_t)(mk_win_base_types_null)), mk_win_base_user_functions_make_int_resource_w(id));
	}
	#endif
	mk_assert(icon);
	*icon = i;
	return 0;

	#undef LoadIconM
}
