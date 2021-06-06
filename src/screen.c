/*------------------------------------------------------------------------------
 * tic-tac-toe.c
 *
 * File: screen.c
 * Author: Daniel Wojcickoski
 * Date: 2021/05/26
 * 
 * MIT License - Copyright (c) 2021 Daniel Wojcickoski
 *----------------------------------------------------------------------------*/
#include "../includes/screen.h"
#include "../includes/screen_components.h"
#include "../includes/logo.h"

/*------------------------------------------------------------------------------
 * Thread control variables
 *----------------------------------------------------------------------------*/
bool screenIsUpdated = FALSE;
appState_t screenState = {0};

/*------------------------------------------------------------------------------
 * Altera o estado do cursor entre visivel e invisivel
 *----------------------------------------------------------------------------*/
void setCursor(cursorState_e cursorState){
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = cursorState;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

/*------------------------------------------------------------------------------
 * Ajusta o buffer do terminal para o tamanho sizeX sizeY
 *----------------------------------------------------------------------------*/
void configScreenSize(int sizeX, int sizeY){
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  SMALL_RECT sr;
  COORD consoleSize;

  consoleSize.X = sizeX;
  consoleSize.Y = sizeY;

  sr.Top = sr.Left = 0;
  sr.Right = consoleSize.X - 1;
  sr.Bottom = consoleSize.Y - 1;

  SetConsoleWindowInfo(console, TRUE, &sr);
  SetConsoleScreenBufferSize(console, consoleSize);
}

/*------------------------------------------------------------------------------
 * Printa a tela do menu principal
 *----------------------------------------------------------------------------*/
void screen_mainMenu(appState_t currentAppState){
  int menuXStart = 23;
  menuState_e menuState = currentAppState.screen.menuState;

  print_logoLetter(LOGO_T, menuXStart, 3, DEFAULT_BG_COLOR, DEFAULT_TEXT_COLOR);
  print_logoLetter(LOGO_T, menuXStart + 8, 3, DEFAULT_BG_COLOR, DEFAULT_TEXT_COLOR);
  print_logoLetter(LOGO_T, menuXStart + 16, 3, DEFAULT_BG_COLOR, DEFAULT_TEXT_COLOR);
  print_logoLetter(LOGO_DOT, menuXStart + 23, 3, DEFAULT_BG_COLOR, DEFAULT_TEXT_COLOR);
  print_logoLetter(LOGO_C, menuXStart + 26, 3, DEFAULT_BG_COLOR, DEFAULT_TEXT_COLOR);

  print_menuButton("PvP", menuXStart + 7, 13, (menuState == STATE_MENU_PVP) ? TRUE : FALSE);
  print_menuButton("PvC", menuXStart + 7, 15, (menuState == STATE_MENU_PVC) ? TRUE : FALSE);
  print_menuButton("CvC", menuXStart + 7, 17, (menuState == STATE_MENU_CVC) ? TRUE : FALSE);
  print_menuButton("Sair", menuXStart + 7, 19, (menuState == STATE_MENU_EXIT) ? TRUE : FALSE);
}

/*------------------------------------------------------------------------------
 * Printa a tela dentro de jogo
 *----------------------------------------------------------------------------*/
void screen_inGame(appState_t * currentAppState){
  
}

/*------------------------------------------------------------------------------
 * Printa a tela de fim de partida
 *----------------------------------------------------------------------------*/
void screen_endGame(appState_t * currentAppState){
  
}

/*------------------------------------------------------------------------------
 * Updates the variables used in the thread to print the screen
 *----------------------------------------------------------------------------*/
void updateScreenState(appState_t * newScreenState){
  screenState = *newScreenState;
  screenIsUpdated = FALSE;
}

/*------------------------------------------------------------------------------
 * Thread responsible for showing the components on the screen
 *----------------------------------------------------------------------------*/
void *screenThread(){
  while(TRUE){
    if(screenIsUpdated == FALSE){
      SET_COLOR(DEFAULT_BG_COLOR, DEFAULT_TEXT_COLOR);
      setCursor(CURSOR_HIDDEN);
      SetConsoleTitleW(DEFAULT_SCREEN_TITLE);
      configScreenSize(DEFAULT_SCREEN_X_SIZE, DEFAULT_SCREEN_Y_SIZE);

      if(screenState.screen.lastScreen == SCREEN_NONE){
        configScreenSize(DEFAULT_SCREEN_X_SIZE, DEFAULT_SCREEN_Y_SIZE);
        cr_clearScreen();
      }

      if(screenState.screen.lastScreen != screenState.screen.currentScreen || screenState.screen.forceClear == TRUE){
        cr_clearScreen();
      }

      //Mostra a tela correta relativa a currentScreen
      switch (screenState.screen.currentScreen){
        case SCREEN_MENU:
          screen_mainMenu(screenState);
          break;

        case SCREEN_GAME:
          screen_inGame(&screenState);
          break;

        case SCREEN_ENDGAME:
          screen_endGame(&screenState);
          setCursor(CURSOR_VISIBLE);
          break;

        default:
          screenState.screen.currentScreen = SCREEN_MENU;
          break;
      }

      screenIsUpdated = TRUE;
    }

    Sleep(16);
  }
}

