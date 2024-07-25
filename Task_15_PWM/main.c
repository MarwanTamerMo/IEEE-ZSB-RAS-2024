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

void Isr_cmf(void)
 {
	static uint8 toggle = 0;

	if (toggle == 0)
	{
		DIO_enumWritePin(0, 1); // Set pin 0 high
		toggle = 1;
	}
	else
	{
		DIO_enumWritePin(0, 0); // Set pin 0 low
		toggle = 0;
	}
}

int main(void)
{
    DIO_vidInit();
    TIM0_vidInit();

   //TIM0_vidSetValueTcnt(0);
    TIM0_vidSetValueOcr(127);
    TIM0_vidSetCallbackOvf(Isr_cmf);
    TIM0_vidEnableOvfIreq();
    GIE_vidEnable();

    while (1)
    {
        // Main loop
    }

    return 0;
}
