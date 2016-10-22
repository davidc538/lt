#include "lt_list.h"

#include <malloc.h>

lt_list* lt_list_new()
{
	lt_list* list = malloc(sizeof(lt_list));

	lt_list_init(list);

	return list;
}

void lt_list_init(lt_list* da)
{
	da->start = NULL;
	da->end = NULL;
	da->size = 0;
}

void lt_list_free(lt_list* da)
{
	// TODO:
	// use lt_list_each to free all elements?
}

void lt_list_delete(lt_list* da)
{
	lt_list_free(da);
	free(da);
}

void lt_list_each(lt_list* da, void (func)(void*, void*), void* data)
{
	lt_list_node* i = da->start;

	for (size_t j = 0; j < da->size; j++)
	{
		func(i, data);
		i = i->next;
	}
}

void lt_list_attach_between(lt_list* da, lt_list_node* left, lt_list_node* right, lt_list_node* data)
{
	left->next = data;
	data->prev = left;

	data->next = right;
	right->prev = data;

	da->size++;
}

void lt_list_attach_back(lt_list* da, void* list_node)
{
	if (da->size == 0)
		lt_list_attach_between(da, (lt_list_node*)da, (lt_list_node*)da, list_node);
	else
		lt_list_attach_between(da, da->end, (lt_list_node*)da, list_node);
}

void lt_list_attach_front(lt_list* da, void* list_node)
{
	if (da->size == 0)
		lt_list_attach_between(da, (lt_list_node*)da, (lt_list_node*)da, list_node);
	else 
		lt_list_attach_between(da, (lt_list_node*)da, da->start, list_node);
}

size_t lt_list_size(lt_list* da)
{
	return da->size;
}

