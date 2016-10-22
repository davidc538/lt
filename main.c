#include <stdio.h>
//#include <malloc.h>
//#include <string.h>

#include "lt_vector.h"

void my_func(void* arr_item, void* data)
{
	long long ptr = (long long)arr_item;
}

int my_comparator(void* left, void* right)
{
	long long l, r;

	l = (long long)left;
	r = (long long)right;

	if (l < r) return -1;
	else if  (l > r) return 1;
	else return 0;
}

int main(int argc, char** argv)
{
	void* found;

	lt_vector da;
	lt_vector_init(&da);

	for (unsigned int i = 0; i < 256; i++)
		lt_vector_insert(&da, (void*)(long long)(i));

	found = lt_vector_binary_search(&da, my_comparator, (void*)42);

	printf("found: %I64d", (long long)found);

	lt_vector_each(&da, my_func, NULL);
	lt_vector_free(&da);

	getchar();
}
