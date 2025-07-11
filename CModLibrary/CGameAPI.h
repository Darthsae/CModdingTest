#ifndef C_GAME_API_H
#define C_GAME_API_H
#include <stdint.h>
#include <stdbool.h>
#include <Collections/BinaryTree.h>
#include <EventHandler.h>
#include <Collections/Dict.h>
#include <CDataDefinition.h>

/// @struct CGameAPI
/// @brief The API struct for the game.
///
/// Holds all the data related to the game, as well as being what is called by API functions to allow communication between the game and mods. 
typedef struct {
    /// @brief Whether or not the game is running.
    bool running;
    /// @brief The delta time between frames.
    double deltaTime;
    /// @brief The @c BinaryTreeNode containing custom data.
    BinaryTreeNode tree;
    /// @brief The @c EventHandler for updates.
    EventHandler updateEventHandler;
    /// @brief The @c Dict holding the @c CDataDefinition's that are initialized.
    Dict* definitions;
} CGameAPI;

/// @brief Create a new CGameAPI instance. 
/// @return A new CGameAPI instance.
CGameAPI InitCGameAPI(void);



/// @brief Terminates a CGameAPI instance.
/// @param[in] a_gameAPI A pointer to the CGameAPI to terminate.
void TerminateCGameAPI(CGameAPI*);
#endif