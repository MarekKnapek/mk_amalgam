#include "mk_win_comctl.h"

#include "../../mk_win_base/src/mk_win_base_comctl_functions.h"

#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo int mk_win_comctl_init(void)
{
	InitCommonControls();

	return 0;
}
