#include "lt_list.h"
#include "lt_vector.h"
#include "lt_binary_tree.h"
#include "lt_lib.h"

lt_binary_tree* lt_binary_tree_new(int(*comparator)(void*, void*))
{
	lt_binary_tree* tree = malloc(sizeof(lt_binary_tree));

	lt_binary_tree_init(tree, comparator);

	return tree;
}

void lt_binary_tree_init(lt_binary_tree* da, int(*comparator)(void*, void*))
{
	da->size = 0;
	da->comparator = comparator;
}

// @private
void lt_binary_tree_get_each(void* node, void* data)
{
	lt_vector_insert(data, node);
}

// @private
void lt_binary_tree_free_each(void* node, void* data)
{
	lt_free(node);
}

void lt_binary_tree_free(lt_binary_tree* da)
{
	lt_vector all;
	lt_vector_init(&all);

	lt_binary_tree_each(da, lt_binary_tree_get_each, &all);

	lt_vector_each(&all, lt_binary_tree_free_each, NULL);

	lt_vector_free(&all);
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
	register int compare;
	register lt_binary_tree_node* last,* current;

	lt_binary_tree_node_init(node);

	da->size++;

	if (da->size == 1)
	{
		da->root = node;
		return;
	}

	current = da->root;

	last = current;

	while (current != NULL)
	{
		compare = da->comparator(da->root, node);

		last = current;

		if (compare < 0)
			current = current->left;
		else if (compare > 0)
			current = current->right;
		else
			current = current->right;
	}

	if (compare < 0)
		last->left = node;
	else if (compare > 0)
		last->right = node;
	else
		last->right = node;
}

typedef struct
{
	LT_LIST_HEADER
	lt_binary_tree_node* node;
} binary_tree_each_t;

// BUGBUG:
void lt_binary_tree_each(lt_binary_tree* da, void (each)(void*, void*), void* data)
{
	lt_list queue;
	binary_tree_each_t* tmp;

	lt_list_init(&queue);

	tmp = lt_malloc(sizeof(binary_tree_each_t));
	tmp->node = da->root;

	lt_list_attach_back(&queue, tmp);

	while (lt_list_size(&queue) > 0)
	{
		tmp = lt_list_pop_front(&queue);
		each(tmp->node, data);

		if (tmp->node->left != NULL)
		{
			binary_tree_each_t* tmp2 = lt_malloc(sizeof(binary_tree_each_t));
			tmp->node = tmp->node->left;
			lt_list_attach_back(&queue, tmp2);
		}

		if (tmp->node->right != NULL)
		{
			binary_tree_each_t* tmp2 = lt_malloc(sizeof(binary_tree_each_t));
			tmp->node = tmp->node->right;
			lt_list_attach_back(&queue, tmp2);
		}

		lt_free(tmp);
	}

	lt_free(tmp);
	lt_list_free(&queue);
}
