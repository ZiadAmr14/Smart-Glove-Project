/*******Name: Ziad Amr ****************/
/*******Date: 27/8/2020 ***************/
/*******SWC: DIO **********************/
/******** V1.0 ***************/

#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H


//Macros for ports
#define DIO_u8_PORTA  0
#define DIO_u8_PORTB  1
#define DIO_u8_PORTC  2
#define DIO_u8_PORTD  3


//Macros for Pins
#define DIO_u8_PIN0  0
#define DIO_u8_PIN1  1
#define DIO_u8_PIN2  2
#define DIO_u8_PIN3  3
#define DIO_u8_PIN4  4
#define DIO_u8_PIN5  5
#define DIO_u8_PIN6  6
#define DIO_u8_PIN7  7

//Macros for pin direction
#define DIO_u8_INPUT   0
#define DIO_u8_OUTPUT  1

//Macros for PinValue
#define DIO_u8_HIGH    1
#define DIO_u8_LOW     0


void DioInit();

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDirection);

u8 DIO_u8SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinValue);

u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8* Copy_Pu8ReturnedPinValue);

u8 DIO_u8SetPortDirection(u8 Copy_u8PortId , u8 Copy_u8PinDirection);

u8 DIO_u8SetPortValue(u8 Copy_u8PortId , u8 Copy_u8PortValue);

u8 DIO_u8GetPortValue(u8 Copy_u8PortId , u8* Copy_Pu8ReturnedPortValue);








#endif