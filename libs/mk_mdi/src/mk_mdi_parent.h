#ifndef mk_include_guard_mdi_parent
#define mk_include_guard_mdi_parent


#include "../../mk_std/src/mk_std_ptr_buff.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"


struct mk_mdi_app_s;
typedef struct mk_mdi_app_s mk_mdi_app_t;
typedef mk_mdi_app_t* mk_mdi_app_pt;

struct mk_mdi_parent_s;
typedef struct mk_mdi_parent_s mk_mdi_parent_t;
typedef mk_mdi_parent_t* mk_mdi_parent_pt;

struct mk_mdi_child_s;
typedef struct mk_mdi_child_s mk_mdi_child_t;
typedef mk_mdi_child_t* mk_mdi_child_pt;

struct mk_mdi_parent_s
{
	mk_mdi_app_pt m_app;
	mk_win_base_user_types_hwnd_t m_hwnd;
	mk_win_base_user_types_hwnd_t m_mdi;
	mk_std_ptr_buff_t m_children;
};


mk_jumbo int mk_mdi_parent_init(void);
mk_jumbo int mk_mdi_parent_deinit(void);
mk_jumbo int mk_mdi_parent_hwnd2object(mk_win_base_user_types_hwnd_t hwnd, mk_mdi_parent_pt* object);
mk_jumbo int mk_mdi_parent_construct(mk_mdi_parent_pt parent, mk_mdi_app_pt app);
mk_jumbo int mk_mdi_parent_destruct(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_show(mk_mdi_parent_pt parent, int show);
mk_jumbo int mk_mdi_parent_close(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_children_add(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_children_close_active(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_children_cascade(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_children_cascade_zorder(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_children_tile_vertically(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_children_tile_horizontally(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_children_arrange_icons(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_children_close_all(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_on_child_destroy(mk_mdi_parent_pt parent, mk_mdi_child_pt child);


#endif
