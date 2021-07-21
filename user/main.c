#include "stm32f10x.h"
#include "module.h"   //module的初始化
#include "task.h"   //
#include "sysclk.h" //配置系统时钟
#include "nvic.h"

void module_init(void){
	
	// 普通模块
	led_init(); //pc13
	
	// 需要配置中断的模块
	EXTI0_Config();
	USART1_Config();
	
}


int main(void)	
{
	//HSE_SetSysClk( uint32_t RCC_PLLMul_9 ); //8M*9=72M
	
	NVIC_Config();
	
	module_init();
	
	task();	
}
