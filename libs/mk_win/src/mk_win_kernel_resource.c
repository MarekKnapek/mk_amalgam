#include "mk_win_kernel_resource.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_kernel_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_functions.h"


mk_jumbo int mk_win_kernel_resource_find(mk_win_base_kernel_types_hmodule_t module, mk_win_base_types_strac_t name, mk_win_base_types_strac_t type, mk_win_base_kernel_types_hrsrc_t* resource)
{
	#if mk_win_api == mk_win_api_old
	#define FindResourceM FindResource
	#else
	#define FindResourceM FindResourceA
	#endif

	mk_win_base_kernel_types_hrsrc_t r;

	mk_assert(resource);

	r = FindResourceM(module, name, type);
	*resource = r;

	return 0;

	#undef FindResourceM
}

mk_jumbo int mk_win_kernel_resource_find_bytypeid(mk_win_base_kernel_types_hmodule_t module, mk_win_base_types_strac_t name, mk_win_base_types_uint16_t type, mk_win_base_kernel_types_hrsrc_t* resource)
{
	#if mk_win_api == mk_win_api_old
	#define FindResourceM FindResource
	#else
	#define FindResourceM FindResourceA
	#endif

	mk_win_base_kernel_types_hrsrc_t r;

	mk_assert(resource);

	r = FindResourceM(module, name, (mk_win_base_types_strac_t)(mk_win_base_types_uintptr_t)type);
	*resource = r;

	return 0;

	#undef FindResourceM
}

mk_jumbo int mk_win_kernel_resource_load(mk_win_base_kernel_types_hmodule_t module, mk_win_base_kernel_types_hrsrc_t resource, mk_win_base_kernel_types_hglobal_t* global)
{
	mk_win_base_kernel_types_hglobal_t g;

	mk_assert(global);

	g = LoadResource(module, resource);
	*global = g;

	return 0;
}

mk_jumbo int mk_win_kernel_resource_lock(mk_win_base_kernel_types_hglobal_t global, mk_win_base_types_void_t* data)
{
	mk_win_base_types_void_t d;

	mk_assert(data);

	d = LockResource(global);
	*data = d;

	return 0;
}
