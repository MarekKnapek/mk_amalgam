#ifndef mk_detail_include_guard_lang_concat
#define mk_detail_include_guard_lang_concat


#define mk_detail_lang_concat_impl(a, b) a ## b
#define mk_lang_concat(a, b) mk_detail_lang_concat_impl(a, b)


#endif
