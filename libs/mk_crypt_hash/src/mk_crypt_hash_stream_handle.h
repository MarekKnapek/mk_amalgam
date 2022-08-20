#ifndef mk_include_guard_crypt_hash_stream_handle
#define mk_include_guard_crypt_hash_stream_handle


#include "mk_crypt_hash_base_type.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_crypt_hash_stream_handle_s; typedef struct mk_crypt_hash_stream_handle_s mk_crypt_hash_stream_handle_t; typedef mk_crypt_hash_stream_handle_t const* mk_crypt_hash_stream_handle_h;


mk_jumbo void mk_crypt_hash_stream_handle_create(mk_crypt_hash_stream_handle_h* self, mk_crypt_hash_base_type_t type);
mk_jumbo void mk_crypt_hash_stream_handle_init(mk_crypt_hash_stream_handle_h self);
mk_jumbo void mk_crypt_hash_stream_handle_append(mk_crypt_hash_stream_handle_h self, void const* msg, int len);
mk_jumbo void mk_crypt_hash_stream_handle_end_stream(mk_crypt_hash_stream_handle_h self);
mk_jumbo void mk_crypt_hash_stream_handle_finish(mk_crypt_hash_stream_handle_h self, void* digest);
mk_jumbo void mk_crypt_hash_stream_handle_destroy(mk_crypt_hash_stream_handle_h self);


#endif
