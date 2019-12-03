#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - allocate new node
 * @parent: node's parent
 * @value: value
 * Return: pointer to node, or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->parent = parent;
	new->n = value;
	return (new);
}
