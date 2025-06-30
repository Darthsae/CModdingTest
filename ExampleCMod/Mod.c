#include "Mod.h"
#include <Windows.h>
#include <stdio.h>
#include <CGameAPI.h>
#include <Collections/BinaryTree.h>
#include <Logging.h>
#include <stdlib.h>
#include <Random.h>
#include <CString.h>

__declspec(dllexport) int8_t InitMod(CGameAPI* a_gameAPI) {
    LOG_INFO("%s loaded.", MOD_NAME);
    uint32_t* valToSave = malloc(sizeof(uint32_t));
    *valToSave = 120;
    BinaryTreeInsert(&a_gameAPI->tree, HashCharArray((char*)"aa"), (void*)valToSave);
    return 0;
}

__declspec(dllexport) int8_t UpdateMod(CGameAPI* a_gameAPI) {
    Largo++;
    if (RandomUniformUInt32(0, 15) > 12) {
        a_gameAPI->running = false;
    } else {
        LOG_INFO("No crash for %I64i", Largo);
    }
    return 0;
}

__declspec(dllexport) int8_t ExitMod(CGameAPI* a_gameAPI) {
    LOG_INFO("%s unloaded.", MOD_NAME);
    LOG_INFO("%i", *(uint32_t*)BinaryTreeQuery(&a_gameAPI->tree, HashCharArray((char*)"aa")));
    return 0;
}
