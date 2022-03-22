/*
 * MUART_config.h
 *
 *  Created on: Oct 21, 2021
 *      Author: AT Once
 */

#ifndef MCAL_MUART_MUART_CONFIG_H_
#define MCAL_MUART_MUART_CONFIG_H_

/*
 * Options for the operation mode:
 * MUART_AsynchronousOperation
 * MUART_SynchronousOperation
 * */
#define MUART_OPERATION_MODE  MUART_AsynchronousOperation


/*Options for the number of data bits
 * MUART_DATA_SIZE_5
 * MUART_DATA_SIZE_6
 * MUART_DATA_SIZE_7
 * MUART_DATA_SIZE_8
 * MUART_DATA_SIZE_9
 */
#define MUART_DATA_BITS     MUART_DATA_SIZE_8

/*Options for the stop bits:
 * MUART_1_STOP_BIT
 * MUART_2_STOP_BIT
 */
#define MUART_STOP_BIT   MUART_1_STOP_BIT

/*Options for the parity :
 * MUART_DISABLE_PARITY
 * MUART_EVEN_PARITY
 * MUART_ODD_PARITY
 */
#define MUART_PARITY_BIT MUART_DISABLE_PARITY
/* Options for the boud rate
 * MUART_BR_4800_8MHZ
 * MUART_BR_9600_8MHZ
 * MUART_BR_115200_8MHZ
 * MUART_BR_4800_16MHZ
 * MUART_BR_9600_16MHZ
 * MUART_BR_115200_16MHZ
 */
#define MUART_BOUD_RATE   MUART_BR_9600_8MHZ

#endif /* MCAL_MUART_MUART_CONFIG_H_ */
