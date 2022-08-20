#include "mk_crypt_hash_base_handle.h"

#include "mk_crypt_hash_base_pointer.h"
#include "mk_crypt_hash_base_type.h"
#include "mk_crypt_hash_bases.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_clobber.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include <stdlib.h>


struct mk_crypt_hash_base_handle_private_tag_s{ mk_crypt_hash_base_type_t m_type; unsigned int m_value; }; typedef struct mk_crypt_hash_base_handle_private_tag_s mk_crypt_hash_base_handle_private_tag_t; typedef mk_crypt_hash_base_handle_private_tag_t* mk_crypt_hash_base_handle_private_tag_pt;
#define xmacro(x) struct mk_concat(mk_concat(mk_crypt_hash_base_handle_private_, x), _s){ mk_crypt_hash_base_type_t m_type; mk_concat(mk_concat(mk_crypt_hash_base_, x), _t) m_value; }; typedef struct mk_concat(mk_concat(mk_crypt_hash_base_handle_private_, x), _s) mk_concat(mk_concat(mk_crypt_hash_base_handle_private_, x), _t); typedef mk_concat(mk_concat(mk_crypt_hash_base_handle_private_, x), _t)* mk_concat(mk_concat(mk_crypt_hash_base_handle_private_, x), _pt);
mk_crypt_hash_xinvoke
#undef xmacro
union mk_crypt_hash_base_handle_private_u
{
	mk_crypt_hash_base_handle_private_tag_t m_tag;
	#define xmacro(x) mk_concat(mk_concat(mk_crypt_hash_base_handle_private_, x), _t) mk_concat(m_, x);
	mk_crypt_hash_xinvoke
	#undef xmacro
};
typedef union mk_crypt_hash_base_handle_private_u mk_crypt_hash_base_handle_private_t;
typedef mk_crypt_hash_base_handle_private_t* mk_crypt_hash_base_handle_private_pt;
typedef mk_crypt_hash_base_handle_private_t const* mk_crypt_hash_base_handle_private_pct;


static mk_inline mk_crypt_hash_base_handle_h mk_crypt_hash_base_handle_private_encode_pointer(void* ptr);
static mk_inline mk_crypt_hash_base_handle_private_pt mk_crypt_hash_base_handle_private_decode_pointer(mk_crypt_hash_base_handle_h handle);


mk_jumbo void mk_crypt_hash_base_handle_create(mk_crypt_hash_base_handle_h* self, mk_crypt_hash_base_type_t type)
{
	int size;
	void* mem;
	mk_crypt_hash_base_handle_private_pt ihash;

	mk_assert(self);
	mk_assert(mk_crypt_hash_base_type_is_good(type));

	mk_clobber(&size);
	switch(type)
	{
		#define xmacro(x) case mk_concat(mk_crypt_hash_base_type_e_, x): size = (int)sizeof(mk_concat(mk_concat(mk_crypt_hash_base_handle_private_, x), _t)); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
	mem = malloc(size);
	*self = mk_crypt_hash_base_handle_private_encode_pointer(mem);
	if(!mem)
	{
		return;
	}
	ihash = (mk_crypt_hash_base_handle_private_pt)mem;
	ihash->m_tag.m_type = type;
}

mk_jumbo void mk_crypt_hash_base_handle_init(mk_crypt_hash_base_handle_h self)
{
	mk_crypt_hash_base_handle_private_pt ihash;

	mk_assert(self);

	ihash = mk_crypt_hash_base_handle_private_decode_pointer(self);
	mk_crypt_hash_base_pointer_init(ihash->m_tag.m_type, &ihash->m_tag.m_value);
}

mk_jumbo void mk_crypt_hash_base_handle_append_blocks(mk_crypt_hash_base_handle_h self, void const* blocks, int count)
{
	mk_crypt_hash_base_handle_private_pt ihash;

	mk_assert(self);

	ihash = mk_crypt_hash_base_handle_private_decode_pointer(self);
	mk_crypt_hash_base_pointer_append_blocks(ihash->m_tag.m_type, &ihash->m_tag.m_value, blocks, count);
}

mk_jumbo void mk_crypt_hash_base_handle_append_last_partial_block(mk_crypt_hash_base_handle_h self, void* block, int len)
{
	mk_crypt_hash_base_handle_private_pt ihash;

	mk_assert(self);

	ihash = mk_crypt_hash_base_handle_private_decode_pointer(self);
	mk_crypt_hash_base_pointer_append_last_partial_block(ihash->m_tag.m_type, &ihash->m_tag.m_value, block, len);
}

mk_jumbo void mk_crypt_hash_base_handle_finish(mk_crypt_hash_base_handle_h self, void* digest)
{
	mk_crypt_hash_base_handle_private_pt ihash;

	mk_assert(self);

	ihash = mk_crypt_hash_base_handle_private_decode_pointer(self);
	mk_crypt_hash_base_pointer_finish(ihash->m_tag.m_type, &ihash->m_tag.m_value, digest);
}

mk_jumbo void mk_crypt_hash_base_handle_destroy(mk_crypt_hash_base_handle_h self)
{
	mk_crypt_hash_base_handle_private_pt ihash;

	mk_assert(self);

	ihash = mk_crypt_hash_base_handle_private_decode_pointer(self);
	mk_assert(mk_crypt_hash_base_type_is_good(ihash->m_tag.m_type));
	free(ihash);
}


static mk_inline mk_crypt_hash_base_handle_h mk_crypt_hash_base_handle_private_encode_pointer(void* ptr)
{
	mk_crypt_hash_base_handle_h handle;

	handle = (mk_crypt_hash_base_handle_h)ptr;

	return handle;
}

static mk_inline mk_crypt_hash_base_handle_private_pt mk_crypt_hash_base_handle_private_decode_pointer(mk_crypt_hash_base_handle_h handle)
{
	mk_crypt_hash_base_handle_private_pt ptr;

	ptr = (mk_crypt_hash_base_handle_private_pt)handle;

	return ptr;
}
