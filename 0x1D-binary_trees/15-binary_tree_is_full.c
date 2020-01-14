#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_full - check if binary tree is full
 *  (each node has 0 or 2 branches)
 * @tree: root of tree
 * Return: if tree is full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->right || tree->left)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (1);
}
