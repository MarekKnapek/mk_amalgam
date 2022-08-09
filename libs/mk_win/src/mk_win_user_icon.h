#ifndef mk_include_guard_win_user_icon
#define mk_include_guard_win_user_icon


#include "mk_win_str.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_user_types.h"


#define mk_win_user_icon_id_application 32512
#define mk_win_user_icon_id_hand        32513
#define mk_win_user_icon_id_question    32514
#define mk_win_user_icon_id_exclamation 32515
#define mk_win_user_icon_id_asterisk    32516
#define mk_win_user_icon_id_winlogo     32517 /* 0x0400 */
#define mk_win_user_icon_id_shield      32518 /* 0x0600 */
#define mk_win_user_icon_id_error       mk_win_user_icon_id_hand /* 0x0400 */
#define mk_win_user_icon_id_warning     mk_win_user_icon_id_exclamation /* 0x0400 */
#define mk_win_user_icon_id_information mk_win_user_icon_id_asterisk /* 0x0400 */


mk_jumbo int mk_win_user_icon_load_by_name(mk_win_base_types_hinstance_t instance, mk_win_strc_t name, mk_win_base_user_types_hicon_t* icon);
mk_jumbo int mk_win_user_icon_load_by_id(unsigned short id, mk_win_base_user_types_hicon_t* icon);


#endif
