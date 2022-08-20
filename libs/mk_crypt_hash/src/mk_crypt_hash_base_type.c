#include "mk_crypt_hash_base_type.h"

#include "mk_crypt_hash_bases.h"
#include "mk_crypt_hash_xmacro.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


mk_jumbo int mk_crypt_hash_base_type_block_len(mk_crypt_hash_base_type_t type)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));

	switch(type)
	{
		#define xmacro(type) case mk_concat(mk_crypt_hash_base_type_e_, type): return mk_concat(mk_concat(mk_crypt_hash_base_, type), _block_len); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
	return -1;
}

mk_jumbo int mk_crypt_hash_base_type_digest_len(mk_crypt_hash_base_type_t type)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));

	switch(type)
	{
		#define xmacro(type) case mk_concat(mk_crypt_hash_base_type_e_, type): return mk_concat(mk_concat(mk_crypt_hash_base_, type), _digest_len); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
	return -1;
}

mk_jumbo char const* mk_crypt_hash_base_type_name(mk_crypt_hash_base_type_t type)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));

	switch(type)
	{
		#define xmacro(type) case mk_concat(mk_crypt_hash_base_type_e_, type): return mk_concat(mk_concat(mk_crypt_hash_base_, type), _name); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
	return NULL;
}

mk_jumbo int mk_crypt_hash_base_type_name_len(mk_crypt_hash_base_type_t type)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));

	switch(type)
	{
		#define xmacro(type) case mk_concat(mk_crypt_hash_base_type_e_, type): return mk_concat(mk_concat(mk_crypt_hash_base_, type), _name_len); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
	return -1;
}
