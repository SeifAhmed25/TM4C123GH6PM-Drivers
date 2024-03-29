#include "Mcu_HW.h"
#include "Port_int.h"
#include "Dio_int.h" 
#include "Systick_int.h" 
/*Definitions*/
#define RED_LED PORT_PF1 
#define BLUE_LED PORT_PF2
#define GREEN_LED PORT_PF3 
#define PUSH_BUTTON1 PORT_PF4
StateMachine g_state = STATE1;
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
/*CallBack Function*/
void SysTickCallback_ServeTasks(void); 
/*Tasks Functions Prototypes*/
void Task1_Each1Sec(void);  
void Task2_Each500mSec(void); 
void Task3_Each3Sec(void); 
/*Struct Defining 3 aspects for every task*/
typedef struct{
	u8 Priority; /*Starting from 1, lower is higher priority*/ 
	u8 Periodicity; /*in seconds*/
	void (*ptr)(void);  
}Task_Aspect;  
/*Object for each task*/
Task_Aspect Task1 = {1, 1, Task1_Each1Sec};
Task_Aspect Task2 = {2, 2, Task2_Each500mSec};
Task_Aspect Task3 = {3, 3, Task3_Each3Sec}; 
int main()
{
	  /*Initializing PF4 PB1, PF1 RED LIGHT, PF2 BLUE LIGHT, PF3 GREEN LIGHT*/
    Port_Init(PORT_Config_Arr);
    /* Initialize SysTick with PIOSC_4 as the clock source */
    Systick_Init(PIOSC_4);
    /* Start SysTick Timer with a count to wait  */
      Systick_startTimer(2000000);
    /* Set a callback function to be called on SysTick interrupt */
    Systick_setCallBack(SysTickCallback_ServeTasks);
    while (1) {
        // Your application code here
		}
}
void SysTickCallback_ServeTasks(void){
	static u8 Handler_Counter = 1; 
	if (((Handler_Counter) % (Task1.Periodicity)) == 0){ 
		Task1.ptr();
	}
	if (((Handler_Counter) % (Task2.Periodicity)) == 0){
		Task2.ptr(); 
	}
	if (((Handler_Counter) % (Task3.Periodicity)) == 0){
		Task3.ptr();
	} 
	Handler_Counter++; 
}
/*TASK1 Func*/
void Task1_Each1Sec(void){ 
		Dio_TogPin(RED_LED);
}
/*TASK2 Func*/
void Task2_Each500mSec(void){
	if (Dio_ReadPin(PUSH_BUTTON1) == 0){
			Dio_TogPin(BLUE_LED);
	}
}
/*TASK3 Func*/
void Task3_Each3Sec(void){ 
	Dio_TogPin(GREEN_LED);
}