/****************Name: Ziad***************/
/***************Date: 5/10/2020 **********/
/***************SWC: SPI ***************/
/******************* V1.0 **************/

#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H 


void SPI_voidInit(void);

u8 SPI_u8TransmitRecieve(u8 Copy_u8TransmittedByte,u8* Copy_Pu8RecievedByte);

u8 SPI_u8TransmitRecieveStringSynch(u8* Copy_Pu8TransmittedByte,u8* Copy_Pu8RecievedByte);


void SPI_voidSlaveSendByte(u8 Copy_u8DataByte);


u8 SPI_u8RecieveByte(u8* Copy_Pu8RecievedByte);















#endif