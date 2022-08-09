#ifndef mk_win_base_kernel_functions
#define mk_win_base_kernel_functions


#include "mk_win_base_kernel_types.h"
#include "mk_win_base_keywords.h"
#include "mk_win_base_types.h"

#include "../../mk_utils/src/mk_cpp.h"


mk_extern_c mk_win_base_keywords_dll_import mk_win_base_kernel_types_hmodule_t mk_win_base_keywords_calling_convention_api GetModuleHandle(mk_win_base_types_strac_t);
mk_extern_c mk_win_base_keywords_dll_import mk_win_base_kernel_types_hmodule_t mk_win_base_keywords_calling_convention_api GetModuleHandleA(mk_win_base_types_strac_t);
mk_extern_c mk_win_base_keywords_dll_import mk_win_base_kernel_types_hmodule_t mk_win_base_keywords_calling_convention_api GetModuleHandleW(mk_win_base_types_strwc_t);
mk_extern_c mk_win_base_keywords_dll_import mk_win_base_kernel_types_farproc_t mk_win_base_keywords_calling_convention_api GetProcAddress(mk_win_base_kernel_types_hmodule_t, mk_win_base_types_strac_t);


#endif
