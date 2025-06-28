#include "CGameAPI.h"

CGameAPI InitCGameAPI(void) {
    CGameAPI gameAPI;
    gameAPI.running = true;
    gameAPI.deltaTime = 0;
    InitBinaryTree(&gameAPI.tree);
    InitEventHandler(&gameAPI.updateEventHandler);
    return gameAPI;
}

void TerminateCGameAPI(CGameAPI* a_gameAPI) {
    DestroyBinaryTree(&a_gameAPI->tree);
    DestroyEventHandler(&a_gameAPI->updateEventHandler);
}