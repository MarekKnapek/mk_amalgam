#ifndef mk_include_guard_crypt_hash_base_md5
#define mk_include_guard_crypt_hash_base_md5


#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_crypt_hash_base_md5_s
{
	mk_uint32_t m_state[4];
	mk_uint64_t m_len;
};
typedef struct mk_crypt_hash_base_md5_s mk_crypt_hash_base_md5_t;
typedef mk_crypt_hash_base_md5_t* mk_crypt_hash_base_md5_pt;
typedef mk_crypt_hash_base_md5_t const* mk_crypt_hash_base_md5_pct;


#define mk_crypt_hash_base_md5_block_len 64
#define mk_crypt_hash_base_md5_digest_len 16
#define mk_crypt_hash_base_md5_name "MD5"
#define mk_crypt_hash_base_md5_name_len (((int)(sizeof(mk_crypt_hash_base_md5_name))) - 1)


mk_jumbo void mk_crypt_hash_base_md5_init(mk_crypt_hash_base_md5_pt self);
mk_jumbo void mk_crypt_hash_base_md5_append_blocks(mk_crypt_hash_base_md5_pt self, void const* blocks, int count);
mk_jumbo void mk_crypt_hash_base_md5_append_last_partial_block(mk_crypt_hash_base_md5_pt self, void* block, int len);
mk_jumbo void mk_crypt_hash_base_md5_finish(mk_crypt_hash_base_md5_pct self, void* digest);


#endif
