/*
 * HMOTOR_program.c
 *
 *  Created on: Oct 28, 2021
 *      Author: AT Once
 */
#include <util/delay.h>
#include "data_types.h"
#include "DIO_interface.h"
#include "HMOTOR_private.h"
#include "HMOTOR_config.h"
#include "HMOTOR_interface.h"

u8 Glopal_u8DOORFLAG = 0;         //the door is closed

void HMOTOR_voidInit (void)
{
	DIO_u8SetPinDirection(Motor_controlPins,Motor_pin1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(Motor_controlPins,Motor_pin2,DIO_u8_OUTPUT);
}

void OpenDoorMotor(void)
{
	if(Glopal_u8DOORFLAG == 0)       //the door is closed
	{
		Glopal_u8DOORFLAG = 1;       //the door is open
		DIO_u8SetPinValue(Motor_controlPins,Motor_pin1,DIO_u8_HIGH);
		DIO_u8SetPinValue(Motor_controlPins,Motor_pin2,DIO_u8_LOW);
        _delay_ms(1000);
        DIO_u8SetPinValue(Motor_controlPins,Motor_pin1,DIO_u8_LOW);
        DIO_u8SetPinValue(Motor_controlPins,Motor_pin2,DIO_u8_LOW);
	}
	else
	{

	}
}

void CloseDoorMotor(void)
{
	if(Glopal_u8DOORFLAG == 1)       //the door is closed
	{
		Glopal_u8DOORFLAG = 0;       //the door is closed
		DIO_u8SetPinValue(Motor_controlPins,Motor_pin2,DIO_u8_HIGH);
		DIO_u8SetPinValue(Motor_controlPins,Motor_pin1,DIO_u8_LOW);
        _delay_ms(1000);
        DIO_u8SetPinValue(Motor_controlPins,Motor_pin1,DIO_u8_LOW);
        DIO_u8SetPinValue(Motor_controlPins,Motor_pin2,DIO_u8_LOW);
	}
	else
	{

	}
}
