#ifndef mk_include_guard_win_base_comdlg_types
#define mk_include_guard_win_base_comdlg_types


#include "mk_win_base_keywords.h"
#include "mk_win_base_types.h"
#include "mk_win_base_user_types.h"


typedef mk_win_base_types_cpu_word_t(mk_win_base_keywords_calling_convention_api*mk_win_base_comdlg_types_open_file_name_hook_t)(mk_win_base_user_types_hwnd_t, mk_win_base_types_uint_t, mk_win_base_user_types_wparam_t, mk_win_base_user_types_lparam_t);

struct mk_win_base_comdlg_types_open_file_name_v1_a_s
{
	mk_win_base_types_dword_t m_size;
	mk_win_base_user_types_hwnd_t m_owner;
	mk_win_base_types_hinstance_t m_instance;
	mk_win_base_types_char_lpct m_filter;
	mk_win_base_types_char_lpt m_custom_filter;
	mk_win_base_types_dword_t m_max_custom_tfilter;
	mk_win_base_types_dword_t m_filter_index;
	mk_win_base_types_char_lpt m_file;
	mk_win_base_types_dword_t m_max_file;
	mk_win_base_types_char_lpt m_file_title;
	mk_win_base_types_dword_t m_max_file_title;
	mk_win_base_types_char_lpct m_initial_dir;
	mk_win_base_types_char_lpct m_title;
	mk_win_base_types_dword_t m_flags;
	mk_win_base_types_word_t m_file_offset;
	mk_win_base_types_word_t m_file_extension;
	mk_win_base_types_char_lpct m_default_extension;
	mk_win_base_user_types_lparam_t m_custom_data;
	mk_win_base_comdlg_types_open_file_name_hook_t m_hook;
	mk_win_base_types_char_lpct m_template_name;
};
mk_win_base_types_make_struct(mk_win_base_comdlg_types_open_file_name_v1_a);

struct mk_win_base_comdlg_types_open_file_name_v2_a_s
{
	mk_win_base_types_dword_t m_size;
	mk_win_base_user_types_hwnd_t m_owner;
	mk_win_base_types_hinstance_t m_instance;
	mk_win_base_types_char_lpct m_filter;
	mk_win_base_types_char_lpt m_custom_filter;
	mk_win_base_types_dword_t m_max_custom_tfilter;
	mk_win_base_types_dword_t m_filter_index;
	mk_win_base_types_char_lpt m_file;
	mk_win_base_types_dword_t m_max_file;
	mk_win_base_types_char_lpt m_file_title;
	mk_win_base_types_dword_t m_max_file_title;
	mk_win_base_types_char_lpct m_initial_dir;
	mk_win_base_types_char_lpct m_title;
	mk_win_base_types_dword_t m_flags;
	mk_win_base_types_word_t m_file_offset;
	mk_win_base_types_word_t m_file_extension;
	mk_win_base_types_char_lpct m_default_extension;
	mk_win_base_user_types_lparam_t m_custom_data;
	mk_win_base_comdlg_types_open_file_name_hook_t m_hook;
	mk_win_base_types_char_lpct m_template_name;
	mk_win_base_types_void_lpt m_preserved;
	mk_win_base_types_dword_t m_nreserved;
	mk_win_base_types_dword_t m_flags_extra;
};
mk_win_base_types_make_struct(mk_win_base_comdlg_types_open_file_name_v2_a);

struct mk_win_base_comdlg_types_open_file_name_v1_w_s
{
	mk_win_base_types_dword_t m_size;
	mk_win_base_user_types_hwnd_t m_owner;
	mk_win_base_types_hinstance_t m_instance;
	mk_win_base_types_wchar_lpct m_filter;
	mk_win_base_types_wchar_lpt m_custom_filter;
	mk_win_base_types_dword_t m_max_custom_tfilter;
	mk_win_base_types_dword_t m_filter_index;
	mk_win_base_types_wchar_lpt m_file;
	mk_win_base_types_dword_t m_max_file;
	mk_win_base_types_wchar_lpt m_file_title;
	mk_win_base_types_dword_t m_max_file_title;
	mk_win_base_types_wchar_lpct m_initial_dir;
	mk_win_base_types_wchar_lpct m_title;
	mk_win_base_types_dword_t m_flags;
	mk_win_base_types_word_t m_file_offset;
	mk_win_base_types_word_t m_file_extension;
	mk_win_base_types_wchar_lpct m_default_extension;
	mk_win_base_user_types_lparam_t m_custom_data;
	mk_win_base_comdlg_types_open_file_name_hook_t m_hook;
	mk_win_base_types_wchar_lpct m_template_name;
};
mk_win_base_types_make_struct(mk_win_base_comdlg_types_open_file_name_v1_w);

struct mk_win_base_comdlg_types_open_file_name_v2_w_s
{
	mk_win_base_types_dword_t m_size;
	mk_win_base_user_types_hwnd_t m_owner;
	mk_win_base_types_hinstance_t m_instance;
	mk_win_base_types_wchar_lpct m_filter;
	mk_win_base_types_wchar_lpt m_custom_filter;
	mk_win_base_types_dword_t m_max_custom_tfilter;
	mk_win_base_types_dword_t m_filter_index;
	mk_win_base_types_wchar_lpt m_file;
	mk_win_base_types_dword_t m_max_file;
	mk_win_base_types_wchar_lpt m_file_title;
	mk_win_base_types_dword_t m_max_file_title;
	mk_win_base_types_wchar_lpct m_initial_dir;
	mk_win_base_types_wchar_lpct m_title;
	mk_win_base_types_dword_t m_flags;
	mk_win_base_types_word_t m_file_offset;
	mk_win_base_types_word_t m_file_extension;
	mk_win_base_types_wchar_lpct m_default_extension;
	mk_win_base_user_types_lparam_t m_custom_data;
	mk_win_base_comdlg_types_open_file_name_hook_t m_hook;
	mk_win_base_types_wchar_lpct m_template_name;
	mk_win_base_types_void_lpt m_preserved;
	mk_win_base_types_dword_t m_nreserved;
	mk_win_base_types_dword_t m_flags_extra;
};
mk_win_base_types_make_struct(mk_win_base_comdlg_types_open_file_name_v2_w);


#endif
