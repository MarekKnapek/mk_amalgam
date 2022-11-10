#ifndef mk_detail_include_guard_lang_charbit
#define mk_detail_include_guard_lang_charbit


#if (defined __cplusplus)
#include <climits> /* CHAR_BIT */
#else
#include <limits.h> /* CHAR_BIT */
#endif


#define mk_lang_charbit CHAR_BIT


#endif
