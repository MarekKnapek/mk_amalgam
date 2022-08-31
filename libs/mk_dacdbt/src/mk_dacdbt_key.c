#include "mk_dacdbt_key.h"

#include "mk_dacdbt_io.h"
#include "mk_dacdbt_str.h"
#include "mk_dacdbt_value.h"

#include "../../mk_std/src/mk_std_gcallocator.h"
#include "../../mk_std/src/mk_std_input_stream.h"
#include "../../mk_std/src/mk_std_ptr_buff.h"

#include "../../mk_int/src/exact/mk_uint_32.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


mk_jumbo int mk_dacdbt_key_construct(mk_dacdbt_key_t* key)
{
	mk_assert(key);

	mk_try(mk_dacdbt_str_construct(&key->m_name));
	mk_try(mk_std_ptr_buff_construct(&key->m_sub_keys));
	mk_try(mk_std_ptr_buff_construct(&key->m_values));
	key->m_nocomp = 0;

	return 0;
}

mk_jumbo int mk_dacdbt_key_construct_parse(mk_dacdbt_key_t* key, mk_std_input_stream_t* is)
{
	static mk_uint32_t const s_max_items = mk_uint32_c(0x04000000);

	mk_uint32_t sub_keys_count;
	mk_uint32_t values_count;
	mk_uint32_t i;
	mk_dacdbt_key_t* sub_key;
	mk_dacdbt_value_t* value;
	int next_nocomp;

	mk_assert(key);
	mk_assert(is);

	mk_try(mk_dacdbt_key_construct(key));
	mk_try(mk_dacdbt_str_construct_parse(&key->m_name, is)); mk_check(key->m_name.m_len != 0);
	mk_try(mk_dacdbt_io_read_u32(is, &sub_keys_count)); mk_check(mk_uint32_le(&sub_keys_count, &s_max_items));
	mk_try(mk_dacdbt_io_read_u32(is, &values_count)); mk_check(mk_uint32_le(&values_count, &s_max_items));
	/*mk_try(mk_std_ptr_buff_reserve(&key->m_sub_keys, mk_uint32_to_sizet(&sub_keys_count)));*/
	for(mk_uint32_zero(&i); mk_uint32_neq(&i, &sub_keys_count); mk_uint32_inc(&i))
	{
		mk_try(mk_std_gcallocator_allocate(sizeof(*sub_key), (void**)&sub_key));
		mk_try(mk_dacdbt_key_construct(sub_key));
		mk_try(mk_std_ptr_buff_append(&key->m_sub_keys, sub_key));
		mk_try(mk_dacdbt_key_construct_parse(sub_key, is));
	}
	value = NULL;
	next_nocomp = 0;
	/*mk_try(mk_std_ptr_buff_reserve(&key->m_values, mk_uint32_to_sizet(&values_count)));*/
	for(mk_uint32_zero(&i); mk_uint32_neq(&i, &values_count); mk_uint32_inc(&i))
	{
		if(value == NULL) mk_try(mk_std_gcallocator_allocate(sizeof(*value), (void**)&value));
		mk_try(mk_dacdbt_value_construct(value));
		mk_try(mk_std_ptr_buff_append(&key->m_values, value));
		mk_try(mk_dacdbt_value_construct_parse(value, is));
		if
		(
			value->m_type == mk_dacdbt_value_type_e_u32 &&
			value->m_name.m_type == 0 &&
			value->m_name.m_len == 2 &&
			value->m_name.m_data.m_narrow[0] == '%' &&
			value->m_name.m_data.m_narrow[1] == '%'
		)
		{
			if(mk_uint32_is_zero(&value->m_data.m_u32))
			{
				key->m_nocomp = 1;
			}
			else
			{
				next_nocomp = 1;
			}
			mk_try(mk_std_ptr_buff_remove_last(&key->m_values));
			mk_try(mk_dacdbt_value_destruct(value));
			mk_try(mk_dacdbt_value_construct(value));
			mk_uint32_dec(&i);
		}
		else if
		(
			value->m_type == mk_dacdbt_value_type_e_u32 &&
			value->m_name.m_type == 0 &&
			value->m_name.m_len >= 2 &&
			value->m_name.m_data.m_narrow[0] == '@' &&
			value->m_name.m_data.m_narrow[1] == '@'
		)
		{
			if(mk_uint32_is_zero(&value->m_data.m_u32))
			{
				key->m_nocomp = 1;
			}
			else
			{
				next_nocomp = 1;
			}
			mk_try(mk_std_ptr_buff_remove_last(&key->m_values));
			mk_try(mk_dacdbt_value_destruct(value));
			mk_try(mk_dacdbt_value_construct(value));
		}
		else
		{
			if(next_nocomp != 0)
			{
				value->m_nocomp = 1;
				next_nocomp = 0;
			}
			value = NULL;
		}
	}
	if(value)
	{
		mk_try(mk_std_gcallocator_deallocate(value));
		mk_check(0);
	}

	return 0;
}

mk_jumbo int mk_dacdbt_key_destruct(mk_dacdbt_key_t* key)
{
	size_t count;
	size_t i;
	mk_dacdbt_key_t* sub_key;
	mk_dacdbt_value_t* value;

	mk_assert(key);

	mk_try(mk_std_ptr_buff_get_count(&key->m_values, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&key->m_values, count - 1 - i, (void**)&value));
		mk_try(mk_std_ptr_buff_remove_last(&key->m_values));
		mk_try(mk_dacdbt_value_destruct(value));
		mk_try(mk_std_gcallocator_deallocate(value));
	}
	mk_try(mk_std_ptr_buff_destruct(&key->m_values));
	mk_try(mk_std_ptr_buff_get_count(&key->m_sub_keys, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&key->m_sub_keys, count - 1 - i, (void**)&sub_key));
		mk_try(mk_std_ptr_buff_remove_last(&key->m_sub_keys));
		mk_try(mk_dacdbt_key_destruct(sub_key));
		mk_try(mk_std_gcallocator_deallocate(sub_key));
	}
	mk_try(mk_std_ptr_buff_destruct(&key->m_sub_keys));
	mk_try(mk_dacdbt_str_destruct(&key->m_name));

	return 0;
}

mk_jumbo int mk_dacdbt_key_get_max(mk_dacdbt_key_t* key, unsigned long* keys, unsigned long* values)
{
	size_t cnt;
	size_t i;
	mk_dacdbt_key_t* k;

	mk_assert(key);
	mk_assert(keys);
	mk_assert(values);

	mk_try(mk_std_ptr_buff_get_count(&key->m_values, &cnt));
	if(cnt > *values)
	{
		*values = (unsigned long)cnt;
	}
	mk_try(mk_std_ptr_buff_get_count(&key->m_sub_keys, &cnt));
	if(cnt > *keys)
	{
		*keys = (unsigned long)cnt;
	}
	for(i = 0; i != cnt; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&key->m_sub_keys, i, &k));
		mk_try(mk_dacdbt_key_get_max(k, keys, values));
	}

	return 0;
}
