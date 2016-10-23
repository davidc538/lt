#include "lt_lib.h"

void* lt_malloc(size_t size)
{
	return malloc(size);
}

void lt_free(void* ptr)
{
	free(ptr);
}

