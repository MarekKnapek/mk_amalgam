#include "mk_dacdbte_global.h"

#include "mk_dacdbte_app.h"
#include "mk_dacdbte_parent.h"
#include "mk_dacdbte_child.h"

#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"


mk_jumbo int mk_dacdbte_global_init(void)
{
	mk_try(mk_dacdbte_app_init());
	mk_try(mk_dacdbte_parent_init());
	mk_try(mk_dacdbte_child_init());

	return 0;
}

mk_jumbo int mk_dacdbte_global_deinit(void)
{
	mk_try(mk_dacdbte_child_deinit());
	mk_try(mk_dacdbte_parent_deinit());
	mk_try(mk_dacdbte_app_deinit());

	return 0;
}
