#ifndef mk_include_guard_mdi_child
#define mk_include_guard_mdi_child


#include "mk_mdi_forward.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"


struct mk_mdi_child_s
{
	mk_mdi_parent_pt m_parent;
	mk_win_base_user_types_hwnd_t m_hwnd;
};


mk_jumbo int mk_mdi_child_init(void);
mk_jumbo int mk_mdi_child_deinit(void);
mk_jumbo int mk_mdi_child_hwnd2object(mk_win_base_user_types_hwnd_t hwnd, mk_mdi_child_pt* object);
mk_jumbo int mk_mdi_child_construct(mk_mdi_child_pt child, mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_child_destruct(mk_mdi_child_pt child);
mk_jumbo int mk_mdi_child_close(mk_mdi_child_pt child);


#endif
