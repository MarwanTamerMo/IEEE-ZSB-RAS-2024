/*
 * main.c
 *
 *  Created on: July 8, 2024
 *      Author: Marwan
 */


#include "STD_Types.h"
#include "BitMath.h"
#include <util/delay.h>
#include <stdlib.h>

#include "DIO.h"
#include "EXT0.h"
#include "GIE.h"

#include "LCD.h"
#include "Keypad.h"

void ISR_EXT0_Action();
uint8 calculateResult(uint8 firstNum, uint8 secondNum, uint8 operation);
void displayResult(uint16 result);

uint8 u8FirstNumLoc = 0;
uint8 u8SecNumLoc = 0;
uint8 u8OperationLoc = 0;
uint8 u8EqualValuLoc = 0;
uint8 u8CntrLoc = 0;
uint8 u8PressedKeyLoc = 0;
uint8 u8ClearFlag = 0;

int main(void)
{
	DIO_vidInit();
	LCD_vidInit();
	KEYPAD_voidInit();

	EXT0_vidInit();
	EXT0_vidIntEnable();

	EXT0_vidSetCallback(ISR_EXT0_Action);

	GIE_vidEnable();

	LCD_vidSendCmd(0, LCD_CLR);

	while (1)
	{

	    if (u8ClearFlag == 1)
	    {
			u8ClearFlag = 0; // Set the flag to indicate clearing is required

			LCD_vidSendCmd(0, LCD_CLR);
			_delay_ms(10);

			// Reset variables after clearing the LCD
			u8FirstNumLoc = 0;
			u8SecNumLoc = 0;
			u8OperationLoc = 0;
			u8EqualValuLoc = 0;
			u8CntrLoc = 0;

			continue;
	    }

	    u8PressedKeyLoc = KEYPAD_u8GetPressedKey(0);

		if (u8PressedKeyLoc != 0xFF)
		{

            if (u8PressedKeyLoc == '=')
            {
                if (u8CntrLoc == 3) // Ensure all required inputs are available
                {
                    uint8 u8EqualValuLoc = calculateResult(u8FirstNumLoc, u8SecNumLoc, u8OperationLoc);
                    LCD_vidWriteData(0, '=');
                    displayResult(u8EqualValuLoc);

                    _delay_ms(2000);

                    // Reset variables for next calculation
                    u8FirstNumLoc = 0;
                    u8SecNumLoc = 0;
                    u8OperationLoc = 0;
                    u8CntrLoc = 0;
                }
            }
            else
            {
				if (u8CntrLoc == 0 && u8PressedKeyLoc != 'C')
				{
					u8FirstNumLoc = u8PressedKeyLoc;
					LCD_vidWriteData(0, u8FirstNumLoc);

				}
				else if (u8CntrLoc == 1 && u8PressedKeyLoc != 'C')
				{
					u8OperationLoc = u8PressedKeyLoc;
					LCD_vidWriteData(0, u8OperationLoc);

				} else if (u8CntrLoc == 2 && u8PressedKeyLoc != 'C')
				{
					u8SecNumLoc = u8PressedKeyLoc;
					LCD_vidWriteData(0, u8SecNumLoc);

				}
				else if (u8CntrLoc == 3 && u8PressedKeyLoc != 'C')
				{
					u8EqualValuLoc = calculateResult(u8FirstNumLoc, u8SecNumLoc, u8OperationLoc);
					u8CntrLoc = 0;

					displayResult(u8EqualValuLoc);
				}

				_delay_ms(2000);

				u8CntrLoc++;
			}
		}



	}

	return 0 ;
}


void ISR_EXT0_Action()
{
	u8PressedKeyLoc = KEYPAD_u8GetPressedKey(0);

	if(u8PressedKeyLoc == 'C')
	{
		u8ClearFlag = 1;
	}
}

uint8 calculateResult(uint8 firstNum, uint8 secondNum, uint8 operation)
{
    uint8 result;

    firstNum -= '0';  // Convert from ASCII to number
    secondNum -= '0'; // Convert from ASCII to number

    switch (operation)
    {
        case '+':
            result = firstNum + secondNum;
            break;
        case '-':
            result = firstNum - secondNum;
            break;
        case '*':
            result = firstNum * secondNum;
            break;
        case '/':
            if (secondNum != 0)
            {
                result = firstNum / secondNum;
            }
            else
            {
                result = 0; // Handle division by zero case
            }
            break;
        default:
            result = 0;
            break;
    }

    return result;

}

void displayResult(uint16 result)
{
    char buffer[5]; // Buffer to hold the result as a string

    itoa(result, buffer, 10); // Convert the result to a string

    for (uint8 i = 0; buffer[i] != '\0'; i++)
    {
        LCD_vidWriteData(0, buffer[i]);
    }
}
