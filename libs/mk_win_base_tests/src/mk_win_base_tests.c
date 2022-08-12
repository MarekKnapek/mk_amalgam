#ifdef NDEBUG
#undef NDEBUG
#endif


#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_platform.h"

#include "../../mk_win/src/mk_win_user_window.h"

#include "../../mk_utils/src/mk_alignof.h"
#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_try.h"

#include <stdlib.h>
#include <limits.h>

#include <windows.h>


static mk_inline int mk_win_base_tests_types(void);
static mk_inline int mk_win_base_tests_user_types(void);


int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	mk_try(mk_win_base_tests_types());
	mk_try(mk_win_base_tests_user_types());

	return EXIT_SUCCESS;
}


static mk_inline int mk_win_base_tests_types(void)
{
	mk_assert(CHAR_BIT == 8);

	mk_assert(sizeof(mk_win_base_types_uint16_t) * CHAR_BIT == 16);
	mk_assert(sizeof(mk_win_base_types_int16_t) * CHAR_BIT == 16);
	mk_assert(sizeof(mk_win_base_types_uint32_t) * CHAR_BIT == 32);
	mk_assert(sizeof(mk_win_base_types_int32_t) * CHAR_BIT == 32);
	#if mk_win_base_platform_os == mk_win_base_platform_os_win64
	mk_assert(sizeof(mk_win_base_types_uint64_t) * CHAR_BIT == 64);
	mk_assert(sizeof(mk_win_base_types_int64_t) * CHAR_BIT == 64);
	#endif

	mk_assert(sizeof(mk_win_base_types_uintptr_t) == sizeof(mk_win_base_types_void_t));
	mk_assert(sizeof(mk_win_base_types_intptr_t) == sizeof(mk_win_base_types_void_t));

	mk_assert(sizeof(mk_win_base_types_bool_t) == sizeof(BOOL));
	mk_assert(sizeof(mk_win_base_types_atom_t) == sizeof(ATOM));
	mk_assert(sizeof(mk_win_base_types_uint_t) == sizeof(UINT));
	mk_assert(sizeof(mk_win_base_types_dword_t) == sizeof(DWORD));

	mk_assert(sizeof(mk_win_base_types_void_t) == sizeof(LPVOID));
	mk_assert(sizeof(mk_win_base_types_stra_t) == sizeof(LPSTR));
	mk_assert(sizeof(mk_win_base_types_strac_t) == sizeof(LPCSTR));
	#if mk_win_base_platform_os != mk_win_base_platform_os_win16
	mk_assert(sizeof(mk_win_base_types_strw_t) == sizeof(LPWSTR));
	mk_assert(sizeof(mk_win_base_types_strwc_t) == sizeof(LPCWSTR));
	#endif

	mk_assert(sizeof(mk_win_base_types_hinstance_t) == sizeof(HINSTANCE));


	mk_assert(mk_alignof(mk_win_base_types_uintptr_t) == mk_alignof(mk_win_base_types_void_t));
	mk_assert(mk_alignof(mk_win_base_types_intptr_t) == mk_alignof(mk_win_base_types_void_t));

	mk_assert(mk_alignof(mk_win_base_types_bool_t) == mk_alignof(BOOL));
	mk_assert(mk_alignof(mk_win_base_types_atom_t) == mk_alignof(ATOM));
	mk_assert(mk_alignof(mk_win_base_types_uint_t) == mk_alignof(UINT));
	mk_assert(mk_alignof(mk_win_base_types_dword_t) == mk_alignof(DWORD));

	mk_assert(mk_alignof(mk_win_base_types_void_t) == mk_alignof(LPVOID));
	mk_assert(mk_alignof(mk_win_base_types_stra_t) == mk_alignof(LPSTR));
	mk_assert(mk_alignof(mk_win_base_types_strac_t) == mk_alignof(LPCSTR));
	#if mk_win_base_platform_os != mk_win_base_platform_os_win16
	mk_assert(mk_alignof(mk_win_base_types_strw_t) == mk_alignof(LPWSTR));
	mk_assert(mk_alignof(mk_win_base_types_strwc_t) == mk_alignof(LPCWSTR));
	#endif

	mk_assert(mk_alignof(mk_win_base_types_hinstance_t) == mk_alignof(HINSTANCE));


	mk_assert(sizeof(((mk_win_base_types_point_t*)NULL)->m_x) == sizeof(((POINT*)NULL)->x));
	mk_assert(sizeof(((mk_win_base_types_point_t*)NULL)->m_y) == sizeof(((POINT*)NULL)->y));
	mk_assert(mk_alignof(((mk_win_base_types_point_t*)NULL)->m_x) == mk_alignof(((POINT*)NULL)->x));
	mk_assert(mk_alignof(((mk_win_base_types_point_t*)NULL)->m_y) == mk_alignof(((POINT*)NULL)->y));
	mk_assert(offsetof(mk_win_base_types_point_t, m_x) == offsetof(POINT, x));
	mk_assert(offsetof(mk_win_base_types_point_t, m_y) == offsetof(POINT, y));
	mk_assert(sizeof(mk_win_base_types_point_t) == sizeof(POINT));
	mk_assert(mk_alignof(mk_win_base_types_point_t) == mk_alignof(POINT));

	mk_assert(sizeof(((mk_win_base_types_rect_t*)NULL)->m_left) == sizeof(((RECT*)NULL)->left));
	mk_assert(sizeof(((mk_win_base_types_rect_t*)NULL)->m_top) == sizeof(((RECT*)NULL)->top));
	mk_assert(sizeof(((mk_win_base_types_rect_t*)NULL)->m_right) == sizeof(((RECT*)NULL)->right));
	mk_assert(sizeof(((mk_win_base_types_rect_t*)NULL)->m_bottom) == sizeof(((RECT*)NULL)->bottom));
	mk_assert(mk_alignof(((mk_win_base_types_rect_t*)NULL)->m_left) == mk_alignof(((RECT*)NULL)->left));
	mk_assert(mk_alignof(((mk_win_base_types_rect_t*)NULL)->m_top) == mk_alignof(((RECT*)NULL)->top));
	mk_assert(mk_alignof(((mk_win_base_types_rect_t*)NULL)->m_right) == mk_alignof(((RECT*)NULL)->right));
	mk_assert(mk_alignof(((mk_win_base_types_rect_t*)NULL)->m_bottom) == mk_alignof(((RECT*)NULL)->bottom));
	mk_assert(offsetof(mk_win_base_types_rect_t, m_left) == offsetof(RECT, left));
	mk_assert(offsetof(mk_win_base_types_rect_t, m_top) == offsetof(RECT, top));
	mk_assert(offsetof(mk_win_base_types_rect_t, m_right) == offsetof(RECT, right));
	mk_assert(offsetof(mk_win_base_types_rect_t, m_bottom) == offsetof(RECT, bottom));
	mk_assert(sizeof(mk_win_base_types_rect_t) == sizeof(RECT));
	mk_assert(mk_alignof(mk_win_base_types_rect_t) == mk_alignof(RECT));

	return 0;
}

static mk_inline int mk_win_base_tests_user_types(void)
{
	mk_assert(sizeof(mk_win_base_user_types_lresult_t) == sizeof(LRESULT));
	mk_assert(sizeof(mk_win_base_user_types_wparam_t) == sizeof(WPARAM));
	mk_assert(sizeof(mk_win_base_user_types_lparam_t) == sizeof(LPARAM));

	mk_assert(sizeof(mk_win_base_user_types_hbrush_t) == sizeof(HBRUSH));
	mk_assert(sizeof(mk_win_base_user_types_hcursor_t) == sizeof(HCURSOR));
	mk_assert(sizeof(mk_win_base_user_types_hicon_t) == sizeof(HICON));
	mk_assert(sizeof(mk_win_base_user_types_hmenu_t) == sizeof(HMENU));
	mk_assert(sizeof(mk_win_base_user_types_hwnd_t) == sizeof(HWND));

	mk_assert(sizeof(mk_win_base_user_types_wndproc_t) == sizeof(WNDPROC));


	mk_assert(mk_alignof(mk_win_base_user_types_lresult_t) == mk_alignof(LRESULT));
	mk_assert(mk_alignof(mk_win_base_user_types_wparam_t) == mk_alignof(WPARAM));
	mk_assert(mk_alignof(mk_win_base_user_types_lparam_t) == mk_alignof(LPARAM));

	mk_assert(mk_alignof(mk_win_base_user_types_hbrush_t) == mk_alignof(HBRUSH));
	mk_assert(mk_alignof(mk_win_base_user_types_hcursor_t) == mk_alignof(HCURSOR));
	mk_assert(mk_alignof(mk_win_base_user_types_hicon_t) == mk_alignof(HICON));
	mk_assert(mk_alignof(mk_win_base_user_types_hmenu_t) == mk_alignof(HMENU));
	mk_assert(mk_alignof(mk_win_base_user_types_hwnd_t) == mk_alignof(HWND));

	mk_assert(mk_alignof(mk_win_base_user_types_wndproc_t) == mk_alignof(WNDPROC));


	#if mk_win_base_platform_os == mk_win_base_platform_os_win16
	#define WNDCLASSA WNDCLASS
	#endif
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_style) == sizeof(((WNDCLASSA*)NULL)->style));
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_wndproc) == sizeof(((WNDCLASSA*)NULL)->lpfnWndProc));
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_cls_extra) == sizeof(((WNDCLASSA*)NULL)->cbClsExtra));
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_wnd_extra) == sizeof(((WNDCLASSA*)NULL)->cbWndExtra));
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_hinstance) == sizeof(((WNDCLASSA*)NULL)->hInstance));
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_hicon) == sizeof(((WNDCLASSA*)NULL)->hIcon));
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_hcursor) == sizeof(((WNDCLASSA*)NULL)->hCursor));
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_background) == sizeof(((WNDCLASSA*)NULL)->hbrBackground));
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_menu_name) == sizeof(((WNDCLASSA*)NULL)->lpszMenuName));
	mk_assert(sizeof(((mk_win_base_user_types_class_a_t*)NULL)->m_class_name) == sizeof(((WNDCLASSA*)NULL)->lpszClassName));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_style) == mk_alignof(((WNDCLASSA*)NULL)->style));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_wndproc) == mk_alignof(((WNDCLASSA*)NULL)->lpfnWndProc));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_cls_extra) == mk_alignof(((WNDCLASSA*)NULL)->cbClsExtra));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_wnd_extra) == mk_alignof(((WNDCLASSA*)NULL)->cbWndExtra));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_hinstance) == mk_alignof(((WNDCLASSA*)NULL)->hInstance));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_hicon) == mk_alignof(((WNDCLASSA*)NULL)->hIcon));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_hcursor) == mk_alignof(((WNDCLASSA*)NULL)->hCursor));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_background) == mk_alignof(((WNDCLASSA*)NULL)->hbrBackground));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_menu_name) == mk_alignof(((WNDCLASSA*)NULL)->lpszMenuName));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_a_t*)NULL)->m_class_name) == mk_alignof(((WNDCLASSA*)NULL)->lpszClassName));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_style) == offsetof(WNDCLASSA, style));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_wndproc) == offsetof(WNDCLASSA, lpfnWndProc));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_cls_extra) == offsetof(WNDCLASSA, cbClsExtra));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_wnd_extra) == offsetof(WNDCLASSA, cbWndExtra));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_hinstance) == offsetof(WNDCLASSA, hInstance));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_hicon) == offsetof(WNDCLASSA, hIcon));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_hcursor) == offsetof(WNDCLASSA, hCursor));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_background) == offsetof(WNDCLASSA, hbrBackground));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_menu_name) == offsetof(WNDCLASSA, lpszMenuName));
	mk_assert(offsetof(mk_win_base_user_types_class_a_t, m_class_name) == offsetof(WNDCLASSA, lpszClassName));
	mk_assert(sizeof(mk_win_base_user_types_class_a_t) == sizeof(WNDCLASSA));
	mk_assert(mk_alignof(mk_win_base_user_types_class_a_t) == mk_alignof(WNDCLASSA));

	#if mk_win_base_platform_os != mk_win_base_platform_os_win16
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_style) == sizeof(((WNDCLASSW*)NULL)->style));
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_wndproc) == sizeof(((WNDCLASSW*)NULL)->lpfnWndProc));
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_cls_extra) == sizeof(((WNDCLASSW*)NULL)->cbClsExtra));
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_wnd_extra) == sizeof(((WNDCLASSW*)NULL)->cbWndExtra));
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_hinstance) == sizeof(((WNDCLASSW*)NULL)->hInstance));
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_hicon) == sizeof(((WNDCLASSW*)NULL)->hIcon));
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_hcursor) == sizeof(((WNDCLASSW*)NULL)->hCursor));
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_background) == sizeof(((WNDCLASSW*)NULL)->hbrBackground));
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_menu_name) == sizeof(((WNDCLASSW*)NULL)->lpszMenuName));
	mk_assert(sizeof(((mk_win_base_user_types_class_w_t*)NULL)->m_class_name) == sizeof(((WNDCLASSW*)NULL)->lpszClassName));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_style) == mk_alignof(((WNDCLASSW*)NULL)->style));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_wndproc) == mk_alignof(((WNDCLASSW*)NULL)->lpfnWndProc));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_cls_extra) == mk_alignof(((WNDCLASSW*)NULL)->cbClsExtra));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_wnd_extra) == mk_alignof(((WNDCLASSW*)NULL)->cbWndExtra));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_hinstance) == mk_alignof(((WNDCLASSW*)NULL)->hInstance));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_hicon) == mk_alignof(((WNDCLASSW*)NULL)->hIcon));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_hcursor) == mk_alignof(((WNDCLASSW*)NULL)->hCursor));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_background) == mk_alignof(((WNDCLASSW*)NULL)->hbrBackground));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_menu_name) == mk_alignof(((WNDCLASSW*)NULL)->lpszMenuName));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_w_t*)NULL)->m_class_name) == mk_alignof(((WNDCLASSW*)NULL)->lpszClassName));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_style) == offsetof(WNDCLASSW, style));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_wndproc) == offsetof(WNDCLASSW, lpfnWndProc));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_cls_extra) == offsetof(WNDCLASSW, cbClsExtra));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_wnd_extra) == offsetof(WNDCLASSW, cbWndExtra));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_hinstance) == offsetof(WNDCLASSW, hInstance));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_hicon) == offsetof(WNDCLASSW, hIcon));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_hcursor) == offsetof(WNDCLASSW, hCursor));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_background) == offsetof(WNDCLASSW, hbrBackground));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_menu_name) == offsetof(WNDCLASSW, lpszMenuName));
	mk_assert(offsetof(mk_win_base_user_types_class_w_t, m_class_name) == offsetof(WNDCLASSW, lpszClassName));
	mk_assert(sizeof(mk_win_base_user_types_class_w_t) == sizeof(WNDCLASSW));
	mk_assert(mk_alignof(mk_win_base_user_types_class_w_t) == mk_alignof(WNDCLASSW));
	#endif

	#if WINVER > 0x030a
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_size) == sizeof(((WNDCLASSEXA*)NULL)->cbSize));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_style) == sizeof(((WNDCLASSEXA*)NULL)->style));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_wndproc) == sizeof(((WNDCLASSEXA*)NULL)->lpfnWndProc));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_cls_extra) == sizeof(((WNDCLASSEXA*)NULL)->cbClsExtra));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_wnd_extra) == sizeof(((WNDCLASSEXA*)NULL)->cbWndExtra));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_hinstance) == sizeof(((WNDCLASSEXA*)NULL)->hInstance));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_hicon) == sizeof(((WNDCLASSEXA*)NULL)->hIcon));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_hcursor) == sizeof(((WNDCLASSEXA*)NULL)->hCursor));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_background) == sizeof(((WNDCLASSEXA*)NULL)->hbrBackground));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_menu_name) == sizeof(((WNDCLASSEXA*)NULL)->lpszMenuName));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_class_name) == sizeof(((WNDCLASSEXA*)NULL)->lpszClassName));
	mk_assert(sizeof(((mk_win_base_user_types_class_exa_t*)NULL)->m_small_icon) == sizeof(((WNDCLASSEXA*)NULL)->hIconSm));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_size) == mk_alignof(((WNDCLASSEXA*)NULL)->cbSize));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_style) == mk_alignof(((WNDCLASSEXA*)NULL)->style));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_wndproc) == mk_alignof(((WNDCLASSEXA*)NULL)->lpfnWndProc));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_cls_extra) == mk_alignof(((WNDCLASSEXA*)NULL)->cbClsExtra));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_wnd_extra) == mk_alignof(((WNDCLASSEXA*)NULL)->cbWndExtra));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_hinstance) == mk_alignof(((WNDCLASSEXA*)NULL)->hInstance));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_hicon) == mk_alignof(((WNDCLASSEXA*)NULL)->hIcon));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_hcursor) == mk_alignof(((WNDCLASSEXA*)NULL)->hCursor));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_background) == mk_alignof(((WNDCLASSEXA*)NULL)->hbrBackground));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_menu_name) == mk_alignof(((WNDCLASSEXA*)NULL)->lpszMenuName));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_class_name) == mk_alignof(((WNDCLASSEXA*)NULL)->lpszClassName));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exa_t*)NULL)->m_small_icon) == mk_alignof(((WNDCLASSEXA*)NULL)->hIconSm));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_size) == offsetof(WNDCLASSEXA, cbSize));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_style) == offsetof(WNDCLASSEXA, style));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_wndproc) == offsetof(WNDCLASSEXA, lpfnWndProc));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_cls_extra) == offsetof(WNDCLASSEXA, cbClsExtra));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_wnd_extra) == offsetof(WNDCLASSEXA, cbWndExtra));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_hinstance) == offsetof(WNDCLASSEXA, hInstance));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_hicon) == offsetof(WNDCLASSEXA, hIcon));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_hcursor) == offsetof(WNDCLASSEXA, hCursor));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_background) == offsetof(WNDCLASSEXA, hbrBackground));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_menu_name) == offsetof(WNDCLASSEXA, lpszMenuName));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_class_name) == offsetof(WNDCLASSEXA, lpszClassName));
	mk_assert(offsetof(mk_win_base_user_types_class_exa_t, m_small_icon) == offsetof(WNDCLASSEXA, hIconSm));
	mk_assert(sizeof(mk_win_base_user_types_class_exa_t) == sizeof(WNDCLASSEXA));
	mk_assert(mk_alignof(mk_win_base_user_types_class_exa_t) == mk_alignof(WNDCLASSEXA));
	#endif

	#if WINVER > 0x030a
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_size) == sizeof(((WNDCLASSEXW*)NULL)->cbSize));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_style) == sizeof(((WNDCLASSEXW*)NULL)->style));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_wndproc) == sizeof(((WNDCLASSEXW*)NULL)->lpfnWndProc));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_cls_extra) == sizeof(((WNDCLASSEXW*)NULL)->cbClsExtra));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_wnd_extra) == sizeof(((WNDCLASSEXW*)NULL)->cbWndExtra));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_hinstance) == sizeof(((WNDCLASSEXW*)NULL)->hInstance));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_hicon) == sizeof(((WNDCLASSEXW*)NULL)->hIcon));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_hcursor) == sizeof(((WNDCLASSEXW*)NULL)->hCursor));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_background) == sizeof(((WNDCLASSEXW*)NULL)->hbrBackground));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_menu_name) == sizeof(((WNDCLASSEXW*)NULL)->lpszMenuName));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_class_name) == sizeof(((WNDCLASSEXW*)NULL)->lpszClassName));
	mk_assert(sizeof(((mk_win_base_user_types_class_exw_t*)NULL)->m_small_icon) == sizeof(((WNDCLASSEXW*)NULL)->hIconSm));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_size) == mk_alignof(((WNDCLASSEXW*)NULL)->cbSize));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_style) == mk_alignof(((WNDCLASSEXW*)NULL)->style));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_wndproc) == mk_alignof(((WNDCLASSEXW*)NULL)->lpfnWndProc));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_cls_extra) == mk_alignof(((WNDCLASSEXW*)NULL)->cbClsExtra));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_wnd_extra) == mk_alignof(((WNDCLASSEXW*)NULL)->cbWndExtra));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_hinstance) == mk_alignof(((WNDCLASSEXW*)NULL)->hInstance));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_hicon) == mk_alignof(((WNDCLASSEXW*)NULL)->hIcon));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_hcursor) == mk_alignof(((WNDCLASSEXW*)NULL)->hCursor));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_background) == mk_alignof(((WNDCLASSEXW*)NULL)->hbrBackground));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_menu_name) == mk_alignof(((WNDCLASSEXW*)NULL)->lpszMenuName));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_class_name) == mk_alignof(((WNDCLASSEXW*)NULL)->lpszClassName));
	mk_assert(mk_alignof(((mk_win_base_user_types_class_exw_t*)NULL)->m_small_icon) == mk_alignof(((WNDCLASSEXW*)NULL)->hIconSm));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_size) == offsetof(WNDCLASSEXW, cbSize));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_style) == offsetof(WNDCLASSEXW, style));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_wndproc) == offsetof(WNDCLASSEXW, lpfnWndProc));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_cls_extra) == offsetof(WNDCLASSEXW, cbClsExtra));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_wnd_extra) == offsetof(WNDCLASSEXW, cbWndExtra));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_hinstance) == offsetof(WNDCLASSEXW, hInstance));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_hicon) == offsetof(WNDCLASSEXW, hIcon));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_hcursor) == offsetof(WNDCLASSEXW, hCursor));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_background) == offsetof(WNDCLASSEXW, hbrBackground));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_menu_name) == offsetof(WNDCLASSEXW, lpszMenuName));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_class_name) == offsetof(WNDCLASSEXW, lpszClassName));
	mk_assert(offsetof(mk_win_base_user_types_class_exw_t, m_small_icon) == offsetof(WNDCLASSEXW, hIconSm));
	mk_assert(sizeof(mk_win_base_user_types_class_exw_t) == sizeof(WNDCLASSEXW));
	mk_assert(mk_alignof(mk_win_base_user_types_class_exw_t) == mk_alignof(WNDCLASSEXW));
	#endif

	mk_assert(sizeof(((mk_win_base_user_types_msg_t*)NULL)->m_hwnd) == sizeof(((MSG*)NULL)->hwnd));
	mk_assert(sizeof(((mk_win_base_user_types_msg_t*)NULL)->m_msg) == sizeof(((MSG*)NULL)->message));
	mk_assert(sizeof(((mk_win_base_user_types_msg_t*)NULL)->m_wparam) == sizeof(((MSG*)NULL)->wParam));
	mk_assert(sizeof(((mk_win_base_user_types_msg_t*)NULL)->m_lparam) == sizeof(((MSG*)NULL)->lParam));
	mk_assert(sizeof(((mk_win_base_user_types_msg_t*)NULL)->m_time) == sizeof(((MSG*)NULL)->time));
	mk_assert(sizeof(((mk_win_base_user_types_msg_t*)NULL)->m_point) == sizeof(((MSG*)NULL)->pt));
	mk_assert(mk_alignof(((mk_win_base_user_types_msg_t*)NULL)->m_hwnd) == mk_alignof(((MSG*)NULL)->hwnd));
	mk_assert(mk_alignof(((mk_win_base_user_types_msg_t*)NULL)->m_msg) == mk_alignof(((MSG*)NULL)->message));
	mk_assert(mk_alignof(((mk_win_base_user_types_msg_t*)NULL)->m_wparam) == mk_alignof(((MSG*)NULL)->wParam));
	mk_assert(mk_alignof(((mk_win_base_user_types_msg_t*)NULL)->m_lparam) == mk_alignof(((MSG*)NULL)->lParam));
	mk_assert(mk_alignof(((mk_win_base_user_types_msg_t*)NULL)->m_time) == mk_alignof(((MSG*)NULL)->time));
	mk_assert(mk_alignof(((mk_win_base_user_types_msg_t*)NULL)->m_point) == mk_alignof(((MSG*)NULL)->pt));
	mk_assert(offsetof(mk_win_base_user_types_msg_t, m_hwnd) == offsetof(MSG, hwnd));
	mk_assert(offsetof(mk_win_base_user_types_msg_t, m_msg) == offsetof(MSG, message));
	mk_assert(offsetof(mk_win_base_user_types_msg_t, m_wparam) == offsetof(MSG, wParam));
	mk_assert(offsetof(mk_win_base_user_types_msg_t, m_lparam) == offsetof(MSG, lParam));
	mk_assert(offsetof(mk_win_base_user_types_msg_t, m_time) == offsetof(MSG, time));
	mk_assert(offsetof(mk_win_base_user_types_msg_t, m_point) == offsetof(MSG, pt));
	mk_assert(sizeof(mk_win_base_user_types_msg_t) == sizeof(MSG));
	mk_assert(mk_alignof(mk_win_base_user_types_msg_t) == mk_alignof(MSG));

	#if mk_win_base_platform_os == mk_win_base_platform_os_win16
	#define CREATESTRUCTA CREATESTRUCT
	#endif
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_param) == sizeof(((CREATESTRUCTA*)NULL)->lpCreateParams));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_instance) == sizeof(((CREATESTRUCTA*)NULL)->hInstance));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_menu) == sizeof(((CREATESTRUCTA*)NULL)->hMenu));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_parent) == sizeof(((CREATESTRUCTA*)NULL)->hwndParent));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_height) == sizeof(((CREATESTRUCTA*)NULL)->cy));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_width) == sizeof(((CREATESTRUCTA*)NULL)->cx));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_y) == sizeof(((CREATESTRUCTA*)NULL)->y));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_x) == sizeof(((CREATESTRUCTA*)NULL)->x));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_style) == sizeof(((CREATESTRUCTA*)NULL)->style));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_name) == sizeof(((CREATESTRUCTA*)NULL)->lpszName));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_class) == sizeof(((CREATESTRUCTA*)NULL)->lpszClass));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_extra_style) == sizeof(((CREATESTRUCTA*)NULL)->dwExStyle));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_param) == mk_alignof(((CREATESTRUCTA*)NULL)->lpCreateParams));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_instance) == mk_alignof(((CREATESTRUCTA*)NULL)->hInstance));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_menu) == mk_alignof(((CREATESTRUCTA*)NULL)->hMenu));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_parent) == mk_alignof(((CREATESTRUCTA*)NULL)->hwndParent));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_height) == mk_alignof(((CREATESTRUCTA*)NULL)->cy));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_width) == mk_alignof(((CREATESTRUCTA*)NULL)->cx));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_y) == mk_alignof(((CREATESTRUCTA*)NULL)->y));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_x) == mk_alignof(((CREATESTRUCTA*)NULL)->x));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_style) == mk_alignof(((CREATESTRUCTA*)NULL)->style));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_name) == mk_alignof(((CREATESTRUCTA*)NULL)->lpszName));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_class) == mk_alignof(((CREATESTRUCTA*)NULL)->lpszClass));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_a_t*)NULL)->m_extra_style) == mk_alignof(((CREATESTRUCTA*)NULL)->dwExStyle));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_param) == offsetof(CREATESTRUCTA, lpCreateParams));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_instance) == offsetof(CREATESTRUCTA, hInstance));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_menu) == offsetof(CREATESTRUCTA, hMenu));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_parent) == offsetof(CREATESTRUCTA, hwndParent));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_height) == offsetof(CREATESTRUCTA, cy));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_width) == offsetof(CREATESTRUCTA, cx));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_y) == offsetof(CREATESTRUCTA, y));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_x) == offsetof(CREATESTRUCTA, x));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_style) == offsetof(CREATESTRUCTA, style));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_name) == offsetof(CREATESTRUCTA, lpszName));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_class) == offsetof(CREATESTRUCTA, lpszClass));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_a_t, m_extra_style) == offsetof(CREATESTRUCTA, dwExStyle));
	mk_assert(sizeof(mk_win_base_user_types_wm_create_a_t) == sizeof(CREATESTRUCTA));
	mk_assert(mk_alignof(mk_win_base_user_types_wm_create_a_t) == mk_alignof(CREATESTRUCTA));

	#if mk_win_base_platform_os != mk_win_base_platform_os_win16
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_param) == sizeof(((CREATESTRUCTW*)NULL)->lpCreateParams));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_instance) == sizeof(((CREATESTRUCTW*)NULL)->hInstance));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_menu) == sizeof(((CREATESTRUCTW*)NULL)->hMenu));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_parent) == sizeof(((CREATESTRUCTW*)NULL)->hwndParent));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_height) == sizeof(((CREATESTRUCTW*)NULL)->cy));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_width) == sizeof(((CREATESTRUCTW*)NULL)->cx));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_y) == sizeof(((CREATESTRUCTW*)NULL)->y));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_x) == sizeof(((CREATESTRUCTW*)NULL)->x));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_style) == sizeof(((CREATESTRUCTW*)NULL)->style));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_name) == sizeof(((CREATESTRUCTW*)NULL)->lpszName));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_class) == sizeof(((CREATESTRUCTW*)NULL)->lpszClass));
	mk_assert(sizeof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_extra_style) == sizeof(((CREATESTRUCTW*)NULL)->dwExStyle));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_param) == mk_alignof(((CREATESTRUCTW*)NULL)->lpCreateParams));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_instance) == mk_alignof(((CREATESTRUCTW*)NULL)->hInstance));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_menu) == mk_alignof(((CREATESTRUCTW*)NULL)->hMenu));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_parent) == mk_alignof(((CREATESTRUCTW*)NULL)->hwndParent));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_height) == mk_alignof(((CREATESTRUCTW*)NULL)->cy));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_width) == mk_alignof(((CREATESTRUCTW*)NULL)->cx));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_y) == mk_alignof(((CREATESTRUCTW*)NULL)->y));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_x) == mk_alignof(((CREATESTRUCTW*)NULL)->x));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_style) == mk_alignof(((CREATESTRUCTW*)NULL)->style));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_name) == mk_alignof(((CREATESTRUCTW*)NULL)->lpszName));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_class) == mk_alignof(((CREATESTRUCTW*)NULL)->lpszClass));
	mk_assert(mk_alignof(((mk_win_base_user_types_wm_create_w_t*)NULL)->m_extra_style) == mk_alignof(((CREATESTRUCTW*)NULL)->dwExStyle));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_param) == offsetof(CREATESTRUCTW, lpCreateParams));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_instance) == offsetof(CREATESTRUCTW, hInstance));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_menu) == offsetof(CREATESTRUCTW, hMenu));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_parent) == offsetof(CREATESTRUCTW, hwndParent));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_height) == offsetof(CREATESTRUCTW, cy));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_width) == offsetof(CREATESTRUCTW, cx));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_y) == offsetof(CREATESTRUCTW, y));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_x) == offsetof(CREATESTRUCTW, x));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_style) == offsetof(CREATESTRUCTW, style));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_name) == offsetof(CREATESTRUCTW, lpszName));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_class) == offsetof(CREATESTRUCTW, lpszClass));
	mk_assert(offsetof(mk_win_base_user_types_wm_create_w_t, m_extra_style) == offsetof(CREATESTRUCTW, dwExStyle));
	mk_assert(sizeof(mk_win_base_user_types_wm_create_w_t) == sizeof(CREATESTRUCTW));
	mk_assert(mk_alignof(mk_win_base_user_types_wm_create_w_t) == mk_alignof(CREATESTRUCTW));
	#endif

	mk_assert(sizeof(((mk_win_base_user_client_create_t*)NULL)->m_menu) == sizeof(((CLIENTCREATESTRUCT*)NULL)->hWindowMenu));
	mk_assert(sizeof(((mk_win_base_user_client_create_t*)NULL)->m_first_child_id) == sizeof(((CLIENTCREATESTRUCT*)NULL)->idFirstChild));
	mk_assert(mk_alignof(((mk_win_base_user_client_create_t*)NULL)->m_menu) == mk_alignof(((CLIENTCREATESTRUCT*)NULL)->hWindowMenu));
	mk_assert(mk_alignof(((mk_win_base_user_client_create_t*)NULL)->m_first_child_id) == mk_alignof(((CLIENTCREATESTRUCT*)NULL)->idFirstChild));
	mk_assert(offsetof(mk_win_base_user_client_create_t, m_menu) == offsetof(CLIENTCREATESTRUCT, hWindowMenu));
	mk_assert(offsetof(mk_win_base_user_client_create_t, m_first_child_id) == offsetof(CLIENTCREATESTRUCT, idFirstChild));
	mk_assert(sizeof(mk_win_base_user_client_create_t) == sizeof(CLIENTCREATESTRUCT));
	mk_assert(mk_alignof(mk_win_base_user_client_create_t) == mk_alignof(CLIENTCREATESTRUCT));

	#if mk_win_base_platform_os == mk_win_base_platform_os_win16
	#define MDICREATESTRUCTA MDICREATESTRUCT
	#endif
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_class_name) == sizeof(((MDICREATESTRUCTA*)NULL)->szClass));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_window_name) == sizeof(((MDICREATESTRUCTA*)NULL)->szTitle));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_instance) == sizeof(((MDICREATESTRUCTA*)NULL)->hOwner));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_x) == sizeof(((MDICREATESTRUCTA*)NULL)->x));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_y) == sizeof(((MDICREATESTRUCTA*)NULL)->y));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_width) == sizeof(((MDICREATESTRUCTA*)NULL)->cx));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_height) == sizeof(((MDICREATESTRUCTA*)NULL)->cy));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_style) == sizeof(((MDICREATESTRUCTA*)NULL)->style));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_param) == sizeof(((MDICREATESTRUCTA*)NULL)->lParam));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_class_name) == mk_alignof(((MDICREATESTRUCTA*)NULL)->szClass));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_window_name) == mk_alignof(((MDICREATESTRUCTA*)NULL)->szTitle));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_instance) == mk_alignof(((MDICREATESTRUCTA*)NULL)->hOwner));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_x) == mk_alignof(((MDICREATESTRUCTA*)NULL)->x));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_y) == mk_alignof(((MDICREATESTRUCTA*)NULL)->y));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_width) == mk_alignof(((MDICREATESTRUCTA*)NULL)->cx));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_height) == mk_alignof(((MDICREATESTRUCTA*)NULL)->cy));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_style) == mk_alignof(((MDICREATESTRUCTA*)NULL)->style));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_a_t*)NULL)->m_param) == mk_alignof(((MDICREATESTRUCTA*)NULL)->lParam));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_a_t, m_class_name) == offsetof(MDICREATESTRUCTA, szClass));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_a_t, m_window_name) == offsetof(MDICREATESTRUCTA, szTitle));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_a_t, m_instance) == offsetof(MDICREATESTRUCTA, hOwner));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_a_t, m_x) == offsetof(MDICREATESTRUCTA, x));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_a_t, m_y) == offsetof(MDICREATESTRUCTA, y));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_a_t, m_width) == offsetof(MDICREATESTRUCTA, cx));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_a_t, m_height) == offsetof(MDICREATESTRUCTA, cy));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_a_t, m_style) == offsetof(MDICREATESTRUCTA, style));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_a_t, m_param) == offsetof(MDICREATESTRUCTA, lParam));
	mk_assert(sizeof(mk_win_base_user_wm_mdicreate_a_t) == sizeof(MDICREATESTRUCTA));
	mk_assert(mk_alignof(mk_win_base_user_wm_mdicreate_a_t) == mk_alignof(MDICREATESTRUCTA));

	#if mk_win_base_platform_os != mk_win_base_platform_os_win16
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_class_name) == sizeof(((MDICREATESTRUCTW*)NULL)->szClass));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_window_name) == sizeof(((MDICREATESTRUCTW*)NULL)->szTitle));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_instance) == sizeof(((MDICREATESTRUCTW*)NULL)->hOwner));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_x) == sizeof(((MDICREATESTRUCTW*)NULL)->x));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_y) == sizeof(((MDICREATESTRUCTW*)NULL)->y));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_width) == sizeof(((MDICREATESTRUCTW*)NULL)->cx));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_height) == sizeof(((MDICREATESTRUCTW*)NULL)->cy));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_style) == sizeof(((MDICREATESTRUCTW*)NULL)->style));
	mk_assert(sizeof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_param) == sizeof(((MDICREATESTRUCTW*)NULL)->lParam));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_class_name) == mk_alignof(((MDICREATESTRUCTW*)NULL)->szClass));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_window_name) == mk_alignof(((MDICREATESTRUCTW*)NULL)->szTitle));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_instance) == mk_alignof(((MDICREATESTRUCTW*)NULL)->hOwner));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_x) == mk_alignof(((MDICREATESTRUCTW*)NULL)->x));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_y) == mk_alignof(((MDICREATESTRUCTW*)NULL)->y));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_width) == mk_alignof(((MDICREATESTRUCTW*)NULL)->cx));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_height) == mk_alignof(((MDICREATESTRUCTW*)NULL)->cy));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_style) == mk_alignof(((MDICREATESTRUCTW*)NULL)->style));
	mk_assert(mk_alignof(((mk_win_base_user_wm_mdicreate_w_t*)NULL)->m_param) == mk_alignof(((MDICREATESTRUCTW*)NULL)->lParam));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_w_t, m_class_name) == offsetof(MDICREATESTRUCTW, szClass));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_w_t, m_window_name) == offsetof(MDICREATESTRUCTW, szTitle));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_w_t, m_instance) == offsetof(MDICREATESTRUCTW, hOwner));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_w_t, m_x) == offsetof(MDICREATESTRUCTW, x));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_w_t, m_y) == offsetof(MDICREATESTRUCTW, y));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_w_t, m_width) == offsetof(MDICREATESTRUCTW, cx));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_w_t, m_height) == offsetof(MDICREATESTRUCTW, cy));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_w_t, m_style) == offsetof(MDICREATESTRUCTW, style));
	mk_assert(offsetof(mk_win_base_user_wm_mdicreate_w_t, m_param) == offsetof(MDICREATESTRUCTW, lParam));
	mk_assert(sizeof(mk_win_base_user_wm_mdicreate_w_t) == sizeof(MDICREATESTRUCTW));
	mk_assert(mk_alignof(mk_win_base_user_wm_mdicreate_w_t) == mk_alignof(MDICREATESTRUCTW));
	#endif

	return 0;
}
