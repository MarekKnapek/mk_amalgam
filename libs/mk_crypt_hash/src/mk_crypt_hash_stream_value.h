#ifndef mk_include_guard_crypt_hash_stream_value
#define mk_include_guard_crypt_hash_stream_value


#include "mk_crypt_hash_base_type.h"
#include "mk_crypt_hash_stream.h"
#include "mk_crypt_hash_xmacro.h"

#include "../../mk_utils/src/mk_jumbo.h"


union mk_crypt_hash_stream_value_u
{
	#define xmacro(x) mk_concat(mk_concat(mk_crypt_hash_stream_, x), _t) mk_concat(m_, x);
	mk_crypt_hash_xinvoke
	#undef xmacro
};
typedef union mk_crypt_hash_stream_value_u mk_crypt_hash_stream_value_t;
typedef mk_crypt_hash_stream_value_t* mk_crypt_hash_stream_value_pt;
typedef mk_crypt_hash_stream_value_t const* mk_crypt_hash_stream_value_pct;

struct mk_crypt_hash_stream_value_tag_s
{
	mk_crypt_hash_base_type_t m_type;
	mk_crypt_hash_stream_value_t m_value;
};
typedef struct mk_crypt_hash_stream_value_tag_s mk_crypt_hash_stream_value_tag_t;
typedef mk_crypt_hash_stream_value_tag_t* mk_crypt_hash_stream_value_tag_pt;
typedef mk_crypt_hash_stream_value_tag_t const* mk_crypt_hash_stream_value_tag_pct;


mk_jumbo void mk_crypt_hash_stream_value_init(mk_crypt_hash_base_type_t type, mk_crypt_hash_stream_value_pt self);
mk_jumbo void mk_crypt_hash_stream_value_append(mk_crypt_hash_base_type_t type, mk_crypt_hash_stream_value_pt self, void const* msg, int len);
mk_jumbo void mk_crypt_hash_stream_value_end_stream(mk_crypt_hash_base_type_t type, mk_crypt_hash_stream_value_pt self);
mk_jumbo void mk_crypt_hash_stream_value_finish(mk_crypt_hash_base_type_t type, mk_crypt_hash_stream_value_pct self, void* digest);

mk_jumbo void mk_crypt_hash_stream_value_tag_init(mk_crypt_hash_stream_value_tag_pt self, mk_crypt_hash_base_type_t type);
mk_jumbo void mk_crypt_hash_stream_value_tag_append(mk_crypt_hash_stream_value_tag_pt self, void const* msg, int len);
mk_jumbo void mk_crypt_hash_stream_value_tag_end_stream(mk_crypt_hash_stream_value_tag_pt self);
mk_jumbo void mk_crypt_hash_stream_value_tag_finish(mk_crypt_hash_stream_value_tag_pct self, void* digest);


#endif
