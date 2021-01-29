/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

/*---------------------------
  Variables and constants
---------------------------*/
type_gameState gameState;

/*---------------------------
  Functions
---------------------------*/
void gameInitVars(enum_gameType gameType) {
  gameState.currentTurn = 0;
  gameState.currentPlayer = rand() % 2;
  gameState.playerSymbol[0] = 'X';
  gameState.playerSymbol[1] = 'O';
  memset(gameState.currentBoard, ' ', sizeof(gameState.currentBoard));
  gameState.gameType = gameType;
  gameState.gameWinner = WINNER_NONE;
}

void verifyWinner(){
  if(gameState.currentTurn == 9){
    gameState.gameWinner = WINNER_TOE;
  }

  char compareValue[3] = {' '};

  for (int count = 0; count < 8; count++){
    compareValue[0] = gameState.currentBoard[getHouseByPattern(count, 0, LINE)][getHouseByPattern(count, 0, COLLUMN)];
    compareValue[1] = gameState.currentBoard[getHouseByPattern(count, 1, LINE)][getHouseByPattern(count, 1, COLLUMN)];
    compareValue[2] = gameState.currentBoard[getHouseByPattern(count, 2, LINE)][getHouseByPattern(count, 2, COLLUMN)];

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

void playerAction(){
  int selection = getch();

  switch (selection){
    case KEY_ESC:
      gameState.gameWinner = WINNER_ERROR;
      break;

    default:
      if(selection >= KEY_NUM1 && selection <= KEY_NUM9){
        char newSymbol = gameState.playerSymbol[gameState.currentPlayer];

        printf("%d ", selection);

        if(selection >= KEY_NUM7 && selection <= KEY_NUM9)
          selection -= 55;
        else if(selection >= KEY_NUM4 && selection <= KEY_NUM6)
          selection -= 49;
        else if(selection >= KEY_NUM1 && selection <= KEY_NUM3)
          selection -= 43;

        unsigned char line = getHouseByNumber(selection, LINE);
        unsigned char collumn = getHouseByNumber(selection, COLLUMN);

        printf("%d\n", selection);

        if(gameState.currentBoard[line][collumn] == ' '){
          gameState.currentBoard[line][collumn] = newSymbol;
        }
        else{
          return;
        }
      }
      else {
        return;
      }
      break;
  }

  gameState.currentPlayer = !gameState.currentPlayer;
  gameState.currentTurn++;
}

void game(enum_gameType gameType){
  gameInitVars(gameType);
  setGameScreenState(gameState);

  while(gameState.gameWinner == WINNER_NONE) {
    printCurrentScreen();

    if(gameState.gameType == GAME_PVC && gameState.currentPlayer == 1){
      setAiGameState(gameState);
      aiAction();
      gameState = getAiGameState();
      gameState.currentPlayer = !gameState.currentPlayer;
      gameState.currentTurn++;
    }
    else{
      playerAction();
    }

    verifyWinner();
    setGameScreenState(gameState);
  }

  if(gameState.gameWinner != WINNER_ERROR)
    setCurrentScreen(WINNER_SCREEN);
  else
    setCurrentScreen(PLAY_SCREEN);
}
