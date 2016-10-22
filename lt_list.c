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
	start = NULL;
	end = NULL;
}

void lt_list_free(lt_list* da)
{
	// TODO:
}

void lt_list_delete(lt_list* da)
{
	lt_list_free(da);
	free(da);
}

void lt_list_each(lt_list* da, void (func)(void*, void*), void* data)
{
	for (lt_list_node* i = da->start; i != NULL; i = i->next)
	{
		func(i, data);
	}
}

void lt_list_insert_back(lt_list* da, void* data)
{
	
}

size_t lt_list_size(lt_list* da)
{
	return 0;
}

