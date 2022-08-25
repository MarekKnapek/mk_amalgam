#ifndef mk_include_guard_win_user_window
#define mk_include_guard_win_user_window


#include "mk_win_user_window_constants.h"
#include "mk_win_str.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_platform.h"


struct mk_win_user_window_create_s
{
	mk_win_base_types_dword_t m_extra_style;
	mk_win_strc_t m_class_name;
	mk_win_strc_t m_window_name;
	mk_win_base_types_dword_t m_style;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	mk_win_base_user_types_hwnd_t m_parent;
	mk_win_base_user_types_hmenu_t m_menu;
	mk_win_base_types_hinstance_t m_instance;
	mk_win_base_types_void_t m_param;
};
typedef struct mk_win_user_window_create_s mk_win_user_window_create_t;
typedef mk_win_user_window_create_t* mk_win_user_window_create_pt;
typedef mk_win_user_window_create_t const* mk_win_user_window_create_pct;

struct mk_win_user_window_mdicreate_s
{
	mk_win_strc_t m_class_name;
	mk_win_strc_t m_window_name;
	mk_win_base_types_hinstance_t m_instance;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	mk_win_base_types_dword_t m_style;
	mk_win_base_types_void_t m_param;
};
typedef struct mk_win_user_window_mdicreate_s mk_win_user_window_mdicreate_t;
typedef mk_win_user_window_mdicreate_t const* mk_win_user_window_mdicreate_pct;


#if mk_win_base_platform_os == mk_win_base_platform_os_win16
#define mk_win_user_window_default_value ((int)0x8000)
#else
#define mk_win_user_window_default_value ((int)0x80000000)
#endif

#define mk_win_user_window_show_hide            0
#define mk_win_user_window_show_shownormal      1
#define mk_win_user_window_show_normal          1
#define mk_win_user_window_show_showminimized   2
#define mk_win_user_window_show_showmaximized   3
#define mk_win_user_window_show_maximize        3
#define mk_win_user_window_show_shownoactivate  4
#define mk_win_user_window_show_show            5
#define mk_win_user_window_show_minimize        6
#define mk_win_user_window_show_showminnoactiv  7
#define mk_win_user_window_show_showna          8
#define mk_win_user_window_show_restore         9
#define mk_win_user_window_show_showdefault    10
#define mk_win_user_window_show_forceminimize  11
#define mk_win_user_window_show_max            11


mk_jumbo int mk_win_user_window_create(mk_win_user_window_create_pct wnd_info, mk_win_base_user_types_hwnd_t* hwnd);
mk_jumbo int mk_win_user_window_set_info(mk_win_base_user_types_hwnd_t hwnd, int info_id, mk_win_base_types_uintptr_t info, mk_win_base_types_uintptr_t* prev_info);
mk_jumbo int mk_win_user_window_get_info(mk_win_base_user_types_hwnd_t hwnd, int info_id, mk_win_base_types_uintptr_t* info);
mk_jumbo int mk_win_user_window_defproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres);
mk_jumbo int mk_win_user_window_defframeproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_hwnd_t mdi, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres);
mk_jumbo int mk_win_user_window_defmdichildproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres);
mk_jumbo int mk_win_user_window_show(mk_win_base_user_types_hwnd_t hwnd, int show, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_window_move(mk_win_base_user_types_hwnd_t hwnd, int x, int y, int width, int height, mk_win_base_types_bool_t repaint, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_window_get_rect(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_rect_pt rect, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_window_get_client_rect(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_rect_pt rect, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_window_set_focus(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_hwnd_t* ret);
mk_jumbo int mk_win_user_window_set_parent(mk_win_base_user_types_hwnd_t child, mk_win_base_user_types_hwnd_t new_parent, mk_win_base_user_types_hwnd_t* ret);
mk_jumbo int mk_win_user_window_post(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_window_send(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* ret);
mk_jumbo int mk_win_user_window_is_child(mk_win_base_user_types_hwnd_t parent, mk_win_base_user_types_hwnd_t child, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_window_is_screen2client(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_point_pt pt, mk_win_base_types_bool_t* ret);

mk_jumbo int mk_win_user_window_post_close(mk_win_base_user_types_hwnd_t hwnd);

mk_jumbo int mk_win_user_window_send_close(mk_win_base_user_types_hwnd_t hwnd);
mk_jumbo int mk_win_user_window_send_mdicreate(mk_win_base_user_types_hwnd_t hwnd, mk_win_user_window_mdicreate_pct mdi, mk_win_base_user_types_hwnd_t* mdihwnd);


#endif
