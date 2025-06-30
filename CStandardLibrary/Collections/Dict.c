#include "Dict.h"

void InitDictEntry(DictEntry* a_dictEntry, uint64_t a_key) {
    a_dictEntry->key = a_key;
    a_dictEntry->data = malloc(0);
    a_dictEntry->nextEntry = NULL;
}

void DictEntrySet(DictEntry* a_dictEntry, uint64_t a_key, void* a_value) {
    if (a_dictEntry->key == a_key) {
        a_dictEntry->data = realloc(a_dictEntry->data, sizeof(a_value));
        memcpy(a_dictEntry->data, a_value, sizeof(a_value));
    } else {
        if (a_dictEntry->nextEntry == NULL) {
            a_dictEntry->nextEntry = malloc(sizeof(DictEntry));
            InitDictEntry(a_dictEntry->nextEntry, a_key);
        }

        DictEntrySet(a_dictEntry->nextEntry, a_key, a_value);
    }
}

void* DictEntryGet(DictEntry* a_dictEntry, uint64_t a_key) {
    if (a_dictEntry->key == a_key) {
        return a_dictEntry->data;
    } else if (a_dictEntry->nextEntry != NULL) {
        return DictEntryGet(a_dictEntry->nextEntry, a_key);
    }
    return NULL;
}

void InitDict(Dict* a_dict, size_t breadth) {
    a_dict->size = breadth;
    a_dict->entries = malloc(a_dict->size * sizeof(DictEntry));
    for (int i = 0; i < a_dict->size; i++) {
        InitDictEntry(&a_dict->entries[i], i);
    }
}

void DictSet(Dict* a_dict, uint64_t a_key, void* a_value) {
    size_t index = a_key % a_dict->size;
    DictEntrySet(&a_dict->entries[index], a_key, a_value);
}

void* DictGet(Dict* a_dict, uint64_t a_key) {
    size_t index = a_key % a_dict->size;
    return DictEntryGet(&a_dict->entries[index], a_key);
}