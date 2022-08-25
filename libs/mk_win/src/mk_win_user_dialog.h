#ifndef mk_include_guard_win_user_dialog
#define mk_include_guard_win_user_dialog


#include "mk_win_user_dialog_constants.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_utils/src/mk_jumbo.h"


#define mk_win_user_dialog_cmdid_ok           1
#define mk_win_user_dialog_cmdid_cancel       2
#define mk_win_user_dialog_cmdid_abort        3
#define mk_win_user_dialog_cmdid_retry        4
#define mk_win_user_dialog_cmdid_ignore       5
#define mk_win_user_dialog_cmdid_yes          6
#define mk_win_user_dialog_cmdid_no           7
#define mk_win_user_dialog_cmdid_close        8 /* winver >= 0x0400 */
#define mk_win_user_dialog_cmdid_help         9 /* winver >= 0x0400 */
#define mk_win_user_dialog_cmdid_tryagain    10 /* winver >= 0x0500 */
#define mk_win_user_dialog_cmdid_continue    11 /* winver >= 0x0500 */
#define mk_win_user_dialog_cmdid_timeout  32000 /* winver >= 0x0501 */


mk_jumbo int mk_win_user_dialog_indirect_param(mk_win_base_types_hinstance_t instance, mk_win_base_kernel_types_hglobal_t dlg_template, mk_win_base_user_types_hwnd_t parent, mk_win_base_user_types_dlgproc_t dlg_proc, mk_win_base_user_types_lparam_t param, mk_win_base_types_cpu_iword_t* ret);
mk_jumbo int mk_win_user_dialog_get_item(mk_win_base_user_types_hwnd_t dialog, int item_id, mk_win_base_user_types_hwnd_t* item);
mk_jumbo int mk_win_user_dialog_end(mk_win_base_user_types_hwnd_t dialog, mk_win_base_types_cpu_iword_t result, mk_win_base_types_bool_t* ret);


#endif
