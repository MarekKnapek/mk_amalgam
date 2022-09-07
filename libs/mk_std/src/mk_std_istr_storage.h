#ifndef mk_include_guard_std_istr_storage
#define mk_include_guard_std_istr_storage


#include "mk_std_istr.h"
#include "mk_std_robin_hood_strn.h"
#include "mk_std_robin_hood_strw.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


struct mk_std_istr_storage_s
{
	mk_std_robin_hood_strn_t m_n;
	mk_std_robin_hood_strw_t m_w;
};
typedef struct mk_std_istr_storage_s mk_std_istr_storage_t;


mk_jumbo int mk_std_istr_storage_construct(mk_std_istr_storage_t* istr_storage);
mk_jumbo int mk_std_istr_storage_destruct(mk_std_istr_storage_t* istr_storage);
mk_jumbo int mk_std_istr_storage_insert_narrow(mk_std_istr_storage_t* istr_storage, char const* str, size_t len, mk_std_istr_t* istr);
mk_jumbo int mk_std_istr_storage_insert_wide(mk_std_istr_storage_t* istr_storage, wchar_t const* str, size_t len, mk_std_istr_t* istr);
mk_jumbo int mk_std_istr_storage_get(mk_std_istr_storage_t* istr_storage, mk_std_istr_t const* istr, int* is_wide, void const** str, size_t* len);
mk_jumbo int mk_std_istr_storage_remove(mk_std_istr_storage_t* istr_storage, mk_std_istr_t const* istr);
mk_jumbo int mk_std_istr_storage_purge(mk_std_istr_storage_t* istr_storage);


#endif
