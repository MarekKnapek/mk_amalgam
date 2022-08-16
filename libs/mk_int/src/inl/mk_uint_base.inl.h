#include "../../../mk_utils/src/mk_jumbo.h"

#include <stddef.h> /* size_t */


#define mk_uint_concat_1(a, b) mk_uint_ ## a ## _ ## b
#define mk_uint_concat(a, b) mk_uint_concat_1(a, b)


mk_jumbo void mk_uint_concat(mk_uint_tn, zero)(mk_uint_t* out);
mk_jumbo void mk_uint_concat(mk_uint_tn, one)(mk_uint_t* out);
mk_jumbo void mk_uint_concat(mk_uint_tn, from_int)(mk_uint_t* out, unsigned in);
mk_jumbo unsigned mk_uint_concat(mk_uint_tn, to_int)(mk_uint_t const* x);
mk_jumbo void mk_uint_concat(mk_uint_tn, from_long)(mk_uint_t* out, unsigned long in);
mk_jumbo unsigned long mk_uint_concat(mk_uint_tn, to_long)(mk_uint_t const* x);
mk_jumbo void mk_uint_concat(mk_uint_tn, from_sizet)(mk_uint_t* out, size_t in);
mk_jumbo size_t mk_uint_concat(mk_uint_tn, to_sizet)(mk_uint_t const* x);
mk_jumbo void mk_uint_concat(mk_uint_tn, from_buff_le)(mk_uint_t* out, void const* buff);
mk_jumbo void mk_uint_concat(mk_uint_tn, to_buff_le)(mk_uint_t const* x, void* buff);
mk_jumbo void mk_uint_concat(mk_uint_tn, from_buff_be)(mk_uint_t* out, void const* buff);
mk_jumbo void mk_uint_concat(mk_uint_tn, to_buff_be)(mk_uint_t const* x, void* buff);

mk_jumbo int mk_uint_concat(mk_uint_tn, is_zero)(mk_uint_t const* x);
mk_jumbo int mk_uint_concat(mk_uint_tn, is_max)(mk_uint_t const* x);

mk_jumbo void mk_uint_concat(mk_uint_tn, cmplmnt)(mk_uint_t* out, mk_uint_t const* x);
mk_jumbo void mk_uint_concat(mk_uint_tn, or)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_tn, and)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_tn, xor)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);

mk_jumbo void mk_uint_concat(mk_uint_tn, shl)(mk_uint_t* out, mk_uint_t const* x, int n);
mk_jumbo void mk_uint_concat(mk_uint_tn, shr)(mk_uint_t* out, mk_uint_t const* x, int n);
mk_jumbo void mk_uint_concat(mk_uint_tn, rotl)(mk_uint_t* out, mk_uint_t const* x, int n);
mk_jumbo void mk_uint_concat(mk_uint_tn, rotr)(mk_uint_t* out, mk_uint_t const* x, int n);

mk_jumbo int mk_uint_concat(mk_uint_tn, eq)(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_tn, neq)(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_tn, lt)(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_tn, le)(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_tn, gt)(mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_tn, ge)(mk_uint_t const* a, mk_uint_t const* b);

mk_jumbo void mk_uint_concat(mk_uint_tn, inc)(mk_uint_t* x);
mk_jumbo void mk_uint_concat(mk_uint_tn, dec)(mk_uint_t* x);

mk_jumbo void mk_uint_concat(mk_uint_tn, add)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_tn, sub)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_tn, mul)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_tn, mulhi)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_tn, divmod)(mk_uint_t* div, mk_uint_t* mod, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_tn, div)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_tn, mod)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);


#undef mk_uint_concat_1
#undef mk_uint_concat
