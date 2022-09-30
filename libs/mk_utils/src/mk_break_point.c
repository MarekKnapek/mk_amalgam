#include "mk_break_point.h"

#include "mk_jumbo.h"


#ifdef NDEBUG
#else
/* TODO 1900 (VS2015) has it, 1200 (VS6) doesn't has it, don't know in between */
#if defined(_MSC_VER) && _MSC_VER >= 1900
#pragma warning(push)
#pragma warning(disable:4019) /* warning C4019: empty statement at global scope */
#include <intrin.h>
#pragma warning(pop)
#endif
#endif


mk_jumbo void mk_break_point(void)
{
	#ifdef NDEBUG
	#else
	/* TODO 1900 (VS2015) has it, 1200 (VS6) doesn't has it, don't know in between */
	#if defined(_MSC_VER) && _MSC_VER >= 1900
	/*__debugbreak();*/
	#endif
	#endif
}
