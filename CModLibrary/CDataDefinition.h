#ifndef C_DATA_DEFINITION_H
#define C_DATA_DEFINITION_H
#include <Collections/Dict.h>
#include <CString.h>
typedef struct {
    String name;
    String type;
    uint64_t hash;
} CDataDefinitionEntry;

typedef struct {
    String name;
    CDataDefinitionEntry* data;
    size_t dataEntries;
} CDataDefinition;


void InitCDataDefinitionEntry(CDataDefinitionEntry*, const char*, const char*);

void InitCDataDefinition(CDataDefinition*, const char*);

void CDataDefinitionAddEntry(CDataDefinition*, const char*, const char*);

void DestroyCDataDefinition(CDataDefinition*);
#endif