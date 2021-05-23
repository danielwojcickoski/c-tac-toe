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
unsigned char getHouseByPattern(int pattern, int house, enum_housePositions position);
unsigned char getHouseByNumber(int house, enum_housePositions position);