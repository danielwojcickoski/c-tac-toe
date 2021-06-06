/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: main.c
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#include "../includes/main.h"
#include "../includes/screen.h"
#include "../includes/controls.h"
#include "../includes/appState.h"

/*------------------------------------------------------------------------------
 * Loop principal da aplicação
 *----------------------------------------------------------------------------*/
int main(){
  pthread_t tId;
  appState_t appState = getDefaultAppState();

  pthread_create(&tId, NULL, screenThread, (void *)&tId);

  do{
    updateScreenState(&appState);
    appState.screen.lastScreen = appState.screen.currentScreen;
    appState.screen.forceClear = FALSE;

    captureUserAction(&appState);

    handleUserAction(&appState);
  } while(appState.appStatus == STATUS_RUNNING);

  return appState.appStatus;
}
