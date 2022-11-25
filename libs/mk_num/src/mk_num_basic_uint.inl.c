#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizet.h"
#include "mk_lang_uintmaxt.h"


#if defined(_MSC_VER) && _MSC_VER >= 1700 /* VS 2012 */ && defined(_M_AMD64)
#include <intrin.h>
#pragma intrinsic(_umul128)
#endif
#if defined(_MSC_VER) && _MSC_VER >= 1600 /* VS 2010 */ && (defined(_M_AMD64) || defined(_M_IA64))
#include <intrin.h>
#pragma intrinsic(__umulh)
#endif
#if defined(_MSC_VER) && _MSC_VER >= 1500 /* VS 2008 */ && (defined(_M_IX86) || defined(_M_AMD64))
#include <intrin.h>
#pragma intrinsic(__emulu)
#endif
#if defined(_MSC_VER) && _MSC_VER >= 1500 /* VS 2008 */ && defined(_M_AMD64)
#include <intrin.h>
#pragma intrinsic(__ull_rshift)
#endif


#include "mk_num_basic_uint_def.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4514) /* warning C4514: 'xxx': unreferenced inline function has been removed */
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


mk_lang_jumbo void mk_num_set_zero(mk_num_basic_uint_type* x)
{
	mk_lang_assert(x);

	*x = 0;
}

mk_lang_jumbo void mk_num_set_one(mk_num_basic_uint_type* x)
{
	mk_lang_assert(x);

	*x = 1;
}

mk_lang_jumbo void mk_num_set_mask(mk_num_basic_uint_type* x, int bits)
{
	#ifdef NDEBUG
	#else
	mk_num_basic_uint_type tmp;
	#endif

	mk_lang_assert(x);
	mk_lang_assert(bits > 0 && bits <= ((int)(sizeof(mk_num_basic_uint_type) * mk_lang_charbit)));

	#ifdef NDEBUG
	*x = ((mk_num_basic_uint_type)(((mk_num_basic_uint_type)(((mk_num_basic_uint_type)(((mk_num_basic_uint_type)(((mk_num_basic_uint_type)(1)) << (bits - 1))) - ((mk_num_basic_uint_type)(1)))) << 1)) | ((mk_num_basic_uint_type)(1))));
	#else
	tmp = ((mk_num_basic_uint_type)(1));
	tmp = ((mk_num_basic_uint_type)(tmp << (bits - 1)));
	tmp = ((mk_num_basic_uint_type)(tmp - ((mk_num_basic_uint_type)(1))));
	tmp = ((mk_num_basic_uint_type)(tmp << 1));
	tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(1))));
	*x = tmp;
	#endif
}


mk_lang_jumbo void mk_num_from_char(mk_num_basic_uint_type* x, char const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_uchar(mk_num_basic_uint_type* x, unsigned char const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_schar(mk_num_basic_uint_type* x, signed char const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_ushort(mk_num_basic_uint_type* x, unsigned short int const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_sshort(mk_num_basic_uint_type* x, signed short int const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_uint(mk_num_basic_uint_type* x, unsigned int const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_sint(mk_num_basic_uint_type* x, signed int const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_ulong(mk_num_basic_uint_type* x, unsigned long int const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_slong(mk_num_basic_uint_type* x, signed long int const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_ullong(mk_num_basic_uint_type* x, mk_lang_ullong_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_sllong(mk_num_basic_uint_type* x, mk_lang_sllong_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_ulllong(mk_num_basic_uint_type* x, mk_lang_ulllong_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_slllong(mk_num_basic_uint_type* x, mk_lang_slllong_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_sizet(mk_num_basic_uint_type* x, mk_lang_size_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_umaxt(mk_num_basic_uint_type* x, mk_lang_uintmax_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}

mk_lang_jumbo void mk_num_from_smaxt(mk_num_basic_uint_type* x, mk_lang_sintmax_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_num_basic_uint_type)(*src));
}


mk_lang_jumbo void mk_num_to_char(mk_num_basic_uint_type const* x, char* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((char)(*x));
}

mk_lang_jumbo void mk_num_to_uchar(mk_num_basic_uint_type const* x, unsigned char* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((unsigned char)(*x));
}

mk_lang_jumbo void mk_num_to_schar(mk_num_basic_uint_type const* x, signed char* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((signed char)(*x));
}

mk_lang_jumbo void mk_num_to_ushort(mk_num_basic_uint_type const* x, unsigned short int* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((unsigned short int)(*x));
}

mk_lang_jumbo void mk_num_to_sshort(mk_num_basic_uint_type const* x, signed short int* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((signed short int)(*x));
}

mk_lang_jumbo void mk_num_to_uint(mk_num_basic_uint_type const* x, unsigned int* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((unsigned int)(*x));
}

mk_lang_jumbo void mk_num_to_sint(mk_num_basic_uint_type const* x, signed int* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((signed int)(*x));
}

mk_lang_jumbo void mk_num_to_ulong(mk_num_basic_uint_type const* x, unsigned long int* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((unsigned long int)(*x));
}

mk_lang_jumbo void mk_num_to_slong(mk_num_basic_uint_type const* x, signed long int* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((signed long int)(*x));
}

mk_lang_jumbo void mk_num_to_ullong(mk_num_basic_uint_type const* x, mk_lang_ullong_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_ullong_t)(*x));
}

mk_lang_jumbo void mk_num_to_sllong(mk_num_basic_uint_type const* x, mk_lang_sllong_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_sllong_t)(*x));
}

mk_lang_jumbo void mk_num_to_ulllong(mk_num_basic_uint_type const* x, mk_lang_ulllong_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_ulllong_t)(*x));
}

mk_lang_jumbo void mk_num_to_slllong(mk_num_basic_uint_type const* x, mk_lang_slllong_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_slllong_t)(*x));
}

mk_lang_jumbo void mk_num_to_sizet(mk_num_basic_uint_type const* x, mk_lang_size_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_size_t)(*x));
}

mk_lang_jumbo void mk_num_to_umaxt(mk_num_basic_uint_type const* x, mk_lang_uintmax_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_uintmax_t)(*x));
}

mk_lang_jumbo void mk_num_to_smaxt(mk_num_basic_uint_type const* x, mk_lang_sintmax_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_sintmax_t)(*x));
}


mk_lang_jumbo void mk_num_from_uchars_le(mk_num_basic_uint_type* x, unsigned char const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1 - i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_ushorts_le(mk_num_basic_uint_type* x, unsigned short int const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1 - i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_uints_le(mk_num_basic_uint_type* x, unsigned int const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1 - i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_ulongs_le(mk_num_basic_uint_type* x, unsigned long int const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1 - i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_ullongs_le(mk_num_basic_uint_type* x, mk_lang_ullong_t const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1 - i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_ulllongs_le(mk_num_basic_uint_type* x, mk_lang_ulllong_t const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1 - i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_sizets_le(mk_num_basic_uint_type* x, mk_lang_size_t const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1 - i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_umaxts_le(mk_num_basic_uint_type* x, mk_lang_uintmax_t const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
			#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[(sizeof(tmp) + (sizeof(*src) - 1)) / sizeof(*src) - 1 - i]))));
	}
	*x = tmp;
}


mk_lang_jumbo void mk_num_to_uchars_le(mk_num_basic_uint_type const* x, unsigned char* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[0] = ((unsigned char)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[i] = ((unsigned char)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_ushorts_le(mk_num_basic_uint_type const* x, unsigned short int* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[0] = ((unsigned short int)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[i] = ((unsigned short int)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_uints_le(mk_num_basic_uint_type const* x, unsigned int* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[0] = ((unsigned int)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
			#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[i] = ((unsigned int)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_ulongs_le(mk_num_basic_uint_type const* x, unsigned long int* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[0] = ((unsigned long int)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[i] = ((unsigned long int)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_ullongs_le(mk_num_basic_uint_type const* x, mk_lang_ullong_t* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[0] = ((mk_lang_ullong_t)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[i] = ((mk_lang_ullong_t)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_ulllongs_le(mk_num_basic_uint_type const* x, mk_lang_ulllong_t* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[0] = ((mk_lang_ulllong_t)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[i] = ((mk_lang_ulllong_t)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_sizets_le(mk_num_basic_uint_type const* x, mk_lang_size_t* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[0] = ((mk_lang_size_t)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[i] = ((mk_lang_size_t)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_umaxts_le(mk_num_basic_uint_type const* x, mk_lang_uintmax_t* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[0] = ((mk_lang_uintmax_t)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[i] = ((mk_lang_uintmax_t)(tmp));
	}
}


mk_lang_jumbo void mk_num_from_uchars_be(mk_num_basic_uint_type* x, unsigned char const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[0]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_ushorts_be(mk_num_basic_uint_type* x, unsigned short int const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[0]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_uints_be(mk_num_basic_uint_type* x, unsigned int const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[0]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_ulongs_be(mk_num_basic_uint_type* x, unsigned long int const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[0]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_ullongs_be(mk_num_basic_uint_type* x, mk_lang_ullong_t const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[0]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_ulllongs_be(mk_num_basic_uint_type* x, mk_lang_ulllong_t const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[0]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_sizets_be(mk_num_basic_uint_type* x, mk_lang_size_t const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[0]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[i]))));
	}
	*x = tmp;
}

mk_lang_jumbo void mk_num_from_umaxts_be(mk_num_basic_uint_type* x, mk_lang_uintmax_t const* src)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	tmp = ((mk_num_basic_uint_type)(src[0]));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*src) - 1)) / (sizeof(*src)))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp << (sizeof(*src) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp | ((mk_num_basic_uint_type)(src[i]))));
	}
	*x = tmp;
}


mk_lang_jumbo void mk_num_to_uchars_be(mk_num_basic_uint_type const* x, unsigned char* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1] = ((unsigned char)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1 - i] = ((unsigned char)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_ushorts_be(mk_num_basic_uint_type const* x, unsigned short int* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1] = ((unsigned short int)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1 - i] = ((unsigned short int)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_uints_be(mk_num_basic_uint_type const* x, unsigned int* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1] = ((unsigned int)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1 - i] = ((unsigned int)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_ulongs_be(mk_num_basic_uint_type const* x, unsigned long int* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1] = ((unsigned long int)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1 - i] = ((unsigned long int)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_ullongs_be(mk_num_basic_uint_type const* x, mk_lang_ullong_t* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1] = ((mk_lang_ullong_t)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1 - i] = ((mk_lang_ullong_t)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_ulllongs_be(mk_num_basic_uint_type const* x, mk_lang_ulllong_t* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1] = ((mk_lang_ulllong_t)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1 - i] = ((mk_lang_ulllong_t)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_sizets_be(mk_num_basic_uint_type const* x, mk_lang_size_t* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1] = ((mk_lang_size_t)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1 - i] = ((mk_lang_size_t)(tmp));
	}
}

mk_lang_jumbo void mk_num_to_umaxts_be(mk_num_basic_uint_type const* x, mk_lang_uintmax_t* dst)
{
	mk_num_basic_uint_type tmp;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	tmp = *x;
	dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1] = ((mk_lang_uintmax_t)(tmp));
	for(i = 1; i != ((int)((sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst))); ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		tmp = ((mk_num_basic_uint_type)(tmp >> (sizeof(*dst) * mk_lang_charbit)));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		dst[(sizeof(tmp) + (sizeof(*dst) - 1)) / sizeof(*dst) - 1 - i] = ((mk_lang_uintmax_t)(tmp));
	}
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_is_zero(mk_num_basic_uint_type const* x)
{
	mk_lang_assert(x);

	return *x == 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_eq(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x == *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_ne(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x != *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_lt(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x < *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_le(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x <= *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_gt(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x > *y;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_ge(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	return *x >= *y;
}


mk_lang_jumbo void mk_num_inc2(mk_num_basic_uint_type const* x, mk_num_basic_uint_type* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	*y = ((mk_num_basic_uint_type)(*x + 1));
}

mk_lang_jumbo void mk_num_dec2(mk_num_basic_uint_type const* x, mk_num_basic_uint_type* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	*y = ((mk_num_basic_uint_type)(*x - 1));
}

mk_lang_jumbo void mk_num_inc1(mk_num_basic_uint_type* x)
{
	mk_lang_assert(x);

	++*x;
}

mk_lang_jumbo void mk_num_dec1(mk_num_basic_uint_type* x)
{
	mk_lang_assert(x);

	--*x;
}


mk_lang_jumbo void mk_num_not2(mk_num_basic_uint_type const* x, mk_num_basic_uint_type* y)
{
	mk_lang_assert(x);
	mk_lang_assert(y);

	*y = ((mk_num_basic_uint_type)(~*x));
}

mk_lang_jumbo void mk_num_not1(mk_num_basic_uint_type* x)
{
	mk_num_not2(x, x);
}


mk_lang_jumbo void mk_num_or3(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_num_basic_uint_type)(*x | *y));
}

mk_lang_jumbo void mk_num_and3(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_num_basic_uint_type)(*x & *y));
}

mk_lang_jumbo void mk_num_xor3(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_num_basic_uint_type)(*x ^ *y));
}

mk_lang_jumbo void mk_num_or2(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_or3(x, y, x);
}

mk_lang_jumbo void mk_num_and2(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_and3(x, y, x);
}

mk_lang_jumbo void mk_num_xor2(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_xor3(x, y, x);
}


mk_lang_jumbo void mk_num_shl3(mk_num_basic_uint_type const* x, int bits, mk_num_basic_uint_type* y)
{
	mk_lang_assert(x);
	mk_lang_assert(bits >= 0 && bits < ((int)(sizeof(mk_num_basic_uint_type) * mk_lang_charbit)));
	mk_lang_assert(y);

	*y = ((mk_num_basic_uint_type)(*x << bits));
}

mk_lang_jumbo void mk_num_shr3(mk_num_basic_uint_type const* x, int bits, mk_num_basic_uint_type* y)
{
	mk_lang_assert(x);
	mk_lang_assert(bits >= 0 && bits < ((int)(sizeof(mk_num_basic_uint_type) * mk_lang_charbit)));
	mk_lang_assert(y);

	*y = ((mk_num_basic_uint_type)(*x >> bits));
}

mk_lang_jumbo void mk_num_shl2(mk_num_basic_uint_type* x, int bits)
{
	mk_num_shl3(x, bits, x);
}

mk_lang_jumbo void mk_num_shr2(mk_num_basic_uint_type* x, int bits)
{
	mk_num_shr3(x, bits, x);
}


mk_lang_jumbo void mk_num_add3_wrap_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_num_basic_uint_type)(*x + *y));
}

mk_lang_jumbo void mk_num_add3_wrap_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_num_basic_uint_type tmp;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(co);

	tmp = ((mk_num_basic_uint_type)(*x + *y));
	*co = tmp < *x;
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_wrap_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_num_basic_uint_type)(*x + *y + ci));
}

mk_lang_jumbo void mk_num_add3_wrap_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_num_basic_uint_type tmp;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(co);

	tmp = ((mk_num_basic_uint_type)(*x + *y + ci));
	*co = ci ? (tmp <= *x) : (tmp < *x);
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_sat_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_add3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		tmp = 0;
		--tmp;
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_sat_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_add3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		tmp = 0;
		--tmp;
	}
	*z = tmp;
	*co = b;
}

mk_lang_jumbo void mk_num_add3_sat_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_add3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		tmp = 0;
		--tmp;
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_sat_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_add3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		tmp = 0;
		--tmp;
	}
	*z = tmp;
	*co = b;
}

mk_lang_jumbo void mk_num_add3_crash_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_add3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		mk_lang_crash();
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_crash_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_add3_crash_cid_cod(x, y, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_add3_crash_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_add3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		mk_lang_crash();
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_add3_crash_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_add3_crash_cie_cod(x, y, ci, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_add2_wrap_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_add3_wrap_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_add2_wrap_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co)
{
	mk_num_add3_wrap_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_add2_wrap_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci)
{
	mk_num_add3_wrap_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_add2_wrap_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_add3_wrap_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_add2_sat_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_add3_sat_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_add2_sat_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co)
{
	mk_num_add3_sat_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_add2_sat_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci)
{
	mk_num_add3_sat_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_add2_sat_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_add3_sat_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_add2_crash_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_add3_crash_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_add2_crash_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co)
{
	mk_num_add3_crash_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_add2_crash_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci)
{
	mk_num_add3_crash_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_add2_crash_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_add3_crash_cie_coe(x, y, ci, x, co);
}


mk_lang_jumbo void mk_num_sub3_wrap_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_num_basic_uint_type)(*x - *y));
}

mk_lang_jumbo void mk_num_sub3_wrap_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(co);

	*co = *x < *y;
	*z = ((mk_num_basic_uint_type)(*x - *y));
}

mk_lang_jumbo void mk_num_sub3_wrap_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_num_basic_uint_type)(*x - *y - ci));
}

mk_lang_jumbo void mk_num_sub3_wrap_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(co);

	*co = ci ? (*x <= *y) : (*x < *y);
	*z = ((mk_num_basic_uint_type)(*x - *y - ci));
}

mk_lang_jumbo void mk_num_sub3_sat_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_sub3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		tmp = 0;
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_sub3_sat_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_sub3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		tmp = 0;
	}
	*z = tmp;
	*co = b;
}

mk_lang_jumbo void mk_num_sub3_sat_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_sub3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		tmp = 0;
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_sub3_sat_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_sub3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		tmp = 0;
	}
	*z = tmp;
	*co = b;
}

mk_lang_jumbo void mk_num_sub3_crash_cid_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_sub3_wrap_cid_coe(x, y, &tmp, &b);
	if(b)
	{
		mk_lang_crash();
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_sub3_crash_cid_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_sub3_crash_cid_cod(x, y, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_sub3_crash_cie_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type tmp;
	mk_lang_bool_t b;

	mk_lang_assert(z);

	mk_num_sub3_wrap_cie_coe(x, y, ci, &tmp, &b);
	if(b)
	{
		mk_lang_crash();
	}
	*z = tmp;
}

mk_lang_jumbo void mk_num_sub3_crash_cie_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_num_basic_uint_type* z, mk_lang_bool_t* co)
{
	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_sub3_crash_cie_cod(x, y, ci, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_sub2_wrap_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_sub3_wrap_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_sub2_wrap_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co)
{
	mk_num_sub3_wrap_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_sub2_wrap_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci)
{
	mk_num_sub3_wrap_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_sub2_wrap_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_sub3_wrap_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_sub2_sat_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_sub3_sat_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_sub2_sat_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co)
{
	mk_num_sub3_sat_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_sub2_sat_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci)
{
	mk_num_sub3_sat_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_sub2_sat_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_sub3_sat_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_sub2_crash_cid_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_sub3_crash_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_sub2_crash_cid_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t* co)
{
	mk_num_sub3_crash_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_sub2_crash_cie_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci)
{
	mk_num_sub3_crash_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_sub2_crash_cie_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_sub3_crash_cie_coe(x, y, ci, x, co);
}


mk_lang_jumbo void mk_num_mul3_wrap_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	*z = ((mk_num_basic_uint_type)(*x * *y));
}

mk_lang_jumbo void mk_num_mul3_wrap_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_num_basic_uint_type* co)
{
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(sizeof(mk_num_basic_uint_type) * mk_lang_charbit <= 8)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		unsigned short int xx;
		unsigned short int yy;
		unsigned short int zz;

		mk_lang_assert(x);
		mk_lang_assert(y);
		mk_lang_assert(z);
		mk_lang_assert(co);

		xx = ((unsigned short int)(*x));
		yy = ((unsigned short int)(*y));
		zz = ((unsigned short int)(xx * yy));
		*z = ((mk_num_basic_uint_type)(zz));
		*co = ((mk_num_basic_uint_type)(zz >> 8));
	}
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	else if(sizeof(mk_num_basic_uint_type) * mk_lang_charbit <= 16)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		unsigned long int xx;
		unsigned long int yy;
		unsigned long int zz;

		mk_lang_assert(x);
		mk_lang_assert(y);
		mk_lang_assert(z);
		mk_lang_assert(co);

		xx = ((unsigned long int)(*x));
		yy = ((unsigned long int)(*y));
		zz = ((unsigned long int)(xx * yy));
		*z = ((mk_num_basic_uint_type)(zz));
		*co = ((mk_num_basic_uint_type)(zz >> 16));
	}
	#if defined(_MSC_VER) && _MSC_VER >= 1500 /* VS 2008 */ && (defined(_M_IX86) || defined(_M_AMD64))
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	else if(sizeof(mk_num_basic_uint_type) * mk_lang_charbit <= 32)
	#pragma warning(pop)
	{
		unsigned int xx;
		unsigned int yy;
		unsigned __int64 zz;

		mk_lang_assert(x);
		mk_lang_assert(y);
		mk_lang_assert(z);
		mk_lang_assert(co);

		xx = ((unsigned int)(*x));
		yy = ((unsigned int)(*y));
		zz = __emulu(xx, yy);
		*z = ((mk_num_basic_uint_type)(zz));
		#if defined(_M_AMD64)
		*co = ((mk_num_basic_uint_type)(__ull_rshift(zz, 32)));
		#else
		*co = ((mk_num_basic_uint_type)(zz >> 32));
		#endif
	}
	#endif
	#if mk_lang_llong_has != 0
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	else if(sizeof(mk_num_basic_uint_type) * mk_lang_charbit <= 32)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_lang_ullong_t xx;
		mk_lang_ullong_t yy;
		mk_lang_ullong_t zz;

		mk_lang_assert(x);
		mk_lang_assert(y);
		mk_lang_assert(z);
		mk_lang_assert(co);

		xx = ((mk_lang_ullong_t)(*x));
		yy = ((mk_lang_ullong_t)(*y));
		zz = ((mk_lang_ullong_t)(xx * yy));
		*z = ((mk_num_basic_uint_type)(zz));
		*co = ((mk_num_basic_uint_type)(zz >> 32));
	}
	#endif
	#if defined(_MSC_VER) && _MSC_VER >= 1700 /* VS 2012 */ && defined(_M_AMD64)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	else if(sizeof(mk_num_basic_uint_type) * mk_lang_charbit <= 64)
	#pragma warning(pop)
	{
		unsigned __int64 xx;
		unsigned __int64 yy;
		unsigned __int64 cc;

		mk_lang_assert(x);
		mk_lang_assert(y);
		mk_lang_assert(z);
		mk_lang_assert(co);

		xx = ((unsigned __int64)(*x));
		yy = ((unsigned __int64)(*y));
		*z = ((mk_num_basic_uint_type)(_umul128(xx, yy, &cc)));
		*co = ((mk_num_basic_uint_type)(cc));
	}
	#endif
	#if defined(_MSC_VER) && _MSC_VER >= 1600 /* VS 2010 */ && (defined(_M_AMD64) || defined(_M_IA64))
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	else if(sizeof(mk_num_basic_uint_type) * mk_lang_charbit <= 64)
	#pragma warning(pop)
	{
		unsigned __int64 xx;
		unsigned __int64 yy;

		mk_lang_assert(x);
		mk_lang_assert(y);
		mk_lang_assert(z);
		mk_lang_assert(co);

		xx = ((unsigned __int64)(*x));
		yy = ((unsigned __int64)(*y));
		*z = ((mk_num_basic_uint_type)(*x * *y));
		*co = ((mk_num_basic_uint_type)(__umulh(xx, yy)));
	}
	#endif
	#if mk_lang_lllong_has != 0
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	else if(sizeof(mk_num_basic_uint_type) * mk_lang_charbit <= 64)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_lang_ulllong_t xx;
		mk_lang_ulllong_t yy;
		mk_lang_ulllong_t zz;

		mk_lang_assert(x);
		mk_lang_assert(y);
		mk_lang_assert(z);
		mk_lang_assert(co);

		xx = ((mk_lang_ulllong_t)(*x));
		yy = ((mk_lang_ulllong_t)(*y));
		zz = ((mk_lang_ulllong_t)(xx * yy));
		*z = ((mk_num_basic_uint_type)(zz));
		*co = ((mk_num_basic_uint_type)(zz >> 64));
	}
	#endif
	else
	{
		#define shift ((int)(sizeof(mk_num_basic_uint_type) * mk_lang_charbit / 2))
		#define mask ((mk_num_basic_uint_type)(((mk_num_basic_uint_type)(((mk_num_basic_uint_type)(1)) << shift)) - ((mk_num_basic_uint_type)(1))))

		mk_num_basic_uint_type m;
		mk_num_basic_uint_type xlo;
		mk_num_basic_uint_type xhi;
		mk_num_basic_uint_type ylo;
		mk_num_basic_uint_type yhi;
		mk_num_basic_uint_type xylo;
		mk_num_basic_uint_type xymi;
		mk_num_basic_uint_type yxmi;
		mk_num_basic_uint_type xyhi;

		mk_lang_assert(x);
		mk_lang_assert(y);
		mk_lang_assert(z);
		mk_lang_assert(co);
		mk_lang_assert(((sizeof(mk_num_basic_uint_type) * mk_lang_charbit) % 2) == 0);

		m = mask;
		xlo = ((mk_num_basic_uint_type)(*x & m));
		xhi = ((mk_num_basic_uint_type)(*x >> shift));
		ylo = ((mk_num_basic_uint_type)(*y & m));
		yhi = ((mk_num_basic_uint_type)(*y >> shift));
		xylo = ((mk_num_basic_uint_type)(xlo * ylo));
		xymi = ((mk_num_basic_uint_type)(xlo * yhi));
		yxmi = ((mk_num_basic_uint_type)(xhi * ylo));
		xyhi = ((mk_num_basic_uint_type)(xhi * yhi));
		*z = ((mk_num_basic_uint_type)(*x * *y));
		*co =
			((mk_num_basic_uint_type)(
				((mk_num_basic_uint_type)(
					((mk_num_basic_uint_type)(
						((mk_num_basic_uint_type)(xymi >> shift)) +
						((mk_num_basic_uint_type)(yxmi >> shift))
					)) +
					xyhi
				)) +
				((mk_num_basic_uint_type)(
					((mk_num_basic_uint_type)(
						((mk_num_basic_uint_type)(
							((mk_num_basic_uint_type)(xymi & m)) +
							((mk_num_basic_uint_type)(yxmi & m))
						)) +
						((mk_num_basic_uint_type)(xylo >> shift))
					)) >>
					shift
				))
			));

		#undef shift
		#undef mask
	}
}

mk_lang_jumbo void mk_num_mul3_sat_cod(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type zz;
	mk_num_basic_uint_type cc;

	mk_lang_assert(z);

	mk_num_mul3_wrap_coe(x, y, &zz, &cc);
	if(cc != 0)
	{
		zz = 0;
		--zz;
	}
	*z = zz;
}

mk_lang_jumbo void mk_num_mul3_sat_coe(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z, mk_num_basic_uint_type* co)
{
	mk_num_basic_uint_type zz;
	mk_num_basic_uint_type cc;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_mul3_wrap_coe(x, y, &zz, &cc);
	if(cc != 0)
	{
		zz = 0;
		--zz;
	}
	*z = zz;
	*co = cc;
}

mk_lang_jumbo void mk_num_mul3_crash(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* z)
{
	mk_num_basic_uint_type cc;

	mk_lang_assert(z);

	mk_num_mul3_wrap_coe(x, y, z, &cc);
	if(cc != 0)
	{
		mk_lang_crash();
	}
}

mk_lang_jumbo void mk_num_mul2_wrap_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_mul3_wrap_cod(x, y, x);
}

mk_lang_jumbo void mk_num_mul2_wrap_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* co)
{
	mk_num_mul3_wrap_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_mul2_sat_cod(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_mul3_sat_cod(x, y, x);
}

mk_lang_jumbo void mk_num_mul2_sat_coe(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* co)
{
	mk_num_mul3_sat_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_mul2_crash(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_mul3_crash(x, y, x);
}


mk_lang_jumbo void mk_num_div3_wrap(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(res);

	*res = ((mk_num_basic_uint_type)(*x / *y));
}

mk_lang_jumbo void mk_num_mod3_wrap(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(res);

	*res = ((mk_num_basic_uint_type)(*x % *y));
}

mk_lang_jumbo void mk_num_divmod3_wrap(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res_div, mk_num_basic_uint_type* res_mod)
{
	mk_num_basic_uint_type xx;
	mk_num_basic_uint_type yy;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(res_div);
	mk_lang_assert(res_mod);

	xx = *x;
	yy = *y;
	*res_div = ((mk_num_basic_uint_type)(xx / yy));
	*res_mod = ((mk_num_basic_uint_type)(xx % yy));
}

mk_lang_jumbo void mk_num_div3_sat(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res)
{
	mk_lang_assert(y);
	mk_lang_assert(res);

	if(*y == 0)
	{
		mk_num_basic_uint_type mx;
		mx = 0;
		--mx;
		*res = mx;
	}
	else
	{
		mk_num_div3_wrap(x, y, res);
	}
}

mk_lang_jumbo void mk_num_mod3_sat(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res)
{
	mk_lang_assert(y);
	mk_lang_assert(res);

	if(*y == 0)
	{
		mk_num_basic_uint_type mx;
		mx = 0;
		--mx;
		*res = mx;
	}
	else
	{
		mk_num_mod3_wrap(x, y, res);
	}
}

mk_lang_jumbo void mk_num_divmod3_sat(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res_div, mk_num_basic_uint_type* res_mod)
{
	mk_lang_assert(y);
	mk_lang_assert(res_div);
	mk_lang_assert(res_mod);

	if(*y == 0)
	{
		mk_num_basic_uint_type mx;
		mx = 0;
		--mx;
		*res_div = mx;
		*res_mod = mx;
	}
	else
	{
		mk_num_divmod3_wrap(x, y, res_div, res_mod);
	}
}

mk_lang_jumbo void mk_num_div3_crash(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res)
{
	mk_lang_assert(y);

	if(*y == 0)
	{
		mk_lang_crash();
	}
	else
	{
		mk_num_div3_wrap(x, y, res);
	}
}

mk_lang_jumbo void mk_num_mod3_crash(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res)
{
	mk_lang_assert(y);

	if(*y == 0)
	{
		mk_lang_crash();
	}
	else
	{
		mk_num_mod3_wrap(x, y, res);
	}
}

mk_lang_jumbo void mk_num_divmod3_crash(mk_num_basic_uint_type const* x, mk_num_basic_uint_type const* y, mk_num_basic_uint_type* res_div, mk_num_basic_uint_type* res_mod)
{
	mk_lang_assert(y);

	if(*y == 0)
	{
		mk_lang_crash();
	}
	else
	{
		mk_num_divmod3_wrap(x, y, res_div, res_mod);
	}
}

mk_lang_jumbo void mk_num_div2_wrap(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_div3_wrap(x, y, x);
}

mk_lang_jumbo void mk_num_mod2_wrap(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_mod3_wrap(x, y, x);
}

mk_lang_jumbo void mk_num_div2_sat(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_div3_sat(x, y, x);
}

mk_lang_jumbo void mk_num_mod2_sat(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_mod3_sat(x, y, x);
}

mk_lang_jumbo void mk_num_div2_crash(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_div3_crash(x, y, x);
}

mk_lang_jumbo void mk_num_mod2_crash(mk_num_basic_uint_type* x, mk_num_basic_uint_type const* y)
{
	mk_num_mod3_crash(x, y, x);
}


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#include "mk_num_basic_uint_undef.h"


#undef mk_num_basic_uint_type
#undef mk_num_basic_uint_name
