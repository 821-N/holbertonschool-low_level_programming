#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - call a function on each node of a binary tree using
 *  post-order traversal
 * @tree: root of tree
 * @func: function to call
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
