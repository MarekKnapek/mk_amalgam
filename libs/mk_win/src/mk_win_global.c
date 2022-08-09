#include "mk_win_global.h"

#include "mk_win_unicode.h"
#include "mk_win_user_class.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"


mk_jumbo int mk_win_global_init(void)
{
	mk_try(mk_win_unicode_init());
	mk_try(mk_win_user_class_init());

	return 0;
}

mk_jumbo int mk_win_global_deinit(void)
{
	mk_try(mk_win_user_class_deinit());
	mk_try(mk_win_unicode_deinit());

	return 0;
}
