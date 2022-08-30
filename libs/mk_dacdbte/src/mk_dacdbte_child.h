#ifndef mk_include_guard_dacdbte_child
#define mk_include_guard_dacdbte_child


#include "mk_dacdbte_forward.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_dacdbte_child_s
{
	mk_dacdbte_parent_pt m_parent;
	mk_win_base_user_types_hwnd_t m_hwnd;
	mk_win_base_user_types_hwnd_t m_content;
};


mk_jumbo int mk_dacdbte_child_init(void);
mk_jumbo int mk_dacdbte_child_deinit(void);
mk_jumbo int mk_dacdbte_child_hwnd2object(mk_win_base_user_types_hwnd_t hwnd, mk_dacdbte_child_pt* object);
mk_jumbo int mk_dacdbte_child_construct(mk_dacdbte_child_pt child, mk_dacdbte_parent_pt parent, mk_dacdbte_child_pt old_child);
mk_jumbo int mk_dacdbte_child_destruct(mk_dacdbte_child_pt child);
mk_jumbo int mk_dacdbte_child_close(mk_dacdbte_child_pt child);


#endif
