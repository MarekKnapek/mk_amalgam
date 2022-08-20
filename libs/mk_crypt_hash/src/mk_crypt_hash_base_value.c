#include "mk_crypt_hash_base_value.h"

#include "mk_crypt_hash_base_pointer.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo void mk_crypt_hash_base_value_init(mk_crypt_hash_base_type_t type, mk_crypt_hash_base_value_pt hash)
{
	mk_crypt_hash_base_pointer_init(type, hash);
}

mk_jumbo void mk_crypt_hash_base_value_append_blocks(mk_crypt_hash_base_type_t type, mk_crypt_hash_base_value_pt hash, void const* blocks, int count)
{
	mk_crypt_hash_base_pointer_append_blocks(type, hash, blocks, count);
}

mk_jumbo void mk_crypt_hash_base_value_append_last_partial_block(mk_crypt_hash_base_type_t type, mk_crypt_hash_base_value_pt hash, void* block, int len)
{
	mk_crypt_hash_base_pointer_append_last_partial_block(type, hash, block, len);
}

mk_jumbo void mk_crypt_hash_base_value_finish(mk_crypt_hash_base_type_t type, mk_crypt_hash_base_value_pct hash, void* digest)
{
	mk_crypt_hash_base_pointer_finish(type, hash, digest);
}


mk_jumbo void mk_crypt_hash_base_value_tag_init(mk_crypt_hash_base_value_tag_pt self, mk_crypt_hash_base_type_t type)
{
	mk_assert(self);
	mk_assert(mk_crypt_hash_base_type_is_good(type));

	self->m_type = type;
	mk_crypt_hash_base_value_init(self->m_type, &self->m_value);
}

mk_jumbo void mk_crypt_hash_base_value_tag_append_blocks(mk_crypt_hash_base_value_tag_pt self, void const* blocks, int count)
{
	mk_assert(self);

	mk_crypt_hash_base_value_append_blocks(self->m_type, &self->m_value, blocks, count);
}

mk_jumbo void mk_crypt_hash_base_value_tag_append_last_partial_block(mk_crypt_hash_base_value_tag_pt self, void* block, int len)
{
	mk_assert(self);

	mk_crypt_hash_base_value_append_last_partial_block(self->m_type, &self->m_value, block, len);
}

mk_jumbo void mk_crypt_hash_base_value_tag_finish(mk_crypt_hash_base_value_tag_pct self, void* digest)
{
	mk_assert(self);

	mk_crypt_hash_base_value_finish(self->m_type, &self->m_value, digest);
}
