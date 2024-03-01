#include "binary_trees.h"
#include "queue.h" // Assuming you have a queue implementation

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	const binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;

	queue = queue_create();
	if (queue == NULL)
		return;

	queue_push(queue, (void *)tree);

	while (!queue_is_empty(queue))
	{
		current = (const binary_tree_t *)queue_front(queue);
		queue_pop(queue);
		func(current->n);

		if (current->left != NULL)
			queue_push(queue, (void *)current->left);
		if (current->right != NULL)
			queue_push(queue, (void *)current->right);
	}

	queue_delete(queue);
}
