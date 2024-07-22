/*
 * app.c
 *
 *  Created on: 22 Jul 2024
 *      Author: Marwan Tamer
 */
#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"
#include "GIE.h"
#include "TIM0.h"

void Isr_ovf(void)
{
	static uint16 ovf = 0;
	static uint8 a0 = 0;

	ovf++;

	if (ovf == 35)
	{
		if(a0 == 1)
		{
			DIO_enuWritePin(0, 1);
		}
		else if(a0 == 4)
		{
			DIO_enuWritePin(0, 0);
			a0 = 0;
		}

		a0++;

		ovf = 0;
		TIM0_vidSetValueTcnt(120);
	}

}

//void Isr_CMP(void) {
//	static uint8 a0 = 0, a1 = 0, a2 = 0;
//
//	/*1 micros*/
//	a0++;
//	a1++;
//	a2++;
//
//	if (a0 == 20)
//	{
//		DIO_enuWritePin(0, 0);
//
//	}
//	else if (a0 == 100)
//	{
//		DIO_enuWritePin(0, 1);
//		a0 = 0;
//	}
//
//	if (a1 == 25)
//	{
//		DIO_enuWritePin(1, 0);
//
//	}
//	else if (a1 == 50)
//	{
//		DIO_enuWritePin(1, 1);
//		a1 = 0;
//	}
//
//	if (a2 == 16)
//	{
//		DIO_enuWritePin(2, 0);
//
//	}
//	else if (a2 == 20)
//	{
//		DIO_enuWritePin(2, 1);
//		a2 = 0;
//	}
//
//}

int main(void)
{
	DIO_vidInit();
	TIM0_vidInit();

//	TIM0_vidSetCallbackCmp(Isr_CMP);

//	DIO_enuWritePin(0, 1);
//	DIO_enuWritePin(1, 1);
//	DIO_enuWritePin(2, 1);
	TIM0_vidSetValueTcnt(120);
	TIM0_vidSetCallbackOvf(Isr_ovf);
//	TIM0_vidEnableCmpIreq();
	TIM0_vidEnableOvfIreq();
	GIE_vidEnable();
//	TIM0_vidSetValueOcr(100);



	while (1)
	{

	}/*End of while */

	return 0;
}/*End of main*/
