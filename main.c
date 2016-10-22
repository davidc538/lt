//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>

#include "lt_vector.h"

void myfunc(void* arr_item, void* data)
{
	long long ptr = arr_item;
}

int main(int argc, char** argv)
{
	lt_vector da;
	lt_vector_init(&da);

	for (unsigned int i = 0; i < 256; i++)
		lt_vector_insert(&da, (void*)(i));

	lt_vector_each(&da, myfunc, NULL);

	getchar();
}
