#include "mk_std_str_convertor.h"

#include "mk_std_buffer.h"

#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


#define mk_std_str_convertor_private_idx_max 8


static struct mk_std_buffer_s mk_std_str_convertor_private_buffers[mk_std_str_convertor_private_idx_max];


static mk_inline int mk_std_str_convertor_private_is_ascii(wchar_t chr);


mk_jumbo int mk_std_str_convertor_init(void)
{
	int i;

	for(i = 0; i != mk_std_str_convertor_private_idx_max; ++i)
	{
		mk_try(mk_std_buffer_init(&mk_std_str_convertor_private_buffers[i]));
		mk_try(mk_std_buffer_reserve(&mk_std_str_convertor_private_buffers[i], 1));
	}

	return 0;
}

mk_jumbo int mk_std_str_convertor_deinit(void)
{
	int i;

	for(i = 0; i != mk_std_str_convertor_private_idx_max; ++i)
	{
		mk_try(mk_std_buffer_deinit(&mk_std_str_convertor_private_buffers[i]));
	}

	return 0;
}


mk_jumbo int mk_std_str_convertor_is_ascii_z(wchar_t const* str, int* is_ascii)
{
	size_t len;
	wchar_t const* in;

	mk_assert(str);

	len = 0;
	in = str;
	while(*in++) ++len;
	mk_try(mk_std_str_convertor_is_ascii_s(str, len, is_ascii));

	return 0;
}

mk_jumbo int mk_std_str_convertor_is_ascii_s(wchar_t const* str, size_t len, int* is_ascii)
{
	size_t i;

	mk_assert(str);
	mk_assert(is_ascii);

	for(i = 0; i != len; ++i)
	{
		if(!mk_std_str_convertor_private_is_ascii(str[i]))
		{
			break;
		}
	}
	*is_ascii = i == len;

	return 0;
}


mk_jumbo int mk_std_str_convertor_narrow_to_narrow_z(char const mk_win_base_keywords_far* in, int idx, char const**  out)
{
	size_t len;
	char const mk_win_base_keywords_far* str;

	mk_assert(out);
	mk_assert(idx >= 0 && idx < mk_std_str_convertor_private_idx_max);

	if(in)
	{
		len = 0;
		str = in;
		while(*str++) ++len;
		mk_try(mk_std_str_convertor_narrow_to_narrow_s(in, len + 1, idx, out));
	}
	else
	{
		*out = NULL;
	}

	return 0;
}

mk_jumbo int mk_std_str_convertor_wide_to_narrow_z(wchar_t const* in, int idx, char const**  out)
{
	size_t len;
	wchar_t const* str;

	mk_assert(out);
	mk_assert(idx >= 0 && idx < mk_std_str_convertor_private_idx_max);

	if(in)
	{
		len = 0;
		str = in;
		while(*str++) ++len;
		mk_try(mk_std_str_convertor_wide_to_narrow_s(in, len + 1, idx, out));
	}
	else
	{
		*out = NULL;
	}

	return 0;
}

mk_jumbo int mk_std_str_convertor_narrow_to_wide_z(char const* in, int idx, wchar_t const**  out)
{
	size_t len;
	char const* str;

	mk_assert(out);
	mk_assert(idx >= 0 && idx < mk_std_str_convertor_private_idx_max);

	if(in)
	{
		len = 0;
		str = in;
		while(*str++) ++len;
		mk_try(mk_std_str_convertor_narrow_to_wide_s(in, len + 1, idx, out));
	}
	else
	{
		*out = NULL;
	}

	return 0;
}


mk_jumbo int mk_std_str_convertor_narrow_to_narrow_zz(char const mk_win_base_keywords_far* in, int idx, char const**  out)
{
	size_t len;
	char const mk_win_base_keywords_far* str;

	mk_assert(out);
	mk_assert(idx >= 0 && idx < mk_std_str_convertor_private_idx_max);

	if(in)
	{
		len = 0;
		str = in;
		while(str[0] || str[1]) ++str, ++len;
		mk_try(mk_std_str_convertor_narrow_to_narrow_s(in, len + 2, idx, out));
	}
	else
	{
		*out = NULL;
	}

	return 0;
}

mk_jumbo int mk_std_str_convertor_wide_to_narrow_zz(wchar_t const* in, int idx, char const**  out)
{
	size_t len;
	wchar_t const* str;

	mk_assert(out);
	mk_assert(idx >= 0 && idx < mk_std_str_convertor_private_idx_max);

	if(in)
	{
		len = 0;
		str = in;
		while(str[0] || str[1]) ++str, ++len;
		mk_try(mk_std_str_convertor_wide_to_narrow_s(in, len + 2, idx, out));
	}
	else
	{
		*out = NULL;
	}

	return 0;
}

mk_jumbo int mk_std_str_convertor_narrow_to_wide_zz(char const* in, int idx, wchar_t const**  out)
{
	size_t len;
	char const* str;

	mk_assert(out);
	mk_assert(idx >= 0 && idx < mk_std_str_convertor_private_idx_max);

	if(in)
	{
		len = 0;
		str = in;
		while(str[0] || str[1]) ++str, ++len;
		mk_try(mk_std_str_convertor_narrow_to_wide_s(in, len + 2, idx, out));
	}
	else
	{
		*out = NULL;
	}

	return 0;
}


mk_jumbo int mk_std_str_convertor_narrow_to_narrow_s(char const mk_win_base_keywords_far* in, size_t len, int idx, char const**  out)
{
	size_t needed;
	void* mem;
	char* str;
	size_t i;

	mk_assert(out);
	mk_assert(idx >= 0 && idx < mk_std_str_convertor_private_idx_max);

	needed = len * sizeof(char);
	mk_try(mk_std_buffer_reserve(&mk_std_str_convertor_private_buffers[idx], needed));
	mk_try(mk_std_buffer_get_mem(&mk_std_str_convertor_private_buffers[idx], &mem));
	str = (char*)mem;
	for(i = 0; i != len; ++i)
	{
		str[i] = (char)(in[i]);
	}
	*out = str;

	return 0;
}

mk_jumbo int mk_std_str_convertor_wide_to_narrow_s(wchar_t const* in, size_t len, int idx, char const**  out)
{
	size_t needed;
	void* mem;
	char* str;
	size_t i;

	mk_assert(out);
	mk_assert(idx >= 0 && idx < mk_std_str_convertor_private_idx_max);

	needed = len * sizeof(char);
	mk_try(mk_std_buffer_reserve(&mk_std_str_convertor_private_buffers[idx], needed));
	mk_try(mk_std_buffer_get_mem(&mk_std_str_convertor_private_buffers[idx], &mem));
	str = (char*)mem;
	for(i = 0; i != len; ++i)
	{
		str[i] = (char)(in[i]);
	}
	*out = str;

	return 0;
}

mk_jumbo int mk_std_str_convertor_narrow_to_wide_s(char const* in, size_t len, int idx, wchar_t const**  out)
{
	size_t needed;
	void* mem;
	wchar_t* str;
	size_t i;

	mk_assert(out);
	mk_assert(idx >= 0 && idx < mk_std_str_convertor_private_idx_max);

	needed = len * sizeof(wchar_t);
	mk_try(mk_std_buffer_reserve(&mk_std_str_convertor_private_buffers[idx], needed));
	mk_try(mk_std_buffer_get_mem(&mk_std_str_convertor_private_buffers[idx], &mem));
	str = (wchar_t*)mem;
	for(i = 0; i != len; ++i)
	{
		str[i] = (wchar_t)(in[i]);
	}
	*out = str;

	return 0;
}


static mk_inline int mk_std_str_convertor_private_is_ascii(wchar_t chr)
{
	return chr >= 0x20 && chr <= 0x7e;
}
