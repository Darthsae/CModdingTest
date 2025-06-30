#ifndef DICT_H
#define DICT_H
#include <stdio.h>
#include <stdint.h>
#include <windows.h>
#include <CString.h>
#include <FatPtr.h>

/// @struct DictEntry
/// @brief An entry into a @c Dict.
///
/// An entry into a @c Dict that handles conflicts and data storage.
typedef struct m_dictEntry {
    struct m_dictEntry* nextEntry;
    uint64_t key;
    FatPtr data;
} DictEntry;

/// @struct Dict
/// @brief A structure containing an array of DictEntry's.
///
/// A structure containing an array of DictEntry's, which are queryable by a hash, and can support conflicts.
typedef struct {
    /// @brief The entries of the dictionary.
    DictEntry* entries;
    /// @brief The width of the dictionary.
    size_t size;
} Dict;


void InitDictEntry(DictEntry*, uint64_t);


void DictEntrySet(DictEntry*, uint64_t, FatPtr);


FatPtr DictEntryGet(DictEntry*, uint64_t);

/// @brief Initializes a dictionary with a size.
/// @param[out] a_dict The dictionary to intialize.
/// @param[in] a_breadth The width of the dictionary.
void InitDict(Dict*, size_t);


void DictSet(Dict*, uint64_t, FatPtr);


FatPtr DictGet(Dict*, uint64_t);
#endif