#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - return sibling of parent
 * @node: node to get uncle of
 * Return: uncle or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	node = node->parent;
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
