#ifndef mk_include_guard_win_base_types
#define mk_include_guard_win_base_types


#include "mk_win_base_platform.h"
#include "mk_win_base_keywords.h"

#include <stddef.h>


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
typedef mk_win_base_types_bool_t* mk_win_base_types_bool_pt;
typedef mk_win_base_types_bool_t mk_win_base_keywords_far* mk_win_base_types_bool_lpt;
typedef unsigned short int mk_win_base_types_atom_t;
typedef unsigned int mk_win_base_types_uint_t;
typedef mk_win_base_types_uint32_t mk_win_base_types_dword_t;
typedef mk_win_base_types_uint16_t mk_win_base_types_word_t;

typedef void mk_win_base_keywords_far* mk_win_base_types_void_t;
typedef char mk_win_base_keywords_far* mk_win_base_types_stra_t;
typedef char const mk_win_base_keywords_far* mk_win_base_types_strac_t;
typedef wchar_t mk_win_base_keywords_far* mk_win_base_types_strw_t;
typedef wchar_t const mk_win_base_keywords_far* mk_win_base_types_strwc_t;

struct mk_win_base_types_hinstance_s; typedef struct mk_win_base_types_hinstance_s const mk_win_base_keywords_near* mk_win_base_types_hinstance_t;


struct mk_win_base_types_point_s
{
	int m_x;
	int m_y;
};
typedef struct mk_win_base_types_point_s mk_win_base_types_point_t;
typedef mk_win_base_types_point_t* mk_win_base_types_point_pt;
typedef mk_win_base_types_point_t const* mk_win_base_types_point_pct;
typedef mk_win_base_types_point_t mk_win_base_keywords_far* mk_win_base_types_point_lpt;
typedef mk_win_base_types_point_t const mk_win_base_keywords_far* mk_win_base_types_point_lpct;

struct mk_win_base_types_rect_s
{
	int m_left;
	int m_top;
	int m_right;
	int m_bottom;
};
typedef struct mk_win_base_types_rect_s mk_win_base_types_rect_t;
typedef mk_win_base_types_rect_t* mk_win_base_types_rect_pt;
typedef mk_win_base_types_rect_t const* mk_win_base_types_rect_pct;
typedef mk_win_base_types_rect_t mk_win_base_keywords_far* mk_win_base_types_rect_lpt;
typedef mk_win_base_types_rect_t const mk_win_base_keywords_far* mk_win_base_types_rect_lpct;


#endif
