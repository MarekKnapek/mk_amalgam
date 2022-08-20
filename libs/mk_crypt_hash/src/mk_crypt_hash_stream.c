#include "mk_crypt_hash_stream.h"


#define x md2
#include "mk_crypt_hash_stream.inl.c"
#undef x
#define x md4
#include "mk_crypt_hash_stream.inl.c"
#undef x
#define x md5
#include "mk_crypt_hash_stream.inl.c"
#undef x
