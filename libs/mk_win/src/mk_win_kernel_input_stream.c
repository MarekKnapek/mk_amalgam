#include "mk_win_kernel_input_stream.h"

#include "mk_win_char.h"
#include "mk_win_kernel_file.h"
#include "mk_win_kernel_mapping.h"
#include "mk_win_kernel_mapping_view.h"

#include "../../mk_win_base/src/mk_win_base_kernel_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_functions.h"

#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


mk_jumbo int mk_win_kernel_input_stream_construct(mk_win_kernel_input_stream_pt is, mk_win_strc_t file_name)
{
	static mk_uint64_t const s_zero = mk_uint64_c(0x00000000ul, 0x00000000ul);
	static mk_uint64_t const s_2mb = mk_uint64_c(0x00000000ul, 0x00200000ul);

	int err;
	mk_uint64_t len;

	mk_assert(is);
	mk_assert(file_name);
	mk_assert(*file_name);

	mk_try(mk_win_kernel_file_construct_existing_ro(file_name, &is->m_file));
	err = mk_win_kernel_file_get_length(is->m_file, &len);
	if(err) goto cleanup_file;
	if(mk_uint64_is_zero(&len)) goto cleanup_file;
	err = mk_win_kernel_mapping_construct_ro(is->m_file, s_zero, &is->m_mapping);
	if(err) goto cleanup_file;
	is->m_file_len = len;
	mk_uint64_zero(&is->m_file_pos);
	is->m_view_pos = 0;
	if(mk_uint64_gt(&len, &s_2mb)) len = s_2mb;
	err = mk_win_kernel_mapping_view_construct_ro(&is->m_view, is->m_mapping, is->m_file_pos, mk_uint64_to_sizet(&len));
	if(err) goto cleanup_mapping;

	return 0;

	cleanup_mapping:;
	mk_try(mk_win_kernel_mapping_destruct(is->m_mapping));
	cleanup_file:;
	mk_try(mk_win_kernel_file_destruct(is->m_file));
	return err;
}

mk_jumbo int mk_win_kernel_input_stream_destruct(mk_win_kernel_input_stream_pct is)
{
	mk_assert(is);

	mk_try(mk_win_kernel_mapping_view_destruct(&is->m_view));
	mk_try(mk_win_kernel_mapping_destruct(is->m_mapping));
	mk_try(mk_win_kernel_file_destruct(is->m_file));

	return 0;
}

mk_jumbo int mk_win_kernel_input_stream_get_remaining(mk_win_kernel_input_stream_pct is, mk_uint64_t* remaining)
{
	mk_uint64_t pos;

	mk_assert(is);
	mk_assert(remaining);

	mk_uint64_from_sizet(&pos, is->m_view_pos);
	mk_uint64_add(&pos, &pos, &is->m_file_pos);
	mk_assert(mk_uint64_le(&pos, &is->m_file_len));
	mk_uint64_sub(remaining, &is->m_file_len, &pos);

	return 0;
}

mk_jumbo int mk_win_kernel_input_stream_read(mk_win_kernel_input_stream_pt is, void const** data, size_t* len)
{
	#define mk_min(x, y) ((y) < (x) ? (y) : (x))

	static mk_uint64_t const s_2mb = mk_uint64_c(0x00000000ul, 0x00200000ul);

	mk_uint64_t requested;
	mk_uint64_t file_remaining;
	size_t view_remaining;
	void const* mem;

	mk_assert(is);
	mk_assert(data);
	mk_assert(len);

	mk_uint64_from_sizet(&requested, *len);
	mk_try(mk_win_kernel_input_stream_get_remaining(is, &file_remaining));
	mk_check(mk_uint64_le(&requested, &file_remaining));
	mk_assert(is->m_view_pos <= mk_uint64_to_sizet(&s_2mb));
	view_remaining = mk_uint64_to_sizet(&s_2mb) - is->m_view_pos;
	if(view_remaining == 0)
	{
		if(mk_uint64_gt(&file_remaining, &s_2mb)) file_remaining = s_2mb;
		mk_uint64_add(&is->m_file_pos, &is->m_file_pos, &s_2mb);
		mk_assert(mk_uint64_le(&is->m_file_pos, &is->m_file_len));
		is->m_view_pos = 0;
		mk_try(mk_win_kernel_mapping_view_destruct(&is->m_view));
		mk_try(mk_win_kernel_mapping_view_construct_ro(&is->m_view, is->m_mapping, is->m_file_pos, mk_uint64_to_sizet(&file_remaining)));
		view_remaining = mk_uint64_to_sizet(&file_remaining);
	}
	mk_try(mk_win_kernel_mapping_view_get_ro(&is->m_view, &mem));
	mem = ((void const*)(((unsigned char const*)(mem)) + is->m_view_pos));
	view_remaining = mk_min(view_remaining, *len);
	is->m_view_pos += view_remaining;
	mk_assert(is->m_view_pos <= mk_uint64_to_sizet(&s_2mb));
	*data = mem;
	*len = view_remaining;

	return 0;

	#undef mk_min
}
