#ifndef mk_include_guard_std_istr
#define mk_include_guard_std_istr


#include "../../mk_int/src/exact/mk_uint_32.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_std_istr_s
{
	mk_uint32_t m_idx;
};
typedef struct mk_std_istr_s mk_std_istr_t;


mk_jumbo int mk_std_istr_construct(mk_std_istr_t* istr);


#endif
