#include <CString.h>
#include <stdlib.h>
#include <string.h>

void InitString(String* a_string, const char* a_chars) {
    a_string->size = strlen(a_chars);
    a_string->m_maxSize = a_string->size;
    a_string->chars = malloc(a_string->size);
    memcpy(a_string->chars, a_chars, a_string->size + 1);
    //printf("%s - %s - %zi - %zi - %zi\n", a_chars, a_string->chars, strlen(a_chars), a_string->size, a_string->m_maxSize);
};

void EmptyString(String* a_string) {
    a_string->size = 0;
    a_string->m_maxSize = 0;
    a_string->chars = "";
};

size_t StringLen(const String* a_string) {
    return a_string->size + 1;
}

void StringConcatChars(String* a_string, const char* a_chars) {
    size_t newLength = StringLen(a_string) + strlen(a_chars);
    SetString(a_string, strcat(a_string->chars, a_chars));
}

void StringConcatString(String* a_string, const String* a_otherString) {
    return;
}


void SetString(String* a_string, char* a_chars) {
    a_string->size = strlen(a_chars);
    if (a_string->m_maxSize < a_string->size) {
        a_string->chars = realloc(a_string->chars, a_string->size);
        a_string->m_maxSize = a_string->size;
    }
    memcpy(a_string->chars, a_chars, a_string->size + 1);
};

void ClearString(String* a_string) {
    free(a_string->chars);
    a_string->size = 0;
    a_string->m_maxSize = 0;
};

uint64_t HashString(const String* a_string) {
    char* str = a_string->chars;
    uint64_t hash = 5381;
    char c = 0;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

uint64_t HashCharArray(char* a_chars) {
    uint64_t hash = 5381;
    char c = 0;

    while (c = *a_chars++) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}