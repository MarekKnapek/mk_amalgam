#ifndef mk_detail_include_guard_lang_jumbo
#define mk_detail_include_guard_lang_jumbo


#include "mk_lang_inline.h"


#if defined(mk_lang_jumbo_want) && mk_lang_jumbo_want == 1
#define mk_lang_jumbo static mk_lang_inline
#elif defined(mk_lang_jumbo_want) && mk_lang_jumbo_want == 0
#define mk_lang_jumbo
#elif defined(NDEBUG)
#define mk_lang_jumbo static mk_lang_inline
#else
#define mk_lang_jumbo
#endif


#endif
