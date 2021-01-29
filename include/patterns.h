/*---------------------------
  Includes
---------------------------*/

/*---------------------------
  Variables and constants
---------------------------*/
typedef enum {
  LINE = 0,
  COLLUMN,
} enum_housePositions;

/*---------------------------
  Functions
---------------------------*/
unsigned char getHouseByPattern(int pattern, int house, int position);
unsigned char getHouseByNumber(int house, int position);