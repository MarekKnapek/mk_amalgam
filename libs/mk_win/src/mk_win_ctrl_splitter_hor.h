#ifndef mk_include_guard_win_ctrl_splitter_hor
#define mk_include_guard_win_ctrl_splitter_hor


#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_types.h"

#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_user_window.h"


#define mk_win_ctrl_splitter_hor_wm_set_ratio ((unsigned short)(mk_win_user_window_wm_user + 0x0001ul))
#define mk_win_ctrl_splitter_hor_wm_set_child ((unsigned short)(mk_win_user_window_wm_user + 0x0002ul))


mk_jumbo int mk_win_ctrl_splitter_hor_class_register(void);
mk_jumbo int mk_win_ctrl_splitter_hor_class_unregister(void);
mk_jumbo int mk_win_ctrl_splitter_hor_class_get_atom(mk_win_base_types_atom_t* const atom);
mk_jumbo int mk_win_ctrl_splitter_hor_class_get_name(mk_win_strc_t* const name);


#endif
