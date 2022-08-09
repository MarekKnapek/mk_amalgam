#ifndef mk_include_guard_win_instance
#define mk_include_guard_win_instance


#include "../../mk_win_base/src/mk_win_base_types.h"

#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo int mk_win_instance_init(mk_win_base_types_hinstance_t instance);
mk_jumbo int mk_win_instance_deinit(void);
mk_jumbo int mk_win_instance_get(mk_win_base_types_hinstance_t* instance);


#endif
