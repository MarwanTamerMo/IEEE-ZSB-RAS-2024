/********************************************************/
/** Description : Private file for I2C                */
/** Author      : Ahmed Abo Elnour                 	    */
/** Date        : 7 June 2024                           */
/** Version     : 1.0V                                  */
/********************************************************/

#ifndef I2C_PRIV_H
#define I2C_PRIV_H

#define I2C_DIV_1    0
#define I2C_DIV_4    1
#define I2C_DIV_16   2
#define I2C_DIV_64   3


#define I2C_DISABLED    0
#define I2C_ENABLED     1

/*Register*/
#define TWBR     *((volatile uint8 *) 0x20)
#define TWSR     *((volatile uint8 *) 0x21)
#define TWAR     *((volatile uint8 *) 0x22)
#define TWDR     *((volatile uint8 *) 0x23)
#define TWCR     *((volatile uint8 *) 0x56)



static void Stub (void);
#endif
