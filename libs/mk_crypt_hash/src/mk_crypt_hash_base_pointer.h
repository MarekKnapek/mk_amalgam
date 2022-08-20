#ifndef mk_include_guard_crypt_hash_base_pointer
#define mk_include_guard_crypt_hash_base_pointer


#include "mk_crypt_hash_base_type.h"

#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo void mk_crypt_hash_base_pointer_init(mk_crypt_hash_base_type_t type, void* hash);
mk_jumbo void mk_crypt_hash_base_pointer_append_blocks(mk_crypt_hash_base_type_t type, void* hash, void const* blocks, int count);
mk_jumbo void mk_crypt_hash_base_pointer_append_last_partial_block(mk_crypt_hash_base_type_t type, void* hash, void* block, int len);
mk_jumbo void mk_crypt_hash_base_pointer_finish(mk_crypt_hash_base_type_t type, void const* hash, void* digest);


#endif
