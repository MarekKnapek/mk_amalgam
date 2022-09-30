#include "mk_dacdbtw_panel.h"

#include "../../mk_win/src/mk_win_api.h"
#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_comctl.h"
#include "../../mk_win/src/mk_win_comctl_treeview.h"
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
#include "../../mk_std/src/mk_std_str_convertor.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stdio.h>
#include <string.h>


enum mk_dacdbtw_panel_private_state
{
	mk_dacdbtw_panel_private_state_empty,
	mk_dacdbtw_panel_private_state_ok,
	mk_dacdbtw_panel_private_state_fail_open,
	mk_dacdbtw_panel_private_state_fail_parse
};


static mk_win_char_t const mk_dacdbtw_panel_private_class_name[] = mk_win_char_c("mkdacdbtwp");


static mk_inline int mk_dacdbtw_panel_private_populate_tree(mk_dacdbtw_panel_t* panel);
static mk_inline int mk_dacdbtw_panel_private_create_tree(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret);
static mk_inline int mk_dacdbtw_panel_private_create_label(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret);
static mk_inline int mk_dacdbtw_panel_private_reposition(mk_dacdbtw_panel_t* panel);
static mk_inline int mk_dacdbtw_panel_private_on_wm_create(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam);
static mk_inline int mk_dacdbtw_panel_private_on_wm_destroy(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_size(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
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


static mk_inline int mk_dacdbtw_panel_private_populate_tree(mk_dacdbtw_panel_t* panel)
{
	mk_win_comctl_treeview_insert_t insert;
	mk_win_comctl_treeview_htreeitem_t hti;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	mk_assert(panel->m_state == mk_dacdbtw_panel_private_state_ok);

	insert.m_parent = mk_win_comctl_treeview_hti_root;
	insert.m_insert_after = mk_win_comctl_treeview_hti_root;
	insert.m_item.m_item_ex.m_mask = mk_win_comctl_treeview_item_flag_text | mk_win_comctl_treeview_item_flag_param | mk_win_comctl_treeview_item_flag_children;
	insert.m_item.m_item_ex.m_hitem = 0;
	insert.m_item.m_item_ex.m_state = 0;
	insert.m_item.m_item_ex.m_state_mask = 0;
	insert.m_item.m_item_ex.m_text = mk_win_comctl_treeview_text_callback;
	insert.m_item.m_item_ex.m_text_len = 0;
	insert.m_item.m_item_ex.m_image_idx = 0;
	insert.m_item.m_item_ex.m_selected_image_idx = 0;
	insert.m_item.m_item_ex.m_children_count = mk_win_comctl_treeview_children_callback;
	insert.m_item.m_item_ex.m_param = ((mk_win_base_user_types_lparam_t)(&panel->m_doc.m_root));
	insert.m_item.m_item_ex.m_integral = 0; /* 1 */
	insert.m_item.m_item_ex.m_state_ex = 0;
	insert.m_item.m_item_ex.m_hwnd = 0;
	insert.m_item.m_item_ex.m_expanded_image_idx = 0;
	insert.m_item.m_item_ex.m_reserved = 0;
	mk_try(mk_win_comctl_treeview_insert(panel->m_tree, &insert, &hti));
	mk_assert(hti);

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_create_tree(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret)
{
	mk_win_user_window_create_t wi;
	mk_win_base_user_types_hwnd_t hwnd;

	mk_assert(panel);
	mk_assert(panel->m_hwnd);
	mk_assert(ret);

	wi.m_extra_style = mk_win_user_window_style_ex_clientedge;
	wi.m_class_name = mk_win_char_c("SysTreeView32");
	wi.m_window_name = NULL;
	wi.m_style = mk_win_comctl_treeview_vs_hasbuttons | mk_win_comctl_treeview_vs_haslines | mk_win_comctl_treeview_vs_linesatroot | mk_win_comctl_treeview_vs_showselalways | mk_win_user_window_style_tabstop | mk_win_user_window_style_border | mk_win_user_window_style_child;
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
	wi.m_style = mk_win_user_window_style_child;
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

static mk_inline int mk_dacdbtw_panel_private_reposition(mk_dacdbtw_panel_t* panel)
{
	mk_win_base_types_rect_t rect;
	mk_win_base_types_bool_t b;
	int width;
	int height;
	mk_win_base_user_types_hwnd_t wnd;

	mk_assert(panel);
	mk_assert(panel->m_hwnd);
	mk_assert(panel->m_tree);
	mk_assert(panel->m_label);

	mk_try(mk_win_user_window_get_client_rect(panel->m_hwnd, &rect, &b)); mk_assert(b != 0);
	mk_assert(rect.m_left == 0);
	mk_assert(rect.m_top == 0);
	width = rect.m_right;
	height = rect.m_bottom;
	wnd = (panel->m_state == mk_dacdbtw_panel_private_state_ok) ? panel->m_tree : panel->m_label;
	mk_try(mk_win_user_window_move(wnd, 0, 0, width, height, 1, &b)); mk_assert(b != 0);

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
	mk_try(mk_dacdbtw_panel_private_create_tree(panel, &panel->m_tree));
	mk_try(mk_dacdbtw_panel_private_create_label(panel, &panel->m_label));
	panel->m_state = mk_dacdbtw_panel_private_state_empty;
	mk_try(mk_win_user_window_send_set_text(panel->m_label, mk_win_char_c("empty")));
	panel->m_file_name = NULL;
	mk_try(mk_dacdbt_doc_construct(&panel->m_doc));
	mk_try(mk_std_buffer_init(&panel->m_tree_callback_texts[0]));
	mk_try(mk_std_buffer_init(&panel->m_tree_callback_texts[1]));
	mk_try(mk_std_buffer_init(&panel->m_tree_callback_texts[2]));
	mk_try(mk_std_buffer_init(&panel->m_tree_callback_texts[3]));
	panel->m_tree_callback_texts_idx = 0;
	mk_try(mk_dacdbtw_panel_private_reposition(panel));

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

	mk_try(mk_std_buffer_deinit(&panel->m_tree_callback_texts[3]));
	mk_try(mk_std_buffer_deinit(&panel->m_tree_callback_texts[2]));
	mk_try(mk_std_buffer_deinit(&panel->m_tree_callback_texts[1]));
	mk_try(mk_std_buffer_deinit(&panel->m_tree_callback_texts[0]));
	mk_try(mk_dacdbt_doc_destruct(&panel->m_doc));
	mk_try(mk_std_gcallocator_deallocate(panel->m_file_name));
	mk_try(mk_std_gcallocator_deallocate(panel));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_size(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_assert(panel);
	(void)wparam;
	(void)lparam;
	(void)skip_defproc;
	(void)lr;

	mk_try(mk_dacdbtw_panel_private_reposition(panel));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	(void)(wparam);
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	if(nmhdr->m_from == panel->m_tree)
	{
		if(nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfoa || nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfow)
		{
			mk_win_comctl_treeview_nm_dispinfom_lpt dispinfo;
			mk_dacdbt_key_t* key;

			dispinfo = ((mk_win_comctl_treeview_nm_dispinfom_lpt)(nmhdr));
			mk_assert(((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_text) != 0) || ((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_children) != 0));
			mk_assert(dispinfo->m_item.m_item_a.m_param != 0);
			key = ((mk_dacdbt_key_t*)(dispinfo->m_item.m_item_a.m_param));
			if((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_text) != 0)
			{
				int is_wide;
				void const* data;
				size_t len;
				char* narrow;
				void* mem;
				wchar_t* wide;

				mk_try(mk_dacdbt_key_get_name(key, &is_wide, &data, &len));
				#define mk_min(a, b) (((b) < (a)) ? (b) : (a))
				if(is_wide == 0)
				{
					if(nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfoa)
					{
						narrow = ((char*)(data));
						mk_try(mk_std_buffer_reserve(&panel->m_tree_callback_texts[panel->m_tree_callback_texts_idx], mk_min(len + 1, 512) * sizeof(char)));
						mk_try(mk_std_buffer_get_mem(&panel->m_tree_callback_texts[panel->m_tree_callback_texts_idx], &mem));
						memcpy(mem, narrow, mk_min(len, 512 - 1) * sizeof(char));
						((char*)(mem))[mk_min(len, 512 - 1)] = '\0';
						dispinfo->m_item.m_item_a.m_text = ((char*)(mem));
					}
					else
					{
						mk_try(mk_std_str_convertor_narrow_to_wide_s(((char const*)(data)), mk_min(len, 512), 0, &wide));
						mk_try(mk_std_buffer_reserve(&panel->m_tree_callback_texts[panel->m_tree_callback_texts_idx], mk_min(len + 1, 512) * sizeof(wchar_t)));
						mk_try(mk_std_buffer_get_mem(&panel->m_tree_callback_texts[panel->m_tree_callback_texts_idx], &mem));
						memcpy(mem, wide, mk_min(len, 512 - 1) * sizeof(wchar_t));
						((wchar_t*)(mem))[mk_min(len, 512 - 1)] = L'\0';
						dispinfo->m_item.m_item_w.m_text = ((wchar_t*)(mem));
					}
				}
				else
				{
					if(nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfoa)
					{
						mk_try(mk_std_str_convertor_wide_to_narrow_s(((wchar_t const*)(data)), mk_min(len, 512), 0, &narrow));
						mk_try(mk_std_buffer_reserve(&panel->m_tree_callback_texts[panel->m_tree_callback_texts_idx], mk_min(len + 1, 512) * sizeof(char)));
						mk_try(mk_std_buffer_get_mem(&panel->m_tree_callback_texts[panel->m_tree_callback_texts_idx], &mem));
						memcpy(mem, narrow, mk_min(len, 512 - 1) * sizeof(char));
						((char*)(mem))[mk_min(len, 512 - 1)] = '\0';
						dispinfo->m_item.m_item_a.m_text = ((char*)(mem));
					}
					else
					{
						wide = ((wchar_t*)(((wchar_t const*)(data))));
						mk_try(mk_std_buffer_reserve(&panel->m_tree_callback_texts[panel->m_tree_callback_texts_idx], mk_min(len + 1, 512) * sizeof(wchar_t)));
						mk_try(mk_std_buffer_get_mem(&panel->m_tree_callback_texts[panel->m_tree_callback_texts_idx], &mem));
						memcpy(mem, wide, mk_min(len, 512 - 1) * sizeof(wchar_t));
						((wchar_t*)(mem))[mk_min(len, 512 - 1)] = L'\0';
						dispinfo->m_item.m_item_w.m_text = ((wchar_t*)(mem));
					}
				}
				#undef mk_min
				panel->m_tree_callback_texts_idx = (panel->m_tree_callback_texts_idx + 1) % 4;
			}
			if((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_children) != 0)
			{
				unsigned long count;

				mk_try(mk_dacdbt_key_get_sub_keys_count(key, &count));
				dispinfo->m_item.m_item_a.m_children_count = (count == 0) ? 0 : 1;
			}
		}
		else if(nmhdr->m_code == mk_win_comctl_treeview_notify_itemexpandinga || nmhdr->m_code == mk_win_comctl_treeview_notify_itemexpandingw)
		{
			mk_win_comctl_treeview_nm_lpt nm;
			mk_win_comctl_treeview_insert_t insert;
			unsigned long i;
			mk_dacdbt_key_t* sub_key;
			mk_win_comctl_treeview_htreeitem_t hti;

			nm = ((mk_win_comctl_treeview_nm_lpt)(nmhdr));
			if
			(
				((nm->m_new.m_a.m_state & mk_win_comctl_treeview_item_state_expandedonce) == 0) &&
				(
					((nm->m_action & mk_win_comctl_treeview_action_expand) == mk_win_comctl_treeview_action_expand) ||
					((nm->m_action & mk_win_comctl_treeview_action_toggle) == mk_win_comctl_treeview_action_toggle)
				)
			)
			{
				mk_dacdbt_key_t* key;
				unsigned long count;

				mk_assert(nm->m_new.m_a.m_hitem != 0);
				mk_assert(nm->m_new.m_a.m_param != 0);
				key = ((mk_dacdbt_key_t*)(nm->m_new.m_a.m_param));
				insert.m_parent = nm->m_new.m_a.m_hitem;
				insert.m_insert_after = mk_win_comctl_treeview_hti_first;
				insert.m_item.m_item_ex.m_mask = mk_win_comctl_treeview_item_flag_text | mk_win_comctl_treeview_item_flag_param | mk_win_comctl_treeview_item_flag_children;
				insert.m_item.m_item_ex.m_hitem = 0;
				insert.m_item.m_item_ex.m_state = 0;
				insert.m_item.m_item_ex.m_state_mask = 0;
				insert.m_item.m_item_ex.m_text = mk_win_comctl_treeview_text_callback;
				insert.m_item.m_item_ex.m_text_len = 0;
				insert.m_item.m_item_ex.m_image_idx = 0;
				insert.m_item.m_item_ex.m_selected_image_idx = 0;
				insert.m_item.m_item_ex.m_children_count = mk_win_comctl_treeview_children_callback;
				insert.m_item.m_item_ex.m_integral = 0; /* 1 */
				insert.m_item.m_item_ex.m_state_ex = 0;
				insert.m_item.m_item_ex.m_hwnd = 0;
				insert.m_item.m_item_ex.m_expanded_image_idx = 0;
				insert.m_item.m_item_ex.m_reserved = 0;
				mk_try(mk_dacdbt_key_get_sub_keys_count(key, &count));
				for(i = 0; i != count; ++i)
				{
					mk_try(mk_dacdbt_key_get_sub_key(key, count - 1 - i, &sub_key)); mk_assert(sub_key);
					insert.m_item.m_item_ex.m_param = ((mk_win_base_user_types_lparam_t)(sub_key));
					mk_try(mk_win_comctl_treeview_insert(panel->m_tree, &insert, &hti));
					mk_assert(hti);
				}
			}
		}
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_set_file_name(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_char_t const mk_win_base_keywords_far* file_name;
	mk_win_char_t const mk_win_base_keywords_far* str; /* TODO: strlen */
	size_t file_name_len;
	size_t i;
	int err;
	mk_std_input_stream_t is;
	int parsed;
	mk_win_base_types_bool_t b;

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
		err = mk_std_input_stream_construct_mapping(&is, file_name);
		if(err == 0)
		{
			parsed = mk_dacdbt_doc_construct_parse(&panel->m_doc, &is);
			mk_try(mk_std_input_stream_destruct(&is));
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
	if(panel->m_state == mk_dacdbtw_panel_private_state_ok)
	{
		mk_try(mk_dacdbtw_panel_private_populate_tree(panel));
		mk_try(mk_win_user_window_show(panel->m_label, mk_win_user_window_show_hide, &b)); (void)b;
		mk_try(mk_win_user_window_show(panel->m_tree, mk_win_user_window_show_show, &b)); (void)b;
	}
	else
	{
		mk_try(mk_win_user_window_show(panel->m_tree, mk_win_user_window_show_hide, &b)); (void)b;
		mk_try(mk_win_user_window_show(panel->m_label, mk_win_user_window_show_show, &b)); (void)b;
	}
	mk_try(mk_dacdbtw_panel_private_reposition(panel));

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
		case mk_win_user_window_wm_notify: mk_try(mk_dacdbtw_panel_private_on_wm_notify(panel, wparam, lparam, skip_defproc, lr)); break;
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
