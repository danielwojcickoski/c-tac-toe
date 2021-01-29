/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

/*---------------------------
  Variables and constants
---------------------------*/
//[house][line|column]
unsigned char housePatterns[9][2] = {
    {0, 0},
    {0, 1},
    {0, 2},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 0},
    {2, 1},
    {2, 2},
  };

//[pattern][house]
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

/*
  @params:
    pattern: 0 ~ 8 = pattern number
    house: 0, 1, 2 = house of pattern
    position: 0 = line | 1 = collumn

  @return:
    int: 0, 1, 2 = number of line|column of selected house of selected pattern
*/
unsigned char getHouseByPattern(int pattern, int house, int position){
  int houseOfPattern = victoryPatterns[pattern][house];

  return housePatterns[houseOfPattern][position];
}

/*
  @params:
    house: 0 ~ 8 = house , left-top to right-down
    position: 0 = line | 1 = collumn

  @return:
    int: 0, 1, 2 = number of line|column of selected house
*/
unsigned char getHouseByNumber(int house, int position){
  return housePatterns[house][position];
}