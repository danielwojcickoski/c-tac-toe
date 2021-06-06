/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: main.h
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#ifndef  MAIN_H
#define  MAIN_H

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <pthread.h>
#include <windows.h>
#include "creact.h"

//Constants
#define FALSE 0
#define TRUE  1
#define NO_CHANGE -2

//Screen constants
#define DEFAULT_BG_COLOR BLACK
#define DEFAULT_TEXT_COLOR LIGHTGRAY

#define WIDTH_BUTTON_INGAME 14
#define WIDTH_BUTTON_MENU 16
#define WIDTH_MENU_SELECTOR 3

#define MENU_LOGO_LINES 7
#define MENU_LOGO_COLUMNS 9

#define GAME_CARD_WIDTH 12
#define GAME_CARD_HEIGHT 7

#define DEFAULT_SCREEN_TITLE L"TicTacToeC"
#define DEFAULT_SCREEN_X_SIZE 75
#define DEFAULT_SCREEN_Y_SIZE 27

typedef unsigned char bool; //Variavel Booleana, deve receber TRUE ou FALSE

//Macros
#define SET_COLOR(BG, TEXT) cr_setColors(BG, TEXT); 

//Enums
typedef enum appStatus {
  STATUS_OK = 0,
  STATUS_ERROR,
  STATUS_RUNNING,
} appStatus_e;

typedef enum keys{
  KEY_ENTER = 13,
  KEY_ESCAPE = 27,
  KEY_SPACE = 32,

  KEY_NUM1 = 49,
  KEY_NUM2,
  KEY_NUM3,
  KEY_NUM4,
  KEY_NUM5,
  KEY_NUM6,
  KEY_NUM7,
  KEY_NUM8,
  KEY_NUM9,

  KEY_UP = 72,
  KEY_DOWN = 80,
} keys_e;

typedef enum userAction {
  ACTION_NONE = 0,

  ACTION_UP,
  ACTION_DOWN,
  ACTION_ENTER,

  ACTION_ESCAPE,

  ACTION_0_0,
  ACTION_0_1,
  ACTION_0_2,
  ACTION_1_0,
  ACTION_1_1,
  ACTION_1_2,
  ACTION_2_0,
  ACTION_2_1,
  ACTION_2_2,
} userAction_e;

typedef enum gameStatus{
  GAME_RUNNING = 0,
  GAME_TOE,
  GAME_WIN_P1,
  GAME_WIN_P2,
} gameStatus_e;

typedef enum ursorState {
  CURSOR_HIDDEN = 0,
  CURSOR_VISIBLE,
} cursorState_e;

typedef enum screens {
  SCREEN_NONE = -1,
  SCREEN_MENU = 0,
  SCREEN_GAME,
  SCREEN_ENDGAME,
} screens_e;

typedef enum menuState{
  STATE_MENU_FIRST = 0,
  STATE_MENU_PVP,
  STATE_MENU_PVC,
  STATE_MENU_CVC,
  STATE_MENU_EXIT,
  STATE_MENU_LAST,
} menuState_e;

//Types
typedef struct gameCard {
  int value;
  char symbol;
  COLORS color;
} gamePiece_t;

typedef struct gameState {
  gameStatus_e gameStatus;         

  gamePiece_t gamePieces[3];        
  gamePiece_t * gameBoard[3][3];     
} gameState_t;

typedef struct screenState {
  screens_e lastScreen;    
  screens_e currentScreen; 
  menuState_e menuState;   

  bool forceClear;            
} screenState_t;

typedef struct appState {
  appStatus_e appStatus;
  userAction_e userAction;
  gameState_t gameState;
  screenState_t screen;
} appState_t;

#endif  /*MAIN_H*/
