#ifndef LT_VECTOR_H
#define LT_VECTOR_H

#include "lt_lib.h"

typedef struct
{
	void** ptr; // pointer to actual array
	size_t cap; // capacity of actual array
	size_t size; // number of items in actual array
} lt_vector;

lt_vector* lt_vector_new();
void lt_vector_init(lt_vector* da);
void lt_vector_free(lt_vector* da);
void lt_vector_delete(lt_vector* da);

void lt_vector_each(lt_vector* da, void (func)(void*, void*), void* data);
void lt_vector_expand(lt_vector* da, size_t factor);
void lt_vector_insert(lt_vector* da, void* data);
void* lt_vector_random_access(lt_vector* da, size_t index);
void lt_vector_random_access_set(lt_vector* da, size_t index, void* to_set);
void* lt_vector_binary_search(lt_vector* da, int (comparator)(void*, void*), void* to_find);
void lt_vector_bubble_sort_range(lt_vector* da, int (comparator)(void*, void*), size_t start, size_t end);
void lt_vector_bubble_sort(lt_vector* da, int (comparator)(void*, void*));

size_t lt_vector_size(lt_vector* da);
size_t lt_vector_capacity(lt_vector* da);

#endif // LT_VECTOR_H
