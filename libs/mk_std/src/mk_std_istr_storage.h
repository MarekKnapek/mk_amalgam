#ifndef mk_include_guard_std_istr_storage
#define mk_include_guard_std_istr_storage


#include "mk_std_istr.h"
#include "mk_std_ptr_buff.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


struct mk_std_istr_storage_s
{
	mk_std_ptr_buff_t m_strings;
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
