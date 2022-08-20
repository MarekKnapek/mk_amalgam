#include "mk_crypt_hash_bases.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"


#ifndef x
#include "mk_crypt_hash_stream.inl.h"
#endif


#define concat_1(a, b) a ## b
#define concat(a, b) concat_1(a, b)

#define base_t concat(concat(mk_crypt_hash_base_, x), _t)
#define block_len concat(concat(mk_crypt_hash_base_, x), _block_len)
#define base_init concat(concat(mk_crypt_hash_base_, x), _init)
#define base_append_blocks concat(concat(mk_crypt_hash_base_, x), _append_blocks)
#define base_append_last_partial_block concat(concat(mk_crypt_hash_base_, x), _append_last_partial_block)
#define base_finish concat(concat(mk_crypt_hash_base_, x), _finish)
#define stream_s concat(concat(mk_crypt_hash_stream_, x), _s)
#define stream_t concat(concat(mk_crypt_hash_stream_, x), _t)
#define stream_pt concat(concat(mk_crypt_hash_stream_, x), _pt)
#define stream_pct concat(concat(mk_crypt_hash_stream_, x), _pct)
#define stream_init concat(concat(mk_crypt_hash_stream_, x), _init)
#define stream_append concat(concat(mk_crypt_hash_stream_, x), _append)
#define stream_end_stream concat(concat(mk_crypt_hash_stream_, x), _end_stream)
#define stream_finish concat(concat(mk_crypt_hash_stream_, x), _finish)

#define mk_memcpy(dst, src, cnt) { unsigned char* d; unsigned char const* s; int n; int i; d = (unsigned char*)(dst); s = (unsigned char const*)(src); n = (int)(cnt); for(i = 0; i != n; ++i, ++d, ++s) *d = *s; }


mk_jumbo void stream_init(stream_pt self)
{
	mk_assert(self);

	base_init(&self->m_base);
	self->m_idx = 0;
}

mk_jumbo void stream_append(stream_pt self, void const* msg, int len)
{
	unsigned char const* input;
	int remaining;
	int capacity;
	int blocks;

	mk_assert(self);
	mk_assert(self->m_idx >= 0 && self->m_idx < block_len);
	mk_assert(msg || len == 0);
	mk_assert(len >= 0);

	input = (unsigned char const*)msg;
	remaining = len;
	capacity = block_len - self->m_idx;
	if(remaining >= capacity)
	{
		if(self->m_idx != 0)
		{
			mk_memcpy(self->m_block + self->m_idx, input, capacity);
			base_append_blocks(&self->m_base, self->m_block, 1);
			input += capacity;
			remaining -= capacity;
			self->m_idx = 0;
		}
		blocks = remaining / block_len;
		base_append_blocks(&self->m_base, input, blocks);
		input += blocks * block_len;
		remaining -= blocks * block_len;
	}
	mk_assert(remaining >= 0 && remaining < block_len);
	mk_assert(self->m_idx + remaining >= 0 && self->m_idx + remaining < block_len);
	mk_memcpy(self->m_block + self->m_idx, input, remaining);
	self->m_idx += remaining;
}

mk_jumbo void stream_end_stream(stream_pt self)
{
	mk_assert(self);
	mk_assert(self->m_idx >= 0 && self->m_idx < block_len);

	base_append_last_partial_block(&self->m_base, self->m_block, self->m_idx);
}

mk_jumbo void stream_finish(stream_pct self, void* digest)
{
	mk_assert(self);
	mk_assert(self->m_idx >= 0 && self->m_idx < block_len);

	base_finish(&self->m_base, digest);
}


#undef mk_memcpy

#undef base_t
#undef block_len
#undef base_init
#undef base_append_blocks
#undef base_append_last_partial_block
#undef base_finish
#undef stream_s
#undef stream_t
#undef stream_pt
#undef stream_pct
#undef stream_init
#undef stream_append
#undef stream_end_stream
#undef stream_finish

#undef concat_1
#undef concat
