/****************Name: Ziad***************/
/***************Date: 9/15/2020 **********/
/***************SWC: Global INTERRUPT ***************/
/******************* V1.0 **************/
#include"typedefs.h"
#include"BitMath.h"
#include"Global_INTERRUPT_Interface.h"
#include"Global_INTERRUPT_Configuration.h"
#include"Global_INTERRUPT_Private.h"


void GlobalInt_voidEnableGI()
{
	SETBit(GLBLINT_u8_SREG,GLOBAL_INTERRUPT_PIN);
}

void GlobalInt_voidDisableGI()
{
	CLRBIT(GLBLINT_u8_SREG,GLOBAL_INTERRUPT_PIN);
}