#ifndef mk_include_guard_robin_hood_strw
#define mk_include_guard_robin_hood_strw


#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


struct mk_std_robin_hood_strw_incomming_s
{
	wchar_t const* m_strw;
	size_t m_len;
};
typedef struct mk_std_robin_hood_strw_incomming_s mk_std_robin_hood_strw_incomming_t;


mk_jumbo int mk_std_robin_hood_strw_hash(mk_std_robin_hood_strw_incomming_t const* incomming, size_t* hash);
mk_jumbo int mk_std_robin_hood_strw_move(mk_std_robin_hood_strw_incomming_t const* incomming, wchar_t const** key);
mk_jumbo int mk_std_robin_hood_strw_dstr(wchar_t const* key);
mk_jumbo int mk_std_robin_hood_strw_cmp(mk_std_robin_hood_strw_incomming_t const* incomming, wchar_t const* key);


#define mk_std_robin_hood_t_name strw
#define mk_std_robin_hood_t_keyt wchar_t
#define mk_std_robin_hood_t_ikeyt mk_std_robin_hood_strw_incomming_t
#define mk_std_robin_hood_t_hash mk_std_robin_hood_strw_hash
#define mk_std_robin_hood_t_move mk_std_robin_hood_strw_move
#define mk_std_robin_hood_t_dstr mk_std_robin_hood_strw_dstr
#define mk_std_robin_hood_t_cmp mk_std_robin_hood_strw_cmp
#include "mk_std_robin_hood.inl.h"


#endif
