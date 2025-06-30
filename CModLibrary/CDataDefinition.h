#ifndef C_DATA_DEFINITION_H
#define C_DATA_DEFINITION_H
#include <Collections/Dict.h>
#include <CString.h>

/// @struct CDataDefinitionEntry
/// @brief An entry for a @c CDataDefinition.
///
/// An entry for a @c CDataDefinition, has a name, type, and a hash.
typedef struct {
    /// @brief The name of the @c CDataDefinitionEntry.
    String name;
    /// @brief The type of the @c CDataDefinitionEntry.
    String type;
    /// @brief The hash of the @c CDataDefinitionEntry.
    uint64_t hash;
} CDataDefinitionEntry;

/// @struct CDataDefinition
/// @brief A data holder for definitions.
///
/// A data holder for definitions, has a name, and list of entries.
typedef struct {
    /// @brief The name of the @c CDataDefinition.
    String name;
    /// @brief The data entries of the @c CDataDefinition.
    CDataDefinitionEntry* data;
    /// @brief The number of data entries in the @c CDataDefinition.
    size_t dataEntries;
} CDataDefinition;

/// @brief Initializes a @c CDataDefinitionEntry with @p a_name and @p a_type.
/// @param[out] a_dataDefinitionEntry The @c CDataDefinitionEntry to initialize.
/// @param[in] a_name The name of the @c CDataDefinitionEntry.
/// @param[in] a_type The type of the @c CDataDefinitionEntry.
void InitCDataDefinitionEntry(CDataDefinitionEntry*, const char*, const char*);

/// @brief Initializes a @c CDataDefinition with @p a_name.
/// @param[out] a_dataDefinition The @c CDataDefinition to initialize.
/// @param[in] a_name The name of the @c CDataDefinition.
void InitCDataDefinition(CDataDefinition*, const char*);

/// @brief Adds an entry to a @c CDataDefinition.
/// @param[in,out] a_dataDefinition The @c CDataDefinition to add an entry to.
/// @param[in] a_name The name of the @c CDataDefinitionEntry.
/// @param[in] a_type The type of the @c CDataDefinitionEntry.
void CDataDefinitionAddEntry(CDataDefinition*, const char*, const char*);

/// @brief Destroys a @c CDataDefinition.
/// @param[in] a_dataDefinition The @c CDataDefinition to destroy. 
void DestroyCDataDefinition(CDataDefinition*);
#endif