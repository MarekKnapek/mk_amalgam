#ifndef mk_include_guard_std_input_stream
#define mk_include_guard_std_input_stream


#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>
#include <stdio.h>


struct mk_std_input_stream_private_file_s
{
	FILE* m_file;
};
typedef struct mk_std_input_stream_private_file_s mk_std_input_stream_private_file_t;

struct mk_std_input_stream_private_buffer_s
{
	void const* m_buffer;
	size_t m_len;
};
typedef struct mk_std_input_stream_private_buffer_s mk_std_input_stream_private_buffer_t;

union mk_std_input_stream_private_mix_u
{
	mk_std_input_stream_private_file_t m_file;
	mk_std_input_stream_private_buffer_t m_buffer;
};
typedef union mk_std_input_stream_private_mix_u mk_std_input_stream_private_mix_t;

enum mk_std_input_stream_private_type_e
{
	mk_std_input_stream_private_type_e_file,
	mk_std_input_stream_private_type_e_buffer
};
typedef enum mk_std_input_stream_private_type_e mk_std_input_stream_private_type_t;


struct mk_std_input_stream_s
{
	mk_std_input_stream_private_type_t m_type;
	mk_std_input_stream_private_mix_t m_mix;
};
typedef struct mk_std_input_stream_s mk_std_input_stream_t;


mk_jumbo int mk_std_input_stream_construct_file(mk_std_input_stream_t* is, FILE* file);
mk_jumbo int mk_std_input_stream_construct_buffer(mk_std_input_stream_t* is, void const* buffer, size_t len);
mk_jumbo int mk_std_input_stream_destruct(mk_std_input_stream_t* is);
mk_jumbo int mk_std_input_stream_read(mk_std_input_stream_t* is, void* dst, size_t len, size_t* read);


#endif
