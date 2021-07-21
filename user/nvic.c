#include "nvic.h"


//IRQ Channels list refer to stm32f10x.h file 
//seach: STM32 specific Interrupt Numbers



void NVIC_Config(void) //�ж����ȼ�����
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	/* ��ռ���ȼ� �����ȼ� �ж�Դ ʹ�� */
	NVIC_Struct(1,1,EXTI0_IRQn,ENABLE);
	NVIC_Struct(1,1,USART1_IRQn,ENABLE);
}


void NVIC_Struct(uint8_t PreemptionPriority,uint8_t SubPriority,uint8_t Channel,FunctionalState Cmd)
	{
		NVIC_InitTypeDef NVIC_InitStruct;		
	NVIC_InitStruct.NVIC_IRQChannel = Channel;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = PreemptionPriority;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = SubPriority;
	NVIC_InitStruct.NVIC_IRQChannelCmd = Cmd;
	NVIC_Init(&NVIC_InitStruct);	
}


