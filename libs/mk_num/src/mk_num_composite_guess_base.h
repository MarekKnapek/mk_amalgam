#include "mk_lang_charbit.h"
#include "mk_lang_limits.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_sizeof.h"


#if mk_num_composite_bits <= 8
#define mk_num_composite_base_type unsigned char
#define mk_num_composite_base_name uchar
#define mk_num_composite_base_bits (mk_lang_sizeof_uchar * mk_lang_charbit)
#elif mk_num_composite_bits <= 16
#define mk_num_composite_base_type unsigned short int
#define mk_num_composite_base_name ushort
#define mk_num_composite_base_bits (mk_lang_sizeof_ushort * mk_lang_charbit)
#elif mk_num_composite_bits <= 32
#if mk_lang_limits_uintmax >= 0xfffffffful
#define mk_num_composite_base_type unsigned int
#define mk_num_composite_base_name uint
#define mk_num_composite_base_bits (mk_lang_sizeof_uint * mk_lang_charbit)
#else
#define mk_num_composite_base_type unsigned long int
#define mk_num_composite_base_name ulong
#define mk_num_composite_base_bits (mk_lang_sizeof_ulong * mk_lang_charbit)
#endif
#elif mk_num_composite_bits <= 64
#if mk_lang_llong_has != 0
#define mk_num_composite_base_type mk_lang_ullong_t
#define mk_num_composite_base_name ullong
#define mk_num_composite_base_bits (mk_lang_sizeof_ullong * mk_lang_charbit)
#elif mk_lang_limits_uintmax >= 0xfffffffful
#define mk_num_composite_base_type unsigned int
#define mk_num_composite_base_name uint
#define mk_num_composite_base_bits (mk_lang_sizeof_uint * mk_lang_charbit)
#else
#define mk_num_composite_base_type unsigned long int
#define mk_num_composite_base_name ulong
#define mk_num_composite_base_bits (mk_lang_sizeof_ulong * mk_lang_charbit)
#endif
#else
#if mk_lang_lllong_has != 0
#define mk_num_composite_base_type mk_lang_ulllong_t
#define mk_num_composite_base_name ulllong
#define mk_num_composite_base_bits (mk_lang_sizeof_ulllong * mk_lang_charbit)
#elif mk_lang_llong_has != 0
#define mk_num_composite_base_type mk_lang_ullong_t
#define mk_num_composite_base_name ullong
#define mk_num_composite_base_bits (mk_lang_sizeof_ullong * mk_lang_charbit)
#elif mk_lang_limits_uintmax >= 0xfffffffful
#define mk_num_composite_base_type unsigned int
#define mk_num_composite_base_name uint
#define mk_num_composite_base_bits (mk_lang_sizeof_uint * mk_lang_charbit)
#else
#define mk_num_composite_base_type unsigned long int
#define mk_num_composite_base_name ulong
#define mk_num_composite_base_bits (mk_lang_sizeof_ulong * mk_lang_charbit)
#endif
#endif
