
/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : Port_prg.c
*  breif   : Port Driver
*  details : 
*****************************************************************   
*
*/
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"
#include "BitMath.h"
#include "Port_int.h"
#include "Mcu_HW.h"


/******************************************
  Local Macros / Functions  
*******************************************/
#define  GPIO_UNLOCK_KEY 0x4C4F434B

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
  syntax : void Port_Init(const Port_ConfigType * ConfigPtr); 
  
  Description :    
				
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant 
  parameters (in)  :   
  parameters (out) : none 
  Return Value     : void   
******************************************/
void Port_Init(const Port_ConfigType * ConfigPtr)
{
	extern StateMachine g_state ;
   g_state = STATE2;
	if(ConfigPtr == NULL)
	{
		// To do Report Error
	}
	else 
	{
		u8 i;
		u8 Local_pin;
		u8 Local_port;
		for(i= 0;i<PORT_PINS_CONFIG_ARR_SIZE;i++)
		{
			Local_pin =(ConfigPtr[i].Port_PinNumber)%10 ;
			Local_port =(ConfigPtr[i].Port_PinNumber)/10 ;
			// step 0 : Initiate clock 
				switch(Local_port)
			{
					case PORT_PORTA:
							SET_BIT(RCC_RCGCGPIO_REG,0);
						break;
					case PORT_PORTB:
							SET_BIT(RCC_RCGCGPIO_REG,1);
						break;
					case PORT_PORTC:
							SET_BIT(RCC_RCGCGPIO_REG,2);
						break;
					case PORT_PORTD:
							SET_BIT(RCC_RCGCGPIO_REG,3);
						break;
					case PORT_PORTE:
						SET_BIT(RCC_RCGCGPIO_REG,4);
						break;
					case PORT_PORTF:
						SET_BIT(RCC_RCGCGPIO_REG,5);
			
					 GPIO_PORTF_BASE_ADDRESS->GPIOLOCK_REG = GPIO_UNLOCK_KEY;   // unlock GPIO Port F
           GPIO_PORTF_BASE_ADDRESS->GPIOCR_REG = 0x1F;           // allow changes to PF4-0
						break;
			}
			// step 1 : set direction
			if(ConfigPtr[i].Port_PinDirection == PORT_PINDIR_INPUT || ConfigPtr[i].Port_PinDirection ==PORT_PINDIR_OUTPUT)
	    {
				switch(Local_port)
			 {
				case PORT_PORTA:
				 GPIO_PORTA_BASE_ADDRESS->GPIODIR_REG |= (u32)(ConfigPtr[i].Port_PinDirection<< Local_pin);
				break;
				case PORT_PORTB:
				 GPIO_PORTB_BASE_ADDRESS->GPIODIR_REG |= (u32)(ConfigPtr[i].Port_PinDirection << Local_pin);
				break;
				case PORT_PORTC:
				 GPIO_PORTC_BASE_ADDRESS->GPIODIR_REG |= (u32)(ConfigPtr[i].Port_PinDirection << Local_pin);
				break;
				case PORT_PORTD:
				GPIO_PORTD_BASE_ADDRESS->GPIODIR_REG |= (u32)(ConfigPtr[i].Port_PinDirection << Local_pin);
				break;
				case PORT_PORTE:
				GPIO_PORTE_BASE_ADDRESS->GPIODIR_REG |= (u32)(ConfigPtr[i].Port_PinDirection << Local_pin);
				break;
				case PORT_PORTF:
				GPIO_PORTF_BASE_ADDRESS->GPIODIR_REG |= (u32)(ConfigPtr[i].Port_PinDirection << Local_pin);
				break;
				default :break;
					// TODO (Report Error)
				}//switch
				// step 2 : config initial pin value 
        if(ConfigPtr[i].Port_PinLevelValue == PORT_PIN_LEVEL_LOW || ConfigPtr[i].Port_PinLevelValue == PORT_PIN_LEVEL_HIGH)	
				{
					
					switch(Local_port)
			   {
					case PORT_PORTA:
			
					 GPIO_PORTA_BASE_ADDRESS->GPIODATA_REG |= (u32)(ConfigPtr[i].Port_PinLevelValue<< Local_pin);
					break;
					case PORT_PORTB:
				
					 GPIO_PORTB_BASE_ADDRESS->GPIODATA_REG |= (u32)(ConfigPtr[i].Port_PinLevelValue << Local_pin);
					break;
					case PORT_PORTC:
				
					 GPIO_PORTC_BASE_ADDRESS->GPIODATA_REG |= (u32)(ConfigPtr[i].Port_PinLevelValue << Local_pin);
					break;
					case PORT_PORTD:
			
					GPIO_PORTD_BASE_ADDRESS->GPIODATA_REG |= (u32)(ConfigPtr[i].Port_PinLevelValue << Local_pin);
					break;
					case PORT_PORTE:
		
					GPIO_PORTE_BASE_ADDRESS->GPIODATA_REG |= (u32)(ConfigPtr[i].Port_PinLevelValue << Local_pin);
					break;
					case PORT_PORTF:
				
					GPIO_PORTF_BASE_ADDRESS->GPIODATA_REG |= (u32)(ConfigPtr[i].Port_PinLevelValue << Local_pin);
					break;
					default :break;
						// TODO (Report Error)
					}//switch
				  //step 3 : config output current
					if( ConfigPtr[i].Port_PinOutputCurrent<= PORT_8_mA )
					{
						
						switch(Local_port)
						{
							case PORT_PORTA:
						  switch(ConfigPtr[i].Port_PinOutputCurrent)  
							{
								case PORT_2_mA:
									GPIO_PORTA_BASE_ADDRESS->GPIODR2R_REG |= (1<< Local_pin);
									break;
								case PORT_4_mA:
									GPIO_PORTA_BASE_ADDRESS->GPIODR4R_REG |= (1<< Local_pin);
									break;
                case PORT_8_mA:
									GPIO_PORTA_BASE_ADDRESS->GPIODR8R_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
						break;
						case PORT_PORTB:
						 switch(ConfigPtr[i].Port_PinOutputCurrent)
							{
								case PORT_2_mA:
									GPIO_PORTB_BASE_ADDRESS->GPIODR2R_REG |= (1<< Local_pin);
									break;
								case PORT_4_mA:
									GPIO_PORTB_BASE_ADDRESS->GPIODR4R_REG |= (1<< Local_pin);
									break;
                case PORT_8_mA:
									GPIO_PORTB_BASE_ADDRESS->GPIODR8R_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
						break;
						case PORT_PORTC:
						 switch(ConfigPtr[i].Port_PinOutputCurrent)
							{
								case PORT_2_mA:
									GPIO_PORTC_BASE_ADDRESS->GPIODR2R_REG |= (1<< Local_pin);
									break;
								case PORT_4_mA:
									GPIO_PORTC_BASE_ADDRESS->GPIODR4R_REG |= (1<< Local_pin);
									break;
                case PORT_8_mA:
									GPIO_PORTC_BASE_ADDRESS->GPIODR8R_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
						break;
						case PORT_PORTD:
						switch(ConfigPtr[i].Port_PinOutputCurrent)
							{
								case PORT_2_mA:
									GPIO_PORTD_BASE_ADDRESS->GPIODR2R_REG |= (1<< Local_pin);
									break;
								case PORT_4_mA:
									GPIO_PORTD_BASE_ADDRESS->GPIODR4R_REG |= (1<< Local_pin);
									break;
                case PORT_8_mA:
									GPIO_PORTD_BASE_ADDRESS->GPIODR8R_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
						break;
						case PORT_PORTE:
						switch(ConfigPtr[i].Port_PinOutputCurrent)
							{
								case PORT_2_mA:
									GPIO_PORTE_BASE_ADDRESS->GPIODR2R_REG |= (1<< Local_pin);
									break;
								case PORT_4_mA:
									GPIO_PORTE_BASE_ADDRESS->GPIODR4R_REG |= (1<< Local_pin);
									break;
                case PORT_8_mA:
									GPIO_PORTE_BASE_ADDRESS->GPIODR8R_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
						break;
						case PORT_PORTF:
						switch(ConfigPtr[i].Port_PinOutputCurrent)
							{
								case PORT_2_mA:
									GPIO_PORTF_BASE_ADDRESS->GPIODR2R_REG |= (1<< Local_pin);
									break;
								case PORT_4_mA:
									GPIO_PORTF_BASE_ADDRESS->GPIODR4R_REG |= (1<< Local_pin);
									break;
                case PORT_8_mA:
									GPIO_PORTF_BASE_ADDRESS->GPIODR8R_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
						break;
						default :break;
							// TODO (Report Error)
						}//switch
						// step 4 : config Intrnal Attach 
						switch(Local_port)
						{
							case PORT_PORTA:
							switch(ConfigPtr[i].Port_PinInternalAttach)
							{
								case PORT_PIN_IN_ATTATCH_OPENDRAIN:
									GPIO_PORTA_BASE_ADDRESS->GPIOODR_REG |= (1<< Local_pin);
									break;
								case PORT_PIN_IN_ATTATCH_PULLUP:
									GPIO_PORTA_BASE_ADDRESS->GPIOPUR_REG |= (1<< Local_pin);
									break;
                case PORT_PIN_IN_ATTATCH_PULLDOWN:
									GPIO_PORTA_BASE_ADDRESS->GPIOPDR_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
							break;
							case PORT_PORTB:
							 switch(ConfigPtr[i].Port_PinInternalAttach)
								{
									case PORT_PIN_IN_ATTATCH_OPENDRAIN:
										GPIO_PORTB_BASE_ADDRESS->GPIOODR_REG |= (1<< Local_pin);
										break;
									case PORT_PIN_IN_ATTATCH_PULLUP:
										GPIO_PORTB_BASE_ADDRESS->GPIOPUR_REG |= (1<< Local_pin);
										break;
									case PORT_PIN_IN_ATTATCH_PULLDOWN:
										GPIO_PORTB_BASE_ADDRESS->GPIOPDR_REG |= (1<< Local_pin);
										break;
									default :break;
									 // TODO (Report Error)									
								}
							break;
							case PORT_PORTC:
							 switch(ConfigPtr[i].Port_PinInternalAttach)
							{
								case PORT_PIN_IN_ATTATCH_OPENDRAIN:
									GPIO_PORTC_BASE_ADDRESS->GPIOODR_REG |= (1<< Local_pin);
									break;
								case PORT_PIN_IN_ATTATCH_PULLUP:
									GPIO_PORTC_BASE_ADDRESS->GPIOPUR_REG |= (1<< Local_pin);
									break;
                case PORT_PIN_IN_ATTATCH_PULLDOWN:
									GPIO_PORTC_BASE_ADDRESS->GPIOPDR_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
							break;
							case PORT_PORTD:
							switch(ConfigPtr[i].Port_PinInternalAttach)
							{
								case PORT_PIN_IN_ATTATCH_OPENDRAIN:
									GPIO_PORTD_BASE_ADDRESS->GPIOODR_REG |= (1<< Local_pin);
									break;
								case PORT_PIN_IN_ATTATCH_PULLUP:
									GPIO_PORTD_BASE_ADDRESS->GPIOPUR_REG |= (1<< Local_pin);
									break;
                case PORT_PIN_IN_ATTATCH_PULLDOWN:
									GPIO_PORTD_BASE_ADDRESS->GPIOPDR_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
							break;
							case PORT_PORTE:
							switch(ConfigPtr[i].Port_PinInternalAttach)
							{
								case PORT_PIN_IN_ATTATCH_OPENDRAIN:
									GPIO_PORTE_BASE_ADDRESS->GPIOODR_REG |= (1<< Local_pin);
									break;
								case PORT_PIN_IN_ATTATCH_PULLUP:
									GPIO_PORTE_BASE_ADDRESS->GPIOPUR_REG |= (1<< Local_pin);
									break;
                case PORT_PIN_IN_ATTATCH_PULLDOWN:
									GPIO_PORTE_BASE_ADDRESS->GPIOPDR_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
							break;
							case PORT_PORTF:
							switch(ConfigPtr[i].Port_PinInternalAttach)
							{
								case PORT_PIN_IN_ATTATCH_OPENDRAIN:
									GPIO_PORTF_BASE_ADDRESS->GPIOODR_REG |= (1<< Local_pin);
									break;
								case PORT_PIN_IN_ATTATCH_PULLUP:
									GPIO_PORTF_BASE_ADDRESS->GPIOPUR_REG |= (1<< Local_pin);
									break;
                case PORT_PIN_IN_ATTATCH_PULLDOWN:
									GPIO_PORTF_BASE_ADDRESS->GPIOPDR_REG |= (1<< Local_pin);
									break;
                default :break;
                 // TODO (Report Error)									
							}
							break;
							default :break;
								// TODO (Report Error)
						}//switch 
						//step 5 : config pin Mode 
						if(ConfigPtr[i].Port_PinMode == PORT_PINMODE_DEN)// digital Mode
						{
							switch(Local_port)
							 {
								case PORT_PORTA:
								// clear the corresponding bit in GPIOAFSEL_REG to disable ulternate fn
								CLR_BIT( GPIO_PORTA_BASE_ADDRESS->GPIOAFSEL_REG , Local_pin);
								// set the coresponding bit in  GPIODEN_REG to enable digital fn
								SET_BIT( GPIO_PORTA_BASE_ADDRESS->GPIODEN_REG , Local_pin);
								// clear the coresponding bit in GPIOAMSEL_REG to disable analog fn 
								CLR_BIT( GPIO_PORTA_BASE_ADDRESS->GPIOAMSEL_REG , Local_pin);
								break;
								case PORT_PORTB:
								 // clear the corresponding bit in GPIOAFSEL_REG to disable ulternate fn
								CLR_BIT( GPIO_PORTB_BASE_ADDRESS->GPIOAFSEL_REG , Local_pin);
								// set the coresponding bit in  GPIODEN_REG to enable digital fn
								SET_BIT( GPIO_PORTB_BASE_ADDRESS->GPIODEN_REG , Local_pin);
								// clear the coresponding bit in GPIOAMSEL_REG to disable analog fn 
								CLR_BIT( GPIO_PORTB_BASE_ADDRESS->GPIOAMSEL_REG , Local_pin);
								break;
								case PORT_PORTC:
								// clear the corresponding bit in GPIOAFSEL_REG to disable ulternate fn
								CLR_BIT( GPIO_PORTC_BASE_ADDRESS->GPIOAFSEL_REG , Local_pin);
								// set the coresponding bit in  GPIODEN_REG to enable digital fn
								SET_BIT( GPIO_PORTC_BASE_ADDRESS->GPIODEN_REG , Local_pin);
								// clear the coresponding bit in GPIOAMSEL_REG to disable analog fn 
								CLR_BIT( GPIO_PORTC_BASE_ADDRESS->GPIOAMSEL_REG , Local_pin);
								break;
								case PORT_PORTD:
								// clear the corresponding bit in GPIOAFSEL_REG to disable ulternate fn
								CLR_BIT( GPIO_PORTD_BASE_ADDRESS->GPIOAFSEL_REG , Local_pin);
								// set the coresponding bit in  GPIODEN_REG to enable digital fn
								SET_BIT( GPIO_PORTD_BASE_ADDRESS->GPIODEN_REG , Local_pin);
								// clear the coresponding bit in GPIOAMSEL_REG to disable analog fn 
								CLR_BIT( GPIO_PORTD_BASE_ADDRESS->GPIOAMSEL_REG , Local_pin);
								break;
								case PORT_PORTE:
								// clear the corresponding bit in GPIOAFSEL_REG to disable ulternate fn
								CLR_BIT( GPIO_PORTE_BASE_ADDRESS->GPIOAFSEL_REG , Local_pin);
								// set the coresponding bit in  GPIODEN_REG to enable digital fn
								SET_BIT( GPIO_PORTE_BASE_ADDRESS->GPIODEN_REG , Local_pin);
								// clear the coresponding bit in GPIOAMSEL_REG to disable analog fn 
								CLR_BIT( GPIO_PORTE_BASE_ADDRESS->GPIOAMSEL_REG , Local_pin);
								break;
								case PORT_PORTF:
								// clear the corresponding bit in GPIOAFSEL_REG to disable ulternate fn
								CLR_BIT( GPIO_PORTF_BASE_ADDRESS->GPIOAFSEL_REG , Local_pin);
								// set the coresponding bit in  GPIODEN_REG to enable digital fn
								SET_BIT( GPIO_PORTF_BASE_ADDRESS->GPIODEN_REG , Local_pin);
								// clear the coresponding bit in GPIOAMSEL_REG to disable analog fn 
								CLR_BIT( GPIO_PORTF_BASE_ADDRESS->GPIOAMSEL_REG , Local_pin);
								break;
								default :break;
									// TODO (Report Error)
								}//switch
						}//ConfigPtr[i].Port_PinMode == PORT_PINMODE_DEN
					}//if config output current
					else
					{
							//TODO : Report Error
					    break;
					}//else
				}//if
        else{
					//TODO : Report Error
					break;
				}//else 
         				
			}//if
			else
			{
				//TODO : Report Error
				break;
			}
			
		}//for
	}//else 
}//fn
