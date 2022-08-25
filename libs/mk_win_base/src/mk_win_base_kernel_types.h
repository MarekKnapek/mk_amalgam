#ifndef mk_win_base_kernel_types
#define mk_win_base_kernel_types


#include "mk_win_base_keywords.h"


struct mk_win_base_kernel_types_hmodule_s; typedef struct mk_win_base_kernel_types_hmodule_s const mk_win_base_keywords_near* mk_win_base_kernel_types_hmodule_t;
struct mk_win_base_kernel_types_hglobal_s; typedef struct mk_win_base_kernel_types_hglobal_s const mk_win_base_keywords_near* mk_win_base_kernel_types_hglobal_t;
struct mk_win_base_kernel_types_hrsrc_s; typedef struct mk_win_base_kernel_types_hrsrc_s const mk_win_base_keywords_near* mk_win_base_kernel_types_hrsrc_t;

typedef int(mk_win_base_keywords_calling_convention_api*mk_win_base_kernel_types_farproc_t)(int);


#endif
