#include "mk_std_istr_storage.h"

#include "../../mk_int/src/exact/mk_uint_32.h"

#include "mk_std_gcallocator.h"
#include "mk_std_istr.h"
#include "mk_std_robin_hood_strn.h"
#include "mk_std_robin_hood_strw.h"
#include "mk_std_str_convertor.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_clobber.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>
#include <string.h>


struct mk_std_istr_string_s
{
	mk_uint32_t m_ref_count;
	mk_uint32_t m_length;
	/* flexible char[] or wchar_t[] */
};
typedef struct mk_std_istr_string_s mk_std_istr_string_t;


mk_jumbo int mk_std_istr_storage_construct(mk_std_istr_storage_t* istr_storage)
{
	mk_assert(istr_storage);

	mk_try(mk_std_robin_hood_strn_construct(&istr_storage->m_n));
	mk_try(mk_std_robin_hood_strw_construct(&istr_storage->m_w));

	return 0;
}

mk_jumbo int mk_std_istr_storage_destruct(mk_std_istr_storage_t* istr_storage)
{
	mk_assert(istr_storage);

	mk_try(mk_std_robin_hood_strw_destruct(&istr_storage->m_w));
	mk_try(mk_std_robin_hood_strn_destruct(&istr_storage->m_n));

	return 0;
}

mk_jumbo int mk_std_istr_storage_insert_narrow(mk_std_istr_storage_t* istr_storage, char const* str, size_t len, mk_std_istr_t* istr)
{
	mk_std_robin_hood_strn_incomming_t incomming;
	char const* inserted;

	mk_assert(istr_storage);
	mk_assert(str);
	mk_assert(istr);

	incomming.m_strn = str;
	incomming.m_len = len;
	mk_try(mk_std_robin_hood_strn_insert(&istr_storage->m_n, &incomming, &inserted));
	istr->m_idx.m_n = inserted;
	mk_assert((mk_uintp_to_int(&istr->m_idx.m_i) & 0x01) == 0);

	return 0;
}

mk_jumbo int mk_std_istr_storage_insert_wide(mk_std_istr_storage_t* istr_storage, wchar_t const* str, size_t len, mk_std_istr_t* istr)
{
	int is_ascii;
	char const* ascii;
	mk_std_robin_hood_strw_incomming_t incomming;
	wchar_t const* inserted;

	mk_assert(istr_storage);
	mk_assert(str);
	mk_assert(istr);

	mk_try(mk_std_str_convertor_is_ascii_s(str, len, &is_ascii));
	if(is_ascii)
	{
		mk_try(mk_std_str_convertor_wide_to_narrow_s(str, len, 0, &ascii));
		mk_try(mk_std_istr_storage_insert_narrow(istr_storage, ascii, len, istr));
	}
	else
	{
		incomming.m_strw = str;
		incomming.m_len = len;
		mk_try(mk_std_robin_hood_strw_insert(&istr_storage->m_w, &incomming, &inserted));
		istr->m_idx.m_w = inserted;
		mk_assert((mk_uintp_to_int(&istr->m_idx.m_i) & 0x01) == 0);
		mk_uintp_inc(&istr->m_idx.m_i);
	}

	return 0;
}

mk_jumbo int mk_std_istr_storage_get(mk_std_istr_storage_t const* istr_storage, mk_std_istr_t const* istr, int* is_wide, void const** str, size_t* len)
{
	mk_std_istr_t copy;

	mk_assert(istr_storage);
	mk_assert(istr);
	mk_assert(is_wide);
	mk_assert(str);
	mk_assert(len);

	if((mk_uintp_to_int(&istr->m_idx.m_i) & 0x01) == 0)
	{
		*is_wide = 0;
		*str = istr->m_idx.m_n;
		*len = ((size_t const*)(istr->m_idx.m_n))[-1];
	}
	else
	{
		copy = *istr;
		mk_uintp_dec(&copy.m_idx.m_i);
		*is_wide = 1;
		*str = copy.m_idx.m_w;
		*len = ((size_t const*)(copy.m_idx.m_w))[-1];
	}

	return 0;
}

mk_jumbo int mk_std_istr_storage_remove(mk_std_istr_storage_t* istr_storage, mk_std_istr_t const* istr)
{
	mk_assert(istr_storage);
	mk_assert(istr);

	return 0;
}

mk_jumbo int mk_std_istr_storage_purge(mk_std_istr_storage_t* istr_storage)
{
	mk_assert(istr_storage);

	return 0;
}
