#include "mk_uint_fuzz_c.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4127) /* warning C4127: conditional expression is constant */
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../../mk_int/src/exact/mk_uint_8.h"
#include "../../mk_int/src/exact/mk_uint_16.h"
#include "../../mk_int/src/exact/mk_uint_32.h"
#include "../../mk_int/src/exact/mk_uint_64.h"
#include "../../mk_int/src/exact/mk_uint_128.h"

#include <string.h>


static int g_mk_uint_fuzz_c_private_tested;


#define test(x) do{ if(!(x)){ int volatile* volatile ptr = NULL; *ptr = 0; } }while(0)


void mk_uint_fuzz_c(unsigned char const* data)
{
	static unsigned char const s_buff[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77};
	static mk_uint8_t const s_u8 = mk_uint8_c(0x01ul);
	static mk_uint16_t const s_u16 = mk_uint16_c(0x0123ul);
	static mk_uint32_t const s_u32 = mk_uint32_c(0x01234567ul);
	static mk_uint64_t const s_u64 = mk_uint64_c(0x01234567ul, 0x89abcdeful);
	static mk_uint128_t const s_u128 = mk_uint128_c(0x01234567ul, 0x89abcdeful, 0x00112233ul, 0x44556677ul);

	unsigned char buff[sizeof(s_buff)];

	(void)data;

	if(g_mk_uint_fuzz_c_private_tested == 0)
	{
		++g_mk_uint_fuzz_c_private_tested;
		test(sizeof(s_buff) == 128 / 8);
		test(sizeof(s_u8) == 8 / 8);
		test(sizeof(s_u16) == 16 / 8);
		test(sizeof(s_u32) == 32 / 8);
		test(sizeof(s_u64) == 64 / 8);
		test(sizeof(s_u128) == 128 / 8);
		mk_uint8_to_buff_be(&s_u8, &buff); test(memcmp(&buff, &s_buff, sizeof(s_u8)) == 0);
		mk_uint16_to_buff_be(&s_u16, &buff); test(memcmp(&buff, &s_buff, sizeof(s_u16)) == 0);
		mk_uint32_to_buff_be(&s_u32, &buff); test(memcmp(&buff, &s_buff, sizeof(s_u32)) == 0);
		mk_uint64_to_buff_be(&s_u64, &buff); test(memcmp(&buff, &s_buff, sizeof(s_u64)) == 0);
		mk_uint128_to_buff_be(&s_u128, &buff); test(memcmp(&buff, &s_buff, sizeof(s_u128)) == 0);
	}
}


#undef test


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
