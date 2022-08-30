#ifndef mk_include_guard_dacdbtw_panel
#define mk_include_guard_dacdbtw_panel


#include "../../mk_dacdbt/src/mk_dacdbt_doc.h"

#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_user_window.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_dacdbtw_panel_s
{
	mk_win_base_user_types_hwnd_t m_hwnd;
	mk_win_base_user_types_hwnd_t m_label;
	int m_state;
	mk_win_char_t* m_file_name;
	mk_dacdbt_doc_t m_doc;
};
mk_win_base_types_make_struct(mk_dacdbtw_panel);


#define mk_dacdbtw_panel_wm_set_file_name ((unsigned short)(mk_win_user_window_wm_user + 0x0001ul))


mk_jumbo int mk_dacdbtw_panel_init(void);
mk_jumbo int mk_dacdbtw_panel_deinit(void);
mk_jumbo int mk_dacdbtw_panel_get_class_name(mk_win_char_t const** name);


#endif
