#ifndef mk_include_guard_crypt_hash_stream
#define mk_include_guard_crypt_hash_stream


#define x md2
#include "mk_crypt_hash_stream.inl.h"
#undef x
#define x md4
#include "mk_crypt_hash_stream.inl.h"
#undef x
#define x md5
#include "mk_crypt_hash_stream.inl.h"
#undef x


#endif
