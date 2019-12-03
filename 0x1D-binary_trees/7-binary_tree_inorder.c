#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - call a function on each node of a binary tree using
 *  in-order traversal
 * @tree: root of tree
 * @func: function to call
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
