/*
 * interface.c
 *
 *  Created on: Dec 12, 2024
 *      Author: Duyen
 */

#include "interface.h"

void init_lcd(){
	lcd_Clear(WHITE);
	lcd_ShowStr(20, 150, "TEMPERATURE:", BLACK, BLACK, 16, 1);
	lcd_ShowStr(20 + 160, 150, "oC", BLACK, BLACK, 16, 1);
}

void update_lcd(){
	lcd_ShowFloatNum(20 + 100, 150, current_temp, 4, RED, WHITE, 16);
}
