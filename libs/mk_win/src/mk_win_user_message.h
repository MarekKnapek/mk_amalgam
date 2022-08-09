#ifndef mk_include_guard_win_user_message
#define mk_include_guard_win_user_message


#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_user_types.h"


#define mk_win_user_message_id_null    ((unsigned short)0x0000u)
#define mk_win_user_message_id_create  ((unsigned short)0x0001u)
#define mk_win_user_message_id_destroy ((unsigned short)0x0002u)
#define mk_win_user_message_id_close   ((unsigned short)0x0010u)
#define mk_win_user_message_id_quit    ((unsigned short)0x0012u)
#define mk_win_user_message_id_command ((unsigned short)0x0111u)


mk_jumbo int mk_win_user_message_get(mk_win_base_user_types_msg_t* msg, mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg_min, mk_win_base_types_uint_t msg_max, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_message_translate(mk_win_base_user_types_msg_t const* msg, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_message_dispatch(mk_win_base_user_types_msg_t const* msg, mk_win_base_user_types_lresult_t* ret);
mk_jumbo int mk_win_user_message_post_quit(int exit_code);


#endif
