#include "mk_std_istr.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


mk_jumbo int mk_std_istr_construct(mk_std_istr_t* istr)
{
	mk_assert(istr);
	mk_assert(sizeof(istr->m_idx.m_n) == sizeof(istr->m_idx.m_w));
	mk_assert(sizeof(istr->m_idx.m_n) == sizeof(istr->m_idx.m_i));

	istr->m_idx.m_n = NULL;

	return 0;
}
