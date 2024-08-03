/********************************************************/
/** Description : Private file for SPI                */
/** Author      : Ahmed Abo Elnour                 	    */
/** Date        : 31 May 2024                           */
/** Version     : 1.0V                                  */
/********************************************************/

#ifndef SPI_PRIV_H
#define SPI_PRIV_H


#define SPI_SEND_MSB   0
#define SPI_SEND_LSB   1

#define SPI_SLAVE      0
#define SPI_MASTER     1

#define SPI_LOW        0
#define SPI_HIGH	   1

#define SPI_SETUP_LEAD      1
#define SPI_SETUP_TRAIL     0

#define SPI_PRE_DIV_2    4
#define SPI_PRE_DIV_4    0
#define SPI_PRE_DIV_8    5
#define SPI_PRE_DIV_16   1
#define SPI_PRE_DIV_32   6
#define SPI_PRE_DIV_64   7
#define SPI_PRE_DIV_128  3

#define SPDR     *((volatile uint8 *) 0x2F)  
#define SPSR     *((volatile uint8 *) 0x2E)
#define SPCR     *((volatile uint8 *) 0x2D)


static void Stub (void);

#endif