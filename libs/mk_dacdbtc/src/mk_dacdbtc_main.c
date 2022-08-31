#include "../../mk_dacdbt/src/mk_dacdbt_doc.h"

#include "../../mk_std/src/mk_std_input_stream.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_check.h"
#include "../../mk_utils/src/mk_inline.h"
#include "../../mk_utils/src/mk_try.h"

#include <stdio.h>


#ifdef __SANITIZE_ADDRESS__


static mk_inline int llvm_fuzzer_test_one_input_3(mk_dacdbt_doc_t* doc, mk_std_input_stream_t* is)
{
	mk_assert(doc);
	mk_assert(is);

	mk_try(mk_dacdbt_doc_construct_parse(doc, is));

	return 0;
}

static mk_inline int llvm_fuzzer_test_one_input_2(unsigned char const* data, size_t size)
{
	mk_std_input_stream_t is;
	mk_dacdbt_doc_t doc;
	int err;

	mk_try(mk_std_input_stream_construct_buffer(&is, data, size));
	err = llvm_fuzzer_test_one_input_3(&doc, &is); (void)err;
	mk_try(mk_dacdbt_doc_destruct(&doc));
	mk_try(mk_std_input_stream_destruct(&is));

	return 0;
}

extern int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size)
{
	int ret;

	ret = llvm_fuzzer_test_one_input_2(data, size);
	mk_assert(ret == 0);

	return 0;
}


#else


int main(int argc, char** argv)
{
	FILE* file;
	mk_std_input_stream_t is;
	mk_dacdbt_doc_t doc;
	unsigned long keys;
	unsigned long max_values;
	unsigned long max_keys;
	unsigned long values;
	int printed;
	int closed;

	mk_check(argc == 2);
	file = fopen(argv[1], "rb"); mk_check(file);
	mk_try(mk_std_input_stream_construct_file(&is, file));
	mk_try(mk_dacdbt_doc_construct_parse(&doc, &is));
	mk_try(mk_dacdbt_doc_get_count(&doc, &keys, &values));
	mk_try(mk_dacdbt_doc_get_max(&doc, &max_keys, &max_values));
	printed = printf("keys: %lu, values: %lu, max keys: %lu, max values: %lu\n", keys, values, max_keys, max_values);
	mk_try(mk_dacdbt_doc_destruct(&doc));
	mk_try(mk_std_input_stream_destruct(&is));
	closed = fclose(file); mk_check(closed == 0);

	return 0;
}


#endif
