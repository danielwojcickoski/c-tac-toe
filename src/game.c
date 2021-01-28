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
void gameInitVars() {
  gameState.currentTurn = 0;
  gameState.gameWinner = WINNER_NONE;
  memset(gameState.currentBoard, ' ', sizeof(gameState.currentBoard));
  gameState.currentPlayer = rand() % 2;
  gameState.playerSymbol[0] = 'X';
  gameState.playerSymbol[1] = 'O';
}

char convertNumberToValue(unsigned char house){
    switch (house){
      case 0:
        return gameState.currentBoard[0][0];
        break;

      case 1:
        return gameState.currentBoard[0][1];
        break;

      case 2:
        return gameState.currentBoard[0][2];
        break;

      case 3:
        return gameState.currentBoard[1][0];
        break;

      case 4:
        return gameState.currentBoard[1][1];
        break;
        
      case 5:
        return gameState.currentBoard[1][2];
        break;

      case 6:
        return gameState.currentBoard[2][0];
        break;

      case 7:
        return gameState.currentBoard[2][1];
        break;

      case 8:
        return gameState.currentBoard[2][2];
        break;
    }
    return ' ';
  }

void verifyWinner(){
  unsigned char victoryPatterns[8][3] = {
    {0, 1, 2},
    {0, 4, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {2, 4, 6},
    {3, 4, 5},
    {6, 7, 8}
  };

  if(gameState.currentTurn == 9){
    gameState.gameWinner = WINNER_TOE;
  }

  char compareValue[3] = {' '};

  //Verify Winner X
  for (int count = 0; count < 8; count++){
    compareValue[0] = convertNumberToValue(victoryPatterns[count][0]);
    compareValue[1] = convertNumberToValue(victoryPatterns[count][1]);
    compareValue[2] = convertNumberToValue(victoryPatterns[count][2]);

    if(compareValue[0] == 'X' &&
       compareValue[1] == 'X' &&
       compareValue[2] == 'X'){
         gameState.gameWinner = WINNER_P1;
         return;
    }

    if(compareValue[0] == 'O' &&
       compareValue[1] == 'O' &&
       compareValue[2] == 'O'){
         gameState.gameWinner = WINNER_P2;
         return;
    }
  }
}

void gameAction(){
  int selection = getch();

  switch (selection){
    case KEY_ESC:
      gameState.gameWinner = WINNER_ERROR;
      break;
    case KEY_NUM1:
      if(gameState.currentBoard[2][0] == ' ')
        gameState.currentBoard[2][0] = gameState.playerSymbol[gameState.currentPlayer];
      else
        return;
      break;

    case KEY_NUM2:
      if(gameState.currentBoard[2][1] == ' ')
        gameState.currentBoard[2][1] = gameState.playerSymbol[gameState.currentPlayer];
      else
        return;
      break;

    case KEY_NUM3:
      if(gameState.currentBoard[2][2] == ' ')
        gameState.currentBoard[2][2] = gameState.playerSymbol[gameState.currentPlayer];
      else
        return;
      break;

    case KEY_NUM4:
      if(gameState.currentBoard[1][0] == ' ')
        gameState.currentBoard[1][0] = gameState.playerSymbol[gameState.currentPlayer];
      else
        return;
      break;

    case KEY_NUM5:
      if(gameState.currentBoard[1][1] == ' ')
        gameState.currentBoard[1][1] = gameState.playerSymbol[gameState.currentPlayer];
      else
        return;
      break;

    case KEY_NUM6:
      if(gameState.currentBoard[1][2] == ' ')
        gameState.currentBoard[1][2] = gameState.playerSymbol[gameState.currentPlayer];
      else
        return;
      break;

    case KEY_NUM7:
      if(gameState.currentBoard[0][0] == ' ')
        gameState.currentBoard[0][0] = gameState.playerSymbol[gameState.currentPlayer];
      else
        return;
      break;

    case KEY_NUM8:
      if(gameState.currentBoard[0][1] == ' ')
        gameState.currentBoard[0][1] = gameState.playerSymbol[gameState.currentPlayer];
      else
        return;
      break;

    case KEY_NUM9:
      if(gameState.currentBoard[0][2] == ' ')
        gameState.currentBoard[0][2] = gameState.playerSymbol[gameState.currentPlayer];
      else
        return;
      break;

    default:
      return;
      break;
  }

  gameState.currentPlayer = !gameState.currentPlayer;
  gameState.currentTurn++;
}

void game(){
  gameInitVars();
  while(gameState.gameWinner == WINNER_NONE) {
    printCurrentScreen();

    if(gameState.gameType == GAME_PVC && gameState.currentPlayer == 1){
      aiAction();
    }
    else{
      gameAction();
    }

    verifyWinner();
  }
  if(gameState.gameWinner != WINNER_ERROR)
    screenState.currentScreen = WINNER_SCREEN;
  else
    screenState.currentScreen = MENU_SCREEN;
}
