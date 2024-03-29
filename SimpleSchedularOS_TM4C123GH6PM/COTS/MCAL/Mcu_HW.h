/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Mcu_HW.h
*   
*  breif    : this file contains all registers addresses 
*  
*****************************************************************   
*/
#ifndef MCU_HW_H
#define MCU_HW_H
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"

/******************************************
  Global Data TYPES AND STRUCTURES 
*******************************************/
typedef struct{
	u32 GPIO_DATA_MAP[255];//GPIO Data Register 
	u32 GPIODATA_REG;// data register
	u32 GPIODIR_REG; // direction register 
	u32 GPIOIS_REG;//Interrupt Sense
	u32 GPIOIBE_REG;//Interrupt both edges
	u32 GPIOIEV_REG;//Interrupt Event
	u32 GPIOIM_REG;//Interrupt Mask
	u32 GPIORIS_REG;//GPIO Raw Interrupt Status
	u32 GPIOMIS_REG;//GPIO Masked Interrupt Status
	u32 GPIOICR_REG;// GPIO Interrupt Clear
    u32 GPIOAFSEL_REG; //Alternate Function Select 
	u32 RESERVED1[55]; //Reserved
    u32 GPIODR2R_REG ;//GPIO 2-mA Drive Select 
    u32 GPIODR4R_REG ;//GPIO 4-mA Drive Select 
    u32 GPIODR8R_REG ;//GPIO 8-mA Drive Select 
    u32 GPIOODR_REG;//GPIO Open Drain Select 
    u32 GPIOPUR_REG;// GPIO Pull-Up Select   
    u32 GPIOPDR_REG;// GPIO Pull-Down Select 
    u32 GPIOSLR_REG;// GPIO Slew Rate Control Select 
    u32 GPIODEN_REG;// GPIO Digital Enable 
    u32 GPIOLOCK_REG;//GPIO Lock 
    u32 GPIOCR_REG;// GPIO Commit 
    u32 GPIOAMSEL_REG;// GPIO Analog Mode Select 
    u32 GPIOPCTL_REG;// GPIO Port Control 
    u32 GPIOADCCTL_REG;// GPIO ADC Control 
    u32 GPIODMACTL_REG;// GPIO DMA Control 
    u32 GPIOPeriphID4_REG;//GPIO Peripheral Identification 4 
    u32 GPIOPeriphID5_REG;//GPIO Peripheral Identification 5 
    u32 GPIOPeriphID6_REG;//GPIO Peripheral Identification 6 
    u32 GPIOPeriphID7_REG;//GPIO Peripheral Identification 7 
    u32 GPIOPeriphID0_REG;//GPIO Peripheral Identification 0 
    u32 GPIOPeriphID1_REG;//GPIO Peripheral Identification 1 
    u32 GPIOPeriphID2_REG;//GPIO Peripheral Identification 2 
    u32 GPIOPeriphID3_REG;//GPIO Peripheral Identification 3 
    u32 GPIOPCellID0_REG;// GPIO PrimeCell Identification 0 
    u32 GPIOPCellID1_REG;// GPIO PrimeCell Identification 1 
    u32 GPIOPCellID2_REG;// GPIO PrimeCell Identification 2 
    u32 GPIOPCellID3_REG;// GPIO PrimeCell Identification 3
}GPIO_type;








/******************************************
  GLOBAL CONSTANT MACROS   
*******************************************/
//-------------------CORE PERIPHERALS------------------- 
#define CORTEX_M4_PRI_BASE_ADDRESS 0xE000E000UL
//*** SCB Registers**********
#define APINT_REG      *((volatile u32*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0xD0C))
#define INTCTRL_REG    *((volatile INTCTRL_REG_tag*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0xD04))
#define SYSHNDCTRL_REG *((volatile u32*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0xD24))

#define SYSPRI_REG    ((volatile u8*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0xD18))// SYSPRI1_REG



//**** Systick registers***** 
//-------------------Systick Control-------------------

#define ST_CTRL_R   	*((volatile u32*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0x010))
#define ST_RELOAD_R   *((volatile u32*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0x014))
#define ST_CURRENT_R  * ((volatile u32*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0x018))

//**** NVIC Registers *****
#define EN_REG     ((volatile u32*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0x100)) // EN0-EN4
#define DIS_REG     ((volatile u32*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0x180))//DIS0_DIS4
#define ACTIVE_REG   ((volatile u32*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0x300))//ACTIVE0
#define PRI_REG      ((volatile u8*)(CORTEX_M4_PRI_BASE_ADDRESS+ 0x400))


//-------------------END OF CORE PERIPHERALS------------- 
//========================================================
//-------------------EXTERNAL PERIPHERALS----------------
//-------------------DIO-------------------
#define GPIO_PORTA_BASE_ADDRESS ((volatile GPIO_type*)0x40004000UL)
#define GPIO_PORTB_BASE_ADDRESS ((volatile GPIO_type*)0x40005000UL)
#define GPIO_PORTC_BASE_ADDRESS ((volatile GPIO_type*)0x40006000UL)
#define GPIO_PORTD_BASE_ADDRESS ((volatile GPIO_type*)0x40007000UL)
#define GPIO_PORTE_BASE_ADDRESS ((volatile GPIO_type*)0x40024000UL)
#define GPIO_PORTF_BASE_ADDRESS ((volatile GPIO_type*)0x40025000UL)
//------------------ END of DIO------------ 


 
//-------------------System Control-------------------
#define RCC_RCGCGPIO_REG    *((volatile u32*)(0x400FE000UL + 0x608))


//------------------ END of System Control------------ 
/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


#endif
