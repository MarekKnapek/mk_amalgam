#ifndef mk_include_guard_crypt_hash_base_md4
#define mk_include_guard_crypt_hash_base_md4


#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_crypt_hash_base_md4_s
{
	mk_uint32_t m_state[4];
	mk_uint64_t m_len;
};
typedef struct mk_crypt_hash_base_md4_s mk_crypt_hash_base_md4_t;
typedef mk_crypt_hash_base_md4_t* mk_crypt_hash_base_md4_pt;
typedef mk_crypt_hash_base_md4_t const* mk_crypt_hash_base_md4_pct;


#define mk_crypt_hash_base_md4_block_len 64
#define mk_crypt_hash_base_md4_digest_len 16
#define mk_crypt_hash_base_md4_name "MD4"
#define mk_crypt_hash_base_md4_name_len (((int)(sizeof(mk_crypt_hash_base_md4_name))) - 1)


mk_jumbo void mk_crypt_hash_base_md4_init(mk_crypt_hash_base_md4_pt self);
mk_jumbo void mk_crypt_hash_base_md4_append_blocks(mk_crypt_hash_base_md4_pt self, void const* blocks, int count);
mk_jumbo void mk_crypt_hash_base_md4_append_last_partial_block(mk_crypt_hash_base_md4_pt self, void* block, int len);
mk_jumbo void mk_crypt_hash_base_md4_finish(mk_crypt_hash_base_md4_pct self, void* digest);


#endif
