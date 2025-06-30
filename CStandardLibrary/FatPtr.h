#pragma once
#ifndef FAT_PTR_H
#define FAT_PTR_H
#include <stdint.h>

/// @struct FatPtr
/// @brief A Fat Pointer holding arbitrary data and the size of the data.
typedef struct {
    void* data;
    size_t length;
} FatPtr;

/// @brief Initialize a FatPtr with data and size.
/// @param[out] a_fatPtr The FatPtr to initialize.
/// @param[in] a_data The data to initialize the FatPtr with.
/// @param[in] a_size The size of the data.
void InitFatPtr(FatPtr*, void*, size_t);

/// @brief Set a FatPtr to data and size.
/// @param[in,out] a_fatPtr The FatPtr to set.
/// @param[in] a_data The data to set the FatPtr to.
/// @param[in] a_size The size of the data.
void FatPtrSet(FatPtr*, void*, size_t);

/// @brief Destroy a FatPtr.
/// @param[in] a_fatPtr The FatPtr to destroy.
void DestroyFatPtr(FatPtr*);
#endif