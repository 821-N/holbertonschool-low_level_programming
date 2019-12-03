#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_root - alright buddy you're
 *  gonna have to figure out this one on your own
 * @node: node to check
 * Return: 1 if node is root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && !node->parent);
}
