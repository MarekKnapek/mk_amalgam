#ifndef mk_detail_include_guard_num_basic_uints
#define mk_detail_include_guard_num_basic_uints


#include "mk_lang_i128.h"
#include "mk_lang_llong.h"
#include "mk_lang_sizet.h"
#include "mk_lang_uintmaxt.h"


#define mk_detail_num_basic_ut_type unsigned char
#define mk_detail_num_basic_ut_name uchar
#include "mk_num_basic_uint.inl.h"

#define mk_detail_num_basic_ut_type unsigned short int
#define mk_detail_num_basic_ut_name ushort
#include "mk_num_basic_uint.inl.h"

#define mk_detail_num_basic_ut_type unsigned int
#define mk_detail_num_basic_ut_name uint
#include "mk_num_basic_uint.inl.h"

#define mk_detail_num_basic_ut_type unsigned long int
#define mk_detail_num_basic_ut_name ulong
#include "mk_num_basic_uint.inl.h"

#if mk_lang_llong_has != 0
#define mk_detail_num_basic_ut_type mk_lang_ullong_t
#define mk_detail_num_basic_ut_name ullong
#include "mk_num_basic_uint.inl.h"
#endif

#define mk_detail_num_basic_ut_type size_t
#define mk_detail_num_basic_ut_name usize
#include "mk_num_basic_uint.inl.h"

#if mk_lang_uintmaxt_has != 0
#define mk_detail_num_basic_ut_type uintmax_t
#define mk_detail_num_basic_ut_name umax
#include "mk_num_basic_uint.inl.h"
#endif

#if mk_lang_i128_has != 0
#define mk_detail_num_basic_ut_type unsigned __int128
#define mk_detail_num_basic_ut_name u128
#include "mk_num_basic_uint.inl.h"
#endif


#endif
