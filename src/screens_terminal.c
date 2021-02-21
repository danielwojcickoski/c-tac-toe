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
int calcPreSpaces(int discount){
  int spaces = ((getXScreenSize() - discount) / 2);
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

void terminal_printMenuScreen(){
  printf("\n\n");
  printInCenter("Play", MENU_PLAY);
  printInCenter("Settings", MENU_CONFIG);
  printInCenter("Exit", MENU_EXIT);
}

void terminal_printConfigScreen(){
  printf("\n\n");
  printInCenter("Return", CONFIG_RETURN);
}

void terminal_printPlayScreen(){
  printf("\n\n");
  printInCenter("PvP", PLAY_PVP);
  printInCenter("PvC", PLAY_PVC);
  printInCenter("CvC", PLAY_CVC);
  printInCenter("Online", PLAY_ONLINE);
  printInCenter("Return", PLAY_RETURN);
}

void terminal_printGameScreen(type_gameState gameScreenState){
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

void terminal_printWinnerScreen(type_gameState gameScreenState){
  printf("\n\n");
  if(gameScreenState.gameWinner == WINNER_TOE){
    printInCenter("Toe", -1);
  }
  else {
    printf("%sPlayer %c wins", genPreSpaces(calcPreSpaces(sizeof("Player X wins"))), gameScreenState.playerSymbol[gameScreenState.gameWinner - 1]);
  }
}

void terminal_printOnlineScreen(){
  printf("\n\n");
  printInCenter("Server", ONLINE_SERVER);
  printInCenter("Client", ONLINE_CLIENT);
  printInCenter("Return", ONLINE_RETURN);
}

void terminal_printServerScreen(){
  printf("\n\n");
  printInCenter("Return", SERVER_RETURN);
}

void terminal_printClientScreen(){
  printf("\n\n");
  printInCenter("Return", CLIENT_RETURN);
}