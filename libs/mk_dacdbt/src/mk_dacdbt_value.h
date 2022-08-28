#ifndef mk_include_guard_dacdbt_value
#define mk_include_guard_dacdbt_value


#include "mk_dacdbt_str.h"

#include "../../mk_std/src/mk_std_input_stream.h"

#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


enum mk_dacdbt_value_type_e
{
	mk_dacdbt_value_type_e_u32 = 1,
	mk_dacdbt_value_type_e_f64 = 2,
	mk_dacdbt_value_type_e_str = 3,
	mk_dacdbt_value_type_e_bin = 4,
	mk_dacdbt_value_type_e_file = 5,
	mk_dacdbt_value_type_e_u64 = 6
};
typedef enum mk_dacdbt_value_type_e mk_dacdbt_value_type_t;

struct mk_dacdbt_value_binary_s
{
	void* m_data;
	size_t m_len;
};
typedef struct mk_dacdbt_value_binary_s mk_dacdbt_value_binary_t;

union mk_dacdbt_value_data_u
{
	mk_uint32_t m_u32;
	double m_f64;
	mk_dacdbt_str_t m_str;
	mk_dacdbt_value_binary_t m_bin;
	mk_dacdbt_value_binary_t m_file;
	mk_uint64_t m_u64;
};
typedef union mk_dacdbt_value_data_u mk_dacdbt_value_data_t;


struct mk_dacdbt_value_s
{
	mk_dacdbt_str_t m_name;
	mk_dacdbt_value_type_t m_type;
	mk_dacdbt_value_data_t m_data;
	int m_nocomp;
};
typedef struct mk_dacdbt_value_s mk_dacdbt_value_t;


mk_jumbo int mk_dacdbt_value_construct(mk_dacdbt_value_t* value);
mk_jumbo int mk_dacdbt_value_construct_parse(mk_dacdbt_value_t* value, mk_std_input_stream_t* is);
mk_jumbo int mk_dacdbt_value_destruct(mk_dacdbt_value_t* value);


#endif
