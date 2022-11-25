#include "mk_num_basic_uints.h"

#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_sizet.h"
#include "mk_lang_uintmaxt.h"


#define mk_detail_num_basic_ut_type unsigned char
#define mk_detail_num_basic_ut_name uchar
#include "mk_num_basic_uint.inl.c"

#define mk_detail_num_basic_ut_type unsigned short int
#define mk_detail_num_basic_ut_name ushort
#include "mk_num_basic_uint.inl.c"

#define mk_detail_num_basic_ut_type unsigned int
#define mk_detail_num_basic_ut_name uint
#include "mk_num_basic_uint.inl.c"

#define mk_detail_num_basic_ut_type unsigned long int
#define mk_detail_num_basic_ut_name ulong
#include "mk_num_basic_uint.inl.c"

#define mk_detail_num_basic_ut_type mk_lang_ullong_t
#define mk_detail_num_basic_ut_name ullong
#include "mk_num_basic_uint.inl.c"

#define mk_detail_num_basic_ut_type mk_lang_ulllong_t
#define mk_detail_num_basic_ut_name ulllong
#include "mk_num_basic_uint.inl.c"

#define mk_detail_num_basic_ut_type size_t
#define mk_detail_num_basic_ut_name usize
#include "mk_num_basic_uint.inl.c"

#define mk_detail_num_basic_ut_type uintmax_t
#define mk_detail_num_basic_ut_name umax
#include "mk_num_basic_uint.inl.c"
