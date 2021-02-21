/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"
#include "../include/screens_terminal.h"

/*---------------------------
  Variables and constants
---------------------------*/
type_screenState screenState = {0};
type_gameState gameScreenState = {0};

/*---------------------------
  Functions
---------------------------*/
void setCurrentScreen(enum_screens newScreen) {
  screenState.currentScreen = newScreen;
}

enum_screens getCurrentScreen(){
  return screenState.currentScreen;
}

void setCurrentScreenState(int newValue) {
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      screenState.menuScreenState = newValue;
      break;

    case CONFIG_SCREEN:
      screenState.configScreenState = newValue;
      break;

    case PLAY_SCREEN:
      screenState.playScreenState = newValue;
      break;

    case ONLINE_SCREEN:
      screenState.onlineScreenState = newValue;
      break;

    case SERVER_SCREEN:
      screenState.serverScreenState = newValue;
      break;

    case CLIENT_SCREEN:
      screenState.clientScreenState = newValue;
      break;

    default:
      break;
  }
}

int getCurrentScreenState(enum_stateFlag stateFlag) {
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      return (stateFlag == FIRST) ? MENU_FIRST_VALUE : (stateFlag == LAST) ? MENU_LAST_VALUE : screenState.menuScreenState;
      break;

    case CONFIG_SCREEN:
      return (stateFlag == FIRST) ? CONFIG_FIRST_VALUE : (stateFlag == LAST) ? CONFIG_LAST_VALUE : screenState.configScreenState;
      break;

    case PLAY_SCREEN:
      return (stateFlag == FIRST) ? PLAY_FIRST_VALUE : (stateFlag == LAST) ? PLAY_LAST_VALUE : screenState.playScreenState;
      break;

    case ONLINE_SCREEN:
      return (stateFlag == FIRST) ? ONLINE_FIRST_VALUE : (stateFlag == LAST) ? ONLINE_LAST_VALUE : screenState.onlineScreenState;
      break;

    case SERVER_SCREEN:
      return (stateFlag == FIRST) ? SERVER_FIRST_VALUE : (stateFlag == LAST) ? SERVER_LAST_VALUE : screenState.serverScreenState;
      break;

    case CLIENT_SCREEN:
      return (stateFlag == FIRST) ? CLIENT_FIRST_VALUE : (stateFlag == LAST) ? CLIENT_LAST_VALUE : screenState.clientScreenState;
      break;

    default:
      return 0;
      break;
  }
}

void setGameScreenState(type_gameState newGameScreenState){
  gameScreenState = newGameScreenState;
}

void printCurrentScreen() {
  clearScreen();
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      terminal_printMenuScreen();
      break;

    case CONFIG_SCREEN:
      terminal_printConfigScreen();
      break;

    case PLAY_SCREEN:
      terminal_printPlayScreen();
      break;

    case GAME_SCREEN:
      terminal_printGameScreen(gameScreenState);
      break;

    case WINNER_SCREEN:
      terminal_printWinnerScreen(gameScreenState);
      break;

    case ONLINE_SCREEN:
      terminal_printOnlineScreen();
      break;

    case SERVER_SCREEN:
      terminal_printServerScreen();
      break;

    case CLIENT_SCREEN:
      terminal_printClientScreen();
      break;

    default:
      break;
  }
}
