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