/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Dio.c
*  Module   : DIO 
*  breif    : This File Contains Functions Implementaion
*****************************************************************/   
#include "../Dio_MemMap.h" 
#include "Inc/Dio.h" 
/****************************************************************
 *						Functions Implementaion					* 
 ****************************************************************/
 /****************************************************************
	Service name		: Dio_ReadChannel 
	syntax 		        : Dio_LevelType Dio_ReadChannel(
				      Dio_ChannelType ChannelId
				  )
	Service ID [hex]	: 0x00  
	Synch/Asynch     	: Synchronouse
	Reentrance       	: Reentrant 
	Parameters (in)  	: ChannelId (ID of DIO Channel) 
	Parameters (inout)	: None 
	Parameters (out)	: None
	Return Value     	: Dio_LevelType (STD_HIGH, STD_LOW)     
*****************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
	u8 pin  = ChannelId % 10;
	u8 port = ChannelId / 10;
	Dio_LevelType ChannelState = 0;
	switch(port)
	{
		case DIO_PORTA:
		ChannelState = (u8)(((GPIO_PORTA_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
		case DIO_PORTB:
		ChannelState = (u8)(((GPIO_PORTB_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin); 
		break;
		case DIO_PORTC:
		ChannelState = (u8)(((GPIO_PORTC_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
		case DIO_PORTD:
		ChannelState = (u8)(((GPIO_PORTD_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
		case DIO_PORTE:
		ChannelState = (u8)(((GPIO_PORTE_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
		case DIO_PORTF:
		ChannelState = (u8)(((GPIO_PORTF_BASE_ADDRESS -> GPIODATA_REG) & (1<< pin)) >> pin);
		break; 
		default:
		break;
	}
	return ChannelState;
} 
/**************************************************************** 
	Service name		: Dio_WriteChannel 
	syntax 			: void Dio_WriteChannel(
					Dio_ChannelType ChannelId,
					Dio_LevelType Level
				  )
	Service ID		: 0x01     
	Synch/Asynch     	: Synchronouse
	Reentrance       	: Reentrant 
	Parameters (in)  	: ChannelId (ID of DIO channel),
						  Level 	(Value to be written)
	Parameters (inout)	: none 
	Parameters (out)	: none 
	Return Value     	: none 
	Description			: Service to set a level of a channel.
*****************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level){ 
	u8 pin  = ChannelId % 10;
	u8 port = ChannelId / 10;
	if(Level == STD_HIGH)
	{
		switch(port)
		{
			case DIO_PORTA:
			(GPIO_PORTA_BASE_ADDRESS -> GPIODATA_REG) |= (1 << pin);
			break;
			case DIO_PORTB:
			(GPIO_PORTB_BASE_ADDRESS -> GPIODATA_REG) |= (1 << pin);
			break;
			case DIO_PORTC:
			(GPIO_PORTC_BASE_ADDRESS -> GPIODATA_REG) |= (1 << pin);
			break;
			case DIO_PORTD:
			(GPIO_PORTD_BASE_ADDRESS -> GPIODATA_REG) |= (1 << pin);
			break;
			case DIO_PORTE:
			(GPIO_PORTE_BASE_ADDRESS -> GPIODATA_REG) |= (1 << pin);
			break;
			case DIO_PORTF:
			(GPIO_PORTF_BASE_ADDRESS -> GPIODATA_REG) |= (1 << pin);
			break;
			default: 
			break;
		}			
	}
	else if (Level == STD_LOW)
	{
		switch(port)
		{
			case DIO_PORTA:
			(GPIO_PORTA_BASE_ADDRESS -> GPIODATA_REG) &= ~ (1 << pin);
			break;
			case DIO_PORTB:
			(GPIO_PORTB_BASE_ADDRESS -> GPIODATA_REG) &= ~ (1 << pin);
			break;
			case DIO_PORTC:
			(GPIO_PORTC_BASE_ADDRESS -> GPIODATA_REG) &= ~ (1 << pin);
			break;
			case DIO_PORTD:
			(GPIO_PORTD_BASE_ADDRESS -> GPIODATA_REG) &= ~ (1 << pin);
			break;
			case DIO_PORTE:
			(GPIO_PORTE_BASE_ADDRESS -> GPIODATA_REG) &= ~ (1 << pin);
			break;
			case DIO_PORTF:
			(GPIO_PORTF_BASE_ADDRESS -> GPIODATA_REG) &= ~ (1 << pin);
			break;
			default:
			break;
		}		
	}
}
/****************************************************************
	Service name		: Dio_ReadPort
	syntax 			: Dio_PortLevelType Dio_ReadPort(
					Dio_PortType PortId
				  )
	Service ID [hex] 	: 0x02 
	Synch/Asynch     	: Synchronouse
	Reentrancy       	: Reentrant 
	Parameters (in)  	: PortId (ID of DIO Port)
	Parameters (inout)	: none
	Parameters (out)	: none
	Return Value     	: Dio_PortLevelType (Level of all channels of that Port)  
	Description 		: Returns the level of all channels of that port. 
******************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID){
	Dio_PortLevelType PortValue = 0; 
	switch (PortID)
	{
		case DIO_PORTA: 
		PortValue = (u8)(GPIO_PORTA_BASE_ADDRESS -> GPIODATA_REG);
		break; 
		case DIO_PORTB: 
		PortValue = (u8)(GPIO_PORTB_BASE_ADDRESS -> GPIODATA_REG);
		break;
		case DIO_PORTC: 
		PortValue = (u8)(GPIO_PORTC_BASE_ADDRESS -> GPIODATA_REG);
		break;
		case DIO_PORTD: 
		PortValue = (u8)(GPIO_PORTD_BASE_ADDRESS -> GPIODATA_REG);
		break;
		case DIO_PORTE: 
		PortValue = (u8)(GPIO_PORTE_BASE_ADDRESS -> GPIODATA_REG);
		break;
		case DIO_PORTF: 
		PortValue = (u8)(GPIO_PORTF_BASE_ADDRESS -> GPIODATA_REG);
		break; 
	}
	return PortValue; 
}
/***************************************************************** 
	Service name		: Dio_WritePort
	syntax 			: void Dio_WritePort(
					Dio_PortType PortId,
					Dio_PortLevelType Level
				  )
	Service ID[hex]		: 0x03  
	Synch/Asynch     	: Synchronouse
	Reentrance       	: Reentrant 
	Parameters (in)  	: PortId (ID of DIO Port),
						  Level  (Value to be written)
	Parameters (inout)	: none 
	Parameters (out)	: none
	Return Value     	: none  
	Description 		: Service to set a value of the port.
*****************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){
	switch (PortId)
	{
		case DIO_PORTA: 
		(GPIO_PORTA_BASE_ADDRESS -> GPIODATA_REG) = (u32) Level;
		break; 
		case DIO_PORTB: 
		(GPIO_PORTB_BASE_ADDRESS -> GPIODATA_REG) = (u32) Level;
		break;
		case DIO_PORTC: 
		(GPIO_PORTC_BASE_ADDRESS -> GPIODATA_REG) = (u32) Level;
		break;
		case DIO_PORTD: 
		(GPIO_PORTD_BASE_ADDRESS -> GPIODATA_REG) = (u32) Level;
		break;
		case DIO_PORTE: 
		(GPIO_PORTE_BASE_ADDRESS -> GPIODATA_REG) = (u32) Level;
		break;
		case DIO_PORTF: 
		(GPIO_PORTF_BASE_ADDRESS -> GPIODATA_REG) = (u32) Level;
		break;
	}
} 
/****************************************************************
	Service name		: Dio_ReadChannelGroup
	syntax 			: Dio_PortLevelType Dio_ReadChannelGroup(
					const Dio_ChannelGroupType* ChannelGroupIdPtr
				  )
	Service ID[hex]		: 0x04
	Synch/Asynch     	: Synchronouse
	Reentrance       	: Reentrant 
	Parameters (in)  	: ChannelGroupPtr (Pointer to ChannelGroup)
	Parameters (inout)	: none 
	Parameters (out)	: none
	Return Value     	: none   
	Description 		: This Service reads a subset of the adjoining bits of a port
*****************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr){
	Dio_PortLevelType ChannelGroupValue;
	switch (ChannelGroupIdPtr -> port)
	{
		case DIO_PORTA: 
		ChannelGroupValue  = (u8)((GPIO_PORTA_BASE_ADDRESS -> GPIODATA_REG) >> (ChannelGroupIdPtr -> offset));
		ChannelGroupValue &= (ChannelGroupIdPtr -> mask); 
		break; 
		case DIO_PORTB:
		ChannelGroupValue  = (u8)((GPIO_PORTB_BASE_ADDRESS -> GPIODATA_REG) >> (ChannelGroupIdPtr -> offset));
		ChannelGroupValue &= (ChannelGroupIdPtr -> mask);
		break;
		case DIO_PORTC: 
		ChannelGroupValue  = (u8)((GPIO_PORTC_BASE_ADDRESS -> GPIODATA_REG) >> (ChannelGroupIdPtr -> offset));
		ChannelGroupValue &= (ChannelGroupIdPtr -> mask);
		break;
		case DIO_PORTD: 
		ChannelGroupValue  = (u8)((GPIO_PORTD_BASE_ADDRESS -> GPIODATA_REG) >> (ChannelGroupIdPtr -> offset));
		ChannelGroupValue &= (ChannelGroupIdPtr -> mask);
		break;
		case DIO_PORTE: 
		ChannelGroupValue  = (u8)((GPIO_PORTE_BASE_ADDRESS -> GPIODATA_REG) >> (ChannelGroupIdPtr -> offset));
		ChannelGroupValue &= (ChannelGroupIdPtr -> mask);
		break;
		case DIO_PORTF: 
		ChannelGroupValue  = (u8)((GPIO_PORTF_BASE_ADDRESS -> GPIODATA_REG) >> (ChannelGroupIdPtr -> offset));
		ChannelGroupValue &= (ChannelGroupIdPtr -> mask);
		break;
	} 
	return ChannelGroupValue; 
} 
/*****************************************************************
	Service name		: Dio_WriteChannelGroup
	syntax 			: void Dio_WriteChannelGroup(
					const Dio_ChannelGroupType* ChannelGroupIdPtr,
					Dio_PortLevelType Level
				  ) 
	Service ID[hex]		: 0x05
	Synch/Asynch     	: Synchronouse
	Reentrance       	: Reentrant 
	Parameters (in)  	: ChannelGroupPtr (Pointer to ChannelGroup)
				  Level           (Value to be Written)
	Parameters (inout)      : none 
	Parameters (out)	: none
	Return Value     	: none   
	Description 		: Service to set a subset of the adjoining bits of a port to a specified level.
*****************************************************************/ 
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level){
	switch (ChannelGroupIdPtr -> port)
	{
		case DIO_PORTA: 
		(GPIO_PORTA_BASE_ADDRESS -> GPIODATA_REG) |= (u32)(Level << (ChannelGroupIdPtr -> offset));
		break; 
		case DIO_PORTB: 
		(GPIO_PORTB_BASE_ADDRESS -> GPIODATA_REG) |= (u32)(Level << (ChannelGroupIdPtr -> offset));
		break;
		case DIO_PORTC: 
		(GPIO_PORTC_BASE_ADDRESS -> GPIODATA_REG) |= (u32)(Level << (ChannelGroupIdPtr -> offset));
		break;
		case DIO_PORTD: 
		(GPIO_PORTD_BASE_ADDRESS -> GPIODATA_REG) |= (u32)(Level << (ChannelGroupIdPtr -> offset));
		break;
		case DIO_PORTE: 
		(GPIO_PORTE_BASE_ADDRESS -> GPIODATA_REG) |= (u32)(Level << (ChannelGroupIdPtr -> offset));
		break;
		case DIO_PORTF: 
		(GPIO_PORTF_BASE_ADDRESS -> GPIODATA_REG) |= (u32)(Level << (ChannelGroupIdPtr -> offset));
		break;
	}
}
/****************************************************************
	Service name		: Dio_FlipChannel
	Syntax 			: Dio_LevelType Dio_FlipChannel(
					Dio_ChannelType channelId
				  )
	Service ID[hex]		: 0x011
	Synch/Asynch     	: Synchronouse
	Reentrance       	: Reentrant 
	parameters (in)  	: ChannelId (ID of DIO Channel)
	parameters (inout)	: none
	Return Value     	: none  
	Description 		: Service to flip (change from 1 to 0 or from 0 to 1)
											 the level of a channel and return the level of the channel after flip.    
*****************************************************************/
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId){ 
	u8 pin  = ChannelId % 10;
	u8 port = ChannelId / 10; 
	Dio_LevelType ChannelState = 0; 
	switch(port)
	{
		case DIO_PORTA:
		(GPIO_PORTA_BASE_ADDRESS -> GPIODATA_REG) ^= (1 << pin);
		ChannelState = (u8)(((GPIO_PORTA_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
		case DIO_PORTB:
		(GPIO_PORTB_BASE_ADDRESS -> GPIODATA_REG) ^= (1 << pin);
		ChannelState = (u8)(((GPIO_PORTB_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
		case DIO_PORTC:
		(GPIO_PORTC_BASE_ADDRESS -> GPIODATA_REG) ^= (1 << pin);
		ChannelState = (u8)(((GPIO_PORTC_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
		case DIO_PORTD:
		(GPIO_PORTD_BASE_ADDRESS -> GPIODATA_REG) ^= (1 << pin);
		ChannelState = (u8)(((GPIO_PORTD_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
		case DIO_PORTE:
		(GPIO_PORTE_BASE_ADDRESS -> GPIODATA_REG) ^= (1 << pin);
		ChannelState = (u8)(((GPIO_PORTE_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
		case DIO_PORTF:
		(GPIO_PORTF_BASE_ADDRESS -> GPIODATA_REG) ^= (1 << pin);
		ChannelState = (u8)(((GPIO_PORTF_BASE_ADDRESS -> GPIODATA_REG) & (1 << pin)) >> pin);
		break;
	}	
	return ChannelState;
}

/*****************************************************************/
