#ifndef C_STRING_H
#define C_STRING_H
#include <stdio.h>
#include <stdint.h>
#include <string.h>
/// @file String.h
/// @brief Defines the String struct and functions to modify them.
///
/// Defines the String struct and functions to modify them.

/// @struct String
/// @brief A String struct.
///
/// A String struct containing the contents of the String and the size of the String. 
typedef struct {
    /// @brief The contents of the String.
    char* chars;
    /// @brief The size of the String.
    size_t size;
    /// @brief The max size of the String. THIS SHOULD NEVER BE CHANGED.
    size_t m_maxSize;
} String;

/// @brief Initialize a @c String instance with the @p a_chars parameter.
/// @param[out] a_string The String to initialize. 
/// @param[in] a_chars The character array to initialize the String with.
void InitString(String*, const char*);

/// @brief Initialize a @c String to be empty.
/// @param[out] a_string The @c String to initalize.
void EmptyString(String*);

/// @brief Get the length of a @c String.
/// @param[in] a_string The @c String to get the length of.
size_t StringLen(const String*);

/// @brief 
/// @param[in] a_string
void StringConcatChars(String*, const char*);

/// @brief Concatenate a @c String onto another @c String.
/// @param[in,out] a_string The @c String to be concatenated onto.
/// @param[in] a_otherString The @c String to be concatenated.
void StringConcatString(String*, const String*);

/// @brief 
/// @param[in,out] a_string
/// @param[in] a_char
void SetString(String*, char*);

/// @brief 
/// @param[in] a_string Pointer to the String to clear.
void ClearString(String*);

/// @brief 
/// @param[in] a_string Pointer to the String to hash.
/// @return The hash of the @p a_string parameter, the hash is a @c uint64_t.
uint64_t HashString(const String*);

/// @brief 
/// @param[in] a_chars Char array to hash.
/// @return The hash of the @p a_chars parameter, the hash is a @c uint64_t.
uint64_t HashCharArray(char*);
#endif