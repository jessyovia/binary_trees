#include "binary_trees.h"
#include <stdlib.h>

void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    /* Recursively delete left subtree */
    binary_tree_delete(tree->left);
    /* Recursively delete right subtree */
    binary_tree_delete(tree->right);

    /* Free current node */
    free(tree);
}
