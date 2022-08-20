#ifndef mk_include_guard_crypt_hash_stream_pointer
#define mk_include_guard_crypt_hash_stream_pointer


#include "mk_crypt_hash_base_type.h"

#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo void mk_crypt_hash_stream_pointer_init(mk_crypt_hash_base_type_t type, void* self);
mk_jumbo void mk_crypt_hash_stream_pointer_append(mk_crypt_hash_base_type_t type, void* self, void const* msg, int len);
mk_jumbo void mk_crypt_hash_stream_pointer_end_stream(mk_crypt_hash_base_type_t type, void* self);
mk_jumbo void mk_crypt_hash_stream_pointer_finish(mk_crypt_hash_base_type_t type, void const* self, void* digest);


#endif
