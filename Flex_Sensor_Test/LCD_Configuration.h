/***************** 1/9/2020 ***************/
/*****************Name: Ziad Amr***********/
/**************** SWC: LCD ****************/
/**************** V1.0 ******************/


#ifndef _LCD_CONFIGURATION_H
#define _LCD_CONFIGURATION_H

/* Options:  DIO_u8_PORTA
			 DIO_u8_PORTB
			 DIO_u8_PORTC
			 DIO_u8_PORTD  */
#define LCD_u8_CONTROL_PORT   DIO_u8_PORTC
#define LCD_u8_RS_PIN		0
#define LCD_u8_RW_PIN       1
#define LCD_u8_E_PIN        2

#define LCD_u8_DATA_PORT    DIO_u8_PORTB
/*
 	 OPTIONS: LCD_u8_MODE_8BIT
 	 	 	  LCD_u8_MODE_4BIT
 */
#define LCD_u8_MODE      LCD_u8_MODE_8BIT





#endif
