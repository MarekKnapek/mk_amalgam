#ifndef mk_include_guard_win_user_window_constants
#define mk_include_guard_win_user_window_constants


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
#define mk_win_user_window_style_caption             (mk_win_user_window_style_dlgframe | mk_win_user_window_style_border)
#define mk_win_user_window_style_overlappedwindow    (mk_win_user_window_style_overlapped | mk_win_user_window_style_caption | mk_win_user_window_style_sysmenu | mk_win_user_window_style_thickframe | mk_win_user_window_style_minimizebox | mk_win_user_window_style_maximizebox)
#define mk_win_user_window_style_popupwindow         (mk_win_user_window_style_popup | mk_win_user_window_style_border | mk_win_user_window_style_sysmenu)
#define mk_win_user_window_style_tiled               (mk_win_user_window_style_overlapped)
#define mk_win_user_window_style_sizebox             (mk_win_user_window_style_thickframe)
#define mk_win_user_window_style_iconic              (mk_win_user_window_style_minimize)
#define mk_win_user_window_style_childwindow         (mk_win_user_window_style_child)
#define mk_win_user_window_style_tiledwindow         (mk_win_user_window_style_overlappedwindow)


#endif
