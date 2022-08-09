#include "mk_mdi_app.h"

#include "mk_mdi_parent.h"

#include "../../mk_std/src/mk_std_gcallocator.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include "../../mk_win/src/mk_win_user_message.h"

#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include <stddef.h>


static mk_inline int mk_mdi_app_private_message_process(mk_mdi_app_t* app, mk_win_base_user_types_msg_t const* msg);


mk_jumbo int mk_mdi_app_init(void)
{
	mk_try(mk_mdi_parent_init());

	return 0;
}

mk_jumbo int mk_mdi_app_deinit(void)
{
	mk_try(mk_mdi_parent_deinit());

	return 0;
}

mk_jumbo int mk_mdi_app_construct(mk_mdi_app_t* app)
{
	mk_assert(app);

	app->m_exit_code = 0;
	mk_try(mk_std_ptr_buff_construct(&app->m_parents));

	return 0;
}

mk_jumbo int mk_mdi_app_destruct(mk_mdi_app_t* app)
{
	mk_assert(app);

	mk_try(mk_std_ptr_buff_destruct(&app->m_parents));

	return 0;
}

mk_jumbo int mk_mdi_app_get_exit_code(mk_mdi_app_t* app, int* exit_code)
{
	mk_assert(app);
	mk_assert(exit_code);

	*exit_code = app->m_exit_code;

	return 0;
}

mk_jumbo int mk_mdi_app_add_parent(mk_mdi_app_t* app)
{
	mk_mdi_parent_pt parent;

	mk_assert(app);

	mk_try(mk_std_ptr_buff_reserve_one(&app->m_parents));
	mk_try(mk_std_gcallocator_allocate(sizeof(*parent), &parent));
	mk_try(mk_std_ptr_buff_append(&app->m_parents, parent));
	mk_try(mk_mdi_parent_construct(parent, app));

	return 0;
}

mk_jumbo int mk_mdi_app_show_last_parent(mk_mdi_app_t* app, int show)
{
	size_t count;
	mk_mdi_parent_pt parent;

	mk_assert(app);

	mk_try(mk_std_ptr_buff_get_count(&app->m_parents, &count));
	mk_assert(count != 0);
	mk_try(mk_std_ptr_buffer_get_element(&app->m_parents, count - 1, &parent));
	mk_try(mk_mdi_parent_show(parent, show));

	return 0;
}

mk_jumbo int mk_mdi_app_run(mk_mdi_app_t* app)
{
	mk_win_base_user_types_msg_t msg;
	mk_win_base_types_bool_t b;

	mk_assert(app);

	for(;;)
	{
		mk_try(mk_win_user_message_get(&msg, NULL, 0, 0, &b));
		if(b == 0)
		{
			mk_assert(msg.m_msg == mk_win_user_message_id_quit);
			app->m_exit_code = (int)msg.m_wparam;
			break;
		}
		mk_try(mk_mdi_app_private_message_process(app, &msg));
	}

	return 0;
}

mk_jumbo int mk_mdi_app_on_parent_destroy(mk_mdi_app_t* app, struct mk_mdi_parent_s* parent)
{
	size_t count;

	mk_assert(app);
	mk_assert(parent);

	mk_try(mk_std_ptr_buff_remove_val(&app->m_parents, parent));
	mk_try(mk_mdi_parent_destruct(parent));
	mk_try(mk_std_gcallocator_deallocate(parent));
	mk_try(mk_std_ptr_buff_get_count(&app->m_parents, &count));
	if(count == 0)
	{
		mk_try(mk_win_user_message_post_quit(0));
	}

	return 0;
}


static mk_inline int mk_mdi_app_private_message_process(mk_mdi_app_t* app, mk_win_base_user_types_msg_t const* msg)
{
	mk_win_base_types_bool_t translated;
	mk_win_base_user_types_lresult_t lres;

	mk_assert(app);
	mk_assert(msg);

	mk_try(mk_win_user_message_translate(msg, &translated));
	mk_try(mk_win_user_message_dispatch(msg, &lres));

	return 0;
}
