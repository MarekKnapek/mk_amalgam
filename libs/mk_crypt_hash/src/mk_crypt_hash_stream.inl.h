#include "mk_crypt_hash_bases.h"

#include "../../mk_utils/src/mk_jumbo.h"


#ifndef x
#define x md2
#endif


#define concat_1(a, b) a ## b
#define concat(a, b) concat_1(a, b)

#define base_t concat(concat(mk_crypt_hash_base_, x), _t)
#define block_len concat(concat(mk_crypt_hash_base_, x), _block_len)
#define stream_s concat(concat(mk_crypt_hash_stream_, x), _s)
#define stream_t concat(concat(mk_crypt_hash_stream_, x), _t)
#define stream_pt concat(concat(mk_crypt_hash_stream_, x), _pt)
#define stream_pct concat(concat(mk_crypt_hash_stream_, x), _pct)
#define stream_init concat(concat(mk_crypt_hash_stream_, x), _init)
#define stream_append concat(concat(mk_crypt_hash_stream_, x), _append)
#define stream_end_stream concat(concat(mk_crypt_hash_stream_, x), _end_stream)
#define stream_finish concat(concat(mk_crypt_hash_stream_, x), _finish)


struct stream_s
{
	base_t m_base;
	int m_idx;
	unsigned char m_block[block_len];
};
typedef struct stream_s stream_t;
typedef stream_t* stream_pt;
typedef stream_t const* stream_pct;


mk_jumbo void stream_init(stream_pt self);
mk_jumbo void stream_append(stream_pt self, void const* msg, int len);
mk_jumbo void stream_end_stream(stream_pt self);
mk_jumbo void stream_finish(stream_pct self, void* digest);


#undef base_t
#undef block_len
#undef stream_s
#undef stream_t
#undef stream_pt
#undef stream_pct
#undef stream_init
#undef stream_append
#undef stream_end_stream
#undef stream_finish

#undef concat_1
#undef concat
