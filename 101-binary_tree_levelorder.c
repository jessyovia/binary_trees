#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary
 * tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tmp, k;

	if (!tree || !func)
		return;

	/* Measure the height of the tree */
	tmp = binary_tree_height(tree);

	/* Traverse the tree level by level */
	for (k = 1; k <= tmp; k++)
		tree_level(tree, k, func);
}

/**
 * tree_level - Function to traverse a level of a binary tree
 * @tree: Pointer to the root of the tree
 * @level: Level of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void tree_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		tree_level(tree->left, level - 1, func);
		tree_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}
