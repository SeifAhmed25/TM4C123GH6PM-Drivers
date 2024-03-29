/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Port_Cfg.h
*  Module   : PORT 
*  breif    : Config file for PORT driver
*  
*****************************************************************   
*/
#ifndef PORT_CFG_H
#define PORT_CFG_H
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"

/******************************************
  GLOBAL CONSTANT MACROS   
*******************************************/
#define PORT_PINS_CONFIG_ARR_SIZE 5

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES 
*******************************************/
typedef struct {
	Port_PinType             Port_PinNumber; //PA0 or PA1...etc
	Port_PinModeType         Port_PinMode; // general or alternate fn
	Port_LevelType           Port_PinLevelValue;// initial value of pin
  Port_PinDirectionType    Port_PinDirection; // input or output
	Port_InternalAttachType  Port_PinInternalAttach;//pull up or pull down or open drain
  Port_PinOtputCurrentType Port_PinOutputCurrent; //2mA or 4mA or 8mA 	
}Port_ConfigType;
#endif
