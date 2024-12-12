/*
 * esp_process.c
 *
 *  Created on: Dec 30, 2023
 *      Author: ADMIN
 */

#include "esp_process.h"

float tp;
uint8_t tp1 = 0;
uint8_t tp2 = 0;

void sensor_esp() {
	char buffer[20];
	tp = current_temp;
	tp = tp * 100;
	tp1 = tp / 100; // Get integer part
	tp2 = (int) tp % 100; // Get decimal part
	sprintf(buffer, "!TEMP:%d.%02d#", tp1, tp2); // Create data string
	uart_EspSendBytes((uint8_t*)buffer, strlen(buffer)); // Send string via UART to ESP
}
