#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - find number of layers in binary tree ABOVE current node
 * @tree: root of tree
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || (!tree->parent)) /* dumb special case */
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
