/*---------------------------
  Includes
---------------------------*/

/*---------------------------
  Variables and Constants
---------------------------*/
//Definition of app screens
typedef enum {
  MENU_SCREEN = 0,
  PLAY_SCREEN,
  GAME_SCREEN,
  CONFIG_SCREEN,
  WINNER_SCREEN,
} enum_screens;

typedef enum {
  MENU_PLAY = 1,
  MENU_CONFIG,
  MENU_EXIT,
} enum_menuState;

typedef enum {
  MENU_FIRST_VALUE = 0,
  PLAY_PVP,
  PLAY_PVC,
  PLAY_RETURN,
  MENU_LAST_VALUE,
} enum_playState;

typedef struct{
  enum_screens currentScreen;
  unsigned char currentScreenState;
} type_screenState;
type_screenState screenState;

/*---------------------------
  Functions
---------------------------*/
void printCurrentScreen();