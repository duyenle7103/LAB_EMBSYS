/*
 * uart.h
 *
 *  Created on: Nov 18, 2023
 *      Author: ADMIN
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "lcd.h"
#include "usart.h"
#include <stdio.h>
#include "utils.h"

void uart_init_rs232();

void uart_Rs232SendString(uint8_t* str);

void uart_Rs232SendBytes(uint8_t* bytes, uint16_t size);

void uart_Rs232SendNum(uint32_t num);

void uart_Rs232SendNumPercent(uint32_t num);

void uart_init_esp();

void uart_EspSendBytes(uint8_t* bytes, uint16_t size);

uint8_t uart_EspCheck();

#endif /* INC_UART_H_ */
