#ifndef mk_include_guard_win_user_listbox
#define mk_include_guard_win_user_listbox


#include "mk_win_user_window_constants.h"


#define mk_win_user_listbox_notify_errspace  ((int)(-2))
#define mk_win_user_listbox_notify_selchange ((int)( 1))
#define mk_win_user_listbox_notify_dblclk    ((int)( 2))
#define mk_win_user_listbox_notify_selcancel ((int)( 3))
#define mk_win_user_listbox_notify_setfocus  ((int)( 4))
#define mk_win_user_listbox_notify_killfocus ((int)( 5))

#define mk_win_user_listbox_style_notify            0x0001ul
#define mk_win_user_listbox_style_sort              0x0002ul
#define mk_win_user_listbox_style_noredraw          0x0004ul
#define mk_win_user_listbox_style_multiplesel       0x0008ul
#define mk_win_user_listbox_style_ownerdrawfixed    0x0010ul
#define mk_win_user_listbox_style_ownerdrawvariable 0x0020ul
#define mk_win_user_listbox_style_hasstrings        0x0040ul
#define mk_win_user_listbox_style_usetabstops       0x0080ul
#define mk_win_user_listbox_style_nointegralheight  0x0100ul
#define mk_win_user_listbox_style_multicolumn       0x0200ul
#define mk_win_user_listbox_style_wantkeyboardinput 0x0400ul
#define mk_win_user_listbox_style_extendedsel       0x0800ul
#define mk_win_user_listbox_style_disablenoscroll   0x1000ul /* winver >= 0x030a */
#define mk_win_user_listbox_style_nodata            0x2000ul
#define mk_win_user_listbox_style_nosel             0x4000ul /* winver >= 0x0400 */
#define mk_win_user_listbox_style_combobox          0x8000ul
#define mk_win_user_listbox_style_standard          (mk_win_user_listbox_style_notify | mk_win_user_listbox_style_sort | mk_win_user_window_style_vscroll | mk_win_user_window_style_border)

#if mk_win_base_platform_os == mk_win_base_platform_os_win16
#define mk_win_user_listbox_wm_addstring           ((unsigned short)(0x0400ul +  1))
#define mk_win_user_listbox_wm_insertstring        ((unsigned short)(0x0400ul +  2))
#define mk_win_user_listbox_wm_deletestring        ((unsigned short)(0x0400ul +  3))
#define mk_win_user_listbox_wm_resetcontent        ((unsigned short)(0x0400ul +  5))
#define mk_win_user_listbox_wm_setsel              ((unsigned short)(0x0400ul +  6))
#define mk_win_user_listbox_wm_setcursel           ((unsigned short)(0x0400ul +  7))
#define mk_win_user_listbox_wm_getsel              ((unsigned short)(0x0400ul +  8))
#define mk_win_user_listbox_wm_getcursel           ((unsigned short)(0x0400ul +  9))
#define mk_win_user_listbox_wm_gettext             ((unsigned short)(0x0400ul + 10))
#define mk_win_user_listbox_wm_gettextlen          ((unsigned short)(0x0400ul + 11))
#define mk_win_user_listbox_wm_getcount            ((unsigned short)(0x0400ul + 12))
#define mk_win_user_listbox_wm_selectstring        ((unsigned short)(0x0400ul + 13))
#define mk_win_user_listbox_wm_dir                 ((unsigned short)(0x0400ul + 14))
#define mk_win_user_listbox_wm_gettopindex         ((unsigned short)(0x0400ul + 15))
#define mk_win_user_listbox_wm_findstring          ((unsigned short)(0x0400ul + 16))
#define mk_win_user_listbox_wm_getselcount         ((unsigned short)(0x0400ul + 17))
#define mk_win_user_listbox_wm_getselitems         ((unsigned short)(0x0400ul + 18))
#define mk_win_user_listbox_wm_settabstops         ((unsigned short)(0x0400ul + 19))
#define mk_win_user_listbox_wm_gethorizontalextent ((unsigned short)(0x0400ul + 20))
#define mk_win_user_listbox_wm_sethorizontalextent ((unsigned short)(0x0400ul + 21))
#define mk_win_user_listbox_wm_setcolumnwidth      ((unsigned short)(0x0400ul + 22))
#define mk_win_user_listbox_wm_settopindex         ((unsigned short)(0x0400ul + 24))
#define mk_win_user_listbox_wm_getitemrect         ((unsigned short)(0x0400ul + 25))
#define mk_win_user_listbox_wm_getitemdata         ((unsigned short)(0x0400ul + 26))
#define mk_win_user_listbox_wm_setitemdata         ((unsigned short)(0x0400ul + 27))
#define mk_win_user_listbox_wm_selitemrange        ((unsigned short)(0x0400ul + 28))
#define mk_win_user_listbox_wm_setcaretindex       ((unsigned short)(0x0400ul + 31))
#define mk_win_user_listbox_wm_getcaretindex       ((unsigned short)(0x0400ul + 32))
#define mk_win_user_listbox_wm_setitemheight       ((unsigned short)(0x0400ul + 33)) /* winver >= 0x030a */
#define mk_win_user_listbox_wm_getitemheight       ((unsigned short)(0x0400ul + 34)) /* winver >= 0x030a */
#define mk_win_user_listbox_wm_findstringexact     ((unsigned short)(0x0400ul + 35)) /* winver >= 0x030a */
#else
#define mk_win_user_listbox_wm_addstring           ((unsigned short)(0x0180ul))
#define mk_win_user_listbox_wm_insertstring        ((unsigned short)(0x0181ul))
#define mk_win_user_listbox_wm_deletestring        ((unsigned short)(0x0182ul))
#define mk_win_user_listbox_wm_selitemrangeex      ((unsigned short)(0x0183ul))
#define mk_win_user_listbox_wm_resetcontent        ((unsigned short)(0x0184ul))
#define mk_win_user_listbox_wm_setsel              ((unsigned short)(0x0185ul))
#define mk_win_user_listbox_wm_setcursel           ((unsigned short)(0x0186ul))
#define mk_win_user_listbox_wm_getsel              ((unsigned short)(0x0187ul))
#define mk_win_user_listbox_wm_getcursel           ((unsigned short)(0x0188ul))
#define mk_win_user_listbox_wm_gettext             ((unsigned short)(0x0189ul))
#define mk_win_user_listbox_wm_gettextlen          ((unsigned short)(0x018aul))
#define mk_win_user_listbox_wm_getcount            ((unsigned short)(0x018bul))
#define mk_win_user_listbox_wm_selectstring        ((unsigned short)(0x018cul))
#define mk_win_user_listbox_wm_dir                 ((unsigned short)(0x018dul))
#define mk_win_user_listbox_wm_gettopindex         ((unsigned short)(0x018eul))
#define mk_win_user_listbox_wm_findstring          ((unsigned short)(0x018ful))
#define mk_win_user_listbox_wm_getselcount         ((unsigned short)(0x0190ul))
#define mk_win_user_listbox_wm_getselitems         ((unsigned short)(0x0191ul))
#define mk_win_user_listbox_wm_settabstops         ((unsigned short)(0x0192ul))
#define mk_win_user_listbox_wm_gethorizontalextent ((unsigned short)(0x0193ul))
#define mk_win_user_listbox_wm_sethorizontalextent ((unsigned short)(0x0194ul))
#define mk_win_user_listbox_wm_setcolumnwidth      ((unsigned short)(0x0195ul))
#define mk_win_user_listbox_wm_addfile             ((unsigned short)(0x0196ul))
#define mk_win_user_listbox_wm_settopindex         ((unsigned short)(0x0197ul))
#define mk_win_user_listbox_wm_getitemrect         ((unsigned short)(0x0198ul))
#define mk_win_user_listbox_wm_getitemdata         ((unsigned short)(0x0199ul))
#define mk_win_user_listbox_wm_setitemdata         ((unsigned short)(0x019aul))
#define mk_win_user_listbox_wm_selitemrange        ((unsigned short)(0x019bul))
#define mk_win_user_listbox_wm_setanchorindex      ((unsigned short)(0x019cul))
#define mk_win_user_listbox_wm_getanchorindex      ((unsigned short)(0x019dul))
#define mk_win_user_listbox_wm_setcaretindex       ((unsigned short)(0x019eul))
#define mk_win_user_listbox_wm_getcaretindex       ((unsigned short)(0x019ful))
#define mk_win_user_listbox_wm_setitemheight       ((unsigned short)(0x01a0ul))
#define mk_win_user_listbox_wm_getitemheight       ((unsigned short)(0x01a1ul))
#define mk_win_user_listbox_wm_findstringexact     ((unsigned short)(0x01a2ul))
#define mk_win_user_listbox_wm_setlocale           ((unsigned short)(0x01a5ul))
#define mk_win_user_listbox_wm_getlocale           ((unsigned short)(0x01a6ul))
#define mk_win_user_listbox_wm_setcount            ((unsigned short)(0x01a7ul))
#define mk_win_user_listbox_wm_initstorage         ((unsigned short)(0x01a8ul)) /* winver >= 0x0400 */
#define mk_win_user_listbox_wm_itemfrompoint       ((unsigned short)(0x01a9ul)) /* winver >= 0x0400 */
#define mk_win_user_listbox_wm_multipleaddstring   ((unsigned short)(0x01b1ul)) /* wce >= 0x0400 */
#define mk_win_user_listbox_wm_getlistboxinfo      ((unsigned short)(0x01b2ul)) /* winnt >= 0x0501 */
#endif

#define mk_win_user_listbox_error_okay     ( 0)
#define mk_win_user_listbox_error_err      (-1)
#define mk_win_user_listbox_error_errspace (-2)


#endif
