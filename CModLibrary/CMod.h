#ifndef CMOD_H
#define CMOD_H
#include <Windows.h>
#include <CString.h>

typedef struct {
    String name;
    HMODULE library;
} CMod;
#endif