#ifndef mk_include_guard_crypt_hash_base_md2
#define mk_include_guard_crypt_hash_base_md2


#include "../../mk_int/src/exact/mk_uint_8.h"

#include "../../mk_utils/src/mk_jumbo.h"


union mk_crypt_hash_base_md2_private_aligned_u
{
	unsigned long m_long;
	unsigned char m_bytes[16];
};
typedef union mk_crypt_hash_base_md2_private_aligned_u mk_crypt_hash_base_md2_private_aligned_t;


struct mk_crypt_hash_base_md2_s
{
	mk_crypt_hash_base_md2_private_aligned_t m_state;
	mk_crypt_hash_base_md2_private_aligned_t m_checksum;
};
typedef struct mk_crypt_hash_base_md2_s mk_crypt_hash_base_md2_t;
typedef mk_crypt_hash_base_md2_t* mk_crypt_hash_base_md2_pt;
typedef mk_crypt_hash_base_md2_t const* mk_crypt_hash_base_md2_pct;


#define mk_crypt_hash_base_md2_block_len 16
#define mk_crypt_hash_base_md2_digest_len 16
#define mk_crypt_hash_base_md2_name "MD2"
#define mk_crypt_hash_base_md2_name_len (((int)(sizeof(mk_crypt_hash_base_md2_name))) - 1)


mk_jumbo void mk_crypt_hash_base_md2_init(mk_crypt_hash_base_md2_pt self);
mk_jumbo void mk_crypt_hash_base_md2_append_blocks(mk_crypt_hash_base_md2_pt self, void const* blocks, int count);
mk_jumbo void mk_crypt_hash_base_md2_append_last_partial_block(mk_crypt_hash_base_md2_pt self, void* block, int len);
mk_jumbo void mk_crypt_hash_base_md2_finish(mk_crypt_hash_base_md2_pct self, void* digest);


#endif
