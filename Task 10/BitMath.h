/*****************************************************/
/*Discription  : Bit manipulation lib                */
/*Author       : Marwan Tamer                        */
/*version 	    : 1.0V   on 8 mar 2024               */
/*****************************************************/

#ifndef BITMATH_H
#define BITMATH_H

#define SET_BIT(reg, bit)    ((reg) |= (1 << (bit)))
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1 << (bit)))
#define TOGGLE_BIT(reg, bit) ((reg) ^= (1 << (bit)))
#define GET_BIT(reg, bit)    (((reg) >> (bit)) & 0x01)

#define CLR_BIT(Reg,BitNO)   (Reg) = (Reg) & (~(1 << (BitNO)))

#endif /* BITMATH_H */
