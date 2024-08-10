/*
 * main.c
 *
 *  Created on: Aug 3, 2024
 *      Author: Marwan
 */

#include "STD_Types.h"
#include <util/delay.h>

// MCAL
#include "DIO.h"
#include "I2C.h"

// HAL
#include "LCD_I2C.h"

int main()
{
    // Initialize DIO and I2C
    DIO_vidInit();
    I2C_vidInit();

    DIO_enuActivePullUp(16, 1);
    DIO_enuActivePullUp(17, 1);

    // I2C Enable
    I2C_vidEnable();

    I2C_vidEnableIreq();

    // Initialize the I2C LCD
    LCD_I2C_Init();

    // Delay to ensure the LCD is ready
    _delay_ms(50);

    // Write a message to the LCD
    LCD_I2C_WriteString("Hello, Marwan!");

    while(1)
    {

    }

    return 0;
}
