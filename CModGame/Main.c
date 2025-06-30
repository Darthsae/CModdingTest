#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <CString.h>
#include <CGameAPI.h>
#include <Logging.h>
#include <time.h>
#include <CMod.h>
#include "Data.h"

typedef int8_t (__stdcall *InitModFunctionPtr)(CGameAPI*);
typedef int8_t (__stdcall *UpdateModFunctionPtr)(CGameAPI*);
typedef int8_t (__stdcall *ExitModFunctionPtr)(CGameAPI*);

const char* MODS_DIRECTORY = "Mods/";
const size_t MODS_DIRECTORY_LENGTH = 6;

const char* ASSETS_DIRECTORY = "/Assets/";
const size_t ASSETS_DIRECTORY_LENGTH = 9;

const char* DEFINITIONS_DIRECTORY = "Definitions/";
const size_t DEFINITIONS_DIRECTORY_LENGTH = 13;

const char* DATA_DIRECTORY = "Data/";
const size_t DATA_DIRECTORY_LENGTH = 6;

static void m_LoadDefinitions(CMod* a_libraries, size_t a_libraryCount, CGameAPI* a_gameAPI) {
    char* assetPath = malloc(2048);
    char* assetPathDupe = malloc(2048);
    char* assetPathDuped = malloc(2048);
    WIN32_FIND_DATA fileData;
    HANDLE fileIterator;
    memcpy(assetPath, MODS_DIRECTORY, MODS_DIRECTORY_LENGTH);
    for (size_t i = 0; i < a_libraryCount; i++) {
        size_t length = StringLen(&a_libraries[i].name) - 4;
        assetPath = realloc(assetPath, MODS_DIRECTORY_LENGTH + length + ASSETS_DIRECTORY_LENGTH + DEFINITIONS_DIRECTORY_LENGTH);
        
        assetPathDupe = realloc(assetPathDupe, MODS_DIRECTORY_LENGTH + length + ASSETS_DIRECTORY_LENGTH + DEFINITIONS_DIRECTORY_LENGTH + 260);
        memcpy(assetPath + MODS_DIRECTORY_LENGTH - 1, a_libraries[i].name.chars, length);
        
        memcpy(assetPath + MODS_DIRECTORY_LENGTH + length - 2, ASSETS_DIRECTORY, ASSETS_DIRECTORY_LENGTH);
        
        memcpy(assetPath + MODS_DIRECTORY_LENGTH + length + ASSETS_DIRECTORY_LENGTH - 3, DEFINITIONS_DIRECTORY, DEFINITIONS_DIRECTORY_LENGTH);
        memcpy(assetPathDupe, assetPath, strlen(assetPath) + 1);
        memcpy(assetPathDupe + strlen(assetPath), "*.mdef", 7);
        memcpy(assetPathDuped, assetPath, strlen(assetPath) + 1);
        memcpy(assetPathDuped + strlen(assetPath), "*.mdef", 7);
        fileIterator = FindFirstFile(assetPathDupe, &fileData);
        if (fileIterator == NULL) {
            LOG_INFO("No definitions for %s.", a_libraries[i].name.chars);
            continue;
        }

        LOG_INFO("Loading Definitions for %s", a_libraries[i].name.chars);
        do {
            memcpy(assetPathDuped + strlen(assetPath), fileData.cFileName, strlen(fileData.cFileName) + 1);
            memcpy(assetPathDuped + strlen(assetPath) + strlen(fileData.cFileName), "", 1);
            LOG_INFO("Loading Definition: %s (%s)", fileData.cFileName, assetPathDuped);
            char** buf = malloc(2048);
            LoadData(assetPathDuped, buf);
            LOG_INFO("Loaded Definition: %s", fileData.cFileName);
        } while (FindNextFile(fileIterator, &fileData));
        LOG_INFO("Finished Loading Definitions for %s\n", a_libraries[i].name.chars);
    }
    FindClose(fileIterator);
    free(assetPath);
    free(assetPathDupe);
}

static void m_LoadData(CMod* a_libraries, size_t a_libraryCount, CGameAPI* a_gameAPI) {
    for (size_t i = 0; i < a_libraryCount; i++) {
        
    }
}

static uint8_t m_InitMods(CMod* a_libraries, size_t a_libraryCount, CGameAPI* a_gameAPI) {
    for (size_t i = 0; i < a_libraryCount; i++) {
        LOG_INFO("Loading init function for %s.", a_libraries[i].name.chars);
        InitModFunctionPtr initFunction = (InitModFunctionPtr)GetProcAddress(a_libraries[i].library, "InitMod");
        if (initFunction == NULL) {
            LOG_ERROR("Failed to load init function.");
            return 1;
            //return 1;
        }
        initFunction(a_gameAPI);
    }
    
    return 0;
}

int main(int argc, char** argv) {
    #pragma region Setup
    LOG_INFO("Intitializing Game API\n");
    CGameAPI gameAPI = InitCGameAPI();
    srand(0);
    #pragma endregion

    #pragma region Loading Mods
    char* dirPath = malloc(MODS_DIRECTORY_LENGTH + 260);
    memcpy(dirPath, MODS_DIRECTORY, MODS_DIRECTORY_LENGTH);
    WIN32_FIND_DATA fileData;
    HANDLE fileIterator = FindFirstFile("Mods/*.dll", &fileData);
    CMod* libraries = (CMod*)malloc(0);
    size_t libraryCount = 0;
    if (fileIterator == NULL) {
        LOG_INFO("No mods.");
        return 1;
    }

    LOG_INFO("Loading Mods");
    do {
        memcpy(dirPath + MODS_DIRECTORY_LENGTH - 1, fileData.cFileName, strlen(fileData.cFileName) + 1);
        LOG_INFO("Loading Mod: %s", fileData.cFileName);
        libraryCount++;
        libraries = realloc(libraries, libraryCount * sizeof(CMod));
        InitString(&libraries[libraryCount - 1].name, fileData.cFileName);
        LOG_INFO("Loading Mod: %s", libraries[libraryCount - 1].name.chars);
        libraries[libraryCount - 1].library = LoadLibrary(dirPath);
        UpdateModFunctionPtr updateFunction = (UpdateModFunctionPtr)GetProcAddress(libraries[libraryCount - 1].library, "UpdateMod");
        if (updateFunction != NULL) {
            LOG_INFO("Loading an update function from %s.", fileData.cFileName);
            EventHandlerAddHook(&gameAPI.updateEventHandler, (GenericFnptr)updateFunction);
            LOG_INFO("Loaded an update function from %s.", fileData.cFileName);
        }
    } while (FindNextFile(fileIterator, &fileData));
    free(dirPath);
    FindClose(fileIterator);
    LOG_INFO("Finished Loading Mods\n");

    LOG_INFO("Loading Definitions");
    m_LoadDefinitions(libraries, libraryCount, &gameAPI);
    LOG_INFO("Finished Loading Definitions\n");

    LOG_INFO("Loading Data");
    m_LoadData(libraries, libraryCount, &gameAPI);
    LOG_INFO("Finished Loading Data\n");

    LOG_INFO("Initializing Mods");
    m_InitMods(libraries, libraryCount, &gameAPI);
    LOG_INFO("Finished Initializing Mods\n");
    #pragma endregion

    #pragma region Main Loop
    LOG_INFO("Starting Main Loop");
    
    time_t oldTime = time(NULL);
    while (gameAPI.running) {
        oldTime = time(NULL);
        RUN_EVENT_HANDLER(gameAPI.updateEventHandler, UpdateModFunctionPtr, i, &gameAPI)
        gameAPI.deltaTime = difftime(oldTime, time(NULL));
    }
    LOG_INFO("Ending Main Loop\n");
    #pragma endregion

    #pragma region Unloading Mods
    LOG_INFO("Unloading Mods");
    for (size_t i = 0; i < libraryCount; i++) {
        ExitModFunctionPtr exitFunction = (ExitModFunctionPtr)GetProcAddress(libraries[i].library, "ExitMod");
        if (exitFunction == NULL) {
            LOG_ERROR("Failed to load exit function.");
            return 1;
        }
        exitFunction(&gameAPI);
        FreeLibrary(libraries[i].library);
    }
    LOG_INFO("Finished Unloading Mods\n");
    #pragma endregion
    
    #pragma region Shutdown
    TerminateCGameAPI(&gameAPI);
    LOG_INFO("Shutting Down");
    #pragma endregion
}
