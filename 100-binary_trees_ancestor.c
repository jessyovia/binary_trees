#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
	binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	temp = (binary_tree_t *)first;
	while (temp)
	{
		if (temp == second || binary_tree_is_descendant(second, temp))
			return (temp);
		temp = temp->parent;
	}

	return (NULL);
}

/**
 * binary_tree_is_descendant - Checks if a node is a descendant of another
 * @node: Pointer to the potential descendant node
 * @ancestor: Pointer to the potential ancestor node
 *
 * Return: 1 if node is a descendant, otherwise 0
 */
int binary_tree_is_descendant(const binary_tree_t *node,
                              const binary_tree_t *ancestor)
{
	if (!node)
		return (0);
	if (node == ancestor)
		return (1);

	return (binary_tree_is_descendant(node->parent, ancestor));
}
