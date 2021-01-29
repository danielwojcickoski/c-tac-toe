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


char aiConvertNumberToValue(unsigned char house, char newValue){
    switch (house){
      case 0:
        if(newValue != ' '){
          gameAiState.currentBoard[0][0] = newValue;
          return ' ';
        }
        return gameAiState.currentBoard[0][0];
        break;

      case 1:
        if(newValue != ' '){
          gameAiState.currentBoard[0][1] = newValue;
          return ' ';
        }
        return gameAiState.currentBoard[0][1];
        break;

      case 2:
        if(newValue != ' '){
          gameAiState.currentBoard[0][2] = newValue;
          return ' ';
        }
        return gameAiState.currentBoard[0][2];
        break;

      case 3:
        if(newValue != ' '){
          gameAiState.currentBoard[1][0] = newValue;
          return ' ';
        }
        return gameAiState.currentBoard[1][0];
        break;

      case 4:
        if(newValue != ' '){
          gameAiState.currentBoard[1][1] = newValue;
          return ' ';
        }
        return gameAiState.currentBoard[1][1];
        break;
        
      case 5:
        if(newValue != ' '){
          gameAiState.currentBoard[1][2] = newValue;
          return ' ';
        }
        return gameAiState.currentBoard[1][2];
        break;

      case 6:
        if(newValue != ' '){
          gameAiState.currentBoard[2][0] = newValue;
          return ' ';
        }
        return gameAiState.currentBoard[2][0];
        break;

      case 7:
        if(newValue != ' '){
          gameAiState.currentBoard[2][1] = newValue;
          return ' ';
        }
        return gameAiState.currentBoard[2][1];
        break;

      case 8:
        if(newValue != ' '){
          gameAiState.currentBoard[2][2] = newValue;
          return ' ';
        }
        return gameAiState.currentBoard[2][2];
        break;
    }
  return ' ';
}

void aiAction(){
  //Inpiração para a IA com um dificuldade maior Future use
  //https://pt.quora.com/Existe-uma-maneira-de-nunca-perder-no-Jogo-da-Velha-ou-Jogo-do-Galo#:~:text=Fa%C3%A7a%20uma%20jogada%20no%20canto,jogo%20ir%C3%A1%20terminar%20em%20empate.

  unsigned char bestOponnentPattern[2] = {0};//pattern, count
  unsigned char bestAiPattern[2] = {0};//pattern, count

  //Verifica em qual pattern tem mais peças do oponente e em qual tem mais minhas
  //Salva o numero do pattern e o valor dele
  for (int count = 0; count < 8; count++){
    char compareValue[3] = {' '};
    int auxOponnent = 0, auxAi = 0;
    compareValue[0] = aiConvertNumberToValue(victoryPatterns[count][0], ' ');
    compareValue[1] = aiConvertNumberToValue(victoryPatterns[count][1], ' ');
    compareValue[2] = aiConvertNumberToValue(victoryPatterns[count][2], ' ');

    if(compareValue[0] == gameAiState.playerSymbol[gameAiState.currentPlayer]){
      auxAi++;
    }
    else if(compareValue[0] == gameAiState.playerSymbol[!gameAiState.currentPlayer]) {
      auxOponnent++;
    }

    if(compareValue[1] == gameAiState.playerSymbol[gameAiState.currentPlayer]){
      auxAi++;
    }
    else if(compareValue[1] == gameAiState.playerSymbol[!gameAiState.currentPlayer]) {
      auxOponnent++;
    }

    if(compareValue[2] == gameAiState.playerSymbol[gameAiState.currentPlayer]){
      auxAi++;
    }
    else if(compareValue[2] == gameAiState.playerSymbol[!gameAiState.currentPlayer]) {
      auxOponnent++;
    }

    if(auxAi >= bestAiPattern[1]) {
      bestAiPattern[0] = count;
      bestAiPattern[1] = auxAi;
    }

    if(auxOponnent >= bestOponnentPattern[1]){
      bestOponnentPattern[0] = count;
      bestOponnentPattern[1] = auxOponnent;
    }
  }

  //Verifica se a ia esta para ganhar neste pattern
  if(bestAiPattern[1] == 2){
    //Se sim joga, na casa livre
    if(aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][0], ' ') == ' '){
      aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][0], gameAiState.playerSymbol[gameAiState.currentPlayer]);
      printf("Best i pat 1");
      getch();
      return;
    }
    else if(aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][1], ' ') == ' '){
      aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][1], gameAiState.playerSymbol[gameAiState.currentPlayer]);
      printf("Best i pat 2");
      getch();
      return;
    }
    else if(aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][2], ' ') == ' '){
      aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][2], gameAiState.playerSymbol[gameAiState.currentPlayer]);
      printf("Best i pat 3");
      getch();
      return;
    }
  }

  //Verifica se o oponente esta para ganhar neste pattern
  if(bestOponnentPattern[1] == 2){
    //Se sim joga, na casa livre
    if(aiConvertNumberToValue(victoryPatterns[bestOponnentPattern[0]][0], ' ') == ' '){
      aiConvertNumberToValue(victoryPatterns[bestOponnentPattern[0]][0], gameAiState.playerSymbol[gameAiState.currentPlayer]);
      printf("Best o pat 1");
      getch();
      return;
    }
    else if(aiConvertNumberToValue(victoryPatterns[bestOponnentPattern[0]][1], ' ') == ' '){
      aiConvertNumberToValue(victoryPatterns[bestOponnentPattern[0]][1], gameAiState.playerSymbol[gameAiState.currentPlayer]);
      printf("Best o pat 2");
      getch();
      return;
    }
    else if(aiConvertNumberToValue(victoryPatterns[bestOponnentPattern[0]][2], ' ') == ' '){
      aiConvertNumberToValue(victoryPatterns[bestOponnentPattern[0]][2], gameAiState.playerSymbol[gameAiState.currentPlayer]);
      printf("Best o pat 3 = %d, victoryPattern = %d, symbol = %c", bestOponnentPattern[0],victoryPatterns[bestOponnentPattern[0]][2],gameAiState.playerSymbol[gameAiState.currentPlayer]);
      getch();
      return;
    }
  }

  //Verifica se a ia esta para ganhar neste pattern
  if(bestAiPattern[1] == 1){
    //Se sim joga, na casa livre
    if(aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][0], ' ') == ' '){
      aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][0], gameAiState.playerSymbol[gameAiState.currentPlayer]);
      printf("Best i pat 4");
      getch();
      return;
    }
    else if(aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][1], ' ') == ' '){
      aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][1], gameAiState.playerSymbol[gameAiState.currentPlayer]);
      printf("Best i pat 5");
      return;
    }
    else if(aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][2], ' ') == ' '){
      aiConvertNumberToValue(victoryPatterns[bestAiPattern[0]][2], gameAiState.playerSymbol[gameAiState.currentPlayer]);
      printf("Best i pat 6");
      getch();
      return;
    }
  }

  while (TRUE){
    int newHouse = rand() % 9;

    if(aiConvertNumberToValue(newHouse, ' ') == ' '){
      aiConvertNumberToValue(newHouse, gameAiState.playerSymbol[gameAiState.currentPlayer]);
      
      printf("JOguei no rand");
      getch();
      return;
      break;
    }
  }

  printf("não fiz nada");
  getch();
}