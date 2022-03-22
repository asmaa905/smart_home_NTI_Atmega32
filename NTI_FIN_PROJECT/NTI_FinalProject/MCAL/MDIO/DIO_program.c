/********************************************************************************************
 * Name   : DIO_program.c
 * Date   : 7/10/2021
 * Version: v01
 * Author : Heba Safwat
 *********************************************************************************************/
/* Library Layer */
#include "data_types.h"
#include "bit_math.h"

/* MCAL */
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"


u8 DIO_u8SetPinDirection (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorStatus = STD_TYPES_OK;
	if(Copy_u8PinId <= DIO_u8_PIN7)
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8_PORTA :
			switch (Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT          : SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);  break;
			case DIO_u8_INPUT_FLOATING  : CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);  break;
			case DIO_u8_INPUT_PULLED_UP : CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);
			                              SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);/*activate internal pull up resistor*/
			                              break;
			default : Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Direction*/
			}
			break;
		case DIO_u8_PORTB :
			switch (Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT          : SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);  break;
			case DIO_u8_INPUT_FLOATING  : CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);  break;
			case DIO_u8_INPUT_PULLED_UP : CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);
			                              SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);/*activate internal pull up resistor*/
			                              break;
			default : Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Direction*/
			}
			break;
		case DIO_u8_PORTC :
			switch (Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT          : SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);  break;
			case DIO_u8_INPUT_FLOATING  : CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);  break;
			case DIO_u8_INPUT_PULLED_UP : CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);
			                              SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);/*activate internal pull up resistor*/
			                              break;
			default : Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Direction*/
			}
			break;
		case DIO_u8_PORTD :
			switch (Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT          : SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);  break;
			case DIO_u8_INPUT_FLOATING  : CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);  break;
			case DIO_u8_INPUT_PULLED_UP : CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);
			                              SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);/*activate internal pull up resistor*/
			                              break;
			default : Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Direction*/
			}
			break;
			default :  Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Port number*/
		}
	}
	else
	{
		Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Pin number*/
	}
	return Local_u8ErrorStatus;
}


u8 DIO_u8SetPinValue (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorStatus = STD_TYPES_OK;
	if(Copy_u8PinId<=DIO_u8_PIN7)
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8_PORTA :
			if(Copy_u8PinValue == DIO_u8_HIGH)      SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);
			else if (Copy_u8PinValue == DIO_u8_LOW) CLR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);
			else                                    Local_u8ErrorStatus = STD_TYPES_NOK;  //invalid pin value
			break;
		case DIO_u8_PORTB :
			if(Copy_u8PinValue == DIO_u8_HIGH)      SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);
			else if (Copy_u8PinValue == DIO_u8_LOW) CLR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);
			else                                    Local_u8ErrorStatus = STD_TYPES_NOK;  //invalid pin value
			break;
		case DIO_u8_PORTC :
			if(Copy_u8PinValue == DIO_u8_HIGH)      SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);
			else if (Copy_u8PinValue == DIO_u8_LOW) CLR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);
			else                                    Local_u8ErrorStatus = STD_TYPES_NOK;  //invalid pin value
			break;
		case DIO_u8_PORTD :
			if(Copy_u8PinValue == DIO_u8_HIGH)      SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);
			else if (Copy_u8PinValue == DIO_u8_LOW) CLR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);
			else                                    Local_u8ErrorStatus = STD_TYPES_NOK;  //invalid pin value
			break;
		default :
			Local_u8ErrorStatus = STD_TYPES_NOK; //invalid port number
		}
	}
	else
	{
		Local_u8ErrorStatus = STD_TYPES_NOK;    //invalid pin number
	}
	return Local_u8ErrorStatus ;
}

u8 DIO_u8GETPinValue (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 * Copy_Pu8ReturnedPinValue)
{
	u8 Local_u8ErrorStatus = STD_TYPES_OK;
	if((Copy_u8PinId <= DIO_u8_PIN7) && (Copy_Pu8ReturnedPinValue != NULL))
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8_PORTA:*Copy_Pu8ReturnedPinValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);break;
		case DIO_u8_PORTB:*Copy_Pu8ReturnedPinValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);break;
		case DIO_u8_PORTC:*Copy_Pu8ReturnedPinValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);break;
		case DIO_u8_PORTD:*Copy_Pu8ReturnedPinValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);break;
		default          :Local_u8ErrorStatus = STD_TYPES_NOK;    //invalid port number
		}
	}
	else
	{
		Local_u8ErrorStatus = STD_TYPES_NOK;    //invalid pin number or wild pointer
	}
	return Local_u8ErrorStatus;
}

u8 DIO_u8TogPinValue (u8 Copy_u8PortId , u8 Copy_u8PinId)
{
	u8 Local_u8ErrorStatus = STD_TYPES_OK;
	if(Copy_u8PinId <= DIO_u8_PIN7)
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8_PORTA : TOG_BIT(DIO_u8_PORTA_REG,Copy_u8PinId); break;
		case DIO_u8_PORTB : TOG_BIT(DIO_u8_PORTB_REG,Copy_u8PinId); break;
		case DIO_u8_PORTC : TOG_BIT(DIO_u8_PORTC_REG,Copy_u8PinId); break;
		case DIO_u8_PORTD : TOG_BIT(DIO_u8_PORTD_REG,Copy_u8PinId); break;
		default           : Local_u8ErrorStatus = STD_TYPES_NOK;    //invalid port number
		}
	}
	else
	{
		Local_u8ErrorStatus = STD_TYPES_NOK;    //invalid pin number
	}
	return Local_u8ErrorStatus;
}

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId , u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorStatus = STD_TYPES_OK;
	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA :
		switch (Copy_u8PortDirection)
		{
		case DIO_u8_OUTPUT          : DIO_u8_DDRA_REG = 0xFF;  break;
		case DIO_u8_INPUT_FLOATING  : DIO_u8_DDRA_REG = 0x00;  break;
		case DIO_u8_INPUT_PULLED_UP : DIO_u8_DDRA_REG = 0x00;
		                              DIO_u8_PORTA_REG = 0xFF;/*activate internal pull up resistor*/
		                              break;
		default : Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Direction*/
		}
		break;
	case DIO_u8_PORTB :
		switch (Copy_u8PortDirection)
		{
		case DIO_u8_OUTPUT          : DIO_u8_DDRB_REG = 0xFF;  break;
		case DIO_u8_INPUT_FLOATING  : DIO_u8_DDRB_REG = 0x00;  break;
		case DIO_u8_INPUT_PULLED_UP : DIO_u8_DDRB_REG = 0x00;
		                              DIO_u8_PORTB_REG = 0xFF;/*activate internal pull up resistor*/
		                              break;
		default : Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Direction*/
		}
		break;
	case DIO_u8_PORTC :
		switch (Copy_u8PortDirection)
		{
		case DIO_u8_OUTPUT          : DIO_u8_DDRC_REG = 0xFF;  break;
		case DIO_u8_INPUT_FLOATING  : DIO_u8_DDRC_REG = 0x00;  break;
		case DIO_u8_INPUT_PULLED_UP : DIO_u8_DDRC_REG = 0x00;
		                              DIO_u8_PORTC_REG = 0xFF;/*activate internal pull up resistor*/
		                              break;
		default : Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Direction*/
		}
		break;
	case DIO_u8_PORTD :
		switch (Copy_u8PortDirection)
		{
		case DIO_u8_OUTPUT          : DIO_u8_DDRD_REG = 0xFF;  break;
		case DIO_u8_INPUT_FLOATING  : DIO_u8_DDRD_REG = 0x00;  break;
		case DIO_u8_INPUT_PULLED_UP : DIO_u8_DDRD_REG = 0x00;
		                              DIO_u8_PORTD_REG = 0xFF;/*activate internal pull up resistor*/
		                              break;
		default : Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Direction*/
		}
		break;
		default :  Local_u8ErrorStatus = STD_TYPES_NOK;  /*invalid Port number*/
	}
	return Local_u8ErrorStatus;
}

u8 DIO_u8SetPortValue (u8 Copy_u8PortId , u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorStatus = STD_TYPES_OK;
	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA : DIO_u8_PORTA_REG = Copy_u8PortValue;break;
	case DIO_u8_PORTB : DIO_u8_PORTB_REG = Copy_u8PortValue;break;
	case DIO_u8_PORTC : DIO_u8_PORTC_REG = Copy_u8PortValue;break;
	case DIO_u8_PORTD : DIO_u8_PORTD_REG = Copy_u8PortValue;break;
	default :
		Local_u8ErrorStatus = STD_TYPES_NOK; //invalid port number
	}
	return Local_u8ErrorStatus;
}

u8 DIO_u8GETPortValue (u8 Copy_u8PortId , u8 * Copy_Pu8ReturnedPortValue)
{
	u8 Local_u8ErrorStatus = STD_TYPES_OK;
	if(Copy_Pu8ReturnedPortValue != NULL)
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8_PORTA :*Copy_Pu8ReturnedPortValue = DIO_u8_PINA_REG;break;
		case DIO_u8_PORTB :*Copy_Pu8ReturnedPortValue = DIO_u8_PINB_REG;break;
		case DIO_u8_PORTC :*Copy_Pu8ReturnedPortValue = DIO_u8_PINC_REG;break;
		case DIO_u8_PORTD :*Copy_Pu8ReturnedPortValue = DIO_u8_PIND_REG;break;
		default :
			Local_u8ErrorStatus = STD_TYPES_NOK;    //invalid port number
		}
	}
	else
	{
		Local_u8ErrorStatus = STD_TYPES_NOK;        //wild pointer
	}
	return Local_u8ErrorStatus;
}
