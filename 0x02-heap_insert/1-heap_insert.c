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
