#include "mk_win_comctl_statusbar.h"

#include "mk_win_api.h"
#include "mk_win_char.h"
#include "mk_win_str.h"
#include "mk_win_user_window.h"
#include "mk_win_unicode.h"

#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo int mk_win_comctl_statusbar_set_text(mk_win_base_user_types_hwnd_t statusbar, unsigned short int part_idx, unsigned short int drawing_operation, mk_win_strc_t text)
{
	#if mk_win_api == mk_win_api_old
	#define charm char
	#define mk_win_comctl_statusbar_wm_settextm mk_win_comctl_statusbar_wm_settexta
	#elif mk_win_api == mk_win_api_ansi
	#define charm char
	#define mk_win_comctl_statusbar_wm_settextm mk_win_comctl_statusbar_wm_settexta
	#elif mk_win_api == mk_win_api_wide
	#define charm wchar_t
	#define mk_win_comctl_statusbar_wm_settextm mk_win_comctl_statusbar_wm_settextw
	#elif mk_win_api == mk_win_api_both
	#endif

	#if mk_win_api != mk_win_api_both
	charm const* txt;
	mk_win_base_user_types_lresult_t lr;
	mk_assert(statusbar);
	mk_assert((part_idx >> 8) == 0);
	mk_assert((drawing_operation & 0xfful) == 0);
	mk_assert(text);
	mk_try(mk_win_str_to_api_z(text, 0, &txt));
	mk_try(mk_win_user_window_send(statusbar, mk_win_comctl_statusbar_wm_settextm, ((mk_win_base_user_types_lparam_t)(part_idx | drawing_operation)), ((mk_win_base_user_types_lparam_t)(((mk_win_base_types_void_lpt)(txt)))), &lr));
	mk_assert(lr != 0);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		char const* txt;
		mk_win_base_user_types_lresult_t lr;
		mk_assert(statusbar);
		mk_assert((part_idx >> 8) == 0);
		mk_assert((drawing_operation & 0xfful) == 0);
		mk_assert(text);
		mk_try(mk_win_str_to_narrow_z(text, 0, &txt));
		mk_try(mk_win_user_window_send(statusbar, mk_win_comctl_statusbar_wm_settexta, ((mk_win_base_user_types_lparam_t)(part_idx | drawing_operation)), ((mk_win_base_user_types_lparam_t)(((mk_win_base_types_char_lpt)(txt)))), &lr));
		mk_assert(lr != 0);
	}
	else
	{
		wchar_t const* txt;
		mk_win_base_user_types_lresult_t lr;
		mk_assert(statusbar);
		mk_assert((part_idx >> 8) == 0);
		mk_assert((drawing_operation & 0xfful) == 0);
		mk_assert(text);
		mk_try(mk_win_str_to_wide_z(text, 0, &txt));
		mk_try(mk_win_user_window_send(statusbar, mk_win_comctl_statusbar_wm_settextw, ((mk_win_base_user_types_lparam_t)(part_idx | drawing_operation)), ((mk_win_base_user_types_lparam_t)(((mk_win_base_types_wchar_lpt)(txt)))), &lr));
		mk_assert(lr != 0);
	}
	#endif
	return 0;

	#undef charm
	#undef mk_win_comctl_statusbar_wm_settextm
}
