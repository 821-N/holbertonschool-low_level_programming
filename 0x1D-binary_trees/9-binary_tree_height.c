#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - find number of layers in binary tree BELOW current node
 * @tree: root of tree
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	return (1 + (left > right ? left : right));
}
