/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Port.h
*  Module   : PORT 
*  breif    : header file PORT
*  
*****************************************************************   
*/
#ifndef PORT_H
#define PORT_H
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"
#include "Port_Types.h"
#include "Port_Cfg.h"

/******************************************
  GLOBAL CONSTANT MACROS   
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS 
*******************************************/


/******************************************
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/
typedef enum {STATE1,STATE2,STATE3}StateMachine;
/******************************************
  GLOBAL DATA PROTOTYPES
*******************************************/

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax : void Port_Init(const Port_ConfigType * ConfigPtr); 
  
  Description :    
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :   
  parameters (out) : none 
  Return Value     : void      
******************************************/
void Port_Init(const Port_ConfigType * ConfigPtr); 

#endif
