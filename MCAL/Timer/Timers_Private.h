/****************Name: Ziad***************/
/***************Date: 22/9/2020 **********/
/***************SWC: Timers ***************/
/******************* V1.0 **************/

#ifndef _Timers_Private_H
#define _Timers_Private_H

#define TIMERS_u8_TIMERS_TIMSK        *((volatile u8*)0x59)
#define TIMERS_u8_TIMERS_TIFR         *((volatile u8*)0x58)
#define TIMERS_u8_TIMERS_TCCR0        *((volatile u8*)0x53)
#define TIMERS_u8_TIMERS_TCNT0        *((volatile u8*)0x52)
#define TIMERS_u8_TIMERS_OCR0         *((volatile u8*)0x5c)
#define TIMERS_u8_TCCR1A          *((volatile u8*)0x4F)
#define TIMERS_u8_TCCR1B          *((volatile u8*)0x4E)
#define TIMERS_u8_TCNT1H          *((volatile u8*)0x4D)
#define TIMERS_u8_TCNT1L          *((volatile u8*)0x4C)

#define TIMERS_u16_TCNT1          *((volatile u16*)0x4C)

#define TIMERS_u8_OCR1AH          *((volatile u8*)0x4B)
#define TIMERS_u8_OCR1AL          *((volatile u8*)0x4A)

#define TIMERS_u16_OCR1A          *((volatile u16*)0x4A)

#define TIMERS_u8_ICR1H        *((volatile u8*)0x47)
#define TIMERS_u8_ICR1L       *((volatile u8*)0x46)

#define TIMERS_u16_ICR1         *((volatile u16*)0x46)

















#endif
