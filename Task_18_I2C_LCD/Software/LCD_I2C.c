#include "STD_Types.h"
#include "I2C.h"
#include <util/delay.h>
#include "LCD_I2C.h"
#include "LCD.h"

#define LCD_I2C_ADDRESS 0x20 // Example I2C address for the LCD

void LCD_I2C_Init(void)
{
    I2C_vidStartCond();
    I2C_vidSendData(LCD_I2C_ADDRESS << 1); // Send LCD address with write command

//  I2C_vidSendData(0x38); // Function set: 2 Line, 8-bit, 5x7 dots
    I2C_vidWait(); // Wait for the transmission to complete


    I2C_vidSendData(0x0C); // Display on, Cursor off, Blink off
    I2C_vidWait();
    _delay_ms(5);

    I2C_vidSendData(0x01); // Clear display
    I2C_vidWait();
    _delay_ms(2);

    I2C_vidStopCond();
}

void LCD_I2C_WriteString(const char* str)
{
    while (*str)
    {
        I2C_vidStartCond();
        I2C_vidSendData(LCD_I2C_ADDRESS << 1); // Send LCD address with write command
        I2C_vidSendData(*str++);
        I2C_vidWait(); // Ensure each character is transmitted properly
        I2C_vidStopCond();
        _delay_ms(1); // Small delay between characters
    }
}
