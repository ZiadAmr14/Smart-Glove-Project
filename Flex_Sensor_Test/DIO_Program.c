/*******Name: ZiadAmr ****************/
/*******Date: 27/8/2020 ***************/
/*******SWC: DIO **********************/
/******** V1.0 ***************/


//Library Layer
#include"typedefs.h"
#include"BitMath.h"

//MCAL 
#include"DIO_Interface.h"
#include"DIO_Private.h"
#include"DIO_Configuration.h"

void DioInit()
{
	DIO_u8_DDRA_REG = Conc(DIO_u8_PA7_DIRECTION,DIO_u8_PA6_DIRECTION,DIO_u8_PA5_DIRECTION,DIO_u8_PA4_DIRECTION
	,DIO_u8_PA3_DIRECTION,DIO_u8_PA2_DIRECTION,DIO_u8_PA1_DIRECTION,DIO_u8_PA0_DIRECTION);
	
	DIO_u8_DDRB_REG = Conc(DIO_u8_PB7_DIRECTION,DIO_u8_PB6_DIRECTION,DIO_u8_PB5_DIRECTION,DIO_u8_PB4_DIRECTION,
		DIO_u8_PB3_DIRECTION,DIO_u8_PB2_DIRECTION,DIO_u8_PB1_DIRECTION,DIO_u8_PB0_DIRECTION);
		
	DIO_u8_DDRC_REG = Conc(DIO_u8_PC7_DIRECTION,DIO_u8_PC6_DIRECTION,DIO_u8_PC5_DIRECTION,DIO_u8_PC4_DIRECTION,
		DIO_u8_PC3_DIRECTION,DIO_u8_PC2_DIRECTION,DIO_u8_PC1_DIRECTION,DIO_u8_PC0_DIRECTION);
		
	DIO_u8_DDRD_REG = Conc(DIO_u8_PD7_DIRECTION,DIO_u8_PD6_DIRECTION,DIO_u8_PD5_DIRECTION,DIO_u8_PD4_DIRECTION,
		DIO_u8_PD3_DIRECTION,DIO_u8_PD2_DIRECTION,DIO_u8_PD1_DIRECTION,DIO_u8_PD0_DIRECTION);
		
		
	DIO_u8_PORTA_REG = Conc(DIO_u8_PA7_Value,DIO_u8_PA6_Value,DIO_u8_PA5_Value,DIO_u8_PA4_Value,DIO_u8_PA3_Value,DIO_u8_PA2_Value,
	DIO_u8_PA1_Value,DIO_u8_PA0_Value);
	
	DIO_u8_PORTB_REG = Conc(DIO_u8_PB7_Value,DIO_u8_PB6_Value,DIO_u8_PB5_Value,DIO_u8_PB4_Value,DIO_u8_PB3_Value,DIO_u8_PB2_Value,
	DIO_u8_PB1_Value,DIO_u8_PB0_Value);
	
	
	DIO_u8_PORTC_REG = Conc(DIO_u8_PC7_Value,DIO_u8_PC6_Value,DIO_u8_PC5_Value,DIO_u8_PC4_Value,DIO_u8_PC3_Value,DIO_u8_PC2_Value,
	DIO_u8_PC1_Value,DIO_u8_PC0_Value);
	
	DIO_u8_PORTD_REG = Conc(DIO_u8_PD7_Value,DIO_u8_PD6_Value,DIO_u8_PD5_Value,DIO_u8_PD4_Value,DIO_u8_PD3_Value,DIO_u8_PD2_Value,
	DIO_u8_PD1_Value,DIO_u8_PD0_Value);
	
	
	
		
		
	
}

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId<=DIO_u8_PIN7) &&( (Copy_u8PinDirection == DIO_u8_OUTPUT)||(Copy_u8PinDirection == DIO_u8_INPUT)))
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:
					SETBit(DIO_u8_DDRA_REG,Copy_u8PinId);
					break;
				case DIO_u8_INPUT:
					CLRBIT(DIO_u8_DDRA_REG,Copy_u8PinId);
					break;
				
			}
			break;
			case DIO_u8_PORTB:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:
					SETBit(DIO_u8_DDRB_REG,Copy_u8PinId);
					break;
				case DIO_u8_INPUT:
					CLRBIT(DIO_u8_DDRB_REG,Copy_u8PinId);
					break;
				
			}
			break;
			case DIO_u8_PORTC:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:
					SETBit(DIO_u8_DDRC_REG,Copy_u8PinId);
					break;
				case DIO_u8_INPUT:
					CLRBIT(DIO_u8_DDRC_REG,Copy_u8PinId);
					break;
				
			}
			break;
			case DIO_u8_PORTD:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:
					SETBit(DIO_u8_DDRD_REG,Copy_u8PinId);
					break;
				case DIO_u8_INPUT:
					CLRBIT(DIO_u8_DDRD_REG,Copy_u8PinId);
					break;
				
			}
			break;
			
		}
	}
	
	else
	{
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8PinId<=DIO_u8_PIN7)
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:
				switch(Copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SETBit(DIO_u8_PORTA_REG,Copy_u8PinId);
						break;
					
					case DIO_u8_LOW:
						CLRBIT(DIO_u8_PORTA_REG,Copy_u8PinId);
						break;
					
					default:
						Local_u8ErrorState=STD_TYPES_NOT_OK;
				}
				break;
			case DIO_u8_PORTB:
				switch(Copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SETBit(DIO_u8_PORTB_REG,Copy_u8PinId);
						break;
					
					case DIO_u8_LOW:
						CLRBIT(DIO_u8_PORTB_REG,Copy_u8PinId);
						break;
					
					default:
						Local_u8ErrorState=STD_TYPES_NOT_OK;
				}
				
				
			
				break;
			case DIO_u8_PORTC:
				switch(Copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SETBit(DIO_u8_PORTC_REG,Copy_u8PinId);
						break;
					
					case DIO_u8_LOW:
						CLRBIT(DIO_u8_PORTC_REG,Copy_u8PinId);
						break;
					
					default:
						Local_u8ErrorState=STD_TYPES_NOT_OK;
				}
			
				break;
				
			case DIO_u8_PORTD:
				switch(Copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SETBit(DIO_u8_PORTD_REG,Copy_u8PinId);
						break;
					
					case DIO_u8_LOW:
						CLRBIT(DIO_u8_PORTD_REG,Copy_u8PinId);
						break;
					
					default:
						Local_u8ErrorState=STD_TYPES_NOT_OK;
				}
			
				break;
				
			default:
				Local_u8ErrorState=STD_TYPES_NOT_OK;	
				
		}
		
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOT_OK;
	}
	
	
	return Local_u8ErrorState;
	
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8* Copy_Pu8ReturnedPinValue)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	u8 Local_u8PinValue;
	if((Copy_u8PortId<=DIO_u8_PORTD) && (Copy_u8PinId<=DIO_u8_PIN7) && (Copy_Pu8ReturnedPinValue!=NULL))
	{

		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:



				Local_u8PinValue = GetBit(DIO_u8_PINA_REG,Copy_u8PinId);
				if(Local_u8PinValue==0)
				{
					*Copy_Pu8ReturnedPinValue = DIO_u8_LOW;
				}
				
				else
				{
					*Copy_Pu8ReturnedPinValue = DIO_u8_HIGH;
				}
				break;
			
			case DIO_u8_PORTB:

				Local_u8PinValue = GetBit(DIO_u8_PINB_REG,Copy_u8PinId);
				if(Local_u8PinValue==0)
				{
					*Copy_Pu8ReturnedPinValue = DIO_u8_LOW;
				}
				
				else
				{
					*Copy_Pu8ReturnedPinValue = DIO_u8_HIGH;
				}
				break;
				
			case DIO_u8_PORTC:

				Local_u8PinValue = GetBit(DIO_u8_PINC_REG,Copy_u8PinId);
				if(Local_u8PinValue==0)
				{
					*Copy_Pu8ReturnedPinValue = DIO_u8_LOW;
				}
				
				else
				{
					*Copy_Pu8ReturnedPinValue = DIO_u8_HIGH;
				}
				break;
				
			case DIO_u8_PORTD:

				Local_u8PinValue = GetBit(DIO_u8_PIND_REG,Copy_u8PinId);
				if(Local_u8PinValue==0)
				{
					*Copy_Pu8ReturnedPinValue = DIO_u8_LOW;
				}
				
				else
				{
					*Copy_Pu8ReturnedPinValue = DIO_u8_HIGH;
				}
				break;
		}
		
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOT_OK;
	}
	
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8PortId , u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if((Copy_u8PinDirection==DIO_u8_HIGH) || (Copy_u8PinDirection==DIO_u8_LOW))
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_INPUT:
					DIO_u8_DDRA_REG = 0x00;
					break;
				case DIO_u8_OUTPUT:
					DIO_u8_DDRA_REG = 0xff;
					break;
			}
			break;
			
			case DIO_u8_PORTB:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_INPUT:
					DIO_u8_DDRB_REG = 0x00;
					break;
				case DIO_u8_OUTPUT:
					DIO_u8_DDRB_REG = 0xff;
					break;
			}
			break;
			
			case DIO_u8_PORTC:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_INPUT:
					DIO_u8_DDRC_REG = 0x00;
					break;
				case DIO_u8_OUTPUT:
					DIO_u8_DDRC_REG = 0xff;
					break;
			}
			break;
			
			case DIO_u8_PORTD:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_INPUT:
					DIO_u8_DDRD_REG = 0x00;
					break;
				case DIO_u8_OUTPUT:
					DIO_u8_DDRD_REG = 0xff;
					break;
			}
			break;
			
			default:
				Local_u8ErrorState = STD_TYPES_NOT_OK;
				
		}
		
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	
	
	
	
	
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue(u8 Copy_u8PortId , u8 Copy_u8PortValue)
{
	
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	switch(Copy_u8PortId)
	{
		case DIO_u8_PORTA:
			DIO_u8_PORTA_REG = Copy_u8PortValue;
			break;
		
		case DIO_u8_PORTB:
			DIO_u8_PORTB_REG = Copy_u8PortValue;
			break;
			
		case DIO_u8_PORTC:
			DIO_u8_PORTC_REG = Copy_u8PortValue;
			break;
			
		case DIO_u8_PORTD:
			DIO_u8_PORTD_REG = Copy_u8PortValue;
			break;
		
		default:
			Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	
	return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue(u8 Copy_u8PortId , u8* Copy_Pu8ReturnedPortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_Pu8ReturnedPortValue!=NULL)
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:
				*Copy_Pu8ReturnedPortValue = DIO_u8_PINA_REG;
				break;
				
			case DIO_u8_PORTB:
				*Copy_Pu8ReturnedPortValue = DIO_u8_PINB_REG;
				break;
				
				
			case DIO_u8_PORTC:
				*Copy_Pu8ReturnedPortValue = DIO_u8_PINC_REG;
				break;
			
			case DIO_u8_PORTD:
				*Copy_Pu8ReturnedPortValue = DIO_u8_PIND_REG;
				break;
				
			default:
				Local_u8ErrorState = STD_TYPES_NOT_OK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	
	
	
	return Local_u8ErrorState;
}

