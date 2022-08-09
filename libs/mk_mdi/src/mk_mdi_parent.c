#include "mk_mdi_parent.h"

#include "mk_mdi_parent_constants.h"
#include "mk_mdi_app.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win/src/mk_win_instance.h"
#include "../../mk_win/src/mk_win_user_brush.h"
#include "../../mk_win/src/mk_win_user_class.h"
#include "../../mk_win/src/mk_win_user_cursor.h"
#include "../../mk_win/src/mk_win_user_icon.h"
#include "../../mk_win/src/mk_win_user_window.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include <stddef.h>


static mk_win_char_t const mk_mdi_parent_private_menu_name[] = mk_win_char_c("mk_mdi_parent_menu");
static mk_win_char_t const mk_mdi_parent_private_class_name[] = mk_win_char_c("mk_mdi_parent_class");


static mk_inline int mk_mdi_parent_private_register_class(void);
static mk_inline int mk_mdi_parent_private_on_destroy(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_new_file(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_close_file(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_new_window(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_close_window(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu(mk_mdi_parent_pt parent, unsigned short menu_id, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_command(mk_mdi_parent_pt parent, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_message(mk_mdi_parent_pt parent, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres);
static mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_mdi_parent_private_wndproc2(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam);


mk_jumbo int mk_mdi_parent_init(void)
{
	mk_try(mk_mdi_parent_private_register_class());

	return 0;
}

mk_jumbo int mk_mdi_parent_deinit(void)
{
	return 0;
}

mk_jumbo int mk_mdi_parent_construct(mk_mdi_parent_pt parent, struct mk_mdi_app_s* app)
{
	mk_win_user_window_create_t wnd_info;
	mk_win_base_user_types_hwnd_t hwnd;

	mk_assert(parent);
	mk_assert(app);

	parent->m_app = app;
	parent->m_hwnd = NULL;

	wnd_info.m_extra_style = mk_win_user_window_style_ex_overlappedwindow;
	wnd_info.m_class_name = mk_mdi_parent_private_class_name;
	wnd_info.m_window_name = mk_win_char_c("Parent");
	wnd_info.m_style = mk_win_user_window_style_overlappedwindow;
	wnd_info.m_x = mk_win_user_window_default_value;
	wnd_info.m_y = mk_win_user_window_default_value;
	wnd_info.m_width = mk_win_user_window_default_value;
	wnd_info.m_height = mk_win_user_window_default_value;
	wnd_info.m_parent = NULL;
	wnd_info.m_menu = NULL;
	mk_try(mk_win_instance_get(&wnd_info.m_instance));
	wnd_info.m_param = parent;
	mk_try(mk_win_user_window_create(&wnd_info, &hwnd));
	mk_assert(parent->m_hwnd == hwnd);

	return 0;
}

mk_jumbo int mk_mdi_parent_destruct(mk_mdi_parent_pt parent)
{
	mk_assert(parent);

	return 0;
}

mk_jumbo int mk_mdi_parent_show(mk_mdi_parent_pt parent, int show)
{
	mk_win_base_types_bool_t b;

	mk_assert(parent);

	mk_try(mk_win_user_window_show(parent->m_hwnd, show, &b));
	(void)b;

	return 0;
}

mk_jumbo int mk_mdi_parent_close(mk_mdi_parent_pt parent)
{
	mk_assert(parent);
	mk_assert(parent->m_hwnd);

	mk_try(mk_win_user_window_message_post_close(parent->m_hwnd));

	return 0;
}


static mk_inline int mk_mdi_parent_private_register_class(void)
{
	mk_win_user_class_t cls;
	mk_win_base_types_atom_t atom;

	cls.m_style = 0;
	cls.m_wndproc = &mk_mdi_parent_private_wndproc2;
	cls.m_cls_extra = 0;
	cls.m_wnd_extra = 0;
	mk_try(mk_win_instance_get(&cls.m_hinstance));
	mk_try(mk_win_user_icon_load_by_id(mk_win_user_icon_id_application, &cls.m_hicon));
	mk_try(mk_win_user_cursor_load_by_id(mk_win_user_cursor_id_arrow, &cls.m_hcursor));
	cls.m_background = (mk_win_base_user_types_hbrush_t)(mk_win_base_types_uintptr_t)(mk_win_user_color_id_appworkspace + 1);
	cls.m_menu_name = mk_mdi_parent_private_menu_name;
	cls.m_class_name = mk_mdi_parent_private_class_name;
	cls.m_small_icon = NULL;
	mk_try(mk_win_user_class_register(&cls, &atom));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_destroy(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_app_on_parent_destroy(parent->m_app, parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_new_file(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	/**/

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_close_file(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	/**/

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_new_window(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_app_add_parent(parent->m_app));
	mk_try(mk_mdi_app_show_last_parent(parent->m_app, mk_win_user_window_show_shownormal));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_close_window(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_close(parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu(mk_mdi_parent_pt parent, unsigned short menu_id, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	switch(menu_id)
	{
		case mk_mdi_parent_menu_id_file_new_file: mk_try(mk_mdi_parent_private_on_menu_new_file(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_file_close_file: mk_try(mk_mdi_parent_private_on_menu_close_file(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_file_new_window: mk_try(mk_mdi_parent_private_on_menu_new_window(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_file_close_window: mk_try(mk_mdi_parent_private_on_menu_close_window(parent, override_defproc, lres)); break;
	}

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_command(mk_mdi_parent_pt parent, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	if(((((mk_win_base_types_uintptr_t)wparam) >> 16) & 0xffffu) == 0 && lparam == 0)
	{
		mk_try(mk_mdi_parent_private_on_menu(parent, (unsigned short)(wparam & 0xffffu), override_defproc, lres));
	}

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_message(mk_mdi_parent_pt parent, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	switch(msg)
	{
		case mk_win_base_user_types_window_wm_destroy: mk_try(mk_mdi_parent_private_on_destroy(parent, override_defproc, lres)); break;
		case mk_win_base_user_types_window_wm_command: mk_try(mk_mdi_parent_private_on_command(parent, wparam, lparam, override_defproc, lres)); break;
	}

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres)
{
	int override_defproc;
	mk_win_base_types_uintptr_t info;
	mk_mdi_parent_pt parent;

	mk_assert(hwnd);
	mk_assert(lres);

	if(msg == mk_win_base_user_types_window_wm_create)
	{
		mk_win_base_user_types_wm_create_a_lpct create;
		mk_mdi_parent_lpt parent_lp;
		mk_win_base_types_uintptr_t prev;
		mk_assert(lparam != 0);
		create = (mk_win_base_user_types_wm_create_a_lpct)lparam;
		mk_assert(create->m_param);
		parent_lp = (mk_mdi_parent_lpt)create->m_param;
		mk_assert(!parent_lp->m_hwnd);
		parent_lp->m_hwnd = hwnd;
		mk_try(mk_win_user_window_set_info(hwnd, mk_win_base_user_types_window_info_id_userdata, (mk_win_base_types_uintptr_t)parent_lp, &prev));
		mk_assert(prev == 0);
	}
	override_defproc = 0;
	mk_try(mk_win_user_window_get_info(hwnd, mk_win_base_user_types_window_info_id_userdata, &info));
	if(info != 0)
	{
		parent = (mk_mdi_parent_pt)(mk_mdi_parent_lpt)info;
		mk_try(mk_mdi_parent_private_on_message(parent, msg, wparam, lparam, &override_defproc, lres));
	}
	if(!override_defproc)
	{
		mk_try(mk_win_user_window_defproc(hwnd, msg, wparam, lparam, lres));
	}

	return 0;
}

static mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_mdi_parent_private_wndproc2(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam)
{
	int err;
	mk_win_base_user_types_lresult_t lres;

	err = mk_mdi_parent_private_on_wndproc(hwnd, msg, wparam, lparam, &lres);
	mk_assert(err == 0);

	return lres;
}
