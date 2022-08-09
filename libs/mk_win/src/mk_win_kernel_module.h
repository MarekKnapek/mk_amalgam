#ifndef mk_include_guard_win_kernel_module
#define mk_include_guard_win_kernel_module


#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_kernel_types.h"


mk_jumbo int mk_win_kernel_module_get_module_handle(char const* module_name, mk_win_base_kernel_types_hmodule_t* module);
mk_jumbo int mk_win_kernel_module_get_module_handle_user(mk_win_base_kernel_types_hmodule_t* module);
mk_jumbo int mk_win_kernel_module_get_proc_address(mk_win_base_kernel_types_hmodule_t module, char const* procedure_name, mk_win_base_kernel_types_farproc_t* proc);


#endif
