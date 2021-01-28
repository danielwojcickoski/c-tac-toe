/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

/*---------------------------
  Variables and constants
---------------------------*/
type_screenState screenState = {0};

/*---------------------------
  Functions
---------------------------*/
void printCurrentScreen() {
  switch (screenState.currentScreen){      
    case MENU_SCREEN:
      system("cls");
      printf("Play\t\t%s\n", screenState.currentScreenState == MENU_PLAY ? "<--" : "");
      printf("Configs\t\t%s\n", screenState.currentScreenState == MENU_CONFIG ? "<--" : "");
      printf("Exit\t\t%s\n", screenState.currentScreenState == MENU_EXIT ? "<--" : "");
      break;

    case PLAY_SCREEN:
      system("cls");
      printf("PVP\t\t%s\n", screenState.currentScreenState == PLAY_PVP ? "<--" : "");
      printf("PVC\t\t%s\n", screenState.currentScreenState == PLAY_PVC ? "<--" : "");
      printf("Return\t\t%s\n", screenState.currentScreenState == PLAY_RETURN ? "<--" : "");
      break;

    case GAME_SCREEN:
      system("cls");
      printf("Current Player: %c\n", gameState.playerSymbol[gameState.currentPlayer]);
      printf(" %c | %c | %c \n", gameState.currentBoard[0][0], gameState.currentBoard[0][1], gameState.currentBoard[0][2]);
      printf("---+---+---\n");
      printf(" %c | %c | %c \n", gameState.currentBoard[1][0], gameState.currentBoard[1][1], gameState.currentBoard[1][2]);
      printf("---+---+---\n");
      printf(" %c | %c | %c \n", gameState.currentBoard[2][0], gameState.currentBoard[2][1], gameState.currentBoard[2][2]);
      break;

    case CONFIG_SCREEN:
      system("cls");
      printf("Return\t\t<--");//%s\n", screenState.currentScreenState == PLAY_RETURN ? "<--" : "");
      break;

    case WINNER_SCREEN:
      system("cls");
      if(gameState.gameWinner == WINNER_TOE){
        printf("Toe");
      }
      else {
        printf("Player %c wins", gameState.playerSymbol[gameState.gameWinner - 1]);
      }
      break;
    
    default:
      system("cls");
      break;
  }
}