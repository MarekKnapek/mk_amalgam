#include "mk_std_istr_storage.h"

#include "../../mk_int/src/exact/mk_uint_32.h"

#include "mk_std_gcallocator.h"
#include "mk_std_istr.h"
#include "mk_std_ptr_buff.h"
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

	mk_try(mk_std_ptr_buff_construct(&istr_storage->m_strings));

	return 0;
}

mk_jumbo int mk_std_istr_storage_destruct(mk_std_istr_storage_t* istr_storage)
{
	size_t count;
	size_t i;
	mk_std_istr_string_t* elem;

	mk_assert(istr_storage);

	mk_try(mk_std_ptr_buff_get_count(&istr_storage->m_strings, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_last(&istr_storage->m_strings, (void**)&elem));
		mk_try(mk_std_gcallocator_deallocate(elem));
	}
	mk_try(mk_std_ptr_buff_remove_all(&istr_storage->m_strings));
	mk_try(mk_std_ptr_buff_destruct(&istr_storage->m_strings));

	return 0;
}

mk_jumbo int mk_std_istr_storage_insert_narrow(mk_std_istr_storage_t* istr_storage, char const* str, size_t len, mk_std_istr_t* istr)
{
	mk_std_istr_string_t* elem;
	size_t count;
	size_t i;
	mk_uint32_t is_wide;

	mk_assert(istr_storage);
	mk_assert(str);
	mk_assert(istr);

	mk_clobber(&elem);
	mk_try(mk_std_ptr_buff_get_count(&istr_storage->m_strings, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&istr_storage->m_strings, i, (void**)&elem)); mk_assert(elem);
		mk_uint32_shr(&elem->m_ref_count, &is_wide, 31);
		if(mk_uint32_to_sizet(&elem->m_length) == len && mk_uint32_to_int(&is_wide) == 0 && memcmp(str, ((char*)(((unsigned char*)(elem)) + sizeof(*elem))), len * sizeof(char)) == 0)
		{
			break;
		}
	}
	if(i == count)
	{
		mk_try(mk_std_ptr_buff_reserve_one(&istr_storage->m_strings));
		mk_try(mk_std_gcallocator_allocate(sizeof(*elem) + (len + 1) * sizeof(char), (void**)&elem)); mk_assert(elem);
		mk_try(mk_std_ptr_buff_append(&istr_storage->m_strings, elem));
		mk_uint32_from_int(&elem->m_ref_count, 0);
		mk_uint32_from_sizet(&elem->m_length, len);
		memcpy(((unsigned char*)(elem)) + sizeof(*elem), str, (len + 1) * sizeof(char));
	}
	mk_assert(!mk_uint32_is_max(&elem->m_ref_count));
	mk_uint32_inc(&elem->m_ref_count);
	mk_uint32_from_sizet(&istr->m_idx, i);

	return 0;
}

mk_jumbo int mk_std_istr_storage_insert_wide(mk_std_istr_storage_t* istr_storage, wchar_t const* str, size_t len, mk_std_istr_t* istr)
{
	size_t i;
	int is_ascii;
	char const* ascii;
	mk_std_istr_string_t* elem;
	size_t count;
	mk_uint32_t is_wide;

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
		mk_clobber(&elem);
		mk_try(mk_std_ptr_buff_get_count(&istr_storage->m_strings, &count));
		for(i = 0; i != count; ++i)
		{
			mk_try(mk_std_ptr_buff_get_element(&istr_storage->m_strings, i, (void**)&elem)); mk_assert(elem);
			mk_uint32_shr(&elem->m_ref_count, &is_wide, 31);
			if(mk_uint32_to_sizet(&elem->m_length) == len && mk_uint32_to_int(&is_wide) == 1 && memcmp(str, ((char*)(((unsigned char*)(elem)) + sizeof(*elem))), len * sizeof(wchar_t)) == 0)
			{
				break;
			}
		}
		if(i == count)
		{
			mk_try(mk_std_ptr_buff_reserve_one(&istr_storage->m_strings));
			mk_try(mk_std_gcallocator_allocate(sizeof(*elem) + (len + 1) * sizeof(wchar_t), (void**)&elem)); mk_assert(elem);
			mk_try(mk_std_ptr_buff_append(&istr_storage->m_strings, elem));
			mk_uint32_from_int(&elem->m_ref_count, 1);
			mk_uint32_shl(&elem->m_ref_count, &elem->m_ref_count, 31);
			mk_uint32_from_sizet(&elem->m_length, len);
			memcpy(((unsigned char*)(elem)) + sizeof(*elem), str, (len + 1) * sizeof(char));
		}
		mk_assert(!mk_uint32_is_max(&elem->m_ref_count));
		mk_uint32_inc(&elem->m_ref_count);
		mk_uint32_from_sizet(&istr->m_idx, i);
	}

	return 0;
}

mk_jumbo int mk_std_istr_storage_get(mk_std_istr_storage_t* istr_storage, mk_std_istr_t const* istr, int* is_wide, void const** str, size_t* len)
{
	unsigned long int idxf;
	unsigned long int idx;
	int wide;
	mk_std_istr_string_t* elem;

	mk_assert(istr_storage);
	mk_assert(istr);
	mk_assert(!mk_uint32_is_max(&istr->m_idx));
	mk_assert(is_wide);
	mk_assert(str);
	mk_assert(len);

	idxf = mk_uint32_to_long(&istr->m_idx);
	idx = (idxf << 1) >> 1;
	wide = idxf >> 31;
	mk_try(mk_std_ptr_buff_get_element(&istr_storage->m_strings, (size_t)idx, (void**)&elem)); mk_assert(elem);
	*is_wide = wide;
	*str = (void const*)(((unsigned char*)(elem)) + sizeof(*elem));
	*len = mk_uint32_to_sizet(&elem->m_length);

	return 0;
}

mk_jumbo int mk_std_istr_storage_remove(mk_std_istr_storage_t* istr_storage, mk_std_istr_t const* istr)
{
	unsigned long int idxf;
	unsigned long int idx;
	mk_std_istr_string_t* elem;

	mk_assert(istr_storage);
	mk_assert(istr);

	if(!mk_uint32_is_max(&istr->m_idx))
	{
		idxf = mk_uint32_to_long(&istr->m_idx);
		idx = (idxf << 1) >> 1;
		mk_try(mk_std_ptr_buff_get_element(&istr_storage->m_strings, (size_t)idx, (void**)&elem)); mk_assert(elem);
		mk_assert(!mk_uint32_is_zero(&elem->m_ref_count));
		mk_uint32_dec(&elem->m_ref_count);
	}


	return 0;
}

mk_jumbo int mk_std_istr_storage_purge(mk_std_istr_storage_t* istr_storage)
{
	size_t count;
	size_t i;
	mk_std_istr_string_t* elem;

	mk_assert(istr_storage);

	mk_try(mk_std_ptr_buff_get_count(&istr_storage->m_strings, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&istr_storage->m_strings, count - 1 - i, (void**)&elem)); mk_assert(elem);
		if(mk_uint32_is_zero(&elem->m_ref_count))
		{
			mk_try(mk_std_ptr_buff_remove_idx(&istr_storage->m_strings, count - 1 - i));
		}
	}

	return 0;
}
