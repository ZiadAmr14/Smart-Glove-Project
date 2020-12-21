/****************Name: Ziad***************/
/***************Date: 22/9/2020 **********/
/***************SWC: Timers ***************/
/******************* V1.0 **************/

#include"typedefs.h"
#include"BitMath.h"
#include"Timers_Interface.h"
#include"Timers_Configuration.h"
#include"Timers_Private.h"

/*Global Pointer to function of Timer0 OVF*/
static void(*Timers_pfTimer0OVF)(void)=NULL;



volatile static u16 Timers_u16OnPeriod,Timers_u16OffPeriod;
void Timers_voidTimer0Init(void)
{
	//	/*Select Mode ->Normal Mode*/
	//	CLRBIT(TIMERS_u8_TIMERS_TCCR0,6);
	//	CLRBIT(TIMERS_u8_TIMERS_TCCR0,3);
	//	/*Enable PIE on overflow*/
	//	SETBit(TIMERS_u8_TIMERS_TIMSK,0);
	//	/*Set Preload Value*/
	//	TIMERS_u8_TIMERS_TCNT0=192;
	//	/*Set Prescalar value-> 8*/
	//	CLRBIT(TIMERS_u8_TIMERS_TCCR0,2);
	//	SETBit(TIMERS_u8_TIMERS_TCCR0,1);
	//	CLRBIT(TIMERS_u8_TIMERS_TCCR0,0);


	/*Select Mode->Fast PWM Mode*/
	SETBit(TIMERS_u8_TIMERS_TCCR0,6);
	SETBit(TIMERS_u8_TIMERS_TCCR0,3);

	/*Select Hardware action on OC0->Non Inverting*/
	SETBit(TIMERS_u8_TIMERS_TCCR0,5);
	CLRBIT(TIMERS_u8_TIMERS_TCCR0,4);

	/*Set Prescalar value-> 8*/
	CLRBIT(TIMERS_u8_TIMERS_TCCR0,2);
	SETBit(TIMERS_u8_TIMERS_TCCR0,1);
	CLRBIT(TIMERS_u8_TIMERS_TCCR0,0);


	//		/*Select Mode->Phase Correct PWM Mode*/
	//		CLRBIT(TIMERS_u8_TIMERS_TCCR0,3);
	//		SETBit(TIMERS_u8_TIMERS_TCCR0,6);
	//
	//		/*Select Hardware action on OC0->Non Inverting*/
	//		SETBit(TIMERS_u8_TIMERS_TCCR0,5);
	//		CLRBIT(TIMERS_u8_TIMERS_TCCR0,4);
	//
	//		/*Set Prescalar value-> 8*/
	//		CLRBIT(TIMERS_u8_TIMERS_TCCR0,2);
	//		SETBit(TIMERS_u8_TIMERS_TCCR0,1);
	//		CLRBIT(TIMERS_u8_TIMERS_TCCR0,0);

}

void Timers_voidTimer1Init()
{
	/*Select Timer1 Mode=>Normall Mode*/
	CLRBIT(TIMERS_u8_TCCR1A,1);
	CLRBIT(TIMERS_u8_TCCR1A,0);
	CLRBIT(TIMERS_u8_TCCR1B,3);
	CLRBIT(TIMERS_u8_TCCR1B,4);

	/*Set Prescaler value-> 8*/
	CLRBIT(TIMERS_u8_TCCR1B,2);
	SETBit(TIMERS_u8_TCCR1B,1);
	CLRBIT(TIMERS_u8_TCCR1B,0);

	//	/*Select Timer1 Mode=> 14*/
	//	SETBit(TIMERS_u8_TCCR1A,1);
	//	CLRBIT(TIMERS_u8_TCCR1A,0);
	//	SETBit(TIMERS_u8_TCCR1B,4);
	//	SETBit(TIMERS_u8_TCCR1B,3);
	//
	//	/*Select HW action on OC1A pin => Non inverting */
	//	SETBit(TIMERS_u8_TCCR1A,7);
	//	CLRBIT(TIMERS_u8_TCCR1A,6);
	//
	//	/*Select Top value in ICR1*/
	//	TIMERS_u16_ICR1=19999;
	//
	//	/*Set Angle of Servo Motor*/
	//	TIMERS_u16_OCR1A=499;
	//
	//	/*Set Prescaler value-> 8*/
	//	CLRBIT(TIMERS_u8_TCCR1B,2);
	//	SETBit(TIMERS_u8_TCCR1B,1);
	//	CLRBIT(TIMERS_u8_TCCR1B,0);

}

void Timers_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value)
{
	TIMERS_u8_TIMERS_OCR0=Copy_u8OCR0Value;
}


u8 Timers_u8Timers0SetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if(Copy_pf!=NULL)
	{
		Timers_pfTimer0OVF=Copy_pf;
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;
}

void Timers_voidTimer1SetCompareMatchValue(u16 Copy_u8OCR1AValue)
{
	TIMERS_u16_OCR1A=Copy_u8OCR1AValue;
}



u8 Timers_u8Timer1GetCounterValue(u16 *Copy_Pu16CounterValue)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if(Copy_Pu16CounterValue!=NULL)
	{
		*Copy_Pu16CounterValue=TIMERS_u16_TCNT1;
		Local_u8ErrorState=STD_TYPES_OK;
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOT_OK;
	}


	return Local_u8ErrorState;
}

void Timers_voidHwIcuInit()
{
	/*Select Triggering Source for ICU Interrupt */
	SETBit(TIMERS_u8_TCCR1B,6);
	/*Enable Interrupt*/
	SETBit(TIMERS_u8_TIMERS_TIMSK,5);
}

u8 Timers_voidGetPWMOnPeriod(u16* Copy_Pu16OnTime)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if(Copy_Pu16OnTime!=NULL)
	{
		*Copy_Pu16OnTime=Timers_u16OnPeriod;
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;

}

u8 Timers_voidGetPWMTotalPeriod(u32* Copy_Pu32TotalPeriod)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if(Copy_Pu32TotalPeriod!=NULL)
	{
		*Copy_Pu32TotalPeriod=Timers_u16OnPeriod+Timers_u16OffPeriod;
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;
}

u8 Timers_voidGetPWMDutyCycle(u8* Copy_Pu8DutyCycle)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if(Copy_Pu8DutyCycle!=NULL)
	{
		*Copy_Pu8DutyCycle=(u8)((Timers_u16OnPeriod*100UL)/(Timers_u16OffPeriod+Timers_u16OnPeriod));
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;
}

/*Prototype of timer0 overflow ISR*/
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{

	static u16 Local_u16CounterOVF=0;
	Local_u16CounterOVF++;
	if(Local_u16CounterOVF==3907)
	{
		/*Update Preload Value*/
		TIMERS_u8_TIMERS_TCNT0=192;
		/*Clear the OVF*/
		Local_u16CounterOVF=0;
		/*Call application function*/
		if(Timers_pfTimer0OVF!=NULL)
		{
			Timers_pfTimer0OVF();
		}


	}
}

/*Prototype of timer1 ICU ISR*/
void __vector_6(void)   __attribute__((signal));
void __vector_6(void)
{
	static u8 Local_u8Flag=0;
	static u16 Local_u16OldValue=0;
	if(Local_u8Flag==0)
	{
		/*Rising Edge*/
		Timers_u16OffPeriod=TIMERS_u16_ICR1-Local_u16OldValue;
		/*Change Interrupt Source to falling Edge*/
		CLRBIT(TIMERS_u8_TCCR1B,6);
		/*Change Flag*/
		Local_u8Flag=1;

	}
	else
	{
		/*Falling Edge*/
		Timers_u16OnPeriod=TIMERS_u16_ICR1-Local_u16OldValue;
		/*Change Interrupt Source to Rising Edge*/
		SETBit(TIMERS_u8_TCCR1B,6);
		/*Change Flag*/
		Local_u8Flag=0;
	}
	Local_u16OldValue=TIMERS_u16_ICR1;
}
