/****************Name: Ziad***************/
/***************Date: 8/10/2020 **********/
/***************SWC: EEPROM ***************/
/******************* V1.0 **************/
#include"typedefs.h"
#include"BitMath.h"
#include"TWI_Interface.h"

#include"EEPROM_Configuration.h"
#include"EEPROM_Private.h"
#include"EEPROM_Interface.h"
#define F_CPU 8000000UL
#include<util/delay.h>


static u8 Private_u8CheckErrorState(TWI_ERROR_STATE Copy_EnumErrorState)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_EnumErrorState!=TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;
}

u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress, u8 Copy_u8Data)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ERROR_STATE Local_enumTwiErrorState = TWI_OK;
	/*Send Start Condition*/
	Local_enumTwiErrorState = TWI_u8SendStartCondition();
	Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);

	/*Send Slave Address With Write Operation*/
	Local_enumTwiErrorState = TWI_u8SendSlaveAddressWithWrite(EEPROM_u8_FIXED_ADDRESS|(EEPROM_u8_A2<<2)|(Copy_u16ByteAddress>>8));

	Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);

	/* Send Byte Address */
	Local_enumTwiErrorState = TWI_u8SendDataByte((u8)Copy_u16ByteAddress);

	Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);
	/*Send Actual Data*/
	TWI_u8SendDataByte(Copy_u8Data);

	Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);

	/*Stop Condition*/
	TWI_u8SendStopCondition();

	_delay_ms(5);

	return Local_u8ErrorState;

}

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress, u8* Copy_Pu8ReturnedData)
{

	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ERROR_STATE Local_enumTwiErrorState = TWI_OK;
	/*Check the pointer*/
	if(Copy_Pu8ReturnedData!=NULL)
	{
		/*Send Start Condition*/
		Local_enumTwiErrorState = TWI_u8SendStartCondition();

		Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);

		/*Send Slave Address With Write Operation*/
		Local_enumTwiErrorState = TWI_u8SendSlaveAddressWithWrite(EEPROM_u8_FIXED_ADDRESS | (EEPROM_u8_A2<<2) | (Copy_u16ByteAddress>>8));

		Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);

		/* Send Byte Address */
		Local_enumTwiErrorState = TWI_u8SendDataByte((u8)Copy_u16ByteAddress);

		Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);

		/*Send Repeated Start Condition */
		Local_enumTwiErrorState = TWI_u8SendRestartCondition();

		Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);

		/*Send Slave Address With Read Operation*/
		Local_enumTwiErrorState = TWI_u8SendSlaveAddressWithRead(EEPROM_u8_FIXED_ADDRESS | (EEPROM_u8_A2<<2) | (Copy_u16ByteAddress>>8));
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);

		/*Read Data*/
		Local_enumTwiErrorState = TWI_u8ReadDataByte(Copy_Pu8ReturnedData);
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTwiErrorState);

		/*Stop Condition*/
		TWI_u8SendStopCondition();

		_delay_ms(5);

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErrorState;

}
