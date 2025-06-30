#ifndef INT32_LIST_H
#define INT32_LIST_H
#include <stdint.h>
#include <stdbool.h>

/// @struct Int32List
/// @brief A dynamic list of int32_t.
///
/// A dynamic list of int32_t that will grow to fit it's contents. It will not shrink in size.
typedef struct {
    /// @brief The contents of the list.
    int32_t* data;
    /// @brief The max size of the list. THIS SHOULD NEVER BE CHANGED.
    size_t m_maxSize;
    /// @brief The current size of the list.
    size_t size;
} Int32List;

/// @brief Initialize a list with a maximum capacity.
/// @param[in] a_list The list to be initialized.
/// @param[in] a_capacity The max capacity of the list. 
void InitInt32List(Int32List*, size_t);

/// @brief Check if a list contains a value.
/// @param[in] a_list The list to check for containing the value.
/// @param[in] a_value The value to check for.
/// @return 
bool Int32ListContains(Int32List*, int32_t);

/// @brief Count the number of occurences of a value in a list.
/// @param[in] a_list The list to count the number of occurences of value in.
/// @param[in] a_value The value to count the number of occurences of.
/// @return 
size_t Int32ListCount(Int32List*, int32_t);

/// @brief 
/// @param[in] a_list The list to insert the value into.
/// @param[in] a_index The index to insert the value at.
/// @param[in] a_value The value to insert.
void Int32ListInsert(Int32List*, size_t, int32_t);

/// @brief 
/// @param[in] a_list The list to append the value to.
/// @param[in] a_value The value to append to the end of the list.
void Int32ListAppend(Int32List*, int32_t);

/// @brief Get a value from a list at an index.
/// @param[in] a_list The list to get the value at the index from.
/// @param[in] a_index The index to get the value from.
/// @return 
int32_t Int32ListGet(Int32List*, size_t);

/// @brief Find the index of a value's first occurence in a list.
/// @param[in] a_list The list to find the index of the value in.
/// @param[in] a_value The value to find in the list.
/// @return 
size_t Int32ListFind(Int32List*, int32_t);

/// @brief Remove a value from a list.
/// @param[in] a_list The list to remove the value from.
/// @param[in] a_value The value to remove from the list.
void Int32ListRemoveValue(Int32List*, int32_t);

/// @brief Remove a value from a list at an index.
/// @param[in] a_list The list to remove the index from.
/// @param[in] a_index The index to remove the value from.
void Int32ListRemoveIndex(Int32List*, size_t);

/// @brief Pop the top value from a list.
/// @param[in] a_list The list to pop the top from.
/// @return The value that was popped.
int32_t Int32ListPopTop(Int32List*);

/// @brief Destroy a list.
/// @param[in] a_list The list to destroy.
void DestroyInt32List(Int32List*);
#endif