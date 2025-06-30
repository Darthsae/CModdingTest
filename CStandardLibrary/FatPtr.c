#include "FatPtr.h"
#include <stdlib.h>
#include <memory.h>

void InitFatPtr(FatPtr* a_fatPtr, void* a_data, size_t a_size) {
    a_fatPtr->length = a_size;
    a_fatPtr->data = malloc(a_fatPtr->length);
    memcpy(a_fatPtr->data, a_data, a_fatPtr->length);
}
void FatPtrSet(FatPtr* a_fatPtr, void* a_data, size_t a_size) {
    a_fatPtr->length = a_size;
    a_fatPtr->data = realloc(a_fatPtr->data, a_fatPtr->length);
    memcpy(a_fatPtr->data, a_data, a_fatPtr->length);
}
void DestroyFatPtr(FatPtr* a_fatPtr) {
    a_fatPtr->length = 0;
    free(a_fatPtr->data);
}