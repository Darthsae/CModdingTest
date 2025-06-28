#ifndef STRING_H
#define STRING_H
#include <stdio.h>
#include <stdint.h>
#include <windows.h>
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

/// @brief Create a new @c String instance with the @p a_chars parameter. 
/// @param[in] a_chars The character array to initialize the String with.
/// @return A string with the contents of the @p a_chars parameter.
String InitString(char*);

/// @brief 
/// @return 
String EmptyString(void);

/// @brief 
/// @param[in] a_string
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