#include "mk_win_comdlg_ofn.h"

#include "mk_win_api.h"
#include "mk_win_char.h"
#include "mk_win_str.h"
#include "mk_win_unicode.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_comdlg_types.h"
#include "../../mk_win_base/src/mk_win_base_comdlg_functions.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"


mk_jumbo int mk_win_comdlg_ofn(mk_win_comdlg_ofn_t* ofn, mk_win_base_types_bool_t* ret)
{
	#if mk_win_api == mk_win_api_old
	#define GetOpenFileNameM GetOpenFileName
	#define mk_win_base_comdlg_types_open_file_name_t mk_win_base_comdlg_types_open_file_name_v1_a_t
	#elif mk_win_api == mk_win_api_ansi
	#define GetOpenFileNameM GetOpenFileNameA
	#define mk_win_base_comdlg_types_open_file_name_t mk_win_base_comdlg_types_open_file_name_v1_a_t
	#elif mk_win_api == mk_win_api_wide
	#define GetOpenFileNameM GetOpenFileNameW
	#define mk_win_base_comdlg_types_open_file_name_t mk_win_base_comdlg_types_open_file_name_v1_w_t
	#endif
	#if mk_win_api != mk_win_api_both
	mk_win_base_comdlg_types_open_file_name_t ofnr;
	mk_win_base_types_bool_t b;
	mk_assert(ofn);
	mk_assert(ret);
	ofnr.m_size = sizeof(ofnr);
	ofnr.m_owner = ofn->m_owner;
	ofnr.m_instance = ofn->m_instance;
	mk_try(mk_win_str_to_api_zz(ofn->m_filter, 0, &ofnr.m_filter));
	mk_try(mk_win_str_to_api_zz(ofn->m_custom_filter, 1, &ofnr.m_custom_filter));
	ofnr.m_max_custom_tfilter = ofn->m_max_custom_tfilter;
	ofnr.m_filter_index = ofn->m_filter_index;
	mk_try(mk_win_str_to_api_s(ofn->m_file_name_buff, ofn->m_file_name_buff_len_chars, 2, &ofnr.m_file));
	ofnr.m_max_file = ofn->m_file_name_buff_len_chars;
	mk_try(mk_win_str_to_api_z(ofn->m_file_title, 3, &ofnr.m_file_title));
	ofnr.m_max_file_title = ofn->m_max_file_title;
	mk_try(mk_win_str_to_api_z(ofn->m_initial_dir, 4, &ofnr.m_initial_dir));
	mk_try(mk_win_str_to_api_z(ofn->m_title, 5, &ofnr.m_title));
	ofnr.m_flags = ofn->m_flags;
	ofnr.m_file_offset = ofn->m_file_offset;
	ofnr.m_file_extension = ofn->m_file_extension;
	mk_try(mk_win_str_to_api_z(ofn->m_default_extension, 6, &ofnr.m_default_extension));
	ofnr.m_custom_data = ofn->m_custom_data;
	ofnr.m_hook = ofn->m_hook;
	mk_try(mk_win_str_to_api_z(ofn->m_template_name, 7, &ofnr.m_template_name));
	b = GetOpenFileNameM(&ofnr);
	ofn->m_file_offset = ofnr.m_file_offset;
	mk_try(mk_win_str_from_api_z(ofnr.m_custom_filter, 5, &ofn->m_custom_filter));
	mk_try(mk_win_str_from_api_z(ofnr.m_file, 6, &ofn->m_file_name_out));
	mk_try(mk_win_str_from_api_z(ofnr.m_file_title, 7, &ofn->m_file_title));
	mk_assert(ret);
	*ret = b;
	return 0;
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		mk_win_base_comdlg_types_open_file_name_v1_a_t ofnr;
		mk_win_base_types_bool_t b;
		mk_assert(ofn);
		mk_assert(ret);
		ofnr.m_size = sizeof(ofnr);
		ofnr.m_owner = ofn->m_owner;
		ofnr.m_instance = ofn->m_instance;
		mk_try(mk_win_str_to_narrow_zz(ofn->m_filter, 0, &ofnr.m_filter));
		mk_try(mk_win_str_to_narrow_zz(ofn->m_custom_filter, 1, &ofnr.m_custom_filter));
		ofnr.m_max_custom_tfilter = ofn->m_max_custom_tfilter;
		ofnr.m_filter_index = ofn->m_filter_index;
		mk_try(mk_win_str_to_narrow_s(ofn->m_file_name_buff, ofn->m_file_name_buff_len_chars, 2, &ofnr.m_file));
		ofnr.m_max_file = ofn->m_file_name_buff_len_chars;
		mk_try(mk_win_str_to_narrow_z(ofn->m_file_title, 3, &ofnr.m_file_title));
		ofnr.m_max_file_title = ofn->m_max_file_title;
		mk_try(mk_win_str_to_narrow_z(ofn->m_initial_dir, 4, &ofnr.m_initial_dir));
		mk_try(mk_win_str_to_narrow_z(ofn->m_title, 5, &ofnr.m_title));
		ofnr.m_flags = ofn->m_flags;
		ofnr.m_file_offset = ofn->m_file_offset;
		ofnr.m_file_extension = ofn->m_file_extension;
		mk_try(mk_win_str_to_narrow_z(ofn->m_default_extension, 6, &ofnr.m_default_extension));
		ofnr.m_custom_data = ofn->m_custom_data;
		ofnr.m_hook = ofn->m_hook;
		mk_try(mk_win_str_to_narrow_z(ofn->m_template_name, 7, &ofnr.m_template_name));
		b = GetOpenFileNameA(&ofnr);
		ofn->m_file_offset = ofnr.m_file_offset;
		mk_try(mk_win_str_from_narrow_z(ofnr.m_custom_filter, 5, &ofn->m_custom_filter));
		mk_try(mk_win_str_from_narrow_z(ofnr.m_file, 6, &ofn->m_file_name_out));
		mk_try(mk_win_str_from_narrow_z(ofnr.m_file_title, 7, &ofn->m_file_title));
		mk_assert(ret);
		*ret = b;
		return 0;
	}
	else
	{
		mk_win_base_comdlg_types_open_file_name_v1_w_t ofnr;
		mk_win_base_types_bool_t b;
		mk_assert(ofn);
		mk_assert(ret);
		ofnr.m_size = sizeof(ofnr);
		ofnr.m_owner = ofn->m_owner;
		ofnr.m_instance = ofn->m_instance;
		mk_try(mk_win_str_to_wide_zz(ofn->m_filter, 0, &ofnr.m_filter));
		mk_try(mk_win_str_to_wide_zz(ofn->m_custom_filter, 1, &ofnr.m_custom_filter));
		ofnr.m_max_custom_tfilter = ofn->m_max_custom_tfilter;
		ofnr.m_filter_index = ofn->m_filter_index;
		mk_try(mk_win_str_to_wide_s(ofn->m_file_name_buff, ofn->m_file_name_buff_len_chars, 2, &ofnr.m_file));
		ofnr.m_max_file = ofn->m_file_name_buff_len_chars;
		mk_try(mk_win_str_to_wide_z(ofn->m_file_title, 3, &ofnr.m_file_title));
		ofnr.m_max_file_title = ofn->m_max_file_title;
		mk_try(mk_win_str_to_wide_z(ofn->m_initial_dir, 4, &ofnr.m_initial_dir));
		mk_try(mk_win_str_to_wide_z(ofn->m_title, 5, &ofnr.m_title));
		ofnr.m_flags = ofn->m_flags;
		ofnr.m_file_offset = ofn->m_file_offset;
		ofnr.m_file_extension = ofn->m_file_extension;
		mk_try(mk_win_str_to_wide_z(ofn->m_default_extension, 6, &ofnr.m_default_extension));
		ofnr.m_custom_data = ofn->m_custom_data;
		ofnr.m_hook = ofn->m_hook;
		mk_try(mk_win_str_to_wide_z(ofn->m_template_name, 7, &ofnr.m_template_name));
		b = GetOpenFileNameW(&ofnr);
		ofn->m_file_offset = ofnr.m_file_offset;
		mk_try(mk_win_str_from_wide_z(ofnr.m_custom_filter, 5, &ofn->m_custom_filter));
		mk_try(mk_win_str_from_wide_z(ofnr.m_file, 6, &ofn->m_file_name_out));
		mk_try(mk_win_str_from_wide_z(ofnr.m_file_title, 7, &ofn->m_file_title));
		mk_assert(ret);
		*ret = b;
		return 0;
	}
	#endif
	#undef GetOpenFileNameM
	#undef mk_win_base_comdlg_types_open_file_name_t
}
