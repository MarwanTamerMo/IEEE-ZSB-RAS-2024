/********************************************************/
/** Description : config file for I2C    	            */
/** Author      : Marwan Tamer                   	    */
/** Date        : 8 Aug 2024                            */
/** Version     : 1.0V                                  */
/********************************************************/


#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef signed char int8_t;
typedef signed short int16;
typedef signed int int32;
typedef long long int64_t;

typedef float float32_t;
typedef double float64_t;
typedef long double float128;

typedef char char_t;

typedef void (*vidPfu16)(uint16);
typedef void (*pf) (void);

typedef enum
{
	E_OK,
	E_NOK,
	E_NOK_PARM_OUT_OF_RANGE,
	E_NOK_PARM_NULL_POINTER


}tenuErrorStatus;

#endif /* STD_TYPES_H */
