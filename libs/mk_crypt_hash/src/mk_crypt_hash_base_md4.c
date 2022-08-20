#include "mk_crypt_hash_base_md4.h"

#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"


static mk_inline void mk_crypt_hash_base_md4_private_f(mk_uint32_t* out, mk_uint32_t const* x, mk_uint32_t const* y, mk_uint32_t const* z)
{
	mk_uint32_t tmp1;
	mk_uint32_t tmp2;

	mk_assert(out);
	mk_assert(x);
	mk_assert(y);
	mk_assert(z);

	/* return (x & y) | ((~x) & z); */

	mk_uint32_and(&tmp1, x, y);
	mk_uint32_cmplmnt(&tmp2, x);
	mk_uint32_and(&tmp2, &tmp2, z);
	mk_uint32_or(out, &tmp1, &tmp2);
}

static mk_inline void mk_crypt_hash_base_md4_private_g(mk_uint32_t* out, mk_uint32_t const* x, mk_uint32_t const* y, mk_uint32_t const* z)
{
	mk_uint32_t tmp1;
	mk_uint32_t tmp2;

	mk_assert(out);
	mk_assert(x);
	mk_assert(y);
	mk_assert(z);

	/* return (x & y) | (x & z) | (y & z); */

	mk_uint32_and(&tmp1, x, y);
	mk_uint32_and(&tmp2, x, z);
	mk_uint32_or(&tmp1, &tmp1, &tmp2);
	mk_uint32_and(&tmp2, y, z);
	mk_uint32_or(out, &tmp1, &tmp2);
}

static mk_inline void mk_crypt_hash_base_md4_private_h(mk_uint32_t* out, mk_uint32_t const* x, mk_uint32_t const* y, mk_uint32_t const* z)
{
	mk_uint32_t tmp;

	mk_assert(out);
	mk_assert(x);
	mk_assert(y);
	mk_assert(z);

	/* return x ^ y ^ z; */

	mk_uint32_xor(&tmp, x, y);
	mk_uint32_xor(out, &tmp, z);
}

static mk_inline void mk_crypt_hash_base_md4_private_round_1(mk_uint32_t* a, mk_uint32_t const* b, mk_uint32_t const* c, mk_uint32_t const* d, void const* xk, int s)
{
	mk_uint32_t tmp;

	mk_assert(a);
	mk_assert(b);
	mk_assert(c);
	mk_assert(d);
	mk_assert(xk);
	mk_assert(s > 0 && s < 32);
	mk_assert(a != b);
	mk_assert(a != c);
	mk_assert(a != d);
	mk_assert(a != xk);

	/* a = rotl(a + f(b, c, d) + x[k], s); */

	mk_crypt_hash_base_md4_private_f(&tmp, b, c, d);
	mk_uint32_add(a, a, &tmp);
	mk_uint32_from_buff_le(&tmp, xk);
	mk_uint32_add(a, a, &tmp);
	mk_uint32_rotl(a, a, s);
}

static mk_inline void mk_crypt_hash_base_md4_private_round_2(mk_uint32_t* a, mk_uint32_t const* b, mk_uint32_t const* c, mk_uint32_t const* d, void const* xk, int s)
{
	static mk_uint32_t const mk_crypt_hash_base_md4_private_round_2_constant = mk_uint32_c(0x5a827999ul);

	mk_uint32_t tmp;

	mk_assert(a);
	mk_assert(b);
	mk_assert(c);
	mk_assert(d);
	mk_assert(xk);
	mk_assert(s > 0 && s < 32);
	mk_assert(a != b);
	mk_assert(a != c);
	mk_assert(a != d);
	mk_assert(a != xk);

	/* a = rotl(a + g(b, c, d) + x[k] + 0x5a827999, s); */

	mk_crypt_hash_base_md4_private_g(&tmp, b, c, d);
	mk_uint32_add(a, a, &tmp);
	mk_uint32_from_buff_le(&tmp, xk);
	mk_uint32_add(a, a, &tmp);
	mk_uint32_add(a, a, &mk_crypt_hash_base_md4_private_round_2_constant);
	mk_uint32_rotl(a, a, s);
}

static mk_inline void mk_crypt_hash_base_md4_private_round_3(mk_uint32_t* a, mk_uint32_t const* b, mk_uint32_t const* c, mk_uint32_t const* d, void const* xk, int s)
{
	static mk_uint32_t const mk_crypt_hash_base_md4_private_round_3_constant = mk_uint32_c(0x6ed9eba1ul);

	mk_uint32_t tmp;

	mk_assert(a);
	mk_assert(b);
	mk_assert(c);
	mk_assert(d);
	mk_assert(xk);
	mk_assert(s > 0 && s < 32);
	mk_assert(a != b);
	mk_assert(a != c);
	mk_assert(a != d);
	mk_assert(a != xk);

	/* a = rotl(a + h(b, c, d) + x[k] + 0x6ed9eba1, s); */

	mk_crypt_hash_base_md4_private_h(&tmp, b, c, d);
	mk_uint32_add(a, a, &tmp);
	mk_uint32_from_buff_le(&tmp, xk);
	mk_uint32_add(a, a, &tmp);
	mk_uint32_add(a, a, &mk_crypt_hash_base_md4_private_round_3_constant);
	mk_uint32_rotl(a, a, s);
}


mk_jumbo void mk_crypt_hash_base_md4_init(mk_crypt_hash_base_md4_pt self)
{
	static mk_uint32_t const mk_crypt_hash_base_md4_private_init[4] =
	{
		mk_uint32_c(0x67452301ul),
		mk_uint32_c(0xefcdab89ul),
		mk_uint32_c(0x98badcfeul),
		mk_uint32_c(0x10325476ul),
	};

	mk_assert(self);

	self->m_state[0] = mk_crypt_hash_base_md4_private_init[0];
	self->m_state[1] = mk_crypt_hash_base_md4_private_init[1];
	self->m_state[2] = mk_crypt_hash_base_md4_private_init[2];
	self->m_state[3] = mk_crypt_hash_base_md4_private_init[3];
	mk_uint64_zero(&self->m_len);
}

mk_jumbo void mk_crypt_hash_base_md4_append_blocks(mk_crypt_hash_base_md4_pt self, void const* blocks, int count)
{
	static mk_uint64_t const mk_crypt_hash_base_md4_private_max_blocks = mk_uint64_c(0x007ffffful, 0xfffffffful);

	mk_uint64_t len_blocks;
	mk_uint64_t new_len_blocks;
	unsigned char const* input;
	mk_uint32_t oldh[4];
	mk_uint32_t h[4];
	mk_uint32_t* a;
	mk_uint32_t* b;
	mk_uint32_t* c;
	mk_uint32_t* d;
	int iblock;

	mk_assert(self);
	mk_assert(blocks || count == 0);
	mk_assert(count >= 0);

	if(count == 0)
	{
		return;
	}

	mk_uint64_from_int(&len_blocks, count);
	mk_uint64_add(&new_len_blocks, &self->m_len, &len_blocks);
	mk_assert(mk_uint64_le(&new_len_blocks, &mk_crypt_hash_base_md4_private_max_blocks));
	mk_assert(mk_uint64_gt(&new_len_blocks, &self->m_len));
	mk_assert(mk_uint64_ge(&new_len_blocks, &len_blocks));
	input = (unsigned char const*)blocks;
	oldh[0] = self->m_state[0];
	oldh[1] = self->m_state[1];
	oldh[2] = self->m_state[2];
	oldh[3] = self->m_state[3];
	a = &h[0];
	b = &h[1];
	c = &h[2];
	d = &h[3];
	for(iblock = 0; iblock != count; ++iblock, input += 64)
	{
		h[0] = oldh[0];
		h[1] = oldh[1];
		h[2] = oldh[2];
		h[3] = oldh[3];

		mk_crypt_hash_base_md4_private_round_1(a, b, c, d, &input[ 0 * 4],  3);
		mk_crypt_hash_base_md4_private_round_1(d, a, b, c, &input[ 1 * 4],  7);
		mk_crypt_hash_base_md4_private_round_1(c, d, a, b, &input[ 2 * 4], 11);
		mk_crypt_hash_base_md4_private_round_1(b, c, d, a, &input[ 3 * 4], 19);
		mk_crypt_hash_base_md4_private_round_1(a, b, c, d, &input[ 4 * 4],  3);
		mk_crypt_hash_base_md4_private_round_1(d, a, b, c, &input[ 5 * 4],  7);
		mk_crypt_hash_base_md4_private_round_1(c, d, a, b, &input[ 6 * 4], 11);
		mk_crypt_hash_base_md4_private_round_1(b, c, d, a, &input[ 7 * 4], 19);
		mk_crypt_hash_base_md4_private_round_1(a, b, c, d, &input[ 8 * 4],  3);
		mk_crypt_hash_base_md4_private_round_1(d, a, b, c, &input[ 9 * 4],  7);
		mk_crypt_hash_base_md4_private_round_1(c, d, a, b, &input[10 * 4], 11);
		mk_crypt_hash_base_md4_private_round_1(b, c, d, a, &input[11 * 4], 19);
		mk_crypt_hash_base_md4_private_round_1(a, b, c, d, &input[12 * 4],  3);
		mk_crypt_hash_base_md4_private_round_1(d, a, b, c, &input[13 * 4],  7);
		mk_crypt_hash_base_md4_private_round_1(c, d, a, b, &input[14 * 4], 11);
		mk_crypt_hash_base_md4_private_round_1(b, c, d, a, &input[15 * 4], 19);

		mk_crypt_hash_base_md4_private_round_2(a, b, c, d, &input[ 0 * 4],  3);
		mk_crypt_hash_base_md4_private_round_2(d, a, b, c, &input[ 4 * 4],  5);
		mk_crypt_hash_base_md4_private_round_2(c, d, a, b, &input[ 8 * 4],  9);
		mk_crypt_hash_base_md4_private_round_2(b, c, d, a, &input[12 * 4], 13);
		mk_crypt_hash_base_md4_private_round_2(a, b, c, d, &input[ 1 * 4],  3);
		mk_crypt_hash_base_md4_private_round_2(d, a, b, c, &input[ 5 * 4],  5);
		mk_crypt_hash_base_md4_private_round_2(c, d, a, b, &input[ 9 * 4],  9);
		mk_crypt_hash_base_md4_private_round_2(b, c, d, a, &input[13 * 4], 13);
		mk_crypt_hash_base_md4_private_round_2(a, b, c, d, &input[ 2 * 4],  3);
		mk_crypt_hash_base_md4_private_round_2(d, a, b, c, &input[ 6 * 4],  5);
		mk_crypt_hash_base_md4_private_round_2(c, d, a, b, &input[10 * 4],  9);
		mk_crypt_hash_base_md4_private_round_2(b, c, d, a, &input[14 * 4], 13);
		mk_crypt_hash_base_md4_private_round_2(a, b, c, d, &input[ 3 * 4],  3);
		mk_crypt_hash_base_md4_private_round_2(d, a, b, c, &input[ 7 * 4],  5);
		mk_crypt_hash_base_md4_private_round_2(c, d, a, b, &input[11 * 4],  9);
		mk_crypt_hash_base_md4_private_round_2(b, c, d, a, &input[15 * 4], 13);

		mk_crypt_hash_base_md4_private_round_3(a, b, c, d, &input[ 0 * 4],  3);
		mk_crypt_hash_base_md4_private_round_3(d, a, b, c, &input[ 8 * 4],  9);
		mk_crypt_hash_base_md4_private_round_3(c, d, a, b, &input[ 4 * 4], 11);
		mk_crypt_hash_base_md4_private_round_3(b, c, d, a, &input[12 * 4], 15);
		mk_crypt_hash_base_md4_private_round_3(a, b, c, d, &input[ 2 * 4],  3);
		mk_crypt_hash_base_md4_private_round_3(d, a, b, c, &input[10 * 4],  9);
		mk_crypt_hash_base_md4_private_round_3(c, d, a, b, &input[ 6 * 4], 11);
		mk_crypt_hash_base_md4_private_round_3(b, c, d, a, &input[14 * 4], 15);
		mk_crypt_hash_base_md4_private_round_3(a, b, c, d, &input[ 1 * 4],  3);
		mk_crypt_hash_base_md4_private_round_3(d, a, b, c, &input[ 9 * 4],  9);
		mk_crypt_hash_base_md4_private_round_3(c, d, a, b, &input[ 5 * 4], 11);
		mk_crypt_hash_base_md4_private_round_3(b, c, d, a, &input[13 * 4], 15);
		mk_crypt_hash_base_md4_private_round_3(a, b, c, d, &input[ 3 * 4],  3);
		mk_crypt_hash_base_md4_private_round_3(d, a, b, c, &input[11 * 4],  9);
		mk_crypt_hash_base_md4_private_round_3(c, d, a, b, &input[ 7 * 4], 11);
		mk_crypt_hash_base_md4_private_round_3(b, c, d, a, &input[15 * 4], 15);

		mk_uint32_add(&oldh[0], &oldh[0], &h[0]);
		mk_uint32_add(&oldh[1], &oldh[1], &h[1]);
		mk_uint32_add(&oldh[2], &oldh[2], &h[2]);
		mk_uint32_add(&oldh[3], &oldh[3], &h[3]);
	}
	self->m_state[0] = oldh[0];
	self->m_state[1] = oldh[1];
	self->m_state[2] = oldh[2];
	self->m_state[3] = oldh[3];
	self->m_len = new_len_blocks;
}

mk_jumbo void mk_crypt_hash_base_md4_append_last_partial_block(mk_crypt_hash_base_md4_pt self, void* block, int len)
{
	mk_uint64_t len64;
	mk_uint64_t len_bits;
	unsigned char* input;
	int capacity;
	int i;

	mk_assert(self);
	mk_assert(block);
	mk_assert(len >= 0 && len < 64);

	mk_uint64_from_int(&len64, len);
	mk_uint64_shl(&len64, &len64, 3);
	mk_uint64_shl(&len_bits, &self->m_len, 9);
	mk_uint64_add(&len_bits, &len_bits, &len64);
	input = (unsigned char*)block;
	input[len] = 0x80;
	capacity = 64 - len - 1;
	if(capacity >= 8)
	{
		for(i = 0; i != capacity - 8; ++i){ input[len + 1 + i] = 0x00; }
	}
	else
	{
		for(i = 0; i != capacity; ++i){ input[len + 1 + i] = 0x00; }
		mk_crypt_hash_base_md4_append_blocks(self, input, 1);
		for(i = 0; i != 64 - 8; ++i){ input[i] = 0x00; }
	}
	mk_uint64_to_buff_le(&len_bits, &input[64 - 8]);
	mk_crypt_hash_base_md4_append_blocks(self, input, 1);
}

mk_jumbo void mk_crypt_hash_base_md4_finish(mk_crypt_hash_base_md4_pct self, void* digest)
{
	mk_uint32_t const* input;
	unsigned char* output;
	int i;

	mk_assert(self);
	mk_assert(digest);

	input = self->m_state;
	output = (unsigned char*)digest;
	for(i = 0; i != 4; ++i, ++input, output += 4)
	{
		mk_uint32_to_buff_le(input, output);
	}
}
