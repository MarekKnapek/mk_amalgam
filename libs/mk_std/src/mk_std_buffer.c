#include "mk_std_buffer.h"

#include "mk_std_gcallocator.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_try.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


mk_jumbo int mk_std_buffer_init(struct mk_std_buffer_s* buffer)
{
	mk_assert(buffer);

	buffer->m_mem = NULL;
	buffer->m_size = 0;

	return 0;
}

mk_jumbo int mk_std_buffer_deinit(struct mk_std_buffer_s* buffer)
{
	mk_assert(buffer);

	mk_try(mk_std_gcallocator_deallocate(buffer->m_mem));

	return 0;
}

mk_jumbo int mk_std_buffer_get_mem(struct mk_std_buffer_s* buffer, void** mem)
{
	mk_assert(buffer);
	mk_assert(mem);

	*mem = buffer->m_mem;

	return 0;
}

mk_jumbo int mk_std_buffer_get_size(struct mk_std_buffer_s* buffer, size_t* size)
{
	mk_assert(buffer);
	mk_assert(size);

	*size = buffer->m_size;

	return 0;
}

mk_jumbo int mk_std_buffer_reserve(struct mk_std_buffer_s* buffer, size_t size)
{
	mk_assert(buffer);

	if(size > buffer->m_size)
	{
		mk_try(mk_std_gcallocator_reallocate(&buffer->m_mem, size));
		buffer->m_size = size;
	}

	return 0;
}
