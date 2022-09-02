#include "mk_std_istrg.h"

#include "mk_std_istr.h"
#include "mk_std_istr_storage.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


static mk_std_istr_storage_t mk_std_istrg_private_storage;


mk_jumbo int mk_std_istrg_init(void)
{

	mk_try(mk_std_istr_storage_construct(&mk_std_istrg_private_storage));

	return 0;
}

mk_jumbo int mk_std_istrg_deinit(void)
{
	mk_try(mk_std_istr_storage_destruct(&mk_std_istrg_private_storage));

	return 0;
}

mk_jumbo int mk_std_istrg_insert_narrow(char const* str, size_t len, mk_std_istr_t* istr)
{
	mk_try(mk_std_istr_storage_insert_narrow(&mk_std_istrg_private_storage, str, len, istr));

	return 0;
}

mk_jumbo int mk_std_istrg_insert_wide(wchar_t const* str, size_t len, mk_std_istr_t* istr)
{
	mk_try(mk_std_istr_storage_insert_wide(&mk_std_istrg_private_storage, str, len, istr));

	return 0;
}

mk_jumbo int mk_std_istrg_get(mk_std_istr_t* istr, int* is_wide, void const** str, size_t* len)
{
	mk_try(mk_std_istr_storage_get(&mk_std_istrg_private_storage, istr, is_wide, str, len));

	return 0;
}

mk_jumbo int mk_std_istrg_remove(mk_std_istr_t const* istr)
{
	mk_try(mk_std_istr_storage_remove(&mk_std_istrg_private_storage, istr));

	return 0;
}

mk_jumbo int mk_std_istrg_purge(void)
{
	mk_try(mk_std_istr_storage_purge(&mk_std_istrg_private_storage));

	return 0;
}
