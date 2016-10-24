#include <stdio.h>

#include "lt_vector.h"
#include "lt_list.h"
#include "lt_binary_tree.h"

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

	for (int i = 12; i > 6; i--)
	{
		person* p = malloc(sizeof(person));

		p->age = i;

		lt_list_attach_front(&list, p);

		lt_list_each(&list, my_list_func, NULL);
	}

	printf("starting pop_front\r\n");

	while (lt_list_size(&list) > 0)
	{
		person* p = lt_list_pop_front(&list);

		printf("age: %i\r\n", p->age);

		free(p);
	}

	for (int i = 12; i > 0; i--)
	{
		person* p = malloc(sizeof(person));

		p->age = i;

		lt_list_attach_front(&list, p);
	}

	printf("starting pop_back:\r\n");

	while (lt_list_size(&list) > 0)
	{
		person* p = lt_list_pop_back(&list);

		printf("age: %i\r\n", p->age);

		free(p);
	}

	printf("testing each:\r\n");
	lt_list_each(&list, my_list_func, NULL);
	printf("done.");
}

typedef struct
{
	LT_TREE_HEADER
	int id;
} skoo;

int my_binary_tree_comparator(void* left, void* right)
{
	skoo* l, *r;
	l = left;
	r = right;

	if (l->id < r->id) return -1;
	else if (l->id > r->id) return 1;
	else return 0;
}

void test_lt_binary_tree(void)
{
	lt_binary_tree tree;
	lt_binary_tree_init(&tree, my_binary_tree_comparator);

	int vals[] = {4,2,6,1,3,5,7};

	for (int i = 0; i < 6; i++)
	{
		skoo* s = lt_malloc(sizeof(skoo));
		s->id = vals[i];

		lt_binary_tree_insert(&tree, s);
	}

	//lt_binary_tree_free(&tree);
}

int main(int argc, char** argv)
{
	size_t l = sizeof(long long);

	test_lt_vector();
	test_lt_list();
	test_lt_binary_tree();
	printf("done.");
}
