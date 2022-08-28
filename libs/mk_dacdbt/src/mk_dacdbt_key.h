#ifndef mk_include_guard_dacdbt_key
#define mk_include_guard_dacdbt_key


#include "mk_dacdbt_str.h"

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


#endif
