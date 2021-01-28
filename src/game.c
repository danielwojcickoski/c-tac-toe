/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

/*---------------------------
  Variables and constants
---------------------------*/
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

char convertNumberToValue(unsigned char house, char newValue){
    switch (house){
      case 0:
        if(newValue != ' '){
          gameState.currentBoard[0][0] = newValue;
          return ' ';
        }
        return gameState.currentBoard[0][0];
        break;

      case 1:
        if(newValue != ' '){
          gameState.currentBoard[0][1] = newValue;
          return ' ';
        }
        return gameState.currentBoard[0][1];
        break;

      case 2:
        if(newValue != ' '){
          gameState.currentBoard[0][2] = newValue;
          return ' ';
        }
        return gameState.currentBoard[0][2];
        break;

      case 3:
        if(newValue != ' '){
          gameState.currentBoard[1][0] = newValue;
          return ' ';
        }
        return gameState.currentBoard[1][0];
        break;

      case 4:
        if(newValue != ' '){
          gameState.currentBoard[1][1] = newValue;
          return ' ';
        }
        return gameState.currentBoard[1][1];
        break;
        
      case 5:
        if(newValue != ' '){
          gameState.currentBoard[1][2] = newValue;
          return ' ';
        }
        return gameState.currentBoard[1][2];
        break;

      case 6:
        if(newValue != ' '){
          gameState.currentBoard[2][0] = newValue;
          return ' ';
        }
        return gameState.currentBoard[2][0];
        break;

      case 7:
        if(newValue != ' '){
          gameState.currentBoard[2][1] = newValue;
          return ' ';
        }
        return gameState.currentBoard[2][1];
        break;

      case 8:
        if(newValue != ' '){
          gameState.currentBoard[2][2] = newValue;
          return ' ';
        }
        return gameState.currentBoard[2][2];
        break;
    }
  return ' ';
}

void verifyWinner(){
  if(gameState.currentTurn == 9){
    gameState.gameWinner = WINNER_TOE;
  }

  char compareValue[3] = {' '};

  for (int count = 0; count < 8; count++){
    compareValue[0] = convertNumberToValue(victoryPatterns[count][0], ' ');
    compareValue[1] = convertNumberToValue(victoryPatterns[count][1], ' ');
    compareValue[2] = convertNumberToValue(victoryPatterns[count][2], ' ');

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

    gameState.currentPlayer = !gameState.currentPlayer;
    gameState.currentTurn++;
    verifyWinner();
  }
  if(gameState.gameWinner != WINNER_ERROR)
    screenState.currentScreen = WINNER_SCREEN;
  else
    screenState.currentScreen = MENU_SCREEN;
}
