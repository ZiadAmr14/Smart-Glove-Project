/****************Name: Ziad***************/
/***************Date: 12/10/2020 **********/
/***************SWC: RTO ***************/
/******************* V1.0 **************/
#ifndef _RTO_INTERFACE_H
#define _RTO_INTERFACE_H

void RTO_voidInit(void);

u8 RTO_u8CreateTask(u8 Copy_u8Priority,u8 Copy_u8Periodicity,u8 Copy_u8FirstDelay,void(*Copy_Pf)(void));

void RTO_voidSchedule(void);
#endif
