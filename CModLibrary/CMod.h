#ifndef C_MOD_H
#define C_MOD_H
#include <Windows.h>
#include <CString.h>

/// @struct CMod
/// @brief A mod with a name and library.
typedef struct {
    /// @brief The name of the @c CMod.
    String name;
    /// @brief The library of the @c CMod.
    HMODULE library;
} CMod;
#endif