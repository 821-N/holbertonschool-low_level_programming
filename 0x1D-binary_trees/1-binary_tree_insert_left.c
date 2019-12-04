#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert left node
 *  see binary_tree_insert_right
 * @parent: node's parent
 * @value: value
 * Return: pointer to node, or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->parent = parent;
	new->right = NULL;
	new->left = parent->left;
	if (parent->left)
		parent->left->parent = new;
	parent->left = new;
	new->n = value;
	return (new);
}
