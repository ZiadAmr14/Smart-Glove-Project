/****************Name: Ziad***************/
/***************Date: 5/10/2020 **********/
/***************SWC: SPI ***************/
/******************* V1.0 **************/

#include"typedefs.h"
#include"BitMath.h"

#include"SPI_Interface.h"
#include"SPI_Private.h"
#include"SPI_Configuration.h"


void SPI_voidInit(void)
{
	
	#if   (SPI_u8_Mode==SPI_u8_MASTER_MODE)
		/* Select Master Mode */
		SETBit(SPI_u8_SPCR,4);
		/*Choose Data Order =>MSB*/
		CLRBIT(SPI_u8_SPCR,5);
		/*Choose Clock Polarity & Clock Phase => Falling Edge , Rising Edge, Setup, Sample */
		SETBit(SPI_u8_SPCR,3);
		SETBit(SPI_u8_SPCR,2);
		
		/*Select Clock =>Fo/64*/
		SETBit(SPI_u8_SPCR,1);
		CLRBIT(SPI_u8_SPCR,0);
	
	#elif (SPI_u8_Mode==SPI_u8_SLAVE_MODE)
		/* Select Slave Mode */
		CLRBIT(SPI_u8_SPCR,4);
		/*Choose Data Order =>MSB*/
		CLRBIT(SPI_u8_SPCR,5);
		/*Choose Clock Polarity & Clock Phase => Falling Edge , Rising Edge, Setup, Sample */
		SETBit(SPI_u8_SPCR,3);
		SETBit(SPI_u8_SPCR,2);
	#endif
	/*Enable SPI*/
	SETBit(SPI_u8_SPCR,6);
	
	
	
}

u8 SPI_u8TransmitRecieve(u8 Copy_u8TransmittedByte,u8* Copy_Pu8RecievedByte)
{
	u8 Local_u8ErrorState=STD_TYPES_NOT_OK;
	if(Copy_Pu8RecievedByte!=NULL)
	{
		/*Send Byte*/
		SPI_u8_SPDR=Copy_u8TransmittedByte;
		/*Check If the transmission is Completed*/
		while((GetBit(SPI_u8_SPSR,7)==0));
		/*Read Data*/
		*Copy_Pu8RecievedByte=SPI_u8_SPDR;
		Local_u8ErrorState=STD_TYPES_OK;
	}	
	return Local_u8ErrorState;
}

u8 SPI_u8TransmitRecieveStringSynch(u8* Copy_Pu8TransmittedByte,u8* Copy_Pu8RecievedByte)
{
	u8 Local_u8ErrorState=STD_TYPES_NOT_OK;
	static u8 Counter=0;
	if(Copy_Pu8RecievedByte!=NULL && Copy_Pu8TransmittedByte!=NULL)
	{
		while(Copy_Pu8TransmittedByte[Counter]!='\o' || Copy_Pu8RecievedByte[Counter]!='\o' )
		{
			/*Send Byte*/
			SPI_u8_SPDR=Copy_u8TransmittedByte[Counter];
			/*Check If the transmission is Completed*/
			while((GetBit(SPI_u8_SPSR,7))==0);
			/*Read Data*/
			Copy_Pu8RecievedByte[Counter]=SPI_u8_SPDR;
			Local_u8ErrorState=STD_TYPES_OK;
			Counter++;
		}
	}
	return Local_u8ErrorState;
	
}

void SPI_voidSlaveSendByte(u8 Copy_u8DataByte)
{
	SPI_u8_SPDR=Copy_u8DataByte;

}


u8 SPI_u8RecieveByte(u8* Copy_Pu8RecievedByte)
{
	u8 Local_u8ErrorState=STD_TYPES_NOT_OK;
	if(Copy_Pu8RecievedByte!=NULL)
	{
		/*Check If the transmission is Completed*/
		while((GetBit(SPI_u8_SPSR,7)==0));
		*Copy_Pu8RecievedByte=SPI_u8_SPDR;
		Local_u8ErrorState=STD_TYPES_OK;
	}
	
	
	return Local_u8ErrorState;
	
	
	
}