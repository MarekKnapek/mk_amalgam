#include "mk_lang_i128.h"
#include "mk_lang_llong.h"

#include <limits.h> /* UINT_MAX */


#if mk_num_composite_bits <= 8
#define mk_num_composite_base_type unsigned char
#define mk_num_composite_base_name uchar
#elif mk_num_composite_bits <= 16
#define mk_num_composite_base_type unsigned short int
#define mk_num_composite_base_name ushort
#elif mk_num_composite_bits <= 32
#if UINT_MAX >= 0xfffffffful
#define mk_num_composite_base_type unsigned int
#define mk_num_composite_base_name uint
#else
#define mk_num_composite_base_type unsigned long int
#define mk_num_composite_base_name ulong
#endif
#elif mk_num_composite_bits <= 64
#if mk_lang_llong_has != 0
#define mk_num_composite_base_type unsigned long long int
#define mk_num_composite_base_name ullong
#elif UINT_MAX >= 0xfffffffful
#define mk_num_composite_base_type unsigned int
#define mk_num_composite_base_name uint
#else
#define mk_num_composite_base_type unsigned long int
#define mk_num_composite_base_name ulong
#endif
#else
#if mk_lang_i128_has != 0
#define mk_num_composite_base_type unsigned __int128
#define mk_num_composite_base_name u128
#elif mk_lang_llong_has != 0
#define mk_num_composite_base_type unsigned long long int
#define mk_num_composite_base_name ullong
#elif UINT_MAX >= 0xfffffffful
#define mk_num_composite_base_type unsigned int
#define mk_num_composite_base_name uint
#else
#define mk_num_composite_base_type unsigned long int
#define mk_num_composite_base_name ulong
#endif
#endif
