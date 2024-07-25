/*****************************************************/
/*Discription  : Bit manipulation lib                */
/*Author       : Marwan Tamer                        */
/*version 	    : 1.0V   on 8 mar 2024               */
/*****************************************************/


#ifndef BIT_MATH_H

#define BIT_MATH_H

//Register
#define SET_BIT(Reg,BitNO)      Reg = (Reg) | (1 <<(BitNO))
#define CLEAR_BIT(Reg,BitNO)    Reg = (Reg) & (~ (1<<BitNO))
#define TGL_BIT(Reg,BitNO)      Reg = (Reg) ^ (1 <<(BitNO))
#define GET_BIT(Reg,BitNO)      (((Reg) >> (BitNO)) & 0x01)

#define CLR_BIT   (Reg,BitNO)    Reg = (Reg) & (~(1<<BitNO))

#endif 	                   /* Guard */
