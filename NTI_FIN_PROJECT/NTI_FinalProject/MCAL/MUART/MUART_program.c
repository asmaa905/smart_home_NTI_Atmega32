/*
 * MUART_program.c
 *
 *  Created on: Oct 21, 2021
 *      Author: AT Once
 */


#include "BIT_MATH.h"
#include "data_types.h"

#include "MUART_interface.h"
#include "MUART_config.h"
#include "MUART_private.h"

void MUART_voidUARTInit(void)
{
	/* Step 1 : TX Enable */
	SET_BIT(MUART_UCSRB_REGISTER,TXEN_BIN);
	/* Step 2 : RX Enable*/
	SET_BIT(MUART_UCSRB_REGISTER,RXEN_BIN);
	/* Step 3 : UART mode selection */
    #if (MUART_OPERATION_MODE == MUART_AsynchronousOperation)
	CLR_BIT(MUART_UCSRC_REGISTER,UMSEL_bin);
    #elif((MUART_OPERATION_MODE == MUART_SynchronousOperation)
	SET_BIT(MUART_UCSRC_REGISTER,UMSEL_bin);
    #endif
	/* Step 4 : configure the data bit */
    #if(MUART_DATA_BITS == MUART_DATA_SIZE_9)
	/* choose Register C */
	SET_BIT(MUART_UCSRC_REGISTER,URSEL_bin);
	/* write in register C */
	SET_BIT(MUART_UCSRC_REGISTER,UCSZ1_bin);
	SET_BIT(MUART_UCSRC_REGISTER,UCSZ0_bin);
	SET_BIT(MUART_UCSRB_REGISTER,UCSZ2_BIN);
    #else
	/* choose register C */
	SET_BIT(MUART_UCSRC_REGISTER,URSEL_bin);
	/* write in register C */
	MUART_UCSRC_REGISTER = MUART_DATA_BITS<<1;
    #endif
	/* Step 5 : configure the stop bit */
	MUART_UCSRC_REGISTER = MUART_STOP_BIT <<3;
	/* Step 6 : configure the parity bit  */
	//choose Register UBBRH
	CLR_BIT(MUART_UCSRC_REGISTER,URSEL_bin);
	MUART_UCSRC_REGISTER = MUART_PARITY_BIT>>8;
	/* Step 7 : configure the baud rate */
	MUART_UBRRL_REGISTER = MUART_BOUD_RATE;
}

void MUART_voidTransmitData(u8 copy_u8Data)
{
	/*  */
	while(GET_BIT(MUART_UCSRA_REGISTER,UDRE_BIN)==0);
	MUART_UDR_REGISTER = copy_u8Data;
}

u8 MUART_u8ReceiveData(void)
{
	u8 Local_u8ReceivedData ;
	/* Wait until data is received */
	while(GET_BIT(MUART_UCSRA_REGISTER,RXC_BIN)==0);
	/* Access UDR register to read data */
	Local_u8ReceivedData = MUART_UDR_REGISTER;
	return Local_u8ReceivedData;
}

void MUART_voidSendString(u8 *copy_ptr)
{
	u32 i=0;
	while(copy_ptr[i] != '\0')
	{
		MUART_voidTransmitData(copy_ptr[i]);
		i++;
	}
}

