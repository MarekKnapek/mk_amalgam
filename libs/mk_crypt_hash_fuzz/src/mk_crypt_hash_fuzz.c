#include "../../mk_crypt_hash/src/mk_crypt_hash_base_handle.h"
#include "../../mk_crypt_hash/src/mk_crypt_hash_base_value.h"
#include "../../mk_crypt_hash/src/mk_crypt_hash_stream_handle.h"
#include "../../mk_crypt_hash/src/mk_crypt_hash_stream_value.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


struct hash_test_s
{
	mk_crypt_hash_base_type_t m_type;
	void const* m_input;
	int m_input_len;
	void const* m_output;
};
typedef struct hash_test_s hash_test_t;
typedef hash_test_t* hash_test_pt;
typedef hash_test_t const* hash_test_pct;


static char const s_wiki_msg_1[] = "The quick brown fox jumps over the lazy dog";
static char const s_wiki_msg_2[] = "The quick brown fox jumps over the lazy cog";
static char const s_wiki_msg_3[] = "The quick brown fox jumps over the lazy dog.";
static char const s_wiki_md4_msg_1[] = "a";
static char const s_wiki_md4_msg_2[] = "abc";
static char const s_wiki_md4_msg_3[] = "message digest";
static char const s_wiki_md4_msg_4[] = "abcdefghijklmnopqrstuvwxyz";
static char const s_wiki_md4_msg_5[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
static char const s_wiki_md4_msg_6[] = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
static char const s_wiki_md4_msg_7[] = "\x83\x9c\x7a\x4d\x7a\x92\xcb\x56\x78\xa5\xd5\xb9\xee\xa5\xa7\x57\x3c\x8a\x74\xde\xb3\x66\xc3\xdc\x20\xa0\x83\xb6\x9f\x5d\x2a\x3b\xb3\x71\x9d\xc6\x98\x91\xe9\xf9\x5e\x80\x9f\xd7\xe8\xb2\x3b\xa6\x31\x8e\xdd\x45\xe5\x1f\xe3\x97\x08\xbf\x94\x27\xe9\xc3\xe8\xb9";
static char const s_wiki_md4_msg_8[] = "\x83\x9c\x7a\x4d\x7a\x92\xcb\xd6\x78\xa5\xd5\x29\xee\xa5\xa7\x57\x3c\x8a\x74\xde\xb3\x66\xc3\xdc\x20\xa0\x83\xb6\x9f\x5d\x2a\x3b\xb3\x71\x9d\xc6\x98\x91\xe9\xf9\x5e\x80\x9f\xd7\xe8\xb2\x3b\xa6\x31\x8e\xdc\x45\xe5\x1f\xe3\x97\x08\xbf\x94\x27\xe9\xc3\xe8\xb9";
static unsigned char const s_digest_md2_null[mk_crypt_hash_base_md2_digest_len] = {0x83, 0x50, 0xe5, 0xa3, 0xe2, 0x4c, 0x15, 0x3d, 0xf2, 0x27, 0x5c, 0x9f, 0x80, 0x69, 0x27, 0x73};
static unsigned char const s_digest_md4_null[mk_crypt_hash_base_md4_digest_len] = {0x31, 0xd6, 0xcf, 0xe0, 0xd1, 0x6a, 0xe9, 0x31, 0xb7, 0x3c, 0x59, 0xd7, 0xe0, 0xc0, 0x89, 0xc0};
static unsigned char const s_digest_md5_null[mk_crypt_hash_base_md5_digest_len] = {0xd4, 0x1d, 0x8c, 0xd9, 0x8f, 0x00, 0xb2, 0x04, 0xe9, 0x80, 0x09, 0x98, 0xec, 0xf8, 0x42, 0x7e};
static unsigned char const s_digest_md2_wiki_msg_1[mk_crypt_hash_base_md2_digest_len] = {0x03, 0xd8, 0x5a, 0x0d, 0x62, 0x9d, 0x2c, 0x44, 0x2e, 0x98, 0x75, 0x25, 0x31, 0x9f, 0xc4, 0x71};
static unsigned char const s_digest_md2_wiki_msg_2[mk_crypt_hash_base_md2_digest_len] = {0x6b, 0x89, 0x0c, 0x92, 0x92, 0x66, 0x8c, 0xdb, 0xbf, 0xda, 0x00, 0xa4, 0xeb, 0xf3, 0x1f, 0x05};
static unsigned char const s_digest_md4_wiki_msg_1[mk_crypt_hash_base_md4_digest_len] = {0x1b, 0xee, 0x69, 0xa4, 0x6b, 0xa8, 0x11, 0x18, 0x5c, 0x19, 0x47, 0x62, 0xab, 0xae, 0xae, 0x90};
static unsigned char const s_digest_md4_wiki_msg_2[mk_crypt_hash_base_md4_digest_len] = {0xb8, 0x6e, 0x13, 0x0c, 0xe7, 0x02, 0x8d, 0xa5, 0x9e, 0x67, 0x2d, 0x56, 0xad, 0x01, 0x13, 0xdf};
static unsigned char const s_digest_md5_wiki_msg_1[mk_crypt_hash_base_md5_digest_len] = {0x9e, 0x10, 0x7d, 0x9d, 0x37, 0x2b, 0xb6, 0x82, 0x6b, 0xd8, 0x1d, 0x35, 0x42, 0xa4, 0x19, 0xd6};
static unsigned char const s_digest_md5_wiki_msg_3[mk_crypt_hash_base_md5_digest_len] = {0xe4, 0xd9, 0x09, 0xc2, 0x90, 0xd0, 0xfb, 0x1c, 0xa0, 0x68, 0xff, 0xad, 0xdf, 0x22, 0xcb, 0xd0};
static unsigned char const s_digest_md4_wiki_md4_msg_1[mk_crypt_hash_base_md4_digest_len] = {0xbd, 0xe5, 0x2c, 0xb3, 0x1d, 0xe3, 0x3e, 0x46, 0x24, 0x5e, 0x05, 0xfb, 0xdb, 0xd6, 0xfb, 0x24};
static unsigned char const s_digest_md4_wiki_md4_msg_2[mk_crypt_hash_base_md4_digest_len] = {0xa4, 0x48, 0x01, 0x7a, 0xaf, 0x21, 0xd8, 0x52, 0x5f, 0xc1, 0x0a, 0xe8, 0x7a, 0xa6, 0x72, 0x9d};
static unsigned char const s_digest_md4_wiki_md4_msg_3[mk_crypt_hash_base_md4_digest_len] = {0xd9, 0x13, 0x0a, 0x81, 0x64, 0x54, 0x9f, 0xe8, 0x18, 0x87, 0x48, 0x06, 0xe1, 0xc7, 0x01, 0x4b};
static unsigned char const s_digest_md4_wiki_md4_msg_4[mk_crypt_hash_base_md4_digest_len] = {0xd7, 0x9e, 0x1c, 0x30, 0x8a, 0xa5, 0xbb, 0xcd, 0xee, 0xa8, 0xed, 0x63, 0xdf, 0x41, 0x2d, 0xa9};
static unsigned char const s_digest_md4_wiki_md4_msg_5[mk_crypt_hash_base_md4_digest_len] = {0x04, 0x3f, 0x85, 0x82, 0xf2, 0x41, 0xdb, 0x35, 0x1c, 0xe6, 0x27, 0xe1, 0x53, 0xe7, 0xf0, 0xe4};
static unsigned char const s_digest_md4_wiki_md4_msg_6[mk_crypt_hash_base_md4_digest_len] = {0xe3, 0x3b, 0x4d, 0xdc, 0x9c, 0x38, 0xf2, 0x19, 0x9c, 0x3e, 0x7b, 0x16, 0x4f, 0xcc, 0x05, 0x36};
static unsigned char const s_digest_md4_wiki_md4_msg_78[mk_crypt_hash_base_md4_digest_len] = {0x4d, 0x7e, 0x6a, 0x1d, 0xef, 0xa9, 0x3d, 0x2d, 0xde, 0x05, 0xb4, 0x5d, 0x86, 0x4c, 0x42, 0x9b};

static hash_test_t const s_hash_tests[] =
{
	{mk_crypt_hash_base_type_e_md2, NULL, 0, s_digest_md2_null},
	{mk_crypt_hash_base_type_e_md4, NULL, 0, s_digest_md4_null},
	{mk_crypt_hash_base_type_e_md5, NULL, 0, s_digest_md5_null},
	{mk_crypt_hash_base_type_e_md2, s_wiki_msg_1, (int)(sizeof(s_wiki_msg_1) - 1), s_digest_md2_wiki_msg_1},
	{mk_crypt_hash_base_type_e_md4, s_wiki_msg_1, (int)(sizeof(s_wiki_msg_1) - 1), s_digest_md4_wiki_msg_1},
	{mk_crypt_hash_base_type_e_md5, s_wiki_msg_1, (int)(sizeof(s_wiki_msg_1) - 1), s_digest_md5_wiki_msg_1},
	{mk_crypt_hash_base_type_e_md2, s_wiki_msg_2, (int)(sizeof(s_wiki_msg_2) - 1), s_digest_md2_wiki_msg_2},
	{mk_crypt_hash_base_type_e_md4, s_wiki_msg_2, (int)(sizeof(s_wiki_msg_2) - 1), s_digest_md4_wiki_msg_2},
	{mk_crypt_hash_base_type_e_md5, s_wiki_msg_3, (int)(sizeof(s_wiki_msg_3) - 1), s_digest_md5_wiki_msg_3},
	{mk_crypt_hash_base_type_e_md4, s_wiki_md4_msg_1, (int)(sizeof(s_wiki_md4_msg_1) - 1), s_digest_md4_wiki_md4_msg_1},
	{mk_crypt_hash_base_type_e_md4, s_wiki_md4_msg_2, (int)(sizeof(s_wiki_md4_msg_2) - 1), s_digest_md4_wiki_md4_msg_2},
	{mk_crypt_hash_base_type_e_md4, s_wiki_md4_msg_3, (int)(sizeof(s_wiki_md4_msg_3) - 1), s_digest_md4_wiki_md4_msg_3},
	{mk_crypt_hash_base_type_e_md4, s_wiki_md4_msg_4, (int)(sizeof(s_wiki_md4_msg_4) - 1), s_digest_md4_wiki_md4_msg_4},
	{mk_crypt_hash_base_type_e_md4, s_wiki_md4_msg_5, (int)(sizeof(s_wiki_md4_msg_5) - 1), s_digest_md4_wiki_md4_msg_5},
	{mk_crypt_hash_base_type_e_md4, s_wiki_md4_msg_6, (int)(sizeof(s_wiki_md4_msg_6) - 1), s_digest_md4_wiki_md4_msg_6},
	{mk_crypt_hash_base_type_e_md4, s_wiki_md4_msg_7, (int)(sizeof(s_wiki_md4_msg_7) - 1), s_digest_md4_wiki_md4_msg_78},
	{mk_crypt_hash_base_type_e_md4, s_wiki_md4_msg_8, (int)(sizeof(s_wiki_md4_msg_8) - 1), s_digest_md4_wiki_md4_msg_78},
};
static int const s_hash_tests_count = (int)(sizeof(s_hash_tests) / sizeof(s_hash_tests[0]));


#define mk_memcpy(dst, src, cnt) { unsigned char* d; unsigned char const* s; int n; int iii; d = (unsigned char*)(dst); s = (unsigned char const*)(src); n = (int)(cnt); for(iii = 0; iii != n; ++iii, ++d, ++s) *d = *s; }


static mk_inline int mk_memcmp(void const* x, void const* y, size_t len)
{
	unsigned char const* a;
	unsigned char const* b;
	size_t i;

	mk_assert(x);
	mk_assert(y);
	mk_assert(len >= 0);

	if(x == y || len == 0)
	{
		return 0;
	}
	else
	{
		a = (unsigned char const*)x;
		b = (unsigned char const*)y;
		for(i = 0; i != len; ++i, ++a, ++b)
		{
			if(*a != *b)
			{
				return ((int)(((int)(*a)) - ((int)(*b))));
			}
		}
		return 0;
	}
}


static mk_inline int test_base_all_h(void)
{
	int i;
	hash_test_pct test;
	int block_len;
	int rest_len;
	mk_crypt_hash_base_val_block_t block;
	mk_crypt_hash_base_handle_h hash;
	mk_crypt_hash_base_val_digest_t digest;

	for(i = 0; i != s_hash_tests_count; ++i)
	{
		test = &s_hash_tests[i];
		block_len = mk_crypt_hash_base_type_block_len(test->m_type);
		rest_len = test->m_input_len - (test->m_input_len / block_len) * block_len;
		mk_memcpy(&block, ((unsigned char const*)(test->m_input)) + (test->m_input_len / block_len) * block_len, rest_len);
		mk_crypt_hash_base_handle_create(&hash, test->m_type);
		mk_crypt_hash_base_handle_init(hash);
		mk_crypt_hash_base_handle_append_blocks(hash, test->m_input, test->m_input_len / block_len);
		mk_crypt_hash_base_handle_append_last_partial_block(hash, &block, rest_len);
		mk_crypt_hash_base_handle_finish(hash, &digest);
		mk_crypt_hash_base_handle_destroy(hash);
		mk_check(mk_memcmp(&digest, test->m_output, mk_crypt_hash_base_type_digest_len(test->m_type)) == 0);
	}
	return 0;
}

static mk_inline int test_base_all_v(void)
{
	int i;
	hash_test_pct test;
	int block_len;
	int rest_len;
	mk_crypt_hash_base_val_block_t block;
	mk_crypt_hash_base_value_t hash;
	mk_crypt_hash_base_val_digest_t digest;

	for(i = 0; i != s_hash_tests_count; ++i)
	{
		test = &s_hash_tests[i];
		block_len = mk_crypt_hash_base_type_block_len(test->m_type);
		rest_len = test->m_input_len - (test->m_input_len / block_len) * block_len;
		mk_memcpy(&block, ((unsigned char const*)(test->m_input)) + (test->m_input_len / block_len) * block_len, rest_len);
		mk_crypt_hash_base_value_init(test->m_type, &hash);
		mk_crypt_hash_base_value_append_blocks(test->m_type, &hash, test->m_input, test->m_input_len / block_len);
		mk_crypt_hash_base_value_append_last_partial_block(test->m_type, &hash, &block, rest_len);
		mk_crypt_hash_base_value_finish(test->m_type, &hash, &digest);
		mk_check(mk_memcmp(&digest, test->m_output, mk_crypt_hash_base_type_digest_len(test->m_type)) == 0);
	}
	return 0;
}

static mk_inline int test_base_all_vt(void)
{
	int i;
	hash_test_pct test;
	int block_len;
	int rest_len;
	mk_crypt_hash_base_val_block_t block;
	mk_crypt_hash_base_value_tag_t hash;
	mk_crypt_hash_base_val_digest_t digest;

	for(i = 0; i != s_hash_tests_count; ++i)
	{
		test = &s_hash_tests[i];
		block_len = mk_crypt_hash_base_type_block_len(test->m_type);
		rest_len = test->m_input_len - (test->m_input_len / block_len) * block_len;
		mk_memcpy(&block, ((unsigned char const*)(test->m_input)) + (test->m_input_len / block_len) * block_len, rest_len);
		mk_crypt_hash_base_value_tag_init(&hash, test->m_type);
		mk_crypt_hash_base_value_tag_append_blocks(&hash, test->m_input, test->m_input_len / block_len);
		mk_crypt_hash_base_value_tag_append_last_partial_block(&hash, &block, rest_len);
		mk_crypt_hash_base_value_tag_finish(&hash, &digest);
		mk_check(mk_memcmp(&digest, test->m_output, mk_crypt_hash_base_type_digest_len(test->m_type)) == 0);
	}
	return 0;
}


static mk_inline int test_all_h(void)
{
	int i;
	hash_test_pct test;
	mk_crypt_hash_stream_handle_h hash;
	mk_crypt_hash_base_val_digest_t digest;

	for(i = 0; i != s_hash_tests_count; ++i)
	{
		test = &s_hash_tests[i];
		mk_crypt_hash_stream_handle_create(&hash, test->m_type);
		mk_crypt_hash_stream_handle_init(hash);
		mk_crypt_hash_stream_handle_append(hash, test->m_input, test->m_input_len);
		mk_crypt_hash_stream_handle_end_stream(hash);
		mk_crypt_hash_stream_handle_finish(hash, &digest);
		mk_crypt_hash_stream_handle_destroy(hash);
		mk_check(mk_memcmp(&digest, test->m_output, mk_crypt_hash_base_type_digest_len(test->m_type)) == 0);
	}
	return 0;
}

static mk_inline int test_all_v(void)
{
	int i;
	hash_test_pct test;
	mk_crypt_hash_stream_value_t hash;
	mk_crypt_hash_base_val_digest_t digest;

	for(i = 0; i != s_hash_tests_count; ++i)
	{
		test = &s_hash_tests[i];
		mk_crypt_hash_stream_value_init(test->m_type, &hash);
		mk_crypt_hash_stream_value_append(test->m_type, &hash, test->m_input, test->m_input_len);
		mk_crypt_hash_stream_value_end_stream(test->m_type, &hash);
		mk_crypt_hash_stream_value_finish(test->m_type, &hash, &digest);
		mk_check(mk_memcmp(&digest, test->m_output, mk_crypt_hash_base_type_digest_len(test->m_type)) == 0);
	}
	return 0;
}

static mk_inline int test_all_vt(void)
{
	int i;
	hash_test_pct test;
	mk_crypt_hash_stream_value_tag_t hash;
	mk_crypt_hash_base_val_digest_t digest;

	for(i = 0; i != s_hash_tests_count; ++i)
	{
		test = &s_hash_tests[i];
		mk_crypt_hash_stream_value_tag_init(&hash, test->m_type);
		mk_crypt_hash_stream_value_tag_append(&hash, test->m_input, test->m_input_len);
		mk_crypt_hash_stream_value_tag_end_stream(&hash);
		mk_crypt_hash_stream_value_tag_finish(&hash, &digest);
		mk_check(mk_memcmp(&digest, test->m_output, mk_crypt_hash_base_type_digest_len(test->m_type)) == 0);
	}
	return 0;
}


static mk_inline int test_all(void)
{
	mk_try(test_base_all_h());
	mk_try(test_base_all_v());
	mk_try(test_base_all_vt());
	mk_try(test_all_h());
	mk_try(test_all_v());
	mk_try(test_all_vt());
	return 0;
}


int main(void)
{
	mk_try(test_all());
	return 0;
}


#undef mk_memcpy
