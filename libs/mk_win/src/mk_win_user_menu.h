#ifndef mk_include_guard_win_user_menu
#define mk_include_guard_win_user_menu


#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_user_types.h"


mk_jumbo int mk_win_user_menu_get(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_hmenu_t* menu);
mk_jumbo int mk_win_user_menu_get_sub(mk_win_base_user_types_hmenu_t hmenu, int idx, mk_win_base_user_types_hmenu_t* menu);


#endif
