#ifndef LT_BINARY_TREE_H
#define LT_BINARY_TREE_H

#include "lt_lib.h"

#define LT_TREE_HEADER lt_binary_tree_node header;

typedef struct lt_binary_tree_node
{
	struct lt_binary_tree_node* left;
	struct lt_binary_tree_node* right;
	size_t depth;
} lt_binary_tree_node;

typedef struct
{
	lt_binary_tree_node* root;
	size_t size;
	int (*comparator)(void*, void*);
} lt_binary_tree;

lt_binary_tree* lt_binary_tree_new(int(*comparator)(void*, void*));
void lt_binary_tree_init(lt_binary_tree* da, int(*comparator)(void*, void*));
void lt_binary_tree_free(lt_binary_tree* da);
void lt_binary_tree_delete(lt_binary_tree* da);

void lt_binary_tree_node_init(void* da);

void lt_binary_tree_insert(lt_binary_tree* da, void* node);

#endif // LT_BINARY_TREE_H