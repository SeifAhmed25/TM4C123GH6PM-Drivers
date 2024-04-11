/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Dio_Cfg.h
*  Module   : Dio 
*  breif    : contains type Definitions of Module  
*****************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H
/****************************************************************
 *							INCLUSION							*
 ****************************************************************/
#include "../../../Lib/Std_Types.h"
/****************************************************************
 *						type definitions						*
 ****************************************************************/
 /* Name: DIO_ChannelType										
  *	Type: uint													
  * Range: Shall cover all available DIO Channels 
  * Description: Numeric ID of a DIO channel					*/ 
 typedef enum{
	DIO_PA0 = 10,
	DIO_PA1 ,
	DIO_PA2 ,
	DIO_PA3 ,
	DIO_PA4 ,
	DIO_PA5 ,
	DIO_PA6 ,
	DIO_PA7 ,
	DIO_PB0 = 20,
	DIO_PB1 ,
	DIO_PB2 ,
	DIO_PB3 ,
	DIO_PB4 ,
	DIO_PB5 ,
	DIO_PB6 ,
	DIO_PB7 ,
	DIO_PC0 = 30,
	DIO_PC1 ,
	DIO_PC2 ,
	DIO_PC3 ,
	DIO_PC4 ,
	DIO_PC5 ,
	DIO_PC6 ,
	DIO_PC7 ,
	DIO_PD0 = 40,
	DIO_PD1 ,
	DIO_PD2 ,
	DIO_PD3 ,
	DIO_PD4 ,
	DIO_PD5 ,
	DIO_PD6 ,
	DIO_PD7 ,
	DIO_PE0 = 50,
	DIO_PE1 ,
	DIO_PE2 ,
	DIO_PE3 ,
	DIO_PE4 ,
	DIO_PE5 ,
	DIO_PF0 = 60,
	DIO_PF1 ,
	DIO_PF2 ,
	DIO_PF3 ,
	DIO_PF4 
}Dio_ChannelType;
/* Name: Dio_PortType														
 * Type: uint																	
 * Range: Shall cover all available DIO Ports 	 
 * Description: Numeric ID of a DIO port.						*/  
typedef enum {
	DIO_PORTA = 1, 
	DIO_PORTB,   
	DIO_PORTC,
	DIO_PORTD,
	DIO_PORTE,
	DIO_PORTF
}Dio_PortType;  
 /* Name: Dio_ChannelGroupType																								
  *	Type: Structure																														
  * Elements: uint8/16/32 	mask  	defines the positions of the channel group		
  *			  uint8 		offset 	Position of Channel group on the port					
  *			  Dio_PortType 	Port 	Port on which the Channel group is defined		
  * Description: definition of a channel group, which consists of  						
  * several Pins within a port									*/ 
typedef struct { 
	u32 		 mask; 
	u8  		 offset; 
	Dio_PortType port; 
}Dio_ChannelGroupType; 
/* Name: Dio_LevelType									
 * Type: uint8 								
 * Range: STD_HIGH		0x00		Physical State 0V				
 * 		  STD_LOW		0x01		Physical State 5V, 3.3	
 * Description: possible levels of DIO pin						*/ 
typedef enum { 
	STD_LOW = 0, 
	STD_HIGH
}Dio_LevelType; 
/* Name: Dio_PortLevelType																				
 * Type: uint																															*
 * Range: the size of the largest port												
 * Description: If the µC owns ports of different port widths						
				Dio_PortLevelType inherits the size of the largest port	
																*/ 
typedef u8 Dio_PortLevelType; 

#endif
