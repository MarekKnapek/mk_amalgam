#ifndef mk_detail_include_guard_lang_llong
#define mk_detail_include_guard_lang_llong


#if defined(__cplusplus) && __cplusplus >= 201103l
#define mk_lang_llong_has 1
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901l
#define mk_lang_llong_has 1
#else
#define mk_lang_llong_has 0
#endif

#if mk_lang_llong_has == 0
#define mk_lang_ullong_t unsigned long int
#define mk_lang_sllong_t signed long int
#else
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#endif


#endif
