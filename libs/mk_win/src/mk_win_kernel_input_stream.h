#ifndef mk_include_guard_win_kernel_input_stream
#define mk_include_guard_win_kernel_input_stream


#include "mk_win_char.h"
#include "mk_win_kernel_mapping_view.h"

#include "../../mk_win_base/src/mk_win_base_kernel_types.h"

#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


struct mk_win_kernel_input_stream_s
{
	mk_win_base_types_handle_t m_file;
	mk_win_base_types_handle_t m_mapping;
	mk_uint64_t m_file_len;
	mk_uint64_t m_file_pos;
	size_t m_view_pos;
	mk_win_kernel_mapping_view_t m_view;
};
mk_win_base_types_make_struct(mk_win_kernel_input_stream);


mk_jumbo int mk_win_kernel_input_stream_construct(mk_win_kernel_input_stream_pt is, mk_win_strc_t file_name);
mk_jumbo int mk_win_kernel_input_stream_destruct(mk_win_kernel_input_stream_pct is);
mk_jumbo int mk_win_kernel_input_stream_get_remaining(mk_win_kernel_input_stream_pct is, mk_uint64_t* remaining);
mk_jumbo int mk_win_kernel_input_stream_read(mk_win_kernel_input_stream_pt is, void const** data, size_t* len);


#endif
