#include "../../../mk_utils/src/mk_jumbo.h"

#include <stddef.h> /* size_t */


#define mk_uint_concat_1(a, b) mk_uint_ ## a ## _ ## b
#define mk_uint_concat(a, b) mk_uint_concat_1(a, b)


mk_jumbo void mk_uint_concat(mk_uint_base_tn, zero)(mk_uint_base_t* out);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, one)(mk_uint_base_t* out);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, from_int)(mk_uint_base_t* out, unsigned int in);
mk_jumbo unsigned int mk_uint_concat(mk_uint_base_tn, to_int)(mk_uint_base_t const* x);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, from_long)(mk_uint_base_t* out, unsigned long int in);
mk_jumbo unsigned long int mk_uint_concat(mk_uint_base_tn, to_long)(mk_uint_base_t const* x);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, from_sizet)(mk_uint_base_t* out, size_t in);
mk_jumbo size_t mk_uint_concat(mk_uint_base_tn, to_sizet)(mk_uint_base_t const* x);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, from_buff_le)(mk_uint_base_t* out, void const* buff);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, to_buff_le)(mk_uint_base_t const* x, void* buff);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, from_buff_be)(mk_uint_base_t* out, void const* buff);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, to_buff_be)(mk_uint_base_t const* x, void* buff);

mk_jumbo int mk_uint_concat(mk_uint_base_tn, is_zero)(mk_uint_base_t const* x);
mk_jumbo int mk_uint_concat(mk_uint_base_tn, is_max)(mk_uint_base_t const* x);

mk_jumbo void mk_uint_concat(mk_uint_base_tn, cmplmnt)(mk_uint_base_t* out, mk_uint_base_t const* x);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, or)(mk_uint_base_t* out, mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, and)(mk_uint_base_t* out, mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, xor)(mk_uint_base_t* out, mk_uint_base_t const* a, mk_uint_base_t const* b);

mk_jumbo void mk_uint_concat(mk_uint_base_tn, shl)(mk_uint_base_t* out, mk_uint_base_t const* x, int n);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, shr)(mk_uint_base_t* out, mk_uint_base_t const* x, int n);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, rotl)(mk_uint_base_t* out, mk_uint_base_t const* x, int n);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, rotr)(mk_uint_base_t* out, mk_uint_base_t const* x, int n);

mk_jumbo int mk_uint_concat(mk_uint_base_tn, eq)(mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_base_tn, neq)(mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_base_tn, lt)(mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_base_tn, le)(mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_base_tn, gt)(mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo int mk_uint_concat(mk_uint_base_tn, ge)(mk_uint_base_t const* a, mk_uint_base_t const* b);

mk_jumbo void mk_uint_concat(mk_uint_base_tn, inc)(mk_uint_base_t* x);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, dec)(mk_uint_base_t* x);

mk_jumbo void mk_uint_concat(mk_uint_base_tn, add)(mk_uint_base_t* out, mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, sub)(mk_uint_base_t* out, mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, mul)(mk_uint_base_t* out, mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, mulhi)(mk_uint_base_t* out, mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, divmod)(mk_uint_base_t* div, mk_uint_base_t* mod, mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, div)(mk_uint_base_t* out, mk_uint_base_t const* a, mk_uint_base_t const* b);
mk_jumbo void mk_uint_concat(mk_uint_base_tn, mod)(mk_uint_base_t* out, mk_uint_base_t const* a, mk_uint_base_t const* b);


#undef mk_uint_concat_1
#undef mk_uint_concat
