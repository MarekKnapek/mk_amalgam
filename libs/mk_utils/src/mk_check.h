#ifndef mk_include_guard_utils_check
#define mk_include_guard_utils_check


#include "mk_break_point.h"


#ifdef NDEBUG
#define mk_check(x) do{ if(!(x)){ mk_break_point(); return 1; } }while(0)
#else
#define mk_check(x) do{ if(!(x)){ mk_break_point(); return (int)__LINE__; } }while(0)
#endif


#endif
