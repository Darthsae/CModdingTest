#ifndef DICT_H
#define DICT_H
#include <stdio.h>
#include <stdint.h>
#include <windows.h>
#include <CString.h>
#include <FatPtr.h>

/// @struct DictEntry
/// @brief 
///
/// Detailed 
typedef struct m_dictEntry {
    struct m_dictEntry* nextEntry;
    uint64_t key;
    FatPtr data;
} DictEntry;

/// @struct Dict
/// @brief A structure containing an array of DictEntry's.
///
/// Detailed 
typedef struct {
    /// @brief 
    DictEntry* entries;
    /// @brief 
    size_t size;
} Dict;

void InitDictEntry(DictEntry*, uint64_t);
void DictEntrySet(DictEntry*, uint64_t, FatPtr);
FatPtr DictEntryGet(DictEntry*, uint64_t);

void InitDict(Dict*, size_t);
void DictSet(Dict*, uint64_t, FatPtr);
FatPtr DictGet(Dict*, uint64_t);
#endif