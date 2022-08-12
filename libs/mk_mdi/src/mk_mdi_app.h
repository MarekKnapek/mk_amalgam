#ifndef mk_include_guard_mdi_app
#define mk_include_guard_mdi_app


#include "../../mk_std/src/mk_std_ptr_buff.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_mdi_app_s;
typedef struct mk_mdi_app_s mk_mdi_app_t;
typedef mk_mdi_app_t* mk_mdi_app_pt;

struct mk_mdi_parent_s;
typedef struct mk_mdi_parent_s mk_mdi_parent_t;
typedef mk_mdi_parent_t* mk_mdi_parent_pt;

struct mk_mdi_child_s;
typedef struct mk_mdi_child_s mk_mdi_child_t;
typedef mk_mdi_child_t* mk_mdi_child_pt;


struct mk_mdi_app_s
{
	int m_exit_code;
	mk_std_ptr_buff_t m_parents;
};
typedef struct mk_mdi_app_s mk_mdi_app_t;


mk_jumbo int mk_mdi_app_init(void);
mk_jumbo int mk_mdi_app_deinit(void);
mk_jumbo int mk_mdi_app_construct(mk_mdi_app_pt app);
mk_jumbo int mk_mdi_app_destruct(mk_mdi_app_pt app);
mk_jumbo int mk_mdi_app_get_exit_code(mk_mdi_app_pt app, int* exit_code);
mk_jumbo int mk_mdi_app_add_parent(mk_mdi_app_pt app);
mk_jumbo int mk_mdi_app_show_last_parent(mk_mdi_app_pt app, int show);
mk_jumbo int mk_mdi_app_run(mk_mdi_app_pt app);
mk_jumbo int mk_mdi_app_on_parent_destroy(mk_mdi_app_pt app, mk_mdi_parent_pt parent);


#endif
