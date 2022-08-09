#ifndef mk_include_guard_mdi_parent
#define mk_include_guard_mdi_parent


#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"


struct mk_mdi_app_s;


struct mk_mdi_parent_s
{
	struct mk_mdi_app_s* m_app;
	mk_win_base_user_types_hwnd_t m_hwnd;
};
typedef struct mk_mdi_parent_s mk_mdi_parent_t;
typedef mk_mdi_parent_t* mk_mdi_parent_pt;
typedef mk_mdi_parent_t mk_win_base_keywords_far* mk_mdi_parent_lpt;


mk_jumbo int mk_mdi_parent_init(void);
mk_jumbo int mk_mdi_parent_deinit(void);
mk_jumbo int mk_mdi_parent_construct(mk_mdi_parent_pt parent, struct mk_mdi_app_s* app);
mk_jumbo int mk_mdi_parent_destruct(mk_mdi_parent_pt parent);
mk_jumbo int mk_mdi_parent_show(mk_mdi_parent_pt parent, int show);
mk_jumbo int mk_mdi_parent_close(mk_mdi_parent_pt parent);


#endif
