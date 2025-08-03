#include "../include/binary_tree.h"
#include <stdlib.h>
#include <string.h>

BinaryTree *create_binary_tree(char *initial_value) {
        BinaryTree *tree = malloc(sizeof(BinaryTree));

        if (tree == NULL) {
                exit(EXIT_FAILURE);
        }

        tree->left = NULL;
        tree->right = NULL;
        tree->value = initial_value;

        return tree;
}

void binary_tree_insert(BinaryTree *tree, char *value) {
        BinaryTree *new_node = malloc(sizeof(BinaryTree));

        new_node->left = NULL;
        new_node->right = NULL;
        new_node->value = _strdup(value);

        if (tree->left == NULL) {
                tree->left = new_node;
                return;
        } else if (tree->right == NULL) {
                tree->right = new_node;
                return;
        }

        free(new_node);
}