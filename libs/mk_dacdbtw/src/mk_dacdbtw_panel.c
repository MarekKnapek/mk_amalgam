#include "mk_dacdbtw_panel.h"

#include "mk_dacdbtw_float_to_string.h"

#include "../../mk_dacdbt/src/mk_dacdbt_doc.h"

#include "../../mk_win/src/mk_win_api.h"
#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_comctl.h"
#include "../../mk_win/src/mk_win_comctl_listview.h"
#include "../../mk_win/src/mk_win_comctl_statusbar.h"
#include "../../mk_win/src/mk_win_comctl_treeview.h"
#include "../../mk_win/src/mk_win_ctrl_splitter_hor.h"
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

#include "../../mk_int/src/exact/mk_uint_32.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_clobber.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>


struct mk_dacdbtw_panel_s
{
	mk_win_base_user_types_hwnd_t m_hwnd;
	mk_win_base_user_types_hwnd_t m_label;
	mk_win_base_user_types_hwnd_t m_status;
	mk_win_base_user_types_hwnd_t m_splitter;
	mk_win_base_user_types_hwnd_t m_tree;
	mk_win_base_user_types_hwnd_t m_list;
	int m_state;
	mk_win_char_t* m_file_name;
	mk_dacdbt_doc_t m_doc;
	mk_std_buffer_t m_tree_callback_texts[4];
	unsigned int m_tree_callback_texts_idx;
	mk_std_buffer_t m_list_callback_texts[4];
	unsigned int m_list_callback_texts_idx;
};
mk_win_base_types_make_struct(mk_dacdbtw_panel);


enum mk_dacdbtw_panel_private_state
{
	mk_dacdbtw_panel_private_state_empty,
	mk_dacdbtw_panel_private_state_ok,
	mk_dacdbtw_panel_private_state_fail_open,
	mk_dacdbtw_panel_private_state_fail_parse
};


static mk_win_char_t const mk_dacdbtw_panel_private_class_name[] = mk_win_char_c("mkdacdbtwp");


static mk_inline int mk_dacdbtw_panel_private_create_label(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret);
static mk_inline int mk_dacdbtw_panel_private_create_status(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret);
static mk_inline int mk_dacdbtw_panel_private_create_splitter(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret);
static mk_inline int mk_dacdbtw_panel_private_create_tree(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret);
static mk_inline int mk_dacdbtw_panel_private_create_list(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret);
static mk_inline int mk_dacdbtw_panel_private_populate_tree(mk_dacdbtw_panel_t* panel);
static mk_inline int mk_dacdbtw_panel_private_refresh_statusbar(mk_dacdbtw_panel_t* panel);
static mk_inline int mk_dacdbtw_panel_private_refresh_listview(mk_dacdbtw_panel_t* panel);
static mk_inline int mk_dacdbtw_panel_private_reposition(mk_dacdbtw_panel_t* panel);
static mk_inline int mk_dacdbtw_panel_private_on_wm_create(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam);
static mk_inline int mk_dacdbtw_panel_private_on_wm_destroy(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_size(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_selchanged(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_itemexpanding_firsttime(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_itemexpanding(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_getdispinfo_children(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_getdispinfo_text(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_getdispinfo(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_value_text_type_a(mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_type_w(mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_name_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_name_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_lenght_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_lenght_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_u32_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_u32_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_f64_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_f64_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_str_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_str_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_bin_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_bin_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_fil_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_fil_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_u64_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_u64_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text);
static mk_inline int mk_dacdbtw_panel_private_value_text_data_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_list_getdispinfo_text(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_list_getdispinfo_image(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_list_getdispinfo(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_list(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_notify(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
static mk_inline int mk_dacdbtw_panel_private_on_wm_idle(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr);
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
	cls.m_hicon = ((mk_win_base_user_types_hicon_t)(mk_win_base_types_null));
	mk_try(mk_win_user_cursor_load_by_id(mk_win_user_cursor_id_arrow, &cls.m_hcursor));
	cls.m_background = (mk_win_base_user_types_hbrush_t)(mk_win_base_types_uintptr_t)(mk_win_user_color_id_window + 1);
	cls.m_menu_name = ((mk_win_strc_t)(mk_win_base_types_null));
	cls.m_class_name = mk_dacdbtw_panel_private_class_name;
	cls.m_small_icon = ((mk_win_base_user_types_hicon_t)(mk_win_base_types_null));
	mk_try(mk_win_user_class_register(&cls, &atom));
	mk_assert(atom != 0);

	mk_try(mk_win_ctrl_splitter_hor_class_register());

	mk_try(mk_win_comctl_init());

	return 0;
}

mk_jumbo int mk_dacdbtw_panel_deinit(void)
{
	mk_try(mk_win_ctrl_splitter_hor_class_unregister());

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
	wi.m_style = mk_win_user_window_style_child;
	wi.m_x = 0;
	wi.m_y = 0;
	wi.m_width = 0;
	wi.m_height = 0;
	wi.m_parent = panel->m_hwnd;
	wi.m_menu = ((mk_win_base_user_types_hmenu_t)(mk_win_base_types_null));
	mk_try(mk_win_instance_get(&wi.m_instance));
	wi.m_param = NULL;
	mk_try(mk_win_user_window_create(&wi, &hwnd));
	mk_assert(hwnd);

	*ret = hwnd;

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_create_status(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret)
{
	mk_win_user_window_create_t wi;
	mk_win_base_user_types_hwnd_t hwnd;
	mk_win_base_user_types_lresult_t lr;

	mk_assert(panel);
	mk_assert(panel->m_hwnd);
	mk_assert(ret);

	wi.m_extra_style = 0;
	wi.m_class_name = mk_win_comctl_statusbar_classname;
	wi.m_window_name = NULL;
	wi.m_style = mk_win_comctl_statusbar_ws_sizegrip | mk_win_user_window_style_child;
	wi.m_x = 0;
	wi.m_y = 0;
	wi.m_width = 0;
	wi.m_height = 0;
	wi.m_parent = panel->m_hwnd;
	wi.m_menu = ((mk_win_base_user_types_hmenu_t)(mk_win_base_types_null));
	mk_try(mk_win_instance_get(&wi.m_instance));
	wi.m_param = NULL;
	mk_try(mk_win_user_window_create(&wi, &hwnd));
	mk_assert(hwnd);

	mk_try(mk_win_user_window_send(hwnd, mk_win_comctl_statusbar_wm_simple, 1, 0, &lr)); ((void)(lr));

	*ret = hwnd;

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_create_splitter(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret)
{
	mk_win_user_window_create_t wi;
	mk_win_base_user_types_hwnd_t hwnd;

	mk_assert(panel);
	mk_assert(panel->m_hwnd);
	mk_assert(ret);
	
	wi.m_extra_style = 0;
	mk_win_ctrl_splitter_hor_class_get_name(&wi.m_class_name);
	wi.m_window_name = NULL;
	wi.m_style = mk_win_user_window_style_clipchildren | mk_win_user_window_style_visible | mk_win_user_window_style_child;
	wi.m_x = 0;
	wi.m_y = 0;
	wi.m_width = 0;
	wi.m_height = 0;
	wi.m_parent = panel->m_hwnd;
	wi.m_menu = ((mk_win_base_user_types_hmenu_t)(mk_win_base_types_null));
	mk_try(mk_win_instance_get(&wi.m_instance));
	wi.m_param = NULL;
	mk_try(mk_win_user_window_create(&wi, &hwnd));
	mk_assert(hwnd);
	*ret = hwnd;

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_create_tree(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret)
{
	mk_win_user_window_create_t wi;
	mk_win_base_user_types_hwnd_t hwnd;

	mk_assert(panel);
	mk_assert(panel->m_splitter);
	mk_assert(ret);

	wi.m_extra_style = mk_win_user_window_style_ex_clientedge;
	wi.m_class_name = mk_win_char_c("SysTreeView32");
	wi.m_window_name = NULL;
	wi.m_style = mk_win_comctl_treeview_vs_hasbuttons | mk_win_comctl_treeview_vs_haslines | mk_win_comctl_treeview_vs_linesatroot | mk_win_comctl_treeview_vs_showselalways | mk_win_user_window_style_tabstop | mk_win_user_window_style_border | mk_win_user_window_style_child;
	wi.m_x = 0;
	wi.m_y = 0;
	wi.m_width = 0;
	wi.m_height = 0;
	wi.m_parent = panel->m_splitter;
	wi.m_menu = ((mk_win_base_user_types_hmenu_t)(mk_win_base_types_null));
	mk_try(mk_win_instance_get(&wi.m_instance));
	wi.m_param = NULL;
	mk_try(mk_win_user_window_create(&wi, &hwnd));
	mk_assert(hwnd);
	*ret = hwnd;

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_create_list(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_hwnd_t* ret)
{
	mk_win_user_window_create_t wi;
	mk_win_base_user_types_hwnd_t hwnd;
	mk_win_base_user_types_lresult_t lr;
	mk_win_comctl_listview_column_t col;
	mk_win_base_types_intptr_t idx;

	mk_assert(panel);
	mk_assert(panel->m_splitter);
	mk_assert(ret);

	wi.m_extra_style = mk_win_user_window_style_ex_clientedge | mk_win_comctl_listview_wsex_headerdragdrop | mk_win_comctl_listview_wsex_fullrowselect;
	wi.m_class_name = mk_win_comctl_listview_classname;
	wi.m_window_name = NULL;
	wi.m_style = mk_win_comctl_listview_ws_report | mk_win_comctl_listview_ws_showselalways | mk_win_comctl_listview_ws_ownerdata | mk_win_user_window_style_tabstop | mk_win_user_window_style_border | mk_win_user_window_style_child;
	wi.m_x = 0;
	wi.m_y = 0;
	wi.m_width = 0;
	wi.m_height = 0;
	wi.m_parent = panel->m_splitter;
	wi.m_menu = ((mk_win_base_user_types_hmenu_t)(mk_win_base_types_null));
	mk_try(mk_win_instance_get(&wi.m_instance));
	wi.m_param = NULL;
	mk_try(mk_win_user_window_create(&wi, &hwnd));
	mk_assert(hwnd);

	mk_try(mk_win_user_window_send(hwnd, mk_win_comctl_listview_wm_setextendedlistviewstyle, ((mk_win_base_user_types_lparam_t)(wi.m_extra_style)), ((mk_win_base_user_types_lparam_t)(wi.m_extra_style)), &lr)); ((void)(lr));

	col.m_mask = mk_win_comctl_listview_colflag_width | mk_win_comctl_listview_colflag_text;
	col.m_cx = 64;
	col.m_text = mk_win_char_c("Type");
	mk_try(mk_win_comctl_listview_insertcolumn(hwnd, 0, &col, &idx)); mk_assert(idx != -1);
	col.m_text = mk_win_char_c("Name");
	mk_try(mk_win_comctl_listview_insertcolumn(hwnd, 1, &col, &idx)); mk_assert(idx != -1);
	col.m_text = mk_win_char_c("Length");
	mk_try(mk_win_comctl_listview_insertcolumn(hwnd, 2, &col, &idx)); mk_assert(idx != -1);
	col.m_text = mk_win_char_c("Data");
	mk_try(mk_win_comctl_listview_insertcolumn(hwnd, 3, &col, &idx)); mk_assert(idx != -1);

	*ret = hwnd;

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

static mk_inline int mk_dacdbtw_panel_private_refresh_statusbar(mk_dacdbtw_panel_t* panel)
{
	mk_win_base_user_types_lresult_t lr;
	mk_win_comctl_treeview_htreeitem_t item;
	mk_dacdbt_key_t const* key;
	mk_std_ptr_buff_t keys;
	size_t total_len;
	size_t count;
	size_t i;
	int is_wide;
	void const* data;
	size_t len;
	mk_std_buffer_t buff;
	mk_win_char_t* path;
	mk_win_char_t* path_curr;
	mk_win_char_t* name;

	mk_try(mk_win_user_window_send(panel->m_tree, mk_win_comctl_treeview_wm_getnextitem, mk_win_comctl_treeview_getnextitem_caret, ((mk_win_base_user_types_lparam_t)(0)), &lr));
	mk_assert(lr != 0);
	item = ((mk_win_comctl_treeview_htreeitem_t)(lr));
	mk_try(mk_win_comctl_treeview_item_get_param(panel->m_tree, item, ((void**)(&key))));
	mk_assert(key);
	mk_try(mk_std_ptr_buff_construct(&keys));
	mk_try(mk_std_ptr_buff_append(&keys, key));
	while(key != &panel->m_doc.m_root)
	{
		mk_try(mk_win_user_window_send(panel->m_tree, mk_win_comctl_treeview_wm_getnextitem, mk_win_comctl_treeview_getnextitem_parent, ((mk_win_base_user_types_lparam_t)(item)), &lr));
		mk_assert(lr != 0);
		item = ((mk_win_comctl_treeview_htreeitem_t)(lr));
		mk_try(mk_win_comctl_treeview_item_get_param(panel->m_tree, item, ((void**)(&key))));
		mk_assert(key);
		mk_try(mk_std_ptr_buff_append(&keys, key));
	}
	total_len = 0;
	mk_try(mk_std_ptr_buff_get_count(&keys, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&keys, count - 1 - i, ((void const**)(&key))));
		mk_try(mk_dacdbt_key_get_name(key, &is_wide, &data, &len));
		total_len += (1 + len);
	}
	mk_try(mk_std_buffer_init(&buff));
	mk_try(mk_std_buffer_reserve(&buff, (total_len + 1) * sizeof(mk_win_char_t)));
	mk_try(mk_std_buffer_get_mem(&buff, ((void**)(&path))));
	path_curr = path;
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&keys, count - 1 - i, ((void const**)(&key))));
		mk_try(mk_dacdbt_key_get_name(key, &is_wide, &data, &len));
		if(is_wide == 0)
		{
			mk_try(mk_win_str_from_narrow_s(((char const*)(data)), len, 0, &name));
		}
		else
		{
			mk_try(mk_win_str_from_wide_s(((wchar_t const*)(data)), len, 0, &name));
		}
		path_curr[0] = mk_win_char_c('/');
		++path_curr;
		memcpy(path_curr, name, len * sizeof(mk_win_char_t));
		path_curr += len;
	}
	path_curr[0] = mk_win_char_c('\0');
	mk_try(mk_win_comctl_statusbar_set_text(panel->m_status, mk_win_comctl_statusbar_settext_param_simpleid, mk_win_comctl_statusbar_settext_param_notabparsing, path));
	mk_try(mk_std_buffer_deinit(&buff));
	mk_try(mk_std_ptr_buff_remove_all(&keys));
	mk_try(mk_std_ptr_buff_destruct(&keys));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_refresh_listview(mk_dacdbtw_panel_t* panel)
{
	mk_win_base_user_types_lresult_t lr;
	mk_win_comctl_treeview_htreeitem_t item;
	mk_dacdbt_key_t const* key;
	unsigned long count;

	mk_assert(panel);

	mk_try(mk_win_user_window_send(panel->m_tree, mk_win_comctl_treeview_wm_getnextitem, mk_win_comctl_treeview_getnextitem_caret, ((mk_win_base_user_types_lparam_t)(0)), &lr));
	mk_assert(lr != 0);
	item = ((mk_win_comctl_treeview_htreeitem_t)(lr));
	mk_try(mk_win_comctl_treeview_item_get_param(panel->m_tree, item, ((void**)(&key))));
	mk_assert(key);
	mk_try(mk_dacdbt_key_get_values_count(key, &count));
	mk_try(mk_win_user_window_send(panel->m_list, mk_win_comctl_listview_wm_setitemcount, ((mk_win_base_user_types_lparam_t)(count)), ((mk_win_base_user_types_lparam_t)(0)), &lr));
	mk_assert(lr != 0);

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_reposition(mk_dacdbtw_panel_t* panel)
{
	mk_win_base_types_rect_t rect;
	mk_win_base_types_bool_t b;
	int width;
	int height;

	mk_assert(panel);
	mk_assert(panel->m_hwnd);
	mk_assert(panel->m_label);
	mk_assert(panel->m_status);
	mk_assert(panel->m_splitter);

	mk_try(mk_win_user_window_get_client_rect(panel->m_hwnd, &rect, &b)); mk_assert(b != 0);
	mk_assert(rect.m_left == 0);
	mk_assert(rect.m_top == 0);
	width = rect.m_right;
	height = rect.m_bottom;
	if(panel->m_state == mk_dacdbtw_panel_private_state_ok)
	{
		mk_try(mk_win_user_window_move(panel->m_status, 0, 0, width, height, 1, &b)); mk_assert(b != 0);
		mk_win_user_window_get_rect(panel->m_status, &rect, &b); mk_assert(b != 0);
		mk_try(mk_win_user_window_move(panel->m_splitter, 0, 0, width, height - (rect.m_bottom - rect.m_top), 1, &b)); mk_assert(b != 0);
	}
	else
	{
		mk_try(mk_win_user_window_move(panel->m_label, 0, 0, width, height, 1, &b)); mk_assert(b != 0);
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_create(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam)
{
	mk_dacdbtw_panel_t* panel;
	mk_win_base_types_uintptr_t prev;
	mk_win_base_user_types_lresult_t lr;

	mk_assert(hwnd);
	(void)wparam;
	(void)lparam;

	mk_try(mk_std_gcallocator_allocate(sizeof(*panel), (void**)&panel));
	mk_try(mk_win_user_window_set_info(hwnd, 0, (mk_win_base_types_uintptr_t)(mk_dacdbtw_panel_lpt)panel, &prev)); mk_assert(prev == 0);
	panel->m_hwnd = hwnd;
	mk_try(mk_dacdbtw_panel_private_create_label(panel, &panel->m_label));
	mk_try(mk_dacdbtw_panel_private_create_status(panel, &panel->m_status));
	mk_try(mk_dacdbtw_panel_private_create_splitter(panel, &panel->m_splitter));
	mk_try(mk_dacdbtw_panel_private_create_tree(panel, &panel->m_tree));
	mk_try(mk_dacdbtw_panel_private_create_list(panel, &panel->m_list));
	mk_try(mk_win_user_window_send(panel->m_splitter, mk_win_ctrl_splitter_hor_wm_set_child, 0, ((mk_win_base_user_types_lparam_t)(panel->m_tree)), &lr)); ((void)(lr));
	mk_try(mk_win_user_window_send(panel->m_splitter, mk_win_ctrl_splitter_hor_wm_set_child, 1, ((mk_win_base_user_types_lparam_t)(panel->m_list)), &lr)); ((void)(lr));
	panel->m_state = mk_dacdbtw_panel_private_state_empty;
	mk_try(mk_win_user_window_send_set_text(panel->m_label, mk_win_char_c("empty")));
	panel->m_file_name = NULL;
	mk_try(mk_dacdbt_doc_construct(&panel->m_doc));
	mk_try(mk_std_buffer_init(&panel->m_tree_callback_texts[0]));
	mk_try(mk_std_buffer_init(&panel->m_tree_callback_texts[1]));
	mk_try(mk_std_buffer_init(&panel->m_tree_callback_texts[2]));
	mk_try(mk_std_buffer_init(&panel->m_tree_callback_texts[3]));
	panel->m_tree_callback_texts_idx = 0;
	mk_try(mk_std_buffer_init(&panel->m_list_callback_texts[0]));
	mk_try(mk_std_buffer_init(&panel->m_list_callback_texts[1]));
	mk_try(mk_std_buffer_init(&panel->m_list_callback_texts[2]));
	mk_try(mk_std_buffer_init(&panel->m_list_callback_texts[3]));
	panel->m_list_callback_texts_idx = 0;
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

	mk_try(mk_std_buffer_deinit(&panel->m_list_callback_texts[3]));
	mk_try(mk_std_buffer_deinit(&panel->m_list_callback_texts[2]));
	mk_try(mk_std_buffer_deinit(&panel->m_list_callback_texts[1]));
	mk_try(mk_std_buffer_deinit(&panel->m_list_callback_texts[0]));
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

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_selchanged(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;

	mk_win_comctl_treeview_nm_lpt nm;
	mk_dacdbt_key_t* key;
	mk_win_comctl_treeview_htreeitem_t item;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	mk_assert(nmhdr->m_from == panel->m_tree);
	mk_assert(nmhdr->m_code == mk_win_comctl_treeview_notify_selchangeda || nmhdr->m_code == mk_win_comctl_treeview_notify_selchangedw);

	nm = ((mk_win_comctl_treeview_nm_lpt)(nmhdr));
	mk_assert(nm->m_new.m_a.m_param != 0);
	key = ((mk_dacdbt_key_t*)(nm->m_new.m_a.m_param));
	item = nm->m_new.m_a.m_hitem;
	mk_assert(item);

	mk_try(mk_dacdbtw_panel_private_refresh_statusbar(panel));
	mk_try(mk_dacdbtw_panel_private_refresh_listview(panel));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_itemexpanding_firsttime(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;
	mk_win_comctl_treeview_nm_lpt nm;

	mk_dacdbt_key_t* key;
	mk_win_comctl_treeview_insert_t insert;
	unsigned long count;
	unsigned long i;
	mk_dacdbt_key_t* sub_key;
	mk_win_comctl_treeview_htreeitem_t hti;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	mk_assert(nmhdr->m_from == panel->m_tree);
	mk_assert(nmhdr->m_code == mk_win_comctl_treeview_notify_itemexpandinga || nmhdr->m_code == mk_win_comctl_treeview_notify_itemexpandingw);
	nm = ((mk_win_comctl_treeview_nm_lpt)(nmhdr));

	mk_assert(nm->m_new.m_a.m_param != 0);
	key = ((mk_dacdbt_key_t*)(nm->m_new.m_a.m_param));
	mk_assert(nm->m_new.m_a.m_hitem != 0);
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

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_itemexpanding(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;

	mk_win_comctl_treeview_nm_lpt nm;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	mk_assert(nmhdr->m_from == panel->m_tree);
	mk_assert(nmhdr->m_code == mk_win_comctl_treeview_notify_itemexpandinga || nmhdr->m_code == mk_win_comctl_treeview_notify_itemexpandingw);

	nm = ((mk_win_comctl_treeview_nm_lpt)(nmhdr));
	if((nm->m_new.m_a.m_state & mk_win_comctl_treeview_item_state_expandedonce) == 0)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_tree_itemexpanding_firsttime(panel, wparam, lparam, skip_defproc, lr));
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_getdispinfo_children(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;
	mk_win_comctl_treeview_nm_dispinfom_lpt dispinfo;

	mk_dacdbt_key_t* key;
	unsigned long count;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	mk_assert(nmhdr->m_from == panel->m_tree);
	mk_assert(nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfoa || nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfow);
	dispinfo = ((mk_win_comctl_treeview_nm_dispinfom_lpt)(nmhdr));
	mk_assert((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_children) != 0);

	mk_assert(dispinfo->m_item.m_item_a.m_param != 0);
	key = ((mk_dacdbt_key_t*)(dispinfo->m_item.m_item_a.m_param));
	mk_try(mk_dacdbt_key_get_sub_keys_count(key, &count));
	dispinfo->m_item.m_item_a.m_children_count = (count != 0);

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_getdispinfo_text(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;
	mk_win_comctl_treeview_nm_dispinfom_lpt dispinfo;

	mk_dacdbt_key_t* key;
	int is_wide;
	void const* data;
	size_t len;
	char* narrow;
	void* mem;
	wchar_t* wide;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	mk_assert(nmhdr->m_from == panel->m_tree);
	mk_assert(nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfoa || nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfow);
	dispinfo = ((mk_win_comctl_treeview_nm_dispinfom_lpt)(nmhdr));
	mk_assert((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_text) != 0);

	mk_assert(dispinfo->m_item.m_item_a.m_param != 0);
	key = ((mk_dacdbt_key_t*)(dispinfo->m_item.m_item_a.m_param));
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

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree_getdispinfo(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;

	mk_win_comctl_treeview_nm_dispinfom_lpt dispinfo;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	mk_assert(nmhdr->m_from == panel->m_tree);
	mk_assert(nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfoa || nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfow);

	dispinfo = ((mk_win_comctl_treeview_nm_dispinfom_lpt)(nmhdr));
	mk_assert
	(
		((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_text) != 0) ||
		((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_children) != 0)
	);
	if((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_text) != 0)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_tree_getdispinfo_text(panel, wparam, lparam, skip_defproc, lr));
	}
	if((dispinfo->m_item.m_item_a.m_mask & mk_win_comctl_treeview_item_flag_children) != 0)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_tree_getdispinfo_children(panel, wparam, lparam, skip_defproc, lr));
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_tree(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	mk_assert(nmhdr->m_from == panel->m_tree);

	if(nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfoa || nmhdr->m_code == mk_win_comctl_treeview_notify_getdispinfow)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_tree_getdispinfo(panel, wparam, lparam, skip_defproc, lr));
	}
	else if(nmhdr->m_code == mk_win_comctl_treeview_notify_itemexpandinga || nmhdr->m_code == mk_win_comctl_treeview_notify_itemexpandingw)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_tree_itemexpanding(panel, wparam, lparam, skip_defproc, lr));
	}
	else if(nmhdr->m_code == mk_win_comctl_treeview_notify_selchangeda ||nmhdr->m_code == mk_win_comctl_treeview_notify_selchangedw)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_tree_selchanged(panel, wparam, lparam, skip_defproc, lr));
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_type_a(mk_dacdbt_value_t const* value, char const** text)
{
	static char const* const s_types[] =
	{
		"int32",
		"float64",
		"text",
		"binary",
		"file",
		"int64"
	};

	mk_dacdbt_value_type_t type;

	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_type(value, &type));
	mk_assert
	(
		(type == mk_dacdbt_value_type_e_u32) ||
		(type == mk_dacdbt_value_type_e_f64) ||
		(type == mk_dacdbt_value_type_e_str) ||
		(type == mk_dacdbt_value_type_e_bin) ||
		(type == mk_dacdbt_value_type_e_fil) ||
		(type == mk_dacdbt_value_type_e_u64)
	);
	*text = s_types[type - 1];

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_type_w(mk_dacdbt_value_t const* value, wchar_t const** text)
{
	static wchar_t const* const s_types[] =
	{
		L"int32",
		L"float64",
		L"text",
		L"binary",
		L"file",
		L"int64"
	};

	mk_dacdbt_value_type_t type;

	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_type(value, &type));
	mk_assert
	(
		(type == mk_dacdbt_value_type_e_u32) ||
		(type == mk_dacdbt_value_type_e_f64) ||
		(type == mk_dacdbt_value_type_e_str) ||
		(type == mk_dacdbt_value_type_e_bin) ||
		(type == mk_dacdbt_value_type_e_fil) ||
		(type == mk_dacdbt_value_type_e_u64)
	);
	*text = s_types[type - 1];

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_name_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_value_t const* value, char const** text)
{
	int wide;
	void const* data;
	size_t len;
	char* tmp;
	void* mem;

	mk_assert(panel);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_name(value, &wide, &data, &len));
	if(wide == 0)
	{
		tmp = ((char*)(data));
	}
	else
	{
		mk_try(mk_std_str_convertor_wide_to_narrow_s(((wchar_t const*)(data)), len, 0, &tmp));
	}
	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (len + 1) * sizeof(char)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	memcpy(mem, tmp, len * sizeof(char));
	((char*)(mem))[len] = '\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((char const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_name_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_value_t const* value, wchar_t const** text)
{
	int wide;
	void const* data;
	size_t len;
	wchar_t* tmp;
	void* mem;

	mk_assert(panel);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_name(value, &wide, &data, &len));
	if(wide == 0)
	{
		mk_try(mk_std_str_convertor_narrow_to_wide_s(((char const*)(data)), len, 0, &tmp));
	}
	else
	{
		tmp = ((wchar_t*)(data));
	}
	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (len + 1) * sizeof(wchar_t)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	memcpy(mem, tmp, len * sizeof(wchar_t));
	((wchar_t*)(mem))[len] = L'\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((wchar_t const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_lenght_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_value_t const* value, char const** text)
{
	mk_dacdbt_value_type_t type;
	int has_size;
	void* mem;
	size_t len;
	mk_uint32_t len32;
	int slen;

	mk_assert(panel);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_type(value, &type));
	mk_assert
	(
		(type == mk_dacdbt_value_type_e_u32) ||
		(type == mk_dacdbt_value_type_e_f64) ||
		(type == mk_dacdbt_value_type_e_str) ||
		(type == mk_dacdbt_value_type_e_bin) ||
		(type == mk_dacdbt_value_type_e_fil) ||
		(type == mk_dacdbt_value_type_e_u64)
	);
	mk_clobber(&has_size);
	switch(type)
	{
		case mk_dacdbt_value_type_e_u32: has_size = 0; break;
		case mk_dacdbt_value_type_e_f64: has_size = 0; break;
		case mk_dacdbt_value_type_e_str: has_size = 1; break;
		case mk_dacdbt_value_type_e_bin: has_size = 1; break;
		case mk_dacdbt_value_type_e_fil: has_size = 1; break;
		case mk_dacdbt_value_type_e_u64: has_size = 0; break;
	}
	if(has_size == 0)
	{
		mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], sizeof(char)));
		mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
		((char*)(mem))[0] = '\0';
	}
	else
	{
		mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (10 + 1) * sizeof(char)));
		mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
		mk_try(mk_dacdbt_value_get_len(value, &len));
		mk_uint32_from_sizet(&len32, len);
		slen = mk_uint32_to_string_dec_n(&len32, ((char*)(mem)), 10);
		mk_assert(slen >= 1 && slen <= 10);
		((char*)(mem))[slen] = '\0';
	}
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((char const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_lenght_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_value_t const* value, wchar_t const** text)
{
	mk_dacdbt_value_type_t type;
	int has_size;
	void* mem;
	size_t len;
	mk_uint32_t len32;
	int slen;

	mk_assert(panel);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_type(value, &type));
	mk_assert
	(
		(type == mk_dacdbt_value_type_e_u32) ||
		(type == mk_dacdbt_value_type_e_f64) ||
		(type == mk_dacdbt_value_type_e_str) ||
		(type == mk_dacdbt_value_type_e_bin) ||
		(type == mk_dacdbt_value_type_e_fil) ||
		(type == mk_dacdbt_value_type_e_u64)
	);
	mk_clobber(&has_size);
	switch(type)
	{
		case mk_dacdbt_value_type_e_u32: has_size = 0; break;
		case mk_dacdbt_value_type_e_f64: has_size = 0; break;
		case mk_dacdbt_value_type_e_str: has_size = 1; break;
		case mk_dacdbt_value_type_e_bin: has_size = 1; break;
		case mk_dacdbt_value_type_e_fil: has_size = 1; break;
		case mk_dacdbt_value_type_e_u64: has_size = 0; break;
	}
	if(has_size == 0)
	{
		mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], sizeof(wchar_t)));
		mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
		((wchar_t*)(mem))[0] = L'\0';
	}
	else
	{
		mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (10 + 1) * sizeof(wchar_t)));
		mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
		mk_try(mk_dacdbt_value_get_len(value, &len));
		mk_uint32_from_sizet(&len32, len);
		slen = mk_uint32_to_string_dec_w(&len32, ((wchar_t*)(mem)), 10);
		mk_assert(slen >= 1 && slen <= 10);
		((wchar_t*)(mem))[slen] = L'\0';
	}
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((wchar_t const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_u32_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text)
{
	void* mem;
	char* str;
	mk_uint32_t const* u32;
	mk_uint32_t tmp;
	int slen;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (1 + 10 + 1) * sizeof(char)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	str = ((char*)(mem));
	mk_try(mk_dacdbt_value_get_u32(value, &u32));
	mk_uint32_shr(&tmp, u32, 31);
	if((mk_uint32_to_int(&tmp) & 0x01) == 0)
	{
		tmp = *u32;
	}
	else
	{
		mk_uint32_cmplmnt(&tmp, u32);
		mk_uint32_inc(&tmp);
		str[0] = '-';
		++str;
	}
	slen = mk_uint32_to_string_dec_n(&tmp, str, 10);
	mk_assert(slen >= 1 && slen <= 10);
	str[slen] = '\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((char const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_u32_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text)
{
	void* mem;
	wchar_t* str;
	mk_uint32_t const* u32;
	mk_uint32_t tmp;
	int slen;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (1 + 10 + 1) * sizeof(wchar_t)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	str = ((wchar_t*)(mem));
	mk_try(mk_dacdbt_value_get_u32(value, &u32));
	mk_uint32_shr(&tmp, u32, 31);
	if((mk_uint32_to_int(&tmp) & 0x01) == 0)
	{
		tmp = *u32;
	}
	else
	{
		mk_uint32_cmplmnt(&tmp, u32);
		mk_uint32_inc(&tmp);
		str[0] = L'-';
		++str;
	}
	slen = mk_uint32_to_string_dec_w(&tmp, str, 10);
	mk_assert(slen >= 1 && slen <= 10);
	str[slen] = L'\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((wchar_t const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_f64_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text)
{
	int str_max_len;
	char* strn;
	int str_len;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	str_max_len = mk_dacdbtw_float_to_string_get_max_size();
	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (str_max_len + 1) * sizeof(char)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (void**)&strn));
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	str_len = mk_dacdbtw_float_to_string_get_string(&value->m_data.m_f64, strn, str_max_len);
	strn[str_len] = '\0';
	*text = strn;

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_f64_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text)
{
	int str_max_len;
	char* strn;
	int str_len;
	wchar_t* strw;
	int i;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	str_max_len = mk_dacdbtw_float_to_string_get_max_size();
	mk_try(mk_std_gcallocator_allocate(str_max_len, (void**)&strn));
	str_len = mk_dacdbtw_float_to_string_get_string(&value->m_data.m_f64, strn, str_max_len);
	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (str_len + 1) * sizeof(wchar_t)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (void**)&strw));
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	for(i = 0; i != str_len; ++i)
	{
		strw[i] = (wchar_t)strn[i];
	}
	strw[str_len] = L'\0';
	mk_try(mk_std_gcallocator_deallocate(strn));
	*text = strw;

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_str_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text)
{
	void* mem;
	char* txt;
	mk_dacdbt_str_t const* str;
	int wide;
	void const* data;
	char const* tmp;
	size_t len;
	size_t i;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], 512 * sizeof(char)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	txt = ((char*)(mem));
	mk_try(mk_dacdbt_value_get_str(value, &str));
	mk_try(mk_dacdbt_str_get(str, &wide, &data, &len));
	if(len > 511) len = 511;
	if(wide == 0)
	{
		tmp = ((char const*)(data));
	}
	else
	{
		mk_try(mk_std_str_convertor_wide_to_narrow_s(((wchar_t const*)(data)), len, 0, &tmp));
	}
	memcpy(mem, tmp, len * sizeof(char));
	for(i = 0; i != len; ++i) if(!(txt[i] >= 32 && txt[i] <= 126)) txt[i] = '.';
	txt[len] = '\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((char const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_str_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text)
{
	void* mem;
	wchar_t* txt;
	mk_dacdbt_str_t const* str;
	int wide;
	void const* data;
	wchar_t const* tmp;
	size_t len;
	size_t i;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], 512 * sizeof(wchar_t)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	txt = ((wchar_t*)(mem));
	mk_try(mk_dacdbt_value_get_str(value, &str));
	mk_try(mk_dacdbt_str_get(str, &wide, &data, &len));
	if(len > 511) len = 511;
	if(wide == 0)
	{
		mk_try(mk_std_str_convertor_narrow_to_wide_s(((char const*)(data)), len, 0, &tmp));
	}
	else
	{
		tmp = ((wchar_t const*)(data));
	}
	memcpy(mem, tmp, len * sizeof(wchar_t));
	for(i = 0; i != len; ++i) if(!(txt[i] >= 32 && txt[i] <= 126)) txt[i] = L'.';
	txt[len] = L'\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((wchar_t const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_bin_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text)
{
	size_t value_len;
	int value_name_is_wide;
	void const* value_name_data;
	size_t value_name_len;
	wchar_t const* strw;
	char* strn;
	void* mem;
	char* str;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_len(value, &value_len));
	if
	(
		value_len % 2 == 0 &&
		value_len >= 4 &&
		((unsigned char const*)(value->m_data.m_bin.m_mem))[value_len - 2] == 0 &&
		((unsigned char const*)(value->m_data.m_bin.m_mem))[value_len - 1] == 0
	)
	{
		mk_try(mk_dacdbt_value_get_name(value, &value_name_is_wide, &value_name_data, &value_name_len));
		if
		(
			value_name_is_wide == 0 &&
			value_name_len >= 5 &&
			((char const*)(value_name_data))[0] == '@' &&
			((char const*)(value_name_data))[1] == '@' &&
			((char const*)(value_name_data))[2] == 'U' &&
			((char const*)(value_name_data))[0] == '@'
		)
		{
			strw = ((wchar_t const*)(value->m_data.m_bin.m_mem));
			mk_try(mk_std_str_convertor_wide_to_narrow_s(strw, value_len / 2, 0, &strn));
			mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (value_len / 2) * sizeof(char)));
			mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
			panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
			memcpy(mem, strn, value_len / 2);
			*text = ((char const*)(mem));
			return 0;
		}
	}
	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], sizeof(char)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	str = ((char*)(mem));
	str[0] = L'\0';
	*text = str;

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_bin_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text)
{
	size_t value_len;
	int value_name_is_wide;
	void const* value_name_data;
	size_t value_name_len;
	void* mem;
	wchar_t* str;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_len(value, &value_len));
	if
	(
		value_len % 2 == 0 &&
		value_len >= 4 &&
		((unsigned char const*)(value->m_data.m_bin.m_mem))[value_len - 2] == 0 &&
		((unsigned char const*)(value->m_data.m_bin.m_mem))[value_len - 1] == 0
	)
	{
		mk_try(mk_dacdbt_value_get_name(value, &value_name_is_wide, &value_name_data, &value_name_len));
		if
		(
			value_name_is_wide == 0 &&
			value_name_len >= 5 &&
			((char const*)(value_name_data))[0] == '@' &&
			((char const*)(value_name_data))[1] == '@' &&
			((char const*)(value_name_data))[2] == 'U' &&
			((char const*)(value_name_data))[0] == '@'
		)
		{
			*text = ((wchar_t const*)(value->m_data.m_bin.m_mem));
			return 0;
		}
	}
	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], sizeof(wchar_t)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	str = ((wchar_t*)(mem));
	str[0] = L'\0';
	*text = str;

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_fil_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text)
{
	void* mem;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], sizeof(char)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	((char*)(mem))[0] = '\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((char const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_fil_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text)
{
	void* mem;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], sizeof(wchar_t)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	((wchar_t*)(mem))[0] = L'\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((wchar_t const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_u64_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text)
{
	void* mem;
	char* str;
	mk_uint64_t const* u64;
	mk_uint64_t tmp;
	int slen;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (1 + 20 + 1) * sizeof(char)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	str = ((char*)(mem));
	mk_try(mk_dacdbt_value_get_u64(value, &u64));
	mk_uint64_shr(&tmp, u64, 63);
	if((mk_uint64_to_int(&tmp) & 0x01) == 0)
	{
		tmp = *u64;
	}
	else
	{
		mk_uint64_cmplmnt(&tmp, u64);
		mk_uint64_inc(&tmp);
		str[0] = '-';
		++str;
	}
	slen = mk_uint64_to_string_dec_n(&tmp, str, 20);
	mk_assert(slen >= 1 && slen <= 20);
	str[slen] = '\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((char const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_u64_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text)
{
	void* mem;
	wchar_t* str;
	mk_uint64_t const* u64;
	mk_uint64_t tmp;
	int slen;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_std_buffer_reserve(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], (1 + 20 + 1) * sizeof(wchar_t)));
	mk_try(mk_std_buffer_get_mem(&panel->m_list_callback_texts[panel->m_list_callback_texts_idx], &mem));
	str = ((wchar_t*)(mem));
	mk_try(mk_dacdbt_value_get_u64(value, &u64));
	mk_uint64_shr(&tmp, u64, 63);
	if((mk_uint64_to_int(&tmp) & 0x01) == 0)
	{
		tmp = *u64;
	}
	else
	{
		mk_uint64_cmplmnt(&tmp, u64);
		mk_uint64_inc(&tmp);
		str[0] = L'-';
		++str;
	}
	slen = mk_uint64_to_string_dec_w(&tmp, str, 20);
	mk_assert(slen >= 1 && slen <= 20);
	str[slen] = L'\0';
	panel->m_list_callback_texts_idx = (panel->m_list_callback_texts_idx + 1) % (sizeof(panel->m_list_callback_texts) / sizeof(panel->m_list_callback_texts[0]));
	*text = ((wchar_t const*)(mem));

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_a(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, char const** text)
{
	mk_dacdbt_value_type_t type;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_type(value, &type));
	mk_assert
	(
		(type == mk_dacdbt_value_type_e_u32) ||
		(type == mk_dacdbt_value_type_e_f64) ||
		(type == mk_dacdbt_value_type_e_str) ||
		(type == mk_dacdbt_value_type_e_bin) ||
		(type == mk_dacdbt_value_type_e_fil) ||
		(type == mk_dacdbt_value_type_e_u64)
	);
	switch(type)
	{
		case mk_dacdbt_value_type_e_u32: mk_try(mk_dacdbtw_panel_private_value_text_data_u32_a(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_f64: mk_try(mk_dacdbtw_panel_private_value_text_data_f64_a(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_str: mk_try(mk_dacdbtw_panel_private_value_text_data_str_a(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_bin: mk_try(mk_dacdbtw_panel_private_value_text_data_bin_a(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_fil: mk_try(mk_dacdbtw_panel_private_value_text_data_fil_a(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_u64: mk_try(mk_dacdbtw_panel_private_value_text_data_u64_a(panel, key, value, text)); break;
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_value_text_data_w(mk_dacdbtw_panel_t* panel, mk_dacdbt_key_t const* key, mk_dacdbt_value_t const* value, wchar_t const** text)
{
	mk_dacdbt_value_type_t type;

	mk_assert(panel);
	mk_assert(key);
	mk_assert(value);
	mk_assert(text);

	mk_try(mk_dacdbt_value_get_type(value, &type));
	mk_assert
	(
		(type == mk_dacdbt_value_type_e_u32) ||
		(type == mk_dacdbt_value_type_e_f64) ||
		(type == mk_dacdbt_value_type_e_str) ||
		(type == mk_dacdbt_value_type_e_bin) ||
		(type == mk_dacdbt_value_type_e_fil) ||
		(type == mk_dacdbt_value_type_e_u64)
	);
	switch(type)
	{
		case mk_dacdbt_value_type_e_u32: mk_try(mk_dacdbtw_panel_private_value_text_data_u32_w(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_f64: mk_try(mk_dacdbtw_panel_private_value_text_data_f64_w(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_str: mk_try(mk_dacdbtw_panel_private_value_text_data_str_w(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_bin: mk_try(mk_dacdbtw_panel_private_value_text_data_bin_w(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_fil: mk_try(mk_dacdbtw_panel_private_value_text_data_fil_w(panel, key, value, text)); break;
		case mk_dacdbt_value_type_e_u64: mk_try(mk_dacdbtw_panel_private_value_text_data_u64_w(panel, key, value, text)); break;
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_list_getdispinfo_text(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpct nmhdr;
	mk_win_comctl_listview_dispinfo_lpt dispinfo;
	mk_win_base_user_types_lresult_t lres;
	mk_win_comctl_treeview_htreeitem_t item;
	mk_dacdbt_key_t* key;
	mk_dacdbt_value_t* value;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	mk_assert(panel->m_list);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpct)(lparam));
	mk_assert(nmhdr->m_from == panel->m_list);
	mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa || nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
	dispinfo = ((mk_win_comctl_listview_dispinfo_lpt)(nmhdr));
	mk_assert((dispinfo->m_item.m_a.m_mask & mk_win_comctl_listview_itmflag_text) != 0);

	mk_try(mk_win_user_window_send(panel->m_tree, mk_win_comctl_treeview_wm_getnextitem, mk_win_comctl_treeview_getnextitem_caret, ((mk_win_base_user_types_lparam_t)(0)), &lres));
	mk_assert(lres != 0);
	item = ((mk_win_comctl_treeview_htreeitem_t)(lres));
	mk_try(mk_win_comctl_treeview_item_get_param(panel->m_tree, item, ((void**)(&key))));
	mk_assert(key);

	mk_try(mk_dacdbt_key_get_value(key, dispinfo->m_item.m_a.m_item, &value));
	switch(dispinfo->m_item.m_a.m_subitem)
	{
		case 0:
		{
			#if mk_win_api == mk_win_api_old || mk_win_api == mk_win_api_ansi
			char const* text;
			mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa);
			mk_try(mk_dacdbtw_panel_private_value_text_type_a(value, &text));
			dispinfo->m_item.m_a.m_text = text;
			#elif mk_win_api == mk_win_api_wide
			wchar_t const* text;
			mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
			mk_try(mk_dacdbtw_panel_private_value_text_type_w(value, &text));
			dispinfo->m_item.m_w.m_text = text;
			#elif mk_win_api == mk_win_api_both
			if(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa)
			{
				char const* text;
				mk_try(mk_dacdbtw_panel_private_value_text_type_a(value, &text));
				dispinfo->m_item.m_a.m_text = text;
			}
			else
			{
				wchar_t const* text;
				mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
				mk_try(mk_dacdbtw_panel_private_value_text_type_w(value, &text));
				dispinfo->m_item.m_w.m_text = text;
			}
			#endif
		}
		break;
		case 1:
		{
			#if mk_win_api == mk_win_api_old || mk_win_api == mk_win_api_ansi
			char const* text;
			mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa);
			mk_try(mk_dacdbtw_panel_private_value_text_name_a(panel, value, &text));
			dispinfo->m_item.m_a.m_text = text;
			#elif mk_win_api == mk_win_api_wide
			wchar_t const* text;
			mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
			mk_try(mk_dacdbtw_panel_private_value_text_name_w(panel, value, &text));
			dispinfo->m_item.m_w.m_text = text;
			#elif mk_win_api == mk_win_api_both
			if(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa)
			{
				char const* text;
				mk_try(mk_dacdbtw_panel_private_value_text_name_a(panel, value, &text));
				dispinfo->m_item.m_a.m_text = text;
			}
			else
			{
				wchar_t const* text;
				mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
				mk_try(mk_dacdbtw_panel_private_value_text_name_w(panel, value, &text));
				dispinfo->m_item.m_w.m_text = text;
			}
			#endif
		}
		break;
		case 2:
		{
			#if mk_win_api == mk_win_api_old || mk_win_api == mk_win_api_ansi
			char const* text;
			mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa);
			mk_try(mk_dacdbtw_panel_private_value_text_lenght_a(panel, value, &text));
			dispinfo->m_item.m_a.m_text = text;
			#elif mk_win_api == mk_win_api_wide
			wchar_t const* text;
			mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
			mk_try(mk_dacdbtw_panel_private_value_text_lenght_w(panel, value, &text));
			dispinfo->m_item.m_w.m_text = text;
			#elif mk_win_api == mk_win_api_both
			if(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa)
			{
				char const* text;
				mk_try(mk_dacdbtw_panel_private_value_text_lenght_a(panel, value, &text));
				dispinfo->m_item.m_a.m_text = text;
			}
			else
			{
				wchar_t const* text;
				mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
				mk_try(mk_dacdbtw_panel_private_value_text_lenght_w(panel, value, &text));
				dispinfo->m_item.m_w.m_text = text;
			}
			#endif
		}
		break;
		case 3:
		{
			#if mk_win_api == mk_win_api_old || mk_win_api == mk_win_api_ansi
			char const* text;
			mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa);
			mk_try(mk_dacdbtw_panel_private_value_text_data_a(panel, key, value, &text));
			dispinfo->m_item.m_a.m_text = text;
			#elif mk_win_api == mk_win_api_wide
			wchar_t const* text;
			mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
			mk_try(mk_dacdbtw_panel_private_value_text_data_w(panel, key, value, &text));
			dispinfo->m_item.m_w.m_text = text;
			#elif mk_win_api == mk_win_api_both
			if(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa)
			{
				char const* text;
				mk_try(mk_dacdbtw_panel_private_value_text_data_a(panel, key, value, &text));
				dispinfo->m_item.m_a.m_text = text;
			}
			else
			{
				wchar_t const* text;
				mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
				mk_try(mk_dacdbtw_panel_private_value_text_data_w(panel, key, value, &text));
				dispinfo->m_item.m_w.m_text = text;
			}
			#endif
		}
		break;
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_list_getdispinfo_image(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpct nmhdr;
	mk_win_comctl_listview_dispinfo_lpt dispinfo;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpct)(lparam));
	mk_assert(nmhdr->m_from == panel->m_list);
	mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa || nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
	dispinfo = ((mk_win_comctl_listview_dispinfo_lpt)(nmhdr));
	mk_assert((dispinfo->m_item.m_a.m_mask & mk_win_comctl_listview_itmflag_image) != 0);

	/*dispinfo->m_item.m_a.m_image = 0;*/

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_list_getdispinfo(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpct nmhdr;
	mk_win_comctl_listview_dispinfo_lpct dispinfo;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpct)(lparam));
	mk_assert(nmhdr->m_from == panel->m_list);
	mk_assert(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa || nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow);
	dispinfo = ((mk_win_comctl_listview_dispinfo_lpct)(nmhdr));
	if((dispinfo->m_item.m_a.m_mask & mk_win_comctl_listview_itmflag_text) != 0)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_list_getdispinfo_text(panel, wparam, lparam, skip_defproc, lr));
	}
	if((dispinfo->m_item.m_a.m_mask & mk_win_comctl_listview_itmflag_image) != 0)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_list_getdispinfo_image(panel, wparam, lparam, skip_defproc, lr));
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify_list(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;

	mk_assert(panel);
	mk_assert(panel->m_list);
	((void)(wparam));
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	mk_assert(nmhdr->m_from == panel->m_list);

	if(nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfoa || nmhdr->m_code == mk_win_comctl_listview_notify_getdispinfow)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_list_getdispinfo(panel, wparam, lparam, skip_defproc, lr));
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_notify(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	mk_win_base_user_nmhdr_lpt nmhdr;

	mk_assert(panel);
	mk_assert(panel->m_tree);
	mk_assert(panel->m_list);
	(void)(wparam);
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	nmhdr = ((mk_win_base_user_nmhdr_lpt)(lparam));
	if(nmhdr->m_from == panel->m_tree)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_tree(panel, wparam, lparam, skip_defproc, lr));
	}
	else if(nmhdr->m_from == panel->m_list)
	{
		mk_try(mk_dacdbtw_panel_private_on_wm_notify_list(panel, wparam, lparam, skip_defproc, lr));
	}

	return 0;
}

static mk_inline int mk_dacdbtw_panel_private_on_wm_idle(mk_dacdbtw_panel_t* panel, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* skip_defproc, mk_win_base_user_types_lresult_t* lr)
{
	int* did_something;

	mk_assert(panel);
	mk_assert(wparam == 0);
	mk_assert(lparam != 0);
	mk_assert(skip_defproc);
	mk_assert(lr);

	did_something = ((int*)((mk_win_base_types_void_lpt)(lparam)));
	mk_assert(*did_something == 0);

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
		mk_try(mk_win_user_window_show(panel->m_status, mk_win_user_window_show_show, &b)); (void)b;
		mk_try(mk_win_user_window_show(panel->m_tree, mk_win_user_window_show_show, &b)); (void)b;
		mk_try(mk_win_user_window_show(panel->m_list, mk_win_user_window_show_show, &b)); (void)b;
	}
	else
	{
		mk_try(mk_win_user_window_show(panel->m_list, mk_win_user_window_show_hide, &b)); (void)b;
		mk_try(mk_win_user_window_show(panel->m_tree, mk_win_user_window_show_hide, &b)); (void)b;
		mk_try(mk_win_user_window_show(panel->m_status, mk_win_user_window_show_hide, &b)); (void)b;
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
		case mk_dacdbtw_panel_wm_on_idle: mk_try(mk_dacdbtw_panel_private_on_wm_idle(panel, wparam, lparam, skip_defproc, lr)); break;
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
