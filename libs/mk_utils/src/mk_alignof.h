#ifndef mk_include_guard_alignof
#define mk_include_guard_alignof


#if defined(__cplusplus) && __cplusplus >= 201103L
#define mk_alignof(x) alignof(x)
#else
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#define mk_alignof(x) _Alignof(x)
#else
#define mk_alignof(x) 8
#endif
#endif


#endif
