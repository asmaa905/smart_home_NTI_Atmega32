/*
 * HLED_program.c
 *
 *  Created on: Oct 18, 2021
 *      Author: AT Once
 */

#include "data_types.h"

#include "DIO_interface.h"

#include"HLED_config.h"
#include"HLED_interface.h"
#include"HLED_private.h"

void HLED_voidLEDInit(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin)
{
	/* Configure the pin as output pin */
	DIO_u8SetPinDirection(Copy_u8LEDPort,Copy_u8LEDPin,DIO_u8_OUTPUT);
}
void HLED_voidLEDON(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin)
{
	DIO_u8SetPinValue(Copy_u8LEDPort,Copy_u8LEDPin,DIO_u8_HIGH);
}
void HLED_voidLEDOFF(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin)
{
	DIO_u8SetPinValue(Copy_u8LEDPort,Copy_u8LEDPin,DIO_u8_LOW);
}

void HLED_voidLEDToggle(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin)
{
	DIO_u8TogPinValue(Copy_u8LEDPort ,Copy_u8LEDPin);
}
