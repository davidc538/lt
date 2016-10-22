#ifndef LT_VECTOR_H
#define LT_VECTOR_H

#include <malloc.h>

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
void lt_vector_expand(lt_vector* da, size_t new_cap);
void lt_vector_insert(lt_vector* da, void* data);
void* lt_vector_random_access(lt_vector* da, size_t index);
void* lt_vector_binary_search(lt_vector* da, int (comparator)(void*, void*), void* to_find);

size_t lt_vector_size(lt_vector* da);
size_t lt_vector_capacity(lt_vector* da);

#endif // LT_VECTOR_H
