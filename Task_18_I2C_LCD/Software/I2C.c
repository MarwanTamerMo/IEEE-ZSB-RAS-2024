#include "STD_Types.h"
#include "BIT_Math.h"

#include "I2C.h"
#include "I2C_cfg.h"
#include "I2C_priv.h"

static pf I2C_pfCallBack= Stub ;

void   I2C_vidInit(void)
{
	TWBR  = I2C_TWBR_VAL ;
	TWSR |= I2C_PRESCALLER_VAL ;
	TWAR  = I2C_GC_STS | I2C_MY_OWN_ADDRESS << 1 ;
	TWCR  = 0b00000100;
	
}

void   I2C_vidEnable(void)
{
	SET_BIT(TWCR, 2);
}
void   I2C_vidDisable(void)
{
	CLR_BIT(TWCR, 2);
}

void   I2C_vidEnableIreq(void)
{
	uint8 u8TWCR_pre = 0b00000000;

	if ((GET_BIT(TWCR,7)) == 1)
	{
		u8TWCR_pre = TWCR ;

		CLR_BIT(u8TWCR_pre, 7);
		SET_BIT(u8TWCR_pre, 0);

		TWCR = u8TWCR_pre;
	}
	else
	{
		SET_BIT(TWCR,0);
	}
}
void   I2C_vidDisableIreq(void)
{
	uint8 u8TWCR_pre = 0b00000000;

	if ((GET_BIT(TWCR,7)) == 1)
	{
		u8TWCR_pre = TWCR;

		CLR_BIT(u8TWCR_pre,7);
		CLR_BIT(u8TWCR_pre,0);

		TWCR = u8TWCR_pre;
	}
	else
	{
		CLR_BIT(TWCR,0);
	}
}

void   I2C_vidSetCallBack(pf pfCallbackCpy)
{
	I2C_pfCallBack = pfCallbackCpy ;
}

void   I2C_vidStartCond(void)
{
	uint8 u8TempLoc = 0 ;
	u8TempLoc = GET_BIT(TWCR,0);
	u8TempLoc |= 0b10100100;
	TWCR = u8TempLoc ;
}
void   I2C_vidRepStartCond(void)
{
	I2C_vidStartCond();
}
void   I2C_vidStopCond(void)
{
	uint8 u8TempLoc = 0;

	u8TempLoc = GET_BIT(TWCR,0);
	u8TempLoc |= 0b10010100; // int , ack , start , stop ,wwc , enable ,r ,ireq
	TWCR = u8TempLoc;
}
void   I2C_vidSendData(uint8 u8DataCpy)
{
	uint8 u8TempLoc = 0;

	u8TempLoc = GET_BIT(TWCR,0);

	u8TempLoc |= 0b10000100; // int , ack , start , stop ,wwc , enable ,r ,ireq
	TWDR = u8DataCpy;
	TWCR = u8TempLoc;
	
}
uint8  I2C_u8GetData(void)
{
	return TWDR ;
}

void I2C_vidSendAck(void)
{
	uint8 u8TempLoc = 0;

	u8TempLoc = GET_BIT(TWCR, 0);
	u8TempLoc |= 0b11000100; // int , ack , start , stop ,wwc , enable ,r ,ireq
	TWCR = u8TempLoc;
}
void I2C_vidSend_N_Ack(void)
{
	uint8 u8TempLoc = 0;

	u8TempLoc = GET_BIT(TWCR, 0);
	u8TempLoc |= 0b10000100; // int , ack , start , stop ,wwc , enable ,r ,ireq
	TWCR = u8TempLoc;
}
void   I2C_vidWait(void)
{
	while((GET_BIT(TWCR , 7)) ==0);
}

uint8  I2C_u8GetStatusCode(void)
{
	return (TWSR & 0xF8);
}
void __vector_19 (void) __attribute__((signal,used));
void __vector_19 (void)
{
	
	I2C_pfCallBack();
}

static void Stub (void)
{
	
}
