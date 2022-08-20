#include "mk_crypt_hash_base_md5.h"

#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"


static mk_uint32_t const mk_crypt_hash_base_md5_private_table[64] =
{
	mk_uint32_c(0xd76aa478ul), mk_uint32_c(0xe8c7b756ul), mk_uint32_c(0x242070dbul), mk_uint32_c(0xc1bdceeeul),
	mk_uint32_c(0xf57c0faful), mk_uint32_c(0x4787c62aul), mk_uint32_c(0xa8304613ul), mk_uint32_c(0xfd469501ul),
	mk_uint32_c(0x698098d8ul), mk_uint32_c(0x8b44f7aful), mk_uint32_c(0xffff5bb1ul), mk_uint32_c(0x895cd7beul),
	mk_uint32_c(0x6b901122ul), mk_uint32_c(0xfd987193ul), mk_uint32_c(0xa679438eul), mk_uint32_c(0x49b40821ul),
	mk_uint32_c(0xf61e2562ul), mk_uint32_c(0xc040b340ul), mk_uint32_c(0x265e5a51ul), mk_uint32_c(0xe9b6c7aaul),
	mk_uint32_c(0xd62f105dul), mk_uint32_c(0x02441453ul), mk_uint32_c(0xd8a1e681ul), mk_uint32_c(0xe7d3fbc8ul),
	mk_uint32_c(0x21e1cde6ul), mk_uint32_c(0xc33707d6ul), mk_uint32_c(0xf4d50d87ul), mk_uint32_c(0x455a14edul),
	mk_uint32_c(0xa9e3e905ul), mk_uint32_c(0xfcefa3f8ul), mk_uint32_c(0x676f02d9ul), mk_uint32_c(0x8d2a4c8aul),
	mk_uint32_c(0xfffa3942ul), mk_uint32_c(0x8771f681ul), mk_uint32_c(0x6d9d6122ul), mk_uint32_c(0xfde5380cul),
	mk_uint32_c(0xa4beea44ul), mk_uint32_c(0x4bdecfa9ul), mk_uint32_c(0xf6bb4b60ul), mk_uint32_c(0xbebfbc70ul),
	mk_uint32_c(0x289b7ec6ul), mk_uint32_c(0xeaa127faul), mk_uint32_c(0xd4ef3085ul), mk_uint32_c(0x04881d05ul),
	mk_uint32_c(0xd9d4d039ul), mk_uint32_c(0xe6db99e5ul), mk_uint32_c(0x1fa27cf8ul), mk_uint32_c(0xc4ac5665ul),
	mk_uint32_c(0xf4292244ul), mk_uint32_c(0x432aff97ul), mk_uint32_c(0xab9423a7ul), mk_uint32_c(0xfc93a039ul),
	mk_uint32_c(0x655b59c3ul), mk_uint32_c(0x8f0ccc92ul), mk_uint32_c(0xffeff47dul), mk_uint32_c(0x85845dd1ul),
	mk_uint32_c(0x6fa87e4ful), mk_uint32_c(0xfe2ce6e0ul), mk_uint32_c(0xa3014314ul), mk_uint32_c(0x4e0811a1ul),
	mk_uint32_c(0xf7537e82ul), mk_uint32_c(0xbd3af235ul), mk_uint32_c(0x2ad7d2bbul), mk_uint32_c(0xeb86d391ul),
};


static mk_inline void mk_crypt_hash_base_md5_private_f(mk_uint32_t* out, mk_uint32_t const* x, mk_uint32_t const* y, mk_uint32_t const* z)
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

static mk_inline void mk_crypt_hash_base_md5_private_g(mk_uint32_t* out, mk_uint32_t const* x, mk_uint32_t const* y, mk_uint32_t const* z)
{
	mk_uint32_t tmp1;
	mk_uint32_t tmp2;

	mk_assert(out);
	mk_assert(x);
	mk_assert(y);
	mk_assert(z);

	/* return (x & z) | (y & (~z)); */

	mk_uint32_and(&tmp1, x, z);
	mk_uint32_cmplmnt(&tmp2, z);
	mk_uint32_and(&tmp2, y, &tmp2);
	mk_uint32_or(out, &tmp1, &tmp2);
}

static mk_inline void mk_crypt_hash_base_md5_private_h(mk_uint32_t* out, mk_uint32_t const* x, mk_uint32_t const* y, mk_uint32_t const* z)
{
	mk_uint32_t tmp;;

	mk_assert(out);
	mk_assert(x);
	mk_assert(y);
	mk_assert(z);

	/* return x ^ y ^ z; */

	mk_uint32_xor(&tmp, x, y);
	mk_uint32_xor(out, &tmp, z);
}

static mk_inline void mk_crypt_hash_base_md5_private_i(mk_uint32_t* out, mk_uint32_t const* x, mk_uint32_t const* y, mk_uint32_t const* z)
{
	mk_uint32_t tmp;;

	mk_assert(out);
	mk_assert(x);
	mk_assert(y);
	mk_assert(z);

	/* return y ^ (x | (~z)); */

	mk_uint32_cmplmnt(&tmp, z);
	mk_uint32_or(&tmp, x, &tmp);
	mk_uint32_xor(out, y, &tmp);
}

static mk_inline void mk_crypt_hash_base_md5_private_round_1(mk_uint32_t* a, mk_uint32_t const* b, mk_uint32_t const* c, mk_uint32_t const* d, void const* xk, int s, int i)
{
	mk_uint32_t tmp1;
	mk_uint32_t tmp2;

	mk_assert(a);
	mk_assert(b);
	mk_assert(c);
	mk_assert(d);
	mk_assert(xk);
	mk_assert(s > 0 && s < 32);
	mk_assert(i >= 0 && i < 64);

	/* a = b + rotl(a + f(b, c, d) + x[k] + table[i], s); */

	mk_crypt_hash_base_md5_private_f(&tmp1, b, c, d);
	mk_uint32_from_buff_le(&tmp2, xk);

	mk_uint32_add(&tmp1, a, &tmp1);
	mk_uint32_add(&tmp2, &tmp2, &mk_crypt_hash_base_md5_private_table[i]);
	mk_uint32_add(&tmp1, &tmp1, &tmp2);
	mk_uint32_rotl(&tmp1, &tmp1, s);
	mk_uint32_add(a, b, &tmp1);
}

static mk_inline void mk_crypt_hash_base_md5_private_round_2(mk_uint32_t* a, mk_uint32_t const* b, mk_uint32_t const* c, mk_uint32_t const* d, void const* xk, int s, int i)
{
	mk_uint32_t tmp1;
	mk_uint32_t tmp2;

	mk_assert(a);
	mk_assert(b);
	mk_assert(c);
	mk_assert(d);
	mk_assert(xk);
	mk_assert(s > 0 && s < 32);
	mk_assert(i >= 0 && i < 64);

	/* a = b + rotl(a + g(b, c, d) + x[k] + table[i - 1], s); */

	mk_crypt_hash_base_md5_private_g(&tmp1, b, c, d);
	mk_uint32_from_buff_le(&tmp2, xk);

	mk_uint32_add(&tmp1, a, &tmp1);
	mk_uint32_add(&tmp2, &tmp2, &mk_crypt_hash_base_md5_private_table[i]);
	mk_uint32_add(&tmp1, &tmp1, &tmp2);
	mk_uint32_rotl(&tmp1, &tmp1, s);
	mk_uint32_add(a, b, &tmp1);
}

static mk_inline void mk_crypt_hash_base_md5_private_round_3(mk_uint32_t* a, mk_uint32_t const* b, mk_uint32_t const* c, mk_uint32_t const* d, void const* xk, int s, int i)
{
	mk_uint32_t tmp1;
	mk_uint32_t tmp2;

	mk_assert(a);
	mk_assert(b);
	mk_assert(c);
	mk_assert(d);
	mk_assert(xk);
	mk_assert(s > 0 && s < 32);
	mk_assert(i >= 0 && i < 64);

	/* a = b + rotl(a + h(b, c, d) + x[k] + table[i - 1], s); */

	mk_crypt_hash_base_md5_private_h(&tmp1, b, c, d);
	mk_uint32_from_buff_le(&tmp2, xk);

	mk_uint32_add(&tmp1, a, &tmp1);
	mk_uint32_add(&tmp2, &tmp2, &mk_crypt_hash_base_md5_private_table[i]);
	mk_uint32_add(&tmp1, &tmp1, &tmp2);
	mk_uint32_rotl(&tmp1, &tmp1, s);
	mk_uint32_add(a, b, &tmp1);
}

static mk_inline void mk_crypt_hash_base_md5_private_round_4(mk_uint32_t* a, mk_uint32_t const* b, mk_uint32_t const* c, mk_uint32_t const* d, void const* xk, int s, int i)
{
	mk_uint32_t tmp1;
	mk_uint32_t tmp2;

	mk_assert(a);
	mk_assert(b);
	mk_assert(c);
	mk_assert(d);
	mk_assert(xk);
	mk_assert(s > 0 && s < 32);
	mk_assert(i >= 0 && i < 64);

	/* a = b + rotl(a + i(b, c, d) + x[k] + table[i - 1], s); */

	mk_crypt_hash_base_md5_private_i(&tmp1, b, c, d);
	mk_uint32_from_buff_le(&tmp2, xk);

	mk_uint32_add(&tmp1, a, &tmp1);
	mk_uint32_add(&tmp2, &tmp2, &mk_crypt_hash_base_md5_private_table[i]);
	mk_uint32_add(&tmp1, &tmp1, &tmp2);
	mk_uint32_rotl(&tmp1, &tmp1, s);
	mk_uint32_add(a, b, &tmp1);
}


mk_jumbo void mk_crypt_hash_base_md5_init(mk_crypt_hash_base_md5_pt self)
{
	static mk_uint32_t const mk_crypt_hash_base_md5_private_init[4] =
	{
		mk_uint32_c(0x67452301ul),
		mk_uint32_c(0xefcdab89ul),
		mk_uint32_c(0x98badcfeul),
		mk_uint32_c(0x10325476ul),
	};

	mk_assert(self);

	self->m_state[0] = mk_crypt_hash_base_md5_private_init[0];
	self->m_state[1] = mk_crypt_hash_base_md5_private_init[1];
	self->m_state[2] = mk_crypt_hash_base_md5_private_init[2];
	self->m_state[3] = mk_crypt_hash_base_md5_private_init[3];
	mk_uint64_zero(&self->m_len);
}

mk_jumbo void mk_crypt_hash_base_md5_append_blocks(mk_crypt_hash_base_md5_pt self, void const* blocks, int count)
{
	static mk_uint64_t const mk_crypt_hash_base_md5_private_max_blocks = mk_uint64_c(0x007ffffful, 0xfffffffful);

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
	mk_assert(mk_uint64_le(&new_len_blocks, &mk_crypt_hash_base_md5_private_max_blocks));
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

		mk_crypt_hash_base_md5_private_round_1(a, b, c, d, &input[ 0 * 4],  7,  0);
		mk_crypt_hash_base_md5_private_round_1(d, a, b, c, &input[ 1 * 4], 12,  1);
		mk_crypt_hash_base_md5_private_round_1(c, d, a, b, &input[ 2 * 4], 17,  2);
		mk_crypt_hash_base_md5_private_round_1(b, c, d, a, &input[ 3 * 4], 22,  3);
		mk_crypt_hash_base_md5_private_round_1(a, b, c, d, &input[ 4 * 4],  7,  4);
		mk_crypt_hash_base_md5_private_round_1(d, a, b, c, &input[ 5 * 4], 12,  5);
		mk_crypt_hash_base_md5_private_round_1(c, d, a, b, &input[ 6 * 4], 17,  6);
		mk_crypt_hash_base_md5_private_round_1(b, c, d, a, &input[ 7 * 4], 22,  7);
		mk_crypt_hash_base_md5_private_round_1(a, b, c, d, &input[ 8 * 4],  7,  8);
		mk_crypt_hash_base_md5_private_round_1(d, a, b, c, &input[ 9 * 4], 12,  9);
		mk_crypt_hash_base_md5_private_round_1(c, d, a, b, &input[10 * 4], 17, 10);
		mk_crypt_hash_base_md5_private_round_1(b, c, d, a, &input[11 * 4], 22, 11);
		mk_crypt_hash_base_md5_private_round_1(a, b, c, d, &input[12 * 4],  7, 12);
		mk_crypt_hash_base_md5_private_round_1(d, a, b, c, &input[13 * 4], 12, 13);
		mk_crypt_hash_base_md5_private_round_1(c, d, a, b, &input[14 * 4], 17, 14);
		mk_crypt_hash_base_md5_private_round_1(b, c, d, a, &input[15 * 4], 22, 15);

		mk_crypt_hash_base_md5_private_round_2(a, b, c, d, &input[ 1 * 4],  5, 16);
		mk_crypt_hash_base_md5_private_round_2(d, a, b, c, &input[ 6 * 4],  9, 17);
		mk_crypt_hash_base_md5_private_round_2(c, d, a, b, &input[11 * 4], 14, 18);
		mk_crypt_hash_base_md5_private_round_2(b, c, d, a, &input[ 0 * 4], 20, 19);
		mk_crypt_hash_base_md5_private_round_2(a, b, c, d, &input[ 5 * 4],  5, 20);
		mk_crypt_hash_base_md5_private_round_2(d, a, b, c, &input[10 * 4],  9, 21);
		mk_crypt_hash_base_md5_private_round_2(c, d, a, b, &input[15 * 4], 14, 22);
		mk_crypt_hash_base_md5_private_round_2(b, c, d, a, &input[ 4 * 4], 20, 23);
		mk_crypt_hash_base_md5_private_round_2(a, b, c, d, &input[ 9 * 4],  5, 24);
		mk_crypt_hash_base_md5_private_round_2(d, a, b, c, &input[14 * 4],  9, 25);
		mk_crypt_hash_base_md5_private_round_2(c, d, a, b, &input[ 3 * 4], 14, 26);
		mk_crypt_hash_base_md5_private_round_2(b, c, d, a, &input[ 8 * 4], 20, 27);
		mk_crypt_hash_base_md5_private_round_2(a, b, c, d, &input[13 * 4],  5, 28);
		mk_crypt_hash_base_md5_private_round_2(d, a, b, c, &input[ 2 * 4],  9, 29);
		mk_crypt_hash_base_md5_private_round_2(c, d, a, b, &input[ 7 * 4], 14, 30);
		mk_crypt_hash_base_md5_private_round_2(b, c, d, a, &input[12 * 4], 20, 31);

		mk_crypt_hash_base_md5_private_round_3(a, b, c, d, &input[ 5 * 4],  4, 32);
		mk_crypt_hash_base_md5_private_round_3(d, a, b, c, &input[ 8 * 4], 11, 33);
		mk_crypt_hash_base_md5_private_round_3(c, d, a, b, &input[11 * 4], 16, 34);
		mk_crypt_hash_base_md5_private_round_3(b, c, d, a, &input[14 * 4], 23, 35);
		mk_crypt_hash_base_md5_private_round_3(a, b, c, d, &input[ 1 * 4],  4, 36);
		mk_crypt_hash_base_md5_private_round_3(d, a, b, c, &input[ 4 * 4], 11, 37);
		mk_crypt_hash_base_md5_private_round_3(c, d, a, b, &input[ 7 * 4], 16, 38);
		mk_crypt_hash_base_md5_private_round_3(b, c, d, a, &input[10 * 4], 23, 39);
		mk_crypt_hash_base_md5_private_round_3(a, b, c, d, &input[13 * 4],  4, 40);
		mk_crypt_hash_base_md5_private_round_3(d, a, b, c, &input[ 0 * 4], 11, 41);
		mk_crypt_hash_base_md5_private_round_3(c, d, a, b, &input[ 3 * 4], 16, 42);
		mk_crypt_hash_base_md5_private_round_3(b, c, d, a, &input[ 6 * 4], 23, 43);
		mk_crypt_hash_base_md5_private_round_3(a, b, c, d, &input[ 9 * 4],  4, 44);
		mk_crypt_hash_base_md5_private_round_3(d, a, b, c, &input[12 * 4], 11, 45);
		mk_crypt_hash_base_md5_private_round_3(c, d, a, b, &input[15 * 4], 16, 46);
		mk_crypt_hash_base_md5_private_round_3(b, c, d, a, &input[ 2 * 4], 23, 47);

		mk_crypt_hash_base_md5_private_round_4(a, b, c, d, &input[ 0 * 4],  6, 48);
		mk_crypt_hash_base_md5_private_round_4(d, a, b, c, &input[ 7 * 4], 10, 49);
		mk_crypt_hash_base_md5_private_round_4(c, d, a, b, &input[14 * 4], 15, 50);
		mk_crypt_hash_base_md5_private_round_4(b, c, d, a, &input[ 5 * 4], 21, 51);
		mk_crypt_hash_base_md5_private_round_4(a, b, c, d, &input[12 * 4],  6, 52);
		mk_crypt_hash_base_md5_private_round_4(d, a, b, c, &input[ 3 * 4], 10, 53);
		mk_crypt_hash_base_md5_private_round_4(c, d, a, b, &input[10 * 4], 15, 54);
		mk_crypt_hash_base_md5_private_round_4(b, c, d, a, &input[ 1 * 4], 21, 55);
		mk_crypt_hash_base_md5_private_round_4(a, b, c, d, &input[ 8 * 4],  6, 56);
		mk_crypt_hash_base_md5_private_round_4(d, a, b, c, &input[15 * 4], 10, 57);
		mk_crypt_hash_base_md5_private_round_4(c, d, a, b, &input[ 6 * 4], 15, 58);
		mk_crypt_hash_base_md5_private_round_4(b, c, d, a, &input[13 * 4], 21, 59);
		mk_crypt_hash_base_md5_private_round_4(a, b, c, d, &input[ 4 * 4],  6, 60);
		mk_crypt_hash_base_md5_private_round_4(d, a, b, c, &input[11 * 4], 10, 61);
		mk_crypt_hash_base_md5_private_round_4(c, d, a, b, &input[ 2 * 4], 15, 62);
		mk_crypt_hash_base_md5_private_round_4(b, c, d, a, &input[ 9 * 4], 21, 63);

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

mk_jumbo void mk_crypt_hash_base_md5_append_last_partial_block(mk_crypt_hash_base_md5_pt self, void* block, int len)
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
		mk_crypt_hash_base_md5_append_blocks(self, input, 1);
		for(i = 0; i != 64 - 8; ++i){ input[i] = 0x00; }
	}
	mk_uint64_to_buff_le(&len_bits, &input[64 - 8]);
	mk_crypt_hash_base_md5_append_blocks(self, input, 1);
}

mk_jumbo void mk_crypt_hash_base_md5_finish(mk_crypt_hash_base_md5_pct self, void* digest)
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
