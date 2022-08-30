#ifndef mk_include_guard_dacdbte_parent
#define mk_include_guard_dacdbte_parent


#include "mk_dacdbte_forward.h"

#include "../../mk_std/src/mk_std_ptr_buff.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"


struct mk_dacdbte_parent_s
{
	mk_dacdbte_app_pt m_app;
	mk_win_base_user_types_hwnd_t m_hwnd;
	mk_win_base_user_types_hwnd_t m_mdi;
	mk_std_ptr_buff_t m_children;
};


mk_jumbo int mk_dacdbte_parent_init(void);
mk_jumbo int mk_dacdbte_parent_deinit(void);
mk_jumbo int mk_dacdbte_parent_hwnd2object(mk_win_base_user_types_hwnd_t hwnd, mk_dacdbte_parent_pt* object);
mk_jumbo int mk_dacdbte_parent_construct(mk_dacdbte_parent_pt parent, mk_dacdbte_app_pt app);
mk_jumbo int mk_dacdbte_parent_destruct(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_show(mk_dacdbte_parent_pt parent, int show);
mk_jumbo int mk_dacdbte_parent_close(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_children_add(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_children_get_active(mk_dacdbte_parent_pt parent, mk_dacdbte_child_pt* child);
mk_jumbo int mk_dacdbte_parent_children_close_active(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_children_cascade(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_children_cascade_zorder(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_children_tile_vertically(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_children_tile_horizontally(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_children_arrange_icons(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_children_transfer(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_children_close_all(mk_dacdbte_parent_pt parent);
mk_jumbo int mk_dacdbte_parent_on_child_destroy(mk_dacdbte_parent_pt parent, mk_dacdbte_child_pt child);


#endif
