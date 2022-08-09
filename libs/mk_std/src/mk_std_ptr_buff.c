#include "mk_std_ptr_buff.h"

#include "mk_std_buffer.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>
#include <string.h>


static mk_inline int mk_std_ptr_buff_private_get_data(mk_std_ptr_buff_t* ptr_buff, void*** data);


mk_jumbo int mk_std_ptr_buff_construct(mk_std_ptr_buff_t* ptr_buff)
{
	mk_assert(ptr_buff);

	mk_try(mk_std_buffer_init(&ptr_buff->m_ptrs));
	ptr_buff->m_count = 0;

	return 0;
}

mk_jumbo int mk_std_ptr_buff_destruct(mk_std_ptr_buff_t* ptr_buff)
{
	mk_assert(ptr_buff);

	mk_try(mk_std_buffer_deinit(&ptr_buff->m_ptrs));

	return 0;
}


mk_jumbo int mk_std_ptr_buff_get_count(mk_std_ptr_buff_t* ptr_buff, size_t* count)
{
	mk_assert(ptr_buff);
	mk_assert(count);

	*count = ptr_buff->m_count;

	return 0;
}

mk_jumbo int mk_std_ptr_buffer_get_element(mk_std_ptr_buff_t* ptr_buff, size_t idx, void** element)
{
	void** data;

	mk_assert(ptr_buff);
	mk_assert(idx < ptr_buff->m_count);
	mk_assert(element);

	mk_try(mk_std_ptr_buff_private_get_data(ptr_buff, &data));
	*element = data[idx];

	return 0;
}

mk_jumbo int mk_std_ptr_buff_reserve_one(mk_std_ptr_buff_t* ptr_buff)
{
	mk_assert(ptr_buff);

	mk_try(mk_std_ptr_buff_reserve(ptr_buff, ptr_buff->m_count + 1));

	return 0;
}

mk_jumbo int mk_std_ptr_buff_reserve(mk_std_ptr_buff_t* ptr_buff, size_t count)
{
	size_t needed;

	mk_assert(ptr_buff);

	needed = count * sizeof(void*);
	mk_try(mk_std_buffer_reserve(&ptr_buff->m_ptrs, needed));

	return 0;
}

mk_jumbo int mk_std_ptr_buff_append(mk_std_ptr_buff_t* ptr_buff, void const* ptr)
{
	void** ptrs;

	mk_assert(ptr_buff);

	mk_try(mk_std_ptr_buff_reserve(ptr_buff, ptr_buff->m_count + 1));
	mk_try(mk_std_ptr_buff_private_get_data(ptr_buff, &ptrs));
	ptrs[ptr_buff->m_count] = (void*)ptr;
	++ptr_buff->m_count;

	return 0;
}

mk_jumbo int mk_std_ptr_buff_find_first(mk_std_ptr_buff_t* ptr_buff, void const* ptr, size_t* idx)
{
	void** ptrs;
	size_t i;

	mk_assert(ptr_buff);
	mk_assert(idx);

	mk_try(mk_std_ptr_buff_private_get_data(ptr_buff, &ptrs));
	for(i = 0; i != ptr_buff->m_count; ++i)
	{
		if(ptrs[i] == ptr)
		{
			break;
		}
	}
	*idx = i;

	return 0;
}

mk_jumbo int mk_std_ptr_buff_remove_val(mk_std_ptr_buff_t* ptr_buff, void const* ptr)
{
	size_t idx;

	mk_assert(ptr_buff);

	mk_try(mk_std_ptr_buff_find_first(ptr_buff, ptr, &idx));
	mk_try(mk_std_ptr_buff_remove_idx(ptr_buff, idx));

	return 0;
}

mk_jumbo int mk_std_ptr_buff_remove_idx(mk_std_ptr_buff_t* ptr_buff, size_t idx)
{
	void** ptrs;

	mk_assert(ptr_buff);
	mk_assert(idx < ptr_buff->m_count);

	mk_try(mk_std_ptr_buff_private_get_data(ptr_buff, &ptrs));
	memmove(ptrs + idx, ptrs + (idx + 1), (ptr_buff->m_count - idx - 1) * sizeof(void*));
	--ptr_buff->m_count;

	return 0;
}


static mk_inline int mk_std_ptr_buff_private_get_data(mk_std_ptr_buff_t* ptr_buff, void*** data)
{
	void* mem;
	void** ptrs;

	mk_assert(ptr_buff);
	mk_assert(data);

	mk_try(mk_std_buffer_get_mem(&ptr_buff->m_ptrs, &mem));
	ptrs = (void**)mem;
	*data = ptrs;

	return 0;
}
