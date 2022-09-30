#ifndef mk_include_guard_std_input_stream
#define mk_include_guard_std_input_stream


#include "mk_std_buffer.h"

#include "../../mk_win/src/mk_win_char.h"
#include "../../mk_win/src/mk_win_kernel_input_stream.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>
#include <stdio.h>


struct mk_std_input_stream_private_file_s
{
	FILE* m_file;
	mk_std_buffer_t m_buffer;
};
typedef struct mk_std_input_stream_private_file_s mk_std_input_stream_private_file_t;

struct mk_std_input_stream_private_buffer_s
{
	void const* m_buffer;
	size_t m_len;
};
typedef struct mk_std_input_stream_private_buffer_s mk_std_input_stream_private_buffer_t;

struct mk_std_input_stream_private_mapping_s
{
	mk_win_kernel_input_stream_t m_win_is;
};
typedef struct mk_std_input_stream_private_mapping_s mk_std_input_stream_private_mapping_t;

union mk_std_input_stream_private_mix_u
{
	mk_std_input_stream_private_file_t m_file;
	mk_std_input_stream_private_buffer_t m_buffer;
	mk_std_input_stream_private_mapping_t m_mapping;
};
typedef union mk_std_input_stream_private_mix_u mk_std_input_stream_private_mix_t;

enum mk_std_input_stream_private_type_e
{
	mk_std_input_stream_private_type_e_file,
	mk_std_input_stream_private_type_e_buffer,
	mk_std_input_stream_private_type_e_mapping
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
mk_jumbo int mk_std_input_stream_construct_mapping(mk_std_input_stream_t* is, mk_win_strc_t file_name);
mk_jumbo int mk_std_input_stream_destruct(mk_std_input_stream_t* is);
mk_jumbo int mk_std_input_stream_read(mk_std_input_stream_t* is, void const** data, size_t* len);


#endif
