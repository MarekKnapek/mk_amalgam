#ifndef mk_include_guard_crypt_hash_base_type
#define mk_include_guard_crypt_hash_base_type


#include "mk_crypt_hash_xmacro.h"

#include "../../mk_utils/src/mk_jumbo.h"


enum mk_crypt_hash_base_type_e
{
	#define xmacro(x) mk_concat(mk_crypt_hash_base_type_e_, x),
	mk_crypt_hash_xinvoke
	#undef xmacro
};
typedef enum mk_crypt_hash_base_type_e mk_crypt_hash_base_type_t;


#define mk_crypt_hash_base_type_is_good(x) \
	( \
		(x) == mk_crypt_hash_base_type_e_md2 || \
		(x) == mk_crypt_hash_base_type_e_md4 || \
		(x) == mk_crypt_hash_base_type_e_md5 \
	)


mk_jumbo int mk_crypt_hash_base_type_block_len(mk_crypt_hash_base_type_t type);
mk_jumbo int mk_crypt_hash_base_type_digest_len(mk_crypt_hash_base_type_t type);
mk_jumbo char const* mk_crypt_hash_base_type_name(mk_crypt_hash_base_type_t type);
mk_jumbo int mk_crypt_hash_base_type_name_len(mk_crypt_hash_base_type_t type);


#endif
