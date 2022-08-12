#include "mk_win_user_menu.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_user_functions.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"


mk_jumbo int mk_win_user_menu_get(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_hmenu_t* menu)
{
	mk_win_base_user_types_hmenu_t m;

	mk_assert(menu);

	m = GetMenu(hwnd);
	*menu = m;

	return 0;
}

mk_jumbo int mk_win_user_menu_get_sub(mk_win_base_user_types_hmenu_t hmenu, int idx, mk_win_base_user_types_hmenu_t* menu)
{
	mk_win_base_user_types_hmenu_t m;

	mk_assert(menu);

	m = GetSubMenu(hmenu, idx);
	*menu = m;

	return 0;
}
