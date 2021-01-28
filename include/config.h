/*---------------------------
  Includes
---------------------------*/

/*---------------------------
  Variables and Constants
---------------------------*/
typedef struct{
  unsigned int bgColor;
  unsigned int textColor;
  unsigned char * playerName;
} type_appConfigs;
type_appConfigs appConfigs;

/*---------------------------
  Functions
---------------------------*/
void parseConfigs();