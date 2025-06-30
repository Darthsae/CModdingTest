#include "Int32List.h"
#include <CAsserts.h>
#include <string.h>
#include <stdlib.h>

void InitInt32List(Int32List* a_list, size_t a_index) {
    a_list->m_maxSize = a_index;
    a_list->size = 0;
    a_list->data = malloc(a_list->m_maxSize * sizeof(int32_t));
    assert(("Data is not NULL", a_list->data != NULL));
}

bool Int32ListContains(Int32List* a_list, int32_t a_value) {
    for (size_t i = 0; i < a_list->size; ++i) {
        if (a_list->data[i] == a_value) {
            return true;
        }
    }

    return false;
}

size_t Int32ListCount(Int32List* a_list, int32_t a_value) {
    size_t count = 0;

    for (size_t i = 0; i < a_list->size; ++i) {
        if (a_list->data[i] == a_value) {
            count++;
        }
    }

    return count;
}

void Int32ListInsert(Int32List* a_list, size_t a_index, int32_t a_value) {
    a_list->size++;
    if (a_list->size > a_list->m_maxSize) {
        a_list->m_maxSize++;
        a_list->data = realloc(a_list->data, a_list->m_maxSize * sizeof(int32_t));
    }

    memmove(a_list->data + (a_index + 1) * sizeof(int32_t), a_list->data + (a_index) * sizeof(int32_t), (a_list->size - a_index - 2) * sizeof(int32_t));
    a_list->data[a_index] = a_value;
}

void Int32ListAppend(Int32List* a_list, int32_t a_value) {
    a_list->size++;
    if (a_list->size > a_list->m_maxSize) {
        a_list->m_maxSize++;
        a_list->data = realloc(a_list->data, a_list->m_maxSize * sizeof(int32_t));
    }
    a_list->data[a_list->size - 1] = a_value;
}

int32_t Int32ListGet(Int32List* a_list, size_t a_index) {
    return a_list->data[a_index];
}

size_t Int32ListFind(Int32List* a_list, int32_t a_value) {
    for (size_t i = 0; i < a_list->size; ++i) {
        if (a_list->data[i] == a_value) {
            return i;
        }
    }

    return -1;
}

void Int32ListRemoveValue(Int32List* a_list, int32_t a_value) {
    for (size_t i = 0; i < a_list->size; ++i) {
        if (a_list->data[i] == a_value) {
            Int32ListRemoveIndex(a_list, i);
            return;
        }
    }
}

void Int32ListRemoveIndex(Int32List* a_list, size_t a_index) {
    a_list->size--;
    memmove(a_list->data + a_index * sizeof(int32_t), a_list->data + (a_index + 1) * sizeof(int32_t), (a_list->size - a_index) * sizeof(int32_t));
}

int32_t Int32ListPopTop(Int32List* a_list) {
    a_list->size--;
    return a_list->data[a_list->size];
}

void DestroyInt32List(Int32List* a_list) {
    free(a_list->data);
    a_list->m_maxSize = 0;
    a_list->size = 0;
}
