#ifndef mk_include_guard_std_istrg
#define mk_include_guard_std_istrg


#include "mk_std_istr.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


mk_jumbo int mk_std_istrg_init(void);
mk_jumbo int mk_std_istrg_deinit(void);
mk_jumbo int mk_std_istrg_insert_narrow(char const* str, size_t len, mk_std_istr_t* istr);
mk_jumbo int mk_std_istrg_insert_wide(wchar_t const* str, size_t len, mk_std_istr_t* istr);
mk_jumbo int mk_std_istrg_get(mk_std_istr_t const* istr, int* is_wide, void const** str, size_t* len);
mk_jumbo int mk_std_istrg_remove(mk_std_istr_t const* istr);
mk_jumbo int mk_std_istrg_purge(void);


#endif
