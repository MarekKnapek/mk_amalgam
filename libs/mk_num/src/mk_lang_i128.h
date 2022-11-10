#ifndef mk_detail_include_guard_lang_i128
#define mk_detail_include_guard_lang_i128


#if defined(__SIZEOF_INT128__) && __SIZEOF_INT128__ != 0
#define mk_lang_i128_has 1
#define mk_lang_ui128_t unsigned __int128
#define mk_lang_si128_t signed __int128
#else
#define mk_lang_i128_has 0
#endif


#endif
