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
    /// @brief The key of the @c BinaryTreeNode.
    uint64_t key;
    /// @brief The data of the @c BinaryTreeNode.
    FatPtr data;
    /// @brief The left leaf of the @c BinaryTreeNode.
    struct m_binaryTreeNode* left;
    /// @brief The right leaf of the @c BinaryTreeNode.
    struct m_binaryTreeNode* right;
} BinaryTreeNode;

/// @brief Inserts a value into a @c BinaryTreeNode with a key.
/// @param[in,out] a_tree The @c BinaryTreeNode to insert @p a_data into.
/// @param[in] a_key The key of the data to insert.
/// @param[in] a_data The data to insert into the @c BinaryTreeNode @p a_tree.
/// @return Whether or not the insertion was successful.
bool BinaryTreeInsert(BinaryTreeNode*, uint64_t, FatPtr);

/// @brief Gets the value of a key in a @c BinaryTreeNode.
/// @param[in,out] a_tree The @c BinaryTreeNode to query.
/// @param[in] a_key The key to find.
/// @return A @c FatPtr containing the data.
FatPtr BinaryTreeQuery(BinaryTreeNode*, uint64_t);

/// @brief Initializes a @c BinaryTreeNode.
/// @param[out] a_tree The @c BinaryTreeNode to initialize.
void InitBinaryTree(BinaryTreeNode*);

/// @brief Destroys a @c BinaryTreeNode.
/// @param[in] a_tree The @c BinaryTreeNode to destroy.
void DestroyBinaryTree(BinaryTreeNode*);
#endif