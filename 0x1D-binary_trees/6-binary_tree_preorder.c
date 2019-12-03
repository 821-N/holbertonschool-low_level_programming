#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - call a function on each node of a binary tree using pre-order traversal
 *  depth first search basically
 * @tree: root of tree
 * @func: function to call
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
