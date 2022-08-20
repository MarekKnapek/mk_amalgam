#include "mk_crypt_hash_stream_value.h"

#include "mk_crypt_hash_base_type.h"
#include "mk_crypt_hash_stream_pointer.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo void mk_crypt_hash_stream_value_init(mk_crypt_hash_base_type_t type, mk_crypt_hash_stream_value_pt self)
{
	mk_crypt_hash_stream_pointer_init(type, self);
}

mk_jumbo void mk_crypt_hash_stream_value_append(mk_crypt_hash_base_type_t type, mk_crypt_hash_stream_value_pt self, void const* msg, int len)
{
	mk_crypt_hash_stream_pointer_append(type, self, msg, len);
}

mk_jumbo void mk_crypt_hash_stream_value_end_stream(mk_crypt_hash_base_type_t type, mk_crypt_hash_stream_value_pt self)
{
	mk_crypt_hash_stream_pointer_end_stream(type, self);
}

mk_jumbo void mk_crypt_hash_stream_value_finish(mk_crypt_hash_base_type_t type, mk_crypt_hash_stream_value_pct self, void* digest)
{
	mk_crypt_hash_stream_pointer_finish(type, self, digest);
}


mk_jumbo void mk_crypt_hash_stream_value_tag_init(mk_crypt_hash_stream_value_tag_pt self, mk_crypt_hash_base_type_t type)
{
	mk_assert(self);
	mk_assert(mk_crypt_hash_base_type_is_good(type));

	self->m_type = type;
	mk_crypt_hash_stream_value_init(self->m_type, &self->m_value);
}

mk_jumbo void mk_crypt_hash_stream_value_tag_append(mk_crypt_hash_stream_value_tag_pt self, void const* msg, int len)
{
	mk_assert(self);

	mk_crypt_hash_stream_value_append(self->m_type, &self->m_value, msg, len);
}

mk_jumbo void mk_crypt_hash_stream_value_tag_end_stream(mk_crypt_hash_stream_value_tag_pt self)
{
	mk_assert(self);

	mk_crypt_hash_stream_value_end_stream(self->m_type, &self->m_value);
}

mk_jumbo void mk_crypt_hash_stream_value_tag_finish(mk_crypt_hash_stream_value_tag_pct self, void* digest)
{
	mk_assert(self);

	mk_crypt_hash_stream_value_finish(self->m_type, &self->m_value, digest);
}
