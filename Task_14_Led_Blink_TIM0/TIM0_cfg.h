/********************************************************/
/** Description : config file for TIM0                  */
/** Author      : Ahmed Abo Elnour                 	    */
/** Date        : 18 May 2024                           */
/** Version     : 1.0V                                  */
/********************************************************/

#ifndef TIM0_CFG_H
#define TIM0_CFG_H

#define TIM0_MODE		TIM0_NORMAL

#define TIM0_CLK_SEL    TIM0_PRESC_8

#define TIM0_COM_BITS   0

#define  A1  10
#define  CONC_(a,b) CONC_H_P(a,b)
#define  CONC_H_P(a,b) CONC_H_(a,b)
#define  CONC_H_(a,b) a##b




#endif 
