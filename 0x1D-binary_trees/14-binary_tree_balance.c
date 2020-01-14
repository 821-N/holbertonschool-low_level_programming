#include <stdlib.h>
#include "binary_trees.h"

/**
 * height - find number of layers in binary tree (including current node)
 * @tree: root of tree
 * Return: height
 */
static size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	left = height(tree->left);
	right = height(tree->right);
	return (1 + (left > right ? left : right));
}

/**
 * binary_tree_balance - find balance factor of tree
 * @tree: root of tree
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height(tree->left) - height(tree->right));
}
