#include "mk_lang_memcpy.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizet.h"


mk_lang_jumbo void* mk_lang_memcpy(void* dst, void const* src, mk_lang_size_t len)
{
	unsigned char* d;
	unsigned char const* s;
	mk_lang_size_t i;

	mk_lang_assert(dst || len == 0);
	mk_lang_assert(src || len == 0);
	mk_lang_assert
	(
		(((unsigned char const*)(dst)) + len <= ((unsigned char const*)(src))) ||
		(((unsigned char const*)(src)) + len <= ((unsigned char const*)(dst)))
	);

	d = ((unsigned char*)(dst));
	s = ((unsigned char const*)(src));
	for(i = 0; i != len; ++i, ++d, ++s)
	{
		*d = *s;
	}
	return dst;
}
