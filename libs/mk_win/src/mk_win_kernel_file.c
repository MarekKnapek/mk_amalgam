#include "mk_win_kernel_file.h"

#include "mk_win_char.h"
#include "mk_win_str.h"
#include "mk_win_unicode.h"

#include "../../mk_win_base/src/mk_win_base_kernel_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_functions.h"

#include "../../mk_int/src/exact/mk_uint_64.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


#define mk_win_kernel_file_rights_file_read_data        ((unsigned short)(0x0001ul))
#define mk_win_kernel_file_rights_file_write_data       ((unsigned short)(0x0002ul))
#define mk_win_kernel_file_rights_file_append_data      ((unsigned short)(0x0004ul))
#define mk_win_kernel_file_rights_file_read_ea          ((unsigned short)(0x0008ul))
#define mk_win_kernel_file_rights_file_write_ea         ((unsigned short)(0x0010ul))
#define mk_win_kernel_file_rights_file_execute          ((unsigned short)(0x0020ul))
#define mk_win_kernel_file_rights_file_read_attributes  ((unsigned short)(0x0080ul))
#define mk_win_kernel_file_rights_file_write_attributes ((unsigned short)(0x0100ul))

#define mk_win_kernel_file_rights_pipe_read_data            ((unsigned short)(0x0001ul))
#define mk_win_kernel_file_rights_pipe_write_data           ((unsigned short)(0x0002ul))
#define mk_win_kernel_file_rights_pipe_create_pipe_instance ((unsigned short)(0x0004ul))
#define mk_win_kernel_file_rights_pipe_read_attributes      ((unsigned short)(0x0080ul))
#define mk_win_kernel_file_rights_pipe_write_attributes     ((unsigned short)(0x0100ul))

#define mk_win_kernel_file_rights_dir_list_directory   ((unsigned short)(0x0001ul))
#define mk_win_kernel_file_rights_dir_add_file         ((unsigned short)(0x0002ul))
#define mk_win_kernel_file_rights_dir_add_subdirectory ((unsigned short)(0x0004ul))
#define mk_win_kernel_file_rights_dir_read_ea          ((unsigned short)(0x0008ul))
#define mk_win_kernel_file_rights_dir_write_ea         ((unsigned short)(0x0010ul))
#define mk_win_kernel_file_rights_dir_traverse         ((unsigned short)(0x0020ul))
#define mk_win_kernel_file_rights_dir_delete_child     ((unsigned short)(0x0040ul))
#define mk_win_kernel_file_rights_dir_read_attributes  ((unsigned short)(0x0080ul))
#define mk_win_kernel_file_rights_dir_write_attributes ((unsigned short)(0x0100ul))

#define mk_win_kernel_file_share_none   ((unsigned short)(0x0000ul))
#define mk_win_kernel_file_share_read   ((unsigned short)(0x0001ul))
#define mk_win_kernel_file_share_write  ((unsigned short)(0x0002ul))
#define mk_win_kernel_file_share_delete ((unsigned short)(0x0004ul))

#define mk_win_kernel_file_cd_create_new        ((int)(1))
#define mk_win_kernel_file_cd_create_always     ((int)(2))
#define mk_win_kernel_file_cd_open_existing     ((int)(3))
#define mk_win_kernel_file_cd_open_always       ((int)(4))
#define mk_win_kernel_file_cd_truncate_existing ((int)(5))

#define mk_win_kernel_file_attribute_readonly              ((unsigned long)(0x00000001ul))
#define mk_win_kernel_file_attribute_hidden                ((unsigned long)(0x00000002ul))
#define mk_win_kernel_file_attribute_system                ((unsigned long)(0x00000004ul))
#define mk_win_kernel_file_attribute_directory             ((unsigned long)(0x00000010ul))
#define mk_win_kernel_file_attribute_archive               ((unsigned long)(0x00000020ul))
#define mk_win_kernel_file_attribute_device                ((unsigned long)(0x00000040ul))
#define mk_win_kernel_file_attribute_normal                ((unsigned long)(0x00000080ul))
#define mk_win_kernel_file_attribute_temporary             ((unsigned long)(0x00000100ul))
#define mk_win_kernel_file_attribute_sparse_file           ((unsigned long)(0x00000200ul))
#define mk_win_kernel_file_attribute_reparse_point         ((unsigned long)(0x00000400ul))
#define mk_win_kernel_file_attribute_compressed            ((unsigned long)(0x00000800ul))
#define mk_win_kernel_file_attribute_offline               ((unsigned long)(0x00001000ul))
#define mk_win_kernel_file_attribute_not_content_indexed   ((unsigned long)(0x00002000ul))
#define mk_win_kernel_file_attribute_encrypted             ((unsigned long)(0x00004000ul))
#define mk_win_kernel_file_attribute_integrity_stream      ((unsigned long)(0x00008000ul))
#define mk_win_kernel_file_attribute_virtual               ((unsigned long)(0x00010000ul))
#define mk_win_kernel_file_attribute_no_scrub_data         ((unsigned long)(0x00020000ul))
#define mk_win_kernel_file_attribute_ea                    ((unsigned long)(0x00040000ul))
#define mk_win_kernel_file_attribute_recall_on_open        ((unsigned long)(0x00040000ul))
#define mk_win_kernel_file_attribute_pinned                ((unsigned long)(0x00080000ul))
#define mk_win_kernel_file_attribute_unpinned              ((unsigned long)(0x00100000ul))
#define mk_win_kernel_file_attribute_recall_on_data_access ((unsigned long)(0x00400000ul))

#define mk_win_kernel_file_flag_first_pipe_instance   ((unsigned long)(0x00080000ul))
#define mk_win_kernel_file_flag_open_no_recall        ((unsigned long)(0x00100000ul))
#define mk_win_kernel_file_flag_open_reparse_point    ((unsigned long)(0x00200000ul))
#define mk_win_kernel_file_flag_session_aware         ((unsigned long)(0x00800000ul))
#define mk_win_kernel_file_flag_posix_semantics       ((unsigned long)(0x01000000ul))
#define mk_win_kernel_file_flag_backup_semantics      ((unsigned long)(0x02000000ul))
#define mk_win_kernel_file_flag_delete_on_close       ((unsigned long)(0x04000000ul))
#define mk_win_kernel_file_flag_sequential_scan       ((unsigned long)(0x08000000ul))
#define mk_win_kernel_file_flag_random_access         ((unsigned long)(0x10000000ul))
#define mk_win_kernel_file_flag_no_buffering          ((unsigned long)(0x20000000ul))
#define mk_win_kernel_file_flag_overlapped            ((unsigned long)(0x40000000ul))
#define mk_win_kernel_file_flag_write_through         ((unsigned long)(0x80000000ul))

#define mk_win_kernel_file_security_anonymous        ((unsigned long)(0ul << 16))
#define mk_win_kernel_file_security_identification   ((unsigned long)(1ul << 16))
#define mk_win_kernel_file_security_impersonation    ((unsigned long)(2ul << 16))
#define mk_win_kernel_file_security_delegation       ((unsigned long)(3ul << 16))
#define mk_win_kernel_file_security_context_tracking ((unsigned long)(0x00040000ul))
#define mk_win_kernel_file_security_effective_only   ((unsigned long)(0x00080000ul))
#define mk_win_kernel_file_security_sqos_present     ((unsigned long)(0x00100000ul))
#define mk_win_kernel_file_security_valid_sqos_flags ((unsigned long)(0x001f0000ul))

#define mk_win_kernel_file_invalid_handle_value ((mk_win_base_types_handle_t)((mk_win_base_types_void_lpt)(-1)))
#define mk_win_kernel_file_invalid_file_size ((mk_win_base_types_dword_t)(0xfffffffful))


mk_jumbo int mk_win_kernel_file_construct_existing_ro(mk_win_strc_t name, mk_win_base_types_handle_t* ret)
{
	#if mk_win_api == mk_win_api_ansi
	char* namea;
	mk_win_base_types_handle_t h;
	mk_assert(name);
	mk_assert(ret);
	mk_try(mk_win_str_to_narrow_z(name, 0, &namea));
	h = CreateFileA(namea, mk_win_kernel_file_rights_file_read_data | mk_win_kernel_file_rights_file_read_attributes, mk_win_kernel_file_share_read | mk_win_kernel_file_share_delete, NULL, mk_win_kernel_file_cd_open_existing, mk_win_kernel_file_attribute_normal, mk_win_base_types_null);
	mk_check(h != mk_win_kernel_file_invalid_handle_value);
	*ret = h;
	#elif mk_win_api == mk_win_api_wide
	wchar_t* namew;
	mk_win_base_types_handle_t h;
	mk_assert(name);
	mk_assert(ret);
	mk_try(mk_win_str_to_wide_z(name, 0, &namew));
	h = CreateFileW(namew, mk_win_kernel_file_rights_file_read_data | mk_win_kernel_file_rights_file_read_attributes, mk_win_kernel_file_share_read | mk_win_kernel_file_share_delete, NULL, mk_win_kernel_file_cd_open_existing, mk_win_kernel_file_attribute_normal, mk_win_base_types_null);
	mk_check(h != mk_win_kernel_file_invalid_handle_value);
	*ret = h;
	#elif mk_win_api == mk_win_api_both
	int unicode_enabled;
	mk_win_base_types_handle_t h;
	mk_assert(name);
	mk_assert(ret);
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		char* namea;
		mk_try(mk_win_str_to_narrow_z(name, 0, &namea));
		h = CreateFileA(namea, mk_win_kernel_file_rights_file_read_data | mk_win_kernel_file_rights_file_read_attributes, mk_win_kernel_file_share_read | mk_win_kernel_file_share_delete, NULL, mk_win_kernel_file_cd_open_existing, mk_win_kernel_file_attribute_normal, mk_win_base_types_null);
		mk_check(h != mk_win_kernel_file_invalid_handle_value);
		*ret = h;
	}
	else
	{
		wchar_t* namew;
		mk_try(mk_win_str_to_wide_z(name, 0, &namew));
		h = CreateFileW(namew, mk_win_kernel_file_rights_file_read_data | mk_win_kernel_file_rights_file_read_attributes, mk_win_kernel_file_share_read | mk_win_kernel_file_share_delete, NULL, mk_win_kernel_file_cd_open_existing, mk_win_kernel_file_attribute_normal, mk_win_base_types_null);
		mk_check(h != mk_win_kernel_file_invalid_handle_value);
		*ret = h;
	}
	#endif
	return 0;
}

mk_jumbo int mk_win_kernel_file_destruct(mk_win_base_types_handle_t file)
{
	mk_win_base_types_bool_t b;

	b = CloseHandle(file);
	mk_check(b != 0);

	return 0;
}

mk_jumbo int mk_win_kernel_file_get_length(mk_win_base_types_handle_t file, mk_uint64_t* ret)
{
	mk_win_base_types_dword_t lo;
	mk_win_base_types_dword_t hi;
	mk_uint64_t lo64;
	mk_uint64_t hi64;

	mk_assert(file);
	mk_assert(ret);

	lo = GetFileSize(file, &hi);
	mk_check(lo != mk_win_kernel_file_invalid_file_size || GetLastError() == 0);
	mk_uint64_from_long(&lo64, ((unsigned long int)(lo)));
	mk_uint64_from_long(&hi64, ((unsigned long int)(hi)));
	mk_uint64_shl(&hi64, &hi64, 32);
	mk_uint64_or(ret, &hi64, &lo64);

	return 0;
}
