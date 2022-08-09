#ifndef mk_include_guard_win_char
#define mk_include_guard_win_char


#include "mk_win_api.h"

#include <stddef.h>


#define mk_win_char_narrow 1000
#define mk_win_char_wide 1001
#ifndef mk_win_char
#if mk_win_api == mk_win_api_old
#define mk_win_char mk_win_char_narrow
#elif mk_win_api == mk_win_api_ansi
#define mk_win_char mk_win_char_narrow
#elif mk_win_api == mk_win_api_wide
#define mk_win_char mk_win_char_wide
#elif mk_win_api == mk_win_api_both
#define mk_win_char mk_win_char_wide
#endif
#endif


#if mk_win_char == mk_win_char_narrow
typedef char mk_win_char_t;
typedef char* mk_win_str_t;
typedef char const* mk_win_strc_t;
#define mk_win_char_c(x) x
#elif mk_win_char == mk_win_char_wide
typedef wchar_t mk_win_char_t;
typedef wchar_t* mk_win_str_t;
typedef wchar_t const* mk_win_strc_t;
#define mk_win_char_c(x) L ## x
#endif


#endif
