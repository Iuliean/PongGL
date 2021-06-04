#pragma once

#ifdef DEBUG
#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) ClearErrors();\
	x;\
	ASSERT(LogErrors(#x, __FILE__, __LINE__))
#elif NDEBUG
#define GLCall(x) x
#endif

void ClearErrors();

bool LogErrors(const char* function, const char* file, int line);