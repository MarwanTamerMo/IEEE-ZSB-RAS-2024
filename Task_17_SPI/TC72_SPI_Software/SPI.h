/********************************************************/
/** Description : Interface file for SPI                */
/** Author      : Ahmed Abo Elnour                 	    */
/** Date        : 1 June 2024                           */
/** Version     : 1.0V                                  */
/********************************************************/

#ifndef SPI_H
#define SPI_H

void   SPI_vidInit(void);

void SPI_vidEnable(void);
void SPI_vidDisable(void);

void SPI_vidEnableTransCmpIreq(void);
void SPI_vidDisableTransCmpIreq(void);

void SPI_vidSetCallBackTransCmp(pf pfCallbackCpy);

uint8 SPI_u8TransmitDataSync(uint8 u8DataCpy);


uint8 SPI_u8ReadDataReg(void);
void SPI_vidWriteDataReg(uint8 u8DataCpy);


#endif
