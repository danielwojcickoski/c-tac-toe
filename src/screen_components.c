/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: screen_components.c
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#include "../includes/screen_components.h"

/*------------------------------------------------------------------------------
 * Retorna a string centralizada, com base no tamanho informado
 *----------------------------------------------------------------------------*/
void stringCentrilize(char * string, int maxSize){
  int stringSize = strlen(string);
  char preSpaces[100] = {'\0'};
  char posSpaces[100] = {'\0'};
  char newString[100] = {'\0'};

  int qtdPreSpaces = (maxSize - stringSize) / 2;
  int qtdPosSpaces = (maxSize - stringSize - qtdPreSpaces);

  for(int count = 0; count < qtdPreSpaces ; count++){
    preSpaces[count] = ' ';
  }
  for(int count = 0; count < qtdPosSpaces; count++){
    posSpaces[count] = ' ';
  }

  strcat(newString, preSpaces);
  strcat(newString, string);
  strcat(newString, posSpaces);

  strcpy(string, newString);
}

/*------------------------------------------------------------------------------
 * Printa um botão para menu, selected define se o botão está o não selecionado
 *----------------------------------------------------------------------------*/
void print_menuButton(char * placeholder, int posX, int posY, bool selected){
  char selection[WIDTH_BUTTON_MENU + 1] = {0};
  int placeholderSize = strlen(placeholder);
  int numberOfSpaces = WIDTH_BUTTON_MENU - placeholderSize - WIDTH_MENU_SELECTOR;

  cr_moveCursorXY(posX, posY);

  for(int count = 0; count < numberOfSpaces + 3; count++)
    selection[count] = ' ';

  if(selected == TRUE){
    SET_COLOR(DARKGRAY, WHITE);
    selection[numberOfSpaces] = '<';
    selection[numberOfSpaces + 1] = '-';
    selection[numberOfSpaces + 2] = '-';
  }
  selection[numberOfSpaces + 3] = '\0';

  printf(" %s%s ", placeholder, selection);

  SET_COLOR(DEFAULT_BG_COLOR, DEFAULT_TEXT_COLOR);
}

/*------------------------------------------------------------------------------
 * Printa um casa do tabuleiro
 *----------------------------------------------------------------------------*/
void print_gameCard(gamePiece_t * card, int posX, int posY){
  
}

/*------------------------------------------------------------------------------
 * Printa o tabuleiro do jogo
 *----------------------------------------------------------------------------*/
void print_gameBoard(gameState_t * gameState, int posX, int posY){
  
}

/*------------------------------------------------------------------------------
 * Printa o componente que informa vitorio ou derrota do jogador
 *----------------------------------------------------------------------------*/
void print_endGameStatus(gameStatus_e status, int posX, int posY){
  
}