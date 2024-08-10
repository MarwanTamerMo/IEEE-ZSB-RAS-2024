/********************************************************/
/** Description : config file for I2C    	            */
/** Author      : Marwan Tamer                 	        */
/** Date        : 7 Aug 2024                            */
/** Version     : 1.0V                                  */
/********************************************************/

#ifndef LCD_I2C_H_
#define LCD_I2C_H_

void LCD_I2C_Init(void);
void LCD_I2C_WriteString(const char* str);

#endif /* LCD_I2C_H_ */
