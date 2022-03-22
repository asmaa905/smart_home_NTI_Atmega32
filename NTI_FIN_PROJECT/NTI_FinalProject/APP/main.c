/*
 * main.c
 *
 *  Created on: Oct 27, 2021
 *      Author: AT Once
 */

#include "bit_math.h"
#include "data_types.h"

#include "DIO_interface.h"
#include "HLCD_interface.h"
#include "HLED_interface.h"
#include "MUART_interface.h"

void Display_Welcome_Screen (void);
void Relay_voidInit(u8 Copy_u8PortId, u8 Copy_u8PinId);
void Relay_voidLED(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);
void Relay_voidDOOR(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);


int main(void)
{
	HLED_voidLEDInit(DIO_u8_PORTA,DIO_u8_PIN0);
	HLED_voidLEDInit(DIO_u8_PORTA,DIO_u8_PIN1);
	HLED_voidLEDInit(DIO_u8_PORTA,DIO_u8_PIN2);
	HLCD_voidInit();
	HMOTOR_voidInit();

	MUART_voidUARTInit();

	Relay_voidInit(DIO_u8_PORTB,DIO_u8_PIN0);   //Control the Door



	u8 Local_u8UserOption;

	Display_Welcome_Screen();
	while(1)
	{
		Local_u8UserOption = MUART_u8ReceiveData();
		MUART_voidTransmitData(Local_u8UserOption);
		/*************************** Control the LED ***************************/
		if(Local_u8UserOption == '1')
		{
			HLCD_voidClearDisplay();
			HLCD_voidSetPosition(0,0);
			HLCD_voidSendString("1-ON 2-OFF");
			Local_u8UserOption = MUART_u8ReceiveData();
			MUART_voidTransmitData(Local_u8UserOption);
			if(Local_u8UserOption == '1')
			{
				HLCD_voidClearDisplay();
				HLCD_voidSetPosition(0,0);
				HLCD_voidSendString("1-LED1 2-LED2");
				HLCD_voidSetPosition(1,3);
				HLCD_voidSendString("3-LED3");
				Local_u8UserOption = MUART_u8ReceiveData();
				MUART_voidTransmitData(Local_u8UserOption);
				if(Local_u8UserOption == '1')          HLED_voidLEDON(DIO_u8_PORTA,DIO_u8_PIN0);
				else if(Local_u8UserOption == '2')     HLED_voidLEDON(DIO_u8_PORTA,DIO_u8_PIN1);
				else if(Local_u8UserOption == '3')     HLED_voidLEDON(DIO_u8_PORTA,DIO_u8_PIN2);
			}
			/*Led off*/
			else if(Local_u8UserOption== '2')
			{
				HLCD_voidClearDisplay();
				HLCD_voidSetPosition(0,0);
				HLCD_voidSendString("1-LED1 2-LED2");
				HLCD_voidSetPosition(1,3);
				HLCD_voidSendString("3-LED3");
				Local_u8UserOption = MUART_u8ReceiveData();
				MUART_voidTransmitData(Local_u8UserOption);
				if(Local_u8UserOption == '1')          HLED_voidLEDOFF(DIO_u8_PORTA,DIO_u8_PIN0);
				else if(Local_u8UserOption == '2')     HLED_voidLEDOFF(DIO_u8_PORTA,DIO_u8_PIN1);
				else if(Local_u8UserOption == '3')     HLED_voidLEDOFF(DIO_u8_PORTA,DIO_u8_PIN2);
			}
		}
		/************************control the door**************************/
		else if (Local_u8UserOption == '2')
		{
			HLCD_voidClearDisplay();
			HLCD_voidSetPosition(0,0);
			HLCD_voidSendString("1-Open 2-Close");
			Local_u8UserOption = MUART_u8ReceiveData();
			MUART_voidTransmitData(Local_u8UserOption);
			if(Local_u8UserOption == '1')
			{
				Relay_voidDOOR(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_HIGH);
				OpenDoorMotor();
			}
			else if(Local_u8UserOption == '2')
		    {
				Relay_voidDOOR(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_LOW);
				CloseDoorMotor();
			}


		}
		Display_Welcome_Screen();
	}

}



void Display_Welcome_Screen (void)
{
	HLCD_voidClearDisplay();
	HLCD_voidSetPosition(0,0);
	HLCD_voidSendString("1-LED ON/OFF");
	HLCD_voidSetPosition(1,0);
	HLCD_voidSendString("2-Open/Close Door");
}


void Relay_voidInit(u8 Copy_u8PortId, u8 Copy_u8PinId) { //PIN1 PORTC
	DIO_u8SetPinDirection(Copy_u8PortId, Copy_u8PinId, DIO_u8_OUTPUT);
}
void Relay_voidLED(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue) {
	DIO_u8SetPinValue(Copy_u8PortId, Copy_u8PinId, Copy_u8PinValue);
}
void Relay_voidDOOR(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue) {
	DIO_u8SetPinValue(Copy_u8PortId, Copy_u8PinId, Copy_u8PinValue);
}




