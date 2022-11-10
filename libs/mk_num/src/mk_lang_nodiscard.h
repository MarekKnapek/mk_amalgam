#ifndef mk_detail_include_guard_lang_nodiscard
#define mk_detail_include_guard_lang_nodiscard


#if defined(__cplusplus) && __cplusplus >= 201703l
#define mk_lang_nodiscard [[nodiscard]]
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202299l/*TODO c23*/
#define mk_lang_nodiscard [[nodiscard]]
#else
#define mk_lang_nodiscard
#endif


#endif
