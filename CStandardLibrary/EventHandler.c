#include "EventHandler.h"

void InitEventHandler(EventHandler* a_handler) {
    a_handler->hooks = malloc(0);
    a_handler->size = 0;
}

void EventHandlerAddHook(EventHandler* a_handler, GenericFnptr a_hook) {
    a_handler->size++;
    a_handler->hooks = realloc(a_handler->hooks, a_handler->size * sizeof(GenericFnptr));
    a_handler->hooks[a_handler->size - 1] = a_hook;
}

void DestroyEventHandler(EventHandler* a_handler) {
    free(a_handler->hooks);
    a_handler->size = 0;
}