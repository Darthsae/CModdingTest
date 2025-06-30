#include "BinaryTree.h"
#include <string.h>

bool BinaryTreeInsert(BinaryTreeNode* a_tree, uint64_t a_key, FatPtr a_data) {
    if (a_tree->key == a_key || a_tree->key == 0) {
        a_tree->key = a_key;
        FatPtrSet(&a_tree->data, a_data.data, a_data.length);
        return true;
    } else if (a_key < a_tree->key) {
        if (a_tree->left == NULL) {
            a_tree->left = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
            InitBinaryTree(a_tree->left);
        }
        return BinaryTreeInsert(a_tree->left, a_key, a_data);
    } else {
        if (a_tree->right == NULL) {
            a_tree->right = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
            InitBinaryTree(a_tree->right);
        }
        return BinaryTreeInsert(a_tree->right, a_key, a_data);
    }
}

FatPtr BinaryTreeQuery(BinaryTreeNode* a_tree, uint64_t a_key) {
    if (a_tree->key == a_key) {
        return a_tree->data;
    } else if (a_key < a_tree->key) {
        if (a_tree->left != NULL) {
            return BinaryTreeQuery(a_tree->left, a_key);
        }
    } else if (a_tree->right != NULL) {
        return BinaryTreeQuery(a_tree->right, a_key);
    }
    FatPtr ptr = {NULL, 0};
    return ptr;
}

void InitBinaryTree(BinaryTreeNode* a_tree) {
    a_tree->key = 0;
    a_tree->left = NULL;
    a_tree->right = NULL;
    InitFatPtr(&a_tree->data, NULL, 0);
}

void DestroyBinaryTree(BinaryTreeNode* a_tree) {
    if (a_tree->left != NULL) {
        DestroyBinaryTree(a_tree->left);
        free(a_tree->left);
    }
    if (a_tree->right != NULL) {
        DestroyBinaryTree(a_tree->right);
        free(a_tree->right);
    }
    DestroyFatPtr(&a_tree->data);
}