#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <CGameAPI.h>
#include <Logging.h>
#include <time.h>

typedef int8_t (__stdcall *InitModFunctionPtr)(CGameAPI*);
typedef int8_t (__stdcall *UpdateModFunctionPtr)(CGameAPI*);
typedef int8_t (__stdcall *ExitModFunctionPtr)(CGameAPI*);

const size_t MODS_DIRECTORY = 5;

static void m_LoadDefinitions(HMODULE* a_libraries, size_t a_libraryCount, CGameAPI* a_gameAPI) {
    for (size_t i = 0; i < a_libraryCount; i++) {
        
    }
}

static void m_LoadData(HMODULE* a_libraries, size_t a_libraryCount, CGameAPI* a_gameAPI) {
    for (size_t i = 0; i < a_libraryCount; i++) {
        
    }
}

static void m_InitMods(HMODULE* a_libraries, size_t a_libraryCount, CGameAPI* a_gameAPI) {
    for (size_t i = 0; i < a_libraryCount; i++) {
        InitModFunctionPtr initFunction = (InitModFunctionPtr)GetProcAddress(a_libraries[i], "InitMod");
        if (initFunction == NULL) {
            LOG_ERROR("Failed to load init function.");
            return 1;
        }
        initFunction(a_gameAPI);
    }
}

int main(int argc, char** argv) {
    #pragma region Setup
    LOG_INFO("Intitializing Game API\n");
    CGameAPI gameAPI = InitCGameAPI();
    srand(0);
    #pragma endregion

    #pragma region Loading Mods
    char* dirPath = malloc(2048);
    memcpy(dirPath, (char*)"Mods/", MODS_DIRECTORY);
    WIN32_FIND_DATA fileData;
    HANDLE fileIterator = FindFirstFile("Mods/*.dll", &fileData);
    HMODULE* libraries = (HMODULE*)malloc(0);
    size_t libraryCount = 0;
    if (fileIterator == NULL) {
        LOG_INFO("No mods.");
        return 1;
    }

    LOG_INFO("Loading Mods");
    do {
        memcpy(dirPath + MODS_DIRECTORY, fileData.cFileName, sizeof(fileData.cFileName));
        LOG_INFO("Loading Mod: %s", dirPath);
        libraryCount++;
        libraries = realloc(libraries, libraryCount * sizeof(HMODULE));
        libraries[libraryCount - 1] = LoadLibrary(dirPath);
        UpdateModFunctionPtr updateFunction = (UpdateModFunctionPtr)GetProcAddress(libraries[libraryCount - 1], "UpdateMod");
        if (updateFunction != NULL) {
            LOG_INFO("Loaded an update function from %s.", fileData.cFileName);
            EventHandlerAddHook(&gameAPI.updateEventHandler, (GenericFnptr)updateFunction);
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
        ExitModFunctionPtr exitFunction = (ExitModFunctionPtr)GetProcAddress(libraries[i], "ExitMod");
        if (exitFunction == NULL) {
            LOG_ERROR("Failed to load exit function.");
            return 1;
        }
        exitFunction(&gameAPI);
        FreeLibrary(libraries[i]);
    }
    LOG_INFO("Finished Unloading Mods\n");
    #pragma endregion
    
    #pragma region Shutdown
    TerminateCGameAPI(&gameAPI);
    LOG_INFO("Shutting Down");
    #pragma endregion
}
