#ifndef mk_include_guard_win_user_dialog_constants
#define mk_include_guard_win_user_dialog_constants


#define mk_win_user_dialog_style_absalign      0x0001ul
#define mk_win_user_dialog_style_sysmodal      0x0002ul
#define mk_win_user_dialog_style_3dlook        0x0004ul /* winver >= 0x0400 */
#define mk_win_user_dialog_style_fixedsys      0x0008ul /* winver >= 0x0400 */
#define mk_win_user_dialog_style_nofailcreate  0x0010ul /* winver >= 0x0400 */
#define mk_win_user_dialog_style_localedit     0x0020ul
#define mk_win_user_dialog_style_setfont       0x0040ul
#define mk_win_user_dialog_style_modalframe    0x0080ul
#define mk_win_user_dialog_style_noidlemsg     0x0100ul
#define mk_win_user_dialog_style_setforeground 0x0200ul /* not in win3.1 */
#define mk_win_user_dialog_style_control       0x0400ul /* winver >= 0x0400 */
#define mk_win_user_dialog_style_center        0x0800ul /* winver >= 0x0400 */
#define mk_win_user_dialog_style_centermouse   0x1000ul /* winver >= 0x0400 */
#define mk_win_user_dialog_style_contexthelp   0x2000ul /* winver >= 0x0400 */
#define mk_win_user_dialog_style_usepixels     0x8000ul /* wce >= 0x0500 */
#define mk_win_user_dialog_style_shellfont     (mk_win_user_dialog_style_fixedsys | mk_win_user_dialog_style_setfont) /* winver >= 0x0400 */


#endif
