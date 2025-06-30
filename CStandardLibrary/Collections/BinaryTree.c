#include "BinaryTree.h"
#include <string.h>

bool BinaryTreeInsert(struct BinaryTreeNode* a_tree, uint64_t a_key, void* a_data) {
    if (a_tree->key == a_key || a_tree->key == 0) {
        a_tree->key = a_key;
        a_tree->data = realloc(a_tree->data, sizeof(a_data));
        memcpy(a_tree->data, a_data, sizeof(a_data));
        return true;
    } else if (a_key < a_tree->key) {
        if (a_tree->left == NULL) {
            a_tree->left = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
            InitBinaryTree(a_tree->left);
        }
        return BinaryTreeInsert(a_tree->left, a_key, a_data);
    } else {
        if (a_tree->right == NULL) {
            a_tree->right = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
            InitBinaryTree(a_tree->right);
        }
        return BinaryTreeInsert(a_tree->right, a_key, a_data);
    }
}

void* BinaryTreeQuery(struct BinaryTreeNode* a_tree, uint64_t a_key) {
    if (a_tree->key == a_key) {
        return a_tree->data;
    } else if (a_key < a_tree->key) {
        if (a_tree->left != NULL) {
            return BinaryTreeQuery(a_tree->left, a_key);
        }
    } else if (a_tree->right != NULL) {
        return BinaryTreeQuery(a_tree->right, a_key);
    }
    return NULL;
}

void InitBinaryTree(struct BinaryTreeNode* a_tree) {
    a_tree->key = 0;
    a_tree->left = NULL;
    a_tree->right = NULL;
    a_tree->data = malloc(0);
}

void DestroyBinaryTree(struct BinaryTreeNode* a_tree) {
    if (a_tree->left != NULL) {
        DestroyBinaryTree(a_tree->left);
        free(a_tree->left);
    }
    if (a_tree->right != NULL) {
        DestroyBinaryTree(a_tree->right);
        free(a_tree->right);
    }
}