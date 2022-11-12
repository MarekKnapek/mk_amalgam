#ifndef mk_detail_include_guard_num_div_mod
#define mk_detail_include_guard_num_div_mod


#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"


#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#if mk_lang_llong_has != 0
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#include "mk_num_div_mod.inl.h"
#endif

#if mk_lang_lllong_has != 0
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 0
#define mk_num_div_mod_small_name ulong
#define mk_num_div_mod_small_type unsigned long int
#include "mk_num_div_mod.inl.h"
#endif


#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 16
#define mk_num_div_mod_len_y 16
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name uchar
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_len_x 8
#define mk_num_div_mod_len_y 8
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ushort
#define mk_num_div_mod_small_type unsigned short int
#include "mk_num_div_mod.inl.h"

#if mk_lang_llong_has != 0
#define mk_num_div_mod_len_x 4
#define mk_num_div_mod_len_y 4
#define mk_num_div_mod_use_r1d2 1
#define mk_num_div_mod_small_name ulong
#define mk_num_div_mod_small_type unsigned long int
#include "mk_num_div_mod.inl.h"
#endif


#endif
