#include "mk_dacdbt_doc.h"

#include "mk_dacdbt_io.h"
#include "mk_dacdbt_key.h"

#include "../../mk_std/src/mk_std_input_stream.h"

#include "../../mk_int/src/exact/mk_uint_32.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_jumbo.h"
#include "../../mk_utils/src/mk_try.h"

#include <stddef.h>


static mk_inline int mk_dacdbt_doc_private_hdr_v2_verify(mk_dacdbt_doc_hdr_v2_t const* hdr);


mk_jumbo int mk_dacdbt_doc_construct(mk_dacdbt_doc_t* doc)
{
	mk_assert(sizeof(mk_dacdbt_doc_hdr_v1_t) == 24);
	mk_assert(sizeof(((mk_dacdbt_doc_hdr_v1_t*)(NULL))->m_name) == 13);
	mk_assert(sizeof(((mk_dacdbt_doc_hdr_v1_t*)(NULL))->m_unused) == 11);

	mk_assert(sizeof(mk_dacdbt_doc_hdr_v2_t) == 252);
	mk_assert(sizeof(((mk_dacdbt_doc_hdr_v2_t*)(NULL))->m_date) == 4);
	mk_assert(sizeof(((mk_dacdbt_doc_hdr_v2_t*)(NULL))->m_time) == 4);
	mk_assert(sizeof(((mk_dacdbt_doc_hdr_v2_t*)(NULL))->m_analyst) == 81);
	mk_assert(sizeof(((mk_dacdbt_doc_hdr_v2_t*)(NULL))->m_description) == 81);
	mk_assert(sizeof(((mk_dacdbt_doc_hdr_v2_t*)(NULL))->m_id) == 81);
	mk_assert(sizeof(((mk_dacdbt_doc_hdr_v2_t*)(NULL))->m_checksum) == 1);

	mk_assert(doc);

	mk_try(mk_dacdbt_key_construct(&doc->m_root));

	return 0;
}

mk_jumbo int mk_dacdbt_doc_construct_parse(mk_dacdbt_doc_t* doc, mk_std_input_stream_t* is)
{
	static mk_uint32_t mk_dacdbt_doc_private_magic5 = mk_uint32_c(0x0500a55aul);
	static mk_uint32_t mk_dacdbt_doc_private_magic6 = mk_uint32_c(0x0600a55aul);
	static mk_uint32_t mk_dacdbt_doc_private_magic7 = mk_uint32_c(0x0700a55aul);
	static mk_uint32_t mk_dacdbt_doc_private_magic8 = mk_uint32_c(0x0800a55aul);

	mk_uint32_t magic;

	mk_assert(doc);
	mk_assert(is);

	mk_try(mk_dacdbt_doc_construct(doc));
	mk_try(mk_dacdbt_io_read_u32(is, &magic));
	mk_check
	(
		mk_uint32_eq(&magic, &mk_dacdbt_doc_private_magic5) ||
		mk_uint32_eq(&magic, &mk_dacdbt_doc_private_magic6) ||
		mk_uint32_eq(&magic, &mk_dacdbt_doc_private_magic7) ||
		mk_uint32_eq(&magic, &mk_dacdbt_doc_private_magic8)
	);
	if(mk_uint32_eq(&magic, &mk_dacdbt_doc_private_magic5))
	{
		doc->m_format = 0;
		mk_try(mk_dacdbt_io_read_buff(is, &doc->m_hdr.m_hdr1, sizeof(doc->m_hdr.m_hdr1)));
	}
	else
	{
		doc->m_format = 1;
		mk_try(mk_dacdbt_io_read_buff(is, &doc->m_hdr.m_hdr2, sizeof(doc->m_hdr.m_hdr2)));
		mk_try(mk_dacdbt_doc_private_hdr_v2_verify(&doc->m_hdr.m_hdr2));
	}
	mk_try(mk_dacdbt_key_construct_parse(&doc->m_root, is));

	return 0;
}

mk_jumbo int mk_dacdbt_doc_destruct(mk_dacdbt_doc_t* doc)
{
	mk_assert(doc);

	mk_try(mk_dacdbt_key_destruct(&doc->m_root));

	return 0;
}

mk_jumbo int mk_dacdbt_doc_get_count(mk_dacdbt_doc_t* doc, unsigned long* keys, unsigned long* values)
{
	mk_assert(doc);
	mk_assert(keys);
	mk_assert(values);

	*keys = 1;
	*values = 0;
	mk_try(mk_dacdbt_key_get_count(&doc->m_root, keys, values));

	return 0;
}

mk_jumbo int mk_dacdbt_doc_get_max(mk_dacdbt_doc_t* doc, unsigned long* keys, unsigned long* values)
{
	mk_assert(doc);
	mk_assert(keys);
	mk_assert(values);

	*keys = 1;
	*values = 0;
	mk_try(mk_dacdbt_key_get_max(&doc->m_root, keys, values));

	return 0;
}


static mk_inline int mk_dacdbt_doc_private_hdr_v2_verify(mk_dacdbt_doc_hdr_v2_t const* hdr)
{
	unsigned char sum;
	int i;

	mk_assert(hdr);

	sum = 0;
	for(i = 0; i != (int)(sizeof(*hdr)); ++i)
	{
		sum += ((unsigned char const*)(hdr))[i];
	}
	mk_check(sum == 0);

	return 0;
}
