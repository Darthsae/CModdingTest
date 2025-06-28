#include <CString.h>

String InitString(char* a_chars) {
    String string;
    string.size = sizeof(a_chars);
    string.m_maxSize = sizeof(a_chars);
    string.chars = malloc(string.size);
    memcpy(string.chars, a_chars, string.size);
    return string;
};

String EmptyString(void) {
    String string;
    string.size = 0;
    string.m_maxSize = 0;
    string.chars = malloc(0);
    return string;
};

void SetString(String* a_string, char* a_chars) {
    a_string->size = sizeof(a_chars);
    if (a_string->m_maxSize < a_string->size) {
        a_string->chars = realloc(a_string->chars, a_string->size);
        a_string->m_maxSize = a_string->size;
    }
    memcpy(a_string->chars, a_chars, a_string->size);
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