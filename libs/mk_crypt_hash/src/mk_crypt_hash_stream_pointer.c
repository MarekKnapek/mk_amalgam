#include "mk_crypt_hash_stream_pointer.h"

#include "mk_crypt_hash_base_type.h"
#include "mk_crypt_hash_stream.h"
#include "mk_crypt_hash_xmacro.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_jumbo.h"


mk_jumbo void mk_crypt_hash_stream_pointer_init(mk_crypt_hash_base_type_t type, void* self)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));
	mk_assert(self);

	switch(type)
	{
		#define xmacro(x) case mk_concat(mk_crypt_hash_base_type_e_, x): mk_concat(mk_concat(mk_crypt_hash_stream_, x), _init)((mk_concat(mk_concat(mk_crypt_hash_stream_, x), _pt))self); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
}

mk_jumbo void mk_crypt_hash_stream_pointer_append(mk_crypt_hash_base_type_t type, void* self, void const* msg, int len)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));
	mk_assert(self);

	switch(type)
	{
		#define xmacro(x) case mk_concat(mk_crypt_hash_base_type_e_, x): mk_concat(mk_concat(mk_crypt_hash_stream_, x), _append)((mk_concat(mk_concat(mk_crypt_hash_stream_, x), _pt))self, msg, len); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
}

mk_jumbo void mk_crypt_hash_stream_pointer_end_stream(mk_crypt_hash_base_type_t type, void* self)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));
	mk_assert(self);

	switch(type)
	{
		#define xmacro(x) case mk_concat(mk_crypt_hash_base_type_e_, x): mk_concat(mk_concat(mk_crypt_hash_stream_, x), _end_stream)((mk_concat(mk_concat(mk_crypt_hash_stream_, x), _pt))self); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
}

mk_jumbo void mk_crypt_hash_stream_pointer_finish(mk_crypt_hash_base_type_t type, void const* self, void* digest)
{
	mk_assert(mk_crypt_hash_base_type_is_good(type));
	mk_assert(self);

	switch(type)
	{
		#define xmacro(x) case mk_concat(mk_crypt_hash_base_type_e_, x): mk_concat(mk_concat(mk_crypt_hash_stream_, x), _finish)((mk_concat(mk_concat(mk_crypt_hash_stream_, x), _pt))self, digest); break;
		mk_crypt_hash_xinvoke
		#undef xmacro
	}
}
