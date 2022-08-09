#include "mk_std_global.h"

#include "mk_std_str_convertor.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"


mk_jumbo int mk_std_global_init(void)
{
	mk_try(mk_std_str_convertor_init());

	return 0;
}

mk_jumbo int mk_std_global_deinit(void)
{
	mk_try(mk_std_str_convertor_deinit());

	return 0;
}
