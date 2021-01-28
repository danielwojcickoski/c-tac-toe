/*---------------------------
  Includes
---------------------------*/

/*---------------------------
  Variables and Constants
---------------------------*/
typedef enum {
  GAME_PVP = 0,
  GAME_PVC,
} enum_gameType;

typedef enum {
  WINNER_NONE = 0,
  WINNER_P1,
  WINNER_P2,
  WINNER_TOE,
  WINNER_ERROR,
} enum_gameWinner;

typedef struct{
  unsigned char currentTurn;
  unsigned char currentPlayer;
  char playerSymbol[2];
  char currentBoard[3][3];
  enum_gameType gameType;
  enum_gameWinner gameWinner;
} type_gameState;
type_gameState gameState;

/*---------------------------
  Functions
---------------------------*/
void game();