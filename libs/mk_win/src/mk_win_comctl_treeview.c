#include "mk_win_comctl_treeview.h"

#include "mk_win_api.h"
#include "mk_win_char.h"
#include "mk_win_str.h"
#include "mk_win_user_window.h"
#include "mk_win_unicode.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"


mk_jumbo int mk_win_comctl_treeview_insert(mk_win_base_user_types_hwnd_t tree_view, mk_win_comctl_treeview_insert_t* insert, mk_win_comctl_treeview_htreeitem_t* ret)
{
	#if mk_win_api == mk_win_api_old
	#define mk_win_comctl_treeview_wm_insertitem mk_win_comctl_treeview_wm_insertitema
	mk_win_comctl_treeview_insert_a_t insert_exm;
	typedef mk_win_comctl_treeview_item_exa_lpt mk_win_comctl_treeview_item_exm_lpt;
	#elif mk_win_api == mk_win_api_ansi
	#define mk_win_comctl_treeview_wm_insertitem mk_win_comctl_treeview_wm_insertitema
	mk_win_comctl_treeview_insert_a_t insert_exm;
	typedef mk_win_comctl_treeview_item_exa_lpt mk_win_comctl_treeview_item_exm_lpt;
	#elif mk_win_api == mk_win_api_wide
	#define mk_win_comctl_treeview_wm_insertitem mk_win_comctl_treeview_wm_insertitemw
	mk_win_comctl_treeview_insert_w_t insert_exm;
	typedef mk_win_comctl_treeview_item_exw_lpt mk_win_comctl_treeview_item_exm_lpt;
	#elif mk_win_api == mk_win_api_both
	mk_win_comctl_treeview_insert_a_t insert_exa;
	mk_win_comctl_treeview_insert_w_t insert_exw;
	#endif
	mk_win_base_user_types_lresult_t lr;

	#if mk_win_api != mk_win_api_both
	mk_assert(tree_view);
	mk_assert(insert);
	mk_assert(ret);
	insert_exm.m_parent = insert->m_parent;
	insert_exm.m_insert_after = insert->m_insert_after;
	insert_exm.m_item.m_item_ex.m_mask = insert->m_item.m_item_ex.m_mask;
	insert_exm.m_item.m_item_ex.m_hitem = insert->m_item.m_item_ex.m_hitem;
	insert_exm.m_item.m_item_ex.m_state = insert->m_item.m_item_ex.m_state;
	insert_exm.m_item.m_item_ex.m_state_mask = insert->m_item.m_item_ex.m_state_mask;
	mk_try(mk_win_str_to_api_z(insert->m_item.m_item_ex.m_text, 0, &insert_exm.m_item.m_item_ex.m_text));
	insert_exm.m_item.m_item_ex.m_text_len = insert->m_item.m_item_ex.m_text_len;
	insert_exm.m_item.m_item_ex.m_image_idx = insert->m_item.m_item_ex.m_image_idx;
	insert_exm.m_item.m_item_ex.m_selected_image_idx = insert->m_item.m_item_ex.m_selected_image_idx;
	insert_exm.m_item.m_item_ex.m_children_count = insert->m_item.m_item_ex.m_children_count;
	insert_exm.m_item.m_item_ex.m_param = insert->m_item.m_item_ex.m_param;
	insert_exm.m_item.m_item_ex.m_integral = insert->m_item.m_item_ex.m_integral;
	insert_exm.m_item.m_item_ex.m_state_ex = insert->m_item.m_item_ex.m_state_ex;
	insert_exm.m_item.m_item_ex.m_hwnd = insert->m_item.m_item_ex.m_hwnd;
	insert_exm.m_item.m_item_ex.m_expanded_image_idx = insert->m_item.m_item_ex.m_expanded_image_idx;
	insert_exm.m_item.m_item_ex.m_reserved = insert->m_item.m_item_ex.m_reserved;
	mk_try(mk_win_user_window_send(tree_view, mk_win_comctl_treeview_wm_insertitem, 0, (mk_win_base_user_types_lparam_t)(mk_win_comctl_treeview_item_exm_lpt)&insert_exm, &lr));
	*ret = (mk_win_comctl_treeview_htreeitem_t)lr;
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		mk_assert(tree_view);
		mk_assert(insert);
		mk_assert(ret);
		insert_exa.m_parent = insert->m_parent;
		insert_exa.m_insert_after = insert->m_insert_after;
		insert_exa.m_item.m_item_ex.m_mask = insert->m_item.m_item_ex.m_mask;
		insert_exa.m_item.m_item_ex.m_hitem = insert->m_item.m_item_ex.m_hitem;
		insert_exa.m_item.m_item_ex.m_state = insert->m_item.m_item_ex.m_state;
		insert_exa.m_item.m_item_ex.m_state_mask = insert->m_item.m_item_ex.m_state_mask;
		mk_try(mk_win_str_to_narrow_z(insert->m_item.m_item_ex.m_text, 0, &insert_exa.m_item.m_item_ex.m_text));
		insert_exa.m_item.m_item_ex.m_text_len = insert->m_item.m_item_ex.m_text_len;
		insert_exa.m_item.m_item_ex.m_image_idx = insert->m_item.m_item_ex.m_image_idx;
		insert_exa.m_item.m_item_ex.m_selected_image_idx = insert->m_item.m_item_ex.m_selected_image_idx;
		insert_exa.m_item.m_item_ex.m_children_count = insert->m_item.m_item_ex.m_children_count;
		insert_exa.m_item.m_item_ex.m_param = insert->m_item.m_item_ex.m_param;
		insert_exa.m_item.m_item_ex.m_integral = insert->m_item.m_item_ex.m_integral;
		insert_exa.m_item.m_item_ex.m_state_ex = insert->m_item.m_item_ex.m_state_ex;
		insert_exa.m_item.m_item_ex.m_hwnd = insert->m_item.m_item_ex.m_hwnd;
		insert_exa.m_item.m_item_ex.m_expanded_image_idx = insert->m_item.m_item_ex.m_expanded_image_idx;
		insert_exa.m_item.m_item_ex.m_reserved = insert->m_item.m_item_ex.m_reserved;
		mk_try(mk_win_user_window_send(tree_view, mk_win_comctl_treeview_wm_insertitema, 0, (mk_win_base_user_types_lparam_t)(mk_win_comctl_treeview_item_exa_lpt)&insert_exa, &lr));
		*ret = (mk_win_comctl_treeview_htreeitem_t)lr;
	}
	else
	{
		mk_assert(tree_view);
		mk_assert(insert);
		mk_assert(ret);
		insert_exw.m_parent = insert->m_parent;
		insert_exw.m_insert_after = insert->m_insert_after;
		insert_exw.m_item.m_item_ex.m_mask = insert->m_item.m_item_ex.m_mask;
		insert_exw.m_item.m_item_ex.m_hitem = insert->m_item.m_item_ex.m_hitem;
		insert_exw.m_item.m_item_ex.m_state = insert->m_item.m_item_ex.m_state;
		insert_exw.m_item.m_item_ex.m_state_mask = insert->m_item.m_item_ex.m_state_mask;
		mk_try(mk_win_str_to_wide_z(insert->m_item.m_item_ex.m_text, 0, &insert_exw.m_item.m_item_ex.m_text));
		insert_exw.m_item.m_item_ex.m_text_len = insert->m_item.m_item_ex.m_text_len;
		insert_exw.m_item.m_item_ex.m_image_idx = insert->m_item.m_item_ex.m_image_idx;
		insert_exw.m_item.m_item_ex.m_selected_image_idx = insert->m_item.m_item_ex.m_selected_image_idx;
		insert_exw.m_item.m_item_ex.m_children_count = insert->m_item.m_item_ex.m_children_count;
		insert_exw.m_item.m_item_ex.m_param = insert->m_item.m_item_ex.m_param;
		insert_exw.m_item.m_item_ex.m_integral = insert->m_item.m_item_ex.m_integral;
		insert_exw.m_item.m_item_ex.m_state_ex = insert->m_item.m_item_ex.m_state_ex;
		insert_exw.m_item.m_item_ex.m_hwnd = insert->m_item.m_item_ex.m_hwnd;
		insert_exw.m_item.m_item_ex.m_expanded_image_idx = insert->m_item.m_item_ex.m_expanded_image_idx;
		insert_exw.m_item.m_item_ex.m_reserved = insert->m_item.m_item_ex.m_reserved;
		mk_try(mk_win_user_window_send(tree_view, mk_win_comctl_treeview_wm_insertitemw, 0, (mk_win_base_user_types_lparam_t)(mk_win_comctl_treeview_item_exw_lpt)&insert_exw, &lr));
		*ret = (mk_win_comctl_treeview_htreeitem_t)lr;
	}
	#endif
	return 0;

	#undef mk_win_comctl_treeview_wm_insertitem
}

mk_jumbo int mk_win_comctl_treeview_get_item_param(mk_win_base_user_types_hwnd_t tree_view, mk_win_comctl_treeview_htreeitem_t item, void** ret)
{
	#if mk_win_api == mk_win_api_old
	#define mk_win_comctl_treeview_item_m_t mk_win_comctl_treeview_item_a_t
	#define mk_win_comctl_treeview_item_m_lpt mk_win_comctl_treeview_item_a_lpt
	#define mk_win_comctl_treeview_wm_getitemm mk_win_comctl_treeview_wm_getitema
	#elif mk_win_api == mk_win_api_ansi
	#define mk_win_comctl_treeview_item_m_t mk_win_comctl_treeview_item_a_t
	#define mk_win_comctl_treeview_item_m_lpt mk_win_comctl_treeview_item_a_lpt
	#define mk_win_comctl_treeview_wm_getitemm mk_win_comctl_treeview_wm_getitema
	#elif mk_win_api == mk_win_api_wide
	#define mk_win_comctl_treeview_item_m_t mk_win_comctl_treeview_item_w_t
	#define mk_win_comctl_treeview_item_m_lpt mk_win_comctl_treeview_item_w_lpt
	#define mk_win_comctl_treeview_wm_getitemm mk_win_comctl_treeview_wm_getitemw
	#elif mk_win_api == mk_win_api_both
	#endif

	#if mk_win_api != mk_win_api_both
	mk_win_comctl_treeview_item_m_t it;
	mk_win_base_user_types_lresult_t lr;
	mk_assert(tree_view);
	mk_assert(item);
	mk_assert(ret);
	it.m_mask = mk_win_comctl_treeview_item_flag_param;
	it.m_hitem = item;
	it.m_param = 0;
	mk_try(mk_win_user_window_send(tree_view, mk_win_comctl_treeview_wm_getitemm, 0, ((mk_win_base_user_types_lparam_t)(((mk_win_comctl_treeview_item_m_lpt)(&it)))), &lr));
	mk_assert(lr != 0);
	mk_assert(it.m_param != 0);
	*ret = ((void*)((mk_win_base_types_void_lpt)(it.m_param)));
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		mk_win_comctl_treeview_item_a_t it;
		mk_win_base_user_types_lresult_t lr;
		mk_assert(tree_view);
		mk_assert(item);
		mk_assert(ret);
		it.m_mask = mk_win_comctl_treeview_item_flag_param;
		it.m_hitem = item;
		it.m_param = 0;
		mk_try(mk_win_user_window_send(tree_view, mk_win_comctl_treeview_wm_getitema, 0, ((mk_win_base_user_types_lparam_t)(((mk_win_comctl_treeview_item_a_lpt)(&it)))), &lr));
		mk_assert(lr != 0);
		mk_assert(it.m_param != 0);
		*ret = ((void*)((mk_win_base_types_void_lpt)(it.m_param)));
	}
	else
	{
		mk_win_comctl_treeview_item_w_t it;
		mk_win_base_user_types_lresult_t lr;
		mk_assert(tree_view);
		mk_assert(item);
		mk_assert(ret);
		it.m_mask = mk_win_comctl_treeview_item_flag_param;
		it.m_hitem = item;
		it.m_param = 0;
		mk_try(mk_win_user_window_send(tree_view, mk_win_comctl_treeview_wm_getitemw, 0, ((mk_win_base_user_types_lparam_t)(((mk_win_comctl_treeview_item_w_lpt)(&it)))), &lr));
		mk_assert(lr != 0);
		mk_assert(it.m_param != 0);
		*ret = ((void*)((mk_win_base_types_void_lpt)(it.m_param)));
	}
	#endif
	return 0;

	#undef mk_win_comctl_treeview_item_m_t
	#undef mk_win_comctl_treeview_item_m_lpt
	#undef mk_win_comctl_treeview_wm_getitemm
}
