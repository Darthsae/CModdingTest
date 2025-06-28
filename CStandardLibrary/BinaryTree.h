#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdio.h>
#include <stdint.h>
#include <windows.h>
#include <stdbool.h>

/// @struct BinaryTreeNode
/// @brief Brief
///
/// Detailed 
struct BinaryTreeNode {
    /// @brief 
    uint64_t key;
    /// @brief 
    void* data;
    /// @brief 
    struct BinaryTreeNode* left;
    /// @brief 
    struct BinaryTreeNode* right;
};

/// @brief 
/// @param  
/// @param  
/// @param  
/// @return 
bool BinaryTreeInsert(struct BinaryTreeNode*, uint64_t, void*);

/// @brief 
/// @param  
/// @param  
/// @return 
void* BinaryTreeQuery(struct BinaryTreeNode*, uint64_t);

/// @brief 
/// @param 
void InitBinaryTree(struct BinaryTreeNode*);

/// @brief 
/// @param 
void DestroyBinaryTree(struct BinaryTreeNode*);
#endif