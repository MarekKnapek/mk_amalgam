#include "mk_lang_memcmp.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizet.h"


mk_lang_nodiscard mk_lang_jumbo int mk_lang_memcmp(void const* x, void const* y, mk_lang_size_t len)
{
	unsigned char const* xx;
	unsigned char const* yy;
	mk_lang_size_t i;

	mk_lang_assert(x || len == 0);
	mk_lang_assert(y || len == 0);

	if(x != y)
	{
		xx = ((unsigned char const*)(x));
		yy = ((unsigned char const*)(y));
		for(i = 0; i != len; ++i, ++xx, ++yy)
		{
			if(*xx != *yy)
			{
				return ((signed int)(((signed int)(*xx)) - ((signed int)(*yy))));
			}
		}
	}
	return 0;
}
