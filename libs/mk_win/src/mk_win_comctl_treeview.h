#ifndef mk_include_guard_win_comctl_treeview
#define mk_include_guard_win_comctl_treeview


#include "mk_win_char.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_utils/src/mk_jumbo.h"


mk_win_base_types_make_handle(mk_win_comctl_treeview_htreeitem_t);

struct mk_win_comctl_treeview_item_a_s
{
	mk_win_base_types_uint_t m_mask;
	mk_win_comctl_treeview_htreeitem_t m_hitem;
	mk_win_base_types_uint_t m_state;
	mk_win_base_types_uint_t m_state_mask;
	mk_win_base_types_char_lpt m_text;
	int m_text_len;
	int m_image_idx;
	int m_selected_image_idx;
	int m_children_count;
	mk_win_base_user_types_lparam_t m_param;
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_item_a);

struct mk_win_comctl_treeview_item_w_s
{
	mk_win_base_types_uint_t m_mask;
	mk_win_comctl_treeview_htreeitem_t m_hitem;
	mk_win_base_types_uint_t m_state;
	mk_win_base_types_uint_t m_state_mask;
	mk_win_base_types_wchar_lpt m_text;
	int m_text_len;
	int m_image_idx;
	int m_selected_image_idx;
	int m_children_count;
	mk_win_base_user_types_lparam_t m_param;
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_item_w);

struct mk_win_comctl_treeview_item_s
{
	mk_win_base_types_uint_t m_mask;
	mk_win_comctl_treeview_htreeitem_t m_hitem;
	mk_win_base_types_uint_t m_state;
	mk_win_base_types_uint_t m_state_mask;
	mk_win_str_t m_text;
	int m_text_len;
	int m_image_idx;
	int m_selected_image_idx;
	int m_children_count;
	mk_win_base_user_types_lparam_t m_param;
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_item);

struct mk_win_comctl_treeview_item_exa_s
{
	mk_win_base_types_uint_t m_mask;
	mk_win_comctl_treeview_htreeitem_t m_hitem;
	mk_win_base_types_uint_t m_state;
	mk_win_base_types_uint_t m_state_mask;
	mk_win_base_types_char_lpt m_text;
	int m_text_len;
	int m_image_idx;
	int m_selected_image_idx;
	int m_children_count;
	mk_win_base_user_types_lparam_t m_param;
	int m_integral;
	mk_win_base_types_uint_t m_state_ex; /* ie >= 0x0600 */
	mk_win_base_user_types_hwnd_t m_hwnd; /* ie >= 0x0600 */
	int m_expanded_image_idx; /* ie >= 0x0600 */
	int m_reserved; /* ntddi_version >= 0x06010000 */
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_item_exa);

struct mk_win_comctl_treeview_item_exw_s
{
	mk_win_base_types_uint_t m_mask;
	mk_win_comctl_treeview_htreeitem_t m_hitem;
	mk_win_base_types_uint_t m_state;
	mk_win_base_types_uint_t m_state_mask;
	mk_win_base_types_wchar_lpt m_text;
	int m_text_len;
	int m_image_idx;
	int m_selected_image_idx;
	int m_children_count;
	mk_win_base_user_types_lparam_t m_param;
	int m_integral;
	mk_win_base_types_uint_t m_state_ex; /* ie >= 0x0600 */
	mk_win_base_user_types_hwnd_t m_hwnd; /* ie >= 0x0600 */
	int m_expanded_image_idx; /* ie >= 0x0600 */
	int m_reserved; /* ntddi_version >= 0x06010000 */
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_item_exw);

struct mk_win_comctl_treeview_item_ex_s
{
	mk_win_base_types_uint_t m_mask;
	mk_win_comctl_treeview_htreeitem_t m_hitem;
	mk_win_base_types_uint_t m_state;
	mk_win_base_types_uint_t m_state_mask;
	mk_win_str_t m_text;
	int m_text_len;
	int m_image_idx;
	int m_selected_image_idx;
	int m_children_count;
	mk_win_base_user_types_lparam_t m_param;
	int m_integral;
	mk_win_base_types_uint_t m_state_ex; /* ie >= 0x0600 */
	mk_win_base_user_types_hwnd_t m_hwnd; /* ie >= 0x0600 */
	int m_expanded_image_idx; /* ie >= 0x0600 */
	int m_reserved; /* ntddi_version >= 0x06010000 */
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_item_ex);

struct mk_win_comctl_treeview_insert_a_s
{
	mk_win_comctl_treeview_htreeitem_t m_parent;
	mk_win_comctl_treeview_htreeitem_t m_insert_after;
	union
	{
		mk_win_comctl_treeview_item_a_t m_item;
		mk_win_comctl_treeview_item_exa_t m_item_ex;
	} m_item;
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_insert_a);

struct mk_win_comctl_treeview_insert_w_s
{
	mk_win_comctl_treeview_htreeitem_t m_parent;
	mk_win_comctl_treeview_htreeitem_t m_insert_after;
	union
	{
		mk_win_comctl_treeview_item_w_t m_item;
		mk_win_comctl_treeview_item_exw_t m_item_ex;
	} m_item;
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_insert_w);

struct mk_win_comctl_treeview_insert_s
{
	mk_win_comctl_treeview_htreeitem_t m_parent;
	mk_win_comctl_treeview_htreeitem_t m_insert_after;
	union
	{
		mk_win_comctl_treeview_item_t m_item;
		mk_win_comctl_treeview_item_ex_t m_item_ex;
	} m_item;
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_insert);

struct mk_win_comctl_treeview_nm_dispinfoa_s
{
	mk_win_base_user_nmhdr_t m_nmhdr;
	mk_win_comctl_treeview_item_a_t m_itema;
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_nm_dispinfoa);

struct mk_win_comctl_treeview_nm_dispinfow_s
{
	mk_win_base_user_nmhdr_t m_nmhdr;
	mk_win_comctl_treeview_item_w_t m_itemw;
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_nm_dispinfow);

struct mk_win_comctl_treeview_nm_dispinfom_s
{
	mk_win_base_user_nmhdr_t m_nmhdr;
	union
	{
		mk_win_comctl_treeview_item_a_t m_item_a;
		mk_win_comctl_treeview_item_w_t m_item_w;
	} m_item;
};
mk_win_base_types_make_struct(mk_win_comctl_treeview_nm_dispinfom);


#define mk_win_comctl_treeview_wm_first               ((unsigned short)(0x1100ul))
#define mk_win_comctl_treeview_wm_insertitema         ((unsigned short)(mk_win_comctl_treeview_wm_first +  0))
#define mk_win_comctl_treeview_wm_deleteitem          ((unsigned short)(mk_win_comctl_treeview_wm_first +  1))
#define mk_win_comctl_treeview_wm_expand              ((unsigned short)(mk_win_comctl_treeview_wm_first +  2))
#define mk_win_comctl_treeview_wm_getitemrect         ((unsigned short)(mk_win_comctl_treeview_wm_first +  4))
#define mk_win_comctl_treeview_wm_getcount            ((unsigned short)(mk_win_comctl_treeview_wm_first +  5))
#define mk_win_comctl_treeview_wm_getindent           ((unsigned short)(mk_win_comctl_treeview_wm_first +  6))
#define mk_win_comctl_treeview_wm_setindent           ((unsigned short)(mk_win_comctl_treeview_wm_first +  7))
#define mk_win_comctl_treeview_wm_getimagelist        ((unsigned short)(mk_win_comctl_treeview_wm_first +  8))
#define mk_win_comctl_treeview_wm_setimagelist        ((unsigned short)(mk_win_comctl_treeview_wm_first +  9))
#define mk_win_comctl_treeview_wm_getnextitem         ((unsigned short)(mk_win_comctl_treeview_wm_first + 10))
#define mk_win_comctl_treeview_wm_selectitem          ((unsigned short)(mk_win_comctl_treeview_wm_first + 11))
#define mk_win_comctl_treeview_wm_getitema            ((unsigned short)(mk_win_comctl_treeview_wm_first + 12))
#define mk_win_comctl_treeview_wm_setitema            ((unsigned short)(mk_win_comctl_treeview_wm_first + 13))
#define mk_win_comctl_treeview_wm_editlabela          ((unsigned short)(mk_win_comctl_treeview_wm_first + 14))
#define mk_win_comctl_treeview_wm_geteditcontrol      ((unsigned short)(mk_win_comctl_treeview_wm_first + 15))
#define mk_win_comctl_treeview_wm_getvisiblecount     ((unsigned short)(mk_win_comctl_treeview_wm_first + 16))
#define mk_win_comctl_treeview_wm_hittest             ((unsigned short)(mk_win_comctl_treeview_wm_first + 17))
#define mk_win_comctl_treeview_wm_createdragimage     ((unsigned short)(mk_win_comctl_treeview_wm_first + 18))
#define mk_win_comctl_treeview_wm_sortchildren        ((unsigned short)(mk_win_comctl_treeview_wm_first + 19))
#define mk_win_comctl_treeview_wm_ensurevisible       ((unsigned short)(mk_win_comctl_treeview_wm_first + 20))
#define mk_win_comctl_treeview_wm_sortchildrencb      ((unsigned short)(mk_win_comctl_treeview_wm_first + 21))
#define mk_win_comctl_treeview_wm_endeditlabelnow     ((unsigned short)(mk_win_comctl_treeview_wm_first + 22))
#define mk_win_comctl_treeview_wm_getisearchstringa   ((unsigned short)(mk_win_comctl_treeview_wm_first + 23))
#define mk_win_comctl_treeview_wm_settooltips         ((unsigned short)(mk_win_comctl_treeview_wm_first + 24))
#define mk_win_comctl_treeview_wm_gettooltips         ((unsigned short)(mk_win_comctl_treeview_wm_first + 25))
#define mk_win_comctl_treeview_wm_setinsertmark       ((unsigned short)(mk_win_comctl_treeview_wm_first + 26))
#define mk_win_comctl_treeview_wm_setitemheight       ((unsigned short)(mk_win_comctl_treeview_wm_first + 27))
#define mk_win_comctl_treeview_wm_getitemheight       ((unsigned short)(mk_win_comctl_treeview_wm_first + 28))
#define mk_win_comctl_treeview_wm_setbkcolor          ((unsigned short)(mk_win_comctl_treeview_wm_first + 29))
#define mk_win_comctl_treeview_wm_settextcolor        ((unsigned short)(mk_win_comctl_treeview_wm_first + 30))
#define mk_win_comctl_treeview_wm_getbkcolor          ((unsigned short)(mk_win_comctl_treeview_wm_first + 31))
#define mk_win_comctl_treeview_wm_gettextcolor        ((unsigned short)(mk_win_comctl_treeview_wm_first + 32))
#define mk_win_comctl_treeview_wm_setscrolltime       ((unsigned short)(mk_win_comctl_treeview_wm_first + 33))
#define mk_win_comctl_treeview_wm_getscrolltime       ((unsigned short)(mk_win_comctl_treeview_wm_first + 34))
#define mk_win_comctl_treeview_wm_setborder           ((unsigned short)(mk_win_comctl_treeview_wm_first + 35))
#define mk_win_comctl_treeview_wm_setinsertmarkcolor  ((unsigned short)(mk_win_comctl_treeview_wm_first + 37))
#define mk_win_comctl_treeview_wm_getinsertmarkcolor  ((unsigned short)(mk_win_comctl_treeview_wm_first + 38))
#define mk_win_comctl_treeview_wm_getitemstate        ((unsigned short)(mk_win_comctl_treeview_wm_first + 39))
#define mk_win_comctl_treeview_wm_setlinecolor        ((unsigned short)(mk_win_comctl_treeview_wm_first + 40))
#define mk_win_comctl_treeview_wm_getlinecolor        ((unsigned short)(mk_win_comctl_treeview_wm_first + 41))
#define mk_win_comctl_treeview_wm_mapaccidtohtreeitem ((unsigned short)(mk_win_comctl_treeview_wm_first + 42))
#define mk_win_comctl_treeview_wm_maphtreeitemtoaccid ((unsigned short)(mk_win_comctl_treeview_wm_first + 43))
#define mk_win_comctl_treeview_wm_setextendedstyle    ((unsigned short)(mk_win_comctl_treeview_wm_first + 44))
#define mk_win_comctl_treeview_wm_getextendedstyle    ((unsigned short)(mk_win_comctl_treeview_wm_first + 45))
#define mk_win_comctl_treeview_wm_insertitemw         ((unsigned short)(mk_win_comctl_treeview_wm_first + 50))
#define mk_win_comctl_treeview_wm_sethot              ((unsigned short)(mk_win_comctl_treeview_wm_first + 58))
#define mk_win_comctl_treeview_wm_setautoscrollinfo   ((unsigned short)(mk_win_comctl_treeview_wm_first + 59))
#define mk_win_comctl_treeview_wm_getitemw            ((unsigned short)(mk_win_comctl_treeview_wm_first + 62))
#define mk_win_comctl_treeview_wm_setitemw            ((unsigned short)(mk_win_comctl_treeview_wm_first + 63))
#define mk_win_comctl_treeview_wm_getisearchstringw   ((unsigned short)(mk_win_comctl_treeview_wm_first + 64))
#define mk_win_comctl_treeview_wm_editlabelw          ((unsigned short)(mk_win_comctl_treeview_wm_first + 65))
#define mk_win_comctl_treeview_wm_getselectedcount    ((unsigned short)(mk_win_comctl_treeview_wm_first + 70))
#define mk_win_comctl_treeview_wm_showinfotip         ((unsigned short)(mk_win_comctl_treeview_wm_first + 71))
#define mk_win_comctl_treeview_wm_getitempartrect     ((unsigned short)(mk_win_comctl_treeview_wm_first + 72))

#define mk_win_comctl_treeview_notify_first               ((unsigned int)(0u - 400u))
#define mk_win_comctl_treeview_notify_last                ((unsigned int)(0u - 499u))
#define mk_win_comctl_treeview_notify_selchanginga        ((unsigned int)(mk_win_comctl_treeview_notify_first -  1u))
#define mk_win_comctl_treeview_notify_selchangeda         ((unsigned int)(mk_win_comctl_treeview_notify_first -  2u))
#define mk_win_comctl_treeview_notify_getdispinfoa        ((unsigned int)(mk_win_comctl_treeview_notify_first -  3u))
#define mk_win_comctl_treeview_notify_setdispinfoa        ((unsigned int)(mk_win_comctl_treeview_notify_first -  4u))
#define mk_win_comctl_treeview_notify_itemexpandinga      ((unsigned int)(mk_win_comctl_treeview_notify_first -  5u))
#define mk_win_comctl_treeview_notify_itemexpandeda       ((unsigned int)(mk_win_comctl_treeview_notify_first -  6u))
#define mk_win_comctl_treeview_notify_begindraga          ((unsigned int)(mk_win_comctl_treeview_notify_first -  7u))
#define mk_win_comctl_treeview_notify_beginrdraga         ((unsigned int)(mk_win_comctl_treeview_notify_first -  8u))
#define mk_win_comctl_treeview_notify_deleteitema         ((unsigned int)(mk_win_comctl_treeview_notify_first -  9u))
#define mk_win_comctl_treeview_notify_beginlabeledita     ((unsigned int)(mk_win_comctl_treeview_notify_first - 10u))
#define mk_win_comctl_treeview_notify_endlabeledita       ((unsigned int)(mk_win_comctl_treeview_notify_first - 11u))
#define mk_win_comctl_treeview_notify_keydown             ((unsigned int)(mk_win_comctl_treeview_notify_first - 12u))
#define mk_win_comctl_treeview_notify_getinfotipa         ((unsigned int)(mk_win_comctl_treeview_notify_first - 13u))
#define mk_win_comctl_treeview_notify_getinfotipw         ((unsigned int)(mk_win_comctl_treeview_notify_first - 14u))
#define mk_win_comctl_treeview_notify_singleexpand        ((unsigned int)(mk_win_comctl_treeview_notify_first - 15u))
#define mk_win_comctl_treeview_notify_itemchanginga       ((unsigned int)(mk_win_comctl_treeview_notify_first - 16u))
#define mk_win_comctl_treeview_notify_itemchangingw       ((unsigned int)(mk_win_comctl_treeview_notify_first - 17u))
#define mk_win_comctl_treeview_notify_itemchangeda        ((unsigned int)(mk_win_comctl_treeview_notify_first - 18u))
#define mk_win_comctl_treeview_notify_itemchangedw        ((unsigned int)(mk_win_comctl_treeview_notify_first - 19u))
#define mk_win_comctl_treeview_notify_asyncdraw           ((unsigned int)(mk_win_comctl_treeview_notify_first - 20u))
#define mk_win_comctl_treeview_notify_selchangingw        ((unsigned int)(mk_win_comctl_treeview_notify_first - 50u))
#define mk_win_comctl_treeview_notify_selchangedw         ((unsigned int)(mk_win_comctl_treeview_notify_first - 51u))
#define mk_win_comctl_treeview_notify_getdispinfow        ((unsigned int)(mk_win_comctl_treeview_notify_first - 52u))
#define mk_win_comctl_treeview_notify_setdispinfow        ((unsigned int)(mk_win_comctl_treeview_notify_first - 53u))
#define mk_win_comctl_treeview_notify_itemexpandingw      ((unsigned int)(mk_win_comctl_treeview_notify_first - 54u))
#define mk_win_comctl_treeview_notify_itemexpandedw       ((unsigned int)(mk_win_comctl_treeview_notify_first - 55u))
#define mk_win_comctl_treeview_notify_begindragw          ((unsigned int)(mk_win_comctl_treeview_notify_first - 56u))
#define mk_win_comctl_treeview_notify_beginrdragw         ((unsigned int)(mk_win_comctl_treeview_notify_first - 57u))
#define mk_win_comctl_treeview_notify_deleteitemw         ((unsigned int)(mk_win_comctl_treeview_notify_first - 58u))
#define mk_win_comctl_treeview_notify_beginlabeleditw     ((unsigned int)(mk_win_comctl_treeview_notify_first - 59u))
#define mk_win_comctl_treeview_notify_endlabeleditw       ((unsigned int)(mk_win_comctl_treeview_notify_first - 60u))

#define mk_win_comctl_treeview_hti_root  ((mk_win_comctl_treeview_htreeitem_t)(((mk_win_base_types_uintptr_t)(0)) - ((mk_win_base_types_uintptr_t)(0x10000ul))))
#define mk_win_comctl_treeview_hti_first ((mk_win_comctl_treeview_htreeitem_t)(((mk_win_base_types_uintptr_t)(0)) - ((mk_win_base_types_uintptr_t)(0x0fffful))))
#define mk_win_comctl_treeview_hti_last  ((mk_win_comctl_treeview_htreeitem_t)(((mk_win_base_types_uintptr_t)(0)) - ((mk_win_base_types_uintptr_t)(0x0fffeul))))
#define mk_win_comctl_treeview_hti_sort  ((mk_win_comctl_treeview_htreeitem_t)(((mk_win_base_types_uintptr_t)(0)) - ((mk_win_base_types_uintptr_t)(0x0fffdul))))

#define mk_win_comctl_treeview_mask_text          0x0001
#define mk_win_comctl_treeview_mask_image         0x0002
#define mk_win_comctl_treeview_mask_param         0x0004
#define mk_win_comctl_treeview_mask_state         0x0008
#define mk_win_comctl_treeview_mask_handle        0x0010
#define mk_win_comctl_treeview_mask_selectedimage 0x0020
#define mk_win_comctl_treeview_mask_children      0x0040
#define mk_win_comctl_treeview_mask_integral      0x0080
#define mk_win_comctl_treeview_mask_stateex       0x0100 /* ie >= 0x0600 */
#define mk_win_comctl_treeview_mask_expandedimage 0x0200 /* ie >= 0x0600 */

#define mk_win_comctl_treeview_text_callback ((mk_win_char_t*)(((unsigned char*)(0)) - ((unsigned char*)(1)))) /*TODO:far*/
#define mk_win_comctl_treeview_children_callback (-1)


mk_jumbo int mk_win_comctl_treeview_insert(mk_win_base_user_types_hwnd_t tree_view, mk_win_comctl_treeview_insert_t* insert, mk_win_comctl_treeview_htreeitem_t* ret);


#endif
