#include "STD_Types.h"
#include "BIT_Math.h"

#include "USART.h"
#include "USART_cfg.h"
#include "USART_priv.h"

static pf USART_pfCallBackRxCmp = Stub ;
static pf USART_pfCallBackTxCmp = Stub ;
static pf USART_pfCallBackUdrEmp = Stub ;

void   USART_vidInit(void)
{
	uint8 u8UBRRH_Pre = 0b00000000;
	uint8 u8UCSRB_Pre = 0b00011000;
	uint8 u8UCSRC_Pre = 0b10000000;
	#if USART_SPEED_MODE ==  USART_DBL_SPEED 
	SET_BIT(UCSRA,1);
	#else
	CLR_BIT(UCSRA,1);	
	#endif                        
	u8UCSRB_Pre = u8UCSRB_Pre| (USART_DATA_SIZE&0b00000100);
	u8UCSRC_Pre = u8UCSRC_Pre| (USART_CLK_MODE<<6)| (USART_PARITY_MODE<<4)|
	              (USART_STOP_BITS<<3)| ((USART_DATA_SIZE &0b00000011)<<1)|
				  USART_POLARITY_STS ;
				  
	#if USART_REL_MODE == USART_SLAVE
	/*DO Nothing*/
	#else
	    u8UBRRH_Pre = u8UBRRH_Pre|((USART_BAUD_RATE>>8)& 0b00001111);
		UBRRL = (uint8)USART_BAUD_RATE;
		UBRRH = (uint8)u8UBRRH_Pre ;
	#endif		
	UCSRB = u8UCSRB_Pre ;
	UCSRC = u8UCSRC_Pre ;
}
void   USART_vidSendDataSync(uint16 u16DataCpy)
{
	while(GET_BIT(UCSRA , 5)!=1); // wait udr empty for tx 
	#if USART_DATA_SIZE == USART_DATA_9BIT
	if (GET_BIT(u16DataCpy,8)==0)
	{
		CLR_BIT(UCSRB,0);
	}
	else
	{
		SET_BIT(UCSRB,0);
	}
	UDR =(uint8) u16DataCpy ;	
	#else
		UDR =(uint8) u16DataCpy ;
	#endif
}
void   USART_vidEnableRecvCmpIreq(void)
{
	SET_BIT(UCSRB, 7);
}
void   USART_vidDisableRecvCmpIreq(void)
{
	CLR_BIT(UCSRB, 7);
}
void   USART_vidEnableTxCmpIreq(void)
{
	SET_BIT(UCSRB, 6);
}
void   USART_vidDisableTxCmpIreq(void)
{
	CLR_BIT(UCSRB, 6);
}
void   USART_vidEnableUdrEmpIreq(void)
{
	SET_BIT(UCSRB, 5);
}
void   USART_vidDisableUdrEmpIreq(void)
{
	CLR_BIT(UCSRB, 5);
}
void   USART_vidEnableRxChannel(void)
{
	SET_BIT(UCSRB, 4);
}
void   USART_vidDisableRxChannel(void)
{
	CLR_BIT(UCSRB, 4);
}
void   USART_vidEnableTxChannel(void)
{
	SET_BIT(UCSRB, 3);
}
void   USART_vidDisableTxChannel(void)
{
	CLR_BIT(UCSRB, 3);
}
void   USART_vidSetCallBackRxCmp(pf pfCallbackCpy)
{
	USART_pfCallBackRxCmp = pfCallbackCpy ;
}
void   USART_vidSetCallBackTxCmp(pf pfCallbackCpy)
{
	USART_pfCallBackTxCmp = pfCallbackCpy;
}
void   USART_vidSetCallBackUdrEmp(pf pfCallbackCpy)
{
	USART_pfCallBackUdrEmp = pfCallbackCpy ;
}
void   USART_vidWriteTxDataReg(uint16 u16DataCpy)
{
	#if USART_DATA_SIZE == USART_DATA_9BIT
	if (GET_BIT(u16DataCpy,8)==0)
	{
		CLR_BIT(UCSRB,0);
	}
	else
	{
		SET_BIT(UCSRB,0);
	}
	UDR =(uint8) u16DataCpy ;	
	#else
		UDR =(uint8) u16DataCpy ;
	#endif	
}
uint16 USART_u16ReadRxDataReg(void)
{
	uint16 u16VarLoc = 0 ;

	#if USART_DATA_SIZE == USART_DATA_9BIT
		u16VarLoc = GET_BIT(UCSRB,1);
		u16VarLoc = (u16VarLoc<<8)|UDR ;
	#else
		u16VarLoc = UDR ;
	#endif	
 	return u16VarLoc ;
}
uint16 USART_u16RecvDataSync(void)
{
	uint16 u16VarLoc = 0 ;
	while(GET_BIT(UCSRA , 7)!=1); // wait Rx rec data
	
	#if USART_DATA_SIZE == USART_DATA_9BIT
		u16VarLoc = GET_BIT(UCSRB,1);
		u16VarLoc = (u16VarLoc<<8)|UDR ;
	#else
		u16VarLoc = UDR ;
	#endif	
	return 	u16VarLoc ;
}
uint8  USART_u8ReadErrFlgs(void)
{
 return ((UCSRA>>2)& 0b00000111);
}

void __vector_13 (void) __attribute__((signal,used));
void __vector_13 (void)
{
	USART_pfCallBackRxCmp();
	
}

void __vector_14 (void) __attribute__((signal,used));
void __vector_14 (void)
{
	USART_pfCallBackUdrEmp();
	
}

void __vector_15 (void) __attribute__((signal,used));
void __vector_15 (void)
{
	
	USART_pfCallBackTxCmp();
}

static void Stub (void)
{
	
}
