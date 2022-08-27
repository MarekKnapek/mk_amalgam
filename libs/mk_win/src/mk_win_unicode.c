#include "mk_win_unicode.h"

#include "mk_win_api.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_functions.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_assert.h"


#if mk_win_api == mk_win_api_both
static int mk_win_unicode_private_enabled;
#endif


mk_jumbo int mk_win_unicode_init(void)
{
	#if mk_win_api == mk_win_api_both
	mk_win_base_user_types_hicon_t icon;
	icon = LoadIconW(mk_win_base_types_null, mk_win_base_user_functions_make_int_resource_w(32512));
	mk_win_unicode_private_enabled = !!icon;
	#endif

	return 0;
}

mk_jumbo int mk_win_unicode_deinit(void)
{
	return 0;
}

mk_jumbo int mk_win_unicode_enabled(int* enabled)
{
	mk_assert(enabled);

	#if mk_win_api == mk_win_api_both
	*enabled = mk_win_unicode_private_enabled;
	#endif

	return 0;
}
