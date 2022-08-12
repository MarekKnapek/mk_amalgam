#include "mk_mdi_global.h"

#include "mk_mdi_app.h"
#include "mk_mdi_parent.h"
#include "mk_mdi_child.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"


mk_jumbo int mk_mdi_global_init(void)
{
	mk_try(mk_mdi_app_init());
	mk_try(mk_mdi_parent_init());
	mk_try(mk_mdi_child_init());

	return 0;
}

mk_jumbo int mk_mdi_global_deinit(void)
{
	mk_try(mk_mdi_child_deinit());
	mk_try(mk_mdi_parent_deinit());
	mk_try(mk_mdi_app_deinit());

	return 0;
}
