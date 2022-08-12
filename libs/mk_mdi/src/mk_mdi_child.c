#include "mk_mdi_child.h"

#include "mk_mdi_parent.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win/src/mk_win_instance.h"
#include "../../mk_win/src/mk_win_user_brush.h"
#include "../../mk_win/src/mk_win_user_class.h"
#include "../../mk_win/src/mk_win_user_cursor.h"
#include "../../mk_win/src/mk_win_user_icon.h"
#include "../../mk_win/src/mk_win_user_message.h"
#include "../../mk_win/src/mk_win_user_window.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include <stddef.h>


typedef mk_mdi_child_t mk_win_base_keywords_far* mk_mdi_child_lpt;


static mk_win_char_t const mk_mdi_child_private_menu_name[] = mk_win_char_c("mk_mdi_child_menu");
static mk_win_char_t const mk_mdi_child_private_class_name[] = mk_win_char_c("mk_mdi_child_class");


static mk_inline int mk_mdi_child_private_register_class(void);
static mk_inline int mk_mdi_child_private_on_destroy(mk_mdi_child_pt child, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_child_private_on_close(mk_mdi_child_pt child, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_child_private_on_message(mk_mdi_child_pt child, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_child_private_on_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres);
static mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_mdi_child_private_wndproc2(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam);


mk_jumbo int mk_mdi_child_init(void)
{
	mk_try(mk_mdi_child_private_register_class());

	return 0;
}

mk_jumbo int mk_mdi_child_deinit(void)
{
	return 0;
}

mk_jumbo int mk_mdi_child_hwnd2object(mk_win_base_user_types_hwnd_t hwnd, mk_mdi_child_pt* object)
{
	mk_win_base_types_uintptr_t info;
	mk_mdi_child_pt obj;

	mk_assert(hwnd);
	mk_assert(object);

	mk_try(mk_win_user_window_get_info(hwnd, mk_win_base_user_types_window_info_id_userdata, &info));
	obj = (mk_mdi_child_pt)(mk_mdi_child_lpt)info;
	*object = obj;

	return 0;
}

mk_jumbo int mk_mdi_child_construct(mk_mdi_child_pt child, mk_mdi_parent_pt parent)
{
	mk_win_user_window_mdicreate_t mdi;
	mk_win_base_user_types_hwnd_t hwnd;

	mk_assert(child);
	mk_assert(parent);
	mk_assert(parent->m_mdi);

	child->m_parent = parent;
	child->m_hwnd = NULL;

	mdi.m_class_name = mk_mdi_child_private_class_name;
	mdi.m_window_name = mk_win_char_c("Child");
	mk_try(mk_win_instance_get(&mdi.m_instance));
	mdi.m_x = mk_win_user_window_default_value;
	mdi.m_y = mk_win_user_window_default_value;
	mdi.m_width = mk_win_user_window_default_value;
	mdi.m_height = mk_win_user_window_default_value;
	mdi.m_style = mk_win_user_window_style_overlappedwindow | mk_win_user_window_style_visible;
	mdi.m_param = child;
	mk_try(mk_win_user_window_send_mdicreate(parent->m_mdi, &mdi, &hwnd));
	mk_assert(hwnd);
	mk_assert(child->m_hwnd == hwnd);

	return 0;
}

mk_jumbo int mk_mdi_child_destruct(mk_mdi_child_pt child)
{
	mk_assert(child);

	return 0;
}

mk_jumbo int mk_mdi_child_close(mk_mdi_child_pt child)
{
	mk_assert(child);
	mk_assert(child->m_hwnd);

	mk_try(mk_win_user_window_send_close(child->m_hwnd));

	return 0;
}


static mk_inline int mk_mdi_child_private_register_class(void)
{
	mk_win_user_class_t cls;
	mk_win_base_types_atom_t atom;

	cls.m_style = 0;
	cls.m_wndproc = &mk_mdi_child_private_wndproc2;
	cls.m_cls_extra = 0;
	cls.m_wnd_extra = 0;
	mk_try(mk_win_instance_get(&cls.m_hinstance));
	mk_try(mk_win_user_icon_load_by_id(mk_win_user_icon_id_application, &cls.m_hicon));
	mk_try(mk_win_user_cursor_load_by_id(mk_win_user_cursor_id_arrow, &cls.m_hcursor));
	cls.m_background = (mk_win_base_user_types_hbrush_t)(mk_win_base_types_uintptr_t)(mk_win_user_color_id_window + 1);
	cls.m_menu_name = NULL;
	cls.m_class_name = mk_mdi_child_private_class_name;
	cls.m_small_icon = NULL;
	mk_try(mk_win_user_class_register(&cls, &atom));

	return 0;
}

static mk_inline int mk_mdi_child_private_on_destroy(mk_mdi_child_pt child, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_win_base_types_uintptr_t prev;

	mk_assert(child);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_win_user_window_set_info(child->m_hwnd, mk_win_base_user_types_window_info_id_userdata, 0, &prev));
	mk_assert((mk_mdi_child_pt)(mk_mdi_child_lpt)prev == child);

	mk_try(mk_mdi_parent_on_child_destroy(child->m_parent, child));

	return 0;
}

static mk_inline int mk_mdi_child_private_on_close(mk_mdi_child_pt child, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(child);
	mk_assert(override_defproc);
	mk_assert(lres);

	/**/

	return 0;
}

static mk_inline int mk_mdi_child_private_on_message(mk_mdi_child_pt child, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(child);
	mk_assert(override_defproc);
	mk_assert(lres);

	switch(msg)
	{
		case mk_win_base_user_types_window_wm_destroy: mk_try(mk_mdi_child_private_on_destroy(child, override_defproc, lres)); break;
		case mk_win_base_user_types_window_wm_close: mk_try(mk_mdi_child_private_on_close(child, override_defproc, lres)); break;
	}

	(void)wparam;/**/
	(void)lparam;/**/

	return 0;
}

static mk_inline int mk_mdi_child_private_on_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres)
{
	int override_defproc;
	mk_mdi_child_pt child;

	mk_assert(hwnd);
	mk_assert(lres);

	if(msg == mk_win_base_user_types_window_wm_create)
	{
		mk_win_base_user_types_wm_create_a_lpct create;
		mk_win_base_user_wm_mdicreate_a_lpct mdi_create;
		mk_mdi_child_lpt child_lp;
		mk_win_base_types_uintptr_t prev;
		mk_assert(lparam != 0);
		create = (mk_win_base_user_types_wm_create_a_lpct)lparam;
		mk_assert(create->m_param);
		mdi_create = (mk_win_base_user_wm_mdicreate_a_lpct)create->m_param;
		mk_assert(mdi_create->m_param);
		child_lp = (mk_mdi_child_lpt)mdi_create->m_param;
		mk_assert(!child_lp->m_hwnd);
		child_lp->m_hwnd = hwnd;
		mk_try(mk_win_user_window_set_info(hwnd, mk_win_base_user_types_window_info_id_userdata, (mk_win_base_types_uintptr_t)child_lp, &prev));
		mk_assert(prev == 0);
	}
	override_defproc = 0;
	mk_try(mk_mdi_child_hwnd2object(hwnd, &child));
	if(child)
	{
		mk_try(mk_mdi_child_private_on_message(child, msg, wparam, lparam, &override_defproc, lres));
	}
	if(!override_defproc)
	{
		mk_try(mk_win_user_window_defmdichildproc(hwnd, msg, wparam, lparam, lres));
	}

	return 0;
}

static mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_mdi_child_private_wndproc2(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam)
{
	int err;
	mk_win_base_user_types_lresult_t lres;

	err = mk_mdi_child_private_on_wndproc(hwnd, msg, wparam, lparam, &lres);
	mk_assert(err == 0);

	return lres;
}
