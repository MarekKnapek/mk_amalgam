#include "mk_win_instance.h"

#include "../../mk_win_base/src/mk_win_base_types.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"


static mk_win_base_types_hinstance_t mk_win_instance_private_instance;


mk_jumbo int mk_win_instance_init(mk_win_base_types_hinstance_t instance)
{
	mk_assert(instance);

	mk_win_instance_private_instance = instance;

	return 0;
}

mk_jumbo int mk_win_instance_deinit(void)
{
	return 0;
}

mk_jumbo int mk_win_instance_get(mk_win_base_types_hinstance_t* instance)
{
	mk_assert(instance);

	*instance = mk_win_instance_private_instance;

	return 0;
}
