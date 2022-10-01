#include "mk_win_user_message.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win/src/mk_win_api.h"
#include "../../mk_win/src/mk_win_unicode.h"

#include "../../mk_win_base/src/mk_win_base_user_types.h"
#include "../../mk_win_base/src/mk_win_base_user_functions.h"


mk_jumbo int mk_win_user_message_get(mk_win_base_user_types_msg_t* msg, mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg_min, mk_win_base_types_uint_t msg_max, mk_win_base_types_bool_t* ret)
{
	#if mk_win_api == mk_win_api_old
	#define GetMessageM GetMessage
	#elif mk_win_api == mk_win_api_ansi
	#define GetMessageM GetMessageA
	#elif mk_win_api == mk_win_api_wide
	#define GetMessageM GetMessageW
	#endif

	mk_win_base_types_bool_t b;
	#if mk_win_api != mk_win_api_both
	b = GetMessageM(msg, hwnd, msg_min, msg_max);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		b = GetMessageA(msg, hwnd, msg_min, msg_max);
	}
	else
	{
		b = GetMessageW(msg, hwnd, msg_min, msg_max);
	}
	#endif
	mk_assert(ret);
	*ret = b;

	return 0;

	#undef GetMessageM
}

mk_jumbo int mk_win_user_message_peek(mk_win_base_user_types_msg_t* msg, mk_win_base_user_types_hwnd_t hwnd, mk_win_base_types_uint_t msg_min, mk_win_base_types_uint_t msg_max, mk_win_base_types_uint_t remove, mk_win_base_types_bool_t* ret)
{
	#if mk_win_api == mk_win_api_old
	#define PeekMessageM PeekMessage
	#elif mk_win_api == mk_win_api_ansi
	#define PeekMessageM PeekMessageA
	#elif mk_win_api == mk_win_api_wide
	#define PeekMessageM PeekMessageW
	#endif

	mk_win_base_types_bool_t b;
	#if mk_win_api != mk_win_api_both
	b = PeekMessageM(msg, hwnd, msg_min, msg_max, remove);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		b = PeekMessageA(msg, hwnd, msg_min, msg_max, remove);
	}
	else
	{
		b = PeekMessageW(msg, hwnd, msg_min, msg_max, remove);
	}
	#endif
	mk_assert(ret);
	*ret = b;

	return 0;

	#undef PeekMessageM
}

mk_jumbo int mk_win_user_message_translate(mk_win_base_user_types_msg_t const* msg, mk_win_base_types_bool_t* ret)
{
	mk_win_base_types_bool_t b;

	mk_assert(msg);
	mk_assert(ret);

	b = TranslateMessage(msg);
	*ret = b;

	return 0;
}

mk_jumbo int mk_win_user_message_dispatch(mk_win_base_user_types_msg_t const* msg, mk_win_base_user_types_lresult_t* ret)
{
	#if mk_win_api == mk_win_api_old
	#define DispatchMessageM DispatchMessage
	#elif mk_win_api == mk_win_api_ansi
	#define DispatchMessageM DispatchMessageA
	#elif mk_win_api == mk_win_api_wide
	#define DispatchMessageM DispatchMessageW
	#endif

	mk_win_base_user_types_lresult_t lr;
	#if mk_win_api != mk_win_api_both
	lr = DispatchMessageM(msg);
	#else
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		lr = DispatchMessageA(msg);
	}
	else
	{
		lr = DispatchMessageW(msg);
	}
	#endif
	mk_assert(ret);
	*ret = lr;

	return 0;
	#undef DispatchMessageM
}

mk_jumbo int mk_win_user_message_translate_mdi_sys_accel(mk_win_base_user_types_hwnd_t mdi, mk_win_base_user_types_msg_t const* msg, mk_win_base_types_bool_t* ret)
{
	mk_win_base_types_bool_t b;

	mk_assert(mdi);
	mk_assert(msg);
	mk_assert(ret);

	b = TranslateMDISysAccel(mdi, msg);
	*ret = b;

	return 0;
}

mk_jumbo int mk_win_user_message_post_quit(int exit_code)
{
	PostQuitMessage(exit_code);

	return 0;
}
