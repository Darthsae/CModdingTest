#include <CDataDefinition.h>

void InitCDataDefinitionEntry(CDataDefinitionEntry* a_dataDefinitionEntry, const char* a_name, const char* a_type) {
    InitString(&a_dataDefinitionEntry->name, a_name);
    InitString(&a_dataDefinitionEntry->type, a_type);
    a_dataDefinitionEntry->hash = HashString(&a_dataDefinitionEntry->name);
}

void InitCDataDefinition(CDataDefinition* a_dataDefinition, const char* a_name) {
    a_dataDefinition->dataEntries = 0;
    a_dataDefinition->data = malloc(0);
    InitString(&a_dataDefinition->name, a_name);
}

void CDataDefinitionAddEntry(CDataDefinition* a_dataDefinition, const char* a_name, const char* a_type) {
    a_dataDefinition->dataEntries++;
    a_dataDefinition->data = realloc(a_dataDefinition->data, a_dataDefinition->dataEntries * sizeof(CDataDefinitionEntry));
    InitCDataDefinitionEntry(&a_dataDefinition->data[a_dataDefinition->dataEntries - 1], a_name, a_type);
}

void DestroyCDataDefinition(CDataDefinition* a_dataDefinition) {
    free(a_dataDefinition->data);
    ClearString(&a_dataDefinition->name);
}