/*
 * HLED_interface.h
 *
 *  Created on: Oct 18, 2021
 *      Author: AT Once
 */

#ifndef HAL_HLED_HLED_INTERFACE_H_
#define HAL_HLED_HLED_INTERFACE_H_



void HLED_voidLEDInit(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);
void HLED_voidLEDON(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);
void HLED_voidLEDOFF(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);
void HLED_voidLEDToggle(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);

#endif /* HAL_HLED_HLED_INTERFACE_H_ */
