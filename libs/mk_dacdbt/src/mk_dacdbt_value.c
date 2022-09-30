#include "mk_dacdbt_value.h"

#include "mk_dacdbt_io.h"
#include "mk_dacdbt_str.h"

#include "../../mk_std/src/mk_std_gcallocator.h"
#include "../../mk_std/src/mk_std_input_stream.h"

#include "../../mk_int/src/exact/mk_uint_8.h"
#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


mk_jumbo int mk_dacdbt_value_construct(mk_dacdbt_value_t* value)
{
	mk_assert(value);

	mk_try(mk_dacdbt_str_construct(&value->m_name));
	value->m_type = mk_dacdbt_value_type_e_u32;
	mk_uint32_zero(&value->m_data.m_u32);
	value->m_nocomp = 0;

	return 0;
}

mk_jumbo int mk_dacdbt_value_construct_parse(mk_dacdbt_value_t* value, mk_std_input_stream_t* is)
{
	static mk_uint32_t const s_max_len = mk_uint32_c(0x04000000ul);

	int empty;
	mk_uint8_t type;
	unsigned typeu;
	mk_dacdbt_value_type_t typee;
	mk_uint32_t bin_len;

	mk_assert(value);
	mk_assert(is);

	mk_try(mk_dacdbt_value_construct(value));
	mk_try(mk_dacdbt_str_construct_parse(&value->m_name, is));
	mk_try(mk_dacdbt_str_is_empty(&value->m_name, &empty));
	mk_check(!empty);
	mk_try(mk_dacdbt_io_read_u8(is, &type));
	typeu = mk_uint8_to_int(&type);
	mk_check
	(
		typeu == mk_dacdbt_value_type_e_u32 ||
		typeu == mk_dacdbt_value_type_e_f64 ||
		typeu == mk_dacdbt_value_type_e_str ||
		typeu == mk_dacdbt_value_type_e_bin ||
		typeu == mk_dacdbt_value_type_e_file ||
		typeu == mk_dacdbt_value_type_e_u64 ||
		typeu == 7 ||
		typeu == 8
	);
	typee = (typeu == 7) ? (mk_dacdbt_value_type_e_str) : ((typeu == 8) ? (mk_dacdbt_value_type_e_str) : ((mk_dacdbt_value_type_t)(typeu)));
	switch(typee)
	{
		case mk_dacdbt_value_type_e_u32:
		{
			mk_try(mk_dacdbt_io_read_u32(is, &value->m_data.m_u32));
		}
		break;
		case mk_dacdbt_value_type_e_f64:
		{
			mk_assert(sizeof(value->m_data.m_f64) == 8);
			mk_try(mk_dacdbt_io_read_buff(is, &value->m_data.m_f64, sizeof(value->m_data.m_f64)));
		}
		break;
		case mk_dacdbt_value_type_e_str:
		{
			value->m_type = typee;
			mk_try(mk_dacdbt_str_construct_parse(&value->m_data.m_str, is));
		}
		break;
		case mk_dacdbt_value_type_e_bin:
		{
			mk_try(mk_dacdbt_io_read_u32(is, &bin_len));
			mk_check(mk_uint32_le(&bin_len, &s_max_len));
			value->m_data.m_bin.m_len = mk_uint32_to_sizet(&bin_len);
			mk_try(mk_std_gcallocator_allocate(value->m_data.m_bin.m_len, &value->m_data.m_bin.m_data));
			value->m_type = typee;
			mk_try(mk_dacdbt_io_read_buff(is, value->m_data.m_bin.m_data, value->m_data.m_bin.m_len));
		}
		break;
		case mk_dacdbt_value_type_e_file:
		{
			mk_try(mk_dacdbt_io_read_u32(is, &bin_len));
			mk_check(mk_uint32_le(&bin_len, &s_max_len));
			value->m_data.m_file.m_len = mk_uint32_to_sizet(&bin_len);
			mk_try(mk_std_gcallocator_allocate(value->m_data.m_file.m_len, &value->m_data.m_file.m_data));
			value->m_type = typee;
			mk_try(mk_dacdbt_io_read_buff(is, value->m_data.m_file.m_data, value->m_data.m_file.m_len));
		}
		break;
		case mk_dacdbt_value_type_e_u64:
		{
			mk_try(mk_dacdbt_io_read_u64(is, &value->m_data.m_u64));
		}
		break;
	}
	value->m_type = typee;

	return 0;
}

mk_jumbo int mk_dacdbt_value_destruct(mk_dacdbt_value_t* value)
{
	mk_assert(value);
	mk_assert
	(
		value->m_type == mk_dacdbt_value_type_e_u32 ||
		value->m_type == mk_dacdbt_value_type_e_f64 ||
		value->m_type == mk_dacdbt_value_type_e_str ||
		value->m_type == mk_dacdbt_value_type_e_bin ||
		value->m_type == mk_dacdbt_value_type_e_file ||
		value->m_type == mk_dacdbt_value_type_e_u64
	);

	switch(value->m_type)
	{
		case mk_dacdbt_value_type_e_u32: break;
		case mk_dacdbt_value_type_e_f64: break;
		case mk_dacdbt_value_type_e_str: mk_try(mk_dacdbt_str_destruct(&value->m_data.m_str)); break;
		case mk_dacdbt_value_type_e_bin: mk_try(mk_std_gcallocator_deallocate(value->m_data.m_bin.m_data)); break;
		case mk_dacdbt_value_type_e_file: mk_try(mk_std_gcallocator_deallocate(value->m_data.m_file.m_data)); break;
		case mk_dacdbt_value_type_e_u64: break;
	}
	mk_try(mk_dacdbt_str_destruct(&value->m_name));

	return 0;
}
