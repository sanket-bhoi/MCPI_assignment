/*
 * myuart.h
 *
 *  Created on: Apr 1, 2024
 *      Author: sanket
 */

#ifndef MYUART_H_
#define MYUART_H_

#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define TX_PIN			2
#define RX_PIN			3
#define USART_ALT_FN	7

#define BAUD_9600		9600
#define BAUD_38400		38400
#define BAUD_115200		115200

#define BAUD_BRR_9600	0x683
#define BAUD_BRR_38400	0x1A1
#define BAUD_BRR_115200	0x8B

void UartInit(uint32_t baud);
void UartPutch(uint8_t ch);
void UartPuts(char str[]);
void UartGets(char str[]);
uint8_t UartGetch(void);

#endif /* MYUART_H_ */
