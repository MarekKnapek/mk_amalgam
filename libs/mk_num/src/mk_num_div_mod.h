#ifndef mk_detail_include_guard_num_div_mod
#define mk_detail_include_guard_num_div_mod


#include "mk_lang_llong.h"
#include "mk_lang_i128.h"


#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_small_name uchar
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_small_name uchar
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_small_type unsigned char
#define mk_num_div_mod_small_name uchar
#include "mk_num_div_mod.inl.h"

#if mk_lang_llong_has != 0
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_small_name ushort
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_small_type unsigned short int
#define mk_num_div_mod_small_name ushort
#include "mk_num_div_mod.inl.h"
#endif

#if mk_lang_i128_has != 0
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_small_type unsigned long int
#define mk_num_div_mod_small_name ulong
#include "mk_num_div_mod.inl.h"
#endif


#endif
