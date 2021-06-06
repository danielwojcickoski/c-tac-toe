/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: logo.c
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#include "../includes/logo.h"

//Constants
const char charLogoT[MENU_LOGO_LINES][MENU_LOGO_COLUMNS] = {
  "####### ",
  "   #    ",
  "   #    ",
  "   #    ",
  "   #    ",
  "   #    ",
  "   #    ",
};

const char charLogoDot[MENU_LOGO_LINES][MENU_LOGO_COLUMNS] = {
  "   ",
  "   ",
  "   ",
  "   ",
  "   ",
  "   ",
  " # ",
};
const char charLogoC[MENU_LOGO_LINES][MENU_LOGO_COLUMNS] = {
  "       ",
  " ####  ",
  "#    # ",
  "#      ",
  "#      ",
  "#    # ",
  " ####  ",
};

/*------------------------------------------------------------------------------
 * Printa na posição (X, Y) uma letra do logo, com as cores especificadas
 *----------------------------------------------------------------------------*/
void print_logoLetter(logoLetters_e selectedLetter, int posX, int posY, COLORS bgColor, COLORS textColor){
  char letter[MENU_LOGO_LINES][MENU_LOGO_COLUMNS] = {0};

  switch (selectedLetter){
    case LOGO_T: memcpy(letter, charLogoT, MENU_LOGO_LINES * MENU_LOGO_COLUMNS);
      break;
    case LOGO_DOT: memcpy(letter, charLogoDot, MENU_LOGO_LINES * MENU_LOGO_COLUMNS);
      break;
    case LOGO_C: memcpy(letter, charLogoC, MENU_LOGO_LINES * MENU_LOGO_COLUMNS);
      break;
    default:
      return;
      break;
  }

  SET_COLOR(bgColor, textColor);

  for(int count = 0; count < MENU_LOGO_LINES; count++){
    cr_moveCursorXY(posX, posY + count);
    printf("%s", letter[count]);
  }

  SET_COLOR(DEFAULT_BG_COLOR, DEFAULT_TEXT_COLOR);
}