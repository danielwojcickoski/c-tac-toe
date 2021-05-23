/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: gameState.c
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#include "../includes/gameState.h"

/*------------------------------------------------------------------------------
 * Retorna o gameState default
 *----------------------------------------------------------------------------*/
gameState_t getDefaultGameState(){
  gameState_t defaultGameState = {0};

  COLORS gamePieceColors[3] = {BLACK, RED, BLUE};

  defaultGameState.gameStatus = GAME_RUNNING;

  //Alocando estrutura das peças
  defaultGameState.gamePieces[0].symbol = ' ';
  defaultGameState.gamePieces[1].symbol = 'X';
  defaultGameState.gamePieces[2].symbol = 'O';
  for(int piece = 0; piece < 3; piece++){
    defaultGameState.gamePieces[piece].value = piece;
    defaultGameState.gamePieces[piece].color = gamePieceColors[piece];
  }

  //Zerando tabuleiro de jogo
  for(int line = 0; line < 3; line++){
     for(int collumn = 0; collumn < 3; collumn++){
      defaultGameState.gameBoard[line][collumn] = NULL;
    }
  }

  return defaultGameState;
}

/*------------------------------------------------------------------------------
 * Verifica se o tabuleiro de jogo atual possui alguma casa livre
 *
 * Retorna TRUE caso tenha pelo menos uma casa livre
 * Retorna FALSE caso não tenha nenhuma casa livre
 *----------------------------------------------------------------------------*/
bool verifyFreeHouse(gameState_t * gameState){
  for(int line = 0; line < 3; line++){
    for(int collumn = 0; collumn < 3; collumn++){
      if(gameState->gameBoard[line][collumn] == NULL){
        return TRUE;
      }
    }
  }

  return FALSE;
}

/*------------------------------------------------------------------------------
 * Inicia um novo jogo, resetando todas as variaveis para seu estado inicial
 *----------------------------------------------------------------------------*/
void newGame(appState_t * appState){
  //Seta o estado default inicial do jogo
  appState->gameState = getDefaultGameState();

  //Redireciona para a tela de jogo
  appState->screen.currentScreen = SCREEN_GAME;
}

/*------------------------------------------------------------------------------
 * Verifica se o jogador ganhou, completou uma linha
 *
 * Retorna TRUE caso o jogador tenha ganhado
 * Retorna FALSE caso o jogador ainda não tenha ganhado
 *----------------------------------------------------------------------------*/
bool verifyPlayerWin(appState_t * appState){

  return FALSE;
}

/*------------------------------------------------------------------------------
 * Altera o appState com base na ação realizada dentro do jogo
 *----------------------------------------------------------------------------*/
void handleGameAction(appState_t * appState){
  
}