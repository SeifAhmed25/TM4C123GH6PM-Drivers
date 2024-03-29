/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : IntCtrl_Cfg.h
*  Module   : IntCtrl 
*  breif    : Config file for Nested vector Interrupt 
*             Controller  Driver
*  
*****************************************************************   
*/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"

/******************************************
  GLOBAL CONSTANT MACROS   
*******************************************/
/*please choose one of the following 
  INTCTRL_XXX 
  INTCTRL_XXY 
  INTCTRL_XYY 
  INTCTRL_YYY
*/
#define INTCTRL_GROUP_SUBGROUP_TYPE   INTCTRL_XXX 

#define INTCTRL_CONFIG_ARR_SIZE    2
/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES 
*******************************************/
typedef struct {
	u8 IntCtrl_IntIndx;	
	u8 IntCtrl_Group_Prio;	
	u8 IntCtrl_SubGroup_Prio;	
}IntCtrl_ConfigType;
#endif
