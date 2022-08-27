#include "mk_mdi_parent.h"

#include "mk_mdi_parent_constants.h"
#include "mk_mdi_app.h"
#include "mk_mdi_child.h"

#include "../../mk_std/src/mk_std_gcallocator.h"
#include "../../mk_std/src/mk_std_ptr_buff.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_instance.h"
#include "../../mk_win/src/mk_win_kernel_module.h"
#include "../../mk_win/src/mk_win_kernel_resource.h"
#include "../../mk_win/src/mk_win_user_brush.h"
#include "../../mk_win/src/mk_win_user_class.h"
#include "../../mk_win/src/mk_win_user_cursor.h"
#include "../../mk_win/src/mk_win_user_dialog.h"
#include "../../mk_win/src/mk_win_user_icon.h"
#include "../../mk_win/src/mk_win_user_listbox.h"
#include "../../mk_win/src/mk_win_user_menu.h"
#include "../../mk_win/src/mk_win_user_message.h"
#include "../../mk_win/src/mk_win_user_window.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include <stddef.h>


typedef mk_mdi_parent_t mk_win_base_keywords_far* mk_mdi_parent_lpt;


static mk_win_char_t const mk_mdi_parent_private_menu_name[] = mk_win_char_c("mk_mdi_parent_menu");
static mk_win_char_t const mk_mdi_parent_private_class_name[] = mk_win_char_c("mk_mdi_parent_class");


static mk_inline int mk_mdi_parent_private_register_class(void);
static mk_inline int mk_mdi_parent_private_on_create(mk_mdi_parent_pt parent, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_destroy(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_close(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_new_file(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_close_file(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_new_window(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_close_window(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_window_cascade(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_window_cascade_zorder(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_window_tile_vertically(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_window_tile_horizontally(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_window_arrange_icons(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_window_transfer(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_window_close(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu_window_close_all(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_menu(mk_mdi_parent_pt parent, unsigned short menu_id, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_command(mk_mdi_parent_pt parent, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_message(mk_mdi_parent_pt parent, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_dlg_initdialog(mk_mdi_parent_pt parent, mk_win_base_user_types_hwnd_t dlg, mk_win_base_types_cpu_iword_t* ret);
static mk_inline int mk_mdi_parent_private_on_dlg_command(mk_mdi_parent_pt parent, mk_win_base_user_types_hwnd_t dlg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_types_cpu_iword_t* ret);
static mk_inline int mk_mdi_parent_private_on_dlg_message(mk_mdi_parent_pt parent, mk_win_base_user_types_hwnd_t dlg, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_types_cpu_iword_t* ret);
static mk_inline int mk_mdi_parent_private_on_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres);
static mk_inline int mk_mdi_parent_private_on_dlgproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_types_cpu_iword_t* ret);
static mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_mdi_parent_private_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam);
static mk_win_base_types_cpu_iword_t mk_win_base_keywords_calling_convention_api mk_mdi_parent_private_dlgproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam);


mk_jumbo int mk_mdi_parent_init(void)
{
	mk_try(mk_mdi_parent_private_register_class());

	return 0;
}

mk_jumbo int mk_mdi_parent_deinit(void)
{
	return 0;
}

mk_jumbo int mk_mdi_parent_hwnd2object(mk_win_base_user_types_hwnd_t hwnd, mk_mdi_parent_pt* object)
{
	mk_win_base_types_uintptr_t info;
	mk_mdi_parent_pt obj;

	mk_assert(hwnd);
	mk_assert(object);

	mk_try(mk_win_user_window_get_info(hwnd, mk_win_base_user_types_window_info_id_userdata, &info));
	obj = (mk_mdi_parent_pt)(mk_mdi_parent_lpt)info;
	*object = obj;

	return 0;
}

mk_jumbo int mk_mdi_parent_construct(mk_mdi_parent_pt parent, mk_mdi_app_pt app)
{
	mk_win_user_window_create_t wnd;
	mk_win_base_user_types_hwnd_t hwnd;

	mk_assert(parent);
	mk_assert(app);

	parent->m_app = app;
	parent->m_hwnd = NULL;
	parent->m_mdi = NULL;
	mk_try(mk_std_ptr_buff_construct(&parent->m_children));

	wnd.m_extra_style = mk_win_user_window_style_ex_overlappedwindow;
	wnd.m_class_name = mk_mdi_parent_private_class_name;
	wnd.m_window_name = mk_win_char_c("Parent");
	wnd.m_style = mk_win_user_window_style_overlappedwindow | mk_win_user_window_style_clipchildren | mk_win_user_window_style_visible;
	wnd.m_x = mk_win_user_window_default_value;
	wnd.m_y = mk_win_user_window_default_value;
	wnd.m_width = mk_win_user_window_default_value;
	wnd.m_height = mk_win_user_window_default_value;
	wnd.m_parent = NULL;
	wnd.m_menu = NULL;
	mk_try(mk_win_instance_get(&wnd.m_instance));
	wnd.m_param = parent;
	mk_try(mk_win_user_window_create(&wnd, &hwnd));
	mk_assert(parent->m_hwnd == hwnd);

	return 0;
}

mk_jumbo int mk_mdi_parent_destruct(mk_mdi_parent_pt parent)
{
	mk_assert(parent);

	mk_try(mk_std_ptr_buff_destruct(&parent->m_children));

	return 0;
}

mk_jumbo int mk_mdi_parent_show(mk_mdi_parent_pt parent, int show)
{
	mk_win_base_types_bool_t b;

	mk_assert(parent);
	mk_assert(parent->m_hwnd);

	mk_try(mk_win_user_window_show(parent->m_hwnd, show, &b));
	(void)b;

	return 0;
}

mk_jumbo int mk_mdi_parent_close(mk_mdi_parent_pt parent)
{
	mk_assert(parent);
	mk_assert(parent->m_hwnd);

	mk_try(mk_win_user_window_send_close(parent->m_hwnd));

	return 0;
}

mk_jumbo int mk_mdi_parent_children_add(mk_mdi_parent_pt parent, mk_mdi_child_pt old_child)
{
	mk_mdi_child_pt child;

	mk_assert(parent);

	mk_try(mk_std_ptr_buff_reserve_one(&parent->m_children));
	mk_try(mk_std_gcallocator_allocate(sizeof(*child), (void**)&child));
	mk_try(mk_std_ptr_buff_append(&parent->m_children, child));
	mk_try(mk_mdi_child_construct(child, parent, old_child));
	if(old_child)
	{
		mk_try(mk_mdi_child_close(old_child));
	}

	return 0;
}

mk_jumbo int mk_mdi_parent_children_get_active(mk_mdi_parent_pt parent, mk_mdi_child_pt* child)
{
	mk_win_base_types_bool_t b;
	mk_win_base_user_types_lresult_t lr;
	mk_win_base_user_types_hwnd_t childwnd;
	int maximized;
	mk_mdi_child_pt chld;

	mk_assert(parent);
	mk_assert(parent->m_mdi);
	mk_assert(child);

	mk_try(mk_win_user_window_send(parent->m_mdi, mk_win_user_message_id_mdigetactive, 0, (mk_win_base_user_types_lparam_t)(mk_win_base_types_bool_lpt)&b, &lr));
	if(lr != 0)
	{
		childwnd = (mk_win_base_user_types_hwnd_t)lr;
		maximized = b != 0;
		mk_try(mk_mdi_child_hwnd2object(childwnd, &chld));
		mk_assert(chld);
		*child = chld;
	}
	else
	{
		*child = NULL;
	}

	return 0;
}

mk_jumbo int mk_mdi_parent_children_close_active(mk_mdi_parent_pt parent)
{
	mk_mdi_child_pt child;

	mk_assert(parent);

	mk_try(mk_mdi_parent_children_get_active(parent, &child));
	if(child)
	{
		mk_try(mk_mdi_child_close(child));
	}

	return 0;
}

mk_jumbo int mk_mdi_parent_children_cascade(mk_mdi_parent_pt parent)
{
	mk_win_base_user_types_lresult_t r;

	mk_assert(parent);
	mk_assert(parent->m_mdi);

	mk_try(mk_win_user_window_send(parent->m_mdi, mk_win_user_message_id_mdicascade, 0, 0, &r));
	(void)r;

	return 0;
}

mk_jumbo int mk_mdi_parent_children_cascade_zorder(mk_mdi_parent_pt parent)
{
	mk_win_base_user_types_lresult_t r;

	mk_assert(parent);
	mk_assert(parent->m_mdi);

	mk_try(mk_win_user_window_send(parent->m_mdi, mk_win_user_message_id_mdicascade, mk_win_user_message_param_mditile_zorder, 0, &r));
	(void)r;

	return 0;
}

mk_jumbo int mk_mdi_parent_children_tile_vertically(mk_mdi_parent_pt parent)
{
	mk_win_base_user_types_lresult_t r;

	mk_assert(parent);
	mk_assert(parent->m_mdi);

	mk_try(mk_win_user_window_send(parent->m_mdi, mk_win_user_message_id_mditile, mk_win_user_message_param_mditile_vertical, 0, &r));
	(void)r;

	return 0;
}

mk_jumbo int mk_mdi_parent_children_tile_horizontally(mk_mdi_parent_pt parent)
{
	mk_win_base_user_types_lresult_t r;

	mk_assert(parent);
	mk_assert(parent->m_mdi);

	mk_try(mk_win_user_window_send(parent->m_mdi, mk_win_user_message_id_mditile, mk_win_user_message_param_mditile_horizontal, 0, &r));
	(void)r;

	return 0;
}

mk_jumbo int mk_mdi_parent_children_arrange_icons(mk_mdi_parent_pt parent)
{
	mk_win_base_user_types_lresult_t r;

	mk_assert(parent);
	mk_assert(parent->m_mdi);

	mk_try(mk_win_user_window_send(parent->m_mdi, mk_win_user_message_id_mdiiconarrange, 0, 0, &r));
	(void)r;

	return 0;
}

mk_jumbo int mk_mdi_parent_children_transfer(mk_mdi_parent_pt parent)
{
	mk_mdi_child_pt child;
	mk_win_base_types_hinstance_t instance;
	mk_win_base_kernel_types_hmodule_t module;
	mk_win_base_kernel_types_hrsrc_t resource;
	mk_win_base_kernel_types_hglobal_t global;
	mk_win_base_types_cpu_iword_t dlg_ret;
	mk_mdi_parent_pt prnt;

	mk_assert(parent);

	mk_try(mk_mdi_parent_children_get_active(parent, &child));
	if(child)
	{
		mk_try(mk_win_instance_get(&instance)); mk_assert(instance); module = (mk_win_base_kernel_types_hmodule_t)instance;
		mk_try(mk_win_kernel_resource_find_bytypeid(module, "mk_mdi_parent_transfer", mk_win_kernel_resource_type_dialog, &resource)); mk_assert(resource);
		mk_try(mk_win_kernel_resource_load(module, resource, &global)); mk_assert(global);
		mk_try(mk_win_user_dialog_indirect_param(instance, global, parent->m_hwnd, &mk_mdi_parent_private_dlgproc, (mk_win_base_user_types_lparam_t)(mk_mdi_parent_lpt)parent, &dlg_ret));
		if(dlg_ret != 0)
		{
			mk_try(mk_std_ptr_buff_get_element(&parent->m_app->m_parents, dlg_ret - 1, (void**)&prnt)); mk_assert(prnt);
			mk_try(mk_mdi_parent_children_add(prnt, child));
		}
	}

	return 0;
}

mk_jumbo int mk_mdi_parent_children_close_all(mk_mdi_parent_pt parent)
{
	size_t count;
	size_t i;
	mk_mdi_child_pt child;

	mk_assert(parent);

	mk_try(mk_std_ptr_buff_get_count(&parent->m_children, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&parent->m_children, count - 1 - i, (void**)&child));
		mk_try(mk_mdi_child_close(child));
	}

	return 0;
}

mk_jumbo int mk_mdi_parent_on_child_destroy(mk_mdi_parent_pt parent, mk_mdi_child_pt child)
{
	mk_assert(parent);
	mk_assert(child);

	mk_try(mk_std_ptr_buff_remove_val(&parent->m_children, child));
	mk_try(mk_mdi_child_destruct(child));
	mk_try(mk_std_gcallocator_deallocate(child));

	return 0;
}


static mk_inline int mk_mdi_parent_private_register_class(void)
{
	mk_win_user_class_t cls;
	mk_win_base_types_atom_t atom;

	cls.m_style = 0;
	cls.m_wndproc = &mk_mdi_parent_private_wndproc;
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
	mk_assert(atom != 0);

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_create(mk_mdi_parent_pt parent, mk_win_base_user_types_lparam_t lparam, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_win_base_user_types_wm_create_a_lpct create;
	mk_win_base_user_client_create_t client_create;
	mk_win_base_user_types_hmenu_t menu_bar;
	mk_win_base_user_types_hmenu_t menu_window;
	mk_win_user_window_create_t wnd;
	mk_win_base_user_types_hwnd_t mdi;

	mk_assert(parent);
	mk_assert(lparam != 0);
	mk_assert(override_defproc);
	mk_assert(lres);

	create = (mk_win_base_user_types_wm_create_a_lpct)lparam;
	(void)create;

	mk_try(mk_win_user_menu_get(parent->m_hwnd, &menu_bar));
	mk_assert(menu_bar);
	mk_try(mk_win_user_menu_get_sub(menu_bar, 1, &menu_window));
	mk_assert(menu_window);
	client_create.m_menu = menu_window;
	client_create.m_first_child_id = mk_mdi_parent_menu_id_window_children;
	wnd.m_extra_style = 0;
	wnd.m_class_name = mk_win_char_c("mdiclient");
	wnd.m_window_name = NULL;
	wnd.m_style = mk_win_user_window_style_hscroll | mk_win_user_window_style_vscroll | mk_win_user_window_style_clipchildren | mk_win_user_window_style_visible | mk_win_user_window_style_child;
	wnd.m_x = 0;
	wnd.m_y = 0;
	wnd.m_width = 0;
	wnd.m_height = 0;
	wnd.m_parent = parent->m_hwnd;
	wnd.m_menu = 0;
	mk_try(mk_win_instance_get(&wnd.m_instance));
	wnd.m_param = (mk_win_base_types_void_t)&client_create;
	mk_try(mk_win_user_window_create(&wnd, &mdi));
	mk_assert(mdi);
	parent->m_mdi = mdi;

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_destroy(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_win_base_types_uintptr_t prev;

	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_win_user_window_set_info(parent->m_hwnd, mk_win_base_user_types_window_info_id_userdata, 0, &prev));
	mk_assert((mk_mdi_parent_pt)(mk_mdi_parent_lpt)prev == parent);

	mk_try(mk_mdi_app_on_parent_destroy(parent->m_app, parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_close(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	int ok;
	size_t count;
	size_t i;
	mk_mdi_child_pt child;
	mk_win_base_user_types_lresult_t lr;
	mk_win_base_types_bool_t b;

	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	ok = 1;
	mk_try(mk_std_ptr_buff_get_count(&parent->m_children, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&parent->m_children, i, (void**)&child));
		mk_try(mk_win_user_window_send(child->m_hwnd, mk_win_user_message_id_queryendsession, 0, 0, &lr));
		if(lr == 0)
		{
			ok = 0;
			break;
		}
	}
	if(ok != 0)
	{
		mk_try(mk_win_user_window_show(parent->m_hwnd, mk_win_user_window_show_hide, &b));
		
	}
	mk_try(mk_mdi_parent_children_close_all(parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_new_file(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_add(parent, NULL));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_close_file(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_close_active(parent));

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

static mk_inline int mk_mdi_parent_private_on_menu_window_cascade(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_cascade(parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_window_cascade_zorder(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_cascade_zorder(parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_window_tile_vertically(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_tile_vertically(parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_window_tile_horizontally(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_tile_horizontally(parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_window_arrange_icons(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_arrange_icons(parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_window_transfer(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_transfer(parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_window_close(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_close_active(parent));

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_menu_window_close_all(mk_mdi_parent_pt parent, int* override_defproc, mk_win_base_user_types_lresult_t* lres)
{
	mk_assert(parent);
	mk_assert(override_defproc);
	mk_assert(lres);

	mk_try(mk_mdi_parent_children_close_all(parent));

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
		case mk_mdi_parent_menu_id_window_cascade: mk_try(mk_mdi_parent_private_on_menu_window_cascade(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_window_cascade_zorder: mk_try(mk_mdi_parent_private_on_menu_window_cascade_zorder(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_window_tile_vertically: mk_try(mk_mdi_parent_private_on_menu_window_tile_vertically(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_window_tile_horizontally: mk_try(mk_mdi_parent_private_on_menu_window_tile_horizontally(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_window_arrange_icons: mk_try(mk_mdi_parent_private_on_menu_window_arrange_icons(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_window_transfer: mk_try(mk_mdi_parent_private_on_menu_window_transfer(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_window_close: mk_try(mk_mdi_parent_private_on_menu_window_close(parent, override_defproc, lres)); break;
		case mk_mdi_parent_menu_id_window_close_all: mk_try(mk_mdi_parent_private_on_menu_window_close_all(parent, override_defproc, lres)); break;
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
		case mk_win_base_user_types_window_wm_create: mk_try(mk_mdi_parent_private_on_create(parent, lparam, override_defproc, lres)); break;
		case mk_win_base_user_types_window_wm_destroy: mk_try(mk_mdi_parent_private_on_destroy(parent, override_defproc, lres)); break;
		case mk_win_base_user_types_window_wm_close: mk_try(mk_mdi_parent_private_on_close(parent, override_defproc, lres)); break;
		case mk_win_base_user_types_window_wm_command: mk_try(mk_mdi_parent_private_on_command(parent, wparam, lparam, override_defproc, lres)); break;
	}

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_dlg_initdialog(mk_mdi_parent_pt parent, mk_win_base_user_types_hwnd_t dlg, mk_win_base_types_cpu_iword_t* ret)
{
	mk_win_base_user_types_hwnd_t list;
	size_t parents_count;
	size_t i;
	mk_mdi_parent_pt prnt;
	wchar_t name[512];
	mk_win_base_user_types_lresult_t lr;
	mk_win_base_user_types_hwnd_t dummy;

	mk_assert(parent);
	mk_assert(dlg);
	mk_assert(ret);

	mk_try(mk_win_user_dialog_get_item(dlg, mk_mdi_parent_transfer_id_list, &list)); mk_assert(list);
	mk_try(mk_std_ptr_buff_get_count(&parent->m_app->m_parents, &parents_count));
	for(i = 0; i != parents_count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&parent->m_app->m_parents, i, (void**)&prnt)); mk_assert(prnt); mk_assert(prnt->m_hwnd);
		if(prnt == parent)
		{
			continue;
		}
		/* TODO: Get parent name from model instead from view. */
		mk_try(mk_win_user_window_send(prnt->m_hwnd, mk_win_base_user_types_window_wm_gettext, 512, (mk_win_base_user_types_lparam_t)(mk_win_base_types_strw_t)&name, &lr)); mk_assert(lr != 0);
		mk_try(mk_win_user_window_send(list, mk_win_user_listbox_wm_addstring, 0, (mk_win_base_user_types_lparam_t)(mk_win_base_types_strwc_t)&name, &lr)); mk_assert(lr >= 0);
		mk_try(mk_win_user_window_send(list, mk_win_user_listbox_wm_setitemdata, (mk_win_base_user_types_wparam_t)lr, (mk_win_base_user_types_lparam_t)i, &lr)); mk_assert(lr != mk_win_user_listbox_error_err);
	}
	mk_try(mk_win_user_window_send(list, mk_win_user_listbox_wm_setcursel, 0, 0, &lr));
	mk_try(mk_win_user_window_set_focus(list, &dummy)); mk_assert(dummy);

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_dlg_command(mk_mdi_parent_pt parent, mk_win_base_user_types_hwnd_t dlg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_types_cpu_iword_t* ret)
{
	int gud;
	int bad;
	mk_win_base_types_uint16_t wlo;
	mk_win_base_types_uint16_t whi;
	mk_win_base_types_bool_t b;
	mk_win_base_user_types_hwnd_t control;
	mk_win_base_user_types_lresult_t lr;
	int prnt;

	mk_assert(parent);
	mk_assert(dlg);
	mk_assert(ret);

	gud = 0;
	bad = 0;
	wlo = (mk_win_base_types_uint16_t)(wparam & 0xffffu);
	whi = (mk_win_base_types_uint16_t)((wparam >> 16) & 0xffffu);
	if(lparam == 0)
	{
		if(whi == 0)
		{
			switch(wlo)
			{
				case mk_win_user_dialog_cmdid_cancel:
				{
					bad = 1;
				}
				break;
			}
		}
	}
	else
	{
		switch(wlo)
		{
			case mk_mdi_parent_transfer_id_list:
			{
				mk_try(mk_win_user_dialog_get_item(dlg, mk_mdi_parent_transfer_id_list, &control)); mk_assert(control); mk_assert((mk_win_base_user_types_hwnd_t)lparam == control);
				if(whi == mk_win_user_listbox_notify_dblclk)
				{
					gud = 1;
				}
			}
			break;
			case mk_mdi_parent_transfer_id_ok:
			{
				mk_try(mk_win_user_dialog_get_item(dlg, mk_mdi_parent_transfer_id_ok, &control)); mk_assert(control); mk_assert((mk_win_base_user_types_hwnd_t)lparam == control);
				gud = 1;
			}
			break;
			case mk_mdi_parent_transfer_id_cancel:
			{
				mk_try(mk_win_user_dialog_get_item(dlg, mk_mdi_parent_transfer_id_cancel, &control)); mk_assert(control); mk_assert((mk_win_base_user_types_hwnd_t)lparam == control);
				bad = 1;
			}
			break;
		}
	}
	if(gud || bad)
	{
		mk_assert(!(gud && bad));
		prnt = 0;
		if(gud)
		{
			mk_try(mk_win_user_dialog_get_item(dlg, mk_mdi_parent_transfer_id_list, &control)); mk_assert(control);
			mk_try(mk_win_user_window_send(control, mk_win_user_listbox_wm_getcursel, 0, 0, &lr));
			if(lr >= 0)
			{
				mk_try(mk_win_user_window_send(control, mk_win_user_listbox_wm_getitemdata, (mk_win_base_user_types_wparam_t)lr, 0, &lr));
				prnt = ((int)lr) + 1;
			}
		}
		mk_try(mk_win_user_dialog_end(dlg, prnt, &b)); mk_assert(b);
	}

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_dlg_message(mk_mdi_parent_pt parent, mk_win_base_user_types_hwnd_t dlg, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_types_cpu_iword_t* ret)
{
	mk_assert(parent);
	mk_assert(ret);

	switch(msg)
	{
		case mk_win_base_user_types_window_wm_initdialog: mk_try(mk_mdi_parent_private_on_dlg_initdialog(parent, dlg, ret)); break;
		case mk_win_base_user_types_window_wm_command: mk_try(mk_mdi_parent_private_on_dlg_command(parent, dlg, wparam, lparam, ret)); break;
	}

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres)
{
	int override_defproc;
	mk_mdi_parent_pt parent;
	mk_win_base_user_types_hwnd_t mdi;

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
	mk_try(mk_mdi_parent_hwnd2object(hwnd, &parent));
	if(parent)
	{
		mdi = parent->m_mdi;
		mk_try(mk_mdi_parent_private_on_message(parent, msg, wparam, lparam, &override_defproc, lres));
	}
	else
	{
		mdi = NULL;
	}
	if(!override_defproc)
	{
		mk_try(mk_win_user_window_defframeproc(hwnd, mdi, msg, wparam, lparam, lres));
	}

	return 0;
}

static mk_inline int mk_mdi_parent_private_on_dlgproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_types_cpu_iword_t* ret)
{
	mk_mdi_parent_pt parent;
	mk_win_base_types_uintptr_t nfo;

	mk_assert(hwnd);
	mk_assert(ret);

	if(msg == mk_win_base_user_types_window_wm_initdialog)
	{
		mk_assert(lparam != 0);
		parent = (mk_mdi_parent_pt)lparam;
		mk_assert(parent);
		mk_try(mk_win_user_window_set_info(hwnd, mk_win_base_user_types_window_info_id_dlg_user, (mk_win_base_types_uintptr_t)(mk_mdi_parent_lpt)parent, &nfo));
		mk_assert(nfo == 0);
	}
	else
	{
		mk_try(mk_win_user_window_get_info(hwnd, mk_win_base_user_types_window_info_id_dlg_user, &nfo));
		parent = (mk_mdi_parent_pt)(mk_mdi_parent_lpt)nfo;
	}
	if(parent)
	{
		mk_try(mk_mdi_parent_private_on_dlg_message(parent, hwnd, msg, wparam, lparam, ret));
	}

	return 0;
}

static mk_win_base_user_types_lresult_t mk_win_base_keywords_calling_convention_api mk_mdi_parent_private_wndproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam)
{
	int err;
	mk_win_base_user_types_lresult_t lres;

	err = mk_mdi_parent_private_on_wndproc(hwnd, msg, wparam, lparam, &lres);
	mk_assert(err == 0);

	return lres;
}

static mk_win_base_types_cpu_iword_t mk_win_base_keywords_calling_convention_api mk_mdi_parent_private_dlgproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam)
{
	int err;
	mk_win_base_types_cpu_iword_t ret;

	ret = 0;
	err = mk_mdi_parent_private_on_dlgproc(hwnd, msg, wparam, lparam, &ret);
	mk_assert(err == 0);

	return ret;
}
