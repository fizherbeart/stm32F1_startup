#include "exti.h"
#include "led.h"

void EXTI0_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	EXTI_InitTypeDef  EXTI_InitStruct;

	// 初始化GPIO
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);	
	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;		
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);	
	
	// 初始化EXTI
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
}

void EXTI0_IRQHandler (void)
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		LED_TOGGLE;
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}
