/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"
#ifdef OS_WIN32
  #include <windows.h>
#endif

/*---------------------------
  Variables and constants
---------------------------*/

/*---------------------------
  Functions
---------------------------*/
void setCursor(enum_cursorState cursorState){
#ifdef OS_WIN32
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = cursorState;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
#endif
}

short getXScreenSize(){
#ifdef OS_WIN32
  CONSOLE_SCREEN_BUFFER_INFO screenInfo = {0};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);

  return screenInfo.dwMaximumWindowSize.X;
#endif
}

void clearScreen(){
#ifdef OS_WIN32
  system("cls");
#endif
#ifdef OS_LINUX
  system("clear");
#endif
}