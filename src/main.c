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
  //Definição estrutura principal, gameState
  appState_t appState = getDefaultAppState();

  //Mantem rodando enquanto o appStatus for STATUS_RUNNING
  do{
    //Printa tela com base no appState
    printAppState(&appState);

    //Captura ação do usuario e salva em gameState.userAction
    captureUserAction(&appState);

    //Retorna um novo appState com base na ação do usuario
    handleUserAction(&appState);
  } while(appState.appStatus == STATUS_RUNNING);

  //Retorna appStatus
  return appState.appStatus;
}
