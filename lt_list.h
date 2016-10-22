#ifndef LT_LIST_H
#define LT_LIST_H

#include <malloc.h>

typedef struct lt_ll_node
{
	struct lt_ll_node* prev;
	struct lt_ll_node* next;
} lt_list_node;

typedef struct
{
	lt_list_node* start;
	lt_list_node* end;
	size_t size;
} lt_list;

lt_list* lt_list_new();
void lt_list_init(lt_list* da);
void lt_list_free(lt_list* da);
void lt_list_delete(lt_list* da);

void lt_list_each(lt_list* da, void (func)(void*, void*), void* data);
void lt_list_insert_back(lt_list* da, void* data);

size_t lt_list_size(lt_list* da);

#endif // LT_LIST_H
