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
  MENU_FIRST_VALUE = 0,
  MENU_PLAY,
  MENU_CONFIG,
  MENU_EXIT,
  MENU_LAST_VALUE,
} enum_menuState;

typedef enum {
  PLAY_PVP = 1,
  PLAY_PVC,
  PLAY_RETURN,
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