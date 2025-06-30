#include "Data.h"
#include <Collections/Lists/Int32List.h>
#include <string.h>
#include <stdlib.h>
#define GET_VALID(a_character, a_paren) (a_character == '"') ||\
    (!a_paren && (a_character == ' ' || a_character == '(' || a_character == ')' || a_character == '{' || a_character == '}' || a_character == '\n' || a_character == ';'))

typedef enum {
    NONE = 0,
    HEADER = 1,
    DATA = 2,
    FOOTER = 3,
} DepthType;

uint8_t LoadData(char* a_filepath, char** a_buffer) {
    FILE* file = fopen(a_filepath, "r");
    if (file == NULL) {
        return 1;
    }

    char c;
    Int32List depth;
    InitInt32List(&depth, 8);
    char* key = malloc(256);
    size_t length = 0;
    size_t allocations = 0;
    size_t stackingSize = 0;
    bool paren = false;
    a_buffer = malloc(2048);

    while((c = fgetc(file)) != EOF) {
        //printf("%c", c);
        if  (GET_VALID(c, paren)) {
            // Add \0 to the key and add to a_buffer. Also handle depth changes. TODO
            if (c == '"') {
                paren = !paren;
            }
            
            if (length > 0) {
                key[length] = '\0';
                //printf("|Stored (%s):", key);
                allocations++;
                a_buffer[allocations - 1] = malloc(strlen(key) + 1);
                memcpy(a_buffer[allocations - 1], key, strlen(key) + 1);
                //printf("[%s]:", a_buffer[allocations - 1]);
                stackingSize += strlen(key) + 1;
                //printf("%zi - %zi|", allocations, stackingSize);
            }
            length = 0;
        } else {
            key[length] = c;
            length++;
        }
    }

    /*for (size_t i = 0; i < allocations; i++) {
        printf("%zi/%zi: %s\n", i + 1, allocations, a_buffer[i]);
    }*/
    
    fclose(file);
    return 0;
}