#include <stdio.h>

#include "lt_vector.h"
#include "lt_list.h"

void my_vector_func(void* arr_item, void* data)
{
	long long ptr = (long long)arr_item;

	printf("%I64d\r\n", ptr);
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

void test_lt_vector(void)
{
	void* found;

	lt_vector da;
	lt_vector_init(&da);

	for (unsigned int i = 256; i > 0; i--)
		lt_vector_insert(&da, (void*)(long long)(i));

	lt_vector_bubble_sort(&da, my_comparator);

	found = lt_vector_binary_search(&da, my_comparator, (void*)42);

	printf("found: %I64d\r\n", (long long)found);
	printf("testing each:\r\n");

	lt_vector_each(&da, my_vector_func, NULL);
	lt_vector_free(&da);
}

typedef struct
{
	LT_LIST_HEADER
	int age;
} person;

void my_list_func(void* arr_item, void* data)
{
	person* p = (person*)arr_item;

	printf("%i\r\n", p->age);
}

void test_lt_list(void)
{
	lt_list list;
	lt_list_init(&list);

	printf("testing list:\r\n");

	for (int i = 0; i < 6; i++)
	{
		person* p = malloc(sizeof(person));
		
		p->age = i;
		
		lt_list_attach_back(&list, p);
	}

	printf("testing each:\r\n");
	lt_list_each(&list, my_list_func, NULL);
	printf("done.");
}

int main(int argc, char** argv)
{
	test_lt_vector();
	test_lt_list();
	printf("done.");
}
