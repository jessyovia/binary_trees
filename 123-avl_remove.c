#include "binary_trees.h"

/**
 * measure_balance_factor - Measures the balance factor of an AVL tree.
 * @tree: Pointer to the root node of the tree.
 */
void measure_balance_factor(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	measure_balance_factor(&(*tree)->left);
	measure_balance_factor(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * get_successor - Finds the next successor of a node in a BST.
 * @node: Pointer to the node.
 * Return: The minimum value of the right subtree.
 */
int get_successor(bst_t *node)
{
	int left_val = 0;

	if (node == NULL)
		return (0);
	{
		left_val = get_successor(node->left);
		if (left_val == 0)
			return (node->n);
		return (left_val);
	}
}

/**
 * remove_node_type - Removes a node based on its children.
 * @node: Node to remove.
 * Return: 0 if it has no children, otherwise a non-zero value.
 */
int remove_node_type(bst_t *node)
{
	int new_value = 0;

	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		if (!node->left)
		{
			if (node->parent->right == node)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		if (!node->right)
		{
			if (node->parent->right == node)
				node->parent->right = node->left;
			else
				node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		free(node);
		return (0);
	}
	else
	{
		new_value = get_successor(node->right);
		node->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: Pointer to the root node of the tree.
 * @value: Value of the node to remove.
 * Return: The modified tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @value: Value of the node to remove.
 * Return: The modified tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *adjusted_root = (avl_t *)bst_remove((bst_t *)root, value);

	if (adjusted_root == NULL)
		return (NULL);

	measure_balance_factor(&adjusted_root);
	return (adjusted_root);
}
