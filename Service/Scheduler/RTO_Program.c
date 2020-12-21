/****************Name: Ziad***************/
/***************Date: 12/10/2020 **********/
/***************SWC: RTO ***************/
/******************* V1.0 **************/
#include"typedefs.h"
#include"BitMath.h"

#include"Timers_Interface.h"
#include"RTO_Interface.h"
#include"RTO_Configuration.h"
#include"RTO_Private.h"

/*Array of TCB*/
RTO_TCB RTO_Tasks[RTO_u8_MAX_NUMBER_TASKS];
void RTO_voidInit(void)
{
	/*Set Call back Function*/
	Timers_u8Timers0SetCallBack(&RTO_RTO_voidSchedule);
	/*Start Timer*/
	Timers_voidTimer0Init();
}

u8 RTO_u8CreateTask(u8 Copy_u8Priority,u8 Copy_u8Periodicity,u8 Copy_u8FirstDelay,void(*Copy_Pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_NOT_OK;
	if((Copy_u8Priority<RTO_u8_MAX_NUMBER_TASKS)&& (Copy_Pf!=NULL))
	{
		Local_u8ErrorState = STD_TYPES_OK;
		
	}
	
	
	
	
	return Local_u8ErrorState;
}

void RTO_voidSchedule(void);