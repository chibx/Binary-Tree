#pragma once

typedef enum { BINARY_TREE_SUCCESS, BINARY_TREE_ERROR } BinTreeStatus;

// In this case
typedef struct BinaryTree {
        //   int capacity;
        struct BinaryTree *left;
        struct BinaryTree *right;
        char *value;
} BinaryTree;

// void traverse(BinaryTree *stack);

/// Inserts into left first, else right, else if no side is initially NULL,
/// returns an error status
void binary_tree_insert(BinaryTree *tree, char *value);

BinaryTree *create_binary_tree(char *initial_value);