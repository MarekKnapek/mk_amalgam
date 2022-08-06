#define mk_uint_concat_(a, b) a ## b
#define mk_uint_concat(a, b) mk_uint_concat_(a, b)


void mk_uint_concat(mk_uint_fuzz_, mk_uint_n)(unsigned char const* data);


#undef mk_uint_concat_
#undef mk_uint_concat
