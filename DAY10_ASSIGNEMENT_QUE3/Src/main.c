/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "timer.h"
#include "led.h"
#include "i2c_lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	//Use TIM7 to generate interrupt after every 1 second.
	//Increment a global count in interrupt handler. Display count value on LCD (I2C based).
	SystemInit();
	char str[20];
	LedInit(LED_BLUE);
	//int ret;
	LcdInit();
	count = 0;
	TimerInit(1000);

	while(1){
			//if(ret){
			sprintf(str,"Count = %d",count);
			LcdPuts(LCD_LINE1,str);
			LcdPuts(LCD_LINE2,"your count");
			//}
	}
	return 0;
}
