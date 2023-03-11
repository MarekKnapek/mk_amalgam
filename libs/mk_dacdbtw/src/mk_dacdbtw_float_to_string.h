#ifndef mk_include_guard_dacdbtw_float_to_string
#define mk_include_guard_dacdbtw_float_to_string


#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo int mk_dacdbtw_float_to_string_get_max_size(void);
mk_jumbo int mk_dacdbtw_float_to_string_get_string(double const* const flt, char* const str, int const str_len);


#endif
