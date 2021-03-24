#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * is_binary_search_tree - Checks if tree is a binary search tree
 * @node: Current node being checked
 * @min: Integer indicating the left boundary
 * @max: Integer indicating the right boundary
 * @height: Height of the current binary tree level
 * Return: 1 if tree is a valid BST
 */
int is_binary_search_tree(const binary_tree_t *node, int min, int max,
		int *height)
{
	int left_h = 0;
	int right_h = 0;

	if (!node)
		return (1);
	if (node->n >= max || node->n <= min)
		return (0);
	if (!is_binary_search_tree(node->left, min, node->n, &left_h) ||
			!is_binary_search_tree(node->right, node->n,
				max, &right_h))
		return (0);
	*height = (left_h > right_h ? left_h : right_h) + 1;
	return (abs(left_h - right_h) < 2);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node
 * Return: 1 if tree is a valid AVL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (is_binary_search_tree(tree, INT_MIN, INT_MAX, &height));
}
