/*
 * HLCD_private.h
 *
 *  Created on: Oct 11, 2021
 *      Author: AT Once
 */

#ifndef HLCD_HLCD_PRIVATE_H_
#define HLCD_HLCD_PRIVATE_H_


#define FUNCTION_SET_8BIT_MODE_2LINES   0b00111000
#define FUNCTION_SET_8BIT_MODE_1LINES   0b00110000
#define FUNCTION_SET_4BIT_MODE_2LINES   0b00101000
#define FUNCTION_SET_4BIT_MODE_1LINES   0b00100000


#define DISPLAY_ON_CURSOR_ON_BLINK     0b00001111
#define DISPLAY_ON_CURSOR_ON_NOBLINK   0b00001110
#define DISPLAY_ON_CURSOR_OFF_NOBLINK  0b00001100
#define DISPLAY_OFF                    0b00001000


#define ENTRY_MODE_SET_INCREASE        0b00000110
#define ENTRY_MODE_SET_DECREASE        0b00000100

#define CLEAR_DISPLAY                  0b00000001

#define SET_DDRAM_ADDRESS                0x80
#define HLCD_SECOND_ROW_ADDRESS_OFFSET   0x40

#define SET_CGRAM_ADDRESS              0x40
#endif /* HLCD_HLCD_PRIVATE_H_ */

//#ifndef HLCD_HLCD_PRIVATE_H_
//#define HLCD_HLCD_PRIVATE_H_
//                                          /*0b001DNFxx  =>D(1):Eight bit D(0):Four bit , N(1):Two lines N(0):one line , F(1):5x10 , F(0): 5x7 , x: don't care  */
//#define EIGHT_BIT_MODE_5X7_1LINE            0b00110000
//#define EIGHT_BIT_MODE_5X10_1LINE           0b00110100
//
//#define EIGHT_BIT_MODE_5X7_2LINE            0b00111000
//#define EIGHT_BIT_MODE_5X10_2LINE           0b00111100
//
//#define FOUR_BIT_MODE_5X7_1LINE             0b00100000
//#define FOUR_BIT_MODE_5X10_1LINE            0b00100100
//
//#define FOUR_BIT_MODE_5X7_2LINE             0b00101000
//#define FOUR_BIT_MODE_5X10_2LINE            0b00101100
//
//                                          /*0b00000DCB D(1):Display on D(0):Display off ,C(1):cursor on C(0):cursor off , B(1):Blinking , D(0): no blinking */
//#define DISPLAY_ON_CURSOR_ON_BLINK          0b00000111
//#define DISPLAY_ON_CURSOR_ON_NO_BLINK       0b00000110
//#define DISPLAY_ON_CURSOR_OFF               0b00000100
//#define DISPLAY_OFF                         0b00000000
//
//#define CLEAR_DISPLAY                       0b00000001
//
//#define ENTRY_MODE_SET_INCREASE             0b00000010
//#define ENTRY_MODE_SET_DECREASE             0b00000000
//
//#define SET_DDRAM_ADDRESS                   0x80 +
//#define SET_CGRAM_ADDRESS                   0x40 +
//
//
//
//#endif /* HLCD_HLCD_PRIVATE_H_ */
//
