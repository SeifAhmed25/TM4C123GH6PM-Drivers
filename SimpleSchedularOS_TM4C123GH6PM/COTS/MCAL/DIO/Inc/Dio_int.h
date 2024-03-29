/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Dio.h
*  Module   : DIO 
*  breif    : header file DIO
*  
*****************************************************************   
*/
#ifndef DIO_H
#define DIO_H
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"
#include "Dio_types.h"

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
  syntax : Dio_LevelType Dio_ReadPin(Dio_pinType pinId);
  
  Description : read the pin state   
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :  pinId (pin) 
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW     
******************************************/
Dio_LevelType Dio_ReadPin(Dio_pinType pinId);
/******************************************
  syntax : void Dio_WritePin(Dio_pinType pinId,Dio_LevelType Level);
  
  Description : write the pin   
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :  pinId (pin) ,Level (Dio_HIGH or Dio_LOW)
  parameters (out) :  Non
  Return Value     : void    
******************************************/
void Dio_WritePin(Dio_pinType pinId,Dio_LevelType Level);

/******************************************
  syntax : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
  
  Description : Read the whole port   
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :  PortId
  parameters (out) :  Non
  Return Value     : Dio_PortLevelType    
******************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/******************************************
  syntax : void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);
  
  Description : write the whole port   
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void    
******************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);

/******************************************
  syntax : Dio_LevelType Dio_TogPin(Dio_pinType pinId);
  
  Description : toggle the pin state    
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void    
******************************************/
Dio_LevelType Dio_TogPin(Dio_pinType pinId);
#endif
