#ifndef mk_detail_include_guard_num_basic_uints
#define mk_detail_include_guard_num_basic_uints


#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_sizet.h"
#include "mk_lang_uintmaxt.h"


#define mk_num_basic_uint_type unsigned char
#define mk_num_basic_uint_name uchar
#include "mk_num_basic_uint.inl.h"

#define mk_num_basic_uint_type unsigned short int
#define mk_num_basic_uint_name ushort
#include "mk_num_basic_uint.inl.h"

#define mk_num_basic_uint_type unsigned int
#define mk_num_basic_uint_name uint
#include "mk_num_basic_uint.inl.h"

#define mk_num_basic_uint_type unsigned long int
#define mk_num_basic_uint_name ulong
#include "mk_num_basic_uint.inl.h"

#define mk_num_basic_uint_type mk_lang_ullong_t
#define mk_num_basic_uint_name ullong
#include "mk_num_basic_uint.inl.h"

#define mk_num_basic_uint_type mk_lang_ulllong_t
#define mk_num_basic_uint_name ulllong
#include "mk_num_basic_uint.inl.h"

#define mk_num_basic_uint_type size_t
#define mk_num_basic_uint_name usize
#include "mk_num_basic_uint.inl.h"

#define mk_num_basic_uint_type uintmax_t
#define mk_num_basic_uint_name umax
#include "mk_num_basic_uint.inl.h"


#endif
