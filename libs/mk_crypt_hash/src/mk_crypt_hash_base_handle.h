#ifndef mk_include_guard_crypt_hash_base_handle
#define mk_include_guard_crypt_hash_base_handle


#include "mk_crypt_hash_base_type.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_crypt_hash_base_handle_s; typedef struct mk_crypt_hash_base_handle_s mk_crypt_hash_base_handle_t; typedef mk_crypt_hash_base_handle_t const* mk_crypt_hash_base_handle_h;


mk_jumbo void mk_crypt_hash_base_handle_create(mk_crypt_hash_base_handle_h* self, mk_crypt_hash_base_type_t type);
mk_jumbo void mk_crypt_hash_base_handle_init(mk_crypt_hash_base_handle_h self);
mk_jumbo void mk_crypt_hash_base_handle_append_blocks(mk_crypt_hash_base_handle_h self, void const* blocks, int count);
mk_jumbo void mk_crypt_hash_base_handle_append_last_partial_block(mk_crypt_hash_base_handle_h self, void* block, int len);
mk_jumbo void mk_crypt_hash_base_handle_finish(mk_crypt_hash_base_handle_h self, void* digest);
mk_jumbo void mk_crypt_hash_base_handle_destroy(mk_crypt_hash_base_handle_h self);


#endif
