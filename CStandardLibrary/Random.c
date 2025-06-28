#include "random.h"
#include <stdlib.h>

uint32_t RandomUniformUInt32(uint32_t a_min, uint32_t a_max) {
    uint32_t r = rand();
    const uint32_t range = a_max - a_min;
    while ((r = rand()) >= range);
    return a_min + r;
}