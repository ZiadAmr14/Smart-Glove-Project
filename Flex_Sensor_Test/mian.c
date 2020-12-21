#include"typedefs.h"
#include"BitMath.h"
#include"DIO_Interface.h"
#include"ADC_Interface.h"
#include"LCD_Interface.h"
#define F_CPU 8000000UL
#include<util/delay.h>
int main(void)
{
	u16 Local_u16DigitalValue1;
	u16 Local_u16AnalougeValue1;
	u16 Local_u16DigitalValue2;
	u16 Local_u16AnalougeValue2;
	u16 Local_u16DigitalValue3;
	u16 Local_u16AnalougeValue3;
	DioInit();
	ADC_voidInit();
	LCD_voidInitialize();
	while(1)
	{
		ADC_u8GetDigitalValue(ADC_u8_CHANNEL_0,&Local_u16DigitalValue1);
		ADC_u8GetDigitalValue(ADC_u8_CHANNEL_1,&Local_u16DigitalValue2);
		ADC_u8GetDigitalValue(ADC_u8_CHANNEL_2,&Local_u16DigitalValue3);
		Local_u16AnalougeValue1 = (u16)((Local_u16DigitalValue1 * 5000UL) / 1024);
		Local_u16AnalougeValue2 = (u16)((Local_u16DigitalValue2 * 5000UL) / 1024);
		Local_u16AnalougeValue3 = (u16)((Local_u16DigitalValue3 * 5000UL) / 1024);

//		LCD_u8GoToXY(LCD_u8_LINE1,FIRST_CHARACTER_LOCATION);
//		LCD_voidSendNumber(Local_u16AnalougeValue2);
//		_delay_ms(300);
//		LCD_voidSendCommand(0b00000001);
//		_delay_ms(2);

				if((Local_u16AnalougeValue1>=3900 && Local_u16AnalougeValue1<= 4100) && (Local_u16AnalougeValue2>=4000 && Local_u16AnalougeValue2<= 4200) && (Local_u16AnalougeValue3>=4250 && Local_u16AnalougeValue3<= 4350))
				{
					LCD_voidSendCommand(0b00000001);
					_delay_ms(2);
					LCD_u8GoToXY(LCD_u8_LINE1,FIRST_CHARACTER_LOCATION);
					LCD_voidSendString("Perfect!");
				}
				else if((Local_u16AnalougeValue1>=3550 && Local_u16AnalougeValue1<= 3750) && (Local_u16AnalougeValue2>=3900 && Local_u16AnalougeValue2<= 4200) && (Local_u16AnalougeValue3>=4450 && Local_u16AnalougeValue3<= 4600))
				{
					LCD_voidSendCommand(0b00000001);
					_delay_ms(2);
					LCD_u8GoToXY(LCD_u8_LINE1,FIRST_CHARACTER_LOCATION);
					LCD_voidSendString("Good!");
				}
				else if((Local_u16AnalougeValue1>=3850 && Local_u16AnalougeValue1<= 4000) && (Local_u16AnalougeValue2>=3900 && Local_u16AnalougeValue2<= 4300) && (Local_u16AnalougeValue3>=4450 && Local_u16AnalougeValue3<= 4600))
				{
					LCD_voidSendCommand(0b00000001);
					_delay_ms(2);
					LCD_u8GoToXY(LCD_u8_LINE1,FIRST_CHARACTER_LOCATION);
					LCD_voidSendString("Rock");
				}
				else if((Local_u16AnalougeValue1>=3800 && Local_u16AnalougeValue1<= 3900) && (Local_u16AnalougeValue2>=3700 && Local_u16AnalougeValue2<= 3800) && (Local_u16AnalougeValue3>=4250 && Local_u16AnalougeValue3<= 4350))
				{
					LCD_voidSendCommand(0b00000001);
					_delay_ms(2);
					LCD_u8GoToXY(LCD_u8_LINE1,FIRST_CHARACTER_LOCATION);
					LCD_voidSendString("Scissor");
				}
				else if((Local_u16AnalougeValue1>=3600 && Local_u16AnalougeValue1<= 3699) && (Local_u16AnalougeValue2>=3700 && Local_u16AnalougeValue2<= 3800) && (Local_u16AnalougeValue3>=4250 && Local_u16AnalougeValue3<= 4350))
				{
					LCD_voidSendCommand(0b00000001);
					_delay_ms(2);
					LCD_u8GoToXY(LCD_u8_LINE1,FIRST_CHARACTER_LOCATION);
					LCD_voidSendString("Paper");
				}
				_delay_ms(100);
	}

	return 0;
}
