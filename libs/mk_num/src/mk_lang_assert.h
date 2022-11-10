#ifndef mk_detail_include_guard_lang_assert
#define mk_detail_include_guard_lang_assert


#if defined(NDEBUG)


#if defined(_MSC_VER) && _MSC_VER >= 1200 /* VS 6 */
#define mk_lang_assert(x) __assume(x)
#elif defined (__GNUC__) && defined(__GNUC_MINOR__) && (__GNUC__ * 10000l + __GNUC_MINOR__) >= 40005l
#define mk_lang_assert(x) do{ if(!(x)){ __builtin_unreachable(); } }while(0)
#else
#define mk_lang_assert(x) ((void)(0))
#endif


#else


#if defined(__cplusplus)
#include <cassert> /* assert */
#else
#include <assert.h> /* assert */
#endif


#define mk_lang_assert assert


#endif


#endif
