#ifndef mk_win_base_kernel_types
#define mk_win_base_kernel_types


#include "mk_win_base_keywords.h"
#include "mk_win_base_types.h"


mk_win_base_types_make_handle(mk_win_base_kernel_types_hmodule_t);
mk_win_base_types_make_handle(mk_win_base_kernel_types_hglobal_t);
mk_win_base_types_make_handle(mk_win_base_kernel_types_hrsrc_t);

typedef int(mk_win_base_keywords_calling_convention_api*mk_win_base_kernel_types_farproc_t)(int);


#endif
