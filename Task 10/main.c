/*
 * main.c
 *
 *  Created on: Jun 26, 2024
 *      Author: Marwan
 */

#include "STD_Types.h"
#include "BitMath.h"
#include <stdlib.h>
#include <util/delay.h>

//MCAL
#include "DIO.h"

//HAL
#include "SEV.h"

int main()
{
	DIO_vidInit();
	DIO_enuActivPull(23, 1);

	uint8 u8ReadButtonStateLoc = 0;
	uint8 u8randValLoc = 0;
	uint8 u8CntrLoc = 0;
	uint8 u8FlagLoc = 0;
	uint8 u8aLedsPinsLoc[6] = {0, 1, 2, 3, 4, 5};

	while(1)
	{

		DIO_enuReadPin(23, &u8ReadButtonStateLoc);

		if (u8ReadButtonStateLoc == 0 && u8FlagLoc == 0)
		{
			_delay_ms(50);
			// Button pressed, generate new random number
			u8FlagLoc = 1;
			u8randValLoc = rand() % 7;

			// Display the new number on the seven segment display
			SEV_vidWriteNum(0, u8randValLoc);

			for (u8CntrLoc = 0; u8CntrLoc < 6; ++u8CntrLoc)
			{
				DIO_enuWritePin(u8aLedsPinsLoc[u8CntrLoc], 0);
			}

			for (u8CntrLoc = 0; u8CntrLoc < u8randValLoc; ++u8CntrLoc)
			{
				DIO_enuWritePin(u8aLedsPinsLoc[u8CntrLoc], 1);
			}
		}

		if (u8ReadButtonStateLoc == 1)
		{
			u8FlagLoc = 0;
		}

		_delay_ms(10);
	}

	return 0;
}
