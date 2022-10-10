#include "mk_win_comctl_listview.h"

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


mk_jumbo int mk_win_comctl_listview_insertcolumn(mk_win_base_user_types_hwnd_t listview, int idx, mk_win_comctl_listview_column_t const* column, mk_win_base_types_intptr_t* ret_idx)
{
	#if mk_win_api == mk_win_api_old || mk_win_api == mk_win_api_ansi
	#define mk_win_comctl_listview_wm_insertcolumnm mk_win_comctl_listview_wm_insertcolumna
	mk_win_comctl_listview_column_a_t col;
	#elif mk_win_api == mk_win_api_wide
	#define mk_win_comctl_listview_wm_insertcolumnm mk_win_comctl_listview_wm_insertcolumnw
	mk_win_comctl_listview_column_w_t col;
	#elif mk_win_api == mk_win_api_both
	#endif

	#if mk_win_api != mk_win_api_both
	mk_win_base_user_types_lresult_t lr;
	mk_assert(listview);
	mk_assert(column);
	mk_assert(ret_idx);
	col.m_mask = column->m_mask;
	col.m_fmt = column->m_fmt;
	col.m_cx = column->m_cx;
	mk_try(mk_win_str_to_api_z(column->m_text, 0, &col.m_text));
	col.m_textmax = column->m_textmax;
	col.m_subitem = column->m_subitem;
	col.m_image = column->m_image;
	col.m_order = column->m_order;
	col.m_cxmin = column->m_cxmin;
	col.m_cxdefault = column->m_cxdefault;
	col.m_cxideal = column->m_cxideal;
	mk_try(mk_win_user_window_send(listview, mk_win_comctl_listview_wm_insertcolumnm, ((mk_win_base_user_types_wparam_t)(idx)), ((mk_win_base_user_types_lparam_t)(((mk_win_comctl_listview_column_w_lpct)(&col)))), &lr));
	*ret_idx = ((mk_win_base_types_intptr_t)(lr));
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(unicode_enabled == 0)
	{
		mk_win_comctl_listview_column_a_t col;
		mk_win_base_user_types_lresult_t lr;
		mk_assert(listview);
		mk_assert(column);
		mk_assert(ret_idx);
		col.m_mask = column->m_mask;
		col.m_fmt = column->m_fmt;
		col.m_cx = column->m_cx;
		mk_try(mk_win_str_to_narrow_z(column->m_text, 0, &col.m_text));
		col.m_textmax = column->m_textmax;
		col.m_subitem = column->m_subitem;
		col.m_image = column->m_image;
		col.m_order = column->m_order;
		col.m_cxmin = column->m_cxmin;
		col.m_cxdefault = column->m_cxdefault;
		col.m_cxideal = column->m_cxideal;
		mk_try(mk_win_user_window_send(listview, mk_win_comctl_listview_wm_insertcolumna, ((mk_win_base_user_types_wparam_t)(idx)), ((mk_win_base_user_types_lparam_t)(((mk_win_comctl_listview_column_a_lpct)(&col)))), &lr));
		*ret_idx = ((mk_win_base_types_intptr_t)(lr));
	}
	else
	{
		mk_win_comctl_listview_column_w_t col;
		mk_win_base_user_types_lresult_t lr;
		mk_assert(listview);
		mk_assert(column);
		mk_assert(ret_idx);
		col.m_mask = column->m_mask;
		col.m_fmt = column->m_fmt;
		col.m_cx = column->m_cx;
		mk_try(mk_win_str_to_wide_z(column->m_text, 0, &col.m_text));
		col.m_textmax = column->m_textmax;
		col.m_subitem = column->m_subitem;
		col.m_image = column->m_image;
		col.m_order = column->m_order;
		col.m_cxmin = column->m_cxmin;
		col.m_cxdefault = column->m_cxdefault;
		col.m_cxideal = column->m_cxideal;
		mk_try(mk_win_user_window_send(listview, mk_win_comctl_listview_wm_insertcolumnw, ((mk_win_base_user_types_wparam_t)(idx)), ((mk_win_base_user_types_lparam_t)(((mk_win_comctl_listview_column_w_lpct)(&col)))), &lr));
		*ret_idx = ((mk_win_base_types_intptr_t)(lr));
	}
	#endif
	return 0;

	#undef mk_win_comctl_listview_wm_insertcolumnm
}
