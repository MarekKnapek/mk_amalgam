#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"


#define mk_num_div_mod mk_lang_concat(mk_num_div_mod_, mk_num_div_mod_name)


mk_lang_jumbo void mk_num_div_mod(mk_num_div_mod_small_type const* x, mk_num_div_mod_small_type const* y, mk_num_div_mod_small_type* res_div, mk_num_div_mod_small_type* res_mod);


#undef mk_num_div_mod


#undef mk_num_div_mod_name
#undef mk_num_div_mod_small_type
