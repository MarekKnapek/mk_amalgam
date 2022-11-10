#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"


#if(mk_num_div_mod_use_r1d2 == 0)
#define mk_num_div_mod_prefix r3d2
#elif(mk_num_div_mod_use_r1d2 == 1)
#define mk_num_div_mod_prefix r2d1
#endif

#define mk_num_div_mod mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_num_div_mod_, mk_num_div_mod_small_name), _), mk_num_div_mod_len_x), _), mk_num_div_mod_len_y), _), mk_num_div_mod_prefix)


mk_lang_jumbo void mk_num_div_mod(mk_num_div_mod_small_type const* x, mk_num_div_mod_small_type const* y, mk_num_div_mod_small_type* res_div, mk_num_div_mod_small_type* res_mod);


#undef mk_num_div_mod_prefix
#undef mk_num_div_mod


#undef mk_num_div_mod_len_x
#undef mk_num_div_mod_len_y
#undef mk_num_div_mod_use_r1d2
#undef mk_num_div_mod_small_name
#undef mk_num_div_mod_small_type
