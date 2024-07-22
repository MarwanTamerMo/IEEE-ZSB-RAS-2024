/*****************************************************/
/*Discription  : Stdandard library of data types     */
/*Author       : Marwan Tamer                        */
/*version 	    : V01   on 1 mar 2024                */
/*****************************************************/


#ifndef STD_Types_H 

#define STD_Types_H

typedef unsigned char        uint8 ;
typedef unsigned short int   uint16;
typedef unsigned long int    uint32;


typedef  signed char           sint8;
typedef  signed short int      sint16;
typedef  signed long int       sint32;


typedef  float                 float32;
typedef   double               float64;
typedef   long double          float128;


typedef  enum
{
	E_OK,        // == executed ok
	E_NOK_PARM_OUT_OF_RANGE    // == not executed due to out of range parameters
	
	
	
}tenuErrorSatus;     //means type enum name errorstatus

typedef void (*pf) (void);


#endif 	                   /* Gaurd */
