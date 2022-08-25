#ifndef mk_include_guard_win_kernel_resource
#define mk_include_guard_win_kernel_resource


#include "../../mk_utils/src/mk_jumbo.h"

#include "../../mk_win_base/src/mk_win_base_kernel_types.h"


#define mk_win_kernel_resource_type_cursor        1
#define mk_win_kernel_resource_type_bitmap        2
#define mk_win_kernel_resource_type_icon          3
#define mk_win_kernel_resource_type_menu          4
#define mk_win_kernel_resource_type_dialog        5
#define mk_win_kernel_resource_type_string        6
#define mk_win_kernel_resource_type_fontdir       7
#define mk_win_kernel_resource_type_font          8
#define mk_win_kernel_resource_type_accelerator   9
#define mk_win_kernel_resource_type_rcdata       10
#define mk_win_kernel_resource_type_messagetable 11
#define mk_win_kernel_resource_type_group_cursor (mk_win_kernel_resource_type_cursor + 11)
#define mk_win_kernel_resource_type_group_icon   (mk_win_kernel_resource_type_icon + 11)
#define mk_win_kernel_resource_type_version      16
#define mk_win_kernel_resource_type_dlginclude   17
#define mk_win_kernel_resource_type_plugplay     19 /* winver >= 0x0400 */
#define mk_win_kernel_resource_type_vxd          20 /* winver >= 0x0400 */
#define mk_win_kernel_resource_type_anicursor    21 /* winver >= 0x0400 */
#define mk_win_kernel_resource_type_aniicon      22 /* winver >= 0x0400 */
#define mk_win_kernel_resource_type_html         23
#define mk_win_kernel_resource_type_manifest     24


mk_jumbo int mk_win_kernel_resource_find(mk_win_base_kernel_types_hmodule_t module, mk_win_base_types_strac_t name, mk_win_base_types_strac_t type, mk_win_base_kernel_types_hrsrc_t* resource);
mk_jumbo int mk_win_kernel_resource_find_bytypeid(mk_win_base_kernel_types_hmodule_t module, mk_win_base_types_strac_t name, mk_win_base_types_uint16_t type, mk_win_base_kernel_types_hrsrc_t* resource);
mk_jumbo int mk_win_kernel_resource_load(mk_win_base_kernel_types_hmodule_t module, mk_win_base_kernel_types_hrsrc_t resource, mk_win_base_kernel_types_hglobal_t* global);
mk_jumbo int mk_win_kernel_resource_lock(mk_win_base_kernel_types_hglobal_t global, mk_win_base_types_void_t* data);


#endif
