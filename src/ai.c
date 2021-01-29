/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

/*---------------------------
  Variables and constants
---------------------------*/
type_gameState gameAiState = {0};

/*---------------------------
  Functions
---------------------------*/
void setAiGameState(type_gameState  newGameState){
  gameAiState = newGameState;
}

type_gameState getAiGameState(){
  return gameAiState;
}

void aiAction(){
  //modo muito facil
    //Jogada 100% aleatoria

  //modo facil
    //Verifica se vai perder - joga em casa a fim de impedir oponente de finalizar o jogo
    //Faz uma jogada aleatoria

  //modo normal
    //Verifica se vai ganhar
    //Veifica se vai perder
    //Faz jogada aleatoria

  //modo dificil
    //Verifica se vai ganhar
    //Veifica se vai perder
    //Joga no pattern onde tem mais peças suas
    //Joga aleatoriamente

  //modo muito dificil
    //Inpiração para a IA com um dificuldade maior Future use
    //https://pt.quora.com/Existe-uma-maneira-de-nunca-perder-no-Jogo-da-Velha-ou-Jogo-do-Galo#:~:text=Fa%C3%A7a%20uma%20jogada%20no%20canto,jogo%20ir%C3%A1%20terminar%20em%20empate.
    //Faz as jogadas corretas para cada situação

  unsigned char bestAiPattern[2] = {0}, bestOponnentPattern[2] = {0};//pattern, count
  int line = 0, collumn = 0;
  char currentPlayerSymbol = gameAiState.playerSymbol[gameAiState.currentPlayer];
  char anotherPlayerSymbol = gameAiState.playerSymbol[!gameAiState.currentPlayer];

  //Verifica em qual pattern tem mais peças do oponente e em qual tem mais minhas
  //Salva o numero do pattern e o valor dele
  for (int count = 0; count < 8; count++){
    char compareValue[3] = {0};
    int auxOponnent = 0, auxAi = 0;
    compareValue[0] = gameAiState.currentBoard[getHouseByPattern(count, 0, LINE)][getHouseByPattern(count, 0, COLLUMN)];
    compareValue[1] = gameAiState.currentBoard[getHouseByPattern(count, 1, LINE)][getHouseByPattern(count, 1, COLLUMN)];
    compareValue[2] = gameAiState.currentBoard[getHouseByPattern(count, 2, LINE)][getHouseByPattern(count, 2, COLLUMN)];

    for(int count2 = 0; count2 < 3; count2++){
      if(compareValue[count2] == currentPlayerSymbol){
        auxAi++;
      }
      else if(compareValue[count2] == anotherPlayerSymbol) {
        auxOponnent++;
      }
    }

    if(auxAi >= bestAiPattern[1]) {
      if(compareValue[0] == ' ' || compareValue[1] == ' ' || compareValue[2] == ' '){
        bestAiPattern[0] = count;
        bestAiPattern[1] = auxAi;
      }
    }

    if(auxOponnent >= bestOponnentPattern[1]){
      if(compareValue[0] == ' ' || compareValue[1] == ' ' || compareValue[2] == ' '){
        bestOponnentPattern[0] = count;
        bestOponnentPattern[1] = auxOponnent;
      }
    }
  }

  //Verifica se a ia esta para ganhar neste pattern
  if(bestAiPattern[1] == 2){
    //Se sim joga, na casa livre
    line = getHouseByPattern(bestAiPattern[0], 0, LINE);
    collumn = getHouseByPattern(bestAiPattern[0], 0, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn]  = currentPlayerSymbol;
      return;
    }

    line = getHouseByPattern(bestAiPattern[0], 1, LINE);
    collumn = getHouseByPattern(bestAiPattern[0], 1, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn]  = currentPlayerSymbol;
      return;
    }

    line = getHouseByPattern(bestAiPattern[0], 2, LINE);
    collumn = getHouseByPattern(bestAiPattern[0], 2, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn]  = currentPlayerSymbol;
      return;
    }
  }

  //Verifica se o oponente esta para ganhar neste pattern
  if(bestOponnentPattern[1] == 2){
    //Se sim joga, na casa livre
    line = getHouseByPattern(bestOponnentPattern[0], 0, LINE);
    collumn = getHouseByPattern(bestOponnentPattern[0], 0, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn]  = currentPlayerSymbol;
      return;
    }

    line = getHouseByPattern(bestOponnentPattern[0], 1, LINE);
    collumn = getHouseByPattern(bestOponnentPattern[0], 1, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn]  = currentPlayerSymbol;
      return;
    }

    line = getHouseByPattern(bestOponnentPattern[0], 2, LINE);
    collumn = getHouseByPattern(bestOponnentPattern[0], 2, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn]  = currentPlayerSymbol;
      return;
    }
  }

  //Verifica se a ia esta para ganhar neste pattern
  if(bestAiPattern[1] == 1){
    //Se sim joga, na casa livre
    line = getHouseByPattern(bestAiPattern[0], 0, LINE);
    collumn = getHouseByPattern(bestAiPattern[0], 0, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn]  = currentPlayerSymbol;
      return;
    }

    line = getHouseByPattern(bestAiPattern[0], 1, LINE);
    collumn = getHouseByPattern(bestAiPattern[0], 1, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn]  = currentPlayerSymbol;
      return;
    }

    line = getHouseByPattern(bestAiPattern[0], 2, LINE);
    collumn = getHouseByPattern(bestAiPattern[0], 2, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn]  = currentPlayerSymbol;
      return;
    }
  }

  while (TRUE){
    int newHouse = rand() % 9;

    line = getHouseByNumber(newHouse, LINE);
    collumn = getHouseByNumber(newHouse, COLLUMN);
    if(gameAiState.currentBoard[line][collumn] == ' '){
      gameAiState.currentBoard[line][collumn] = currentPlayerSymbol;
      
      return;
      break;
    }
  }
}