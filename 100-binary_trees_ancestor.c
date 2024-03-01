#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 * ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	/* Base case: if either node matches, return the node itself */
	if (first == second)
		return ((binary_tree_t *)first);

	/* Check if first is ancestor of second */
	for (ancestor = second; ancestor != NULL; ancestor = ancestor->parent)
	{
		if (ancestor == first)
			return ((binary_tree_t *)first);
	}

	/* Check if second is ancestor of first */
	for (ancestor = first; ancestor != NULL; ancestor = ancestor->parent)
	{
		if (ancestor == second)
			return ((binary_tree_t *)second);
	}

	/* Traverse upward to find the lowest common ancestor */
	for (; first != NULL; first = first->parent)
	{
		for (ancestor = second; ancestor != NULL; ancestor = ancestor->parent)
		{
			if (first == ancestor)
				return ((binary_tree_t *)first);
		}
	}

	return (NULL); /* No common ancestor found */
}
