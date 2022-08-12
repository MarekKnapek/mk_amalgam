#ifndef mk_include_guard_std_ptr_buff
#define mk_include_guard_std_ptr_buff


#include "mk_std_buffer.h"

#include "../../mk_utils/src/mk_jumbo.h"


#include <stddef.h>


struct mk_std_ptr_buff_s
{
	mk_std_buffer_t m_ptrs;
	size_t m_count;
};
typedef struct mk_std_ptr_buff_s mk_std_ptr_buff_t;


mk_jumbo int mk_std_ptr_buff_construct(mk_std_ptr_buff_t* ptr_buff);
mk_jumbo int mk_std_ptr_buff_destruct(mk_std_ptr_buff_t* ptr_buff);

mk_jumbo int mk_std_ptr_buff_get_count(mk_std_ptr_buff_t* ptr_buff, size_t* count);
mk_jumbo int mk_std_ptr_buff_get_element(mk_std_ptr_buff_t* ptr_buff, size_t idx, void** element);
mk_jumbo int mk_std_ptr_buff_reserve_one(mk_std_ptr_buff_t* ptr_buff);
mk_jumbo int mk_std_ptr_buff_reserve(mk_std_ptr_buff_t* ptr_buff, size_t count);
mk_jumbo int mk_std_ptr_buff_append(mk_std_ptr_buff_t* ptr_buff, void const* ptr);
mk_jumbo int mk_std_ptr_buff_find_first(mk_std_ptr_buff_t* ptr_buff, void const* ptr, size_t* idx);
mk_jumbo int mk_std_ptr_buff_remove_val(mk_std_ptr_buff_t* ptr_buff, void const* ptr);
mk_jumbo int mk_std_ptr_buff_remove_idx(mk_std_ptr_buff_t* ptr_buff, size_t idx);


#endif
