/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: logo.h
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#ifndef  LOGO_H
#define  LOGO_H

//Includes
#include "../includes/main.h"

//Types
typedef enum logoLetters{
  LOGO_T = 0,
  LOGO_DOT,
  LOGO_C,
} logoLetters_e;

//Functions
void print_logoLetter(logoLetters_e selectedLetter, int posX, int posY, COLORS bgColor, COLORS textColor);

#endif  /*LOGO_H*/
