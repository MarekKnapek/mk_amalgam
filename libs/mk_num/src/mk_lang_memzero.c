#include "mk_lang_memzero.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizet.h"


mk_lang_jumbo void* mk_lang_memzero(void* dst, mk_lang_size_t len)
{
	unsigned char* d;
	mk_lang_size_t i;

	mk_lang_assert(dst || len == 0);

	d = ((unsigned char*)(dst));
	for(i = 0; i != len; ++i, ++d)
	{
		*d = 0;
	}
	return dst;
}
