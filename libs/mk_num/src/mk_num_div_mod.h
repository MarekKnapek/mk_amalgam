#ifndef mk_detail_include_guard_num_div_mod
#define mk_detail_include_guard_num_div_mod


#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"


#define mk_num_div_mod_name uchar_4_4_r3d2
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_name uchar_8_8_r3d2
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_name uchar_16_16_r3d2
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#if mk_lang_llong_has != 0
#define mk_num_div_mod_name ushort_4_4_r3d2
#define mk_num_div_mod_small_type unsigned short int
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_name ushort_8_8_r3d2
#define mk_num_div_mod_small_type unsigned short int
#include "mk_num_div_mod.inl.h"
#endif

#if mk_lang_lllong_has != 0
#define mk_num_div_mod_name ulong_4_4_r3d2
#define mk_num_div_mod_small_type unsigned long int
#include "mk_num_div_mod.inl.h"
#endif


#define mk_num_div_mod_name uchar_4_4_r2d1
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_name uchar_8_8_r2d1
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_name uchar_16_16_r2d1
#define mk_num_div_mod_small_type unsigned char
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_name ushort_4_4_r2d1
#define mk_num_div_mod_small_type unsigned short int
#include "mk_num_div_mod.inl.h"

#define mk_num_div_mod_name ushort_8_8_r2d1
#define mk_num_div_mod_small_type unsigned short int
#include "mk_num_div_mod.inl.h"

#if mk_lang_llong_has != 0
#define mk_num_div_mod_name ulong_4_4_r2d1
#define mk_num_div_mod_small_type unsigned long int
#include "mk_num_div_mod.inl.h"
#endif

#if mk_lang_lllong_has != 0
#define mk_num_div_mod_name ullong_2_2_r2d1
#define mk_num_div_mod_small_type mk_lang_ullong_t
#include "mk_num_div_mod.inl.h"
#endif


#endif
