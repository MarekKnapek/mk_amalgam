#include "mk_win_user_dialog.h"

#include "mk_win_unicode.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_user_functions.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"


mk_jumbo int mk_win_user_dialog_indirect_param(mk_win_base_types_hinstance_t instance, mk_win_base_kernel_types_hglobal_t dlg_template, mk_win_base_user_types_hwnd_t parent, mk_win_base_user_types_dlgproc_t dlg_proc, mk_win_base_user_types_lparam_t param, mk_win_base_types_cpu_iword_t* ret)
{
	#if mk_win_api == mk_win_api_old
	#define DialogBoxIndirectParamM DialogBoxIndirectParam
	#elif mk_win_api == mk_win_api_ansi
	#define DialogBoxIndirectParamM DialogBoxIndirectParamA
	#elif mk_win_api == mk_win_api_wide
	#define DialogBoxIndirectParamM DialogBoxIndirectParamW
	#endif
	mk_win_base_types_cpu_iword_t num;
	#if mk_win_api != mk_win_api_both
	num = DialogBoxIndirectParamM(instance, dlg_template, parent, dlg_proc, param);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		num = DialogBoxIndirectParamA(instance, dlg_template, parent, dlg_proc, param);
	}
	else
	{
		num = DialogBoxIndirectParamW(instance, dlg_template, parent, dlg_proc, param);
	}
	#endif
	mk_assert(ret);
	*ret = num;
	return 0;
	#undef DialogBoxIndirectParamM
}

mk_jumbo int mk_win_user_dialog_get_item(mk_win_base_user_types_hwnd_t dialog, int item_id, mk_win_base_user_types_hwnd_t* item)
{
	mk_win_base_user_types_hwnd_t i;

	mk_assert(item);

	i = GetDlgItem(dialog, item_id);
	*item = i;

	return 0;
}

mk_jumbo int mk_win_user_dialog_end(mk_win_base_user_types_hwnd_t dialog, mk_win_base_types_cpu_iword_t result, mk_win_base_types_bool_t* ret)
{
	mk_win_base_types_bool_t b;

	mk_assert(ret);

	#if mk_win_api == mk_win_api_old
	EndDialog(dialog, result);
	b = 1;
	#else
	b = EndDialog(dialog, result);
	#endif
	*ret = b;

	return 0;
}
