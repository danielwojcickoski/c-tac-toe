/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: controls.c
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#include "../includes/controls.h"

//Macros
#define CASE_SELECT(key, action) { \
  case key: \
    userAction = action; \
    break; \
}
#define CASE_DEFAULT(action) { \
  default: \
    userAction = action; \
    break; \
}
#define GETCH_UPPER() { \
  keyPressed = getch(); \
  if(isalpha(keyPressed)) \
    keyPressed = toupper(keyPressed); \
}

/*------------------------------------------------------------------------------
 * Captura e retorna a ação realizada pelo usuario
 *----------------------------------------------------------------------------*/
void captureUserAction(appState_t * appState){
  userAction_e userAction = 0;
  int keyPressed = 0;

  GETCH_UPPER();

  //Captura a ação com base na tela atual
  switch (appState->screen.currentScreen){
    case SCREEN_MENU:
      switch (keyPressed){
        CASE_SELECT(KEY_UP, ACTION_UP);
        CASE_SELECT(KEY_DOWN, ACTION_DOWN);
        CASE_SELECT(KEY_ENTER, ACTION_ENTER);
        CASE_SELECT(KEY_ESCAPE, ACTION_ESCAPE);
        default: break;
      }
      break;
      
    case SCREEN_GAME:
      
      break;
    
    CASE_DEFAULT(ACTION_ESCAPE);
  }

  appState->userAction = userAction;
  return;
}