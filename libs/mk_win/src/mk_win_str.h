#ifndef mk_include_guard_win_str
#define mk_include_guard_win_str


#include "mk_win_api.h"
#include "mk_win_char.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


mk_jumbo int mk_win_str_get_len(mk_win_strc_t str, size_t* len);

mk_jumbo int mk_win_str_to_wide_z(mk_win_strc_t in, int idx, wchar_t const** out);
mk_jumbo int mk_win_str_to_narrow_z(mk_win_strc_t in, int idx, char const mk_win_base_keywords_far** out);
mk_jumbo int mk_win_str_from_wide_z(wchar_t const* in, int idx, mk_win_strc_t* out);
mk_jumbo int mk_win_str_from_narrow_z(char const mk_win_base_keywords_far* in, int idx, mk_win_strc_t* out);

mk_jumbo int mk_win_str_to_wide_zz(mk_win_strc_t in, int idx, wchar_t const** out);
mk_jumbo int mk_win_str_to_narrow_zz(mk_win_strc_t in, int idx, char const mk_win_base_keywords_far** out);
mk_jumbo int mk_win_str_from_wide_zz(wchar_t const* in, int idx, mk_win_strc_t* out);
mk_jumbo int mk_win_str_from_narrow_zz(char const mk_win_base_keywords_far* in, int idx, mk_win_strc_t* out);

mk_jumbo int mk_win_str_to_wide_s(mk_win_strc_t in, size_t length, int idx, wchar_t const** out);
mk_jumbo int mk_win_str_to_narrow_s(mk_win_strc_t in, size_t length, int idx, char const mk_win_base_keywords_far** out);
mk_jumbo int mk_win_str_from_wide_s(wchar_t const* in, size_t length, int idx, mk_win_strc_t* out);
mk_jumbo int mk_win_str_from_narrow_s(char const mk_win_base_keywords_far* in, size_t length, int idx, mk_win_strc_t* out);


#if mk_win_api == mk_win_api_old || mk_win_api == mk_win_api_ansi
typedef char mk_win_api_char_t;
#define mk_win_str_to_api_z mk_win_str_to_narrow_z
#define mk_win_str_from_api_z mk_win_str_from_narrow_z
#define mk_win_str_to_api_zz mk_win_str_to_narrow_zz
#define mk_win_str_from_api_zz mk_win_str_from_narrow_zz
#define mk_win_str_to_api_s mk_win_str_to_narrow_s
#define mk_win_str_from_api_s mk_win_str_from_narrow_s
#elif mk_win_api == mk_win_api_wide
typedef wchar_t mk_win_api_char_t;
#define mk_win_str_to_api_z mk_win_str_to_wide_z
#define mk_win_str_from_api_z mk_win_str_from_wide_z
#define mk_win_str_to_api_zz mk_win_str_to_wide_zz
#define mk_win_str_from_api_zz mk_win_str_from_wide_zz
#define mk_win_str_to_api_s mk_win_str_to_wide_s
#define mk_win_str_from_api_s mk_win_str_from_wide_s
#endif


#endif
