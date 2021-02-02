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

void setCursor(enum_cursorState cursorState){
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = cursorState;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void configScreen(){
  CONSOLE_SCREEN_BUFFER_INFO screenInfo = {0};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);

  screenState.screenSize = screenInfo.dwMaximumWindowSize;
}

int calcPreSpaces(int discount){
  int spaces = ((screenState.screenSize.X - discount) / 2);
  return spaces;
}

char preSpaces[1000];
const char* genPreSpaces(int spaces){
  memset(preSpaces, 0, sizeof(preSpaces));
  memset(preSpaces, ' ', spaces);
  return preSpaces;
}

void printInCenter(char * text, int optionState){
  int flag = getCurrentScreenState(CURRENT) == optionState ? 1 : 0;
  printf("%s%s %s %s\n", genPreSpaces(calcPreSpaces(strlen(text) + 8)), flag == 1 ? "-->" : "   ", text, flag == 1 ? "<--" : "   ");
}

void printMenuScreen(){
  printf("\n\n");
  printInCenter("Play", MENU_PLAY);
  printInCenter("Settings", MENU_CONFIG);
  printInCenter("Exit", MENU_EXIT);
}

void printConfigScreen(){
  printf("\n\n");
  printInCenter("Return", CONFIG_RETURN);
}

void printPlayScreen(){
  printf("\n\n");
  printInCenter("PvP", PLAY_PVP);
  printInCenter("PvC", PLAY_PVC);
  printInCenter("CvC", PLAY_CVC);
  printInCenter("Online", PLAY_ONLINE);
  printInCenter("Return", PLAY_RETURN);
}

void printGameScreen(){
  int boardSpace = calcPreSpaces(strlen("---+---+---"));

  printf("\n\n");
  printInCenter("Press ESC to quit", -1);
  printf("%sCurrent Player: %c", genPreSpaces(calcPreSpaces(sizeof("Current Player:  "))), gameScreenState.playerSymbol[gameScreenState.currentPlayer]);
  printf("\n\n");
  printf("%s %c | %c | %c \n", genPreSpaces(boardSpace), gameScreenState.currentBoard[0][0], gameScreenState.currentBoard[0][1], gameScreenState.currentBoard[0][2]);
  printf("%s---+---+---\n", genPreSpaces(boardSpace));
  printf("%s %c | %c | %c \n", genPreSpaces(boardSpace), gameScreenState.currentBoard[1][0], gameScreenState.currentBoard[1][1], gameScreenState.currentBoard[1][2]);
  printf("%s---+---+---\n", genPreSpaces(boardSpace));
  printf("%s %c | %c | %c \n", genPreSpaces(boardSpace), gameScreenState.currentBoard[2][0], gameScreenState.currentBoard[2][1], gameScreenState.currentBoard[2][2]);

  if(gameScreenState.gameType == GAME_CVC){
    printf("\n\n");
    printInCenter("Press any key to next turn", -1);
  }
}

void printWinnerScreen(){
  printf("\n\n");
  if(gameScreenState.gameWinner == WINNER_TOE){
    printInCenter("Toe", -1);
  }
  else {
    printf("%sPlayer %c wins", genPreSpaces(calcPreSpaces(sizeof("Player X wins"))), gameScreenState.playerSymbol[gameScreenState.gameWinner - 1]);
  }
}

void printOnlineScreen(){
  printf("\n\n");
  printInCenter("Server", ONLINE_SERVER);
  printInCenter("Client", ONLINE_CLIENT);
  printInCenter("Return", ONLINE_RETURN);
}

void printServerScreen(){
  printf("\n\n");
  printInCenter("Return", SERVER_RETURN);
}

void printClientScreen(){
  printf("\n\n");
  printInCenter("Return", CLIENT_RETURN);
}

void printCurrentScreen() {
  configScreen();

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

    case ONLINE_SCREEN:
      printOnlineScreen();
      break;

    case SERVER_SCREEN:
      printServerScreen();
      break;

    case CLIENT_SCREEN:
      printClientScreen();
      break;

    default:
      break;
  }
}
