#include "mk_dacdbt_str.h"

#include "mk_dacdbt_io.h"

#include "../../mk_std/src/mk_std_buffer.h"
#include "../../mk_std/src/mk_std_input_stream.h"
#include "../../mk_std/src/mk_std_istr.h"
#include "../../mk_std/src/mk_std_istrg.h"

#include "../../mk_int/src/exact/mk_uint_8.h"
#include "../../mk_int/src/exact/mk_uint_16.h"
#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


static mk_std_buffer_t mk_dacdbt_str_private_buff;


static mk_inline int mk_dacdbt_str_private_parse_len(mk_std_input_stream_t* is, size_t* len, int* unicode);


mk_jumbo int mk_dacdbt_str_init(void)
{
	mk_try(mk_std_buffer_init(&mk_dacdbt_str_private_buff));
	mk_try(mk_std_buffer_reserve(&mk_dacdbt_str_private_buff, 1));

	return 0;
}

mk_jumbo int mk_dacdbt_str_deinit(void)
{
	mk_try(mk_std_buffer_deinit(&mk_dacdbt_str_private_buff));

	return 0;
}

mk_jumbo int mk_dacdbt_str_construct(mk_dacdbt_str_t* str)
{
	mk_assert(str);

	mk_try(mk_std_istr_construct(&str->m_istr));

	return 0;
}

mk_jumbo int mk_dacdbt_str_construct_parse(mk_dacdbt_str_t* str, mk_std_input_stream_t* is)
{
	size_t len;
	int unicode;
	int multiplier;
	void* buff;

	mk_assert(sizeof(wchar_t) == 2);

	mk_assert(str);
	mk_assert(is);

	mk_try(mk_dacdbt_str_construct(str));
	mk_try(mk_dacdbt_str_private_parse_len(is, &len, &unicode));
	mk_assert(unicode == 0 || unicode == 1);
	multiplier = (int)((unicode == 0) ? sizeof(char) : sizeof(wchar_t));
	mk_try(mk_std_buffer_reserve(&mk_dacdbt_str_private_buff, len * multiplier));
	mk_try(mk_std_buffer_get_mem(&mk_dacdbt_str_private_buff, &buff));
	mk_try(mk_dacdbt_io_read_buff(is, buff, len * multiplier));
	if(unicode == 0)
	{
		mk_try(mk_std_istrg_insert_narrow((char const*)buff, len, &str->m_istr));
	}
	else
	{
		mk_try(mk_std_istrg_insert_wide((wchar_t const*)buff, len, &str->m_istr));
	}

	return 0;
}

mk_jumbo int mk_dacdbt_str_destruct(mk_dacdbt_str_t* str)
{
	mk_assert(str);

	mk_try(mk_std_istrg_remove(&str->m_istr));

	return 0;
}

mk_jumbo int mk_dacdbt_str_get(mk_dacdbt_str_t* str, int* is_wide, void const** data, size_t* len)
{
	mk_assert(str);
	mk_assert(is_wide);
	mk_assert(data);
	mk_assert(len);

	mk_try(mk_std_istrg_get(&str->m_istr, is_wide, data, len));

	return 0;
}

mk_jumbo int mk_dacdbt_str_is_empty(mk_dacdbt_str_t* str, int* is_empty)
{
	int is_wide;
	void const* data;
	size_t len;

	mk_assert(str);
	mk_assert(is_empty);

	mk_try(mk_dacdbt_str_get(str, &is_wide, &data, &len));
	(void)is_wide;
	(void)data;
	*is_empty = len == 0;

	return 0;
}


static mk_inline int mk_dacdbt_str_private_parse_len(mk_std_input_stream_t* is, size_t* len, int* unicode)
{
	static mk_uint8_t const s_len_max8 = mk_uint8_c(0xfful);
	static mk_uint16_t const s_tag16 = mk_uint16_c(0xfffeul);
	static mk_uint16_t const s_len_max16 = mk_uint16_c(0xfffful);
	static mk_uint32_t const s_len_max32 = mk_uint32_c(0xfffffffful);
	static mk_uint64_t const s_len_max64 = mk_uint64_c(0x00000000ul, 0xfffffffful);

	int unc;
	mk_uint8_t len8;
	mk_uint16_t len16;
	mk_uint32_t len32;
	mk_uint64_t len64;

	mk_assert(is);
	mk_assert(len);
	mk_assert(unicode);

	unc = 0;
	mk_try(mk_dacdbt_io_read_u8(is, &len8));
	if(mk_uint8_lt(&len8, &s_len_max8))
	{
		*len = mk_uint8_to_sizet(&len8);
		*unicode = unc;
		return 0;
	}
	mk_try(mk_dacdbt_io_read_u16(is, &len16));
	if(mk_uint16_eq(&len16, &s_tag16))
	{
		unc = 1;
		mk_try(mk_dacdbt_io_read_u8(is, &len8));
		if(mk_uint8_lt(&len8, &s_len_max8))
		{
			*len = mk_uint8_to_sizet(&len8);
			*unicode = unc;
			return 0;
		}
		mk_try(mk_dacdbt_io_read_u16(is, &len16));
	}
	if(mk_uint16_lt(&len16, &s_len_max16))
	{
		*len = mk_uint16_to_sizet(&len16);
		*unicode = unc;
		return 0;
	}
	mk_try(mk_dacdbt_io_read_u32(is, &len32));
	if(mk_uint32_lt(&len32, &s_len_max32))
	{
		*len = mk_uint32_to_sizet(&len32);
		*unicode = unc;
		return 0;
	}
	mk_try(mk_dacdbt_io_read_u64(is, &len64));
	mk_check((sizeof(size_t) >= 4 && mk_uint64_le(&len64, &s_len_max64)) || sizeof(size_t) >= 8);
	*len = mk_uint64_to_sizet(&len64);
	*unicode = unc;
	return 0;
}
