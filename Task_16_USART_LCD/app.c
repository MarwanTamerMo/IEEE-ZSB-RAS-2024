/*
 * app.c
 *
 *  Created on: 27 Jul 2024
 *      Author: Marwan Tamer
 */


#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>

#include "DIO.h"
#include "USART.h"

#include "LCD.h"

int main (void)
{
	uint16 u16DataLoc = 0, i = 0;
	DIO_vidInit();
	USART_vidInit();

	LCD_vidInit();

	while (1)
	{
		USART_vidSendDataSync('Z'- i); // Send characters

		i++;

		if (i == 10)
		{
			i = 0 ;
		}

		_delay_ms(1000);

		u16DataLoc=	USART_u16RecvDataSync();

		LCD_vidSendCmd(0, LCD_CLR);

		LCD_vidWriteData(0, u16DataLoc);


	}/*End of super loop */

	return 0;
}
