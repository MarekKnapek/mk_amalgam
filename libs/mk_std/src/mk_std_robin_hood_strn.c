#include "mk_std_robin_hood_strn.h"

#include "mk_std_gcallocator.h"
#include "mk_std_size_max.h"
#include "mk_std_uintp.h"

#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>
#include <string.h>


mk_jumbo int mk_std_robin_hood_strn_hash(mk_std_robin_hood_strn_incomming_t const* incomming, size_t* hash)
{
	#if mk_uintp_bits == 16 || mk_uintp_bits == 32
	#define mk_uint_fnv_t mk_uint32_t
	#define mk_uint_fnv_from_int mk_uint32_from_int
	#define mk_uint_fnv_xor mk_uint32_xor
	#define mk_uint_fnv_mul mk_uint32_mul
	#define mk_uint_fnv_to_sizet mk_uint32_to_sizet
	static mk_uint32_t const s_fnv1offset = mk_uint32_c(0x811c9dc5ul);
	static mk_uint32_t const s_fnv1prime = mk_uint32_c(0x01000193ul);
	#elif mk_uintp_bits == 64
	#define mk_uint_fnv_t mk_uint64_t
	#define mk_uint_fnv_from_int mk_uint64_from_int
	#define mk_uint_fnv_xor mk_uint64_xor
	#define mk_uint_fnv_mul mk_uint64_mul
	#define mk_uint_fnv_to_sizet mk_uint64_to_sizet
	static mk_uint64_t const s_fnv1offset = mk_uint64_c(0xcbf29ce4ul, 0x84222325ul);
	static mk_uint64_t const s_fnv1prime = mk_uint64_c(0x00000100ul, 0x000001b3ul);
	#endif

	unsigned char const* input;
	mk_uint_fnv_t wrk;
	size_t i;
	mk_uint_fnv_t tmp;

	mk_assert(incomming);
	mk_assert(hash);

	input = ((unsigned char const*)(incomming->m_strn));
	wrk = s_fnv1offset;
	mk_assert(incomming->m_len <= mk_std_size_max / sizeof(char));
	for(i = 0; i != incomming->m_len * sizeof(char); ++i, ++input)
	{
		mk_uint_fnv_from_int(&tmp, *input);
		mk_uint_fnv_xor(&wrk, &wrk, &tmp);
		mk_uint_fnv_mul(&wrk, &wrk, &s_fnv1prime);
	}
	*hash = mk_uint_fnv_to_sizet(&wrk);

	return 0;

	#undef mk_uint_fnv_t
	#undef mk_uint_fnv_from_int
	#undef mk_uint_fnv_xor
	#undef mk_uint_fnv_mul
}

mk_jumbo int mk_std_robin_hood_strn_move(mk_std_robin_hood_strn_incomming_t const* incomming, char const** key)
{
	#define mk_max(a, b) (((b) < (a)) ? (a) : (b))
	#define mk_overhead (mk_max(sizeof(size_t), sizeof(char)))

	void* mem;
	size_t bytes;

	mk_assert(incomming);
	mk_assert(incomming->m_len <= (mk_std_size_max - mk_overhead) / sizeof(char));
	mk_assert(key);

	bytes = mk_overhead + incomming->m_len * sizeof(char);
	mk_try(mk_std_gcallocator_allocate(bytes, &mem));
	mem = ((void*)(((unsigned char const*)(mem)) + mk_overhead));
	((size_t*)(mem))[-1] = incomming->m_len;
	memcpy(mem, incomming->m_strn, incomming->m_len * sizeof(char));
	*key = ((char*)(mem));

	return 0;

	#undef mk_max
	#undef mk_overhead
}

mk_jumbo int mk_std_robin_hood_strn_dstr(char const* key)
{
	#define mk_max(a, b) (((b) < (a)) ? (a) : (b))
	#define mk_overhead (mk_max(sizeof(size_t), sizeof(char)))

	void* mem;

	mk_assert(key);

	mem = ((void*)(((unsigned char const*)(key)) - mk_overhead));
	mk_try(mk_std_gcallocator_deallocate(mem));

	return 0;

	#undef mk_max
	#undef mk_overhead
}

mk_jumbo int mk_std_robin_hood_strn_cmp(mk_std_robin_hood_strn_incomming_t const* incomming, char const* key)
{
	size_t keylen;

	mk_assert(incomming);
	mk_assert(key);

	keylen = ((size_t*)(key))[-1];
	return incomming->m_len == keylen && memcmp(incomming->m_strn, key, incomming->m_len * sizeof(char)) == 0;
}


#define mk_std_robin_hood_t_name strn
#define mk_std_robin_hood_t_keyt char
#define mk_std_robin_hood_t_ikeyt mk_std_robin_hood_strn_incomming_t
#define mk_std_robin_hood_t_hash mk_std_robin_hood_strn_hash
#define mk_std_robin_hood_t_move mk_std_robin_hood_strn_move
#define mk_std_robin_hood_t_dstr mk_std_robin_hood_strn_dstr
#define mk_std_robin_hood_t_cmp mk_std_robin_hood_strn_cmp
#include "mk_std_robin_hood.inl.c"
