/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Port_Lcfg.c
*  Module   : PORT
*  breif    : Config file for PORT Driver
*  
*****************************************************************   
*/
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"
#include "Port_Types.h"
#include "Port_Cfg.h"


/******************************************
  Local Macros / Functions  
*******************************************/


/******************************************
  Local Data 
*******************************************/

/******************************************
  Global Data 
*******************************************/

const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE]= {
	                      
											   {PORT_PF1, 
											   PORT_PINMODE_DEN, 
											   PORT_PIN_LEVEL_LOW, 
											   PORT_PINDIR_OUTPUT, 
											   PORT_PIN_IN_ATTATCH_PULLUP ,
											   PORT_8_mA},
                         {PORT_PF2, 
											   PORT_PINMODE_DEN, 
											   PORT_PIN_LEVEL_LOW, 
											   PORT_PINDIR_OUTPUT, 
											   PORT_PIN_IN_ATTATCH_PULLUP ,
											   PORT_8_mA},
                        {PORT_PF3, 
											   PORT_PINMODE_DEN, 
											   PORT_PIN_LEVEL_LOW, 
											   PORT_PINDIR_OUTPUT, 
											   PORT_PIN_IN_ATTATCH_PULLUP ,
											   PORT_8_mA},
                        {PORT_PF4, 
												PORT_PINMODE_DEN, 
												PORT_PIN_LEVEL_LOW, 
												PORT_PINDIR_INPUT, 
												PORT_PIN_IN_ATTATCH_PULLUP,
												PORT_8_mA},
                        {PORT_PF0, 
												PORT_PINMODE_DEN, 
												PORT_PIN_LEVEL_LOW, 
												PORT_PINDIR_INPUT, 
												PORT_PIN_IN_ATTATCH_PULLUP,
												PORT_8_mA}    };
												 
												 