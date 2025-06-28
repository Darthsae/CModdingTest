#include "Mod.h"
#include <stdint.h>
#include <Windows.h>
#include <stdio.h>
#include <CGameAPI.h>
#include <BinaryTree.h>
#include <CString.h>
#include <Logging.h>
#include <stdlib.h>
#include <Random.h>

__declspec(dllexport) int8_t InitMod(CGameAPI* a_gameAPI) {
    LOG_INFO("%s loaded.", MOD_NAME);
    return 0;
}

__declspec(dllexport) int8_t UpdateMod(CGameAPI* a_gameAPI) {
    if (RandomUniformUInt32(0, 15) > 12) {
        LOG_INFO("Hello from Second Mod.");
    } else {
        LOG_INFO("Salves from Second Mod.");
    }
    return 0;
}

__declspec(dllexport) int8_t ExitMod(CGameAPI* a_gameAPI) {
    LOG_INFO("%s unloaded.", MOD_NAME);
    LOG_INFO("%i", *(uint32_t*)BinaryTreeQuery(&a_gameAPI->tree, HashCharArray((char*)"aa")));
    return 0;
}
