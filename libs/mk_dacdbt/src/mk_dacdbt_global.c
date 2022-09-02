#include "mk_dacdbt_global.h"

#include "mk_dacdbt_str.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"


mk_jumbo int mk_dacdbt_global_init(void)
{
	mk_try(mk_dacdbt_str_init());

	return 0;
}

mk_jumbo int mk_dacdbt_global_deinit(void)
{
	mk_try(mk_dacdbt_str_deinit());

	return 0;
}
