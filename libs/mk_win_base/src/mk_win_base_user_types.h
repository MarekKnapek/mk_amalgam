#ifndef mk_win_base_user_types
#define mk_win_base_user_types


#include "mk_win_base_types.h"
#include "mk_win_base_keywords.h"


#define mk_win_base_user_types_window_info_id_userdata      ((int)-21)
#define mk_win_base_user_types_window_info_id_exstyle       ((int)-20)
#define mk_win_base_user_types_window_info_id_style         ((int)-16)
#define mk_win_base_user_types_window_info_id_id            ((int)-12)
#define mk_win_base_user_types_window_info_id_hwndparent    ((int)-8)
#define mk_win_base_user_types_window_info_id_hinstance     ((int)-6)
#define mk_win_base_user_types_window_info_id_wndproc       ((int)-4)
#define mk_win_base_user_types_window_info_id_dlg_msgresult ((int)0)
#define mk_win_base_user_types_window_info_id_dlg_dlgproc   ((int)(mk_win_base_user_types_window_info_id_dlg_msgresult + sizeof(mk_win_base_types_intptr_t)))
#define mk_win_base_user_types_window_info_id_dlg_user      ((int)(mk_win_base_user_types_window_info_id_dlg_dlgproc + sizeof(mk_win_base_user_types_dlgproc_t)))

#define mk_win_base_user_types_window_wm_null       ((unsigned short)0x0000u)
#define mk_win_base_user_types_window_wm_create     ((unsigned short)0x0001u)
#define mk_win_base_user_types_window_wm_destroy    ((unsigned short)0x0002u)
#define mk_win_base_user_types_window_wm_size       ((unsigned short)0x0005u)
#define mk_win_base_user_types_window_wm_gettext    ((unsigned short)0x000du)
#define mk_win_base_user_types_window_wm_close      ((unsigned short)0x0010u)
#define mk_win_base_user_types_window_wm_quit       ((unsigned short)0x0012u)
#define mk_win_base_user_types_window_wm_initdialog ((unsigned short)0x0110u)
#define mk_win_base_user_types_window_wm_command    ((unsigned short)0x0111u)

#define mk_win_base_user_types_window_wparam_wm_size_restored  0
#define mk_win_base_user_types_window_wparam_wm_size_minimized 1
#define mk_win_base_user_types_window_wparam_wm_size_maximized 2
#define mk_win_base_user_types_window_wparam_wm_size_maxshow   3
#define mk_win_base_user_types_window_wparam_wm_size_maxhide   4


typedef mk_win_base_types_intptr_t mk_win_base_user_types_lresult_t;
typedef mk_win_base_types_cpu_word_t mk_win_base_user_types_wparam_t;
typedef mk_win_base_types_uintptr_t mk_win_base_user_types_lparam_t;

mk_win_base_types_make_handle(mk_win_base_user_types_hbrush_t);
mk_win_base_types_make_handle(mk_win_base_user_types_hcursor_t);
mk_win_base_types_make_handle(mk_win_base_user_types_hicon_t);
mk_win_base_types_make_handle(mk_win_base_user_types_hmenu_t);
mk_win_base_types_make_handle(mk_win_base_user_types_hwnd_t);

typedef mk_win_base_user_types_lresult_t(mk_win_base_keywords_calling_convention_api*mk_win_base_user_types_wndproc_t)(mk_win_base_user_types_hwnd_t, mk_win_base_types_uint_t, mk_win_base_user_types_wparam_t, mk_win_base_user_types_lparam_t);
typedef mk_win_base_types_cpu_iword_t(mk_win_base_keywords_calling_convention_api*mk_win_base_user_types_dlgproc_t)(mk_win_base_user_types_hwnd_t, mk_win_base_types_uint_t, mk_win_base_user_types_wparam_t, mk_win_base_user_types_lparam_t);


struct mk_win_base_user_types_class_a_s
{
	mk_win_base_types_uint_t m_style;
	mk_win_base_user_types_wndproc_t m_wndproc;
	int m_cls_extra;
	int m_wnd_extra;
	mk_win_base_types_hinstance_t m_hinstance;
	mk_win_base_user_types_hicon_t m_hicon;
	mk_win_base_user_types_hcursor_t m_hcursor;
	mk_win_base_user_types_hbrush_t m_background;
	mk_win_base_types_char_lpct m_menu_name;
	mk_win_base_types_char_lpct m_class_name;
};
mk_win_base_types_make_struct(mk_win_base_user_types_class_a);
struct mk_win_base_user_types_class_w_s
{
	mk_win_base_types_uint_t m_style;
	mk_win_base_user_types_wndproc_t m_wndproc;
	int m_cls_extra;
	int m_wnd_extra;
	mk_win_base_types_hinstance_t m_hinstance;
	mk_win_base_user_types_hicon_t m_hicon;
	mk_win_base_user_types_hcursor_t m_hcursor;
	mk_win_base_user_types_hbrush_t m_background;
	mk_win_base_types_wchar_lpct m_menu_name;
	mk_win_base_types_wchar_lpct m_class_name;
};
mk_win_base_types_make_struct(mk_win_base_user_types_class_w);
struct mk_win_base_user_types_class_exa_s
{
	mk_win_base_types_uint_t m_size;
	mk_win_base_types_uint_t m_style;
	mk_win_base_user_types_wndproc_t m_wndproc;
	int m_cls_extra;
	int m_wnd_extra;
	mk_win_base_types_hinstance_t m_hinstance;
	mk_win_base_user_types_hicon_t m_hicon;
	mk_win_base_user_types_hcursor_t m_hcursor;
	mk_win_base_user_types_hbrush_t m_background;
	mk_win_base_types_char_lpct m_menu_name;
	mk_win_base_types_char_lpct m_class_name;
	mk_win_base_user_types_hicon_t m_small_icon;
};
mk_win_base_types_make_struct(mk_win_base_user_types_class_exa);
struct mk_win_base_user_types_class_exw_s
{
	mk_win_base_types_uint_t m_size;
	mk_win_base_types_uint_t m_style;
	mk_win_base_user_types_wndproc_t m_wndproc;
	int m_cls_extra;
	int m_wnd_extra;
	mk_win_base_types_hinstance_t m_hinstance;
	mk_win_base_user_types_hicon_t m_hicon;
	mk_win_base_user_types_hcursor_t m_hcursor;
	mk_win_base_user_types_hbrush_t m_background;
	mk_win_base_types_wchar_lpct m_menu_name;
	mk_win_base_types_wchar_lpct m_class_name;
	mk_win_base_user_types_hicon_t m_small_icon;
};
mk_win_base_types_make_struct(mk_win_base_user_types_class_exw);

struct mk_win_base_user_types_dlg_template_s
{
	mk_win_base_types_dword_t m_style;
	mk_win_base_types_dword_t m_extra_style;
	mk_win_base_types_word_t m_item_count;
	short m_x;
	short m_y;
	short m_width;
	short m_height;
};
mk_win_base_types_make_struct(mk_win_base_user_types_dlg_template);

struct mk_win_base_user_types_msg_s
{
	mk_win_base_user_types_hwnd_t m_hwnd;
	mk_win_base_types_uint_t m_msg;
	mk_win_base_user_types_wparam_t m_wparam;
	mk_win_base_user_types_lparam_t m_lparam;
	mk_win_base_types_dword_t m_time;
	mk_win_base_types_point_t m_point;
};
mk_win_base_types_make_struct(mk_win_base_user_types_msg);

struct mk_win_base_user_types_wm_create_a_s
{
	mk_win_base_types_void_lpt m_param;
	mk_win_base_types_hinstance_t m_instance;
	mk_win_base_user_types_hmenu_t m_menu;
	mk_win_base_user_types_hwnd_t m_parent;
	int m_height;
	int m_width;
	int m_y;
	int m_x;
	mk_win_base_types_dword_t m_style;
	mk_win_base_types_char_lpct m_name;
	mk_win_base_types_char_lpct m_class;
	mk_win_base_types_dword_t m_extra_style;
};
mk_win_base_types_make_struct(mk_win_base_user_types_wm_create_a);
struct mk_win_base_user_types_wm_create_w_s
{
	mk_win_base_types_void_lpt m_param;
	mk_win_base_types_hinstance_t m_instance;
	mk_win_base_user_types_hmenu_t m_menu;
	mk_win_base_user_types_hwnd_t m_parent;
	int m_height;
	int m_width;
	int m_y;
	int m_x;
	mk_win_base_types_dword_t m_style;
	mk_win_base_types_wchar_lpct m_name;
	mk_win_base_types_wchar_lpct m_class;
	mk_win_base_types_dword_t m_extra_style;
};
mk_win_base_types_make_struct(mk_win_base_user_types_wm_create_w);

struct mk_win_base_user_client_create_s
{
	mk_win_base_user_types_hmenu_t m_menu;
	mk_win_base_types_uint_t m_first_child_id;
};
mk_win_base_types_make_struct(mk_win_base_user_client_create);

struct mk_win_base_user_wm_mdicreate_a_s
{
	mk_win_base_types_char_lpct m_class_name;
	mk_win_base_types_char_lpct m_window_name;
	mk_win_base_types_hinstance_t m_instance;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	mk_win_base_types_dword_t m_style;
	mk_win_base_types_void_lpt m_param;
};
mk_win_base_types_make_struct(mk_win_base_user_wm_mdicreate_a);
struct mk_win_base_user_wm_mdicreate_w_s
{
	mk_win_base_types_wchar_lpct m_class_name;
	mk_win_base_types_wchar_lpct m_window_name;
	mk_win_base_types_hinstance_t m_instance;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	mk_win_base_types_dword_t m_style;
	mk_win_base_types_void_lpt m_param;
};
mk_win_base_types_make_struct(mk_win_base_user_wm_mdicreate_w);


#endif
