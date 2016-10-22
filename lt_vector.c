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

void lt_vector_expand(lt_vector* da, size_t factor)
{
	size_t new_cap = da->cap * factor;

	void** new_ptr = malloc(sizeof(void*) * new_cap);

	lt_vector_memcpy(new_ptr, da->ptr, da->cap);

	free(da->ptr);

	da->ptr = new_ptr;
	da->cap = new_cap;
}

void lt_vector_insert(lt_vector* da, void* data)
{
	if (da->size >= da->cap)
		lt_vector_expand(da, 2);

	da->ptr[da->size++] = data;
}

void* lt_vector_random_access(lt_vector* da, size_t index)
{
	return da->ptr[index];
}

void lt_vector_random_access_set(lt_vector* da, size_t index, void* to_set)
{
	da->ptr[index] = to_set;
}

void* lt_vector_binary_search(lt_vector* da, int (comparator)(void*, void*), void* to_find)
{
	size_t min, max, mid;
	int result;
	void* current;

	min = 0;
	max = da->size;

	while (min != max)
	{
		mid = (min + max) / 2;

		current = lt_vector_random_access(da, mid);

		result = comparator(current, to_find);

		if (result < 0) min = mid;
		else if (result > 0) max = mid;
		else if (result == 0) return current;
	}

	return NULL;
}

void lt_vector_bubble_sort(lt_vector* da, int (comparator)(void*, void*))
{
	register size_t i, j, size;
	register void* left,* right;
	register int compare;

	size = lt_vector_size(da);

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			left = lt_vector_random_access(da, j);
			right = lt_vector_random_access(da, j + 1);

			compare = comparator(left, right);

			if (compare > 0)
			{
				lt_vector_random_access_set(da, j, right);
				lt_vector_random_access_set(da, j + 1, left);
			}
		}
	}
}

size_t lt_vector_size(lt_vector* da)
{
	return da->size;
}

size_t lt_vector_capacity(lt_vector* da)
{
	return da->cap;
}
