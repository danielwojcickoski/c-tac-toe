/*---------------------------
  Tic-Tac-Toe game in C

  Date: 2021/02/01
  Author: Daniel Wojcickoski
---------------------------*/

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
int main() {
  setCursor(HIDDEN);

  parseConfigs();

  app();
  
  return 0;
}