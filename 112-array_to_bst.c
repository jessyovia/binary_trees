#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array of integers
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t index;

	if (!array || size == 0)
		return (NULL);

	for (index = 0; index < size; index++)
		bst_insert(&root, array[index]);

	return (root);
}
