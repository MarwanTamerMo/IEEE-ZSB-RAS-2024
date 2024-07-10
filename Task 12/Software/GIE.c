/*
 * GIE.c
 *
 *  Created on: May 7, 2024
 *      Author: Marwan
 */


#include "STD_Types.h"
#include "BitMath.h"

#include "GIE.h"

#define SREG  *((volatile uint8 *) 0x5F)

void GIE_vidEnable(void)
{
	SET_BIT(SREG , 7);
}
void GIE_vidDisable(void)
{
	CLEAR_BIT(SREG , 7);
}
