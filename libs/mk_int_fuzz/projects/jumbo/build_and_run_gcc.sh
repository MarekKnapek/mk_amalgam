#!/bin/bash

set -e

echo "compiling"
time gcc -O3 -Wall -Wextra -Wpedantic -DNDEBUG -Dmk_want_jumbo=1 -Dmk_generate_main -o mk_int_fuzz_gcc.exe mk_int_fuzz.c

echo "striping"
time strip -g --strip-unneeded mk_int_fuzz_gcc.exe

echo "running"
time ./mk_int_fuzz_gcc

echo "done"
