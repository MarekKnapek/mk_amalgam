#ifndef mk_include_guard_crypt_hash_xmacro
#define mk_include_guard_crypt_hash_xmacro


#define mk_crypt_hash_xinvoke \
	xmacro(md2) \
	xmacro(md4) \
	xmacro(md5)

#define mk_concat_1(a, b) a ## b
#define mk_concat(a, b) mk_concat_1(a, b)


#endif
