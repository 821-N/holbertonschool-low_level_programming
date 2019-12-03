#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - alright buddy you're gonna have to figure out this one on your own
 * @node: node to check
 * Return: 1 if node is leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node && !node->right && !node->left);
}
