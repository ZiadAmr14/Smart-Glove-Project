/****************Name: Ziad***************/
/***************Date: 12/10/2020 **********/
/***************SWC: RTO ***************/
/******************* V1.0 **************/
#ifndef _RTO_PRIVATE_H
#define _RTO_PRIVATE_H

typedef struct
{
	u8 FirstDelay;
	u8 Priodicity;
	void(*pf)(void);
	
}RTO_TCB;




#endif