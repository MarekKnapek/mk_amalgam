#ifndef mk_include_guard_dacdbt_key
#define mk_include_guard_dacdbt_key


#include "mk_dacdbt_str.h"
#include "mk_dacdbt_value.h"

#include "../../mk_std/src/mk_std_input_stream.h"
#include "../../mk_std/src/mk_std_ptr_buff.h"

#include "../../mk_int/src/exact/mk_uint_32.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_dacdbt_key_s
{
	mk_dacdbt_str_t m_name;
	mk_std_ptr_buff_t m_sub_keys;
	mk_std_ptr_buff_t m_values;
	int m_nocomp;
};
typedef struct mk_dacdbt_key_s mk_dacdbt_key_t;


mk_jumbo int mk_dacdbt_key_construct(mk_dacdbt_key_t* key);
mk_jumbo int mk_dacdbt_key_construct_parse(mk_dacdbt_key_t* key, mk_std_input_stream_t* is);
mk_jumbo int mk_dacdbt_key_destruct(mk_dacdbt_key_t* key);
mk_jumbo int mk_dacdbt_key_get_name(mk_dacdbt_key_t const* key, int* is_wide, void const** data, size_t* len);
mk_jumbo int mk_dacdbt_key_get_sub_keys_count(mk_dacdbt_key_t const* key, unsigned long* count);
mk_jumbo int mk_dacdbt_key_get_sub_key(mk_dacdbt_key_t* key, unsigned long idx, mk_dacdbt_key_t** sub_key);
mk_jumbo int mk_dacdbt_key_get_values_count(mk_dacdbt_key_t const* key, unsigned long* count);
mk_jumbo int mk_dacdbt_key_get_value(mk_dacdbt_key_t* key, unsigned long idx, mk_dacdbt_value_t** value);
mk_jumbo int mk_dacdbt_key_get_count(mk_dacdbt_key_t* key, unsigned long* keys, unsigned long* values);
mk_jumbo int mk_dacdbt_key_get_max(mk_dacdbt_key_t* key, unsigned long* keys, unsigned long* values);


#endif
