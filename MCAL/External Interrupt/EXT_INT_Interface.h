/****************Name: Ziad***************/
/***************Date: 9/7/2020 **********/
/***************SWC: EXTERNAL INTERRUPT ***************/
/******************* V1.0 **************/
#ifndef EXT_INT_INRERFACE_H
#define EXT_INT_INRERFACE_H

#define ETI_u8_EXTI0    0
#define ETI_u8_EXTI1    1
#define ETI_u8_EXTI2    2

/*Macros For edge source*/
#define EXTI_u8_RisingEdge          0
#define EXTI_u8_FallingEdge         1
#define EXTI_u8_AnyLogicalChange    2
#define EXTI_u8_LowLevel            3


u8 EXTI_u8Enable(u8 Copy_u8EXTI_Index,u8 Copy_u8EdgeIndex);

u8 EXTI_u8Disable(u8 Copy_u8EXTI_Index);

u8 EXTI_u8SetCallBack(u8 Copy_u8EXTI_INDEX, void(*copy_Pf)(void));



#endif