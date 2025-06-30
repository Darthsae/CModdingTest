#pragma once
#ifndef FAT_PTR_H
#define FAT_PTR_H
#include <stdint.h>

typedef struct {
    void* data;
    size_t length;
} FatPtr;

void FatPtrSet(FatPtr*, void*, size_t);
#endif