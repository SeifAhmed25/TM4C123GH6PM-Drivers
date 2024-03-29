/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : IntCtrl_Types.h
*  Module   : IntCtrl 
*  breif    : 
*  
*****************************************************************   
*/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H
/******************************************
  INCLUDES 
*******************************************/
#include "std_types.h"

/******************************************
  GLOBAL CONSTANT MACROS   
*******************************************/

	
#define 	INTCTRL_XXX  0x04
#define 	INTCTRL_XXY  0x05
#define 	INTCTRL_XYY  0x06
#define   INTCTRL_YYY  0x07


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES 
*******************************************/
typedef enum { //  ISR by interrupt bit number (IRQ number)
	GPIO_Port_A_IRQ = 0,
	GPIO_Port_B_IRQ,
	GPIO_Port_C_IRQ,
	GPIO_Port_D_IRQ,
	GPIO_Port_E_IRQ,
	UART0_IRQ,
	UART1_IRQ,
	SSI0_IRQ,
	I2C0_IRQ,
	PWM0_Fault_IRQ,
	 PWM0_Generator_0_IRQ,
	 PWM0_Generator_1_IRQ,
	 PWM0_Generator_2_IRQ,
	 QEI0_IRQ,
	 ADC0_Sequence_0_IRQ,
	 ADC0_Sequence_1_IRQ,
	 ADC0_Sequence_2_IRQ,
	 ADC0_Sequence_3_IRQ,
	 Watchdog_Timers_0_and_1_IRQ,
	 Bit_Timer_0A_16_32_IRQ,
	 Bit_Timer_0B_16_32_IRQ,
	 Bit_Timer_1A_16_32_IRQ,
	 Bit_Timer_1B_16_32_IRQ,
	 Bit_Timer_2A_16_32_IRQ,
	 Bit_Timer_2B_16_32_IRQ,
	 Analog_Comparator_0_IRQ,
	 Analog_Comparator_1_IRQ,
     // 27 is reserved 
	 System_Control_IRQ= 28,
     Flash_Memory_Control_and_EEPROM_Control_IRQ,
     GPIO_Port_F_IRQ,
     // 31-32 - Reserved
	 UART2_IRQ = 33,
	 SSI1_IRQ,
	 Bit_Timer_3A_16_32_IRQ,
	 Bit_Timer_3B_16_32_IRQ,
	 I2C1_IRQ,
	 QEI1_IRQ,
	 CAN0_IRQ,
	 CAN1_IRQ,
	//41-42 - Reserved
	 Hibernation_Module_IRQ = 43,
	 USB_IRQ,
	 PWM_Generator_3_IRQ,
	 DMA_Software_IRQ,
	 DMA_Error_IRQ,
	 ADC1_Sequence_0_IRQ,
	 ADC1_Sequence_1_IRQ,
	 ADC1_Sequence_2_IRQ,
	 ADC1_Sequence_3_IRQ,
	// 52-56 - Reserved
	 SSI2_IRQ = 57,
	 SSI3_IRQ,
	 UART3_IRQ,
	 UART4_IRQ,
	 UART5_IRQ,
	 UART6_IRQ,
	 UART7_IRQ,
	//64-67 Reserved

	 I2C2_IRQ = 68,
	 I2C3_IRQ,
	 Bit_Timer_4A_16_32_IRQ,
	 Bit_Timer_4B_16_32_IRQ,
	//72-91 Reserved

	 Bit_Timer_5A_16_32_IRQ = 92,
	 Bit_Timer_5B_16_32_IRQ, 
	 Bit_Timer_0A_32_64_IRQ, 
	 Bit_Timer_0B_32_64_IRQ,
	 Bit_Timer_1A_32_64_IRQ,
	Bit_Timer_1B_32_64_IRQ,
	Bit_Timer_2A_32_64_IRQ,
	Bit_Timer_2B_32_64_IRQ,
	Bit_Timer_3A_32_64_IRQ,
	Bit_Timer_3B_32_64_IRQ,
	Bit_Timer_4A_32_64_IRQ,
	Bit_Timer_4B_32_64_IRQ,
	Bit_Timer_5A_32_64_IRQ,
	Bit_Timer_5B_32_64_IRQ,
    System_Exception_imprecise_IRQ,
	// 107-133  Reserved
	 PWM1_Generator_0_IRQ = 134,
	 PWM1_Generator_1_IRQ,
	 PWM1_Generator_2_IRQ,
	 PWM1_Generator_3_IRQ,
	 PWM1_Fault_IRQ
}IntCtrl_InterruptType;

typedef enum { // Vedcor Table ISR by vector number  
	Reset_IRQ =1, 
	Non_Maskable_Interrupt_IRQ, 
	Hard_Fault_IRQ, 
	Memory_Management_IRQ, 
	Bus_Fault_IRQ,
	Usage_Fault_IRQ, 
	// 7- 10 Reserved
	SVCall_IRQ =11, 
	Debug_Monitor_IRQ , 
	// 13 Reserved 
	PendSV_IRQ =14,
	SysTick_IRQ 
}IntCtrl_ExceptionType;


#endif
