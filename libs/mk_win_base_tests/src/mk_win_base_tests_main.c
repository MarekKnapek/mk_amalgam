#include "mk_win_base_tests_all.h"

#include "../../mk_utils/src/mk_try.h"

#include <stdlib.h>


int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	mk_try(mk_win_base_tests_all());

	return EXIT_SUCCESS;
}
