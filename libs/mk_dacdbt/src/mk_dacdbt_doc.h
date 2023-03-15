#ifndef mk_include_guard_dacdbt_doc
#define mk_include_guard_dacdbt_doc


#include "mk_dacdbt_key.h"

#include "../../mk_std/src/mk_std_input_stream.h"

#include "../../mk_int/src/exact/mk_uint_32.h"

#include "../../mk_utils/src/mk_jumbo.h"


struct mk_dacdbt_doc_hdr_v1_s
{
	unsigned char m_name[13];
	unsigned char m_unused[11];
};
typedef struct mk_dacdbt_doc_hdr_v1_s mk_dacdbt_doc_hdr_v1_t;

struct mk_dacdbt_doc_hdr_v2_s
{
	mk_uint32_t m_date;
	mk_uint32_t m_time;
	unsigned char m_analyst[81];
	unsigned char m_description[81];
	unsigned char m_id[81];
	unsigned char m_checksum;
};
typedef struct mk_dacdbt_doc_hdr_v2_s mk_dacdbt_doc_hdr_v2_t;

union mk_dacdbt_doc_hdr_vn_e
{
	mk_dacdbt_doc_hdr_v1_t m_hdr1;
	mk_dacdbt_doc_hdr_v2_t m_hdr2;
};
typedef union mk_dacdbt_doc_hdr_vn_e mk_dacdbt_doc_hdr_vn_t;


struct mk_dacdbt_doc_s
{
	int m_format;
	mk_dacdbt_doc_hdr_vn_t m_hdr;
	mk_dacdbt_key_t m_root;
};
typedef struct mk_dacdbt_doc_s mk_dacdbt_doc_t;


mk_jumbo int mk_dacdbt_doc_construct(mk_dacdbt_doc_t* doc);
mk_jumbo int mk_dacdbt_doc_construct_parse(mk_dacdbt_doc_t* doc, mk_std_input_stream_t* is);
mk_jumbo int mk_dacdbt_doc_destruct(mk_dacdbt_doc_t* doc);
mk_jumbo int mk_dacdbt_doc_get_count(mk_dacdbt_doc_t* doc, unsigned long* keys, unsigned long* values);
mk_jumbo int mk_dacdbt_doc_get_max(mk_dacdbt_doc_t* doc, unsigned long* keys, unsigned long* values);


#endif
