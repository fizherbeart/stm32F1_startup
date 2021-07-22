#include "touch_IC.h"
#include "module.h"

void anti_touch_init(void){
	
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //FunctionalState NewState ʹ��λ

	GPIO_InitStruct.GPIO_Mode =	GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOA, &GPIO_InitStruct);	
}


void anti_touch(void){
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.GPIO_Mode =	GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);	

	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	//	GPIO_SetBits(GPIOA, GPIO_Pin_4);

	SysTick_Delay_ms(100);
	anti_touch_init();
	
}
