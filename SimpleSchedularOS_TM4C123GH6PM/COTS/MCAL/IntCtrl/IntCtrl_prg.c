
/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : IntCtrl.c
*  breif   : Nested vector Interrupt Controller  Driver
*  details : The driver configure all MCU interrupts priorities into groups 
*             and sub groups, Enable NVIC , SCB Interrupt gates for peripherals
*****************************************************************   
*
*/
/******************************************
  INCLUDES 
*******************************************/
#include "Std_Types.h"
#include "BitMath.h"
#include "IntCtrl_int.h"
#include "Mcu_HW.h"


/******************************************
  Local Macros / Functions  
*******************************************/

#define APPINT_REGISTER_KEY  0xFA050000


#define CALC_INDX(intID)(4*((intID)/4)+((intID)%4))
/******************************************
  Local Data 
*******************************************/



/******************************************
  Global Data 
*******************************************/
 
extern const IntCtrl_ConfigType  IntCtrl_Config_Arr[INTCTRL_CONFIG_ARR_SIZE];

/******************************************
  Local Functions Prototypes
*******************************************/
//Group_SubGroupType   PriorityGrouping
static void SetPriorityGrouping(void);
static void IntCtrl_SetPriority(IntCtrl_InterruptType copy_IntNum,u8 IntPriority);
static void IntCtrl_EnableInterrupt(IntCtrl_InterruptType  copy_IntNum);
static void IntCtrl_DisableInterrupt(IntCtrl_InterruptType copy_IntNum);

/******************************************
  Local Functions 
*******************************************/

static void SetPriorityGrouping(void)
{
	APINT_REG =   (APPINT_REGISTER_KEY | (INTCTRL_GROUP_SUBGROUP_TYPE << 8));
	
	
}
static void IntCtrl_SetPriority(IntCtrl_InterruptType  copy_IntNum,u8 copy_u8IntPriority)
{
	u16  indx = CALC_INDX(copy_IntNum)  ;
	
	u8 Local_u8IntPriority = ((copy_u8IntPriority &0x07)<< 5);
	if( SysTick_IRQ  < copy_IntNum)
	{
		PRI_REG[indx] = Local_u8IntPriority;
	}
	else{
		switch(copy_IntNum)
		{
			case SysTick_IRQ  : 
			   SYSPRI_REG [11]= Local_u8IntPriority;
			break;
			case PendSV_IRQ  : 
			   SYSPRI_REG [10]= Local_u8IntPriority;
			break;
			case Debug_Monitor_IRQ : 
			   SYSPRI_REG [8]= Local_u8IntPriority;
			break;
			case SVCall_IRQ  : 
			   SYSPRI_REG [7]= Local_u8IntPriority;
			break;
			case Usage_Fault_IRQ  : 
			   SYSPRI_REG [2]= Local_u8IntPriority;
			break;
			case Bus_Fault_IRQ  : 
			   SYSPRI_REG [1]= Local_u8IntPriority;
			break;
			case Memory_Management_IRQ  : 
			   SYSPRI_REG [0]= Local_u8IntPriority;
			break;
				default : break;
		}
	}
}
static void IntCtrl_EnableInterrupt(IntCtrl_InterruptType  copy_IntNum)
{
	u8 indx = copy_IntNum/32;
	u8 bit_no = copy_IntNum%32;
	if( SysTick_IRQ  < copy_IntNum)
	{
		 SET_BIT(EN_REG[indx], bit_no );
	}
	else{
		switch(copy_IntNum)
		{
			case Usage_Fault_IRQ  : 
			   SET_BIT ( SYSHNDCTRL_REG ,18);
			break;
			case Bus_Fault_IRQ  : 
			   SET_BIT ( SYSHNDCTRL_REG ,17);
			break;
			case Memory_Management_IRQ  : 
			  SET_BIT ( SYSHNDCTRL_REG ,16);
			break;
			case SysTick_IRQ  : 
			
			break;
			case PendSV_IRQ  : 
			 
			break;
			case Debug_Monitor_IRQ : 
			 
			break;
			case SVCall_IRQ  : 

			break;
			default : break;
		}
	}
}
static void IntCtrl_DisableInterrupt(IntCtrl_InterruptType copy_IntNum)
{
	u8 indx = copy_IntNum/32;
	u8 bit_no = copy_IntNum%32;
	if( SysTick_IRQ  < copy_IntNum)
	{
		SET_BIT(DIS_REG[indx], bit_no );
	}
	else{
		switch(copy_IntNum)
		{
			case SysTick_IRQ  : 
			 
			break;
			case PendSV_IRQ  : 
			 
			break;
			case Debug_Monitor_IRQ : 
			
			break;
			case SVCall_IRQ  : 
		
			break;
			case Usage_Fault_IRQ  : 
			   CLR_BIT ( SYSHNDCTRL_REG ,18);
			break;
			case Bus_Fault_IRQ  : 
			   CLR_BIT ( SYSHNDCTRL_REG ,17);
			break;
			case Memory_Management_IRQ  : 
			  CLR_BIT ( SYSHNDCTRL_REG ,16);
			break;
			default : break;
		}
	}
	
}
/******************************************
  Global Functions 
*******************************************/

/******************************************
  syntax : void IntCtrl_Init(void)
  
  Description : Initialize NVIC/SCB module by parsing 
                the configuration into NVIC/SCB registers 
				
  Synch/Asynch    : Synchronouse
  Reentrance      : Non Reentrant 
  parameters (in) :  Non 
  parameters (out) : Non
  Return Value     : Non   
******************************************/

void IntCtrl_Init(void)
{
	u8 i;
	u8 Local_IntPriority;
	/* config grouping , subgrouping in APINT register in SCB*/ /*taken as macros*/
	SetPriorityGrouping();
	/* Assign group , subgroup priority in NVIC_PRIx and SCB_SysPRIx Registers*/
	
	for(i = 0;i < INTCTRL_CONFIG_ARR_SIZE ;i++)
	{
#if(INTCTRL_GROUP_SUBGROUP_TYPE  ==   INTCTRL_XXX)
		Local_IntPriority = IntCtrl_Config_Arr[i].IntCtrl_Group_Prio;
#elif(INTCTRL_GROUP_SUBGROUP_TYPE  ==    INTCTRL_XXY)
		Local_IntPriority = (IntCtrl_Config_Arr[i].IntCtrl_Group_Prio << 1  ) |  (IntCtrl_Config_Arr[i].IntCtrl_SubGroup_Prio);
#elif(INTCTRL_GROUP_SUBGROUP_TYPE  ==    INTCTRL_XYY)
		Local_IntPriority = (IntCtrl_Config_Arr[i].IntCtrl_Group_Prio << 2  ) |  (IntCtrl_Config_Arr[i].IntCtrl_SubGroup_Prio);
#elif(INTCTRL_GROUP_SUBGROUP_TYPE  ==    INTCTRL_YYY)
	   Local_IntPriority = IntCtrl_Config_Arr[i].IntCtrl_SubGroup_Prio;	
#endif	
		IntCtrl_SetPriority(IntCtrl_Config_Arr[i].IntCtrl_IntIndx,Local_IntPriority);	
		
	/* Enable /Disable based on user Configuration in NVIC_Enx and SCB_Sys Registers */	
		IntCtrl_EnableInterrupt(IntCtrl_Config_Arr[i].IntCtrl_IntIndx);
	}

	
	
}
