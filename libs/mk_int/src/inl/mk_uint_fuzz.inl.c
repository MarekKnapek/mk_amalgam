#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif

#include "../utils/mk_inline.h"
#if mk_uint_n == 8
#include "../exact/mk_uint_8.h"
#elif mk_uint_n == 16
#include "../exact/mk_uint_16.h"
#elif mk_uint_n == 32
#include "../exact/mk_uint_32.h"
#elif mk_uint_n == 64
#include "../exact/mk_uint_64.h"
#elif mk_uint_n == 128
#include "../exact/mk_uint_128.h"
#endif

#include <limits.h> /* CHAR_BIT */
#include <stddef.h> /* size_t NULL */
#include <stdint.h> /* uintX_t */
#include <stdio.h> /* sprintf */
#include <string.h> /* memcpy memcmp */
#include <wchar.h> /* wchar_t swprintf */


#define mk_uint_concat_(a, b) a ## b
#define mk_uint_concat(a, b) mk_uint_concat_(a, b)
#define mk_uint_func_fuzz(x) mk_uint_concat(mk_uint_concat(mk_uint_concat(mk_uint_fuzz_, mk_uint_n), _), x)
#define mk_uint_func_my(x) mk_uint_concat(mk_uint_concat(mk_uint_concat(mk_uint, mk_uint_n), _), x)
#define mk_uint_type_native mk_uint_concat(mk_uint_concat(uint, mk_uint_n), _t)
#define mk_uint_type_my mk_uint_concat(mk_uint_concat(struct mk_uint, mk_uint_n), _s)


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


#define test(x) do{ if(!(x)){ int volatile* volatile ptr = NULL; *ptr = 0; } }while(0)


static mk_inline void mk_uint_func_fuzz(zero)(void)
{
	mk_uint_type_native br;
	mk_uint_type_my mr;

	br = 0;
	mk_uint_func_my(zero)(&mr);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(one)(void)
{
	mk_uint_type_native br;
	mk_uint_type_my mr;

	br = 1;
	mk_uint_func_my(one)(&mr);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(from_int)(unsigned char const* data)
{
	unsigned int n;
	mk_uint_type_native br;
	mk_uint_type_my mr;
	
	memcpy(&n, data, sizeof(unsigned int));

	br = (mk_uint_type_native)n;
	mk_uint_func_my(from_int)(&mr, n);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(to_int)(unsigned char const* data)
{
	mk_uint_type_native bx;
	unsigned int br;
	mk_uint_type_my mx;
	unsigned int mr;

	memcpy(&bx, data, mk_uint_n / CHAR_BIT);
	br = (unsigned int)bx;

	memcpy(&mx, data, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(to_int)(&mx);

	test(memcmp(&br, &mr, sizeof(unsigned int)) == 0);
}

static mk_inline void mk_uint_func_fuzz(from_long)(unsigned char const* data)
{
	unsigned long int n;
	mk_uint_type_native br;
	mk_uint_type_my mr;
	
	memcpy(&n, data, sizeof(unsigned long int));

	br = (mk_uint_type_native)n;
	mk_uint_func_my(from_long)(&mr, n);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(to_long)(unsigned char const* data)
{
	mk_uint_type_native bx;
	unsigned long int br;
	mk_uint_type_my mx;
	unsigned long int mr;

	memcpy(&bx, data, mk_uint_n / CHAR_BIT);
	br = (unsigned long int)bx;

	memcpy(&mx, data, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(to_long)(&mx);

	test(memcmp(&br, &mr, sizeof(unsigned long int)) == 0);
}

static mk_inline void mk_uint_func_fuzz(from_sizet)(unsigned char const* data)
{
	size_t n;
	mk_uint_type_native br;
	mk_uint_type_my mr;
	
	memcpy(&n, data, sizeof(size_t));

	br = (mk_uint_type_native)n;
	mk_uint_func_my(from_sizet)(&mr, n);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(to_sizet)(unsigned char const* data)
{
	mk_uint_type_native bx;
	size_t br;
	mk_uint_type_my mx;
	size_t mr;

	memcpy(&bx, data, mk_uint_n / CHAR_BIT);
	br = (size_t)bx;

	memcpy(&mx, data, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(to_sizet)(&mx);

	test(memcmp(&br, &mr, sizeof(size_t)) == 0);
}


static mk_inline void mk_uint_func_fuzz(is_zero)(unsigned char const* data)
{
	mk_uint_type_native bx;
	int br;
	mk_uint_type_my mx;
	int mr;

	memcpy(&bx, data, mk_uint_n / CHAR_BIT);
	br = bx == 0;

	memcpy(&mx, data, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(is_zero)(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}

static mk_inline void mk_uint_func_fuzz(is_max)(unsigned char const* data)
{
	mk_uint_type_native bx;
	int br;
	mk_uint_type_my mx;
	int mr;

	memcpy(&bx, data, mk_uint_n / CHAR_BIT);
	br = bx == (mk_uint_type_native)((mk_uint_type_native)0 - (mk_uint_type_native)1);

	memcpy(&mx, data, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(is_max)(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}


static mk_inline void mk_uint_func_fuzz(cmplmnt)(unsigned char const* data)
{
	mk_uint_type_native bx;
	mk_uint_type_native br;
	mk_uint_type_my mx;
	mk_uint_type_my mr;

	memcpy(&bx, data, mk_uint_n / CHAR_BIT);
	br = ~bx;

	memcpy(&mx, data, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(cmplmnt)(&mr, &mx);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(or)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	mk_uint_type_native br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	mk_uint_type_my mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba | bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(or)(&mr, &ma, &mb);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(and)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	mk_uint_type_native br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	mk_uint_type_my mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba & bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(and)(&mr, &ma, &mb);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(xor)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	mk_uint_type_native br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	mk_uint_type_my mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba ^ bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(xor)(&mr, &ma, &mb);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_func_fuzz(shl)(unsigned char const* data)
{
	mk_uint_type_native bx;
	unsigned int bn;
	mk_uint_type_native br;
	mk_uint_type_my mx;
	unsigned int mn;
	mk_uint_type_my mr;

	memcpy(&bx, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bn, data + mk_uint_n / CHAR_BIT, sizeof(bn));
	bn = bn % mk_uint_n;
	br = bx << bn;

	memcpy(&mx, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mn, data + mk_uint_n / CHAR_BIT, sizeof(mn));
	mn = mn % mk_uint_n;
	mk_uint_func_my(shl)(&mr, &mx, mn);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(shr)(unsigned char const* data)
{
	mk_uint_type_native bx;
	unsigned int bn;
	mk_uint_type_native br;
	mk_uint_type_my mx;
	unsigned int mn;
	mk_uint_type_my mr;

	memcpy(&bx, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bn, data + mk_uint_n / CHAR_BIT, sizeof(bn));
	bn = bn % mk_uint_n;
	br = bx >> bn;

	memcpy(&mx, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mn, data + mk_uint_n / CHAR_BIT, sizeof(mn));
	mn = mn % mk_uint_n;
	mk_uint_func_my(shr)(&mr, &mx, mn);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_func_fuzz(eq)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	int br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba == bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(eq)(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_func_fuzz(neq)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	int br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba != bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(neq)(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_func_fuzz(lt)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	int br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba < bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(lt)(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_func_fuzz(le)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	int br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba <= bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(le)(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_func_fuzz(gt)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	int br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba > bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(gt)(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_func_fuzz(ge)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	int br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba >= bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(ge)(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}


static mk_inline void mk_uint_func_fuzz(inc)(unsigned char const* data)
{
	mk_uint_type_native bx;
	mk_uint_type_my mx;

	memcpy(&bx, data, mk_uint_n / CHAR_BIT);
	++bx;

	memcpy(&mx, data, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(inc)(&mx);

	test(memcmp(&mx, &bx, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(dec)(unsigned char const* data)
{
	mk_uint_type_native bx;
	mk_uint_type_my mx;

	memcpy(&bx, data, mk_uint_n / CHAR_BIT);
	--bx;

	memcpy(&mx, data, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(dec)(&mx);

	test(memcmp(&mx, &bx, mk_uint_n / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_func_fuzz(add)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	mk_uint_type_native br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	mk_uint_type_my mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba + bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(add)(&mr, &ma, &mb);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(sub)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	mk_uint_type_native br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	mk_uint_type_my mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba - bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(sub)(&mr, &ma, &mb);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(mul)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	mk_uint_type_native br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	mk_uint_type_my mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = ba * bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(mul)(&mr, &ma, &mb);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(div)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	mk_uint_type_native br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	mk_uint_type_my mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	if(bb == 0) return;
	br = ba / bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(div)(&mr, &ma, &mb);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_func_fuzz(mod)(unsigned char const* data)
{
	mk_uint_type_native ba;
	mk_uint_type_native bb;
	mk_uint_type_native br;
	mk_uint_type_my ma;
	mk_uint_type_my mb;
	mk_uint_type_my mr;

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&bb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	if(bb == 0) return;
	br = ba % bb;

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	memcpy(&mb, data + mk_uint_n / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mk_uint_func_my(mod)(&mr, &ma, &mb);

	test(memcmp(&br, &mr, mk_uint_n / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_func_fuzz(to_string_dec_n)(unsigned char const* data)
{
#if mk_uint_n <= 32
	mk_uint_type_native ba;
	int br;
	char bstr[40];
	mk_uint_type_my ma;
	int mr;
	char mstr[40];

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = sprintf(bstr, "%lu", (unsigned long int)ba);

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(to_string_dec_n)(&ma, mstr, (int)(sizeof(mstr) / sizeof(mstr[0])));

	test(mr == br);
	test(memcmp(mstr, bstr, mr * sizeof(char)) == 0);
#else
	(void)data;
#endif
}

static mk_inline void mk_uint_func_fuzz(to_string_dec_w)(unsigned char const* data)
{
#if mk_uint_n <= 32
	mk_uint_type_native ba;
	int br;
	wchar_t bstr[40];
	mk_uint_type_my ma;
	int mr;
	wchar_t mstr[40];

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = swprintf(bstr, sizeof(bstr), L"%lu", (unsigned long int)ba);

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(to_string_dec_w)(&ma, mstr, (int)(sizeof(mstr) / sizeof(mstr[0])));

	test(mr == br);
	test(memcmp(mstr, bstr, mr * sizeof(wchar_t)) == 0);
#else
	(void)data;
#endif
}

static mk_inline void mk_uint_func_fuzz(to_string_hex_n)(unsigned char const* data)
{
#if mk_uint_n <= 32
	mk_uint_type_native ba;
	int br;
	char bstr[40];
	mk_uint_type_my ma;
	int mr;
	char mstr[40];

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = sprintf(bstr, "%lx", (unsigned long int)ba);

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(to_string_hex_n)(&ma, mstr, (int)(sizeof(mstr) / sizeof(mstr[0])));

	test(mr == br);
	test(memcmp(mstr, bstr, mr * sizeof(char)) == 0);
#else
	(void)data;
#endif
}

static mk_inline void mk_uint_func_fuzz(to_string_hex_w)(unsigned char const* data)
{
#if mk_uint_n <= 32
	mk_uint_type_native ba;
	int br;
	wchar_t bstr[40];
	mk_uint_type_my ma;
	int mr;
	wchar_t mstr[40];

	memcpy(&ba, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	br = swprintf(bstr, sizeof(bstr), L"%lx", (unsigned long int)ba);

	memcpy(&ma, data + 0 / CHAR_BIT, mk_uint_n / CHAR_BIT);
	mr = mk_uint_func_my(to_string_hex_w)(&ma, mstr, (int)(sizeof(mstr) / sizeof(mstr[0])));

	test(mr == br);
	test(memcmp(mstr, bstr, mr * sizeof(wchar_t)) == 0);
#else
	(void)data;
#endif
}


void mk_uint_concat(mk_uint_fuzz_, mk_uint_n)(unsigned char const* data)
{
	mk_uint_func_fuzz(zero)();
	mk_uint_func_fuzz(one)();
	mk_uint_func_fuzz(from_int)(data);
	mk_uint_func_fuzz(to_int)(data);
	mk_uint_func_fuzz(from_long)(data);
	mk_uint_func_fuzz(to_long)(data);
	mk_uint_func_fuzz(from_sizet)(data);
	mk_uint_func_fuzz(to_sizet)(data);

	mk_uint_func_fuzz(is_zero)(data);
	mk_uint_func_fuzz(is_max)(data);

	mk_uint_func_fuzz(cmplmnt)(data);
	mk_uint_func_fuzz(or)(data);
	mk_uint_func_fuzz(and)(data);
	mk_uint_func_fuzz(xor)(data);

	mk_uint_func_fuzz(shl)(data);
	mk_uint_func_fuzz(shr)(data);
	
	mk_uint_func_fuzz(eq)(data);
	mk_uint_func_fuzz(neq)(data);
	mk_uint_func_fuzz(lt)(data);
	mk_uint_func_fuzz(le)(data);
	mk_uint_func_fuzz(gt)(data);
	mk_uint_func_fuzz(ge)(data);

	mk_uint_func_fuzz(inc)(data);
	mk_uint_func_fuzz(dec)(data);

	mk_uint_func_fuzz(add)(data);
	mk_uint_func_fuzz(sub)(data);
	mk_uint_func_fuzz(mul)(data);
	mk_uint_func_fuzz(div)(data);
	mk_uint_func_fuzz(mod)(data);

	mk_uint_func_fuzz(to_string_dec_n)(data);
	mk_uint_func_fuzz(to_string_dec_w)(data);
	mk_uint_func_fuzz(to_string_hex_n)(data);
	mk_uint_func_fuzz(to_string_hex_w)(data);
}


#undef test


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#undef mk_uint_concat_
#undef mk_uint_concat
#undef mk_uint_func_fuzz
#undef mk_uint_func_my
#undef mk_uint_type_native
#undef mk_uint_type_my


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
