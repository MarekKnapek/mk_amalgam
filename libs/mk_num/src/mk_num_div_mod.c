#include "mk_num_div_mod.h"


#include "mk_lang_llong.h"
#include "mk_lang_i128.h"


#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#define mk_num_div_mod_big_type unsigned long int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#define mk_num_div_mod_big_type unsigned long int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#define mk_num_div_mod_big_type unsigned long int
#include "mk_num_div_mod.inl.c"

#if mk_lang_llong_has != 0
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_mid_type unsigned long int
#define mk_num_div_mod_big_type unsigned long long int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_mid_type unsigned long int
#define mk_num_div_mod_big_type unsigned long long int
#include "mk_num_div_mod.inl.c"
#endif

#if mk_lang_i128_has != 0
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ulong
#define mk_num_div_mod_small_type unsigned long int
#define mk_num_div_mod_mid_type unsigned long long int
#define mk_num_div_mod_big_type unsigned __int128
#include "mk_num_div_mod.inl.c"
#endif


#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_mid_type unsigned short int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_mid_type unsigned long int
#include "mk_num_div_mod.inl.c"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_mid_type unsigned long int
#include "mk_num_div_mod.inl.c"

#if mk_lang_llong_has != 0
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ulong
#define mk_num_div_mod_small_type unsigned long int
#define mk_num_div_mod_mid_type unsigned long long int
#include "mk_num_div_mod.inl.c"
#endif
