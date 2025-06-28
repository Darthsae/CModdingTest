#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H
#include <Windows.h>
#include <stdint.h>
typedef void* (*GenericFnptr)(void*);

typedef struct {
    GenericFnptr* hooks;
    size_t size;
} EventHandler;

void InitEventHandler(EventHandler* a_handler);

void EventHandlerAddHook(EventHandler* a_handler, GenericFnptr a_hook);

void DestroyEventHandler(EventHandler* a_handler);

#define RUN_EVENT_HANDLER(a_handler, a_castTo, a_iterName, ...)\
for (int a_iterName = 0; a_iterName < a_handler.size; a_iterName++) {\
    ((a_castTo)a_handler.hooks[a_iterName])(__VA_ARGS__);\
}
#endif