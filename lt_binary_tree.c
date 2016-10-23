#include "lt_binary_tree.h"
#include "lt_lib.h"

lt_binary_tree* lt_binary_tree_new(int(*comparator)(void*, void*))
{
	lt_binary_tree* tree = malloc(sizeof(lt_binary_tree));

	lt_binary_tree_init(tree, comparator);
}

void lt_binary_tree_init(lt_binary_tree* da, int(*comparator)(void*, void*))
{
	da->size = 0;
	da->comparator = comparator;
}

void lt_binary_tree_free(lt_binary_tree* da)
{
	// TODO:
}

void lt_binary_tree_delete(lt_binary_tree* da)
{
	lt_binary_tree_free(da);

	lt_free(da);
}

void lt_binary_tree_node_init(void* da)
{
	lt_binary_tree_node* n = (lt_binary_tree_node*)da;

	n->left = NULL;
	n->right = NULL;
}

void lt_binary_tree_insert(lt_binary_tree* da, void* node)
{
	int compare;
	lt_binary_tree_node* last,* current;

	lt_binary_tree_node_init(node);

	da->size++;

	if (da->size == 1)
	{
		da->root = node;
		return;
	}

	current = da->root;

	while (current != NULL)
	{
		compare = da->comparator(da->root, node);

		last = current;

		if (compare < 0)
			current = current->left;
		if (compare > 0)
			current = current->right;
		else;
	}


}
