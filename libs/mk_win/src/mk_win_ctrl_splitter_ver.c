#include "mk_win_ctrl_splitter_ver.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_functions.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_instance.h"
#include "../../mk_win/src/mk_win_user_brush.h"
#include "../../mk_win/src/mk_win_user_class.h"
#include "../../mk_win/src/mk_win_user_cursor.h"
#include "../../mk_win/src/mk_win_user_window.h"

#include "../../mk_std/src/mk_std_gcallocator.h"


struct mk_win_ctrl_splitter_ver_s
{
	mk_win_base_user_types_hwnd_t m_hwnd;
	mk_win_base_user_types_hwnd_t m_child_left;
	mk_win_base_user_types_hwnd_t m_child_right;
	int m_ratio;
	int m_sizing;
};
mk_win_base_types_make_struct(mk_win_ctrl_splitter_ver);


static mk_win_char_t const s_win_ctrl_splitter_ver_class_name[] = mk_win_char_c("mkwcsv");


mk_win_base_types_atom_t g_win_ctrl_splitter_ver_atom;


mk_jumbo int mk_win_ctrl_splitter_ver_reposition(mk_win_ctrl_splitter_ver_t* const self);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_create(mk_win_base_user_types_hwnd_t const hwnd, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_destroy(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_size(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_notify(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_mousemove(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_lbuttondown(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_lbuttonup(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_set_ratio(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_set_child(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_msg(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_types_uint_t const msg, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);
mk_jumbo int mk_win_ctrl_splitter_ver_on_wndproc(mk_win_base_user_types_hwnd_t const hwnd, mk_win_base_types_uint_t const msg, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam, mk_win_base_user_types_lresult_t* const lr);
mk_jumbo mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_win_ctrl_splitter_ver_wndproc(mk_win_base_user_types_hwnd_t const hwnd, mk_win_base_types_uint_t const msg, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam);


mk_jumbo int mk_win_ctrl_splitter_ver_class_register(void)
{
	mk_win_user_class_t cls;

	mk_assert(!g_win_ctrl_splitter_ver_atom);

	cls.m_style = 0;
	cls.m_wndproc = &mk_win_ctrl_splitter_ver_wndproc;
	cls.m_cls_extra = 0;
	cls.m_wnd_extra = ((int)(sizeof(mk_win_ctrl_splitter_ver_lpt)));
	mk_try(mk_win_instance_get(&cls.m_hinstance));
	cls.m_hicon = ((mk_win_base_user_types_hicon_t)(mk_win_base_types_null));
	mk_try(mk_win_user_cursor_load_by_id(mk_win_user_cursor_id_sizens, &cls.m_hcursor));
	cls.m_background = ((mk_win_base_user_types_hbrush_t)((mk_win_base_types_uintptr_t)(mk_win_user_color_id_btnface + 1)));
	cls.m_menu_name = ((mk_win_strc_t)(mk_win_base_types_null));
	cls.m_class_name = s_win_ctrl_splitter_ver_class_name;
	cls.m_small_icon = ((mk_win_base_user_types_hicon_t)(mk_win_base_types_null));
	mk_try(mk_win_user_class_register(&cls, &g_win_ctrl_splitter_ver_atom));
	mk_assert(g_win_ctrl_splitter_ver_atom);

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_class_unregister(void)
{
	mk_assert(g_win_ctrl_splitter_ver_atom);

	/* todo */

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_class_get_atom(mk_win_base_types_atom_t* const atom)
{
	mk_assert(atom);
	mk_assert(g_win_ctrl_splitter_ver_atom);

	*atom = g_win_ctrl_splitter_ver_atom;

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_class_get_name(mk_win_strc_t* const name)
{
	mk_assert(name);

	*name = s_win_ctrl_splitter_ver_class_name;

	return 0;
}


mk_jumbo int mk_win_ctrl_splitter_ver_reposition(mk_win_ctrl_splitter_ver_t* const self)
{
	static int const s_border = 4;

	mk_win_base_types_rect_t rect;
	mk_win_base_types_bool_t b;
	int width;
	int height;
	int middle;

	mk_assert(self);
	mk_assert(self->m_hwnd);

	if(self->m_child_left && self->m_child_right)
	{
		mk_try(mk_win_user_window_get_client_rect(self->m_hwnd, &rect, &b)); mk_assert(b != 0);
		mk_assert(rect.m_left == 0);
		mk_assert(rect.m_top == 0);
		mk_assert(rect.m_right >= 0);
		mk_assert(rect.m_bottom >= 0);
		width = rect.m_right;
		height = rect.m_bottom;
		middle = ((int)((((long)(height)) * ((long)(self->m_ratio))) / ((long)(10000))));
		if(middle < 10) middle = 10;
		if(middle > height - 10) middle = height - 10;
		mk_try(mk_win_user_window_move(self->m_child_left, 0, 0, width, middle - s_border / 2, 1, &b)); mk_assert(b != 0);
		mk_try(mk_win_user_window_move(self->m_child_right, 0, middle + s_border / 2, width, height - middle - s_border, 1, &b)); mk_assert(b != 0);
	}

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_create(mk_win_base_user_types_hwnd_t const hwnd, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_win_ctrl_splitter_ver_t* self;
	mk_win_base_types_uintptr_t prev;

	mk_assert(hwnd);
	((void)(wparam));
	((void)(lparam));

	mk_try(mk_std_gcallocator_allocate(sizeof(*self), ((void**)(&self))));
	self->m_hwnd = hwnd;
	self->m_child_left = ((mk_win_base_user_types_hwnd_t)(0));
	self->m_child_right = ((mk_win_base_user_types_hwnd_t)(0));
	self->m_ratio = 10000 / 2;
	self->m_sizing = 0;
	mk_try(mk_win_user_window_set_info(hwnd, 0, ((mk_win_base_types_uintptr_t)((mk_win_ctrl_splitter_ver_lpt)(self))), &prev)); mk_assert(prev == 0);

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_destroy(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_win_base_types_uintptr_t prev;

	mk_assert(self);
	mk_assert(self->m_hwnd);
	((void)(wparam));
	((void)(lparam));

	mk_try(mk_win_user_window_set_info(self->m_hwnd, 0, 0, &prev));
	mk_assert(((mk_win_ctrl_splitter_ver_pt)((mk_win_ctrl_splitter_ver_lpt)(prev))) == self);
	mk_try(mk_std_gcallocator_deallocate(self));

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_size(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_assert(self);
	((void)(wparam));
	((void)(lparam));

	mk_try(mk_win_ctrl_splitter_ver_reposition(self));

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_notify(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_win_base_user_types_lresult_t lr;

	mk_assert(self);
	mk_assert(self->m_hwnd);
	mk_assert(GetParent(self->m_hwnd));

	mk_try(mk_win_user_window_send(GetParent(self->m_hwnd), mk_win_user_window_wm_notify, wparam, lparam, &lr)); ((void)(lr)); /* todo lr? */

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_mousemove(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_win_base_types_rect_t rect;
	mk_win_base_types_bool_t b;
	int y;

	mk_assert(self);
	mk_assert(self->m_hwnd);
	((void)(wparam));

	if(self->m_sizing)
	{
		mk_try(mk_win_user_window_get_client_rect(self->m_hwnd, &rect, &b)); mk_assert(b != 0);
		y = ((int)(((short)((lparam >> 16) & 0xfffful))));
		self->m_ratio = ((int)((((long)(y)) * ((long)(10000))) / ((long)(rect.m_bottom))));
		if(self->m_ratio < 500) self->m_ratio = 500;
		if(self->m_ratio > 9500) self->m_ratio = 9500;
		mk_win_ctrl_splitter_ver_reposition(self);
	}

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_lbuttondown(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_win_base_user_types_hwnd_t prev;

	mk_assert(self);
	mk_assert(self->m_hwnd);
	((void)(wparam));
	((void)(lparam));

	prev = SetCapture(self->m_hwnd); ((void)(prev));
	self->m_sizing = 1;

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_lbuttonup(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_win_base_types_bool_t b;

	mk_assert(self);
	mk_assert(self->m_hwnd);
	((void)(wparam));
	((void)(lparam));

	self->m_sizing = 0;
	b = ReleaseCapture(); mk_assert(b != 0);

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_set_ratio(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_assert(self);
	mk_assert(wparam >= 500 && wparam <= 9500);
	((void)(lparam));

	self->m_ratio = ((int)(wparam));

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg_set_child(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_assert(self);
	mk_assert(wparam == 0 || wparam == 1);

	switch(wparam)
	{
		case 0: self->m_child_left = ((mk_win_base_user_types_hwnd_t)(lparam)); break;
		case 1: self->m_child_right = ((mk_win_base_user_types_hwnd_t)(lparam)); break;
	}

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_msg(mk_win_ctrl_splitter_ver_t* const self, mk_win_base_types_uint_t const msg, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	mk_assert(self);

	switch(msg)
	{
		case mk_win_user_window_wm_destroy: mk_try(mk_win_ctrl_splitter_ver_on_msg_destroy(self, wparam, lparam)); break;
		case mk_win_user_window_wm_size: mk_try(mk_win_ctrl_splitter_ver_on_msg_size(self, wparam, lparam)); break;
		case mk_win_user_window_wm_notify: mk_try(mk_win_ctrl_splitter_ver_on_msg_notify(self, wparam, lparam)); break;
		case mk_win_user_window_wm_mousemove: mk_try(mk_win_ctrl_splitter_ver_on_msg_mousemove(self, wparam, lparam)); break;
		case mk_win_user_window_wm_lbuttondown: mk_try(mk_win_ctrl_splitter_ver_on_msg_lbuttondown(self, wparam, lparam)); break;
		case mk_win_user_window_wm_lbuttonup: mk_try(mk_win_ctrl_splitter_ver_on_msg_lbuttonup(self, wparam, lparam)); break;
		case mk_win_ctrl_splitter_ver_wm_set_ratio: mk_try(mk_win_ctrl_splitter_ver_on_msg_set_ratio(self, wparam, lparam)); break;
		case mk_win_ctrl_splitter_ver_wm_set_child: mk_try(mk_win_ctrl_splitter_ver_on_msg_set_child(self, wparam, lparam)); break;
	}

	return 0;
}

mk_jumbo int mk_win_ctrl_splitter_ver_on_wndproc(mk_win_base_user_types_hwnd_t const hwnd, mk_win_base_types_uint_t const msg, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam, mk_win_base_user_types_lresult_t* const lr)
{
	mk_win_base_types_uintptr_t info;
	mk_win_ctrl_splitter_ver_t* self;

	mk_assert(hwnd);

	if(msg == mk_win_user_window_wm_create)
	{
		mk_try(mk_win_ctrl_splitter_ver_on_msg_create(hwnd, wparam, lparam));
	}
	else
	{
		mk_try(mk_win_user_window_get_info(hwnd, 0, &info));
		if(info != 0)
		{
			self = ((mk_win_ctrl_splitter_ver_pt)((mk_win_ctrl_splitter_ver_lpt)(info))); mk_assert(self);
			mk_try(mk_win_ctrl_splitter_ver_on_msg(self, msg, wparam, lparam));
		}
	}
	mk_try(mk_win_user_window_defproc(hwnd, msg, wparam, lparam, lr));

	return 0;
}

mk_jumbo mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_win_ctrl_splitter_ver_wndproc(mk_win_base_user_types_hwnd_t const hwnd, mk_win_base_types_uint_t const msg, mk_win_base_user_types_wparam_t const wparam, mk_win_base_user_types_lparam_t const lparam)
{
	int err;
	mk_win_base_user_types_lresult_t lr;

	err = mk_win_ctrl_splitter_ver_on_wndproc(hwnd, msg, wparam, lparam, &lr);
	mk_assert(err == 0);

	return lr;
}
