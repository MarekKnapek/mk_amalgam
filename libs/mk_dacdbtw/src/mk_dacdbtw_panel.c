#include "mk_dacdbtw_panel.h"

#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_comctl.h"
#include "../../mk_win/src/mk_win_instance.h"
#include "../../mk_win/src/mk_win_user_brush.h"
#include "../../mk_win/src/mk_win_user_class.h"
#include "../../mk_win/src/mk_win_user_cursor.h"
#include "../../mk_win/src/mk_win_user_window.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_std/src/mk_std_gcallocator.h"
#include "../../mk_std/src/mk_std_input_stream.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stdio.h>


enum mk_dacdbtw_panel_private_state
{
	mk_dacdbtw_panel_private_state_empty,
	mk_dacdbtw_panel_private_state_ok,
	mk_dacdbtw_panel_private_state_fail_open,
	mk_dacdbtw_panel_private_state_fail_parse
};


static mk_win_char_t const mk_dacdbtw_panel_private_class_name[] = mk_win_char_c("mkdacdbtwp");


static mk_inline int mk_dacdbtw_panel_private_create_label(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret);
static mk_inline int mk_dacdbtw_panel_private_on_wm_create(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam);
static mk_inline int mk_dacdbtw_panel_private_on_wm_destroy(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_size(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_set_file_name(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_msg(mk_dacdbtw_panel_t* panel, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
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

	mk_try(mk_win_comctl_init());

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


static mk_inline int mk_dacdbtw_panel_private_create_label(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret)
{
	mk_win_user_window_create_t wi;
	mk_win_base_user_types_hwnd_t hwnd;

	mk_assert(panel);
	mk_assert(panel->m_hwnd);
	mk_assert(ret);

	wi.m_extra_style = 0;
	wi.m_class_name = mk_win_char_c("static");
	wi.m_window_name = NULL;
	wi.m_style = mk_win_user_window_style_visible | mk_win_user_window_style_child;
	wi.m_x = 0;
	wi.m_y = 0;
	wi.m_width = 0;
	wi.m_height = 0;
	wi.m_parent = panel->m_hwnd;
	wi.m_menu = mk_win_base_types_null;
	mk_try(mk_win_instance_get(&wi.m_instance));
	wi.m_param = NULL;
	mk_try(mk_win_user_window_create(&wi, &hwnd));
	mk_assert(hwnd);

	*ret = hwnd;

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
	mk_try(mk_win_user_window_set_info(hwnd, 0, (mk_win_base_types_uintptr_t)(mk_dacdbtw_panel_lpt)panel, &prev)); mk_assert(prev == 0);
	panel->m_hwnd = hwnd;
	mk_try(mk_dacdbtw_panel_private_create_label(panel, &panel->m_label));
	panel->m_state = mk_dacdbtw_panel_private_state_empty;
	mk_try(mk_win_user_window_send_set_text(panel->m_label, mk_win_char_c("empty")));
	panel->m_file_name = NULL;
	mk_try(mk_dacdbt_doc_construct(&panel->m_doc));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_destroy(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_types_uintptr_t prev;

	mk_assert(panel);
	mk_assert(panel->m_hwnd);
	(void)(wparam);
	(void)(lparam);
	mk_assert(skip_defproc);
	mk_assert(lr);

	mk_try(mk_win_user_window_set_info(panel->m_hwnd, 0, 0, &prev));
	mk_assert((mk_dacdbtw_panel_pt)(mk_dacdbtw_panel_lpt)prev == panel);

	mk_try(mk_dacdbt_doc_destruct(&panel->m_doc));
	mk_try(mk_std_gcallocator_deallocate(panel->m_file_name));
	mk_try(mk_std_gcallocator_deallocate(panel));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_size(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	unsigned short width;
	unsigned short height;
	mk_win_base_types_bool_t b;

	mk_assert(panel);
	mk_assert(panel->m_label);
	(void)(wparam);
	mk_assert(skip_defproc);
	mk_assert(lr);

	width = (unsigned short)((lparam) & 0xfffful);
	height = (unsigned short)((lparam >> 16) & 0xfffful);
	mk_try(mk_win_user_window_move(panel->m_label, 0, 0, width, height, 1, &b)); (void)b;

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_set_file_name(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_char_t const mk_win_base_keywords_far* file_name;
	mk_win_char_t const mk_win_base_keywords_far* str; /* TODO: strlen */
	size_t file_name_len;
	size_t i;
	char* file_name_c;
	FILE* file;
	mk_std_input_stream_t is;
	int parsed;
	int closed;

	mk_assert(panel);
	mk_assert(wparam == 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	file_name = (mk_win_char_t const mk_win_base_keywords_far*)lparam;
	if(file_name && *file_name)
	{
		str = file_name;
		file_name_len = 0;
		while(*str++) ++file_name_len;
		mk_try(mk_std_gcallocator_reallocate((void**)&panel->m_file_name, (file_name_len + 1) * sizeof(mk_win_char_t)));
		for(i = 0; i != file_name_len + 1; ++i) panel->m_file_name[i] = file_name[i];
		mk_try(mk_win_str_to_narrow_z(panel->m_file_name, 0, &file_name_c));
		file = fopen(file_name_c, "rb"); /* TODO: Wrapper around C file IO and Windows file IO and Windows mapped file IO. */
		if(file)
		{
			mk_try(mk_std_input_stream_construct_file(&is, file));
			parsed = mk_dacdbt_doc_construct_parse(&panel->m_doc, &is);
			if(parsed == 0)
			{
				panel->m_state = mk_dacdbtw_panel_private_state_ok;
				mk_try(mk_win_user_window_send_set_text(panel->m_label, mk_win_char_c("ok")));
			}
			else
			{
				panel->m_state = mk_dacdbtw_panel_private_state_fail_parse;
				mk_try(mk_win_user_window_send_set_text(panel->m_label, mk_win_char_c("failed to parse")));
			}
			mk_try(mk_std_input_stream_destruct(&is));
			closed = fclose(file); mk_check(closed == 0);
		}
		else
		{
			panel->m_state = mk_dacdbtw_panel_private_state_fail_open;
			mk_try(mk_win_user_window_send_set_text(panel->m_label, mk_win_char_c("failed to open")));
		}
	}
	else
	{
		panel->m_state = mk_dacdbtw_panel_private_state_empty;
		mk_try(mk_win_user_window_send_set_text(panel->m_label, mk_win_char_c("empty")));
		mk_try(mk_std_gcallocator_deallocate(panel->m_file_name)); panel->m_file_name = NULL;
		mk_try(mk_dacdbt_doc_destruct(&panel->m_doc));
		mk_try(mk_dacdbt_doc_construct(&panel->m_doc));
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_msg(mk_dacdbtw_panel_t* panel, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_assert(panel);
	mk_assert(skip_defproc);
	mk_assert(lr);

	switch(msg)
	{
		case mk_win_user_window_wm_destroy: mk_try(mk_dacdbtw_panel_private_on_wm_destroy(panel, wparam, lparam, skip_defproc, lr)); break;
		case mk_win_user_window_wm_size: mk_try(mk_dacdbtw_panel_private_on_wm_size(panel, wparam, lparam, skip_defproc, lr)); break;
		case mk_dacdbtw_panel_wm_set_file_name: mk_try(mk_dacdbtw_panel_private_on_wm_set_file_name(panel, wparam, lparam, skip_defproc, lr)); break;
	}

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
		panel = (mk_dacdbtw_panel_pt)(mk_dacdbtw_panel_lpt)info; mk_assert(panel);
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
