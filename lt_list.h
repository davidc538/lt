#ifndef LT_LIST_H
#define LT_LIST_H

#include "lt_lib.h"

#define LT_LIST_HEADER lt_list_node header;

typedef struct lt_list_node
{
	struct lt_list_node* prev;
	struct lt_list_node* next;
} lt_list_node;

typedef struct
{
	lt_list_node* end;
	lt_list_node* start;
	size_t size;
} lt_list;

lt_list* lt_list_new();
void lt_list_init(lt_list* da);
void lt_list_free(lt_list* da);
void lt_list_delete(lt_list* da);

void lt_list_each(lt_list* da, void (func)(void*, void*), void* data);

void lt_list_attach_between(lt_list* da, lt_list_node* left, lt_list_node* right, lt_list_node* data);
void lt_list_attach_back(lt_list* da, void* list_node);
void lt_list_attach_front(lt_list* da, void* list_node);

void* lt_list_peek_front(lt_list* da);
void* lt_list_peek_back(lt_list* da);

void* lt_list_pop_front(lt_list* da);
void* lt_list_pop_back(lt_list* da);

size_t lt_list_size(lt_list* da);

#endif // LT_LIST_H
