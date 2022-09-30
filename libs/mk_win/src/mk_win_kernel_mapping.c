#include "mk_win_kernel_mapping.h"

#include "mk_win_char.h"
#include "mk_win_str.h"
#include "mk_win_unicode.h"

#include "../../mk_win_base/src/mk_win_base_kernel_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_functions.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


#define mk_win_kernel_mapping_page_readonly           ((unsigned short int)(0x02ul))
#define mk_win_kernel_mapping_page_readwrite          ((unsigned short int)(0x04ul))
#define mk_win_kernel_mapping_page_writecopy          ((unsigned short int)(0x08ul))
#define mk_win_kernel_mapping_page_execute_read       ((unsigned short int)(0x20ul))
#define mk_win_kernel_mapping_page_execute_readwrite  ((unsigned short int)(0x40ul))
#define mk_win_kernel_mapping_page_execute_writecopy  ((unsigned short int)(0x80ul))

#define mk_win_kernel_mapping_sec_image            ((unsigned long int)(0x01000000ul))
#define mk_win_kernel_mapping_sec_reserve          ((unsigned long int)(0x04000000ul))
#define mk_win_kernel_mapping_sec_commit           ((unsigned long int)(0x08000000ul))
#define mk_win_kernel_mapping_sec_nocache          ((unsigned long int)(0x10000000ul))
#define mk_win_kernel_mapping_sec_writecombine     ((unsigned long int)(0x40000000ul))
#define mk_win_kernel_mapping_sec_large_pages      ((unsigned long int)(0x80000000ul))
#define mk_win_kernel_mapping_sec_image_no_execute ((unsigned long int)(mk_win_kernel_mapping_sec_image | mk_win_kernel_mapping_sec_nocache))

#define mk_win_kernel_mapping_map_write ((unsigned short int)(0x0002ul))
#define mk_win_kernel_mapping_map_read  ((unsigned short int)(0x0004ul))


mk_jumbo int mk_win_kernel_mapping_construct_ro(mk_win_base_types_handle_t file, mk_uint64_t max_len, mk_win_base_types_handle_t* ret)
{
	#if mk_win_api == mk_win_api_ansi
	unsigned long max_len_lo;
	unsigned long max_len_hi;
	mk_win_base_types_handle_t h;
	mk_assert(ret);
	max_len_lo = mk_uint64_to_long(&max_len);
	mk_uint64_shr(&max_len, &max_len, 32);
	max_len_hi = mk_uint64_to_long(&max_len);
	h = CreateFileMappingA(file, NULL, mk_win_kernel_mapping_page_readonly, ((mk_win_base_types_dword_t)(max_len_hi)), ((mk_win_base_types_dword_t)(max_len_lo)), NULL);
	mk_check(h);
	*ret = h;
	#elif mk_win_api == mk_win_api_wide
	unsigned long max_len_lo;
	unsigned long max_len_hi;
	mk_win_base_types_handle_t h;
	mk_assert(ret);
	max_len_lo = mk_uint64_to_long(&max_len);
	mk_uint64_shr(&max_len, &max_len, 32);
	max_len_hi = mk_uint64_to_long(&max_len);
	h = CreateFileMappingW(file, NULL, mk_win_kernel_mapping_page_readonly, ((mk_win_base_types_dword_t)(max_len_hi)), ((mk_win_base_types_dword_t)(max_len_lo)), NULL);
	mk_check(h);
	*ret = h;
	#elif mk_win_api == mk_win_api_both
	int unicode_enabled;
	mk_assert(ret);
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		unsigned long max_len_lo;
		unsigned long max_len_hi;
		mk_win_base_types_handle_t h;
		mk_assert(ret);
		max_len_lo = mk_uint64_to_long(&max_len);
		mk_uint64_shr(&max_len, &max_len, 32);
		max_len_hi = mk_uint64_to_long(&max_len);
		h = CreateFileMappingA(file, NULL, mk_win_kernel_mapping_page_readonly, ((mk_win_base_types_dword_t)(max_len_hi)), ((mk_win_base_types_dword_t)(max_len_lo)), NULL);
		mk_check(h);
		*ret = h;
	}
	else
	{
		unsigned long max_len_lo;
		unsigned long max_len_hi;
		mk_win_base_types_handle_t h;
		mk_assert(ret);
		max_len_lo = mk_uint64_to_long(&max_len);
		mk_uint64_shr(&max_len, &max_len, 32);
		max_len_hi = mk_uint64_to_long(&max_len);
		h = CreateFileMappingW(file, NULL, mk_win_kernel_mapping_page_readonly, ((mk_win_base_types_dword_t)(max_len_hi)), ((mk_win_base_types_dword_t)(max_len_lo)), NULL);
		mk_check(h);
		*ret = h;
	}
	#endif
	return 0;
}

mk_jumbo int mk_win_kernel_mapping_destruct(mk_win_base_types_handle_t mapping)
{
	mk_win_base_types_bool_t b;

	b = CloseHandle(mapping);
	mk_check(b != 0);

	return 0;
}
