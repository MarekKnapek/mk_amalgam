#ifndef mk_include_guard_win_comctl_statusbar
#define mk_include_guard_win_comctl_statusbar


#include "mk_win_char.h"
#include "mk_win_user_window.h"

#include "../../mk_utils/src/mk_jumbo.h"


#define mk_win_comctl_statusbar_classname mk_win_char_c("msctls_statusbar32")

#define mk_win_comctl_statusbar_wm_settexta       ((unsigned short int)(mk_win_user_window_wm_user +  1))
#define mk_win_comctl_statusbar_wm_gettexta       ((unsigned short int)(mk_win_user_window_wm_user +  2))
#define mk_win_comctl_statusbar_wm_gettextlengtha ((unsigned short int)(mk_win_user_window_wm_user +  3))
#define mk_win_comctl_statusbar_wm_setparts       ((unsigned short int)(mk_win_user_window_wm_user +  4))
#define mk_win_comctl_statusbar_wm_getparts       ((unsigned short int)(mk_win_user_window_wm_user +  6))
#define mk_win_comctl_statusbar_wm_getborders     ((unsigned short int)(mk_win_user_window_wm_user +  7))
#define mk_win_comctl_statusbar_wm_setminheight   ((unsigned short int)(mk_win_user_window_wm_user +  8))
#define mk_win_comctl_statusbar_wm_simple         ((unsigned short int)(mk_win_user_window_wm_user +  9))
#define mk_win_comctl_statusbar_wm_getrect        ((unsigned short int)(mk_win_user_window_wm_user + 10))
#define mk_win_comctl_statusbar_wm_settextw       ((unsigned short int)(mk_win_user_window_wm_user + 11))
#define mk_win_comctl_statusbar_wm_gettextlengthw ((unsigned short int)(mk_win_user_window_wm_user + 12))
#define mk_win_comctl_statusbar_wm_gettextw       ((unsigned short int)(mk_win_user_window_wm_user + 13))
#define mk_win_comctl_statusbar_wm_issimple       ((unsigned short int)(mk_win_user_window_wm_user + 14))
#define mk_win_comctl_statusbar_wm_seticon        ((unsigned short int)(mk_win_user_window_wm_user + 15))
#define mk_win_comctl_statusbar_wm_settiptexta    ((unsigned short int)(mk_win_user_window_wm_user + 16))
#define mk_win_comctl_statusbar_wm_settiptextw    ((unsigned short int)(mk_win_user_window_wm_user + 17))
#define mk_win_comctl_statusbar_wm_gettiptexta    ((unsigned short int)(mk_win_user_window_wm_user + 18))
#define mk_win_comctl_statusbar_wm_gettiptextw    ((unsigned short int)(mk_win_user_window_wm_user + 19))
#define mk_win_comctl_statusbar_wm_geticon        ((unsigned short int)(mk_win_user_window_wm_user + 20))

#define mk_win_comctl_statusbar_ws_sizegrip ((unsigned short int)(0x0100ul))
#define mk_win_comctl_statusbar_ws_tooltips ((unsigned short int)(0x0800ul)) /* version >= 4.71 */

#define mk_win_comctl_statusbar_settext_param_simpleid ((unsigned short int)(0x00fful))

#define mk_win_comctl_statusbar_settext_param_noborders    ((unsigned short int)(0x0100ul))
#define mk_win_comctl_statusbar_settext_param_popout       ((unsigned short int)(0x0200ul))
#define mk_win_comctl_statusbar_settext_param_rtlreading   ((unsigned short int)(0x0400ul))
#define mk_win_comctl_statusbar_settext_param_notabparsing ((unsigned short int)(0x0800ul))
#define mk_win_comctl_statusbar_settext_param_ownerdraw    ((unsigned short int)(0x1000ul))


mk_jumbo int mk_win_comctl_statusbar_set_text(mk_win_base_user_types_hwnd_t statusbar, unsigned short int part_idx, unsigned short int drawing_operation, mk_win_strc_t text);


#endif
