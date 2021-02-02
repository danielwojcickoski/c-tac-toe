/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

/*---------------------------
  Variables and constants
---------------------------*/
type_appState appState;

/*---------------------------
  Functions
---------------------------*/
void menuScreenAction(){
  switch (getCurrentScreenState(CURRENT)){
    case MENU_PLAY:
      setCurrentScreen(PLAY_SCREEN);
      setCurrentScreenState(PLAY_FIRST_VALUE + 1);
      break;

    case MENU_CONFIG:
      setCurrentScreen(CONFIG_SCREEN);
      setCurrentScreenState(CONFIG_FIRST_VALUE + 1);
      break;

    case MENU_EXIT:
      appState.exitFlag = EXIT_STATE_ESCAPE;
      break;

    default:
      setCurrentScreenState(MENU_FIRST_VALUE + 1);
      break;
  }
}

void configScreenAction(){
  switch (getCurrentScreenState(CURRENT)){
    case CONFIG_RETURN:
      setCurrentScreen(MENU_SCREEN);
      break;

    default:
      setCurrentScreenState(CONFIG_FIRST_VALUE + 1);
      break;
  }
}

void playScreenAction(){
  switch (getCurrentScreenState(CURRENT)){
    case PLAY_PVP:
      setCurrentScreen(GAME_SCREEN);
      game(GAME_PVP);
      break;

    case PLAY_PVC:
      setCurrentScreen(GAME_SCREEN);
      game(GAME_PVC);
      break;

    case PLAY_CVC:
      setCurrentScreen(GAME_SCREEN);
      game(GAME_CVC);
      break;

    case PLAY_ONLINE:
      setCurrentScreen(ONLINE_SCREEN);
      setCurrentScreenState(ONLINE_FIRST_VALUE + 1);
      break;

    case PLAY_RETURN:
      setCurrentScreen(MENU_SCREEN);
      break;

    default:
      setCurrentScreenState(PLAY_FIRST_VALUE + 1);
      break;
  }
}

void onlineScreenAction(){
  switch (getCurrentScreenState(CURRENT)){
    case ONLINE_SERVER:
      setCurrentScreen(SERVER_SCREEN);
      setCurrentScreenState(SERVER_FIRST_VALUE + 1);
      break;

    case ONLINE_CLIENT:
      setCurrentScreen(CLIENT_SCREEN);
      setCurrentScreenState(CLIENT_FIRST_VALUE + 1);
      break;

    case ONLINE_RETURN:
      setCurrentScreen(PLAY_SCREEN);
      break;

    default:
      setCurrentScreenState(PLAY_FIRST_VALUE + 1);
      break;
  }
}

void serverScreenAction(){
  switch (getCurrentScreenState(CURRENT)){
    case SERVER_RETURN:
      setCurrentScreen(ONLINE_SCREEN);
      break;

    default:
      setCurrentScreenState(PLAY_FIRST_VALUE + 1);
      break;
  }
}

void clientScreenAction(){
  switch (getCurrentScreenState(CURRENT)){
    case CLIENT_RETURN:
      setCurrentScreen(ONLINE_SCREEN);
      break;

    default:
      setCurrentScreenState(PLAY_FIRST_VALUE + 1);
      break;
  }
}

void handleMenuSelection(int selection){
  if(selection != KEY_ENTER && selection != KEY_SPACE)
    return;

  switch (getCurrentScreen()){
    case MENU_SCREEN:
      menuScreenAction();
      break;

    case PLAY_SCREEN:
      playScreenAction();
      break;

    case CONFIG_SCREEN:
      configScreenAction();
      break;

    case WINNER_SCREEN:
      setCurrentScreen(PLAY_SCREEN);
      break;

    case ONLINE_SCREEN:
      onlineScreenAction();
      break;

    case SERVER_SCREEN:
      serverScreenAction();
      break;

    case CLIENT_SCREEN:
      clientScreenAction();
      break;

    default:
      setCurrentScreen(MENU_SCREEN);
      setCurrentScreenState(MENU_FIRST_VALUE + 1);
      break;
  }
}

void appAction(){
  int selection = getch();

  if(selection == KEY_ARROW_DOWN){
    setCurrentScreenState(getCurrentScreenState(CURRENT) + 1);
    if(getCurrentScreenState(CURRENT) == getCurrentScreenState(LAST))
      setCurrentScreenState(getCurrentScreenState(FIRST) + 1);
  }
  else if(selection == KEY_ARROW_UP) {
    setCurrentScreenState(getCurrentScreenState(CURRENT) - 1);
    if(getCurrentScreenState(CURRENT) == getCurrentScreenState(FIRST))
      setCurrentScreenState(getCurrentScreenState(LAST) - 1);
  }
  else{
    handleMenuSelection(selection);
  }
}

void app() {
  setCurrentScreen(MENU_SCREEN);
  setCurrentScreenState(MENU_FIRST_VALUE + 1);

  while(appState.exitFlag == EXIT_STATE_NONE) {
    printCurrentScreen();

    appAction();
  }
}
