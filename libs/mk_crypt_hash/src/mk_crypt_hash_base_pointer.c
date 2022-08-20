#include "mk_crypt_hash_base_pointer.h"

#include "mk_crypt_hash_base_type.h"
#include "mk_crypt_hash_bases.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo void mk_crypt_hash_base_pointer_init(mk_crypt_hash_base_type_t type, void* hash)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));
	mk_assert(hash);

	switch(type)
	{
		#define xmacro(x) case mk_concat(mk_crypt_hash_base_type_e_, x): mk_concat(mk_concat(mk_crypt_hash_base_, x), _init)((mk_concat(mk_concat(mk_crypt_hash_base_, x), _pt))hash); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
}

mk_jumbo void mk_crypt_hash_base_pointer_append_blocks(mk_crypt_hash_base_type_t type, void* hash, void const* blocks, int count)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));
	mk_assert(hash);

	switch(type)
	{
		#define xmacro(x) case mk_concat(mk_crypt_hash_base_type_e_, x): mk_concat(mk_concat(mk_crypt_hash_base_, x), _append_blocks)((mk_concat(mk_concat(mk_crypt_hash_base_, x), _pt))hash, blocks, count); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
}

mk_jumbo void mk_crypt_hash_base_pointer_append_last_partial_block(mk_crypt_hash_base_type_t type, void* hash, void* block, int len)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));
	mk_assert(hash);

	switch(type)
	{
		#define xmacro(x) case mk_concat(mk_crypt_hash_base_type_e_, x): mk_concat(mk_concat(mk_crypt_hash_base_, x), _append_last_partial_block)((mk_concat(mk_concat(mk_crypt_hash_base_, x), _pt))hash, block, len); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
}

mk_jumbo void mk_crypt_hash_base_pointer_finish(mk_crypt_hash_base_type_t type, void const* hash, void* digest)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));
	mk_assert(hash);

	switch(type)
	{
		#define xmacro(x) case mk_concat(mk_crypt_hash_base_type_e_, x): mk_concat(mk_concat(mk_crypt_hash_base_, x), _finish)((mk_concat(mk_concat(mk_crypt_hash_base_, x), _pt))hash, digest); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
}
