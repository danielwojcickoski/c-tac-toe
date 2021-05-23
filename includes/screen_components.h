/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: screen_components.h
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#ifndef  SCREEN_COMPONENTS_H
#define  SCREEN_COMPONENTS_H

//Includes
#include "../includes/main.h"

//Functions
void print_menuButton(char * placeholder, int posX, int posY, bool selected);
void print_gameBoard(gameState_t * gameState, int posX, int posY);
void print_endGameStatus(gameStatus_e status, int posX, int posY);

#endif  /*SCREEN_COMPONENTS_H*/