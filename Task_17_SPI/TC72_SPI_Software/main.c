/*
 * main.c
 *
 *  Created on: Aug 3, 2024
 *      Author: Marwan
 */

#include "STD_Types.h"
#include <util/delay.h>

//MCAL
#include "DIO.h"
#include "SPI.h"

//HAL
#include "LCD.h"
#include "TC72.h"

int main()
{
	DIO_vidInit();
	LCD_vidInit();

	TC72_vidInit();

	uint8 u8TempLoc = 0;
	LCD_vidSendCmd(0, LCD_CLR);

	while(1)
	{
		LCD_vidSendCmd(0, LCD_CLR);
		u8TempLoc = TC72_u8ReadData();

		LCD_vidWriteString(0, "Temp: ");
		LCD_vidWriteNumber(0, u8TempLoc);
		_delay_ms(1000);
	}
}


