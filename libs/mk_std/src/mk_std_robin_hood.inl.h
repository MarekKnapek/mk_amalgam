#include "../../mk_utils/src/mk_concat.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


#define mk_std_robin_hood_t_s mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _s)
#define mk_std_robin_hood_t_t mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _t)
#define mk_std_robin_hood_t_max_size mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _max_size)
#define mk_std_robin_hood_t_init mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _init)
#define mk_std_robin_hood_t_deinit mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _deinit)
#define mk_std_robin_hood_t_construct mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _construct)
#define mk_std_robin_hood_t_destruct mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _destruct)
#define mk_std_robin_hood_t_insert mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _insert)
#define mk_std_robin_hood_t_find mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _find)


struct mk_std_robin_hood_t_s
{
	void* m_buffer;
	size_t m_capacity;
};
typedef struct mk_std_robin_hood_t_s mk_std_robin_hood_t_t;


/*#define mk_std_robin_hood_t_max_size() (1ul << 27)*//*16-4=12=4096, 32-5=27=134217728, 64-6=58=288230376151711744*/


mk_jumbo int mk_std_robin_hood_t_init(void);
mk_jumbo int mk_std_robin_hood_t_deinit(void);
mk_jumbo int mk_std_robin_hood_t_construct(mk_std_robin_hood_t_t* rh);
mk_jumbo int mk_std_robin_hood_t_destruct(mk_std_robin_hood_t_t* rh);
mk_jumbo int mk_std_robin_hood_t_insert(mk_std_robin_hood_t_t* rh, mk_std_robin_hood_t_ikeyt const* incomming, mk_std_robin_hood_t_keyt const** inserted);
mk_jumbo int mk_std_robin_hood_t_find(mk_std_robin_hood_t_t const* rh, mk_std_robin_hood_t_ikeyt const* incomming, mk_std_robin_hood_t_keyt const** found);


#undef mk_std_robin_hood_t_s
#undef mk_std_robin_hood_t_t
#undef mk_std_robin_hood_t_max_size
#undef mk_std_robin_hood_t_init
#undef mk_std_robin_hood_t_deinit
#undef mk_std_robin_hood_t_construct
#undef mk_std_robin_hood_t_destruct
#undef mk_std_robin_hood_t_insert

#undef mk_std_robin_hood_t_name
#undef mk_std_robin_hood_t_keyt
#undef mk_std_robin_hood_t_ikeyt
#undef mk_std_robin_hood_t_hash
#undef mk_std_robin_hood_t_move
#undef mk_std_robin_hood_t_dstr
#undef mk_std_robin_hood_t_cmp
