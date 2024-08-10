/********************************************************/
/** Description : Interface file for I2C                */
/** Author      : Ahmed Abo Elnour                 	    */
/** Date        : 7 June 2024                           */
/** Version     : 1.0V                                  */
/********************************************************/

#ifndef I2C_H
#define I2C_H


#define MT_START         0x08
#define MT_REP_START     0x10
#define MT_SLA_W_ACK 	 0x18
#define MT_SLA_W_N_ACK   0x20
#define MT_DATA_ACK      0x28
#define MT_DATA_N_ACK    0x30
#define MT_LOSE_ARB      0x38

#define MT_SLA_R_ACK 	 0x40
#define MT_SLA_R_N_ACK   0x48
#define MR_DATA_ACK 	 0x50
#define MR_DATA_N_ACK    0x58



void   I2C_vidInit(void);

void   I2C_vidEnable(void);
void   I2C_vidDisable(void);

void   I2C_vidEnableIreq(void);
void   I2C_vidDisableIreq(void);

void   I2C_vidSetCallBack(pf pfCallbackCpy);

void   I2C_vidStartCond(void);
void   I2C_vidRepStartCond(void);
void   I2C_vidStopCond(void);
void   I2C_vidSendData(uint8 u8DataCpy);
uint8  I2C_u8GetData(void);
void   I2C_vidSendAck(void);
void   I2C_vidSend_N_Ack(void);
void   I2C_vidWait(void);
uint8  I2C_u8GetStatusCode(void);


#endif