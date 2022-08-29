#include "mk_std_input_stream.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_assert.h"

#include <stddef.h>
#include <stdio.h>


mk_jumbo int mk_std_input_stream_construct_file(mk_std_input_stream_t* is, FILE* file)
{
	mk_assert(is);

	is->m_type = mk_std_input_stream_private_type_e_file;
	is->m_mix.m_file.m_file = file;

	return 0;
}

mk_jumbo int mk_std_input_stream_construct_buffer(mk_std_input_stream_t* is, void const* buffer, size_t len)
{
	mk_assert(is);

	is->m_type = mk_std_input_stream_private_type_e_buffer;
	is->m_mix.m_buffer.m_buffer = buffer;
	is->m_mix.m_buffer.m_len = len;

	return 0;
}

mk_jumbo int mk_std_input_stream_destruct(mk_std_input_stream_t* is)
{
	mk_assert(is);

	return 0;
}

mk_jumbo int mk_std_input_stream_read(mk_std_input_stream_t* is, void* dst, size_t len, size_t* read)
{
	#define mk_min(x, y) ((y) < (x) ? (y) : (x))
	#define mk_memcpy(xdst, xsrc, xlen) { unsigned char* xd; unsigned char const* xs; size_t xl; size_t i; xd = (unsigned char*)(xdst); xs = (unsigned char const*)(xsrc); xl = (xlen); for(i = 0; i != xl; ++i, ++xd, ++xs) *xd = *xs; }

	size_t amount;

	mk_assert(is);
	mk_assert(read);

	switch(is->m_type)
	{
		case mk_std_input_stream_private_type_e_file: *read = fread(dst, 1, len, is->m_mix.m_file.m_file); break;
		case mk_std_input_stream_private_type_e_buffer:
			amount = mk_min(len, is->m_mix.m_buffer.m_len);
			mk_memcpy(dst, is->m_mix.m_buffer.m_buffer, amount);
			is->m_mix.m_buffer.m_len -= amount;
			is->m_mix.m_buffer.m_buffer = (void const*)(((unsigned char const*)(is->m_mix.m_buffer.m_buffer)) + amount);
			*read = amount;
			break;
	}

	return 0;

	#undef mk_min
	#undef mk_memcpy
}
