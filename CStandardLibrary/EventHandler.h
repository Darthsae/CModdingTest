#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H
#include <Windows.h>
#include <stdint.h>
typedef void* (*GenericFnptr)(void*);

/// @struct EventHandler
/// @brief Holds an array of hooks.
///
/// Holds an array of hooks which can be called using the RUN_EVENT_HANDLER macro.
typedef struct {
    /// @brief The array of hooks.
    GenericFnptr* hooks;
    /// @brief The number of hooks.
    size_t size;
} EventHandler;

/// @brief Intialize an @c EventHandler.
/// @param[out] a_handler The @c EventHandler to initialize.
void InitEventHandler(EventHandler* a_handler);

/// @brief Add a hook to an @c EventHandler.
/// @param[in,out] a_handler The @c EventHandler to add the hook to.
/// @param[in] a_hook The hook to add to the @c EventHandler.
void EventHandlerAddHook(EventHandler* a_handler, GenericFnptr a_hook);

/// @brief Destroy and @c EventHandler.
/// @param[in] a_handler The @c EventHandler to destroy.
void DestroyEventHandler(EventHandler* a_handler);

/// @brief Runs an event handler.
/// @param[in] a_handler The @c EventHandler to run.
/// @param[in] a_castTo The function pointer to cast too.
/// @param[in] a_iterName The name of the iterator variable in the loop.
#define RUN_EVENT_HANDLER(a_handler, a_castTo, a_iterName, ...)\
for (int a_iterName = 0; a_iterName < a_handler.size; a_iterName++) {\
    ((a_castTo)a_handler.hooks[a_iterName])(__VA_ARGS__);\
}
#endif