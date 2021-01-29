/*---------------------------
  Includes
---------------------------*/

/*---------------------------
  Variables and Constants
---------------------------*/
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
void app();