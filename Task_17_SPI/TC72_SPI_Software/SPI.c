#include "STD_Types.h"
#include "BIT_Math.h"

#include "SPI.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"



static pf SPI_pfCallbackTransmitComp = Stub;

void   SPI_vidInit(void)
{
	uint8 u8SPCR_Pre = 0b01000000 ;
	uint8 u8SPSR_Pre = 0 ;

	u8SPCR_Pre |= SPI_DATA_ORDER << 5    | SPI_MODE << 4     |
	              SPI_CLK_IDLE_STATE << 3| SPI_PHASE_STS << 2|
				  (SPI_PRESCALER & 0b00000011);

	u8SPSR_Pre |= (SPI_PRESCALER & 0b00000100) >> 2;
    SPSR = u8SPSR_Pre;
    SPCR = 	u8SPCR_Pre;
}

void SPI_vidEnable(void)
{
	SET_BIT(SPCR,6);
}
void SPI_vidDisable(void)
{
	CLR_BIT(SPCR,6);
}

void SPI_vidEnableTransCmpIreq(void)
{
	SET_BIT(SPCR,7);	
}
void SPI_vidDisableTransCmpIreq(void)
{
	CLR_BIT(SPCR,7);
}

void SPI_vidSetCallBackTransCmp(pf pfCallbackCpy)
{
	SPI_pfCallbackTransmitComp = pfCallbackCpy ;
}

uint8 SPI_u8TransmitDataSync(uint8 u8DataCpy)
{
	SPDR = u8DataCpy;
	while ((GET_BIT(SPSR,7)) == 0);

	return SPDR;
}


uint8 SPI_u8ReadDataReg(void)
{
	return SPDR;
}
void SPI_vidWriteDataReg(uint8 u8DataCpy)
{
	SPDR = u8DataCpy;
}
void __vector_12 (void) __attribute__((signal,used));
void __vector_12 (void)
{
	SPI_pfCallbackTransmitComp();
}


static void Stub (void)
{
	
}
