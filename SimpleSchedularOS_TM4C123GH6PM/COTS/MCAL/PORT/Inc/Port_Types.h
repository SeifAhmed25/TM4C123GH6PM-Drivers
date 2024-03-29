/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Port_Types.h
*  Module   : PORT 
*  breif    : contains types
*  
*****************************************************************   
*/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"

/******************************************
  GLOBAL CONSTANT MACROS   
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES 
*******************************************/
typedef enum{
	PORT_PA0 = 10,
	PORT_PA1 ,
	PORT_PA2 ,
	PORT_PA3 ,
	PORT_PA4 ,
	PORT_PA5 ,
	PORT_PA6 ,
	PORT_PA7 ,
	PORT_PB0 = 20,
	PORT_PB1 ,
	PORT_PB2 ,
	PORT_PB3 ,
	PORT_PB4 ,
	PORT_PB5 ,
	PORT_PB6 ,
	PORT_PB7 ,
	PORT_PC0 = 30,
	PORT_PC1 ,
	PORT_PC2 ,
	PORT_PC3 ,
	PORT_PC4 ,
	PORT_PC5 ,
	PORT_PC6 ,
	PORT_PC7 ,
	PORT_PD0 = 40,
	PORT_PD1 ,
	PORT_PD2 ,
	PORT_PD3 ,
	PORT_PD4 ,
	PORT_PD5 ,
	PORT_PD6 ,
	PORT_PD7 ,
	PORT_PE0 = 50,
	PORT_PE1 ,
	PORT_PE2 ,
	PORT_PE3 ,
	PORT_PE4 ,
	PORT_PE5 ,
	PORT_PF0 = 60,
	PORT_PF1 ,
	PORT_PF2 ,
	PORT_PF3 ,
	PORT_PF4
}Port_PinType;

typedef enum{
	PORT_PORTA= 1, 
	PORT_PORTB,   
	PORT_PORTC,
	PORT_PORTD,
	PORT_PORTE,
	PORT_PORTF
}Port_PortType;
typedef enum{
	PORT_PINDIR_INPUT,
	PORT_PINDIR_OUTPUT,
	
}Port_PinDirectionType;

typedef enum{
	PORT_PINMODE_DEN = 0,
	PORT_PINMODE_U0Rx = 1,
	PORT_PINMODE_U0Tx = 1,
	PORT_PINMODE_U1Rx = 1,
	PORT_PINMODE_U1Tx = 1,
	PORT_PINMODE_CAN1Rx = 8,
	PORT_PINMODE_CAN1Tx = 8,
	PORT_PINMODE_CAN0Rx = 8,
	PORT_PINMODE_CAN0Tx = 8,
	PORT_PINMODE_I2C1SCL= 3,
	PORT_PINMODE_I2C1SDA= 3,
	PORT_PINMODE_I2C0SCL= 3,
	PORT_PINMODE_I2C0SDA= 3,
	PORT_PINMODE_M0PWM0 = 4,
	PORT_PINMODE_M0PWM1 = 4,
	PORT_PINMODE_M0PWM2 = 4,
	PORT_PINMODE_M0PWM3 = 4,
	PORT_PINMODE_M0PWM4 = 4,
	PORT_PINMODE_M0PWM5 = 4,
	PORT_PINMODE_M0PWM6 = 4,
	PORT_PINMODE_M0PWM7 = 4,
	PORT_PINMODE_M1PWM0 = 5,
	PORT_PINMODE_M1PWM1 = 5,
	PORT_PINMODE_M1PWM2 = 5,
	PORT_PINMODE_M1PWM3 = 5,
	PORT_PINMODE_M1PWM4 = 5,
	PORT_PINMODE_M1PWM5 = 5,
	PORT_PINMODE_M1PWM6 = 5,
	PORT_PINMODE_M1PWM7 = 5
}Port_PinModeType;

typedef enum{
	PORT_PIN_IN_ATTATCH_PULLUP,
	PORT_PIN_IN_ATTATCH_PULLDOWN,
	PORT_PIN_IN_ATTATCH_OPENDRAIN
}Port_InternalAttachType;

typedef enum{
	PORT_PIN_LEVEL_LOW,
	PORT_PIN_LEVEL_HIGH
	
}Port_LevelType;
typedef enum{
	PORT_2_mA,
	PORT_4_mA,
	PORT_8_mA
}Port_PinOtputCurrentType;


#endif
