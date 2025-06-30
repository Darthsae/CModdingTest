#ifndef RANDOM_H
#define RANDOM_H
#include <stdint.h>

/// @brief Generate a random @c uint32_t between @p a_min and @p a_max.
/// @param[in] a_min The minimum size of the number.
/// @param[in] a_max The maximum size of the number.
/// @return A random @c uint32_t between @p a_min and @p a_max.
uint32_t RandomUniformUInt32(uint32_t, uint32_t);
#endif