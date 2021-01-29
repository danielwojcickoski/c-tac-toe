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
  switch (getCurrentScreenState()){
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
  switch (getCurrentScreenState()){
    case CONFIG_RETURN:
      setCurrentScreen(MENU_SCREEN);
      break;
    
    default:
      setCurrentScreenState(CONFIG_FIRST_VALUE + 1);
      break;
  }
}

void playScreenAction(){
  switch (getCurrentScreenState()){
    case PLAY_PVP:
      setCurrentScreen(GAME_SCREEN);
      setCurrentScreenState(0);
      game(GAME_PVP);
      break;

    case PLAY_PVC:
      setCurrentScreen(GAME_SCREEN);
      setCurrentScreenState(0);
      game(GAME_PVC);
      break;

    case PLAY_ONLINE:
      setCurrentScreen(GAME_SCREEN);
      setCurrentScreenState(0);
      game(GAME_ONLINE);
      break;

    case PLAY_RETURN:
      setCurrentScreen(MENU_SCREEN);
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

    default:
      setCurrentScreen(MENU_SCREEN);
      setCurrentScreenState(MENU_FIRST_VALUE + 1);
      break;
  }
}

void appAction(){
  int selection = getch();

  if(selection == KEY_ARROW_DOWN){
    setCurrentScreenState(getCurrentScreenState() + 1);
    if(getCurrentScreenState() == getCurrentScreenLastvalue())
      setCurrentScreenState(getCurrentScreenFirstvalue() + 1);
  }
  else if(selection == KEY_ARROW_UP) {
    setCurrentScreenState(getCurrentScreenState() - 1);
    if(getCurrentScreenState() == getCurrentScreenFirstvalue())
      setCurrentScreenState(getCurrentScreenLastvalue() - 1);
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
