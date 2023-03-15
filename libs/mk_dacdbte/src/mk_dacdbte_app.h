#ifndef mk_include_guard_dacdbte_app
#define mk_include_guard_dacdbte_app


#include "mk_dacdbte_forward.h"

#include "../../mk_std/src/mk_std_ptr_buff.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_dacdbte_app_s
{
	int m_exit_code;
	mk_std_ptr_buff_t m_parents;
};


mk_jumbo int mk_dacdbte_app_init(void);
mk_jumbo int mk_dacdbte_app_deinit(void);
mk_jumbo int mk_dacdbte_app_construct(mk_dacdbte_app_pt app);
mk_jumbo int mk_dacdbte_app_destruct(mk_dacdbte_app_pt app);
mk_jumbo int mk_dacdbte_app_get_exit_code(mk_dacdbte_app_pt app, int* exit_code);
mk_jumbo int mk_dacdbte_app_add_parent(mk_dacdbte_app_pt app);
mk_jumbo int mk_dacdbte_app_show_last_parent(mk_dacdbte_app_pt app, int show);
mk_jumbo int mk_dacdbte_app_run(mk_dacdbte_app_pt app);
mk_jumbo int mk_dacdbte_app_exit(mk_dacdbte_app_pt app);
mk_jumbo int mk_dacdbte_app_on_parent_destroy(mk_dacdbte_app_pt app, mk_dacdbte_parent_pt parent);


#endif
