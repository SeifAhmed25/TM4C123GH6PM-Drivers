
/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : Dio.c
*  breif   : Dio Driver
*  details : 
*****************************************************************   
*
*/
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"
#include "BitMath.h"
#include "Dio_int.h"
#include "Mcu_HW.h"


/******************************************
  Local Macros / Functions  
*******************************************/


/******************************************
  Local Data 
*******************************************/



/******************************************
  Global Data 
*******************************************/





/******************************************
  Local Functions 
*******************************************/


/******************************************
  Global Functions 
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
Dio_LevelType Dio_ReadPin(Dio_pinType pinId)
{
	u8 pin = pinId % 10;
	u8 port = pinId / 10;
	u8 state;
	Dio_LevelType Local_levelType;
	switch(port)
	{
		case DIO_PORTA:
		state = GPIO_PORTA_BASE_ADDRESS->GPIODATA_REG & (1<< pin);
		break;
		case DIO_PORTB:
		state = GPIO_PORTB_BASE_ADDRESS->GPIODATA_REG   & (1<< pin); 
		break;
		case DIO_PORTC:
		state= GPIO_PORTC_BASE_ADDRESS->GPIODATA_REG & (1<< pin);
		break;
		case DIO_PORTD:
		state = GPIO_PORTD_BASE_ADDRESS->GPIODATA_REG & (1<< pin);
		break;
		case DIO_PORTE:
		state = (u8)(GPIO_PORTE_BASE_ADDRESS->GPIODATA_REG & (1<< pin));
		break;
		case DIO_PORTF:
		state = (u8)(GPIO_PORTF_BASE_ADDRESS->GPIODATA_REG & (1<< pin));
		break;
	}
	Local_levelType = (state>>pin) & 0x01;
	return Local_levelType;
}
/******************************************
  syntax : void Dio_WritePin(Dio_pinType pinId,Dio_LevelType Level)
  
  Description : write the pin   
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :  pinId (pin) ,Level (Dio_HIGH or Dio_LOW)
  parameters (out) :  Non
  Return Value     : void    
******************************************/
void Dio_WritePin(Dio_pinType pinId,Dio_LevelType Level)
{
	u8 pin = pinId % 10;
	u8 port = pinId / 10;
	
			if(Level == DIO_HIGH)
			{
				switch(port)
				{
					case DIO_PORTA: SET_BIT(GPIO_PORTA_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTB: SET_BIT(GPIO_PORTB_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTC: SET_BIT(GPIO_PORTC_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTD: SET_BIT(GPIO_PORTD_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTE: SET_BIT(GPIO_PORTE_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTF: SET_BIT(GPIO_PORTF_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    default:						    break;
				}
				
			}
			else if (Level == DIO_LOW)
			{
				switch(port)
				{
					case DIO_PORTA: CLR_BIT(GPIO_PORTA_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTB: CLR_BIT(GPIO_PORTB_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTC: CLR_BIT(GPIO_PORTC_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTD: CLR_BIT(GPIO_PORTD_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTE: CLR_BIT(GPIO_PORTE_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    case DIO_PORTF: CLR_BIT(GPIO_PORTF_BASE_ADDRESS->GPIODATA_REG ,pin); break;
			    default:				   break;
				}
				
			}
		
}

/******************************************
  syntax : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
  
  Description : Read the whole port   
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :  PortId
  parameters (out) :  Non
  Return Value     : Dio_PortLevelType    
******************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	Dio_PortLevelType Local_Reading;
	
	switch(PortId)
	{
		case DIO_PORTA:
		Local_Reading = GPIO_PORTA_BASE_ADDRESS->GPIODATA_REG & (0xFF);
		break;
		case DIO_PORTB:
		Local_Reading = GPIO_PORTB_BASE_ADDRESS->GPIODATA_REG & (0xFF);
		break;
		case DIO_PORTC:
		Local_Reading= GPIO_PORTC_BASE_ADDRESS->GPIODATA_REG & (0xFF);
		break;
		case DIO_PORTD:
		Local_Reading = GPIO_PORTD_BASE_ADDRESS->GPIODATA_REG & (0xFF);
		break;
		case DIO_PORTE:
		Local_Reading = GPIO_PORTE_BASE_ADDRESS->GPIODATA_REG & (0xFF);
		break;
		case DIO_PORTF:
		Local_Reading = GPIO_PORTF_BASE_ADDRESS->GPIODATA_REG & (0xFF);
		break;
	}
	
	return Local_Reading;
}

/******************************************
  syntax : void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);
  
  Description : write the whole port   
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void    
******************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
	switch(PortId)
	{
		case DIO_PORTA:
		GPIO_PORTA_BASE_ADDRESS->GPIODATA_REG =(u32) Level;
		break;
		case DIO_PORTB:
		GPIO_PORTB_BASE_ADDRESS->GPIODATA_REG =(u32) Level;
		break;
		case DIO_PORTC:
		GPIO_PORTC_BASE_ADDRESS->GPIODATA_REG =(u32) Level;
		break;
		case DIO_PORTD:
		GPIO_PORTD_BASE_ADDRESS->GPIODATA_REG = (u32)Level;
		break;
		case DIO_PORTE:
		GPIO_PORTE_BASE_ADDRESS->GPIODATA_REG =(u32) Level;
		break;
		case DIO_PORTF:
		GPIO_PORTF_BASE_ADDRESS->GPIODATA_REG = (u32) Level;
		break;
	}
}

/******************************************
  syntax : Dio_LevelType Dio_FlipChannel(Dio_ChannelType channelId);
  
  Description : toggle the pin state    
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void    
******************************************/
Dio_LevelType Dio_TogPin(Dio_pinType pinId)
{
	u8 pin = pinId % 10;
	u8 port = pinId/ 10;
	
	switch(port)
	{
		case DIO_PORTA:
		TOG_BIT(GPIO_PORTA_BASE_ADDRESS->GPIODATA_REG, pin);
		break;
		case DIO_PORTB:
		TOG_BIT(GPIO_PORTB_BASE_ADDRESS->GPIODATA_REG, pin);
		break;
		case DIO_PORTC:
  	TOG_BIT(GPIO_PORTC_BASE_ADDRESS->GPIODATA_REG, pin);
		break;
		case DIO_PORTD:
		TOG_BIT(GPIO_PORTD_BASE_ADDRESS->GPIODATA_REG, pin);
		break;
		case DIO_PORTE:
		TOG_BIT(GPIO_PORTE_BASE_ADDRESS->GPIODATA_REG, pin);
		break;
		case DIO_PORTF:
		TOG_BIT(GPIO_PORTF_BASE_ADDRESS->GPIODATA_REG, pin);
		break;
	}
	return 0;
}

