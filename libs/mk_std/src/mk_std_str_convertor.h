#ifndef mk_include_guard_str_convertor
#define mk_include_guard_str_convertor


#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"

#include <stddef.h>


mk_jumbo int mk_std_str_convertor_init(void);
mk_jumbo int mk_std_str_convertor_deinit(void);

mk_jumbo int mk_std_str_convertor_is_ascii_z(wchar_t const* str, int* is_ascii);
mk_jumbo int mk_std_str_convertor_is_ascii_s(wchar_t const* str, size_t len, int* is_ascii);

mk_jumbo int mk_std_str_convertor_narrow_to_narrow_z(char const mk_win_base_keywords_far* in, int idx, char const**  out);
mk_jumbo int mk_std_str_convertor_wide_to_narrow_z(wchar_t const* in, int idx, char const**  out);
mk_jumbo int mk_std_str_convertor_narrow_to_wide_z(char const* in, int idx, wchar_t const**  out);

mk_jumbo int mk_std_str_convertor_narrow_to_narrow_zz(char const mk_win_base_keywords_far* in, int idx, char const**  out);
mk_jumbo int mk_std_str_convertor_wide_to_narrow_zz(wchar_t const* in, int idx, char const**  out);
mk_jumbo int mk_std_str_convertor_narrow_to_wide_zz(char const* in, int idx, wchar_t const**  out);

mk_jumbo int mk_std_str_convertor_narrow_to_narrow_s(char const mk_win_base_keywords_far* in, size_t len, int idx, char const**  out);
mk_jumbo int mk_std_str_convertor_wide_to_narrow_s(wchar_t const* in, size_t len, int idx, char const**  out);
mk_jumbo int mk_std_str_convertor_narrow_to_wide_s(char const* in, size_t len, int idx, wchar_t const**  out);


#endif
