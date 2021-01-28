/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

/*---------------------------
  Variables and constants
---------------------------*/

/*---------------------------
  Functions
---------------------------*/
void handleMenuSelection(){
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      if(screenState.currentScreenState ==  MENU_PLAY){
        screenState.currentScreen = PLAY_SCREEN;
        screenState.currentScreenState = 1;
      }
      else if(screenState.currentScreenState ==  MENU_CONFIG){
        screenState.currentScreen = CONFIG_SCREEN;
        screenState.currentScreenState = 1;
      }
      else if(screenState.currentScreenState ==  MENU_EXIT){
        appState.exitFlag = EXIT_STATE_ESCAPE;
      }
      break;

    case PLAY_SCREEN:
      if(screenState.currentScreenState ==  PLAY_PVP){
        screenState.currentScreen = GAME_SCREEN;
        screenState.currentScreenState = 1;
        gameState.gameType = GAME_PVP;
        game();
      }
      else if(screenState.currentScreenState ==  PLAY_PVC){
        screenState.currentScreen = GAME_SCREEN;
        screenState.currentScreenState = 1;
        gameState.gameType = GAME_PVC;
        game();
      }
      else if(screenState.currentScreenState ==  PLAY_RETURN){
        screenState.currentScreen = MENU_SCREEN;
        screenState.currentScreenState = 1;
      }
      break;

    case GAME_SCREEN:
      screenState.currentScreen = PLAY_SCREEN;
      screenState.currentScreenState = 1;
      break;

    case CONFIG_SCREEN:
        screenState.currentScreen = MENU_SCREEN;
        screenState.currentScreenState = 1;
      break;

    case WINNER_SCREEN:
      screenState.currentScreen = MENU_SCREEN;
      screenState.currentScreenState = 1;
      break;

    default:
      screenState.currentScreen = MENU_SCREEN;
      screenState.currentScreenState = 1;
      break;
  }
}

void appAction(){
  int selection = getch();

  if(selection == KEY_ENTER || selection == KEY_SPACE){
    handleMenuSelection();
  }
  else if(selection == KEY_ARROW_DOWN){
    screenState.currentScreenState++;
    if(screenState.currentScreenState == MENU_LAST_VALUE)
      screenState.currentScreenState = MENU_FIRST_VALUE + 1;
  }
  else if(selection == KEY_ARROW_UP) {
    screenState.currentScreenState--;
    if(screenState.currentScreenState == MENU_FIRST_VALUE)
      screenState.currentScreenState = MENU_LAST_VALUE - 1;
  }
}

void app() {
  screenState.currentScreen = MENU_SCREEN;
  screenState.currentScreenState = 1;
  while(appState.exitFlag == EXIT_STATE_NONE) {
    printCurrentScreen();

    appAction();
  }
}
