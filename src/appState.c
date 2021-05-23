/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: appState.c
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 *
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#include "../includes/appState.h"
#include "../includes/gameState.h"

/*------------------------------------------------------------------------------
 * Atualiza as variaveis relativas a tela
 *----------------------------------------------------------------------------*/
void changeScreenState(appState_t * appState, int screen, int menuState, int forceClear){
  if(screen != NO_CHANGE){
    appState->screen.lastScreen = appState->screen.currentScreen;
    appState->screen.currentScreen = screen;
  }
  if(menuState != NO_CHANGE){
    appState->screen.menuState = menuState;
  }
  if(forceClear != NO_CHANGE){
    appState->screen.forceClear = forceClear;
  }
}

/*------------------------------------------------------------------------------
 * Retorna o appState default
 *----------------------------------------------------------------------------*/
appState_t getDefaultAppState(){
  appState_t defaultAppState = {0};

  //Variaveis de controle do app
  defaultAppState.appStatus = STATUS_RUNNING;

  //Variaveis de controle do jogo
  defaultAppState.gameState = getDefaultGameState();

  //Variaveis de controle da tela
  defaultAppState.screen.lastScreen = SCREEN_NONE;
  defaultAppState.screen.currentScreen = SCREEN_MENU;
  defaultAppState.screen.menuState = STATE_MENU_FIRST + 1;

  return defaultAppState;
}

/*------------------------------------------------------------------------------
 * Retorna um novo appState com base na ação realizada na tela de menu
 *----------------------------------------------------------------------------*/
void handleMenuAction(appState_t * appState){
  switch (appState->userAction){
    case ACTION_UP:
      appState->screen.menuState = (appState->screen.menuState - 1 == STATE_MENU_FIRST) ? STATE_MENU_LAST - 1 : appState->screen.menuState - 1;
      break;

    case ACTION_DOWN:
      appState->screen.menuState = (appState->screen.menuState + 1 == STATE_MENU_LAST) ? STATE_MENU_FIRST + 1 : appState->screen.menuState + 1;
      break;

    case ACTION_ENTER:
      switch (appState->screen.menuState){
        case STATE_MENU_PVP:
          break;

        case STATE_MENU_PVC:
          break;

        case STATE_MENU_CVC:
          break;

        case STATE_MENU_EXIT:
          appState->appStatus = STATUS_OK;
          break;

        default:break;
      }
      break;

    case ACTION_ESCAPE:
      appState->appStatus = STATUS_OK;
      break;

    default: break;
  }
}

/*------------------------------------------------------------------------------
 * Retorna um novo appState com base na ação realizada no appState atual
 *----------------------------------------------------------------------------*/
void handleUserAction(appState_t * appState){
  if(appState->userAction != ACTION_NONE){
    appState->screen.lastScreen = appState->screen.currentScreen;
    switch (appState->screen.currentScreen){
      case SCREEN_MENU:
        handleMenuAction(appState);
        break;

      case SCREEN_GAME:
        switch (appState->userAction){


          default: break;
        }
        break;

      case SCREEN_ENDGAME:
        changeScreenState(appState, SCREEN_MENU, NO_CHANGE, NO_CHANGE);
        break;

      default:
        changeScreenState(appState, SCREEN_MENU, NO_CHANGE, NO_CHANGE);
        break;
    }
  }
}
