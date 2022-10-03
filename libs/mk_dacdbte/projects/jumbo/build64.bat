..\..\..\..\..\mk_join\projects\vs2022\x64\Release\mk_join.exe mk_dacdbte.c mkdacdbte.c
rc /fo mk_dacdbte_parent.res ..\..\src\mk_dacdbte_parent.rc

cl ^
/W4 ^
/WX ^
/sdl- ^
/O2 ^
/Ob2 ^
/Oi ^
/Oy ^
/GL ^
/D mk_want_jumbo=1 ^
/D NDEBUG ^
/Zc:preprocessor ^
/GF ^
/Gm- ^
/MT ^
/GS- ^
/Gy ^
/Za ^
/Zc:wchar_t- ^
/Zc:forScope ^
/Zc:inline ^
/permissive- ^
/TC ^
mkdacdbte.c ^
/link ^
/OUT:mkdacdbte64.exe ^
/SUBSYSTEM:WINDOWS ^
/OPT:REF ^
/OPT:ICF ^
/LTCG ^
/RELEASE ^
/DYNAMICBASE ^
/NXCOMPAT ^
/MACHINE:X64 ^
mk_dacdbte_parent.res ^
user32.lib ^
comdlg32.lib ^
comctl32.lib
