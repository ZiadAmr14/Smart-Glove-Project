/****************Name: Ziad***************/
/***************Date: 8/10/2020 **********/
/***************SWC: EEPROM ***************/
/******************* V1.0 **************/
#ifndef _EEPROM_INTERFACE_H
#define _EEPROM_INTERFACE_H


u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress, u8 Copy_u8Data);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress, u8* Copy_Pu8ReturnedData);



#endif