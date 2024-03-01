#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue = NULL;
	int flag = 0;
	const binary_tree_t *current = NULL;

	if (tree == NULL)
		return (0);

	queue = queue_create();
	if (queue == NULL)
		return (0);

	queue_push(queue, (void *)tree);

	while (!queue_is_empty(queue))
	{
		current = (const binary_tree_t *)queue_front(queue);
		queue_pop(queue);

		if (current->left != NULL)
		{
			if (flag == 1) /* If we've encountered a non-full node */
			{
				queue_delete(queue);
				return (0);
			}
			queue_push(queue, (void *)current->left);
		}
		else
		{
			flag = 1;

		}

		if (current->right != NULL)
		{
			if (flag == 1) /* If we've encountered a non-full node */
			{
				queue_delete(queue);
				return (0);
			}
			queue_push(queue, (void *)current->right);
		}
		else
		{
			flag = 1;
		}
	}

	queue_delete(queue);
	return (1);
}
