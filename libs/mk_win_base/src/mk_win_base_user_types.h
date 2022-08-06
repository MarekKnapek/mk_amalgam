#ifndef mk_win_base_user_types
#define mk_win_base_user_types


#include "mk_win_base_types.h"
#include "mk_win_base_keywords.h"


typedef mk_win_base_types_intptr_t mk_win_base_user_types_lresult_t;
typedef mk_win_base_types_cpu_word_t mk_win_base_user_types_wparam_t;
typedef mk_win_base_types_uintptr_t mk_win_base_user_types_lparam_t;

struct mk_win_base_user_types_hbrush_s; typedef struct mk_win_base_user_types_hbrush_s const mk_win_base_keywords_near* mk_win_base_user_types_hbrush_t;
struct mk_win_base_user_types_hcursor_s; typedef struct mk_win_base_user_types_hcursor_s const mk_win_base_keywords_near* mk_win_base_user_types_hcursor_t;
struct mk_win_base_user_types_hicon_s; typedef struct mk_win_base_user_types_hicon_s const mk_win_base_keywords_near* mk_win_base_user_types_hicon_t;
struct mk_win_base_user_types_hmenu_s; typedef struct mk_win_base_user_types_hmenu_s const mk_win_base_keywords_near* mk_win_base_user_types_hmenu_t;
struct mk_win_base_user_types_hwnd_s; typedef struct mk_win_base_user_types_hwnd_s const mk_win_base_keywords_near* mk_win_base_user_types_hwnd_t;

typedef mk_win_base_user_types_lresult_t(mk_win_base_keywords_calling_convention_api*mk_win_base_user_types_wndproc_t)(mk_win_base_user_types_hwnd_t, mk_win_base_types_uint_t, mk_win_base_user_types_wparam_t, mk_win_base_user_types_lparam_t);


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
	mk_win_base_types_strac_t m_menu_name;
	mk_win_base_types_strac_t m_class_name;
};
typedef struct mk_win_base_user_types_class_a_s mk_win_base_user_types_class_a_t;
typedef mk_win_base_user_types_class_a_t const mk_win_base_keywords_far* mk_win_base_user_types_class_a_lpt;
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
	mk_win_base_types_strwc_t m_menu_name;
	mk_win_base_types_strwc_t m_class_name;
};
typedef struct mk_win_base_user_types_class_w_s mk_win_base_user_types_class_w_t;
typedef mk_win_base_user_types_class_w_t const mk_win_base_keywords_far* mk_win_base_user_types_class_w_lpt;
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
	mk_win_base_types_strac_t m_menu_name;
	mk_win_base_types_strac_t m_class_name;
	mk_win_base_user_types_hicon_t m_small_icon;
};
typedef struct mk_win_base_user_types_class_exa_s mk_win_base_user_types_class_exa_t;
typedef mk_win_base_user_types_class_exa_t const mk_win_base_keywords_far* mk_win_base_user_types_class_exa_lpt;
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
	mk_win_base_types_strwc_t m_menu_name;
	mk_win_base_types_strwc_t m_class_name;
	mk_win_base_user_types_hicon_t m_small_icon;
};
typedef struct mk_win_base_user_types_class_exw_s mk_win_base_user_types_class_exw_t;
typedef mk_win_base_user_types_class_exw_t const mk_win_base_keywords_far* mk_win_base_user_types_class_exw_lpt;

struct mk_win_base_user_types_msg_s
{
	mk_win_base_user_types_hwnd_t m_hwnd;
	mk_win_base_types_uint_t m_msg;
	mk_win_base_user_types_wparam_t m_wparam;
	mk_win_base_user_types_lparam_t m_lparam;
	mk_win_base_types_dword_t m_time;
	mk_win_base_types_point_t m_point;
};
typedef struct mk_win_base_user_types_msg_s mk_win_base_user_types_msg_t;
typedef mk_win_base_user_types_msg_t mk_win_base_keywords_far* mk_win_base_user_types_msg_lpt;
typedef mk_win_base_user_types_msg_t const mk_win_base_keywords_far* mk_win_base_user_types_msg_lpct;


#endif
