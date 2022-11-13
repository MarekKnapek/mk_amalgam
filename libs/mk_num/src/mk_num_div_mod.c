#include "mk_num_div_mod.h"


#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"


#define mk_num_div_mod_name uchar_4_4_r3d2
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_mid_type unsigned short int
#define mk_num_div_mod_big_type unsigned long int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_name uchar_8_8_r3d2
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_mid_type unsigned short int
#define mk_num_div_mod_big_type unsigned long int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_name uchar_16_16_r3d2
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_mid_type unsigned short int
#define mk_num_div_mod_big_type unsigned long int
#include "mk_num_div_mod.inl.c"

#if mk_lang_llong_has != 0
#define mk_num_div_mod_name ushort_4_4_r3d2
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_mid_type unsigned long int
#define mk_num_div_mod_big_type mk_lang_ullong_t
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_name ushort_8_8_r3d2
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_mid_type unsigned long int
#define mk_num_div_mod_big_type mk_lang_ullong_t
#include "mk_num_div_mod.inl.c"
#endif

#if mk_lang_lllong_has != 0
#define mk_num_div_mod_name ulong_4_4_r3d2
#define mk_num_div_mod_small_type unsigned long int
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_mid_type mk_lang_ullong_t
#define mk_num_div_mod_big_type mk_lang_ulllong_t
#include "mk_num_div_mod.inl.c"
#endif


#define mk_num_div_mod_name uchar_4_4_r2d1
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_mid_type unsigned short int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_name uchar_8_8_r2d1
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_mid_type unsigned short int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_name uchar_16_16_r2d1
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_mid_type unsigned short int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_name ushort_4_4_r2d1
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_mid_type unsigned long int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_name ushort_8_8_r2d1
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_mid_type unsigned long int
#include "mk_num_div_mod.inl.c"

#if mk_lang_llong_has != 0
#define mk_num_div_mod_name ulong_4_4_r2d1
#define mk_num_div_mod_small_type unsigned long int
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_mid_type mk_lang_ullong_t
#include "mk_num_div_mod.inl.c"
#endif

#if mk_lang_lllong_has != 0
#define mk_num_div_mod_name ullong_2_2_r2d1
#define mk_num_div_mod_small_type mk_lang_ullong_t
#define mk_num_div_mod_len_x 2
#define mk_num_div_mod_len_y 2
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_mid_type mk_lang_ulllong_t
#include "mk_num_div_mod.inl.c"
#endif
