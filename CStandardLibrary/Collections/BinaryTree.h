#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdio.h>
#include <stdint.h>
#include <windows.h>
#include <stdbool.h>
#include <FatPtr.h>

/// @struct BinaryTreeNode
/// @brief Brief
///
/// Detailed 
typedef struct m_binaryTreeNode {
    /// @brief 
    uint64_t key;
    /// @brief 
    FatPtr data;
    /// @brief 
    struct m_binaryTreeNode* left;
    /// @brief 
    struct m_binaryTreeNode* right;
} BinaryTreeNode;

/// @brief 
/// @param  
/// @param  
/// @param  
/// @return 
bool BinaryTreeInsert(BinaryTreeNode*, uint64_t, FatPtr);

/// @brief 
/// @param  
/// @param  
/// @return 
FatPtr BinaryTreeQuery(BinaryTreeNode*, uint64_t);

/// @brief 
/// @param 
void InitBinaryTree(BinaryTreeNode*);

/// @brief 
/// @param 
void DestroyBinaryTree(BinaryTreeNode*);
#endif