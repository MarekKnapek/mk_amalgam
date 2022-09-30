#ifndef mk_include_guard_win_base_types
#define mk_include_guard_win_base_types


#include "mk_win_base_platform.h"
#include "mk_win_base_keywords.h"

#include "../../mk_utils/src/mk_concat.h"

#include <stddef.h>


#define mk_win_base_types_make_pointers(x) \
	typedef mk_concat(x, _t)* mk_concat(x, _pt); \
	typedef const mk_concat(x, _t)* mk_concat(x, _pct); \
	typedef mk_concat(x, _t) mk_win_base_keywords_far* mk_concat(x, _lpt); \
	typedef const mk_concat(x, _t) mk_win_base_keywords_far* mk_concat(x, _lpct)
#define mk_win_base_types_make_struct(x) \
	typedef struct mk_concat(x, _s) mk_concat(x, _t); \
	mk_win_base_types_make_pointers(x)
#if mk_win_base_platform_os == mk_win_base_platform_os_win16
#define mk_win_base_types_make_handle(x) typedef unsigned int x
#else
#define mk_win_base_types_make_handle(x) struct mk_concat(x, _private_s); typedef struct mk_concat(x, _private_s) const* x
#endif


typedef unsigned short int mk_win_base_types_uint16_t;
typedef signed short int mk_win_base_types_int16_t;
typedef unsigned long int mk_win_base_types_uint32_t;
typedef signed long int mk_win_base_types_int32_t;
#if mk_win_base_platform_os == mk_win_base_platform_os_win64
typedef unsigned __int64 mk_win_base_types_uint64_t;
typedef signed __int64 mk_win_base_types_int64_t;
#endif

#if mk_win_base_platform_os == mk_win_base_platform_os_win16
typedef mk_win_base_types_uint16_t mk_win_base_types_cpu_word_t;
typedef mk_win_base_types_int16_t mk_win_base_types_cpu_iword_t;
typedef mk_win_base_types_uint32_t mk_win_base_types_uintptr_t;
typedef mk_win_base_types_int32_t mk_win_base_types_intptr_t;
#elif mk_win_base_platform_os == mk_win_base_platform_os_win32
typedef mk_win_base_types_uint32_t mk_win_base_types_cpu_word_t;
typedef mk_win_base_types_int32_t mk_win_base_types_cpu_iword_t;
typedef mk_win_base_types_uint32_t mk_win_base_types_uintptr_t;
typedef mk_win_base_types_int32_t mk_win_base_types_intptr_t;
#elif mk_win_base_platform_os == mk_win_base_platform_os_win64
typedef mk_win_base_types_uint64_t mk_win_base_types_cpu_word_t;
typedef mk_win_base_types_int64_t mk_win_base_types_cpu_iword_t;
typedef mk_win_base_types_uint64_t mk_win_base_types_uintptr_t;
typedef mk_win_base_types_int64_t mk_win_base_types_intptr_t;
#endif

typedef int mk_win_base_types_bool_t;
typedef unsigned short int mk_win_base_types_atom_t;
typedef unsigned int mk_win_base_types_uint_t;
typedef mk_win_base_types_uint16_t mk_win_base_types_word_t;
typedef mk_win_base_types_uint32_t mk_win_base_types_dword_t;

typedef void mk_win_base_types_void_t;
typedef char mk_win_base_types_char_t;
typedef wchar_t mk_win_base_types_wchar_t;

mk_win_base_types_make_pointers(mk_win_base_types_bool);
mk_win_base_types_make_pointers(mk_win_base_types_atom);
mk_win_base_types_make_pointers(mk_win_base_types_uint);
mk_win_base_types_make_pointers(mk_win_base_types_word);
mk_win_base_types_make_pointers(mk_win_base_types_dword);
mk_win_base_types_make_pointers(mk_win_base_types_void);
mk_win_base_types_make_pointers(mk_win_base_types_char);
mk_win_base_types_make_pointers(mk_win_base_types_wchar);

mk_win_base_types_make_handle(mk_win_base_types_handle_t);
mk_win_base_types_make_handle(mk_win_base_types_hinstance_t);


#if mk_win_base_platform_os == mk_win_base_platform_os_win16
#define mk_win_base_types_null 0
#else
#define mk_win_base_types_null ((void*)0)
#endif


struct mk_win_base_types_point_s
{
	int m_x;
	int m_y;
};
mk_win_base_types_make_struct(mk_win_base_types_point);

struct mk_win_base_types_rect_s
{
	int m_left;
	int m_top;
	int m_right;
	int m_bottom;
};
mk_win_base_types_make_struct(mk_win_base_types_rect);


#endif
