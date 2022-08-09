#ifndef mk_include_guard_gcallocator
#define mk_include_guard_gcallocator


#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


mk_jumbo int mk_std_gcallocator_allocate(size_t amount, void** mem);
mk_jumbo int mk_std_gcallocator_deallocate(void const* mem);
mk_jumbo int mk_std_gcallocator_reallocate(void** mem, size_t amount);


#endif
