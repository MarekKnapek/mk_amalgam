#ifndef mk_detail_include_guard_lang_llong
#define mk_detail_include_guard_lang_llong


#if defined(__cplusplus) && __cplusplus >= 201103l
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901l
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#elif defined(__WATCOMC__) && __WATCOMC__ >= 1100
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned __int64
#define mk_lang_sllong_t signed __int64
#else
#define mk_lang_llong_has 0
#define mk_lang_ullong_t unsigned long int
#define mk_lang_sllong_t signed long int
#endif


#endif
