#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: The value in the node must be passed as a parameter to the function.
 * If tree or func is NULL, do nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Traverse left subtree */
    binary_tree_postorder(tree->left, func);

    /* Traverse right subtree */
    binary_tree_postorder(tree->right, func);

    /* Call function for current node */
    func(tree->n);
}
