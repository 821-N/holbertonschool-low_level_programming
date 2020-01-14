#include <stdlib.h>
#include "binary_trees.h"

/**
 * height - find number of layers in binary tree (including current node)
 * @tree: root of tree
 * Return: height or -1 if not perfect
 */
static ssize_t height(const binary_tree_t *tree)
{
	ssize_t left, right;

	if (!tree)
		return (0);
	left = height(tree->left);
	right = height(tree->right);
	if (left != right || left < 0)
		return (-1);
	return (1 + right);
}

/**
 * binary_tree_is_perfect - check if binary tree is perfect
 *  (full + complete)
 * @tree: root of tree
 * Return: if tree is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height(tree->right) == height(tree->left));
}
