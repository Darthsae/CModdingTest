#ifndef CHAR_ARRAY_LIST_H
#define CHAR_ARRAY_LIST_H
#include <stdint.h>
#include <stdbool.h>

/// @struct CharArrayList
/// @brief A dynamic list of char*.
///
/// A dynamic list of char* that will grow to fit it's contents. It will not shrink in size.
typedef struct {
    /// @brief The contents of the list.
    char** data;
    /// @brief The max size of the list. THIS SHOULD NEVER BE CHANGED.
    size_t m_maxSize;
    /// @brief The current size of the list.
    size_t size;
} CharArrayList;

/// @brief 
/// @param  
/// @param  
void InitCharArrayList(CharArrayList*, size_t);

/// @brief 
/// @param  
/// @param  
/// @return 
bool CharArrayListContains(CharArrayList*, char*);

/// @brief 
/// @param  
/// @param  
/// @return 
size_t CharArrayListCount(CharArrayList*, char*);

/// @brief 
/// @param  
/// @param  
/// @param  
void CharArrayListInsert(CharArrayList*, size_t, char*);

/// @brief 
/// @param  
/// @param  
void CharArrayListAppend(CharArrayList*, char*);

/// @brief 
/// @param  
/// @param  
/// @return 
char* CharArrayListGet(CharArrayList*, size_t);

/// @brief 
/// @param  
/// @param  
/// @return 
size_t CharArrayListFind(CharArrayList*, char*);

/// @brief 
/// @param  
/// @param  
void CharArrayListRemoveValue(CharArrayList*, char*);

/// @brief 
/// @param  
/// @param  
void CharArrayListRemoveIndex(CharArrayList*, size_t);

/// @brief 
/// @param  
/// @return 
char* CharArrayListPopTop(CharArrayList*);

/// @brief 
/// @param  
void DestroyCharArrayList(CharArrayList*);
#endif