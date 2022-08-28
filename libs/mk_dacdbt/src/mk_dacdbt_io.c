#include "mk_dacdbt_io.h"

#include "../../mk_std/src/mk_std_input_stream.h"

#include "../../mk_int/src/exact/mk_uint_8.h"
#include "../../mk_int/src/exact/mk_uint_16.h"
#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


mk_jumbo int mk_dacdbt_io_read_buff(mk_std_input_stream_t* is, void* buff, size_t len)
{
	size_t read;

	mk_assert(is);
	mk_assert(buff || len == 0);

	mk_try(mk_std_input_stream_read(is, buff, len, &read));
	mk_check(read == len);

	return 0;
}

mk_jumbo int mk_dacdbt_io_read_u8(mk_std_input_stream_t* is, mk_uint8_t* u8)
{
	unsigned char buff[1];

	mk_assert(is);
	mk_assert(u8);

	mk_try(mk_dacdbt_io_read_buff(is, &buff, sizeof(buff)));
	mk_uint8_from_buff_le(u8, &buff);

	return 0;
}

mk_jumbo int mk_dacdbt_io_read_u16(mk_std_input_stream_t* is, mk_uint16_t* u16)
{
	unsigned char buff[2];

	mk_assert(is);
	mk_assert(u16);

	mk_try(mk_dacdbt_io_read_buff(is, &buff, sizeof(buff)));
	mk_uint16_from_buff_le(u16, &buff);

	return 0;
}

mk_jumbo int mk_dacdbt_io_read_u32(mk_std_input_stream_t* is, mk_uint32_t* u32)
{
	unsigned char buff[4];

	mk_assert(is);
	mk_assert(u32);

	mk_try(mk_dacdbt_io_read_buff(is, &buff, sizeof(buff)));
	mk_uint32_from_buff_le(u32, &buff);

	return 0;
}

mk_jumbo int mk_dacdbt_io_read_u64(mk_std_input_stream_t* is, mk_uint64_t* u64)
{
	unsigned char buff[8];

	mk_assert(is);
	mk_assert(u64);

	mk_try(mk_dacdbt_io_read_buff(is, &buff, sizeof(buff)));
	mk_uint64_from_buff_le(u64, &buff);

	return 0;
}
