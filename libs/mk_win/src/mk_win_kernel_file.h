#ifndef mk_include_guard_win_kernel_file
#define mk_include_guard_win_kernel_file


#include "mk_win_char.h"

#include "../../mk_win_base/src/mk_win_base_kernel_types.h"

#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo int mk_win_kernel_file_construct_existing_ro(mk_win_strc_t name, mk_win_base_types_handle_t* ret);
mk_jumbo int mk_win_kernel_file_destruct(mk_win_base_types_handle_t file);
mk_jumbo int mk_win_kernel_file_get_length(mk_win_base_types_handle_t file, mk_uint64_t* ret);


#endif
