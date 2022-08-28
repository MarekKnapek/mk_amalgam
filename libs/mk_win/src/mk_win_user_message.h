#ifndef mk_include_guard_win_user_message
#define mk_include_guard_win_user_message


#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_user_types.h"


#define mk_win_user_message_param_mditile_vertical     0x0000u /* not in win3.1 */
#define mk_win_user_message_param_mditile_horizontal   0x0001u /* not in win3.1 */
#define mk_win_user_message_param_mditile_skipdisabled 0x0002u /* not in win3.1 */
#define mk_win_user_message_param_mditile_zorder       0x0004u /* 0x0500 */


mk_jumbo int mk_win_user_message_get(mk_win_base_user_types_msg_t* msg, mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg_min, mk_win_base_types_uint_t msg_max, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_message_translate(mk_win_base_user_types_msg_t const* msg, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_message_dispatch(mk_win_base_user_types_msg_t const* msg, mk_win_base_user_types_lresult_t* ret);
mk_jumbo int mk_win_user_message_translate_mdi_sys_accel(mk_win_base_user_types_hwnd_t mdi, mk_win_base_user_types_msg_t const* msg, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_message_post_quit(int exit_code);


#endif
