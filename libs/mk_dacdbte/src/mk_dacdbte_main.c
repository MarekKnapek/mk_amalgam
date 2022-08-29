#include "../../mk_std/src/mk_std_global.h"

#include "mk_dacdbte_app.h"
#include "mk_dacdbte_global.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win/src/mk_win_global.h"
#include "../../mk_win/src/mk_win_instance.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_types.h"


int mk_win_base_keywords_calling_convention_api WinMain(mk_win_base_types_hinstance_t current, mk_win_base_types_hinstance_t previous, mk_win_base_types_char_lpct cmd_line, int cmd_show)
{
	mk_dacdbte_app_t app;
	int exit_code;

	(void)cmd_line;
	(void)cmd_show;

	mk_try(mk_std_global_init());
	mk_try(mk_win_global_init());
	mk_try(mk_win_instance_init(current ? current : previous));
	mk_try(mk_dacdbte_global_init());
	mk_try(mk_dacdbte_app_construct(&app));

	mk_try(mk_dacdbte_app_add_parent(&app));
	mk_try(mk_dacdbte_app_show_last_parent(&app, cmd_show));
	mk_try(mk_dacdbte_app_run(&app));
	mk_try(mk_dacdbte_app_get_exit_code(&app, &exit_code));

	mk_try(mk_dacdbte_app_destruct(&app));
	mk_try(mk_dacdbte_global_deinit());
	mk_try(mk_win_instance_deinit());
	mk_try(mk_win_global_deinit());
	mk_try(mk_std_global_deinit());

	return exit_code;
}
