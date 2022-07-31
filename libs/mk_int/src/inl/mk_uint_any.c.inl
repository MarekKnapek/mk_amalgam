#define mk_uint_str_suffix n
#define mk_char_t char
#define mk_char_c(x) x
#define mk_str_c(x) x
#include "mk_uint_any_str.c.inl"
#undef mk_uint_str_suffix
#undef mk_char_t
#undef mk_char_c
#undef mk_str_c


#define mk_uint_str_suffix w
#define mk_char_t wchar_t
#define mk_char_c(x) L ## x
#define mk_str_c(x) L ## x
#include "mk_uint_any_str.c.inl"
#undef mk_uint_str_suffix
#undef mk_char_t
#undef mk_char_c
#undef mk_str_c
