/****************************************************/
/**************** Name : Ziad *****************/
/**************** Date : 23/9/2020  *****************/
/**************** SWC  : ADC        *****************/
/**************** Version : 1.0     *****************/
/****************************************************/
#include "typedefs.h"
#include "BitMath.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Configuration.h"

static void(*ADC_pfNotification)(u16) = NULL;
/* ADC busy flag */
static u8 ADC_u8BusyFlag = 0;

void ADC_voidInit(void)
{
	/*	1- Select Vref 
		2- Right/Left Adjust
		3- Disable/Enable AutoTrigger
		4- Select CLK
		5- Enable ADC
	 */
	 #if ADC_REFRENCE_SELECTION == ADC_u8_AVCC_WITH_CAPACITOR_AT_AREF
		CLRBIT(ADC_u8_ADMUX_REG,7);
		SETBit(ADC_u8_ADMUX_REG,6);
	 #elif ADC_REFRENCE_SELECTION == ADC_u8_AREF_WITH_VREF_OFF
		CLRBIT(ADC_u8_ADMUX_REG,7);
		CLRBIT(ADC_u8_ADMUX_REG,6);
	 #elif ADC_REFRENCE_SELECTION == ADC_u8_INTERNTAL_2POINT56V_WITH_CAPACITOR_AT_AREF
		SETBit(ADC_u8_ADMUX_REG,7);
		SETBit(ADC_u8_ADMUX_REG,6);
	 #endif
	
	#if ADC_RIGHT_LEFT_ADJUST == ADC_u8_RIGHT_ADJUST
		CLRBIT(ADC_u8_ADMUX_REG,5);
	#elif ADC_RIGHT_LEFT_ADJUST == ADC_u8_LEFT_ADJUST
		SETBit(ADC_u8_ADMUX_REG,5);
	#endif
	
	#if ADC_AUTO_TRIGGER == ADC_u8_AUTO_TRIGGER_DISABLE
		CLRBIT(ADC_u8_ADCSRA_REG,5);
	#elif ADC_AUTO_TRIGGER == ADC_u8_AUTO_TRIGGER_ENABLE
		SETBit(ADC_u8_ADCSRA_REG,5);
	#endif
	
	#if ADC_PRESCALAR_DIVISION_FACTOR == ADC_u8_DIVION_FACTOR2
		CLRBIT(ADC_u8_ADCSRA_REG,2);
		CLRBIT(ADC_u8_ADCSRA_REG,1);
		CLRBIT(ADC_u8_ADCSRA_REG,0);
	#elif ADC_PRESCALAR_DIVISION_FACTOR == ADC_u8_DIVION_FACTOR4
		CLRBIT(ADC_u8_ADCSRA_REG,2);
		SETBit(ADC_u8_ADCSRA_REG,1);
		CLRBIT(ADC_u8_ADCSRA_REG,0);
	#elif ADC_PRESCALAR_DIVISION_FACTOR == ADC_u8_DIVION_FACTOR8
		CLRBIT(ADC_u8_ADCSRA_REG,2);
		SETBit(ADC_u8_ADCSRA_REG,1);
		SETBit(ADC_u8_ADCSRA_REG,0);
	#elif ADC_PRESCALAR_DIVISION_FACTOR == ADC_u8_DIVION_FACTOR16
		SETBit(ADC_u8_ADCSRA_REG,2);
		CLRBIT(ADC_u8_ADCSRA_REG,1);
		CLRBIT(ADC_u8_ADCSRA_REG,0);
	#elif ADC_PRESCALAR_DIVISION_FACTOR == ADC_u8_DIVION_FACTOR32
		SETBit(ADC_u8_ADCSRA_REG,2);
		CLRBIT(ADC_u8_ADCSRA_REG,1);
		SETBit(ADC_u8_ADCSRA_REG,0);
	#elif ADC_PRESCALAR_DIVISION_FACTOR == ADC_u8_DIVION_FACTOR64
		SETBit(ADC_u8_ADCSRA_REG,2);
		SETBit(ADC_u8_ADCSRA_REG,1);
		CLRBIT(ADC_u8_ADCSRA_REG,0);
	#elif ADC_PRESCALAR_DIVISION_FACTOR == ADC_u8_DIVION_FACTOR128
		SETBit(ADC_u8_ADCSRA_REG,2);
		SETBit(ADC_u8_ADCSRA_REG,1);
		SETBit(ADC_u8_ADCSRA_REG,0);
	#endif
		
	SETBit(ADC_u8_ADCSRA_REG,7);
}

u8 ADC_u8GetDigitalValue(u8 Copy_u8ChannelNb, u16 * Copy_pu16DigitalValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeOutCounter = 0;
	if((Copy_u8ChannelNb < 32) && (Copy_pu16DigitalValue != NULL))
	{
		/* Clear MUX4..0 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNb;
		/* Start Conversion */
		SETBit(ADC_u8_ADCSRA_REG,6);
		/* Wait flag = 1 */
		while((GetBit(ADC_u8_ADCSRA_REG,4))== 0);
		/* Clear flag */
		SETBit(ADC_u8_ADCSRA_REG,4);
		/* Read the Digital Value */
		*Copy_pu16DigitalValue = ADC_u16_ADC_REG;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;

}

u8   ADC_u8GetDigitalValueSynchNonBlocking(u8 Copy_u8ChannelNb, u16 * Copy_pu16DigitalValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeOutCounter = 0;
	if((Copy_u8ChannelNb < 32) && (Copy_pu16DigitalValue != NULL))
	{
		/* Clear MUX4..0 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNb;
		/* Start Conversion */
		SETBit(ADC_u8_ADCSRA_REG,6);
		/* Wait flag = 1 */
		while((GetBit(ADC_u8_ADCSRA_REG,4)== 0) && (Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE))
		{
			Local_u32TimeOutCounter++;
		}
		//while(!GET_BIT(ADC_u8_ADCSRA_REG,4));
		if(GetBit(ADC_u8_ADCSRA_REG,4)!= 0)//(Local_u32TimeOutCounter<ADC_u32_TIME_OUT_MAX_VALUE)
		{
			/* Clear flag */
			SETBit(ADC_u8_ADCSRA_REG,4);
			/* Read the Digital Value */
			*Copy_pu16DigitalValue = ADC_u16_ADC_REG;
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOT_OK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;
}
u8   ADC_u8GetDigitalValueAsynch          (u8 Copy_u8ChannelNb,void(*Copy_pfNotification)(u16))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8ChannelNb < 32) && (Copy_pfNotification != NULL) && (ADC_u8BusyFlag == 0))
	{
		/* Set Flag to make ADC is Busy */
		ADC_u8BusyFlag = 1;
		/* update Global Pointer to a function */
		ADC_pfNotification = Copy_pfNotification;
		/* Enable ADC Interrupt */
		SETBit(ADC_u8_ADCSRA_REG,3);
		/* Clear MUX4..0 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNb;
		/* Start Conversion */
		SETBit(ADC_u8_ADCSRA_REG,6);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;
}
u8   ADC_u8GetADCRegValue                 (u16 * Copy_pu16ADCValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu16ADCValue != NULL)
	{
		/* Read ADC Register */
		*Copy_pu16ADCValue = ADC_u16_ADC_REG;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState ;
}

/* Prototype for ADC ISR */
void __vector_16(void)     __attribute__((signal));
void __vector_16(void)
{
	if(ADC_pfNotification != NULL)
	{
		/* Clear Flag */
		ADC_u8BusyFlag = 0;
		/* Clear PIE of ADC */
		CLRBIT(ADC_u8_ADCSRA_REG,3);
		/* Calling Notification function */
		ADC_pfNotification(ADC_u16_ADC_REG);
	}
}
