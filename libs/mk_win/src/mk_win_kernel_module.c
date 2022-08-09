#include "mk_win_kernel_module.h"

#include "mk_win_api.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win_base/src/mk_win_base_kernel_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_functions.h"


mk_jumbo int mk_win_kernel_module_get_module_handle(char const* module_name, mk_win_base_kernel_types_hmodule_t* module)
{
	#if mk_win_api == mk_win_api_old
	#define GetModuleHandleM GetModuleHandle
	#else
	#define GetModuleHandleM GetModuleHandleA
	#endif
	mk_win_base_kernel_types_hmodule_t m;
	mk_assert(module);
	m = GetModuleHandleM(module_name);
	*module = m;
	return 0;
	#undef GetModuleHandleM
}

mk_jumbo int mk_win_kernel_module_get_module_handle_user(mk_win_base_kernel_types_hmodule_t* module)
{
	#if mk_win_api == mk_win_api_old
	#define user_name "user"
	#else
	#define user_name "user32"
	#endif
	mk_try(mk_win_kernel_module_get_module_handle(user_name, module));
	return 0;
	#undef user_name
}

mk_jumbo int mk_win_kernel_module_get_proc_address(mk_win_base_kernel_types_hmodule_t module, char const* procedure_name, mk_win_base_kernel_types_farproc_t* proc)
{
	mk_win_base_kernel_types_farproc_t p;

	mk_assert(proc);

	p = GetProcAddress(module, procedure_name);
	*proc = p;

	return 0;
}
