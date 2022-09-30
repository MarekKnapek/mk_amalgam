#ifndef mk_include_guard_win_kernel_mapping_view
#define mk_include_guard_win_kernel_mapping_view


#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_types.h"

#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


struct mk_win_kernel_mapping_view_s
{
	void* m_ptr;
};
mk_win_base_types_make_struct(mk_win_kernel_mapping_view);


mk_jumbo int mk_win_kernel_mapping_view_construct_ro(mk_win_kernel_mapping_view_pt view, mk_win_base_types_handle_t mapping, mk_uint64_t offset, size_t len);
mk_jumbo int mk_win_kernel_mapping_view_destruct(mk_win_kernel_mapping_view_pct view);
mk_jumbo int mk_win_kernel_mapping_view_get_ro(mk_win_kernel_mapping_view_pct view, void const** ret);


#endif
