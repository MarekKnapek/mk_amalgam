#ifndef mk_include_guard_std_buffer
#define mk_include_guard_std_buffer


#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


struct mk_std_buffer_s
{
	void* m_mem;
	size_t m_size;
};
typedef struct mk_std_buffer_s mk_std_buffer_t;


mk_jumbo int mk_std_buffer_init(struct mk_std_buffer_s* buffer);
mk_jumbo int mk_std_buffer_deinit(struct mk_std_buffer_s* buffer);
mk_jumbo int mk_std_buffer_get_mem(struct mk_std_buffer_s* buffer, void** mem);
mk_jumbo int mk_std_buffer_get_size(struct mk_std_buffer_s const* buffer, size_t* size);
mk_jumbo int mk_std_buffer_reserve(struct mk_std_buffer_s* buffer, size_t size);


#endif
