#define mk_uint_parts ((mk_uint_bits + (mk_uint_small_bits - 1)) / mk_uint_small_bits)


#if mk_uint_parts == 1


#include "mk_uint_1.inl.c"


#elif mk_uint_parts == 2


#include "mk_uint_2.inl.c"


#else


#include "mk_uint_n.inl.c"


#endif


#include "mk_uint_any.inl.c"


#undef mk_uint_parts
