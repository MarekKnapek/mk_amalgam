#ifndef mk_include_guard_utils_try
#define mk_include_guard_utils_try


#include "mk_break_point.h"


#define mk_try(x) do{ int mk_try_err = (x); if(mk_try_err != 0){ mk_break_point(); return mk_try_err; } }while(0)


#endif
