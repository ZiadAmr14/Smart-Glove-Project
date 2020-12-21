/***************** 1/9/2020 ***************/
/*****************Name: Ziad Amr***********/
/**************** SWC: LCD ****************/
/**************** V1.0 ******************/

#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

#define LCD_u8_LINE1    1
#define LCD_u8_LINE2    2


#define FIRST_CHARACTER_LOCATION    0
#define SECOND_CHARACTER_LOCATION   1
#define THIRD_CHARACTER_LOCATION    2
#define FOURTH_CHARACTER_LOCATION   3
#define FIFTH_CHARACTER_LOCATION    4
#define SIXTH_CHARACTER_LOCATION    5
#define SEVENTH_CHARACTER_LOCATION  6
#define EIGHTH_CHARACTER_LOCATION   7


void LCD_voidInitialize();

void LCD_voidSendCommand(u8 Copy_u8Cmnd);

void LCD_voidSendCharacter(u8 Copy_u8char);

void LCD_voidSendString(u8* Copy_Pu8String);

void LCD_voidSendNumber(u32 Copy_u8Number);

u8 LCD_u8GoToXY(u8 Copy_u8LineNumebr,u8 Copy_u8Location);

u8 LCD_u8SendSpecialCharacter(u8 Copy_u8CharNumber,u8* Copy_Pu8Patterns,u8 Copy_u8LineNumebr,u8 Copy_u8Location);


#endif
