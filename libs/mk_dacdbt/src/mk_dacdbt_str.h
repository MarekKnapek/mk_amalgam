#ifndef mk_include_guard_dacdbt_str
#define mk_include_guard_dacdbt_str


#include "../../mk_std/src/mk_std_input_stream.h"
#include "../../mk_std/src/mk_std_istr.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


struct mk_dacdbt_str_s
{
	mk_std_istr_t m_istr;
};
typedef struct mk_dacdbt_str_s mk_dacdbt_str_t;


mk_jumbo int mk_dacdbt_str_init(void);
mk_jumbo int mk_dacdbt_str_deinit(void);
mk_jumbo int mk_dacdbt_str_construct(mk_dacdbt_str_t* str);
mk_jumbo int mk_dacdbt_str_construct_parse(mk_dacdbt_str_t* str, mk_std_input_stream_t* is);
mk_jumbo int mk_dacdbt_str_destruct(mk_dacdbt_str_t* str);
mk_jumbo int mk_dacdbt_str_get(mk_dacdbt_str_t* str, int* is_wide, void const** data, size_t* len);
mk_jumbo int mk_dacdbt_str_is_empty(mk_dacdbt_str_t* str, int* is_empty);


#endif
