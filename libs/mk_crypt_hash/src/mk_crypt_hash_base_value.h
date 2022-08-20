#ifndef mk_include_guard_crypt_hash_base_value
#define mk_include_guard_crypt_hash_base_value


#include "mk_crypt_hash_base_type.h"
#include "mk_crypt_hash_bases.h"
#include "mk_crypt_hash_xmacro.h"

#include "../../mk_utils/src/mk_jumbo.h"


union mk_crypt_hash_base_value_u
{
	#define xmacro(x) mk_concat(mk_concat(mk_crypt_hash_base_, x), _t) mk_concat(m_, x);
	mk_crypt_hash_xinvoke
	#undef xmacro
};
typedef union mk_crypt_hash_base_value_u mk_crypt_hash_base_value_t;
typedef mk_crypt_hash_base_value_t* mk_crypt_hash_base_value_pt;
typedef mk_crypt_hash_base_value_t const* mk_crypt_hash_base_value_pct;

struct mk_crypt_hash_base_value_tag_s
{
	mk_crypt_hash_base_type_t m_type;
	mk_crypt_hash_base_value_t m_value;
};
typedef struct mk_crypt_hash_base_value_tag_s mk_crypt_hash_base_value_tag_t;
typedef mk_crypt_hash_base_value_tag_t* mk_crypt_hash_base_value_tag_pt;
typedef mk_crypt_hash_base_value_tag_t const* mk_crypt_hash_base_value_tag_pct;

union mk_crypt_hash_base_val_block_u
{
	#define xmacro(x) unsigned char mk_concat(m_, x)[mk_concat(mk_concat(mk_crypt_hash_base_, x), _block_len)];
	mk_crypt_hash_xinvoke
	#undef xmacro
};
typedef union mk_crypt_hash_base_val_block_u mk_crypt_hash_base_val_block_t;
union mk_crypt_hash_base_val_digest_u
{
	#define xmacro(x) unsigned char mk_concat(m_, x)[mk_concat(mk_concat(mk_crypt_hash_base_, x), _digest_len)];
	mk_crypt_hash_xinvoke
	#undef xmacro
};
typedef union mk_crypt_hash_base_val_digest_u mk_crypt_hash_base_val_digest_t;


mk_jumbo void mk_crypt_hash_base_value_init(mk_crypt_hash_base_type_t type, mk_crypt_hash_base_value_pt hash);
mk_jumbo void mk_crypt_hash_base_value_append_blocks(mk_crypt_hash_base_type_t type, mk_crypt_hash_base_value_pt hash, void const* blocks, int count);
mk_jumbo void mk_crypt_hash_base_value_append_last_partial_block(mk_crypt_hash_base_type_t type, mk_crypt_hash_base_value_pt hash, void* block, int len);
mk_jumbo void mk_crypt_hash_base_value_finish(mk_crypt_hash_base_type_t type, mk_crypt_hash_base_value_pct hash, void* digest);

mk_jumbo void mk_crypt_hash_base_value_tag_init(mk_crypt_hash_base_value_tag_pt self, mk_crypt_hash_base_type_t type);
mk_jumbo void mk_crypt_hash_base_value_tag_append_blocks(mk_crypt_hash_base_value_tag_pt self, void const* blocks, int count);
mk_jumbo void mk_crypt_hash_base_value_tag_append_last_partial_block(mk_crypt_hash_base_value_tag_pt self, void* block, int len);
mk_jumbo void mk_crypt_hash_base_value_tag_finish(mk_crypt_hash_base_value_tag_pct self, void* digest);


#endif
