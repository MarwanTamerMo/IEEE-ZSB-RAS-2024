/*
 * EXT0.c
 *
 *  Created on: May 7, 2024
 *      Author: Marwan
 */

#include "STD_Types.h"
#include "BitMath.h"

#include "EXT0.h"
#include "EXT0_cnfg.h"
#include "EXT0_priv.h"

void stup (void)
{
	/* Empty function to handle the issue of wild pointer if the global interrupts
	 * if they are initialized before anything else
	*/
}

static pf EXT0_x = stup;

void EXT0_vidInit(void)
{
	if (EXT0_SENSE_CTR == EXT0_LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR, 1);
		CLEAR_BIT(MCUCR, 0);
	}
	else if (EXT0_SENSE_CTR == EXT0_IOC)
	{
		CLEAR_BIT(MCUCR, 1);
		SET_BIT(MCUCR, 0);
	}
	else if (EXT0_SENSE_CTR == EXT0_FALLING)
	{
		SET_BIT(MCUCR, 1);
		CLEAR_BIT(MCUCR, 0);
	}
	else if (EXT0_SENSE_CTR == EXT0_RISING)
	{
		SET_BIT(MCUCR, 1);
		SET_BIT(MCUCR, 0);
	}

}

void EXT0_vidChangeSense(uint8 u8FormCpy)
{
	switch(u8FormCpy)
	{
		case EXT0_RISING:
		SET_BIT(MCUCR , 1);
		SET_BIT(MCUCR , 0);
		break;

		case EXT0_FALLING:
		SET_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 0);
		break;

		case EXT0_IOC:
		CLEAR_BIT(MCUCR , 1);
		SET_BIT(MCUCR , 0);
		break;

		case EXT0_LOW_LEVEL:
		CLEAR_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 0);
		break;

	}
}

void EXT0_vidIntEnable(void)
{
	SET_BIT(GICR, 6);
}
void EXT0_vidIntDisable(void)
{
	CLEAR_BIT(GICR, 6);
}

void EXT0_vidSetCallback(pf pfCallbackCpy)
{
	EXT0_x = pfCallbackCpy ;
}

void __vector_1 (void) __attribute__ ((signal,used));
void __vector_1 (void)
{
	EXT0_x();
}
