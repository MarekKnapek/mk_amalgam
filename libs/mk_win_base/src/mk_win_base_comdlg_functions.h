#ifndef mk_win_base_comdlg_functions
#define mk_win_base_comdlg_functions


#include "mk_win_base_keywords.h"
#include "mk_win_base_types.h"
#include "mk_win_base_user_types.h"
#include "mk_win_base_comdlg_types.h"

#include "../../mk_utils/src/mk_cpp.h"


mk_extern_c mk_win_base_keywords_dll_import mk_win_base_types_bool_t mk_win_base_keywords_calling_convention_api GetOpenFileName(mk_win_base_comdlg_types_open_file_name_v1_a_lpt);
mk_extern_c mk_win_base_keywords_dll_import mk_win_base_types_bool_t mk_win_base_keywords_calling_convention_api GetOpenFileNameA(mk_win_base_comdlg_types_open_file_name_v1_a_lpt);
mk_extern_c mk_win_base_keywords_dll_import mk_win_base_types_bool_t mk_win_base_keywords_calling_convention_api GetOpenFileNameW(mk_win_base_comdlg_types_open_file_name_v1_w_lpt);


#endif
