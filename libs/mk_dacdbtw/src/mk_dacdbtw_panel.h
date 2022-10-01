#ifndef mk_include_guard_dacdbtw_panel
#define mk_include_guard_dacdbtw_panel


#include "../../mk_utils/src/mk_jumbo.h"


#define mk_dacdbtw_panel_wm_on_idle       ((unsigned short)(mk_win_user_window_wm_user + 0x0001ul))
#define mk_dacdbtw_panel_wm_set_file_name ((unsigned short)(mk_win_user_window_wm_user + 0x0002ul))


mk_jumbo int mk_dacdbtw_panel_init(void);
mk_jumbo int mk_dacdbtw_panel_deinit(void);
mk_jumbo int mk_dacdbtw_panel_get_class_name(mk_win_char_t const** name);


#endif
