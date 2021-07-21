#include "stm32f10x.h"
#include "module.h"   //module�ĳ�ʼ��
#include "task.h"   //
#include "sysclk.h" //����ϵͳʱ��
#include "nvic.h"

void module_init(void){
	
	// ��ͨģ��
	led_init(); //pc13
	
	// ��Ҫ�����жϵ�ģ��
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
