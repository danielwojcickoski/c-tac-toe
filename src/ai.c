//Includes
#include "../include/main.h"

//Variables and constants

//Functions
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
    compareValue[0] = convertNumberToValue(victoryPatterns[count][0], ' ');
    compareValue[1] = convertNumberToValue(victoryPatterns[count][1], ' ');
    compareValue[2] = convertNumberToValue(victoryPatterns[count][2], ' ');

    if(compareValue[0] == gameState.playerSymbol[gameState.currentPlayer]){
      auxAi++;
    }
    else if(compareValue[0] == gameState.playerSymbol[!gameState.currentPlayer]) {
      auxOponnent++;
    }

    if(compareValue[1] == gameState.playerSymbol[gameState.currentPlayer]){
      auxAi++;
    }
    else if(compareValue[1] == gameState.playerSymbol[!gameState.currentPlayer]) {
      auxOponnent++;
    }

    if(compareValue[2] == gameState.playerSymbol[gameState.currentPlayer]){
      auxAi++;
    }
    else if(compareValue[2] == gameState.playerSymbol[!gameState.currentPlayer]) {
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
    if(convertNumberToValue(victoryPatterns[bestAiPattern[0]][0], ' ') == ' '){
      convertNumberToValue(victoryPatterns[bestAiPattern[0]][0], gameState.playerSymbol[gameState.currentPlayer]);
      return;
    }
    else if(convertNumberToValue(victoryPatterns[bestOponnentPattern[0]][1], ' ') == ' '){
      convertNumberToValue(victoryPatterns[bestAiPattern[0]][1], gameState.playerSymbol[gameState.currentPlayer]);
      return;
    }
    else if(convertNumberToValue(victoryPatterns[bestOponnentPattern[0]][2], ' ') == ' '){
      convertNumberToValue(victoryPatterns[bestAiPattern[0]][2], gameState.playerSymbol[gameState.currentPlayer]);
      return;
    }
  }

  //Verifica se o oponente esta para ganhar neste pattern
  if(bestOponnentPattern[1] == 2){
    //Se sim joga, na casa livre
    if(convertNumberToValue(victoryPatterns[bestOponnentPattern[0]][0], ' ') == ' '){
      convertNumberToValue(victoryPatterns[bestOponnentPattern[0]][0], gameState.playerSymbol[gameState.currentPlayer]);
      return;
    }
    else if(convertNumberToValue(victoryPatterns[bestOponnentPattern[0]][1], ' ') == ' '){
      convertNumberToValue(victoryPatterns[bestOponnentPattern[0]][1], gameState.playerSymbol[gameState.currentPlayer]);
      return;
    }
    else if(convertNumberToValue(victoryPatterns[bestOponnentPattern[0]][2], ' ') == ' '){
      convertNumberToValue(victoryPatterns[bestOponnentPattern[0]][2], gameState.playerSymbol[gameState.currentPlayer]);
      return;
    }
  }

  while (TRUE){
    int newHouse = rand() % 9;

    if(convertNumberToValue(newHouse, ' ') == ' '){
      convertNumberToValue(newHouse, gameState.playerSymbol[gameState.currentPlayer]);
      return;
      break;
    }
  }
}