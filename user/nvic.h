#ifndef  __NVIC_H
#define  __NVIC_H

#include "stm32f10x.h"

void NVIC_Config(void);
void NVIC_Struct(uint8_t PreemptionPriority,uint8_t SubPriority,uint8_t Channel,FunctionalState Cmd);

#endif

