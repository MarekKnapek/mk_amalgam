#ifndef mk_include_guard_dacdbt_io
#define mk_include_guard_dacdbt_io


#include "../../mk_std/src/mk_std_buffer.h"
#include "../../mk_std/src/mk_std_input_stream.h"

#include "../../mk_int/src/exact/mk_uint_8.h"
#include "../../mk_int/src/exact/mk_uint_16.h"
#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


mk_jumbo int mk_dacdbt_io_read_buff(mk_std_input_stream_t* is, void* buff, size_t len);
mk_jumbo int mk_dacdbt_io_read_buffer(mk_std_input_stream_t* is, mk_std_buffer_t* buffer, size_t len);
mk_jumbo int mk_dacdbt_io_read_u8(mk_std_input_stream_t* is, mk_uint8_t* u8);
mk_jumbo int mk_dacdbt_io_read_u16(mk_std_input_stream_t* is, mk_uint16_t* u16);
mk_jumbo int mk_dacdbt_io_read_u32(mk_std_input_stream_t* is, mk_uint32_t* u32);
mk_jumbo int mk_dacdbt_io_read_u64(mk_std_input_stream_t* is, mk_uint64_t* u64);
mk_jumbo int mk_dacdbt_io_read_f64(mk_std_input_stream_t* is, double* f64);


#endif
