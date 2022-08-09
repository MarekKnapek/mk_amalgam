#ifndef mk_include_guard_win_user_class
#define mk_include_guard_win_user_class


#include "mk_win_char.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_utils/src/mk_jumbo.h"


#define mk_win_user_class_style_vredraw         0x00000001ul
#define mk_win_user_class_style_hredraw         0x00000002ul
#define mk_win_user_class_style_keycvtwindow    0x00000004ul /* deprecated? */
#define mk_win_user_class_style_dblclks         0x00000008ul
#define mk_win_user_class_style_unknown_4       0x00000010ul /* unknown */
#define mk_win_user_class_style_owndc           0x00000020ul
#define mk_win_user_class_style_classdc         0x00000040ul
#define mk_win_user_class_style_parentdc        0x00000080ul
#define mk_win_user_class_style_nokeycvt        0x00000100ul /* deprecated? */
#define mk_win_user_class_style_noclose         0x00000200ul
#define mk_win_user_class_style_unknown_10      0x00000400ul /* unknown */
#define mk_win_user_class_style_savebits        0x00000800ul
#define mk_win_user_class_style_bytealignclient 0x00001000ul
#define mk_win_user_class_style_bytealignwindow 0x00002000ul
#define mk_win_user_class_style_globalclass     0x00004000ul
#define mk_win_user_class_style_unknown_15      0x00008000ul /* unknown */
#define mk_win_user_class_style_ime             0x00010000ul /* not 16bit */
#define mk_win_user_class_style_dropshadow      0x00020000ul /* 0x0501 */


struct mk_win_user_class_s
{
	mk_win_base_types_uint_t m_style;
	mk_win_base_user_types_wndproc_t m_wndproc;
	int m_cls_extra;
	int m_wnd_extra;
	mk_win_base_types_hinstance_t m_hinstance;
	mk_win_base_user_types_hicon_t m_hicon;
	mk_win_base_user_types_hcursor_t m_hcursor;
	mk_win_base_user_types_hbrush_t m_background;
	mk_win_strc_t m_menu_name;
	mk_win_strc_t m_class_name;
	mk_win_base_user_types_hicon_t m_small_icon;
};
typedef struct mk_win_user_class_s mk_win_user_class_t;


mk_jumbo int mk_win_user_class_init(void);
mk_jumbo int mk_win_user_class_deinit(void);
mk_jumbo int mk_win_user_class_register(mk_win_user_class_t const* cls_info, mk_win_base_types_atom_t* atom);


#endif
