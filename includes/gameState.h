/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: gameState.h
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#ifndef  GAME_STATE_H
#define  GAME_STATE_H

//Includes
#include "../includes/main.h"

//Functions
gameState_t getDefaultGameState();
void newGame(appState_t * appState);
void handleGameAction(appState_t * appState);

#endif  /*GAME_STATE_H*/