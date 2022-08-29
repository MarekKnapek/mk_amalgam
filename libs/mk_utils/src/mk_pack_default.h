#ifndef mk_include_guard_pack_default
#define mk_include_guard_pack_default


#if defined(_MSC_VER)
#if _MSC_VER >= 900
#pragma warning(disable:4103) /* warning c4103: alignment changed after including header, may be due to missing #pragma pack(pop) */
#pragma pack(pop)
#else
#pragma pack()
#endif
#endif


#endif
