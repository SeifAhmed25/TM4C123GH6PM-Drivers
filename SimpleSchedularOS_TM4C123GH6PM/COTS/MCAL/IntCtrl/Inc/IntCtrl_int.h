/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : IntCtrl.h
*  Module   : IntCtrl 
*  breif    : header file for Nested vector Interrupt 
*             Controller  Driver
*  
*****************************************************************   
*/
#ifndef INTCTRL_H
#define INTCTRL_H
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"
#include "IntCtrl_types.h"
#include "IntCtrl_Cfg.h"

/******************************************
  GLOBAL CONSTANT MACROS   
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS 
*******************************************/


/******************************************
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/

/******************************************
  GLOBAL DATA PROTOTYPES
*******************************************/

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax : void IntCtrl_Init(void)
  
  Description : Initialize NVIC/SCB module by parsing 
                the configuration into NVIC/SCB registers 
				
  Synch/Asynch : Synchronouse
  Reentrance   : Reentrant  
******************************************/
void IntCtrl_Init(void);

#endif
