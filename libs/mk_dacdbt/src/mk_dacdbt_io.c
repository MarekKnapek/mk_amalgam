#include "mk_dacdbt_io.h"

#include "../../mk_std/src/mk_std_buffer.h"
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
	#define mk_memcpy(xdst, xsrc, xlen) do{ unsigned char* xd; unsigned char const* xs; size_t xl; size_t i; xd = ((unsigned char*)(xdst)); xs = ((unsigned char const*)(xsrc)); xl = (xlen); for(i = 0; i != xl; ++i, ++xd, ++xs){ *xd = *xs; } }while(0)

	size_t remaining;
	size_t read;
	void const* data;

	mk_assert(is);
	mk_assert(buff || len == 0);

	remaining = len;
	while(remaining != 0)
	{
		read = remaining;
		mk_try(mk_std_input_stream_read(is, &data, &read));
		mk_check(read != 0);
		remaining -= read;
		mk_memcpy(buff, data, read);
		buff = ((void*)(((unsigned char*)(buff)) + read));
	}

	return 0;

	#undef mk_memcpy
}

mk_jumbo int mk_dacdbt_io_read_buffer(mk_std_input_stream_t* is, mk_std_buffer_t* buffer, size_t len)
{
	#define mk_memcpy(xdst, xsrc, xlen) do{ unsigned char* xd; unsigned char const* xs; size_t xl; size_t i; xd = ((unsigned char*)(xdst)); xs = ((unsigned char const*)(xsrc)); xl = (xlen); for(i = 0; i != xl; ++i, ++xd, ++xs){ *xd = *xs; } }while(0)

	mk_assert(is);
	mk_assert(buffer);

	size_t remaining;
	size_t read;
	void const* data;
	void* mem;

	mk_assert(is);

	remaining = len;
	while(remaining != 0)
	{
		read = remaining;
		mk_try(mk_std_input_stream_read(is, &data, &read));
		mk_check(read != 0);
		remaining -= read;
		mk_try(mk_std_buffer_reserve(buffer, len - remaining));
		mk_try(mk_std_buffer_get_mem(buffer, &mem));
		mem = ((void*)(((unsigned char*)(mem)) + len - remaining - read));
		mk_memcpy(mem, data, read);
	}

	return 0;

	#undef mk_memcpy
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
