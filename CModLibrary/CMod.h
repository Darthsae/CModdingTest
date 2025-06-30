#ifndef C_MOD_H
#define C_MOD_H
#include <Windows.h>
#include <CString.h>

typedef struct {
    String name;
    HMODULE library;
} CMod;
#endif