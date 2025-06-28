#include "Data.h"

uint8_t LoadData(char* a_filepath, char** a_buffer) {
    FILE* file = fopen(a_filepath, "r");
    if (file == NULL) {
        return 1;
    }
    fseek(file, 0, SEEK_END);
    uint64_t length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char c;

    while(c = fgetc(file)) {
        printf(c);
    }
    
    fclose(file);
}