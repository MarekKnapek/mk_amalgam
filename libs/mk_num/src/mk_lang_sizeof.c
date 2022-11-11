#include "mk_lang_sizeof.h"

#include "mk_lang_bool.h"
#include "mk_lang_i128.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_llong.h"
#include "mk_lang_nodiscard.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_sizeof_test(void)
{
	mk_lang_bool_t ret;

	ret = mk_lang_true;

	ret = ret && (mk_lang_sizeof_uchar == 1);
	ret = ret && (mk_lang_sizeof_uchar <= mk_lang_sizeof_ushort);
	ret = ret && (mk_lang_sizeof_ushort <= mk_lang_sizeof_uint);
	ret = ret && (mk_lang_sizeof_uint <= mk_lang_sizeof_ulong);
	ret = ret && (mk_lang_sizeof_ulong <= mk_lang_sizeof_ullong);

	ret = ret && (sizeof(unsigned char) == mk_lang_sizeof_uchar);
	ret = ret && (sizeof(unsigned short int) == mk_lang_sizeof_ushort);
	ret = ret && (sizeof(unsigned int) == mk_lang_sizeof_uint);
	ret = ret && (sizeof(unsigned long int) == mk_lang_sizeof_ulong);
	#if mk_lang_llong_has != 0
	ret = ret && (sizeof(mk_lang_ullong_t) == mk_lang_sizeof_ullong);
	#endif
	#if mk_lang_i128_has != 0
	ret = ret && (sizeof(unsigned __int128) == mk_lang_sizeof_ui128t);
	#endif
	return ret;
}
