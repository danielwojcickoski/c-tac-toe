/*---------------------------
  Includes
---------------------------*/

/*---------------------------
  Variables and Constants
---------------------------*/
//App screens
typedef enum {
  MENU_SCREEN = 0,
  HELP_SCREEN,
  CONFIG_SCREEN,

  PLAY_SCREEN,
  GAME_SCREEN,
  WINNER_SCREEN,

  ONLINE_SCREEN,
  SERVER_SCREEN,
  CLIENT_SCREEN,
} enum_screens;

//Menu options
typedef enum {
  MENU_FIRST_VALUE = 0,
  MENU_PLAY,
  MENU_CONFIG,
  MENU_HELP,
  MENU_EXIT,
  MENU_LAST_VALUE,
} enum_menuScreenState;

//Help options
typedef enum {
  HELP_FIRST_VALUE = 0,
  HELP_RETURN,
  HELP_LAST_VALUE,
} enum_helpScreenState;

//Config options
typedef enum {
  CONFIG_FIRST_VALUE = 0,
  CONFIG_RETURN,
  CONFIG_LAST_VALUE,
} enum_configScreenState;

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

//Online options
typedef enum {
  ONLINE_FIRST_VALUE = 0,
  ONLINE_SERVER,
  ONLINE_CLIENT,
  ONLINE_RETURN,
  ONLINE_LAST_VALUE,
} enum_onlineScreenState;

//Server options
typedef enum {
  SERVER_FIRST_VALUE = 0,
  SERVER_RETURN,
  SERVER_LAST_VALUE,
} enum_serverScreenState;

//Client options
typedef enum {
  CLIENT_FIRST_VALUE = 0,
  CLIENT_RETURN,
  CLIENT_LAST_VALUE,
} enum_clientScreenState;

//Screen state
typedef struct {
  enum_screens currentScreen;
  enum_menuScreenState menuScreenState;
  enum_helpScreenState helpScreenState;
  enum_configScreenState configScreenState;
  enum_playScreenState playScreenState;
  enum_playScreenState onlineScreenState;
  enum_serverScreenState serverScreenState;
  enum_clientScreenState clientScreenState;
  short xScreenSize;
} type_screenState;

typedef enum {
  HIDDEN = 0,
  VISIBLE,
} enum_cursorState;

typedef enum {
  FIRST = 0,
  CURRENT,
  LAST,
} enum_stateFlag;

/*---------------------------
  Functions
---------------------------*/
void setCurrentScreen(enum_screens newScreen);
enum_screens getCurrentScreen();
void setCurrentScreenState(int newValue);
int getCurrentScreenState(enum_stateFlag stateFlag);
void setGameScreenState(type_gameState newGameScreenState);
void setCursor(enum_cursorState cursorState);
void printCurrentScreen();