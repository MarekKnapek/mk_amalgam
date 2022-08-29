#include "mk_dacdbtw_panel.h"

#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_instance.h"
#include "../../mk_win/src/mk_win_user_brush.h"
#include "../../mk_win/src/mk_win_user_class.h"
#include "../../mk_win/src/mk_win_user_cursor.h"
#include "../../mk_win/src/mk_win_user_window.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_std/src/mk_std_gcallocator.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"


static mk_win_char_t const mk_dacdbtw_panel_private_class_name[] = mk_win_char_c("mkdacdbtwp");


static mk_inline int mk_dacdbtw_panel_private_on_wm_create(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam);
static mk_inline int mk_dacdbtw_panel_private_on_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lr);
static mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_dacdbtw_panel_private_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam);


mk_jumbo int mk_dacdbtw_panel_init(void)
{
	mk_win_user_class_t cls;
	mk_win_base_types_atom_t atom;

	cls.m_style = mk_win_user_class_style_vredraw | mk_win_user_class_style_hredraw;
	cls.m_wndproc = &mk_dacdbtw_panel_private_wndproc;
	cls.m_cls_extra = 0;
	cls.m_wnd_extra = sizeof(mk_dacdbtw_panel_lpt);
	mk_try(mk_win_instance_get(&cls.m_hinstance));
	cls.m_hicon = mk_win_base_types_null;
	mk_try(mk_win_user_cursor_load_by_id(mk_win_user_cursor_id_arrow, &cls.m_hcursor));
	cls.m_background = (mk_win_base_user_types_hbrush_t)(mk_win_base_types_uintptr_t)(mk_win_user_color_id_window + 1);
	cls.m_menu_name = mk_win_base_types_null;
	cls.m_class_name = mk_dacdbtw_panel_private_class_name;
	cls.m_small_icon = mk_win_base_types_null;
	mk_try(mk_win_user_class_register(&cls, &atom));
	mk_assert(atom != 0);

	return 0;
}

mk_jumbo int mk_dacdbtw_panel_deinit(void)
{
	return 0;
}

mk_jumbo int mk_dacdbtw_panel_get_class_name(mk_win_char_t const** name)
{
	mk_assert(name);

	*name = mk_dacdbtw_panel_private_class_name;

	return 0;
}


static mk_inline int mk_dacdbtw_panel_private_on_wm_create(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam)
{
	mk_dacdbtw_panel_t* panel;
	mk_win_base_types_uintptr_t prev;

	mk_assert(hwnd);
	(void)wparam;
	(void)lparam;

	mk_try(mk_std_gcallocator_allocate(sizeof(*panel), (void**)&panel));
	panel->m_hwnd = hwnd;
	mk_try(mk_win_user_window_set_info(hwnd, 0, (mk_win_base_types_uintptr_t)(mk_dacdbtw_panel_lpt)panel, &prev));
	mk_assert(prev == 0);

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_msg(mk_dacdbtw_panel_t* panel, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_assert(panel);
	mk_assert(skip_defproc);
	mk_assert(lr);

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lr)
{
	int skip_defproc;
	mk_win_base_types_uintptr_t info;
	mk_dacdbtw_panel_t* panel;

	mk_assert(lr);

	if(msg == mk_win_user_window_wm_create)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_create(hwnd, wparam, lparam));
	}
	skip_defproc = 0;
	mk_try(mk_win_user_window_get_info(hwnd, 0, &info));
	if(info != 0)
	{
		panel = (mk_dacdbtw_panel_pt)(mk_dacdbtw_panel_lpt)info;
		mk_assert(panel);
		mk_try(mk_dacdbtw_panel_private_on_msg(panel, msg, wparam, lparam, &skip_defproc, lr));
	}
	if(skip_defproc == 0)
	{
		mk_try(mk_win_user_window_defproc(hwnd, msg, wparam, lparam, lr));
	}

	return 0;
}

static mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_dacdbtw_panel_private_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam)
{
	int err;
	mk_win_base_user_types_lresult_t lr;

	err = mk_dacdbtw_panel_private_on_wndproc(hwnd, msg, wparam, lparam, &lr);
	mk_assert(err == 0);

	return lr;
}
