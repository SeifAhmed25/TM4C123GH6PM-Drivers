/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : IntCtrl_Lcfg.c
*  Module   : IntCtrl 
*  breif    : Config file for Nested vector Interrupt 
*             Controller  Driver
*  
*****************************************************************   
*/
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"
#include "IntCtrl_types.h"
#include "IntCtrl_Cfg.h"
/******************************************
  Local Macros / Functions  
*******************************************/


/******************************************
  Local Data 
*******************************************/

/******************************************
  Global Data 
*******************************************/   //
const IntCtrl_ConfigType  IntCtrl_Config_Arr[INTCTRL_CONFIG_ARR_SIZE] = {{Bit_Timer_0A_32_64_IRQ, 1,0},{SysTick_IRQ,1,0}};                                                                    	
	                                                                      


