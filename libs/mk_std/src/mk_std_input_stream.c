#include "mk_std_input_stream.h"

#include "mk_std_buffer.h"

#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_kernel_input_stream.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>
#include <stdio.h>


mk_jumbo int mk_std_input_stream_construct_file(mk_std_input_stream_t* is, FILE* file)
{
	mk_assert(is);

	is->m_type = mk_std_input_stream_private_type_e_file;
	is->m_mix.m_file.m_file = file;
	mk_try(mk_std_buffer_init(&is->m_mix.m_file.m_buffer));

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

mk_jumbo int mk_std_input_stream_construct_mapping(mk_std_input_stream_t* is, mk_win_strc_t file_name)
{
	mk_assert(is);
	mk_assert(file_name);

	is->m_type = mk_std_input_stream_private_type_e_mapping;
	mk_try(mk_win_kernel_input_stream_construct(&is->m_mix.m_mapping.m_win_is, file_name));

	return 0;
}

mk_jumbo int mk_std_input_stream_destruct(mk_std_input_stream_t* is)
{
	mk_assert(is);

	switch(is->m_type)
	{
		case mk_std_input_stream_private_type_e_file:
		{
			mk_try(mk_std_buffer_deinit(&is->m_mix.m_file.m_buffer));
		}
		break;
		case mk_std_input_stream_private_type_e_buffer:
		break;
		case mk_std_input_stream_private_type_e_mapping:
		{
			mk_try(mk_win_kernel_input_stream_destruct(&is->m_mix.m_mapping.m_win_is));
		}
		break;
	}

	return 0;
}

mk_jumbo int mk_std_input_stream_read(mk_std_input_stream_t* is, void const** data, size_t* len)
{
	mk_assert(is);
	mk_assert(data);
	mk_assert(len);

	switch(is->m_type)
	{
		case mk_std_input_stream_private_type_e_file:
		{
			#define mk_min(x, y) ((y) < (x) ? (y) : (x))
			static size_t const s_2mb = 2ul * 1024ul * 1024ul;
			size_t amount;
			void* mem;
			amount = mk_min(s_2mb, *len);
			mk_try(mk_std_buffer_reserve(&is->m_mix.m_file.m_buffer, amount));
			mk_try(mk_std_buffer_get_mem(&is->m_mix.m_file.m_buffer, &mem));
			*len = fread(mem, 1, amount, is->m_mix.m_file.m_file);
			*data = mem;
			#undef mk_min
		}
		break;
		case mk_std_input_stream_private_type_e_buffer:
		{
			mk_check(*len <= is->m_mix.m_buffer.m_len);
			*data = is->m_mix.m_buffer.m_buffer;
			is->m_mix.m_buffer.m_len -= *len;
			is->m_mix.m_buffer.m_buffer = ((void const*)(((unsigned char const*)(is->m_mix.m_buffer.m_buffer)) + *len));
		}
		break;
		case mk_std_input_stream_private_type_e_mapping:
		{
			mk_try(mk_win_kernel_input_stream_read(&is->m_mix.m_mapping.m_win_is, data, len));
		}
		break;
	}

	return 0;
}
