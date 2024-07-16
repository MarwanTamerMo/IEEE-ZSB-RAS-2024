/*
 * main.c
 *
 *  Created on: May 14, 2024
 *      Author: Marwan
 */


#include "STD_Types.h"
#include <util/delay.h>

//MCAL
#include "ADC.h"
#include "DIO.h"
#include "GIE.h"

//HAL
#include "LCD.h"
#include "SEV.h"

void ISR_ADC_Action(uint16);

int main()
{
//	uint16 u16DigDataLoc = 0;
//	float32_t u16AnalogMvDataLoc = 0;
//	uint16  u8TempLoc = 0;

	DIO_vidInit();

	LCD_vidInit();

	ADC_vidInit();

	ADC_vidEnable();
	ADC_vidSetCallBack(ISR_ADC_Action);
	ADC_vidEnableIntReq();
	GIE_vidEnable();
	ADC_vidStartConv();

	while(1)
	{

		ADC_vidStartConv();

//		LCD_vidSendCmd(0, LCD_CLR);
//		_delay_ms(10);
//
//		u16DigDataLoc = ADC_u16ReadSync(ADC_CH3);
//
//		u16AnalogMvDataLoc = u16DigDataLoc * (5000.0 / 1024);
//		u8TempLoc = u16AnalogMvDataLoc / 10;
//
//		_delay_ms(10);
//		LCD_vidWriteNumber(0, u16AnalogMvDataLoc);
//		_delay_ms(1000);

	}
}


void ISR_ADC_Action(uint16 u16DigDataLoc)
{
	LCD_vidSendCmd(0, LCD_CLR);
	LCD_vidWriteString(0, "ADC ISR");

	LCD_vidSendCmd(0, 0xC0);

	float32_t f32AnalogMvDataLoc = 0;
	float32_t f32VoltValLoc = 0;

	f32AnalogMvDataLoc = u16DigDataLoc * (5000.0 / 1024);
	f32VoltValLoc = f32AnalogMvDataLoc / 1000;

	if(f32VoltValLoc > 4.75) // ADC saturates at (Reference voltage - 1 step)
	{
		f32VoltValLoc = 5;
	}


	_delay_ms(10);
	LCD_vidWriteString(0,"Voltage = ");
	LCD_vidWriteNumber(0, f32VoltValLoc);
	SEV_vidWriteNum(0, f32VoltValLoc);
	_delay_ms(1000);
}
