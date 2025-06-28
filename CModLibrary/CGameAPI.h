#ifndef CGameAPI_H
#define CGameAPI_H
#include <stdint.h>
#include <stdbool.h>
#include <BinaryTree.h>
#include <EventHandler.h>

/// @struct CGameAPI
/// @brief The API struct for the game.
///
/// Holds all the data related to the game, as well as being what is called by API functions to allow communication between the game and mods. 
typedef struct {
    /// @brief Whether or not the game is running.
    bool running;
    /// @brief The delta time between frames.
    double deltaTime;
    /// @brief The binary tree containing custom data.
    struct BinaryTreeNode tree;
    /// @brief 
    EventHandler updateEventHandler;
} CGameAPI;

/// @brief Create a new CGameAPI instance. 
/// @return A new CGameAPI instance.
CGameAPI InitCGameAPI(void);

/// @brief Terminates a CGameAPI instance.
/// @param a_gameAPI A pointer to the CGameAPI to terminate.
void TerminateCGameAPI(CGameAPI*);
#endif