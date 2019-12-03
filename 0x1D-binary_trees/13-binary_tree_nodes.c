#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - find number of non-leaf nodes in tree
 * @tree: root of tree
 * Return: number of non-leaf nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->right && !tree->left))
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
