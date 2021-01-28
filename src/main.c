/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

/*---------------------------
  Variables and constants
---------------------------*/
type_appState appState = {0};

/*---------------------------
  Functions
---------------------------*/
int main() {
  parseConfigs();

  app();
  
  return 0;
}