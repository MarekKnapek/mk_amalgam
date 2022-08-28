#ifndef mk_include_guard_dacdbt_str
#define mk_include_guard_dacdbt_str


#include "../../mk_std/src/mk_std_input_stream.h"

#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


struct mk_dacdbt_str_s
{
	int m_type;
	size_t m_len;
	union
	{
		char* m_narrow;
		wchar_t* m_wide;
	} m_data;
};
typedef struct mk_dacdbt_str_s mk_dacdbt_str_t;


mk_jumbo int mk_dacdbt_str_construct(mk_dacdbt_str_t* str);
mk_jumbo int mk_dacdbt_str_construct_parse(mk_dacdbt_str_t* str, mk_std_input_stream_t* is);
mk_jumbo int mk_dacdbt_str_destruct(mk_dacdbt_str_t* str);


#endif
