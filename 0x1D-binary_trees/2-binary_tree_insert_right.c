#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert right node
 *  see binary_tree_insert_left
 * @parent: node's parent
 * @value: value
 * Return: pointer to node, or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(*new));
	new->parent = parent;
	new->left = NULL;
	new->right = parent->right;
	if (parent->right)
		parent->right->parent = new;
	parent->right = new;
	new->n = value;
	return (new);
}
