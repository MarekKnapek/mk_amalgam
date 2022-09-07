#ifndef mk_include_guard_std_istr
#define mk_include_guard_std_istr


#include "mk_std_uintp.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_std_istr_s
{
	union
	{
		char const* m_n;
		wchar_t const* m_w;
		mk_uintp_t m_i;
	} m_idx;
};
typedef struct mk_std_istr_s mk_std_istr_t;


mk_jumbo int mk_std_istr_construct(mk_std_istr_t* istr);


#endif
