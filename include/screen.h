/*---------------------------
  Includes
---------------------------*/

/*---------------------------
  Variables and Constants
---------------------------*/
//App screens
typedef enum {
  MENU_SCREEN = 0,
  CONFIG_SCREEN,
  PLAY_SCREEN,
  GAME_SCREEN,
  WINNER_SCREEN,
} enum_screens;

//Menu options
typedef enum {
  MENU_FIRST_VALUE = 0,
  MENU_PLAY,
  MENU_CONFIG,
  MENU_EXIT,
  MENU_LAST_VALUE,
} enum_menuScreenState;

//Play options
typedef enum {
  PLAY_FIRST_VALUE = 0,
  PLAY_PVP,
  PLAY_PVC,
  PLAY_CVC,
  PLAY_ONLINE,
  PLAY_RETURN,
  PLAY_LAST_VALUE,
} enum_playScreenState;

//Config options
typedef enum {
  CONFIG_FIRST_VALUE = 0,
  CONFIG_RETURN,
   CONFIG_LAST_VALUE,
} enum_configScreenState;

//Screen state
typedef struct{
  enum_screens currentScreen;
  enum_menuScreenState menuScreenState;
  enum_configScreenState configScreenState;
  enum_playScreenState playScreenState;
  COORD screenSize;
} type_screenState;

/*---------------------------
  Functions
---------------------------*/
void setCurrentScreen(enum_screens newScreen);
enum_screens getCurrentScreen();
void setCurrentScreenState(int newValue);
int getCurrentScreenState();
int getCurrentScreenFirstvalue();
int getCurrentScreenLastvalue();
void setGameScreenState(type_gameState newGameScreenState);
void printCurrentScreen();