#include "led.h"
#include "delay.h"



void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE); //FunctionalState NewState Ê¹ÄÜÎ»
	
	GPIO_InitStruct.GPIO_Mode =	GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);	
}




void LED_flash(void)
{
		while (1){
	GPIO_SetBits(GPIOC, LED_GPIO_PIN);
	SysTick_Delay_ms(1000);
	GPIO_ResetBits(GPIOC, LED_GPIO_PIN);
	SysTick_Delay_ms(10);
	}
}





