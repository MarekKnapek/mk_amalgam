#include "mk_std_gcallocator.h"
#include "mk_std_size_max.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_clobber.h"
#include "../../mk_utils/src/mk_concat.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <limits.h>
#include <stddef.h>
#include <string.h>


#define mk_std_log2_1(x) (((x) >= (1 << 1)) ? 1 : 0)
#define mk_std_log2_2(x) (((x) >= (1 << 2)) ? (2 + mk_std_log2_1((x) >> 2)) : mk_std_log2_1(x))
#define mk_std_log2_4(x) (((x) >= (1 << 4)) ? (4 + mk_std_log2_2((x) >> 4)) : mk_std_log2_2(x))
#define mk_std_log2_8(x) (((x) >= (1 << 8)) ? (8 + mk_std_log2_4((x) >> 8)) : mk_std_log2_4(x))
#define mk_std_log2(x) (((x) >= (1 << 16)) ? (16 + mk_std_log2_8((x) >> 16)) : mk_std_log2_8(x))


#define mk_std_robin_hood_t_s mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _s)
#define mk_std_robin_hood_t_t mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _t)
#define mk_std_robin_hood_t_element_s mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _element_s)
#define mk_std_robin_hood_t_element_t mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _element_t)
#define mk_std_robin_hood_t_init mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _init)
#define mk_std_robin_hood_t_deinit mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _deinit)
#define mk_std_robin_hood_t_construct mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _construct)
#define mk_std_robin_hood_t_destruct mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _destruct)
#define mk_std_robin_hood_t_private_destruct_elements mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _private_destruct_elements)
#define mk_std_robin_hood_t_private_destruct_self mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _private_destruct_self)
#define mk_std_robin_hood_t_private_grow mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _private_grow)
#define mk_std_robin_hood_t_private_insert mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _private_insert)
#define mk_std_robin_hood_t_insert mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _insert)
#define mk_std_robin_hood_t_private_insert_hashed mk_concat(mk_concat(mk_std_robin_hood_, mk_std_robin_hood_t_name), _private_insert_hashed)


mk_jumbo int mk_std_robin_hood_t_private_destruct_elements(mk_std_robin_hood_t_t* rh);
mk_jumbo int mk_std_robin_hood_t_private_destruct_self(mk_std_robin_hood_t_t* rh);
mk_jumbo int mk_std_robin_hood_t_private_insert_hashed(mk_std_robin_hood_t_t* rh, size_t hash, mk_std_robin_hood_t_keyt const* key);


struct mk_std_robin_hood_t_element_s
{
	size_t m_hash_dist;
	mk_std_robin_hood_t_keyt const* m_key;
};
typedef struct mk_std_robin_hood_t_element_s mk_std_robin_hood_t_element_t;


mk_jumbo int mk_std_robin_hood_t_init(void)
{
	return 0;
}

mk_jumbo int mk_std_robin_hood_t_deinit(void)
{
	return 0;
}

mk_jumbo int mk_std_robin_hood_t_construct(mk_std_robin_hood_t_t* rh)
{
	mk_assert(rh);

	rh->m_buffer = NULL;
	rh->m_capacity = 0;

	return 0;
}

mk_jumbo int mk_std_robin_hood_t_destruct(mk_std_robin_hood_t_t* rh)
{
	mk_assert(rh);

	mk_try(mk_std_robin_hood_t_private_destruct_elements(rh));
	mk_try(mk_std_robin_hood_t_private_destruct_self(rh));

	return 0;
}

mk_jumbo int mk_std_robin_hood_t_private_destruct_elements(mk_std_robin_hood_t_t* rh)
{
	size_t capacity;
	mk_std_robin_hood_t_element_t* elements;
	size_t i;
	mk_std_robin_hood_t_element_t* element;

	mk_assert(rh);

	capacity = rh->m_capacity;
	elements = ((mk_std_robin_hood_t_element_t*)(rh->m_buffer));
	element = elements;
	for(i = 0; i != capacity; ++i, ++element)
	{
		if(element->m_hash_dist != 0)
		{
			mk_std_robin_hood_t_dstr(element->m_key);
		}
	}

	return 0;
}

mk_jumbo int mk_std_robin_hood_t_private_destruct_self(mk_std_robin_hood_t_t* rh)
{
	mk_assert(rh);

	mk_try(mk_std_gcallocator_deallocate(rh->m_buffer));

	return 0;
}

mk_jumbo int mk_std_robin_hood_t_private_grow(mk_std_robin_hood_t_t* rh)
{
	mk_std_robin_hood_t_t newrh;
	size_t memsize;
	size_t i;
	mk_std_robin_hood_t_element_t const* element;

	mk_assert(rh);

	newrh.m_capacity = rh->m_capacity;
	if(newrh.m_capacity == 0)
	{
		newrh.m_capacity = ((size_t)(((size_t)(1)) << mk_std_log2(sizeof(size_t) * CHAR_BIT)));
	}
	else
	{
		mk_assert(newrh.m_capacity <= mk_std_size_max / 2);
		newrh.m_capacity <<= 1;
	}
	mk_assert(newrh.m_capacity <= mk_std_size_max / sizeof(mk_std_robin_hood_t_element_t));
	memsize = newrh.m_capacity * sizeof(mk_std_robin_hood_t_element_t);
	mk_try(mk_std_gcallocator_allocate(memsize, &newrh.m_buffer));
	memset(newrh.m_buffer, 0x00, memsize);
	element = (mk_std_robin_hood_t_element_t const*)(rh->m_buffer);
	for(i = 0; i != rh->m_capacity; ++i, ++element)
	{
		if(element->m_hash_dist != 0)
		{
			mk_try(mk_std_robin_hood_t_private_insert_hashed(&newrh, element->m_hash_dist, element->m_key));
		}
	}
	mk_std_robin_hood_t_private_destruct_self(rh);
	*rh = newrh;

	return 0;
}

mk_jumbo int mk_std_robin_hood_t_private_insert(mk_std_robin_hood_t_t* rh, mk_std_robin_hood_t_ikeyt const* incomming, mk_std_robin_hood_t_keyt const** inserted, size_t existing_hash, mk_std_robin_hood_t_keyt const* existing_key)
{
	#define s_dist_vals ((size_t)(sizeof(size_t) * CHAR_BIT))
	#define s_shift_amount ((int)(((int)(s_dist_vals)) - ((int)(mk_std_log2(s_dist_vals)))))
	#define s_dist_mask ((size_t)(((size_t)(s_dist_vals - 1)) << s_shift_amount))
	#define s_hash_mask ((size_t)(~s_dist_mask))

	size_t hash;
	size_t hash2;
	mk_std_robin_hood_t_keyt const* key2;
	int dist;
	size_t bucket_idx;
	mk_std_robin_hood_t_element_t* elements;
	int i;
	mk_std_robin_hood_t_element_t* element;
	mk_std_robin_hood_t_keyt const* key;
	int dist3;
	size_t hash3;
	mk_std_robin_hood_t_keyt const* key3;
	int grow;

	mk_assert(rh);

	if(rh->m_capacity == 0)
	{
		mk_std_robin_hood_t_private_grow(rh);
	}
	if(existing_hash == 0)
	{
		mk_assert(incomming);
		mk_try(mk_std_robin_hood_t_hash(incomming, &hash));
		if((hash & s_hash_mask) == 0)
		{
			hash += s_dist_vals;
		}
		hash &= s_hash_mask;
		hash2 = 0;
		mk_clobber(&key2);
	}
	else
	{
		hash2 = existing_hash;
		key2 = existing_key;
		mk_clobber(&hash);
	}
	do
	{
		dist = 0;
		bucket_idx = (hash2 == 0 ? hash : hash2) & (rh->m_capacity - 1);
		elements = ((mk_std_robin_hood_t_element_t*)(rh->m_buffer));
		for(i = 0; i != ((int)(s_dist_vals)); ++i)
		{
			element = &elements[bucket_idx];
			if(element->m_hash_dist == 0)
			{
				if(hash2 == 0)
				{
					mk_std_robin_hood_t_move(incomming, &key);
					mk_assert(dist < s_dist_vals);
					element->m_hash_dist = ((size_t)(hash | ((size_t)(((size_t)(dist)) << s_shift_amount))));
					element->m_key = key;
					mk_assert(inserted);
					*inserted = key;
				}
				else
				{
					mk_assert(dist < s_dist_vals);
					element->m_hash_dist = ((size_t)(hash2 | ((size_t)(((size_t)(dist)) << s_shift_amount))));
					element->m_key = key2;
				}
				break;
			}
			else if(((int)(element->m_hash_dist >> s_shift_amount)) < dist)
			{
				if(hash2 == 0)
				{
					dist3 = ((int)(element->m_hash_dist >> s_shift_amount));
					hash2 = ((size_t)(element->m_hash_dist & s_hash_mask));
					key2 = element->m_key;
					mk_std_robin_hood_t_move(incomming, &key);
					mk_assert(dist < s_dist_vals);
					element->m_hash_dist = ((size_t)(hash | ((size_t)(((size_t)(dist)) << s_shift_amount))));
					element->m_key = key;
					mk_assert(inserted);
					*inserted = key;
					dist = dist3;
				}
				else
				{
					dist3 = ((int)(element->m_hash_dist >> s_shift_amount));
					hash3 = ((size_t)(element->m_hash_dist & s_hash_mask));
					key3 = element->m_key;
					mk_assert(dist < s_dist_vals);
					element->m_hash_dist = ((size_t)(hash2 | ((size_t)(((size_t)(dist)) << s_shift_amount))));
					element->m_key = key2;
					hash2 = hash3;
					key2 = key3;
					dist = dist3;
				}
			}
			else if(hash2 == 0 && mk_std_robin_hood_t_cmp(incomming, element->m_key) != 0)
			{
				mk_assert(inserted);
				*inserted = element->m_key;
				break;
			}
			bucket_idx = (bucket_idx + 1) & (rh->m_capacity - 1);
			++dist;
		}
		grow = i == ((int)(s_dist_vals));
		if(grow)
		{
			mk_try(mk_std_robin_hood_t_private_grow(rh));
		}
	}while(grow);

	return 0;

	#undef s_dist_vals
	#undef s_shift_amount
	#undef s_dist_mask
	#undef s_hash_mask
}

mk_jumbo int mk_std_robin_hood_t_insert(mk_std_robin_hood_t_t* rh, mk_std_robin_hood_t_ikeyt const* incomming, mk_std_robin_hood_t_keyt const** inserted)
{
	return mk_std_robin_hood_t_private_insert(rh, incomming, inserted, 0, NULL);
}

mk_jumbo int mk_std_robin_hood_t_private_insert_hashed(mk_std_robin_hood_t_t* rh, size_t hash, mk_std_robin_hood_t_keyt const* key)
{
	return mk_std_robin_hood_t_private_insert(rh, NULL, NULL, hash, key);
}

mk_jumbo int mk_std_robin_hood_t_find(mk_std_robin_hood_t_t const* rh, mk_std_robin_hood_t_ikeyt const* incomming, mk_std_robin_hood_t_keyt const** found)
{
	#define s_dist_vals ((size_t)(sizeof(size_t) * CHAR_BIT))
	#define s_shift_amount ((int)(((int)(s_dist_vals)) - ((int)(mk_std_log2(s_dist_vals)))))
	#define s_dist_mask ((size_t)(((size_t)(s_dist_vals - 1)) << s_shift_amount))
	#define s_hash_mask ((size_t)(~s_dist_mask))

	size_t hash;
	size_t bucket_idx;
	mk_std_robin_hood_t_element_t const* elements;
	int i;
	mk_std_robin_hood_t_element_t const* element;

	mk_assert(rh);
	mk_assert(incomming);
	mk_assert(found);

	mk_try(mk_std_robin_hood_t_hash(incomming, &hash));
	if((hash & s_hash_mask) == 0)
	{
		hash += s_dist_vals;
	}
	hash &= s_hash_mask;
	bucket_idx = hash & (rh->m_capacity - 1);
	elements = ((mk_std_robin_hood_t_element_t const*)(rh->m_buffer));
	for(i = 0; i != ((int)(s_dist_vals)); ++i)
	{
		element = &elements[bucket_idx];
		if(((element->m_hash_dist) & s_hash_mask) == hash)
		{
			if(mk_std_robin_hood_t_cmp(incomming, element->m_key) != 0)
			{
				*found = element->m_key;
				break;
			}
		}
		else
		{
			if(((int)(element->m_hash_dist >> s_shift_amount)) < i)
			{
				*found = NULL;
				break;
			}
		}
		bucket_idx = (bucket_idx + 1) & (rh->m_capacity - 1);
	}
	if(i == ((int)(s_dist_vals)))
	{
		*found = NULL;
	}

	return 0;

	#undef s_dist_vals
	#undef s_shift_amount
	#undef s_dist_mask
	#undef s_hash_mask
}


#undef mk_std_robin_hood_t_s
#undef mk_std_robin_hood_t_t
#undef mk_std_robin_hood_t_element_s
#undef mk_std_robin_hood_t_element_t
#undef mk_std_robin_hood_t_init
#undef mk_std_robin_hood_t_deinit
#undef mk_std_robin_hood_t_construct
#undef mk_std_robin_hood_t_destruct
#undef mk_std_robin_hood_t_private_destruct_elements
#undef mk_std_robin_hood_t_private_destruct_self
#undef mk_std_robin_hood_t_private_grow
#undef mk_std_robin_hood_t_private_insert
#undef mk_std_robin_hood_t_insert
#undef mk_std_robin_hood_t_insert_hashed

#undef mk_std_log2_1
#undef mk_std_log2_2
#undef mk_std_log2_4
#undef mk_std_log2_8
#undef mk_std_log2

#undef mk_std_robin_hood_t_name
#undef mk_std_robin_hood_t_keyt
#undef mk_std_robin_hood_t_ikeyt
#undef mk_std_robin_hood_t_hash
#undef mk_std_robin_hood_t_move
#undef mk_std_robin_hood_t_dstr
#undef mk_std_robin_hood_t_cmp
