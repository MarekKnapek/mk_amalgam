#include "mk_win_user_window.h"

#include "mk_win_api.h"
#include "mk_win_unicode.h"
#include "mk_win_user_message.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_platform.h"
#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_user_functions.h"


mk_jumbo int mk_win_user_window_create(mk_win_user_window_create_pct wnd_info, mk_win_base_user_types_hwnd_t* hwnd)
{
	#if mk_win_api == mk_win_api_old
	#define CreateWindowExM CreateWindowEx
	#elif mk_win_api == mk_win_api_ansi
	#define CreateWindowExM CreateWindowExA
	#elif mk_win_api == mk_win_api_wide
	#define CreateWindowExM CreateWindowExW
	#endif

	mk_win_base_user_types_hwnd_t ret;
	#if mk_win_api != mk_win_api_both
	mk_win_api_char_t const mk_win_base_keywords_far* class_name_m;
	mk_win_api_char_t const mk_win_base_keywords_far* window_name_m;
	mk_try(mk_win_str_to_api_z(wnd_info->m_class_name, 0, &class_name_m));
	mk_try(mk_win_str_to_api_z(wnd_info->m_window_name, 1, &window_name_m));
	ret = CreateWindowExM(wnd_info->m_extra_style, class_name_m, window_name_m, wnd_info->m_style, wnd_info->m_x, wnd_info->m_y, wnd_info->m_width, wnd_info->m_height, wnd_info->m_parent, wnd_info->m_menu, wnd_info->m_instance, wnd_info->m_param);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		char const* class_name_a;
		char const* window_name_a;
		mk_try(mk_win_str_to_narrow_z(wnd_info->m_class_name, 0, &class_name_a));
		mk_try(mk_win_str_to_narrow_z(wnd_info->m_window_name, 1, &window_name_a));
		ret = CreateWindowExA(wnd_info->m_extra_style, class_name_a, window_name_a, wnd_info->m_style, wnd_info->m_x, wnd_info->m_y, wnd_info->m_width, wnd_info->m_height, wnd_info->m_parent, wnd_info->m_menu, wnd_info->m_instance, wnd_info->m_param);
	}
	else
	{
		wchar_t const* class_name_w;
		wchar_t const* window_name_w;
		mk_try(mk_win_str_to_wide_z(wnd_info->m_class_name, 0, &class_name_w));
		mk_try(mk_win_str_to_wide_z(wnd_info->m_window_name, 1, &window_name_w));
		ret = CreateWindowExW(wnd_info->m_extra_style, class_name_w, window_name_w, wnd_info->m_style, wnd_info->m_x, wnd_info->m_y, wnd_info->m_width, wnd_info->m_height, wnd_info->m_parent, wnd_info->m_menu, wnd_info->m_instance, wnd_info->m_param);
	}
	#endif
	mk_assert(hwnd);
	*hwnd = ret;
	return 0;
	#undef CreateWindowExM
}

mk_jumbo int mk_win_user_window_set_info(mk_win_base_user_types_hwnd_t hwnd, int info_id, mk_win_base_types_uintptr_t info, mk_win_base_types_uintptr_t* prev_info)
{
	#if mk_win_api == mk_win_api_old
	#define SetWindowLongM SetWindowLong
	#elif mk_win_api == mk_win_api_ansi && mk_win_base_platform_os != mk_win_base_platform_os_win64
	#define SetWindowLongM SetWindowLongA
	#elif mk_win_api == mk_win_api_ansi && mk_win_base_platform_os == mk_win_base_platform_os_win64
	#define SetWindowLongM SetWindowLongPtrA
	#elif mk_win_api == mk_win_api_wide && mk_win_base_platform_os != mk_win_base_platform_os_win64
	#define SetWindowLongM SetWindowLongW
	#elif mk_win_api == mk_win_api_wide && mk_win_base_platform_os == mk_win_base_platform_os_win64
	#define SetWindowLongM SetWindowLongPtrW
	#elif mk_win_api == mk_win_api_both && mk_win_base_platform_os != mk_win_base_platform_os_win64
	#define SetWindowLongMA SetWindowLongA
	#define SetWindowLongMW SetWindowLongW
	#elif mk_win_api == mk_win_api_both && mk_win_base_platform_os == mk_win_base_platform_os_win64
	#define SetWindowLongMA SetWindowLongPtrA
	#define SetWindowLongMW SetWindowLongPtrW
	#endif

	mk_win_base_types_uintptr_t prev;
	#if mk_win_api != mk_win_api_both
	prev = SetWindowLongM(hwnd, info_id, info);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		prev = SetWindowLongMA(hwnd, info_id, info);
	}
	else
	{
		prev = SetWindowLongMW(hwnd, info_id, info);
	}
	#endif
	mk_assert(prev_info);
	*prev_info = prev;
	return 0;

	#undef SetWindowLongM
	#undef SetWindowLongMA
	#undef SetWindowLongMW
}

mk_jumbo int mk_win_user_window_get_info(mk_win_base_user_types_hwnd_t hwnd, int info_id, mk_win_base_types_uintptr_t* info)
{
	#if mk_win_api == mk_win_api_old
	#define GetWindowLongM GetWindowLong
	#elif mk_win_api == mk_win_api_ansi && mk_win_base_platform_os != mk_win_base_platform_os_win64
	#define GetWindowLongM GetWindowLongA
	#elif mk_win_api == mk_win_api_ansi && mk_win_base_platform_os == mk_win_base_platform_os_win64
	#define GetWindowLongM GetWindowLongPtrA
	#elif mk_win_api == mk_win_api_wide && mk_win_base_platform_os != mk_win_base_platform_os_win64
	#define GetWindowLongM GetWindowLongW
	#elif mk_win_api == mk_win_api_wide && mk_win_base_platform_os == mk_win_base_platform_os_win64
	#define GetWindowLongM GetWindowLongPtrW
	#elif mk_win_api == mk_win_api_both && mk_win_base_platform_os != mk_win_base_platform_os_win64
	#define GetWindowLongMA GetWindowLongA
	#define GetWindowLongMW GetWindowLongW
	#elif mk_win_api == mk_win_api_both && mk_win_base_platform_os == mk_win_base_platform_os_win64
	#define GetWindowLongMA GetWindowLongPtrA
	#define GetWindowLongMW GetWindowLongPtrW
	#endif

	mk_win_base_types_uintptr_t nfo;
	#if mk_win_api != mk_win_api_both
	nfo = GetWindowLongM(hwnd, info_id);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		nfo = GetWindowLongMA(hwnd, info_id);
	}
	else
	{
		nfo = GetWindowLongMW(hwnd, info_id);
	}
	#endif
	mk_assert(info);
	*info = nfo;
	return 0;

	#undef SetWindowLongM
	#undef SetWindowLongMA
	#undef SetWindowLongMW
}

mk_jumbo int mk_win_user_window_defproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres)
{
	#if mk_win_api == mk_win_api_old
	#define DefWindowProcM DefWindowProc
	#elif mk_win_api == mk_win_api_ansi
	#define DefWindowProcM DefWindowProcA
	#elif mk_win_api == mk_win_api_wide
	#define DefWindowProcM DefWindowProcW
	#endif

	mk_win_base_user_types_lresult_t lr;
	#if mk_win_api != mk_win_api_both
	lr = DefWindowProcM(hwnd, msg, wparam, lparam);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		lr = DefWindowProcA(hwnd, msg, wparam, lparam);
	}
	else
	{
		lr = DefWindowProcW(hwnd, msg, wparam, lparam);
	}
	#endif
	mk_assert(lres);
	*lres = lr;
	return 0;

	#undef DefWindowProcM
}

mk_jumbo int mk_win_user_window_defframeproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_hwnd_t mdi, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres)
{
	#if mk_win_api == mk_win_api_old
	#define DefFrameProcM DefFrameProc
	#elif mk_win_api == mk_win_api_ansi
	#define DefFrameProcM DefFrameProcA
	#elif mk_win_api == mk_win_api_wide
	#define DefFrameProcM DefFrameProcW
	#endif

	mk_win_base_user_types_lresult_t lr;
	#if mk_win_api != mk_win_api_both
	lr = DefFrameProcM(hwnd, mdi, msg, wparam, lparam);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		lr = DefFrameProcA(hwnd, mdi, msg, wparam, lparam);
	}
	else
	{
		lr = DefFrameProcW(hwnd, mdi, msg, wparam, lparam);
	}
	#endif
	mk_assert(lres);
	*lres = lr;
	return 0;

	#undef DefFrameProcM
}

mk_jumbo int mk_win_user_window_defmdichildproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres)
{
	#if mk_win_api == mk_win_api_old
	#define DefMDIChildProcM DefMDIChildProc
	#elif mk_win_api == mk_win_api_ansi
	#define DefMDIChildProcM DefMDIChildProcA
	#elif mk_win_api == mk_win_api_wide
	#define DefMDIChildProcM DefMDIChildProcW
	#endif
	
	mk_win_base_user_types_lresult_t lr;
	#if mk_win_api != mk_win_api_both
	lr = DefMDIChildProcM(hwnd, msg, wparam, lparam);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		lr = DefMDIChildProcA(hwnd, msg, wparam, lparam);
	}
	else
	{
		lr = DefMDIChildProcW(hwnd, msg, wparam, lparam);
	}
	#endif
	mk_assert(lres);
	*lres = lr;
	return 0;

	#undef DefMDIChildProcM
}

mk_jumbo int mk_win_user_window_show(mk_win_base_user_types_hwnd_t hwnd, int show, mk_win_base_types_bool_t* ret)
{
	mk_win_base_types_bool_t b;

	mk_assert(ret);

	b = ShowWindow(hwnd, show);
	*ret = b;

	return 0;
}

mk_jumbo int mk_win_user_window_move(mk_win_base_user_types_hwnd_t hwnd, int x, int y, int width, int height, mk_win_base_types_bool_t repaint, mk_win_base_types_bool_t* ret)
{
	mk_win_base_types_bool_t b;

	mk_assert(ret);

	b = MoveWindow(hwnd, x, y, width, height, repaint);
	*ret = b;

	return 0;
}

mk_jumbo int mk_win_user_window_get_rect(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_rect_pt rect, mk_win_base_types_bool_t* ret)
{
	mk_win_base_types_bool_t b;

	mk_assert(ret);

#if mk_win_api == mk_win_api_old
	GetWindowRect(hwnd, rect);
	b = 1;
	#else
	b = GetWindowRect(hwnd, rect);
	#endif
	*ret = b;

	return 0;
}

mk_jumbo int mk_win_user_window_get_client_rect(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_rect_pt rect, mk_win_base_types_bool_t* ret)
{
	mk_win_base_types_bool_t b;

	mk_assert(ret);

#if mk_win_api == mk_win_api_old
	GetClientRect(hwnd, rect);
	b = 1;
	#else
	b = GetClientRect(hwnd, rect);
	#endif
	*ret = b;

	return 0;
}

mk_jumbo int mk_win_user_window_set_focus(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_hwnd_t* ret)
{
	mk_win_base_user_types_hwnd_t h;

	mk_assert(ret);

	h = SetFocus(hwnd);
	*ret = h;

	return 0;
}

mk_jumbo int mk_win_user_window_set_parent(mk_win_base_user_types_hwnd_t child, mk_win_base_user_types_hwnd_t new_parent, mk_win_base_user_types_hwnd_t* ret)
{
	mk_win_base_user_types_hwnd_t w;

	mk_assert(ret);

	w = SetParent(child, new_parent);
	*ret = w;

	return 0;
}

mk_jumbo int mk_win_user_window_post(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_types_bool_t* ret)
{
	#if mk_win_api == mk_win_api_old
	#define PostMessageM PostMessage
	#elif mk_win_api == mk_win_api_ansi
	#define PostMessageM PostMessageA
	#elif mk_win_api == mk_win_api_wide
	#define PostMessageM PostMessageW
	#endif
	mk_win_base_types_bool_t b;
	#if mk_win_api != mk_win_api_both
	b = PostMessageM(hwnd, msg, wparam, lparam);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		b = PostMessageA(hwnd, msg, wparam, lparam);
	}
	else
	{
		b = PostMessageW(hwnd, msg, wparam, lparam);
	}
	#endif
	mk_assert(ret);
	*ret = b;
	return 0;
	#undef PostMessageM
}

mk_jumbo int mk_win_user_window_send(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* ret)
{
	#if mk_win_api == mk_win_api_old
	#define SendMessageM SendMessage
	#elif mk_win_api == mk_win_api_ansi
	#define SendMessageM SendMessageA
	#elif mk_win_api == mk_win_api_wide
	#define SendMessageM SendMessageW
	#endif
	mk_win_base_user_types_lresult_t r;
	#if mk_win_api != mk_win_api_both
	r = SendMessageM(hwnd, msg, wparam, lparam);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		r = SendMessageA(hwnd, msg, wparam, lparam);
	}
	else
	{
		r = SendMessageW(hwnd, msg, wparam, lparam);
	}
	#endif
	mk_assert(ret);
	*ret = r;
	return 0;
	#undef SendMessageM
}

mk_jumbo int mk_win_user_window_is_child(mk_win_base_user_types_hwnd_t parent, mk_win_base_user_types_hwnd_t child, mk_win_base_types_bool_t* ret)
{
	mk_win_base_types_bool_t b;

	mk_assert(ret);

	b = IsChild(parent, child);
	*ret = b;

	return 0;
}

mk_jumbo int mk_win_user_window_is_screen2client(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_point_pt pt, mk_win_base_types_bool_t* ret)
{
	mk_win_base_types_bool_t b;

	mk_assert(ret);

#if mk_win_api == mk_win_api_old
	ScreenToClient(hwnd, pt);
	b = 1;
	#else
	b = ScreenToClient(hwnd, pt);
	#endif
	*ret = b;

	return 0;
}


mk_jumbo int mk_win_user_window_post_close(mk_win_base_user_types_hwnd_t hwnd)
{
	mk_win_base_types_bool_t b;

	mk_try(mk_win_user_window_post(hwnd, mk_win_user_window_wm_close, 0, 0, &b));

	return 0;
}


mk_jumbo int mk_win_user_window_send_close(mk_win_base_user_types_hwnd_t hwnd)
{
	mk_win_base_user_types_lresult_t r;

	mk_try(mk_win_user_window_send(hwnd, mk_win_user_window_wm_close, 0, 0, &r));
	(void)r;

	return 0;
}

mk_jumbo int mk_win_user_window_send_mdicreate(mk_win_base_user_types_hwnd_t hwnd, mk_win_user_window_mdicreate_pct mdi, mk_win_base_user_types_hwnd_t* mdihwnd)
{
	#if mk_win_api == mk_win_api_old
	#define mk_win_base_user_wm_mdicreate_m_t mk_win_base_user_wm_mdicreate_a_t
	#define mk_win_str_to_m_z mk_win_str_to_narrow_z
	#elif mk_win_api == mk_win_api_ansi
	#define mk_win_base_user_wm_mdicreate_m_t mk_win_base_user_wm_mdicreate_a_t
	#define mk_win_str_to_m_z mk_win_str_to_narrow_z
	#elif mk_win_api == mk_win_api_wide
	#define mk_win_base_user_wm_mdicreate_m_t mk_win_base_user_wm_mdicreate_w_t
	#define mk_win_str_to_m_z mk_win_str_to_wide_z
	#endif
	#if mk_win_api != mk_win_api_both
	mk_win_base_user_wm_mdicreate_m_t wmdi;
	mk_win_base_user_types_lresult_t lres;
	mk_try(mk_win_str_to_m_z(mdi->m_class_name, 0, &wmdi.m_class_name));
	mk_try(mk_win_str_to_m_z(mdi->m_window_name, 1, &wmdi.m_window_name));
	wmdi.m_instance = mdi->m_instance;
	wmdi.m_x = mdi->m_x;
	wmdi.m_y = mdi->m_y;
	wmdi.m_width = mdi->m_width;
	wmdi.m_height = mdi->m_height;
	wmdi.m_style = mdi->m_style;
	wmdi.m_param = mdi->m_param;
	mk_try(mk_win_user_window_send(hwnd, mk_win_user_window_wm_mdicreate, 0, (mk_win_base_user_types_lparam_t)(mk_win_base_user_wm_mdicreate_a_lpct)&wmdi, &lres));
	mk_assert(mdihwnd);
	*mdihwnd = (mk_win_base_user_types_hwnd_t)lres;
	return 0;
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		mk_win_base_user_wm_mdicreate_a_t wmdi;
		mk_win_base_user_types_lresult_t lres;
		mk_try(mk_win_str_to_narrow_z(mdi->m_class_name, 0, &wmdi.m_class_name));
		mk_try(mk_win_str_to_narrow_z(mdi->m_window_name, 1, &wmdi.m_window_name));
		wmdi.m_instance = mdi->m_instance;
		wmdi.m_x = mdi->m_x;
		wmdi.m_y = mdi->m_y;
		wmdi.m_width = mdi->m_width;
		wmdi.m_height = mdi->m_height;
		wmdi.m_style = mdi->m_style;
		wmdi.m_param = mdi->m_param;
		mk_try(mk_win_user_window_send(hwnd, mk_win_user_window_wm_mdicreate, 0, (mk_win_base_user_types_lparam_t)(mk_win_base_user_wm_mdicreate_a_lpct)&wmdi, &lres));
		mk_assert(mdihwnd);
		*mdihwnd = (mk_win_base_user_types_hwnd_t)lres;
		return 0;
	}
	else
	{
		mk_win_base_user_wm_mdicreate_w_t wmdi;
		mk_win_base_user_types_lresult_t lres;
		mk_try(mk_win_str_to_wide_z(mdi->m_class_name, 0, &wmdi.m_class_name));
		mk_try(mk_win_str_to_wide_z(mdi->m_window_name, 1, &wmdi.m_window_name));
		wmdi.m_instance = mdi->m_instance;
		wmdi.m_x = mdi->m_x;
		wmdi.m_y = mdi->m_y;
		wmdi.m_width = mdi->m_width;
		wmdi.m_height = mdi->m_height;
		wmdi.m_style = mdi->m_style;
		wmdi.m_param = mdi->m_param;
		mk_try(mk_win_user_window_send(hwnd, mk_win_user_window_wm_mdicreate, 0, (mk_win_base_user_types_lparam_t)(mk_win_base_user_wm_mdicreate_a_lpct)&wmdi, &lres));
		mk_assert(mdihwnd);
		*mdihwnd = (mk_win_base_user_types_hwnd_t)lres;
		return 0;
	}
	#endif
	#undef mk_win_base_user_wm_mdicreate_m_t
	#undef mk_win_str_to_m_z
}
