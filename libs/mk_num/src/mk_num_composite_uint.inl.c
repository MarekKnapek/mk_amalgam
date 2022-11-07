#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_llong.h"
#include "mk_lang_minmax.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizet.h"
#include "mk_lang_uintmaxt.h"

#include <limits.h> /* CHAR_BIT */
#include <string.h> /* memcpy */


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4514) /* warning C4514: 'xxx': unreferenced inline function has been removed */
#pragma warning(disable:4702) /* warning C4702: unreachable code */
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#pragma warning(disable:5045) /* warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified */
#endif


#include "mk_num_composite_uint_def.h"
#include "mk_num_composite_uint_base_def.h"


mk_lang_jumbo void mk_num_composite_un_normalize(mk_num_composite_base_type* x)
{
	mk_num_composite_base_type mask;

	mk_num_composite_un_base_set_mask(&mask, mk_num_composite_base_bits);
	mk_num_composite_un_base_and2(x, &mask);
}

mk_lang_jumbo void mk_num_composite_un_normalize_msd(mk_num_composite_un_t* x)
{
	mk_num_composite_base_type mask;

	mk_num_composite_un_base_set_mask(&mask, mk_num_composite_bits - (mk_num_composite_un_parts - 1) * mk_num_composite_base_bits);
	mk_num_composite_un_base_and2(&x->m_parts[mk_num_composite_un_parts - 1], &mask);
}


mk_lang_jumbo void mk_num_composite_un_set_zero(mk_num_composite_un_t* x)
{
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_set_zero(&x->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_set_one(mk_num_composite_un_t* x)
{
	int i;

	mk_lang_assert(x);

	mk_num_composite_un_base_set_one(&x->m_parts[0]);
	for(i = 1; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_set_zero(&x->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_set_mask(mk_num_composite_un_t* x, int bits)
{
	mk_lang_assert(x);
	mk_lang_assert(bits > 0 && bits <= mk_num_composite_bits);

	mk_num_composite_un_set_zero(x);
	mk_num_composite_un_inc(x);
	mk_num_composite_un_shl2(x, bits - 1);
	mk_num_composite_un_dec(x);
	mk_num_composite_un_shl2(x, 1);
	mk_num_composite_un_inc(x);
}


mk_lang_jumbo void mk_num_composite_un_from_buff_le(mk_num_composite_un_t* x, void const* buff)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(buff);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_from_buff_le(&x->m_parts[i], ((unsigned char const*)(buff)) + i * sizeof(mk_num_composite_base_type));
	}
}

mk_lang_jumbo void mk_num_composite_un_from_buff_be(mk_num_composite_un_t* x, void const* buff)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(buff);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_from_buff_be(&x->m_parts[i], ((unsigned char const*)(buff)) + (mk_num_composite_un_parts - 1 - i) * sizeof(mk_num_composite_base_type));
	}
}

mk_lang_jumbo void mk_num_composite_un_to_buff_le(mk_num_composite_un_t const* x, void* buff)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(buff);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_to_buff_le(&x->m_parts[i], ((unsigned char*)(buff)) + i * sizeof(mk_num_composite_base_type));
	}
}

mk_lang_jumbo void mk_num_composite_un_to_buff_be(mk_num_composite_un_t const* x, void* buff)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(buff);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_to_buff_be(&x->m_parts[i], ((unsigned char*)(buff)) + (mk_num_composite_un_parts - 1 - i) * sizeof(mk_num_composite_base_type));
	}
}


mk_lang_jumbo void mk_num_composite_un_from_char(mk_num_composite_un_t* x, char src)
{
	unsigned char buff[sizeof(src)];
	unsigned char uint;

	mk_lang_assert(sizeof(uint) == sizeof(src));

	memcpy(buff, &src, sizeof(src));
	memcpy(&uint, buff, sizeof(src));
	mk_num_composite_un_from_uchar(x, uint);
}

mk_lang_jumbo void mk_num_composite_un_from_uchar(mk_num_composite_un_t* x, unsigned char src)
{
	int i;

	mk_lang_assert(x);

	mk_num_composite_un_base_from_uchar(&x->m_parts[0], src);
	for(i = 1; i != sizeof(src) / sizeof(mk_num_composite_base_type) && i != mk_num_composite_un_parts; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		src = ((unsigned char)(src >> mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		mk_num_composite_un_base_from_uchar(&x->m_parts[i], src);
	}
	for(; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_set_zero(&x->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_from_schar(mk_num_composite_un_t* x, signed char src)
{
	unsigned char buff[sizeof(src)];
	unsigned char uint;

	mk_lang_assert(sizeof(uint) == sizeof(src));

	memcpy(buff, &src, sizeof(src));
	memcpy(&uint, buff, sizeof(src));
	mk_num_composite_un_from_uchar(x, uint);
}

mk_lang_jumbo void mk_num_composite_un_from_ushort(mk_num_composite_un_t* x, unsigned short int src)
{
	int i;

	mk_lang_assert(x);

	mk_num_composite_un_base_from_ushort(&x->m_parts[0], src);
	for(i = 1; i != sizeof(src) / sizeof(mk_num_composite_base_type) && i != mk_num_composite_un_parts; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		src = ((unsigned short int)(src >> mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		mk_num_composite_un_base_from_ushort(&x->m_parts[i], src);
	}
	for(; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_set_zero(&x->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_from_sshort(mk_num_composite_un_t* x, signed short int src)
{
	unsigned char buff[sizeof(src)];
	unsigned short int uint;

	mk_lang_assert(sizeof(uint) == sizeof(src));

	memcpy(buff, &src, sizeof(src));
	memcpy(&uint, buff, sizeof(src));
	mk_num_composite_un_from_ushort(x, uint);
}

mk_lang_jumbo void mk_num_composite_un_from_uint(mk_num_composite_un_t* x, unsigned int src)
{
	int i;

	mk_lang_assert(x);

	mk_num_composite_un_base_from_uint(&x->m_parts[0], src);
	for(i = 1; i != sizeof(src) / sizeof(mk_num_composite_base_type) && i != mk_num_composite_un_parts; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		src = ((unsigned int)(src >> mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		mk_num_composite_un_base_from_uint(&x->m_parts[i], src);
	}
	for(; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_set_zero(&x->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_from_sint(mk_num_composite_un_t* x, signed int src)
{
	unsigned char buff[sizeof(src)];
	unsigned int uint;

	mk_lang_assert(sizeof(uint) == sizeof(src));

	memcpy(buff, &src, sizeof(src));
	memcpy(&uint, buff, sizeof(src));
	mk_num_composite_un_from_uint(x, uint);
}

mk_lang_jumbo void mk_num_composite_un_from_ulong(mk_num_composite_un_t* x, unsigned long int src)
{
	int i;

	mk_lang_assert(x);

	mk_num_composite_un_base_from_ulong(&x->m_parts[0], src);
	for(i = 1; i != sizeof(src) / sizeof(mk_num_composite_base_type) && i != mk_num_composite_un_parts; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		src = ((unsigned long int)(src >> mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		mk_num_composite_un_base_from_ulong(&x->m_parts[i], src);
	}
	for(; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_set_zero(&x->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_from_slong(mk_num_composite_un_t* x, signed long int src)
{
	unsigned char buff[sizeof(src)];
	unsigned long int uint;

	mk_lang_assert(sizeof(uint) == sizeof(src));

	memcpy(buff, &src, sizeof(src));
	memcpy(&uint, buff, sizeof(src));
	mk_num_composite_un_from_ulong(x, uint);
}

mk_lang_jumbo void mk_num_composite_un_from_ullong(mk_num_composite_un_t* x, mk_lang_ullong_t src)
{
	int i;

	mk_lang_assert(x);

	mk_num_composite_un_base_from_ullong(&x->m_parts[0], src);
	for(i = 1; i != sizeof(src) / sizeof(mk_num_composite_base_type) && i != mk_num_composite_un_parts; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		src = ((mk_lang_ullong_t)(src >> mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		mk_num_composite_un_base_from_ullong(&x->m_parts[i], src);
	}
	for(; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_set_zero(&x->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_from_sllong(mk_num_composite_un_t* x, mk_lang_sllong_t src)
{
	unsigned char buff[sizeof(src)];
	mk_lang_ullong_t uint;

	mk_lang_assert(sizeof(uint) == sizeof(src));

	memcpy(buff, &src, sizeof(src));
	memcpy(&uint, buff, sizeof(src));
	mk_num_composite_un_from_ullong(x, uint);
}

mk_lang_jumbo void mk_num_composite_un_from_sizet(mk_num_composite_un_t* x, mk_lang_size_t src)
{
	int i;

	mk_lang_assert(x);

	mk_num_composite_un_base_from_sizet(&x->m_parts[0], src);
	for(i = 1; i != sizeof(src) / sizeof(mk_num_composite_base_type) && i != mk_num_composite_un_parts; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		src = ((mk_lang_size_t)(src >> mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		mk_num_composite_un_base_from_sizet(&x->m_parts[i], src);
	}
	for(; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_set_zero(&x->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_from_umaxt(mk_num_composite_un_t* x, mk_lang_uintmax_t src)
{
	int i;

	mk_lang_assert(x);

	mk_num_composite_un_base_from_umaxt(&x->m_parts[0], src);
	for(i = 1; i != sizeof(src) / sizeof(mk_num_composite_base_type) && i != mk_num_composite_un_parts; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '>>': shift count negative or too big, undefined behavior */
		#pragma warning(disable:4333) /* warning C4333: '>>': right shift by too large amount, data loss */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: right shift count >= width of type [-Wshift-count-overflow] */
		#endif
		src = ((mk_lang_uintmax_t)(src >> mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		mk_num_composite_un_base_from_umaxt(&x->m_parts[i], src);
	}
	for(; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_set_zero(&x->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_from_smaxt(mk_num_composite_un_t* x, mk_lang_sintmax_t src)
{
	unsigned char buff[sizeof(src)];
	mk_lang_uintmax_t uint;

	mk_lang_assert(sizeof(uint) == sizeof(src));

	memcpy(buff, &src, sizeof(src));
	memcpy(&uint, buff, sizeof(src));
	mk_num_composite_un_from_umaxt(x, uint);
}


mk_lang_nodiscard mk_lang_jumbo char mk_num_composite_un_to_char(mk_num_composite_un_t const* x)
{
	unsigned char uint;
	unsigned char buff[sizeof(uint)];
	char sint;

	mk_lang_assert(x);
	mk_lang_assert(sizeof(uint) == sizeof(sint));

	uint = mk_num_composite_un_to_uchar(x);
	memcpy(buff, &uint, sizeof(uint));
	memcpy(&sint, buff, sizeof(uint));
	return sint;
}

mk_lang_nodiscard mk_lang_jumbo unsigned char mk_num_composite_un_to_uchar(mk_num_composite_un_t const* x)
{
	#define n mk_lang_min(mk_num_composite_un_parts, mk_lang_max(1, sizeof(uint) / sizeof(mk_num_composite_base_type)))

	unsigned char uint;
	int i;

	mk_lang_assert(x);

	uint = mk_num_composite_un_base_to_uchar(&x->m_parts[n - 1]);
	for(i = 1; i != n; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		uint = ((unsigned char)(uint << mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		uint = ((unsigned char)(uint | mk_num_composite_un_base_to_uchar(&x->m_parts[n - 1 - i])));
	}
	return uint;

	#undef n
}

mk_lang_nodiscard mk_lang_jumbo signed char mk_num_composite_un_to_schar(mk_num_composite_un_t const* x)
{
	unsigned char uint;
	unsigned char buff[sizeof(uint)];
	signed char sint;

	mk_lang_assert(x);
	mk_lang_assert(sizeof(uint) == sizeof(sint));

	uint = mk_num_composite_un_to_uchar(x);
	memcpy(buff, &uint, sizeof(uint));
	memcpy(&sint, buff, sizeof(uint));
	return sint;
}

mk_lang_nodiscard mk_lang_jumbo unsigned short int mk_num_composite_un_to_ushort(mk_num_composite_un_t const* x)
{
	#define n mk_lang_min(mk_num_composite_un_parts, mk_lang_max(1, sizeof(uint) / sizeof(mk_num_composite_base_type)))

	unsigned short int uint;
	int i;

	mk_lang_assert(x);

	uint = mk_num_composite_un_base_to_ushort(&x->m_parts[n - 1]);
	for(i = 1; i != n; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		uint = ((unsigned short int)(uint << mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		uint = ((unsigned short int)(uint | mk_num_composite_un_base_to_ushort(&x->m_parts[n - 1 - i])));
	}
	return uint;

	#undef n
}

mk_lang_nodiscard mk_lang_jumbo signed short int mk_num_composite_un_to_sshort(mk_num_composite_un_t const* x)
{
	unsigned short int uint;
	unsigned char buff[sizeof(uint)];
	signed short int sint;

	mk_lang_assert(x);
	mk_lang_assert(sizeof(uint) == sizeof(sint));

	uint = mk_num_composite_un_to_ushort(x);
	memcpy(buff, &uint, sizeof(uint));
	memcpy(&sint, buff, sizeof(uint));
	return sint;
}

mk_lang_nodiscard mk_lang_jumbo unsigned int mk_num_composite_un_to_uint(mk_num_composite_un_t const* x)
{
	#define n mk_lang_min(mk_num_composite_un_parts, mk_lang_max(1, sizeof(uint) / sizeof(mk_num_composite_base_type)))

	unsigned int uint;
	int i;

	mk_lang_assert(x);

	uint = mk_num_composite_un_base_to_uint(&x->m_parts[n - 1]);
	for(i = 1; i != n; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		uint = ((unsigned int)(uint << mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		uint = ((unsigned int)(uint | mk_num_composite_un_base_to_uint(&x->m_parts[n - 1 - i])));
	}
	return uint;

	#undef n
}

mk_lang_nodiscard mk_lang_jumbo signed int mk_num_composite_un_to_sint(mk_num_composite_un_t const* x)
{
	unsigned int uint;
	unsigned char buff[sizeof(uint)];
	signed int sint;

	mk_lang_assert(x);
	mk_lang_assert(sizeof(uint) == sizeof(sint));

	uint = mk_num_composite_un_to_uint(x);
	memcpy(buff, &uint, sizeof(uint));
	memcpy(&sint, buff, sizeof(uint));
	return sint;
}

mk_lang_nodiscard mk_lang_jumbo unsigned long int mk_num_composite_un_to_ulong(mk_num_composite_un_t const* x)
{
	#define n mk_lang_min(mk_num_composite_un_parts, mk_lang_max(1, sizeof(uint) / sizeof(mk_num_composite_base_type)))

	unsigned long int uint;
	int i;

	mk_lang_assert(x);

	uint = mk_num_composite_un_base_to_ulong(&x->m_parts[n - 1]);
	for(i = 1; i != n; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		uint = ((unsigned long int)(uint << mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		uint = ((unsigned long int)(uint | mk_num_composite_un_base_to_ulong(&x->m_parts[n - 1 - i])));
	}
	return uint;

	#undef n
}

mk_lang_nodiscard mk_lang_jumbo signed long int mk_num_composite_un_to_slong(mk_num_composite_un_t const* x)
{
	unsigned long int uint;
	unsigned char buff[sizeof(uint)];
	signed long int sint;

	mk_lang_assert(x);
	mk_lang_assert(sizeof(uint) == sizeof(sint));

	uint = mk_num_composite_un_to_ulong(x);
	memcpy(buff, &uint, sizeof(uint));
	memcpy(&sint, buff, sizeof(uint));
	return sint;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_ullong_t mk_num_composite_un_to_ullong(mk_num_composite_un_t const* x)
{
	#define n mk_lang_min(mk_num_composite_un_parts, mk_lang_max(1, sizeof(uint) / sizeof(mk_num_composite_base_type)))

	mk_lang_ullong_t uint;
	int i;

	mk_lang_assert(x);

	uint = mk_num_composite_un_base_to_ullong(&x->m_parts[n - 1]);
	for(i = 1; i != n; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		uint = ((mk_lang_ullong_t)(uint << mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		uint = ((mk_lang_ullong_t)(uint | mk_num_composite_un_base_to_ullong(&x->m_parts[n - 1 - i])));
	}
	return uint;

	#undef n
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_sllong_t mk_num_composite_un_to_sllong(mk_num_composite_un_t const* x)
{
	mk_lang_ullong_t uint;
	unsigned char buff[sizeof(uint)];
	mk_lang_sllong_t sint;

	mk_lang_assert(x);
	mk_lang_assert(sizeof(uint) == sizeof(sint));

	uint = mk_num_composite_un_to_ullong(x);
	memcpy(buff, &uint, sizeof(uint));
	memcpy(&sint, buff, sizeof(uint));
	return sint;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_num_composite_un_to_sizet(mk_num_composite_un_t const* x)
{
	#define n mk_lang_min(mk_num_composite_un_parts, mk_lang_max(1, sizeof(uint) / sizeof(mk_num_composite_base_type)))

	mk_lang_size_t uint;
	int i;

	mk_lang_assert(x);

	uint = mk_num_composite_un_base_to_sizet(&x->m_parts[n - 1]);
	for(i = 1; i != n; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		uint = ((mk_lang_size_t)(uint << mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		uint = ((mk_lang_size_t)(uint | mk_num_composite_un_base_to_sizet(&x->m_parts[n - 1 - i])));
	}
	return uint;

	#undef n
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_uintmax_t mk_num_composite_un_to_umaxt(mk_num_composite_un_t const* x)
{
	#define n mk_lang_min(mk_num_composite_un_parts, mk_lang_max(1, sizeof(uint) / sizeof(mk_num_composite_base_type)))

	mk_lang_uintmax_t uint;
	int i;

	mk_lang_assert(x);

	uint = mk_num_composite_un_base_to_umaxt(&x->m_parts[n - 1]);
	for(i = 1; i != n; ++i)
	{
		#if defined(_MSC_VER)
		#pragma warning(push)
		#pragma warning(disable:4293) /* warning C4293: '<<': shift count negative or too big, undefined behavior */
		#endif
		#if defined(__GNUC__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wshift-count-overflow" /* warning: left shift count >= width of type [-Wshift-count-overflow] */
		#endif
		uint = ((mk_lang_uintmax_t)(uint << mk_num_composite_base_bits));
		#if defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
		#if defined(_MSC_VER)
		#pragma warning(pop)
		#endif
		uint = ((mk_lang_uintmax_t)(uint | mk_num_composite_un_base_to_umaxt(&x->m_parts[n - 1 - i])));
	}
	return uint;

	#undef n
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_sintmax_t mk_num_composite_un_to_smaxt(mk_num_composite_un_t const* x)
{
	mk_lang_uintmax_t uint;
	unsigned char buff[sizeof(uint)];
	mk_lang_sintmax_t sint;

	mk_lang_assert(x);
	mk_lang_assert(sizeof(uint) == sizeof(sint));

	uint = mk_num_composite_un_to_umaxt(x);
	memcpy(buff, &uint, sizeof(uint));
	memcpy(&sint, buff, sizeof(uint));
	return sint;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_is_zero(mk_num_composite_un_t const* x)
{
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		if(!mk_num_composite_un_base_is_zero(&x->m_parts[i]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_eq(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		if(!mk_num_composite_un_base_eq(&x->m_parts[i], &y->m_parts[i]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_ne(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y)
{
	return !mk_num_composite_un_eq(x, y);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_lt(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		if(mk_num_composite_un_base_lt(&x->m_parts[mk_num_composite_un_parts - 1 - i], &y->m_parts[mk_num_composite_un_parts - 1 - i]))
		{
			return mk_lang_true;
		}
		else if(mk_num_composite_un_base_gt(&x->m_parts[mk_num_composite_un_parts - 1 - i], &y->m_parts[mk_num_composite_un_parts - 1 - i]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_false;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_le(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		if(mk_num_composite_un_base_lt(&x->m_parts[mk_num_composite_un_parts - 1 - i], &y->m_parts[mk_num_composite_un_parts - 1 - i]))
		{
			return mk_lang_true;
		}
		else if(mk_num_composite_un_base_gt(&x->m_parts[mk_num_composite_un_parts - 1 - i], &y->m_parts[mk_num_composite_un_parts - 1 - i]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_gt(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		if(mk_num_composite_un_base_gt(&x->m_parts[mk_num_composite_un_parts - 1 - i], &y->m_parts[mk_num_composite_un_parts - 1 - i]))
		{
			return mk_lang_true;
		}
		else if(mk_num_composite_un_base_lt(&x->m_parts[mk_num_composite_un_parts - 1 - i], &y->m_parts[mk_num_composite_un_parts - 1 - i]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_false;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_num_composite_un_ge(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		if(mk_num_composite_un_base_gt(&x->m_parts[mk_num_composite_un_parts - 1 - i], &y->m_parts[mk_num_composite_un_parts - 1 - i]))
		{
			return mk_lang_true;
		}
		else if(mk_num_composite_un_base_lt(&x->m_parts[mk_num_composite_un_parts - 1 - i], &y->m_parts[mk_num_composite_un_parts - 1 - i]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
}


mk_lang_jumbo void mk_num_composite_un_inc(mk_num_composite_un_t* x)
{
	int i;

	mk_lang_assert(x);

	i = 0;
	do
	{
		mk_num_composite_un_base_inc(&x->m_parts[i]);
	}
	while(mk_num_composite_un_base_is_zero(&x->m_parts[i++]) && i != mk_num_composite_un_parts);
	mk_num_composite_un_normalize_msd(x);
}

mk_lang_jumbo void mk_num_composite_un_dec(mk_num_composite_un_t* x)
{
	int i;
	mk_lang_bool_t b;

	mk_lang_assert(x);

	i = 0;
	do
	{
		b = mk_num_composite_un_base_is_zero(&x->m_parts[i]);
		mk_num_composite_un_base_dec(&x->m_parts[i]);
		++i;
	}
	while(b && i != mk_num_composite_un_parts);
	mk_num_composite_un_normalize_msd(x);
}


mk_lang_jumbo void mk_num_composite_un_not2(mk_num_composite_un_t const* x, mk_num_composite_un_t* y)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_not2(&x->m_parts[i], &y->m_parts[i]);
	}
	mk_num_composite_un_normalize_msd(y);
}

mk_lang_jumbo void mk_num_composite_un_not1(mk_num_composite_un_t* x)
{
	mk_num_composite_un_not2(x, x);
}

mk_lang_jumbo void mk_num_composite_un_or3(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_or3(&x->m_parts[i], &y->m_parts[i], &z->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_or2(mk_num_composite_un_t* x, mk_num_composite_un_t const* y)
{
	mk_num_composite_un_or3(x, y, x);
}

mk_lang_jumbo void mk_num_composite_un_and3(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_and3(&x->m_parts[i], &y->m_parts[i], &z->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_and2(mk_num_composite_un_t* x, mk_num_composite_un_t const* y)
{
	mk_num_composite_un_and3(x, y, x);
}

mk_lang_jumbo void mk_num_composite_un_xor3(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	for(i = 0; i != mk_num_composite_un_parts; ++i)
	{
		mk_num_composite_un_base_xor3(&x->m_parts[i], &y->m_parts[i], &z->m_parts[i]);
	}
}

mk_lang_jumbo void mk_num_composite_un_xor2(mk_num_composite_un_t* x, mk_num_composite_un_t const* y)
{
	mk_num_composite_un_xor3(x, y, x);
}


mk_lang_jumbo void mk_num_composite_un_shl3(mk_num_composite_un_t const* x, int bits, mk_num_composite_un_t* y)
{
	int big;
	int smol;
	int i;
	mk_num_composite_base_type tmp1;
	mk_num_composite_base_type tmp2;

	mk_lang_assert(x);
	mk_lang_assert(bits >=0 && bits < mk_num_composite_bits);
	mk_lang_assert(y);

	big = bits / mk_num_composite_base_bits;
	smol = bits % mk_num_composite_base_bits;
	if(smol == 0)
	{
		for(i = 0; i != mk_num_composite_un_parts - big; ++i)
		{
			y->m_parts[mk_num_composite_un_parts - 1 - i] = x->m_parts[mk_num_composite_un_parts - 1 - big - i];
		}
		for(; i != mk_num_composite_un_parts; ++i)
		{
			mk_num_composite_un_base_set_zero(&y->m_parts[mk_num_composite_un_parts - 1 - i]);
		}
		mk_num_composite_un_normalize_msd(y);
	}
	else
	{
		for(i = 0; i != mk_num_composite_un_parts - big - 1; ++i)
		{
			mk_num_composite_un_base_shl3(&x->m_parts[mk_num_composite_un_parts - 1 - big - i], smol, &tmp1);
			mk_num_composite_un_base_shr3(&x->m_parts[mk_num_composite_un_parts - 1 - big - i - 1], mk_num_composite_base_bits - smol, &tmp2);
			mk_num_composite_un_base_or3(&tmp1, &tmp2, &y->m_parts[mk_num_composite_un_parts - 1 - i]);
		}
		mk_num_composite_un_base_shl3(&x->m_parts[mk_num_composite_un_parts - 1 - big - i], smol, &y->m_parts[mk_num_composite_un_parts - 1 - i]);
		for(++i; i != mk_num_composite_un_parts; ++i)
		{
			mk_num_composite_un_base_set_zero(&y->m_parts[mk_num_composite_un_parts - 1 - i]);
		}
		mk_num_composite_un_normalize_msd(y);
	}
}

mk_lang_jumbo void mk_num_composite_un_shl2(mk_num_composite_un_t* x, int bits)
{
	mk_num_composite_un_shl3(x, bits, x);
}

mk_lang_jumbo void mk_num_composite_un_shr3(mk_num_composite_un_t const* x, int bits, mk_num_composite_un_t* y)
{
	int big;
	int smol;
	int i;
	mk_num_composite_base_type tmp1;
	mk_num_composite_base_type tmp2;

	mk_lang_assert(x);
	mk_lang_assert(bits >=0 && bits < mk_num_composite_bits);
	mk_lang_assert(y);

	big = bits / mk_num_composite_base_bits;
	smol = bits % mk_num_composite_base_bits;
	if(smol == 0)
	{
		for(i = 0; i != mk_num_composite_un_parts - big; ++i)
		{
			y->m_parts[i] = x->m_parts[big + i];
		}
		for(; i != mk_num_composite_un_parts; ++i)
		{
			mk_num_composite_un_base_set_zero(&y->m_parts[i]);
		}
	}
	else
	{
		for(i = 0; i != mk_num_composite_un_parts - big - 1; ++i)
		{
			mk_num_composite_un_base_shr3(&x->m_parts[big + i], smol, &tmp1);
			mk_num_composite_un_base_shl3(&x->m_parts[big + i + 1], mk_num_composite_base_bits - smol, &tmp2);
			mk_num_composite_un_base_or3(&tmp1, &tmp2, &y->m_parts[i]);
		}
		mk_num_composite_un_base_shr3(&x->m_parts[big + i], smol, &y->m_parts[i]);
		for(++i; i != mk_num_composite_un_parts; ++i)
		{
			mk_num_composite_un_base_set_zero(&y->m_parts[i]);
		}
	}
}

mk_lang_jumbo void mk_num_composite_un_shr2(mk_num_composite_un_t* x, int bits)
{
	mk_num_composite_un_shr3(x, bits, x);
}


mk_lang_jumbo void mk_num_composite_un_add3_wrap_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 1)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_add3_wrap_cid_cod(&x->m_parts[0], &y->m_parts[0], &z->m_parts[0]);
	}
	else
	{
		mk_lang_bool_t b;
		int i;
		mk_num_composite_un_base_add3_wrap_cid_coe(&x->m_parts[0], &y->m_parts[0], &z->m_parts[0], &b);
		for(i = 1; i != mk_num_composite_un_parts - 1; ++i)
		{
			mk_num_composite_un_base_add3_wrap_cie_coe(&x->m_parts[i], &y->m_parts[i], b, &z->m_parts[i], &b);
		}
		mk_num_composite_un_base_add3_wrap_cie_cod(&x->m_parts[mk_num_composite_un_parts - 1], &y->m_parts[mk_num_composite_un_parts - 1], b, &z->m_parts[mk_num_composite_un_parts - 1]);
	}
	mk_num_composite_un_normalize_msd(z);
}

mk_lang_jumbo void mk_num_composite_un_add3_wrap_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 1)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_add3_wrap_cid_coe(&x->m_parts[0], &y->m_parts[0], &z->m_parts[0], co);
	}
	else
	{
		mk_lang_bool_t b;
		int i;
		mk_num_composite_un_base_add3_wrap_cid_coe(&x->m_parts[0], &y->m_parts[0], &z->m_parts[0], &b);
		for(i = 1; i != mk_num_composite_un_parts - 1; ++i)
		{
			mk_num_composite_un_base_add3_wrap_cie_coe(&x->m_parts[i], &y->m_parts[i], b, &z->m_parts[i], &b);
		}
		mk_num_composite_un_base_add3_wrap_cie_coe(&x->m_parts[mk_num_composite_un_parts - 1], &y->m_parts[mk_num_composite_un_parts - 1], b, &z->m_parts[mk_num_composite_un_parts - 1], co);
	}
}

mk_lang_jumbo void mk_num_composite_un_add3_wrap_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 1)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_add3_wrap_cie_cod(&x->m_parts[0], &y->m_parts[0], ci, &z->m_parts[0]);
	}
	else
	{
		mk_lang_bool_t b;
		int i;
		mk_num_composite_un_base_add3_wrap_cie_coe(&x->m_parts[0], &y->m_parts[0], ci, &z->m_parts[0], &b);
		for(i = 1; i != mk_num_composite_un_parts - 1; ++i)
		{
			mk_num_composite_un_base_add3_wrap_cie_coe(&x->m_parts[i], &y->m_parts[i], b, &z->m_parts[i], &b);
		}
		mk_num_composite_un_base_add3_wrap_cie_cod(&x->m_parts[mk_num_composite_un_parts - 1], &y->m_parts[mk_num_composite_un_parts - 1], b, &z->m_parts[mk_num_composite_un_parts - 1]);
	}
}

mk_lang_jumbo void mk_num_composite_un_add3_wrap_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 1)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_add3_wrap_cie_coe(&x->m_parts[0], &y->m_parts[0], ci, &z->m_parts[0], co);
	}
	else
	{
		mk_lang_bool_t b;
		int i;
		mk_num_composite_un_base_add3_wrap_cie_coe(&x->m_parts[0], &y->m_parts[0], ci, &z->m_parts[0], &b);
		for(i = 1; i != mk_num_composite_un_parts - 1; ++i)
		{
			mk_num_composite_un_base_add3_wrap_cie_coe(&x->m_parts[i], &y->m_parts[i], b, &z->m_parts[i], &b);
		}
		mk_num_composite_un_base_add3_wrap_cie_coe(&x->m_parts[mk_num_composite_un_parts - 1], &y->m_parts[mk_num_composite_un_parts - 1], b, &z->m_parts[mk_num_composite_un_parts - 1], co);
	}
}

mk_lang_jumbo void mk_num_composite_un_add3_sat_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	mk_lang_bool_t b;
	mk_num_composite_base_type smol;
	int i;

	mk_lang_assert(z);

	mk_num_composite_un_add3_wrap_cid_coe(x, y, z, &b);
	if(b)
	{
		mk_num_composite_un_base_set_zero(&smol);
		mk_num_composite_un_base_dec(&smol);
		for(i = 0; i != mk_num_composite_un_parts; ++i)
		{
			z->m_parts[i] = smol;
		}
	}
}

mk_lang_jumbo void mk_num_composite_un_add3_sat_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_bool_t b;
	mk_num_composite_base_type smol;
	int i;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_composite_un_add3_wrap_cid_coe(x, y, z, &b);
	if(b)
	{
		mk_num_composite_un_base_set_zero(&smol);
		mk_num_composite_un_base_dec(&smol);
		for(i = 0; i != mk_num_composite_un_parts; ++i)
		{
			z->m_parts[i] = smol;
		}
	}
	*co = b;
}

mk_lang_jumbo void mk_num_composite_un_add3_sat_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z)
{
	mk_lang_bool_t b;
	mk_num_composite_base_type smol;
	int i;

	mk_lang_assert(z);

	mk_num_composite_un_add3_wrap_cie_coe(x, y, ci, z, &b);
	if(b)
	{
		mk_num_composite_un_base_set_zero(&smol);
		mk_num_composite_un_base_dec(&smol);
		for(i = 0; i != mk_num_composite_un_parts; ++i)
		{
			z->m_parts[i] = smol;
		}
	}
}

mk_lang_jumbo void mk_num_composite_un_add3_sat_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_bool_t b;
	mk_num_composite_base_type smol;
	int i;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_composite_un_add3_wrap_cie_coe(x, y, ci, z, &b);
	if(b)
	{
		mk_num_composite_un_base_set_zero(&smol);
		mk_num_composite_un_base_dec(&smol);
		for(i = 0; i != mk_num_composite_un_parts; ++i)
		{
			z->m_parts[i] = smol;
		}
	}
	*co = b;
}

mk_lang_jumbo void mk_num_composite_un_add3_crash_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	mk_lang_bool_t b;

	mk_num_composite_un_add3_wrap_cid_coe(x, y, z, &b);
	if(b)
	{
		mk_lang_crash();
	}
}

mk_lang_jumbo void mk_num_composite_un_add3_crash_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_composite_un_add3_crash_cid_cod(x, y, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_composite_un_add3_crash_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z)
{
	mk_lang_bool_t b;

	mk_num_composite_un_add3_wrap_cie_coe(x, y, ci, z, &b);
	if(b)
	{
		mk_lang_crash();
	}
}

mk_lang_jumbo void mk_num_composite_un_add3_crash_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_composite_un_add3_crash_cie_cod(x, y, ci, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_composite_un_add2_wrap_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y)
{
	mk_num_composite_un_add3_wrap_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_composite_un_add2_wrap_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co)
{
	mk_num_composite_un_add3_wrap_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_composite_un_add2_wrap_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci)
{
	mk_num_composite_un_add3_wrap_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_composite_un_add2_wrap_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_composite_un_add3_wrap_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_composite_un_add2_sat_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y)
{
	mk_num_composite_un_add3_sat_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_composite_un_add2_sat_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co)
{
	mk_num_composite_un_add3_sat_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_composite_un_add2_sat_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci)
{
	mk_num_composite_un_add3_sat_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_composite_un_add2_sat_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_composite_un_add3_sat_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_composite_un_add2_crash_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y)
{
	mk_num_composite_un_add3_crash_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_composite_un_add2_crash_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_composite_un_add3_crash_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_composite_un_add2_crash_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci)
{
	mk_num_composite_un_add3_crash_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_composite_un_add2_crash_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co)
{
	mk_num_composite_un_add3_crash_cid_coe(x, y, x, co);
}


mk_lang_jumbo void mk_num_composite_un_sub3_wrap_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 1)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_sub3_wrap_cid_cod(&x->m_parts[0], &y->m_parts[0], &z->m_parts[0]);
	}
	else
	{
		mk_lang_bool_t b;
		int i;
		mk_num_composite_un_base_sub3_wrap_cid_coe(&x->m_parts[0], &y->m_parts[0], &z->m_parts[0], &b);
		for(i = 1; i != mk_num_composite_un_parts - 1; ++i)
		{
			mk_num_composite_un_base_sub3_wrap_cie_coe(&x->m_parts[i], &y->m_parts[i], b, &z->m_parts[i], &b);
		}
		mk_num_composite_un_base_sub3_wrap_cie_cod(&x->m_parts[mk_num_composite_un_parts - 1], &y->m_parts[mk_num_composite_un_parts - 1], b, &z->m_parts[mk_num_composite_un_parts - 1]);
	}
	mk_num_composite_un_normalize_msd(z);
}

mk_lang_jumbo void mk_num_composite_un_sub3_wrap_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 1)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_sub3_wrap_cid_coe(&x->m_parts[0], &y->m_parts[0], &z->m_parts[0], co);
	}
	else
	{
		mk_lang_bool_t b;
		int i;
		mk_num_composite_un_base_sub3_wrap_cid_coe(&x->m_parts[0], &y->m_parts[0], &z->m_parts[0], &b);
		for(i = 1; i != mk_num_composite_un_parts - 1; ++i)
		{
			mk_num_composite_un_base_sub3_wrap_cie_coe(&x->m_parts[i], &y->m_parts[i], b, &z->m_parts[i], &b);
		}
		mk_num_composite_un_base_sub3_wrap_cie_coe(&x->m_parts[mk_num_composite_un_parts - 1], &y->m_parts[mk_num_composite_un_parts - 1], b, &z->m_parts[mk_num_composite_un_parts - 1], co);
	}
}

mk_lang_jumbo void mk_num_composite_un_sub3_wrap_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 1)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_sub3_wrap_cie_cod(&x->m_parts[0], &y->m_parts[0], ci, &z->m_parts[0]);
	}
	else
	{
		mk_lang_bool_t b;
		int i;
		mk_num_composite_un_base_sub3_wrap_cie_coe(&x->m_parts[0], &y->m_parts[0], ci, &z->m_parts[0], &b);
		for(i = 1; i != mk_num_composite_un_parts - 1; ++i)
		{
			mk_num_composite_un_base_sub3_wrap_cie_coe(&x->m_parts[i], &y->m_parts[i], b, &z->m_parts[i], &b);
		}
		mk_num_composite_un_base_sub3_wrap_cie_cod(&x->m_parts[mk_num_composite_un_parts - 1], &y->m_parts[mk_num_composite_un_parts - 1], b, &z->m_parts[mk_num_composite_un_parts - 1]);
	}
}

mk_lang_jumbo void mk_num_composite_un_sub3_wrap_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 1)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_sub3_wrap_cie_coe(&x->m_parts[0], &y->m_parts[0], ci, &z->m_parts[0], co);
	}
	else
	{
		mk_lang_bool_t b;
		int i;
		mk_num_composite_un_base_sub3_wrap_cie_coe(&x->m_parts[0], &y->m_parts[0], ci, &z->m_parts[0], &b);
		for(i = 1; i != mk_num_composite_un_parts - 1; ++i)
		{
			mk_num_composite_un_base_sub3_wrap_cie_coe(&x->m_parts[i], &y->m_parts[i], b, &z->m_parts[i], &b);
		}
		mk_num_composite_un_base_sub3_wrap_cie_coe(&x->m_parts[mk_num_composite_un_parts - 1], &y->m_parts[mk_num_composite_un_parts - 1], b, &z->m_parts[mk_num_composite_un_parts - 1], co);
	}
}

mk_lang_jumbo void mk_num_composite_un_sub3_sat_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	mk_lang_bool_t b;
	mk_num_composite_base_type smol;
	int i;

	mk_lang_assert(z);

	mk_num_composite_un_sub3_wrap_cid_coe(x, y, z, &b);
	if(b)
	{
		mk_num_composite_un_base_set_zero(&smol);
		for(i = 0; i != mk_num_composite_un_parts; ++i)
		{
			z->m_parts[i] = smol;
		}
	}
}

mk_lang_jumbo void mk_num_composite_un_sub3_sat_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_bool_t b;
	mk_num_composite_base_type smol;
	int i;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_composite_un_sub3_wrap_cid_coe(x, y, z, &b);
	if(b)
	{
		mk_num_composite_un_base_set_zero(&smol);
		for(i = 0; i != mk_num_composite_un_parts; ++i)
		{
			z->m_parts[i] = smol;
		}
	}
	*co = b;
}

mk_lang_jumbo void mk_num_composite_un_sub3_sat_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z)
{
	mk_lang_bool_t b;
	mk_num_composite_base_type smol;
	int i;

	mk_lang_assert(z);

	mk_num_composite_un_sub3_wrap_cie_coe(x, y, ci, z, &b);
	if(b)
	{
		mk_num_composite_un_base_set_zero(&smol);
		for(i = 0; i != mk_num_composite_un_parts; ++i)
		{
			z->m_parts[i] = smol;
		}
	}
}

mk_lang_jumbo void mk_num_composite_un_sub3_sat_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_bool_t b;
	mk_num_composite_base_type smol;
	int i;

	mk_lang_assert(z);
	mk_lang_assert(co);

	mk_num_composite_un_sub3_wrap_cie_coe(x, y, ci, z, &b);
	if(b)
	{
		mk_num_composite_un_base_set_zero(&smol);
		for(i = 0; i != mk_num_composite_un_parts; ++i)
		{
			z->m_parts[i] = smol;
		}
	}
	*co = b;
}

mk_lang_jumbo void mk_num_composite_un_sub3_crash_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	mk_lang_bool_t b;

	mk_num_composite_un_sub3_wrap_cid_coe(x, y, z, &b);
	if(b)
	{
		mk_lang_crash();
	}
}

mk_lang_jumbo void mk_num_composite_un_sub3_crash_cid_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_composite_un_sub3_crash_cid_cod(x, y, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_composite_un_sub3_crash_cie_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z)
{
	mk_lang_bool_t b;

	mk_num_composite_un_sub3_wrap_cie_coe(x, y, ci, z, &b);
	if(b)
	{
		mk_lang_crash();
	}
}

mk_lang_jumbo void mk_num_composite_un_sub3_crash_cie_coe(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_num_composite_un_t* z, mk_lang_bool_t* co)
{
	mk_lang_assert(co);

	mk_num_composite_un_add3_crash_cie_cod(x, y, ci, z);
	*co = mk_lang_false;
}

mk_lang_jumbo void mk_num_composite_un_sub2_wrap_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y)
{
	mk_num_composite_un_sub3_wrap_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_composite_un_sub2_wrap_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co)
{
	mk_num_composite_un_sub3_wrap_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_composite_un_sub2_wrap_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci)
{
	mk_num_composite_un_sub3_wrap_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_composite_un_sub2_wrap_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_composite_un_sub3_wrap_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_composite_un_sub2_sat_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y)
{
	mk_num_composite_un_sub3_sat_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_composite_un_sub2_sat_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co)
{
	mk_num_composite_un_sub3_sat_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_composite_un_sub2_sat_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci)
{
	mk_num_composite_un_sub3_sat_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_composite_un_sub2_sat_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_composite_un_sub3_sat_cie_coe(x, y, ci, x, co);
}

mk_lang_jumbo void mk_num_composite_un_sub2_crash_cid_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y)
{
	mk_num_composite_un_sub3_crash_cid_cod(x, y, x);
}

mk_lang_jumbo void mk_num_composite_un_sub2_crash_cid_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t* co)
{
	mk_num_composite_un_sub3_crash_cid_coe(x, y, x, co);
}

mk_lang_jumbo void mk_num_composite_un_sub2_crash_cie_cod(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci)
{
	mk_num_composite_un_sub3_crash_cie_cod(x, y, ci, x);
}

mk_lang_jumbo void mk_num_composite_un_sub2_crash_cie_coe(mk_num_composite_un_t* x, mk_num_composite_un_t const* y, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_num_composite_un_sub3_crash_cie_coe(x, y, ci, x, co);
}


mk_lang_jumbo void mk_num_composite_un_mul3_wrap_cid_cod_restrict(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	mk_num_composite_base_type digit1;
	mk_lang_bool_t c;
	mk_num_composite_base_type digit2;
	int j;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(z != x && z != y);
	mk_lang_assert(mk_num_composite_un_parts >= 2);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 2)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[0], &x->m_parts[0], &z->m_parts[0], &z->m_parts[1]);
		mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[0], &x->m_parts[1], &digit1);
		mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[1], &digit1);
		mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[1], &x->m_parts[0], &digit1);
		mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[1], &digit1);
	}
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	else if(mk_num_composite_un_parts == 3)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[0], &x->m_parts[0], &z->m_parts[0], &z->m_parts[1]);
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[0], &x->m_parts[1], &digit1, &z->m_parts[2]);
		mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[1], &digit1, &c);
		if(c) mk_num_composite_un_base_inc(&z->m_parts[2]);
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[1], &x->m_parts[0], &digit1, &digit2);
		mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[1], &digit1, &c);
		mk_num_composite_un_base_add2_wrap_cie_cod(&z->m_parts[2], &digit2, c);
		mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[0], &x->m_parts[2], &digit1);
		mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[2], &digit1);
		mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[1], &x->m_parts[1], &digit1);
		mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[2], &digit1);
		mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[2], &x->m_parts[0], &digit1);
		mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[2], &digit1);
	}
	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	else if(mk_num_composite_un_parts == 4)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[0], &x->m_parts[0], &z->m_parts[0], &z->m_parts[1]);
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[0], &x->m_parts[1], &digit1, &z->m_parts[2]);
		mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[1], &digit1, &c);
		if(c) mk_num_composite_un_base_inc(&z->m_parts[2]);
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[1], &x->m_parts[0], &digit1, &digit2);
		mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[1], &digit1, &c);
		mk_num_composite_un_base_add2_wrap_cie_coe(&z->m_parts[2], &digit2, c, &c);
		if(c) mk_num_composite_un_base_set_one(&z->m_parts[3]); else mk_num_composite_un_base_set_zero(&z->m_parts[3]);
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[0], &x->m_parts[2], &digit1, &digit2);
		mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[2], &digit1, &c);
		mk_num_composite_un_base_add2_wrap_cie_cod(&z->m_parts[3], &digit2, c);
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[1], &x->m_parts[1], &digit1, &digit2);
		mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[2], &digit1, &c);
		mk_num_composite_un_base_add2_wrap_cie_cod(&z->m_parts[3], &digit2, c);
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[2], &x->m_parts[0], &digit1, &digit2);
		mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[2], &digit1, &c);
		mk_num_composite_un_base_add2_wrap_cie_cod(&z->m_parts[3], &digit2, c);
		mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[0], &x->m_parts[3], &digit1);
		mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[3], &digit1);
		mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[1], &x->m_parts[2], &digit1);
		mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[3], &digit1);
		mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[2], &x->m_parts[1], &digit1);
		mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[3], &digit1);
		mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[3], &x->m_parts[0], &digit1);
		mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[3], &digit1);
	}
	else
	{
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[0], &x->m_parts[0], &z->m_parts[0], &z->m_parts[1]);
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[0], &x->m_parts[1], &digit1, &z->m_parts[2]);
		mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[1], &digit1, &c);
		if(c) mk_num_composite_un_base_inc(&z->m_parts[2]);
		mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[1], &x->m_parts[0], &digit1, &digit2);
		mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[1], &digit1, &c);
		mk_num_composite_un_base_add2_wrap_cie_coe(&z->m_parts[2], &digit2, c, &c);
		if(c) mk_num_composite_un_base_set_one(&z->m_parts[3]); else mk_num_composite_un_base_set_zero(&z->m_parts[3]);
		for(j = 2; j != mk_num_composite_un_parts - 2; ++j)
		{
			mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[0], &x->m_parts[j], &digit1, &digit2);
			mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[j], &digit1, &c);
			mk_num_composite_un_base_add2_wrap_cie_coe(&z->m_parts[j + 1], &digit2, c, &c);
			if(c) mk_num_composite_un_base_set_one(&z->m_parts[j + 2]); else mk_num_composite_un_base_set_zero(&z->m_parts[j + 2]);
			for(i = 1; i != j + 1; ++i)
			{
				mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[i], &x->m_parts[j - i], &digit1, &digit2);
				mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[j], &digit1, &c);
				mk_num_composite_un_base_add2_wrap_cie_coe(&z->m_parts[j + 1], &digit2, c, &c);
				if(c) mk_num_composite_un_base_inc(&z->m_parts[j + 2]);
			}
		}
		for(i = 0; i != j + 1; ++i)
		{
			mk_num_composite_un_base_mul3_wrap_cid_coe(&y->m_parts[i], &x->m_parts[j - i], &digit1, &digit2);
			mk_num_composite_un_base_add2_wrap_cid_coe(&z->m_parts[j], &digit1, &c);
			mk_num_composite_un_base_add2_wrap_cie_cod(&z->m_parts[j + 1], &digit2, c);
		}
		++j;
		for(i = 0; i != j + 1; ++i)
		{
			mk_num_composite_un_base_mul3_wrap_cid_cod(&y->m_parts[i], &x->m_parts[j - i], &digit1);
			mk_num_composite_un_base_add2_wrap_cid_cod(&z->m_parts[j], &digit1);
		}
	}
}

mk_lang_jumbo void mk_num_composite_un_mul3_wrap_cid_cod_alias(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	mk_num_composite_un_t zz;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(z == x || z == y);

	mk_num_composite_un_mul3_wrap_cid_cod_restrict(x, y, &zz);
	*z = zz;
}

mk_lang_jumbo void mk_num_composite_un_mul3_wrap_cid_cod(mk_num_composite_un_t const* x, mk_num_composite_un_t const* y, mk_num_composite_un_t* z)
{
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);

	#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
	#endif
	if(mk_num_composite_un_parts == 1)
	#if defined(_MSC_VER)
	#pragma warning(pop)
	#endif
	{
		mk_num_composite_un_base_mul3_wrap_cid_cod(&x->m_parts[0], &y->m_parts[0], &z->m_parts[0]);
	}
	else
	{
		if(x != z && y != z)
		{
			mk_num_composite_un_mul3_wrap_cid_cod_restrict(x, y, z);
		}
		else
		{
			mk_num_composite_un_mul3_wrap_cid_cod_alias(x, y, z);
		}
	}
	mk_num_composite_un_normalize_msd(z);
}


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#include "mk_num_composite_uint_undef.h"
#include "mk_num_composite_uint_base_undef.h"


#undef mk_num_composite_bits
#undef mk_num_composite_base_type
#undef mk_num_composite_base_name
#undef mk_num_composite_base_bits
