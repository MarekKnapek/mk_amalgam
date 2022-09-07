#include "mk_std_gcallocator.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>
#include <stdlib.h>


mk_jumbo int mk_std_gcallocator_allocate(size_t amount, void** mem)
{
	void* m;

	mk_assert(mem);

	m = malloc(amount);
	mk_check(m);
	*mem = m;

	return 0;
}

mk_jumbo int mk_std_gcallocator_deallocate(void const* mem)
{
	free((void*)mem);

	return 0;
}

mk_jumbo int mk_std_gcallocator_reallocate(void** mem, size_t amount)
{
	void* m;

	mk_assert(mem);

	m = *mem;
	m = realloc(m, amount);
	mk_check(m);
	*mem = m;

	return 0;
}
