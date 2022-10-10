#include "mk_dacdbt_value.h"

#include "mk_dacdbt_io.h"
#include "mk_dacdbt_str.h"

#include "../../mk_std/src/mk_std_buffer.h"
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
		typeu == mk_dacdbt_value_type_e_fil ||
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
			mk_try(mk_dacdbt_io_read_f64(is, &value->m_data.m_f64));
		}
		break;
		case mk_dacdbt_value_type_e_str:
		{
			mk_try(mk_dacdbt_str_construct_parse(&value->m_data.m_str, is));
		}
		break;
		case mk_dacdbt_value_type_e_bin:
		{
			mk_try(mk_dacdbt_io_read_u32(is, &bin_len));
			mk_try(mk_std_buffer_init(&value->m_data.m_bin));
			mk_try(mk_dacdbt_io_read_buffer(is, &value->m_data.m_bin, mk_uint32_to_sizet(&bin_len)));
		}
		break;
		case mk_dacdbt_value_type_e_fil:
		{
			mk_try(mk_dacdbt_io_read_u32(is, &bin_len));
			mk_try(mk_std_buffer_init(&value->m_data.m_file));
			mk_try(mk_dacdbt_io_read_buffer(is, &value->m_data.m_file, mk_uint32_to_sizet(&bin_len)));
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
		value->m_type == mk_dacdbt_value_type_e_fil ||
		value->m_type == mk_dacdbt_value_type_e_u64
	);

	switch(value->m_type)
	{
		case mk_dacdbt_value_type_e_u32: break;
		case mk_dacdbt_value_type_e_f64: break;
		case mk_dacdbt_value_type_e_str: mk_try(mk_dacdbt_str_destruct(&value->m_data.m_str)); break;
		case mk_dacdbt_value_type_e_bin: mk_try(mk_std_buffer_deinit(&value->m_data.m_bin)); break;
		case mk_dacdbt_value_type_e_fil: mk_try(mk_std_buffer_deinit(&value->m_data.m_file)); break;
		case mk_dacdbt_value_type_e_u64: break;
	}
	mk_try(mk_dacdbt_str_destruct(&value->m_name));

	return 0;
}

mk_jumbo int mk_dacdbt_value_get_name(mk_dacdbt_value_t const* value, int* is_wide, void const** data, size_t* len)
{
	mk_assert(value);

	mk_try(mk_dacdbt_str_get(&value->m_name, is_wide, data, len));

	return 0;
}

mk_jumbo int mk_dacdbt_value_get_type(mk_dacdbt_value_t const* value, mk_dacdbt_value_type_t* type)
{
	mk_assert(value);
	mk_assert(type);

	*type = value->m_type;

	return 0;
}

mk_jumbo int mk_dacdbt_value_get_len(mk_dacdbt_value_t const* value, size_t* len)
{
	int wide;
	void const* data;

	mk_assert(value);
	mk_assert(len);

	switch(value->m_type)
	{
		case mk_dacdbt_value_type_e_u32: mk_assert(0); break;
		case mk_dacdbt_value_type_e_f64: mk_assert(0); break;
		case mk_dacdbt_value_type_e_str: mk_try(mk_dacdbt_str_get(&value->m_data.m_str, &wide, &data, len)); break;
		case mk_dacdbt_value_type_e_bin: mk_try(mk_std_buffer_get_size(&value->m_data.m_bin, len)); break;
		case mk_dacdbt_value_type_e_fil: mk_try(mk_std_buffer_get_size(&value->m_data.m_file, len)); break;
		case mk_dacdbt_value_type_e_u64: mk_assert(0); break;
	}

	return 0;
}

mk_jumbo int mk_dacdbt_value_get_u32(mk_dacdbt_value_t const* value, mk_uint32_t const** u32)
{
	mk_assert(value);
	mk_assert(u32);
	mk_assert(value->m_type == mk_dacdbt_value_type_e_u32);

	*u32 = &value->m_data.m_u32;

	return 0;
}

mk_jumbo int mk_dacdbt_value_get_str(mk_dacdbt_value_t const* value, mk_dacdbt_str_t const** str)
{
	mk_assert(value);
	mk_assert(str);
	mk_assert(value->m_type == mk_dacdbt_value_type_e_str);

	*str = &value->m_data.m_str;

	return 0;
}

mk_jumbo int mk_dacdbt_value_get_u64(mk_dacdbt_value_t const* value, mk_uint64_t const** u64)
{
	mk_assert(value);
	mk_assert(u64);
	mk_assert(value->m_type == mk_dacdbt_value_type_e_u64);

	*u64 = &value->m_data.m_u64;

	return 0;
}
