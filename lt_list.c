#include "lt_list.h"
#include "lt_lib.h"

lt_list* lt_list_new()
{
	lt_list* list = lt_malloc(sizeof(lt_list));

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
	lt_list_node* tmp;

	while (lt_list_size(da) > 0)
	{
		tmp = lt_list_pop_front(da);
		lt_free(tmp);
	}
}

void lt_list_delete(lt_list* da)
{
	lt_list_free(da);
	lt_free(da);
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

void* lt_list_peek_front(lt_list* da)
{
	return da->start;
}

void* lt_list_peek_back(lt_list* da)
{
	return da->end;
}

// @private
void lt_list_attach_nodes(lt_list* da, lt_list_node* left, lt_list_node* right)
{
	left->next = right;
	right->prev = left;
}

void* lt_list_pop_front(lt_list* da)
{
	lt_list_node* node = da->start;

	da->start = da->start->next;
	da->start->prev = (lt_list_node*)da;

	da->size--;

	return node;
}

void* lt_list_pop_back(lt_list* da)
{
	lt_list_node* node = da->end;

	da->end = da->end->prev;
	da->end->next = (lt_list_node*)da;

	da->size--;

	return node;
}

size_t lt_list_size(lt_list* da)
{
	return da->size;
}

