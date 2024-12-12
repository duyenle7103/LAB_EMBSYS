/*
 * input_process.c
 *
 *  Created on: Dec 12, 2024
 *      Author: Duyen
 */

#include "input_process.h"

void update_temp() {
	sensor_Read();
	current_temp = sensor_GetTemperature();
}
