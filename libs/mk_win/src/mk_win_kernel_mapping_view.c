#include "mk_win_kernel_mapping_view.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_functions.h"

#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


#define mk_win_kernel_mapping_view_write ((unsigned short int)(0x0002ul))
#define mk_win_kernel_mapping_view_read  ((unsigned short int)(0x0004ul))


mk_jumbo int mk_win_kernel_mapping_view_construct_ro(mk_win_kernel_mapping_view_pt view, mk_win_base_types_handle_t mapping, mk_uint64_t offset, size_t len)
{
	unsigned long offset_lo;
	unsigned long offset_hi;
	mk_win_base_types_void_lpct ptr;

	mk_assert(view);
	mk_assert(mapping);
	mk_assert(len);
	mk_assert(sizeof(mk_win_base_types_void_lpct) == sizeof(void const*));

	offset_lo = mk_uint64_to_long(&offset);
	mk_uint64_shr(&offset, &offset, 32);
	offset_hi = mk_uint64_to_long(&offset);
	ptr = MapViewOfFile(mapping, ((mk_win_base_types_dword_t)(mk_win_kernel_mapping_view_read)), ((mk_win_base_types_dword_t)(offset_hi)), ((mk_win_base_types_dword_t)(offset_lo)), ((mk_win_base_types_uintptr_t)(len)));
	mk_check(ptr);
	view->m_ptr = ((void*)(ptr));

	return 0;
}

mk_jumbo int mk_win_kernel_mapping_view_destruct(mk_win_kernel_mapping_view_pct view)
{
	mk_win_base_types_bool_t b;

	mk_assert(view);

	b = UnmapViewOfFile(view->m_ptr);
	mk_check(b != 0);

	return 0;
}

mk_jumbo int mk_win_kernel_mapping_view_get_ro(mk_win_kernel_mapping_view_pct view, void const** ret)
{
	mk_assert(view);
	mk_assert(ret);

	*ret = view->m_ptr;

	return 0;
}
