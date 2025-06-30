#ifndef STRING_LIST_H
#define STRING_LIST_H
#include <stdint.h>
#include <stdbool.h>
#include <CString.h>

/// @struct StringList
/// @brief A dynamic list of String.
///
/// A dynamic list of String that will grow to fit it's contents. It will not shrink in size.
typedef struct {
    /// @brief The contents of the list.
    String* data;
    /// @brief The max size of the list. THIS SHOULD NEVER BE CHANGED.
    size_t m_maxSize;
    /// @brief The current size of the list.
    size_t size;
} StringList;

/// @brief Initialize a list with a maximum capacity.
/// @param[out] a_list The list to be initialized.
/// @param[in] a_capacity The max capacity of the list. 
void InitStringList(StringList*, size_t);

/// @brief Check if a list contains a value.
/// @param[in] a_list The list to check for containing the value.
/// @param[in] a_value The value to check for.
/// @return If the list contains the value.
bool StringListContains(StringList*, String);

/// @brief Count the number of occurences of a value in a list.
/// @param[in] a_list The list to count the number of occurences of value in.
/// @param[in] a_value The value to count the number of occurences of.
/// @return The number of occurences of the value in the list.
size_t StringListCount(StringList*, String);

/// @brief Insert a value into a list at an index.
/// @param[in,out] a_list The list to insert the value into.
/// @param[in] a_index The index to insert the value at.
/// @param[in] a_value The value to insert.
void StringListInsert(StringList*, size_t, String);

/// @brief Append a value onto the end of a list.
/// @param[in,out] a_list The list to append the value to.
/// @param[in] a_value The value to append to the end of the list.
void StringListAppend(StringList*, String);

/// @brief Get a value from a list at an index.
/// @param[in] a_list The list to get the value at the index from.
/// @param[in] a_index The index to get the value from.
/// @return The value at the index of the list.
String StringListGet(StringList*, size_t);

/// @brief Find the index of a value's first occurence in a list.
/// @param[in] a_list The list to find the index of the value in.
/// @param[in] a_value The value to find in the list.
/// @return The index of the value in the list.
size_t StringListFind(StringList*, String);

/// @brief Remove a value from a list.
/// @param[in,out] a_list The list to remove the value from.
/// @param[in] a_value The value to remove from the list.
void StringListRemoveValue(StringList*, String);

/// @brief Remove a value from a list at an index.
/// @param[in,out] a_list The list to remove the index from.
/// @param[in] a_index The index to remove the value from.
void StringListRemoveIndex(StringList*, size_t);

/// @brief Pop the top value from a list.
/// @param[in,out] a_list The list to pop the top from.
/// @return The value that was popped.
String StringListPopTop(StringList*);

/// @brief Destroy a list.
/// @param[in] a_list The list to destroy.
void DestroyStringList(StringList*);
#endif