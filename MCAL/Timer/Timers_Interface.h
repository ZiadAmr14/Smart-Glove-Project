/****************Name: Ziad***************/
/***************Date: 22/9/2020 **********/
/***************SWC: Timers ***************/
/******************* V1.0 **************/

#ifndef _Timers_INTERFACE_H
#define _Timers_INTERFACE_H

void Timers_voidTimer0Init(void);

u8 Timers_u8Timers0SetCallBack(void(*Copy_pf)(void));

void Timers_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);

void Timers_voidTimer1Init();

void Timers_voidTimer1SetCompareMatchValue(u16 Copy_u8OCR1AValue);

u8 Timers_u8Timer1GetCounterValue(u16 *Copy_Pu16CounterValue);

void Timers_voidHwIcuInit();

u8 Timers_voidGetPWMOnPeriod(u16* Copy_Pu16OnTime);

u8 Timers_voidGetPWMTotalPeriodPeriod(u32* Copy_Pu32TotalPeriod);

u8 Timers_voidGetPWMDutyCycle(u8* Copy_Pu8DutyCycle);
#endif
