#ifndef mk_include_guard_win_comdlg_ofn
#define mk_include_guard_win_comdlg_ofn


#include "mk_win_char.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_comdlg_types.h"

#include "../../mk_utils/src/mk_jumbo.h"


#define mk_win_comdlg_ofn_flag_readonly             0x00000001ul
#define mk_win_comdlg_ofn_flag_overwriteprompt      0x00000002ul
#define mk_win_comdlg_ofn_flag_hidereadonly         0x00000004ul
#define mk_win_comdlg_ofn_flag_nochangedir          0x00000008ul
#define mk_win_comdlg_ofn_flag_showhelp             0x00000010ul
#define mk_win_comdlg_ofn_flag_enablehook           0x00000020ul
#define mk_win_comdlg_ofn_flag_enabletemplate       0x00000040ul
#define mk_win_comdlg_ofn_flag_enabletemplatehandle 0x00000080ul
#define mk_win_comdlg_ofn_flag_novalidate           0x00000100ul
#define mk_win_comdlg_ofn_flag_allowmultiselect     0x00000200ul
#define mk_win_comdlg_ofn_flag_extensiondifferent   0x00000400ul
#define mk_win_comdlg_ofn_flag_pathmustexist        0x00000800ul
#define mk_win_comdlg_ofn_flag_filemustexist        0x00001000ul
#define mk_win_comdlg_ofn_flag_createprompt         0x00002000ul
#define mk_win_comdlg_ofn_flag_shareaware           0x00004000ul
#define mk_win_comdlg_ofn_flag_noreadonlyreturn     0x00008000ul
#define mk_win_comdlg_ofn_flag_notestfilecreate     0x00010000ul
#define mk_win_comdlg_ofn_flag_nonetworkbutton      0x00020000ul
#define mk_win_comdlg_ofn_flag_nolongnames          0x00040000ul
#define mk_win_comdlg_ofn_flag_explorer             0x00080000ul /* winver >= 0x0400 */
#define mk_win_comdlg_ofn_flag_nodereferencelinks   0x00100000ul /* winver >= 0x0400 */
#define mk_win_comdlg_ofn_flag_longnames            0x00200000ul /* winver >= 0x0400 */
#define mk_win_comdlg_ofn_flag_enableincludenotify  0x00400000ul /* winver >= 0x0400 */
#define mk_win_comdlg_ofn_flag_enablesizing         0x00800000ul /* winver >= 0x0400 */
#define mk_win_comdlg_ofn_flag_dontaddtorecent      0x02000000ul /* winnt >= 0x0500 */
#define mk_win_comdlg_ofn_flag_forceshowhidden      0x10000000ul /* winnt >= 0x0500 */


struct mk_win_comdlg_ofn_s
{
	mk_win_base_user_types_hwnd_t m_owner;
	mk_win_base_types_hinstance_t m_instance;
	mk_win_strc_t m_filter;
	mk_win_str_t m_custom_filter;
	mk_win_base_types_dword_t m_max_custom_tfilter;
	mk_win_base_types_dword_t m_filter_index;
	mk_win_strc_t m_file_name_buff;
	mk_win_base_types_dword_t m_file_name_buff_len_chars;
	mk_win_str_t m_file_name_out;
	mk_win_str_t m_file_title;
	mk_win_base_types_dword_t m_max_file_title;
	mk_win_strc_t m_initial_dir;
	mk_win_strc_t m_title;
	mk_win_base_types_dword_t m_flags;
	mk_win_base_types_word_t m_file_offset;
	mk_win_base_types_word_t m_file_extension;
	mk_win_strc_t m_default_extension;
	mk_win_base_user_types_lparam_t m_custom_data;
	mk_win_base_comdlg_types_open_file_name_hook_t m_hook;
	mk_win_strc_t m_template_name;
};
mk_win_base_types_make_struct(mk_win_comdlg_ofn);


mk_jumbo int mk_win_comdlg_ofn(mk_win_comdlg_ofn_t* ofn, mk_win_base_types_bool_t* ret);


#endif
