cmake_minimum_required(VERSION 3.10.0)
project(CModTest VERSION 0.1.0 LANGUAGES C)

#configure_file(<input> <output> COPYONLY)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
#set(BUILD_SHARED_LIBS TRUE)
#set(PRECOMPILE_HEADERS TRUE)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(__DEBUG_ASSERTS__)
endif()

file(GLOB_RECURSE CStandardLibrarySourceFiles "CStandardLibrary/*.c" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE CStandardLibraryHeaderFiles "CStandardLibrary/*.h" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE CModLibrarySourceFiles "CModLibrary/*.c" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE CModLibraryHeaderFiles "CModLibrary/*.h" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE CModGameSourceFiles "CModGame/*.c" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE CModGameHeaderFiles "CModGame/*.h" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE ExampleCModSourceFiles "ExampleCMod/*.c" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE ExampleCModHeaderFiles "ExampleCMod/*.h" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE ExampleCModAssetFiles RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/ExampleCMod" "${CMAKE_CURRENT_SOURCE_DIR}/ExampleCMod/Assets/**/*" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE SecondCModSourceFiles "SecondCMod/*.c" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE SecondCModHeaderFiles "SecondCMod/*.h" CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE SecondCModAssetFiles RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/SecondCMod" "${CMAKE_CURRENT_SOURCE_DIR}/SecondCMod/Assets/**/*" CMAKE_CONFIGURE_DEPENDS)

add_library(CStandardLibrary STATIC ${CStandardLibrarySourceFiles} ${CStandardLibraryHeaderFiles})
target_include_directories(CStandardLibrary PUBLIC "CStandardLibrary")
target_link_directories(CStandardLibrary PUBLIC "CStandardLibrary")
source_group(
  TREE "${PROJECT_SOURCE_DIR}/CStandardLibrary"
  PREFIX "Header Files"
  FILES ${CStandardLibraryHeaderFiles})

set_target_properties(CStandardLibrary PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Lib"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Lib"
    PDB_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Lib"
    PDB_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Lib"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Lib"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Lib"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Lib"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Lib"
)

add_library(CModLibrary STATIC ${CModLibrarySourceFiles} ${CModLibraryHeaderFiles})
target_link_libraries(CModLibrary PRIVATE CStandardLibrary)
target_include_directories(CModLibrary PUBLIC "CModLibrary")
target_link_directories(CModLibrary PUBLIC "CModLibrary")
source_group(
  TREE "${PROJECT_SOURCE_DIR}/CModLibrary"
  PREFIX "Header Files"
  FILES ${CModLibraryHeaderFiles})

set_target_properties(CModLibrary PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Lib"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Lib"
    PDB_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Lib"
    PDB_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Lib"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Lib"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Lib"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Lib"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Lib"
)

add_library(ExampleCMod SHARED ${ExampleCModSourceFiles} ${ExampleCModHeaderFiles})

target_link_libraries(ExampleCMod PRIVATE CModLibrary CStandardLibrary)

set_target_properties(ExampleCMod PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Mods"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Mods"
    PDB_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Mods"
    PDB_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Mods"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Mods"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Mods"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Mods"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Mods"
)

foreach(ExampleCModAssetFile IN LISTS ExampleCModAssetFiles)
    message(STATUS ${ExampleCModAssetFile})
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/ExampleCMod/${ExampleCModAssetFile}" "${CMAKE_BINARY_DIR}/Debug/Mods/ExampleCMod/${ExampleCModAssetFile}")
endforeach(ExampleCModAssetFile)

add_library(SecondCMod SHARED ${SecondCModSourceFiles} ${SecondCModHeaderFiles})

target_link_libraries(SecondCMod PRIVATE CModLibrary CStandardLibrary)

set_target_properties(SecondCMod PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Mods"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Mods"
    PDB_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Mods"
    PDB_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Mods"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Mods"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Mods"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/Mods"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/Mods"
)

foreach(SecondCModAssetFile IN LISTS SecondCModAssetFiles)
    message(STATUS ${SecondCModAssetFile})
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/SecondCMod/${SecondCModAssetFile}" "${CMAKE_BINARY_DIR}/Debug/Mods/SecondCMod/${SecondCModAssetFile}")
endforeach(SecondCModAssetFile)

add_executable(CModGame ${CModGameSourceFiles} ${CModGameHeaderFiles})

target_link_libraries(CModGame PRIVATE CModLibrary CStandardLibrary)

set_target_properties(CModGame PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
    PDB_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    PDB_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
)