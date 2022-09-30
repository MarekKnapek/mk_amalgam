#ifndef mk_include_guard_win_kernel_mapping
#define mk_include_guard_win_kernel_mapping


#include "../../mk_win_base/src/mk_win_base_kernel_types.h"

#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo int mk_win_kernel_mapping_construct_ro(mk_win_base_types_handle_t file, mk_uint64_t max_len, mk_win_base_types_handle_t* ret);
mk_jumbo int mk_win_kernel_mapping_destruct(mk_win_base_types_handle_t mapping);


#endif
