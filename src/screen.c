/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

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
    
    default:
      break;
  }
}

int getCurrentScreenState() {
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      return screenState.menuScreenState;
      break;

    case CONFIG_SCREEN:
      return screenState.configScreenState;
      break;

    case PLAY_SCREEN:
      return screenState.playScreenState;
      break;
    
    default:
      return 0;
      break;
  }
}

int getCurrentScreenFirstvalue() {
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      return MENU_FIRST_VALUE;
      break;

    case CONFIG_SCREEN:
      return CONFIG_FIRST_VALUE;
      break;

    case PLAY_SCREEN:
      return PLAY_FIRST_VALUE;
      break;
    
    default:
      return 0;
      break;
  }
}

int getCurrentScreenLastvalue() {
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      return MENU_LAST_VALUE;
      break;

    case CONFIG_SCREEN:
      return CONFIG_LAST_VALUE;
      break;

    case PLAY_SCREEN:
      return PLAY_LAST_VALUE;
      break;
    
    default:
      return 0;
      break;
  }
}

void setGameScreenState(type_gameState newGameScreenState){
  gameScreenState = newGameScreenState;
}

void printMenuScreen(){
  printf("Play\t\t%s\n", screenState.menuScreenState == MENU_PLAY ? "<--" : "");
  printf("Configs\t\t%s\n", screenState.menuScreenState == MENU_CONFIG ? "<--" : "");
  printf("Exit\t\t%s\n", screenState.menuScreenState == MENU_EXIT ? "<--" : "");
}

void printConfigScreen(){
  printf("Return\t\t%s\n", screenState.configScreenState == CONFIG_RETURN ? "<--" : "");
}

void printPlayScreen(){
  printf("PVP\t\t%s\n", screenState.playScreenState == PLAY_PVP ? "<--" : "");
  printf("PVC\t\t%s\n", screenState.playScreenState == PLAY_PVC ? "<--" : "");
  printf("Online\t\t%s\n", screenState.playScreenState == PLAY_ONLINE ? "<--" : "");
  printf("Return\t\t%s\n", screenState.playScreenState == PLAY_RETURN ? "<--" : "");

}

void printGameScreen(){
  printf("Current Player: %c\n", gameScreenState.playerSymbol[gameScreenState.currentPlayer]);
  printf(" %c | %c | %c \n", gameScreenState.currentBoard[0][0], gameScreenState.currentBoard[0][1], gameScreenState.currentBoard[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", gameScreenState.currentBoard[1][0], gameScreenState.currentBoard[1][1], gameScreenState.currentBoard[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", gameScreenState.currentBoard[2][0], gameScreenState.currentBoard[2][1], gameScreenState.currentBoard[2][2]);

}

void printWinnerScreen(){
  if(gameScreenState.gameWinner == WINNER_TOE){
    printf("Toe");
  }
  else {
    printf("Player %c wins", gameScreenState.playerSymbol[gameScreenState.gameWinner - 1]);
  }
}

void printCurrentScreen() {
  system("cls");
  switch (screenState.currentScreen){      
    case MENU_SCREEN:
      printMenuScreen();
      break;

    case CONFIG_SCREEN:
      printConfigScreen();
      break;

    case PLAY_SCREEN:
      printPlayScreen();
      break;

    case GAME_SCREEN:
      printGameScreen();
      break;

    case WINNER_SCREEN:
      printWinnerScreen();
      break;
    
    default:
      break;
  }
}