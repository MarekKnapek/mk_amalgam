#ifndef mk_include_guard_concat
#define mk_include_guard_concat


#define mk_concat_impl(a, b) a ## b
#define mk_concat(a, b) mk_concat_impl(a, b)


#endif
