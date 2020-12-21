/****************Name: Ziad***************/
/***************Date: 9/7/2020 **********/
/***************SWC: EXTERNAL INTERRUPT ***************/
/******************* V1.0 **************/

#include"typedefs.h"
#include"BitMath.h"
#include"EXT_INT_Interface.h"
#include"EXT_INT_Private.h"
#include"EXT_INT_Configuration.h"

/*Global pointer to a function*/
static void (*EXTI_APFExtI[3])(void)={NULL,NULL,NULL};

u8 EXTI_u8Enable(u8 Copy_u8EXTI_Index,u8 Copy_u8EdgeIndex)
{
	u8 Local_u8Error_State=STD_TYPES_OK;
	switch(Copy_u8EXTI_Index)
	{
		case ETI_u8_EXTI0:
			switch(Copy_u8EdgeIndex)
			{
				case EXTI_u8_RisingEdge:
					SETBit(EXTI_u8_MCUCR,1);
					SETBit(EXTI_u8_MCUCR,0);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,6);
					break;
				
				case EXTI_u8_FallingEdge:
					SETBit(EXTI_u8_MCUCR,1);
					CLRBIT(EXTI_u8_MCUCR,0);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,6);
					break;
				
				case EXTI_u8_AnyLogicalChange:
					CLRBIT(EXTI_u8_MCUCR,1);
					SETBit(EXTI_u8_MCUCR,0);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,6);
					break;
					
				case EXTI_u8_LowLevel:
					CLRBIT(EXTI_u8_MCUCR,1);
					CLRBIT(EXTI_u8_MCUCR,0);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,6);
					break;
					
				default:
					Local_u8Error_State=STD_TYPES_NOT_OK;
			}
			break;
		
		case ETI_u8_EXTI1:
			switch(Copy_u8EdgeIndex)
			{
				case EXTI_u8_RisingEdge:
					SETBit(EXTI_u8_MCUCR,3);
					SETBit(EXTI_u8_MCUCR,2);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,7);
					break;
				
				case EXTI_u8_FallingEdge:
					SETBit(EXTI_u8_MCUCR,3);
					CLRBIT(EXTI_u8_MCUCR,2);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,7);
					break;
				
				case EXTI_u8_AnyLogicalChange:
					CLRBIT(EXTI_u8_MCUCR,3);
					SETBit(EXTI_u8_MCUCR,2);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,7);
					break;
					
				case EXTI_u8_LowLevel:
					CLRBIT(EXTI_u8_MCUCR,3);
					CLRBIT(EXTI_u8_MCUCR,2);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,7);
					break;
					
				default:
					Local_u8Error_State=STD_TYPES_NOT_OK;
			}
			break;
			
		case ETI_u8_EXTI2:
			switch(Copy_u8EdgeIndex)
			{
				case EXTI_u8_RisingEdge:
					SETBit(EXTI_u8_MCUCSR,6);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,5);
					break;
				
				case EXTI_u8_FallingEdge:
					CLRBIT(EXTI_u8_MCUCSR,6);
					/*Enable PIE*/
					SETBit(EXTI_u8_GICR,5);
					break;	
					
				default:
					Local_u8Error_State=STD_TYPES_NOT_OK;
			}
			break;
		default:
			Local_u8Error_State = STD_TYPES_NOT_OK;

	}
	
	return Local_u8Error_State;
}


u8 EXTI_u8Disable(u8 Copy_u8EXTI_Index)
{
	u8 Local_u8Error_State=STD_TYPES_OK;
	
	switch(Copy_u8EXTI_Index)
	{
		/*Disable PIE*/
		case ETI_u8_EXTI0:
			CLRBIT(EXTI_u8_GICR,6);
			break;
		case ETI_u8_EXTI1:
			CLRBIT(EXTI_u8_GICR,7);
			break;
		case ETI_u8_EXTI2:
			CLRBIT(EXTI_u8_GICR,5);
			break;
			
		default:
			Local_u8Error_State=STD_TYPES_NOT_OK;
	}
	
	return Local_u8Error_State;
}


u8 EXTI_u8SetCallBack(u8 Copy_u8EXTI_INDEX, void(*copy_Pf)(void))
{
	u8 Local_u8Error_State=STD_TYPES_OK;
	if((Copy_u8EXTI_INDEX<=ETI_u8_EXTI2) && (copy_Pf!=NULL) )
	{
		EXTI_APFExtI[Copy_u8EXTI_INDEX]=copy_Pf;
	}
	
	else
	{
		Local_u8Error_State=STD_TYPES_NOT_OK;
	}
	
	
	return Local_u8Error_State;
}




/*Prototype of EXTI0*/
void __vector_1()   __attribute__((signal));
void __vector_1()
{
	if(EXTI_APFExtI[ETI_u8_EXTI0]!=NULL)
		EXTI_APFExtI[0]();
}


/*Prototype of EXTI1*/
void __vector_2()   __attribute__((signal));
void __vector_2()
{
	if(EXTI_APFExtI[ETI_u8_EXTI1]!=NULL)
		EXTI_APFExtI[1]();
}

/*Prototype of EXTI2*/
void __vector_3()   __attribute__((signal));
void __vector_3()
{
	if(EXTI_APFExtI[ETI_u8_EXTI2]!=NULL)
		EXTI_APFExtI[2]();
}





