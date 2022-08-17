@echo off

echo compiling
cl /O2 /Ob2 /permissive- /Wall /sdl /GL /GS /D NDEBUG /D mk_want_jumbo=1 /D _CRT_SECURE_NO_WARNINGS /nologo mk_int_fuzz.c /link /OUT:mk_int_fuzz_msvc.exe

echo running
mk_int_fuzz_msvc

echo done
