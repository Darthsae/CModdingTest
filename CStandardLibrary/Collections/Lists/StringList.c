#include "StringList.h"
#include <CAsserts.h>
#include <string.h>
#include <stdlib.h>

void InitStringList(StringList* a_list, size_t a_index) {
    a_list->m_maxSize = a_index;
    a_list->size = 0;
    a_list->data = malloc(a_list->m_maxSize * sizeof(String));
    assert(("Data is not NULL", a_list->data != NULL));
}

bool StringListContains(StringList* a_list, String a_value) {
    for (size_t i = 0; i < a_list->size; ++i) {
        if (strcmp(a_list->data[i].chars, a_value.chars) == 0) {
            return true;
        }
    }

    return false;
}

size_t StringListCount(StringList* a_list, String a_value) {
    size_t count = 0;

    for (size_t i = 0; i < a_list->size; ++i) {
        if (strcmp(a_list->data[i].chars, a_value.chars) == 0) {
            count++;
        }
    }

    return count;
}

void StringListInsert(StringList* a_list, size_t a_index, String a_value) {
    a_list->size++;
    if (a_list->size > a_list->m_maxSize) {
        a_list->m_maxSize++;
        a_list->data = realloc(a_list->data, a_list->m_maxSize * sizeof(String));
    }

    memmove(a_list->data + (a_index + 1) * sizeof(String), a_list->data + (a_index) * sizeof(String), (a_list->size - a_index - 2) * sizeof(String));
    a_list->data[a_index] = a_value;
}

void StringListAppend(StringList* a_list, String a_value) {
    a_list->size++;
    if (a_list->size > a_list->m_maxSize) {
        a_list->m_maxSize++;
        a_list->data = realloc(a_list->data, a_list->m_maxSize * sizeof(String));
    }
    a_list->data[a_list->size - 1] = a_value;
}

String StringListGet(StringList* a_list, size_t a_index) {
    return a_list->data[a_index];
}

size_t StringListFind(StringList* a_list, String a_value) {
    for (size_t i = 0; i < a_list->size; ++i) {
        if (strcmp(a_list->data[i].chars, a_value.chars) == 0) {
            return i;
        }
    }

    return -1;
}

void StringListRemoveValue(StringList* a_list, String a_value) {
    for (size_t i = 0; i < a_list->size; ++i) {
        if (strcmp(a_list->data[i].chars, a_value.chars) == 0) {
            StringListRemoveIndex(a_list, i);
            return;
        }
    }
}

void StringListRemoveIndex(StringList* a_list, size_t a_index) {
    a_list->size--;
    memmove(a_list->data + a_index * sizeof(String), a_list->data + (a_index + 1) * sizeof(String), (a_list->size - a_index) * sizeof(String));
}

String StringListPopTop(StringList* a_list) {
    a_list->size--;
    return a_list->data[a_list->size];
}

void DestroyStringList(StringList* a_list) {
    free(a_list->data);
    a_list->m_maxSize = 0;
    a_list->size = 0;
}
