/*
 * MUART_interface.h
 *
 *  Created on: Oct 21, 2021
 *      Author: AT Once
 */

#ifndef MCAL_MUART_MUART_INTERFACE_H_
#define MCAL_MUART_MUART_INTERFACE_H_

void MUART_voidUARTInit(void);
void MUART_voidTransmitData(u8 copy_u8Data);
u8 MUART_u8ReceiveData(void);
void MUART_voidSendString(u8 *copy_ptr);

#endif /* MCAL_MUART_MUART_INTERFACE_H_ */
