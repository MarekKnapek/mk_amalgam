#include "mk_lang_memset.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizet.h"


mk_lang_jumbo void* mk_lang_memset(void* dst, int val, mk_lang_size_t len)
{
	unsigned char* d;
	unsigned char ch;
	mk_lang_size_t i;

	mk_lang_assert(dst || len == 0);
	mk_lang_assert((val >= 0 && val <= ((unsigned char)(((unsigned char)(0)) - ((unsigned char)(1))))) || len == 0);

	d = ((unsigned char*)(dst));
	ch = ((unsigned char)(val));
	for(i = 0; i != len; ++i, ++d)
	{
		*d = ch;
	}
	return dst;
}
