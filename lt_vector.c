#include "lt_vector.h"

#include <malloc.h>

lt_vector* lt_vector_new()
{
	lt_vector* vec = malloc(sizeof(lt_vector));

	lt_vector_init(vec);

	return vec;
}

void lt_vector_init(lt_vector* da)
{
	const static int initial_size = 2;

	da->ptr = malloc(sizeof(void*) * initial_size);
	da->cap = initial_size;
	da->size = 0;
}

void lt_vector_free(lt_vector* da)
{
	free(da->ptr);
}

void lt_vector_delete(lt_vector* da)
{
	lt_vector_free(da);
	free(da);
}

void lt_vector_each(lt_vector* da, void (func)(void*, void*), void* data)
{
	for (size_t i = 0; i < da->size; i++)
		func(da->ptr[i], data);
}

// @private
void lt_vector_memcpy(void** new_ptr, void** old_ptr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		new_ptr[i] = old_ptr[i];
}

// @private
void lt_vector_expand(lt_vector* da)
{
	size_t new_cap = da->cap * 2;

	void** new_ptr = malloc(sizeof(void*) * new_cap);

	lt_vector_memcpy(new_ptr, da->ptr, da->cap);

	free(da->ptr);

	da->ptr = new_ptr;
	da->cap = new_cap;
}

void lt_vector_insert(lt_vector* da, void* data)
{
	if (da->size >= da->cap)
		lt_vector_expand(da);

	da->ptr[da->size++] = data;
}

size_t lt_vector_size(lt_vector* da)
{
	return da->size;
}

size_t lt_vector_capacity(lt_vector* da)
{
	return da->cap;
}