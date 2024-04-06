/*
 * timer.c
 *
 *  Created on: Apr 4, 2024
 *      Author: sanket
 */

#include "led.h"
#include "timer.h"

void TimerInit(uint32_t ms) {
	// enable timer clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
	// set prescalar
	TIM7->PSC = TIM_PR-1;
	// set number of clocks to count
	uint16_t cnt = (TCLK / 1000) * ms / TIM_PR;
	TIM7->ARR = cnt - 1;
	// start count from 0
	TIM7->CNT = 0;
	// enable UI interrupt in timer
	TIM7->DIER |= TIM_DIER_UIE;
	// enable interrupt in NVIC
	NVIC_EnableIRQ(TIM7_IRQn);
	// start timer counter
	TIM7->CR1 |= TIM_CR1_CEN;
}

 extern int count = 0;
// implement timer ISR
void TIM7_IRQHandler(void)
{

	static int flag = 0;
			count ++ ;
	//char str[20];
	// check if interrupt occurred
	if(TIM7->SR & TIM_SR_UIF) {
		// then clear (ack) the interrupt
		TIM7->SR &= ~TIM_SR_UIF;
		// toggle LED
		if(flag == 0) {
			LedOn(LED_BLUE);
			//sprintf(str,"Count = %d \r",count);
			//LcdPuts(LCD_LINE1,str);
			flag = 1;
		} else {
			LedOff(LED_BLUE);
			flag = 0;
		}
	}
}

