#include "mk_std_istr.h"

#include "../../mk_int/src/exact/mk_uint_32.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo int mk_std_istr_construct(mk_std_istr_t* istr)
{
	mk_assert(istr);

	mk_uint32_zero(&istr->m_idx);
	mk_uint32_dec(&istr->m_idx);

	return 0;
}
