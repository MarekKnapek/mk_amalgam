#ifndef mk_include_guard_win_user_window
#define mk_include_guard_win_user_window


#include "mk_win_str.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_platform.h"


struct mk_win_user_window_create_s
{
	mk_win_base_types_dword_t m_extra_style;
	mk_win_strc_t m_class_name;
	mk_win_strc_t m_window_name;
	mk_win_base_types_dword_t m_style;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	mk_win_base_user_types_hwnd_t m_parent;
	mk_win_base_user_types_hmenu_t m_menu;
	mk_win_base_types_hinstance_t m_instance;
	mk_win_base_types_void_t m_param;
};
typedef struct mk_win_user_window_create_s mk_win_user_window_create_t;
typedef mk_win_user_window_create_t* mk_win_user_window_create_pt;
typedef mk_win_user_window_create_t const* mk_win_user_window_create_pct;

struct mk_win_user_window_mdicreate_s
{
	mk_win_strc_t m_class_name;
	mk_win_strc_t m_window_name;
	mk_win_base_types_hinstance_t m_instance;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	mk_win_base_types_dword_t m_style;
	mk_win_base_types_void_t m_param;
};
typedef struct mk_win_user_window_mdicreate_s mk_win_user_window_mdicreate_t;
typedef mk_win_user_window_mdicreate_t const* mk_win_user_window_mdicreate_pct;


#define mk_win_user_window_style_ex_left                0x00000000ul /* 0x0400 */
#define mk_win_user_window_style_ex_ltrreading          0x00000000ul /* 0x0400 */
#define mk_win_user_window_style_ex_rightscrollbar      0x00000000ul /* 0x0400 */
#define mk_win_user_window_style_ex_dlgmodalframe       0x00000001ul
#define mk_win_user_window_style_ex_noparentnotify      0x00000004ul
#define mk_win_user_window_style_ex_topmost             0x00000008ul
#define mk_win_user_window_style_ex_acceptfiles         0x00000010ul
#define mk_win_user_window_style_ex_transparent         0x00000020ul
#define mk_win_user_window_style_ex_mdichild            0x00000040ul /* 0x0400 */
#define mk_win_user_window_style_ex_toolwindow          0x00000080ul /* 0x0400 */
#define mk_win_user_window_style_ex_windowedge          0x00000100ul /* 0x0400 */
#define mk_win_user_window_style_ex_clientedge          0x00000200ul /* 0x0400 */
#define mk_win_user_window_style_ex_contexthelp         0x00000400ul /* 0x0400 */
#define mk_win_user_window_style_ex_right               0x00001000ul /* 0x0400 */
#define mk_win_user_window_style_ex_rtlreading          0x00002000ul /* 0x0400 */
#define mk_win_user_window_style_ex_leftscrollbar       0x00004000ul /* 0x0400 */
#define mk_win_user_window_style_ex_controlparent       0x00010000ul /* 0x0400 */
#define mk_win_user_window_style_ex_staticedge          0x00020000ul /* 0x0400 */
#define mk_win_user_window_style_ex_appwindow           0x00040000ul /* 0x0400 */
#define mk_win_user_window_style_ex_layered             0x00080000ul /* 0x0500 */
#define mk_win_user_window_style_ex_noinheritlayout     0x00100000ul /* 0x0500 */
#define mk_win_user_window_style_ex_noredirectionbitmap 0x00200000ul /* 0x0602 */
#define mk_win_user_window_style_ex_layoutrtl           0x00400000ul /* 0x0500 */
#define mk_win_user_window_style_ex_composited          0x02000000ul /* 0x0501 */
#define mk_win_user_window_style_ex_noactivate          0x08000000ul /* 0x0500 */
#define mk_win_user_window_style_ex_overlappedwindow    (mk_win_user_window_style_ex_windowedge | mk_win_user_window_style_ex_clientedge) /* 0x0400 */
#define mk_win_user_window_style_ex_palettewindow       (mk_win_user_window_style_ex_windowedge | mk_win_user_window_style_ex_toolwindow | mk_win_user_window_style_ex_topmost) /* 0x0400 */

#define mk_win_user_window_style_overlapped          0x00000000ul
#define mk_win_user_window_style_maximizebox         0x00010000ul
#define mk_win_user_window_style_minimizebox         0x00020000ul
#define mk_win_user_window_style_tabstop             0x00010000ul
#define mk_win_user_window_style_group               0x00020000ul
#define mk_win_user_window_style_thickframe          0x00040000ul
#define mk_win_user_window_style_sysmenu             0x00080000ul
#define mk_win_user_window_style_hscroll             0x00100000ul
#define mk_win_user_window_style_vscroll             0x00200000ul
#define mk_win_user_window_style_dlgframe            0x00400000ul
#define mk_win_user_window_style_border              0x00800000ul
#define mk_win_user_window_style_maximize            0x01000000ul
#define mk_win_user_window_style_clipchildren        0x02000000ul
#define mk_win_user_window_style_clipsiblings        0x04000000ul
#define mk_win_user_window_style_disabled            0x08000000ul
#define mk_win_user_window_style_visible             0x10000000ul
#define mk_win_user_window_style_minimize            0x20000000ul
#define mk_win_user_window_style_child               0x40000000ul
#define mk_win_user_window_style_popup               0x80000000ul
#define mk_win_user_window_style_caption             (mk_win_user_window_style_border | mk_win_user_window_style_dlgframe)
#define mk_win_user_window_style_overlappedwindow    (mk_win_user_window_style_overlapped | mk_win_user_window_style_caption | mk_win_user_window_style_sysmenu | mk_win_user_window_style_thickframe | mk_win_user_window_style_minimizebox | mk_win_user_window_style_maximizebox)
#define mk_win_user_window_style_popupwindow         (mk_win_user_window_style_popup | mk_win_user_window_style_border | mk_win_user_window_style_sysmenu)
#define mk_win_user_window_style_tiled               (mk_win_user_window_style_overlapped)
#define mk_win_user_window_style_sizebox             (mk_win_user_window_style_thickframe)
#define mk_win_user_window_style_iconic              (mk_win_user_window_style_minimize)
#define mk_win_user_window_style_childwindow         (mk_win_user_window_style_child)
#define mk_win_user_window_style_tiledwindow         (mk_win_user_window_style_overlappedwindow)

#if mk_win_base_platform_os == mk_win_base_platform_os_win16
#define mk_win_user_window_default_value ((int)0x8000)
#else
#define mk_win_user_window_default_value ((int)0x80000000)
#endif

#define mk_win_user_window_show_hide            0
#define mk_win_user_window_show_shownormal      1
#define mk_win_user_window_show_normal          1
#define mk_win_user_window_show_showminimized   2
#define mk_win_user_window_show_showmaximized   3
#define mk_win_user_window_show_maximize        3
#define mk_win_user_window_show_shownoactivate  4
#define mk_win_user_window_show_show            5
#define mk_win_user_window_show_minimize        6
#define mk_win_user_window_show_showminnoactiv  7
#define mk_win_user_window_show_showna          8
#define mk_win_user_window_show_restore         9
#define mk_win_user_window_show_showdefault    10
#define mk_win_user_window_show_forceminimize  11
#define mk_win_user_window_show_max            11


mk_jumbo int mk_win_user_window_create(mk_win_user_window_create_pct wnd_info, mk_win_base_user_types_hwnd_t* hwnd);
mk_jumbo int mk_win_user_window_set_info(mk_win_base_user_types_hwnd_t hwnd, int info_id, mk_win_base_types_uintptr_t info, mk_win_base_types_uintptr_t* prev_info);
mk_jumbo int mk_win_user_window_get_info(mk_win_base_user_types_hwnd_t hwnd, int info_id, mk_win_base_types_uintptr_t* info);
mk_jumbo int mk_win_user_window_defproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres);
mk_jumbo int mk_win_user_window_defframeproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_user_types_hwnd_t mdi, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres);
mk_jumbo int mk_win_user_window_defmdichildproc(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* lres);
mk_jumbo int mk_win_user_window_show(mk_win_base_user_types_hwnd_t hwnd, int show, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_window_post(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_types_bool_t* ret);
mk_jumbo int mk_win_user_window_send(mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg, mk_win_base_user_types_wparam_t wparam, mk_win_base_user_types_lparam_t lparam, mk_win_base_user_types_lresult_t* ret);
mk_jumbo int mk_win_user_window_is_child(mk_win_base_user_types_hwnd_t parent, mk_win_base_user_types_hwnd_t child, mk_win_base_types_bool_t* ret);

mk_jumbo int mk_win_user_window_post_close(mk_win_base_user_types_hwnd_t hwnd);

mk_jumbo int mk_win_user_window_send_close(mk_win_base_user_types_hwnd_t hwnd);
mk_jumbo int mk_win_user_window_send_mdicreate(mk_win_base_user_types_hwnd_t hwnd, mk_win_user_window_mdicreate_pct mdi, mk_win_base_user_types_hwnd_t* mdihwnd);


#endif
