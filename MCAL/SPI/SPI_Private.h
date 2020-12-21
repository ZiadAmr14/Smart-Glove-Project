/****************Name: Ziad***************/
/***************Date: 5/10/2020 **********/
/***************SWC: SPI ***************/
/******************* V1.0 **************/

#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H 


#define SPI_u8_SPDR        *((volatile u8*)0x2F)
#define SPI_u8_SPSR        *((volatile u8*)0x2E)
#define SPI_u8_SPCR        *((volatile u8*)0x2D)



#define SPI_u8_MASTER_MODE        1
#define SPI_u8_SLAVE_MODE         2







#endif