#ifndef mk_include_guard_win_user_cursor
#define mk_include_guard_win_user_cursor


#include "mk_win_str.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_user_types.h"


#define mk_win_user_cursor_id_arrow       32512
#define mk_win_user_cursor_id_ibeam       32513
#define mk_win_user_cursor_id_wait        32514
#define mk_win_user_cursor_id_cross       32515
#define mk_win_user_cursor_id_uparrow     32516
#define mk_win_user_cursor_id_size        32640 /* obsolete: use sizeall */
#define mk_win_user_cursor_id_icon        32641 /* obsolete: use arrow */
#define mk_win_user_cursor_id_sizenwse    32642
#define mk_win_user_cursor_id_sizenesw    32643
#define mk_win_user_cursor_id_sizewe      32644
#define mk_win_user_cursor_id_sizens      32645
#define mk_win_user_cursor_id_sizeall     32646
#define mk_win_user_cursor_id_no          32648 /* not in win3.1 */
#define mk_win_user_cursor_id_hand        32649 /* 0x0500 */
#define mk_win_user_cursor_id_appstarting 32650 /* not in win3.1 */
#define mk_win_user_cursor_id_help        32651 /* 0x0400 */
#define mk_win_user_cursor_id_pin         32671 /* 0x0606 */
#define mk_win_user_cursor_id_person      32672 /* 0x0606 */


mk_jumbo int mk_win_user_cursor_load_by_name(mk_win_base_types_hinstance_t instance, mk_win_strc_t name, mk_win_base_user_types_hcursor_t* cursor);
mk_jumbo int mk_win_user_cursor_load_by_id(unsigned short id, mk_win_base_user_types_hcursor_t* cursor);


#endif
