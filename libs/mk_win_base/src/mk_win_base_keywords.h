#ifndef mk_win_base_keywords
#define mk_win_base_keywords


#include "mk_win_base_platform.h"


#if mk_win_base_platform_os == mk_win_base_platform_os_win16
#define mk_win_base_keywords_near __near
#define mk_win_base_keywords_far __far
#define mk_win_base_keywords_calling_convention_api __pascal __far
#define mk_win_base_keywords_dll_export
#define mk_win_base_keywords_dll_import
#else
#define mk_win_base_keywords_near
#define mk_win_base_keywords_far
#define mk_win_base_keywords_calling_convention_api __stdcall
#define mk_win_base_keywords_dll_export __declspec(dllexport)
#define mk_win_base_keywords_dll_import __declspec(dllimport)
#endif


#endif
