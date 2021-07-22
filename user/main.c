#include "stm32f10x.h"
#include "module.h"   //module�ĳ�ʼ��
#include "task.h"   //
#include "sysclk.h" //����ϵͳʱ��
#include "nvic.h"


void module_init(void){
	
	/* ��ͨģ�� */
	// led_init(); //pc13
	// anti_touch_init();

	// ========================================
	/* ��Ҫ�����жϵ�ģ�� */
	//	EXTI0_Config();
	// USART1_Config();
}


int main(void)	
{
	//ϵͳʱ������
	//HSE_SetSysClk( uint32_t RCC_PLLMul_9 ); //8M*9=72M
	
	NVIC_Config(); // �ж����ȼ�����
	
	module_init(); // ÿ��ģ��ĳ�ʼ��
	
	task();	// ��������Ҫ��ѭ��ִ�е�����
}
