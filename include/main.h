/*---------------------------
  Includes
---------------------------*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "./game.h"
#include "./ai.h"
#include "./app.h"
#include "./config.h"
#include "./screen.h"

/*---------------------------
  Variables and Constants
---------------------------*/
#define FALSE 0
#define TRUE 1

typedef enum {
  KEY_ENTER = 13,
  
  KEY_ESC = 27,

  KEY_SPACE = 32,

  KEY_NUM1 = 49,
  KEY_NUM2,
  KEY_NUM3,
  KEY_NUM4,
  KEY_NUM5,
  KEY_NUM6,
  KEY_NUM7,
  KEY_NUM8,
  KEY_NUM9,

  KEY_ARROW_UP = 72,
  KEY_ARROW_DOWN = 80,
} enum_keyboardKeys;

typedef enum {
  EXIT_STATE_NONE = 0,
  EXIT_STATE_ERROR,
  EXIT_STATE_ESCAPE,
} enum_exitFlags;

typedef struct{
  enum_exitFlags exitFlag;
} type_appState;

/*---------------------------
  Functions
---------------------------*/