#include <stdlib.h>
#include "binary_trees.h"

/**
 * _find_insert_parent - find parent where to insert heap node
 *
 * @node: node being examined
 * @depth: depth node is at
 *
 * Return: address of parent
 */
node_depth _find_insert_parent(heap_t *node, size_t depth)
{
	node_depth ret, ret2;

	if (node->left == NULL || node->right == NULL)
	{
		ret.node = node;
		ret.depth = depth;
		return (ret);
	}

	ret = _find_insert_parent(node->left, depth + 1);
	ret2 = _find_insert_parent(node->right, depth + 1);
	if (ret.depth != ret2.depth)
		return (ret2);
	else
		return (ret);
}

/**
 * _swap - swap a node with its parent
 *
 * @node: node to swap with its parent
 */
void _swap(heap_t *node)
{
	heap_t *swap, *parent;

	parent = node->parent;
	if (node->left != NULL)
		node->left->parent = parent;
	if (node->right != NULL)
		node->right->parent = parent;
	if (parent->left != NULL)
		parent->left->parent = node;
	if (parent->right != NULL)
		parent->right->parent = node;
	swap = node->left;
	node->left = parent->left;
	parent->left = swap;
	swap = node->right;
	node->right = parent->right;
	parent->right = swap;
	if (node == node->left)
		node->left = parent;
	if (node == node->right)
		node->right = parent;
	if (parent->parent != NULL)
	{
		if (parent->parent->left == parent)
			parent->parent->left = node;
		if (parent->parent->right == parent)
			parent->parent->right = node;
	}
	node->parent = parent->parent;
	parent->parent = node;
}
