/*
 * LCD.h
 *
 *  Created on: Apr 8, 2024
 *      Author: Marwan
 */

#ifndef LCD_H_
#define LCD_H_

#define LCD_CLR 0x01

void LCD_vidInit(void);
void LCD_vidSendCmd(uint8 u8LcdIndxCpy, uint8 u8CmdCpy);
void LCD_vidWriteData(uint8 u8LcdIndxCPy, uint8 u8DataCpy);

void LCD_vidWriteString(uint8 u8LcdIndxCpy,char* charSTring ); /*to write string */
void LCD_vidWriteNumber(uint8 u8LCDIndx, uint32 u32NumberCpy);

#endif /* LCD_H_ */
