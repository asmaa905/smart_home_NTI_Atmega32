/*
 * MUART_private.h
 *
 *  Created on: Oct 21, 2021
 *      Author: AT Once
 */

#ifndef MCAL_MUART_MUART_PRIVATE_H_
#define MCAL_MUART_MUART_PRIVATE_H_

/* UART Register definitions */

#define MUART_UDR_REGISTER           (*(volatile u8 * )0x2C)
#define MUART_UCSRA_REGISTER         (*(volatile u8 * )0x2B)
#define MUART_UCSRB_REGISTER         (*(volatile u8 * )0x2A)
#define MUART_UCSRC_REGISTER         (*(volatile u8 * )0x40)
#define MUART_UBRRL_REGISTER         (*(volatile u8 * )0x29)
#define MUART_UBRRH_REGISTER         (*(volatile u8 * )0x40)



/* Bits Definitions */
/* MUART_UCSRA_REGISTER Bits: */
#define RXC_BIN               7               /* USART Receive Complete */
#define TXC_BIN               6               /* USART Transmit Complete */
#define UDRE_BIN              5               /* USART Data Register Empty */
#define FE_BIN                4               /* Frame Error */
#define DOR_BIN               3               /* Data OverRun */
#define PE_BIN                2               /* Parity Error */
#define U2X_BIN               1               /* Double the USART Transmission Speed */
#define MPCM_BIN              0               /* Multi-processor Communication Mode */


/* MUART_UCSRB_REGISTER bits: */
#define RXCIE_BIN              7              /* RX Complete Interrupt Enable */
#define TXCIE_BIN              6              /* TX Complete Interrupt Enable */
#define UDRIE_BIN              5              /* USART Data Register Empty Interrupt Enable */
#define RXEN_BIN               4              /* Receiver Enable */
#define TXEN_BIN               3              /* Transmitter Enable */
#define UCSZ2_BIN              2              /* Character Size */
#define RXB8_BIN               1              /* Receive Data Bit 8 */
#define TXB8_BIN               0              /* Transmit Data Bit 8 */

/* MUART_UCSRC_REGISTER */
#define  URSEL_bin              7             /* This bit selects between accessing the UCSRC or the UBRRH Register */
#define  UMSEL_bin              6             /* USART Mode Select */
/* Parity Mode */
#define  UPM1_bin               5
#define  UPM0_bin               4
#define  USBS_bin               3             /* Stop Bit Select */
/* Character Size */
#define  UCSZ1_bin              2
#define  UCSZ0_bin              1
#define  UCPOL_bin              0             /* Clock Polarity */


/* Mode Selection: */
#define MUART_AsynchronousOperation              0
#define MUART_SynchronousOperation               1

/* Parity mode */
#define MUART_DISABLE_PARITY                     0
#define MUART_EVEN_PARITY                        2
#define MUART_ODD_PARITY                         3


/* Stop bits */
#define MUART_1_STOP_BIT                         0
#define MUART_2_STOP_BIT                         1

/* Character Size */
#define MUART_DATA_SIZE_5                        0
#define MUART_DATA_SIZE_6                        1
#define MUART_DATA_SIZE_7                        2
#define MUART_DATA_SIZE_8                        3
#define MUART_DATA_SIZE_9                        7

/* poud rate */
#define   MUART_BR_4800_8MHZ                    103
#define   MUART_BR_9600_8MHZ                     51
#define   MUART_BR_115200_8MHZ                    3
#define   MUART_BR_4800_16MHZ                   207
#define   MUART_BR_9600_16MHZ                   103
#define   MUART_BR_115200_16MHZ                   8


#endif /* MCAL_MUART_MUART_PRIVATE_H_ */
