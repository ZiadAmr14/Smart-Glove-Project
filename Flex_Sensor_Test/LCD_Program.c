/***************** 1/9/2020 ***************/
/*****************Name: Ziad Amr***********/
/**************** SWC: LCD ****************/
/**************** V1.0 ******************/
#include"typedefs.h"
#include"BitMath.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"LCD_Private.h"
#include"LCD_Configuration.h"
#define F_CPU 8000000UL
#include<util/delay.h>



	void LCD_voidInitialize()
	{
		_delay_ms(35);
		//Function Set Command
		LCD_voidSendCommand(0b00111000);
		_delay_us(40);
		LCD_voidSendCommand(0b00001111);
		_delay_us(40);
		LCD_voidSendCommand(0b00000001);
		_delay_ms(2);
		LCD_voidSendCommand(0b00000110);
	}

	void LCD_voidSendCommand(u8 Copy_u8Cmnd)
	{
#if LCD_u8_MODE==LCD_u8_MODE_8BIT
		//RS =0, RW=0
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
		//Write Command
		DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd);
		// E=1
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
		_delay_us(1);
		//E=0
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);

#elif LCD_u8_MODE==LCD_u8_MODE_4BIT
		//Code for 4 bit mode
		//RS =0, RW=0
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
		//Write Command
		DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd);
		// E=1
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
		_delay_us(1);
		//E=0
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
		//Write the rest of the command
		DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd<<4);
		// E=1
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
		_delay_us(1);
		//E=0
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
#endif
	}
	
	void LCD_voidSendCharacter(u8 Copy_u8char)
	{
		//RS =1, RW=0
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
		//Write Character
		DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8char);
		// E=1
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
		_delay_us(1);
		//E=0
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	}
	
	
	void LCD_voidSendString(u8* Copy_Pu8String)
	{
		u8 Local_u8Iterator=0;
		while(Copy_Pu8String[Local_u8Iterator]!='\0')
		{
			LCD_voidSendCharacter(Copy_Pu8String[Local_u8Iterator]);
			Local_u8Iterator++;
		}
	}
	
	
	void LCD_voidSendNumber(u32 Copy_u8Number)
	{
		u32 Local_u8TempNumber=0,Local_u8Modulus=0;
		u32 Local_Au8Number[5]={0,0,0,0,0};
		u8 i=0;
		while(Copy_u8Number){
		    Local_Au8Number[i]=(Copy_u8Number%10);
		    Copy_u8Number/=10;
		    i++;
		}
		while(1)
		{
			if(i<=0)
				break;
			u8 Character=(Local_Au8Number[i-1]+'0');
			LCD_voidSendCharacter(Character);
			i--;

		}
		
	}
	
	u8 LCD_u8GoToXY(u8 Copy_u8LineNumebr,u8 Copy_u8Location)
	{
		u8 Local_u8_ErrorState=STD_TYPES_OK;
		if(Copy_u8Location<=39)
		{
			switch(Copy_u8LineNumebr)
			{
				case LCD_u8_LINE1:
					LCD_voidSendCommand(0x80+Copy_u8Location);
					break;
				case LCD_u8_LINE2:
					LCD_voidSendCommand(0xC0+Copy_u8Location);
					break;
				default:
					Local_u8_ErrorState=STD_TYPES_NOT_OK;
					
			}
		}
		else
		{
			Local_u8_ErrorState=STD_TYPES_NOT_OK;
		}
		
		return Local_u8_ErrorState;
	}
	
	u8 LCD_u8SendSpecialCharacter(u8 Copy_u8CharNumber,u8* Copy_Pu8Patterns,u8 Copy_u8LineNumebr,u8 Copy_u8Location)
	{
		u8 Local_u8_ErrorState=STD_TYPES_OK;
		if(Copy_u8Location<=39 &&((Copy_u8LineNumebr==LCD_u8_LINE1)||(Copy_u8LineNumebr==LCD_u8_LINE2)))
		{
			switch(Copy_u8CharNumber)
			{
				case FIRST_CHARACTER_LOCATION:
					LCD_voidSendCommand(0b01000000);
					break;
				case SECOND_CHARACTER_LOCATION:
					LCD_voidSendCommand(0b01001000);
					break;
				case THIRD_CHARACTER_LOCATION:
					LCD_voidSendCommand(0b01010000);
					break;
				case FOURTH_CHARACTER_LOCATION:
					LCD_voidSendCommand(0b01011000);
					break;
				case FIFTH_CHARACTER_LOCATION:
					LCD_voidSendCommand(0b01100000);
					break;
				case SIXTH_CHARACTER_LOCATION:
					LCD_voidSendCommand(0b01101000);
					break;
				case SEVENTH_CHARACTER_LOCATION:
					LCD_voidSendCommand(0b01110000);
					break;
				case EIGHTH_CHARACTER_LOCATION:
					LCD_voidSendCommand(0b01111000);
					break;
				default:
					Local_u8_ErrorState=STD_TYPES_NOT_OK;
					break;
			}
			for(u8 i=0;i<8;i++)
			{
				LCD_voidSendCharacter(Copy_Pu8Patterns[i]);
			}
			LCD_u8GoToXY(Copy_u8LineNumebr,Copy_u8Location);
			LCD_voidSendCharacter(Copy_u8CharNumber);
		}
		else
		{
			Local_u8_ErrorState=STD_TYPES_NOT_OK;
		}
		
		return Local_u8_ErrorState;
	}
