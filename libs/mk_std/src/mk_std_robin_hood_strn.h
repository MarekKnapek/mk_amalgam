#ifndef mk_include_guard_robin_hood_strn
#define mk_include_guard_robin_hood_strn


#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


struct mk_std_robin_hood_strn_incomming_s
{
	char const* m_strn;
	size_t m_len;
};
typedef struct mk_std_robin_hood_strn_incomming_s mk_std_robin_hood_strn_incomming_t;


mk_jumbo int mk_std_robin_hood_strn_hash(mk_std_robin_hood_strn_incomming_t const* incomming, size_t* hash);
mk_jumbo int mk_std_robin_hood_strn_move(mk_std_robin_hood_strn_incomming_t const* incomming, char const** key);
mk_jumbo int mk_std_robin_hood_strn_dstr(char const* key);
mk_jumbo int mk_std_robin_hood_strn_cmp(mk_std_robin_hood_strn_incomming_t const* incomming, char const* key);


#define mk_std_robin_hood_t_name strn
#define mk_std_robin_hood_t_keyt char
#define mk_std_robin_hood_t_ikeyt mk_std_robin_hood_strn_incomming_t
#define mk_std_robin_hood_t_hash mk_std_robin_hood_strn_hash
#define mk_std_robin_hood_t_move mk_std_robin_hood_strn_move
#define mk_std_robin_hood_t_dstr mk_std_robin_hood_strn_dstr
#define mk_std_robin_hood_t_cmp mk_std_robin_hood_strn_cmp
#include "mk_std_robin_hood.inl.h"


#endif
