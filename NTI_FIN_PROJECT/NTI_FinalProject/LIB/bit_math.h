#ifndef bit_math_H
#define bit_math_H

#define SET_BIT(VAR,BIT_NUMBER)   VAR = VAR | (1<<BIT_NUMBER)
#define CLR_BIT(VAR,BIT_NUMBER)   VAR = VAR & ~(1<<BIT_NUMBER)
#define TOG_BIT(VAR,BIT_NUMBER)   VAR = VAR ^(1<<BIT_NUMBER)
//#define GET_BIT(VAR,BIT_NUMBER)   ((VAR & (1<<BIT_NUMBER))>>BIT_NUMBER)
#define GET_BIT(VAR,BIT_NUMBER)   ((VAR>>BIT_NUMBER) &0x01)

#endif
