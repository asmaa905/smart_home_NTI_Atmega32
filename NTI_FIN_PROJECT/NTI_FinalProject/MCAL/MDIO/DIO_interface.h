/********************************************************************************************
 * Name   : DIO_interface.h
 * Date   : 7/10/2021
 * Version: v01
 * Author : Heba Safwat
 *********************************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/***************************************  Public Macros *************************************/
/* Port ID Macros */
#define DIO_u8_PORTA                0
#define DIO_u8_PORTB                1
#define DIO_u8_PORTC                2
#define DIO_u8_PORTD                3


/* PIN ID Macros */
#define DIO_u8_PIN0                 0
#define DIO_u8_PIN1                 1
#define DIO_u8_PIN2                 2
#define DIO_u8_PIN3                 3
#define DIO_u8_PIN4                 4
#define DIO_u8_PIN5                 5
#define DIO_u8_PIN6                 6
#define DIO_u8_PIN7                 7


/* Direction Macros */
#define DIO_u8_INPUT_FLOATING       0
#define DIO_u8_OUTPUT               1
#define DIO_u8_INPUT_PULLED_UP         2


/* Values Macros */
#define DIO_u8_LOW                  0
#define DIO_u8_HIGH                 1


/*************************  Prototypes of public functions  ****************************/
u8 DIO_u8SetPinDirection  (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDirection);
                          
u8 DIO_u8SetPinValue      (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinValue);
                          
u8 DIO_u8GETPinValue      (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 * Copy_Pu8ReturnedPinValue);
                          
u8 DIO_u8TogPinValue      (u8 Copy_u8PortId , u8 Copy_u8PinId);

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId , u8 Copy_u8PortDirection);

u8 DIO_u8SetPortValue     (u8 Copy_u8PortId , u8 Copy_u8PortValue);
                          
u8 DIO_u8GETPortValue     (u8 Copy_u8PortId , u8 * Copy_Pu8ReturnedPortValue);

#endif
