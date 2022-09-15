#include "mk_dacdbte_app.h"

#include "mk_dacdbte_parent.h"

#include "../../mk_std/src/mk_std_gcallocator.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win/src/mk_win_user_message.h"
#include "../../mk_win/src/mk_win_user_window.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include <stddef.h>


static mk_inline int mk_dacdbte_app_private_message_process(mk_dacdbte_app_pt app, mk_win_base_user_types_msg_t const* msg);


mk_jumbo int mk_dacdbte_app_init(void)
{
	return 0;
}

mk_jumbo int mk_dacdbte_app_deinit(void)
{
	return 0;
}

mk_jumbo int mk_dacdbte_app_construct(mk_dacdbte_app_pt app)
{
	mk_assert(app);

	app->m_exit_code = 0;
	mk_try(mk_std_ptr_buff_construct(&app->m_parents));

	return 0;
}

mk_jumbo int mk_dacdbte_app_destruct(mk_dacdbte_app_pt app)
{
	mk_assert(app);

	mk_try(mk_std_ptr_buff_destruct(&app->m_parents));

	return 0;
}

mk_jumbo int mk_dacdbte_app_get_exit_code(mk_dacdbte_app_pt app, int* exit_code)
{
	mk_assert(app);
	mk_assert(exit_code);

	*exit_code = app->m_exit_code;

	return 0;
}

mk_jumbo int mk_dacdbte_app_add_parent(mk_dacdbte_app_pt app)
{
	mk_dacdbte_parent_pt parent;

	mk_assert(app);

	mk_try(mk_std_gcallocator_allocate(sizeof(*parent), (void**)&parent));
	mk_try(mk_std_ptr_buff_append(&app->m_parents, parent));
	mk_try(mk_dacdbte_parent_construct(parent, app));

	return 0;
}

mk_jumbo int mk_dacdbte_app_show_last_parent(mk_dacdbte_app_pt app, int show)
{
	size_t count;
	mk_dacdbte_parent_pt parent;

	mk_assert(app);

	mk_try(mk_std_ptr_buff_get_count(&app->m_parents, &count));
	mk_assert(count != 0);
	mk_try(mk_std_ptr_buff_get_element(&app->m_parents, count - 1, (void**)&parent));
	mk_try(mk_dacdbte_parent_show(parent, show));

	return 0;
}

mk_jumbo int mk_dacdbte_app_run(mk_dacdbte_app_pt app)
{
	mk_win_base_user_types_msg_t msg;
	mk_win_base_types_bool_t b;

	mk_assert(app);

	for(;;)
	{
		mk_try(mk_win_user_message_get(&msg, mk_win_base_types_null, 0, 0, &b));
		if(b == 0)
		{
			mk_assert(msg.m_msg == mk_win_user_window_wm_quit);
			app->m_exit_code = (int)msg.m_wparam;
			break;
		}
		mk_try(mk_dacdbte_app_private_message_process(app, &msg));
	}

	return 0;
}

mk_jumbo int mk_dacdbte_app_exit(mk_dacdbte_app_pt app)
{
	int bad;
	size_t count;
	size_t i;
	mk_dacdbte_parent_pt parent;
	mk_win_base_user_types_lresult_t lr;
	mk_win_base_types_bool_t b;

	mk_assert(app);

	bad = 0;
	mk_try(mk_std_ptr_buff_get_count(&app->m_parents, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&app->m_parents, i, (void**)&parent));
		mk_try(mk_win_user_window_send(parent->m_hwnd, mk_win_user_window_wm_queryendsession, 0, 0, &lr));
		if(lr == 0)
		{
			++bad;
			break;
		}
	}
	if(bad == 0)
	{
		for(i = 0; i != count; ++i)
		{
			mk_try(mk_std_ptr_buff_get_element(&app->m_parents, i, (void**)&parent));
			mk_try(mk_win_user_window_show(parent->m_hwnd, mk_win_user_window_show_hide, &b));
		}
		
	}
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&app->m_parents, count - 1 - i, (void**)&parent));
		mk_try(mk_dacdbte_parent_close(parent));
	}

	return 0;
}

mk_jumbo int mk_dacdbte_app_on_parent_destroy(mk_dacdbte_app_pt app, mk_dacdbte_parent_pt parent)
{
	size_t count;

	mk_assert(app);
	mk_assert(parent);

	mk_try(mk_std_ptr_buff_remove_val(&app->m_parents, parent));
	mk_try(mk_dacdbte_parent_destruct(parent));
	mk_try(mk_std_gcallocator_deallocate(parent));
	mk_try(mk_std_ptr_buff_get_count(&app->m_parents, &count));
	if(count == 0)
	{
		mk_try(mk_win_user_message_post_quit(0));
	}

	return 0;
}


static mk_inline int mk_dacdbte_app_private_message_process(mk_dacdbte_app_pt app, mk_win_base_user_types_msg_t const* msg)
{
	mk_win_base_types_bool_t mdi_translated;
	size_t count;
	size_t i;
	mk_dacdbte_parent_pt parent;
	mk_win_base_types_bool_t is_child;
	mk_win_base_types_bool_t translated;
	mk_win_base_user_types_lresult_t lres;

	mk_assert(app);
	mk_assert(msg);

	mdi_translated = 0;
	mk_try(mk_std_ptr_buff_get_count(&app->m_parents, &count));
	for(i = 0; i != count; ++i)
	{
		mk_try(mk_std_ptr_buff_get_element(&app->m_parents, i, (void**)&parent));
		mk_try(mk_win_user_window_is_child(parent->m_hwnd, msg->m_hwnd, &is_child));
		if(is_child != 0)
		{
			mk_try(mk_win_user_message_translate_mdi_sys_accel(parent->m_mdi, msg, &mdi_translated));
			break;
		}
	}
	if(mdi_translated == 0)
	{
		mk_try(mk_win_user_message_translate(msg, &translated));
		mk_try(mk_win_user_message_dispatch(msg, &lres));
	}

	return 0;
}
