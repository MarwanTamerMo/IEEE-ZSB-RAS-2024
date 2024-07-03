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

void MotorsStop(void);
void MotorsRight(void);
void MotorsLeft(void);
void MotorsForward(void);

int main()
{
	DIO_vidInit();
	DIO_enuActivPull(16, 1);
	DIO_enuActivPull(17, 1);

	uint8 u8Switch1StateLoc = 0;
	uint8 u8Switch2StateLoc = 0;

	while(1)
	{
		DIO_enuReadPin(17, &u8Switch1StateLoc);
		DIO_enuReadPin(16, &u8Switch2StateLoc);

		 if (u8Switch1StateLoc == 0 && u8Switch2StateLoc == 1)
		 {
			MotorsForward();
		 }
		 else if (u8Switch1StateLoc == 1 && u8Switch2StateLoc == 0)
		 {
			MotorsLeft();
		 }
		 else if (u8Switch1StateLoc == 0 && u8Switch2StateLoc == 0)
		 {
			MotorsRight();
		 }
		 else
		 {
			MotorsStop();
		 }

	}

	return 0;
}

void MotorsStop(void)
{
	DIO_enuWritePin(0, 0);
	DIO_enuWritePin(1, 0);
	DIO_enuWritePin(2, 0);
	DIO_enuWritePin(3, 0);
}
void MotorsRight(void)
{
	DIO_enuWritePin(0, 1);
	DIO_enuWritePin(1, 0);
	DIO_enuWritePin(2, 0);
	DIO_enuWritePin(3, 1);
}
void MotorsLeft(void)
{
	DIO_enuWritePin(0, 0);
	DIO_enuWritePin(1, 1);
	DIO_enuWritePin(2, 1);
	DIO_enuWritePin(3, 0);
}
void MotorsForward(void)
{
	DIO_enuWritePin(0, 0);
	DIO_enuWritePin(1, 1);
	DIO_enuWritePin(2, 0);
	DIO_enuWritePin(3, 1);
}
