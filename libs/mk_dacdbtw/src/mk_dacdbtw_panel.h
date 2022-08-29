#ifndef mk_include_guard_dacdbtw_panel
#define mk_include_guard_dacdbtw_panel


#include "../../mk_win/src/mk_win_char.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_dacdbtw_panel_s
{
	mk_win_base_user_types_hwnd_t m_hwnd;
};
mk_win_base_types_make_struct(mk_dacdbtw_panel);


mk_jumbo int mk_dacdbtw_panel_init(void);
mk_jumbo int mk_dacdbtw_panel_deinit(void);
mk_jumbo int mk_dacdbtw_panel_get_class_name(mk_win_char_t const** name);


#endif
