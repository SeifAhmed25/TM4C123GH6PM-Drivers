/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Dio.h
*  Module   : DIO 
*  breif    : header file DIO
*****************************************************************   
*/
#ifndef DIO_H
#define DIO_H  
/****************************************************************
 *							INCLUSION							*
 ****************************************************************/
#include "Dio_Cfg.h" 
/****************************************************************
 *						Functions Prototypes					* 
 ****************************************************************/
/****************************************************************
	Service name		: Dio_ReadChannel 
	syntax 				: Dio_LevelType Dio_ReadChannel(
							Dio_pinType pinId
						  )
	Service ID [hex]	: 0x00  
	Synch/Asynch     	: Synchronouse
	Reentrance       	: Reentrant 
	Parameters (in)  	: ChannelId (ID of DIO Channel) 
	Parameters (inout)	: None 
	Parameters (out)	: None
	Return Value     	: Dio_LevelType (STD_HIGH, STD_LOW)     
*****************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType PinID);
/**************************************************************** 
	Service name		: Dio_WriteChannel 
	syntax 				: void Dio_WriteChannel(
							Dio_ChannelType ChannelId,
							Dio_LevelType Level
						  )
	Service ID			: 0x01   
	Description : write the pin   
	Synch/Asynch     	: Synchronouse
	Reentrance       	: Reentrant 
	Parameters (in)  	: ChannelId (ID of DIO channel),
						  Level 	(Value to be written)
	Parameters (inout)	: none 
	Parameters (out)	: none 
	Return Value     	: none 
	Description			: Service to set a level of a channel.
*****************************************************************/
void Dio_WriteChannel(Dio_ChannelType PinID , Dio_LevelType State); 
/****************************************************************
	Service name		: Dio_ReadPort
	syntax 				: Dio_PortLevelType Dio_ReadPort(
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
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID); 
/***************************************************************** 
	Service name		: Dio_WritePort
	syntax 				: void Dio_WritePort(
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
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level); 
/****************************************************************
	Service name		: Dio_ReadChannelGroup
	syntax 				: Dio_PortLevelType Dio_ReadChannelGroup(
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
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);
/*****************************************************************
	Service name		: Dio_WriteChannelGroup
	syntax 				: void Dio_WriteChannelGroup(
							const Dio_ChannelGroupType* ChannelGroupIdPtr,
							Dio_PortLevelType Level
						  ) 
	Service ID[hex]		: 0x05
	Synch/Asynch     	: Synchronouse
	Reentrance       	: Reentrant 
	Parameters (in)  	: ChannelGroupPtr (Pointer to ChannelGroup)
						  Level (Value to be Written)
	Parameters (inout): none 
	Parameters (out)	: none
	Return Value     	: none   
	Description 		: Service to set a subset of the adjoining bits of a port to a specified level.
*****************************************************************/ 
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);
/****************************************************************
	Service name		: Dio_FlipChannel
	Syntax 				: Dio_LevelType Dio_FlipChannel(
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
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);
#endif
