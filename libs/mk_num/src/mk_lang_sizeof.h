#ifndef mk_detail_include_guard_lang_sizeof
#define mk_detail_include_guard_lang_sizeof


#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"


#define mk_lang_sizeof_uchar 1
#define mk_lang_sizeof_ushort 2
#define mk_lang_sizeof_uint 4
#define mk_lang_sizeof_ulong 4
#define mk_lang_sizeof_ullong 8
#define mk_lang_sizeof_ulllong 16


mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_sizeof_test(void);


#endif
