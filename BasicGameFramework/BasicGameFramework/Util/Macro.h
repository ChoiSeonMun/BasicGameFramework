#pragma once

// ------------------------------------------
// CRASH
// -----------------------------------------

#define CRASH(cause)						\
{											\
	UINT32* crash = nullptr;				\
	__analysis_assume(crash != nullptr);	\
	*crash = 0xDEADBEEF;					\
}

#define ASSERT_CRASH(expr)							\
{													\
	if (!(expr))									\
	{												\
		CRASH("ASSERT_CRASH");						\
		__analysis_assume(expr);					\
	}												\
}