#include "Dict.h"

void InitDictEntry(DictEntry* a_dictEntry, uint64_t a_key) {
    a_dictEntry->key = a_key;
    InitFatPtr(&a_dictEntry->data, NULL, 0);
    a_dictEntry->nextEntry = NULL;
}

void DictEntrySet(DictEntry* a_dictEntry, uint64_t a_key, FatPtr a_value) {
    if (a_dictEntry->key == a_key) {
        FatPtrSet(&a_dictEntry->data, a_value.data, a_value.length);
    } else {
        if (a_dictEntry->nextEntry == NULL) {
            a_dictEntry->nextEntry = malloc(sizeof(DictEntry));
            InitDictEntry(a_dictEntry->nextEntry, a_key);
        }

        DictEntrySet(a_dictEntry->nextEntry, a_key, a_value);
    }
}

FatPtr DictEntryGet(DictEntry* a_dictEntry, uint64_t a_key) {
    if (a_dictEntry->key == a_key) {
        return a_dictEntry->data;
    } else if (a_dictEntry->nextEntry != NULL) {
        return DictEntryGet(a_dictEntry->nextEntry, a_key);
    }
    FatPtr ptr = {NULL, 0};
    return ptr;
}

void InitDict(Dict* a_dict, size_t a_breadth) {
    a_dict->size = a_breadth;
    a_dict->entries = malloc(a_dict->size * sizeof(DictEntry));
    for (int i = 0; i < a_dict->size; i++) {
        InitDictEntry(&a_dict->entries[i], i);
    }
}

void DictSet(Dict* a_dict, uint64_t a_key, FatPtr a_value) {
    size_t index = a_key % a_dict->size;
    DictEntrySet(&a_dict->entries[index], a_key, a_value);
}

FatPtr DictGet(Dict* a_dict, uint64_t a_key) {
    size_t index = a_key % a_dict->size;
    return DictEntryGet(&a_dict->entries[index], a_key);
}