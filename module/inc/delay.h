#ifndef  __DELAY_H
#define  __DELAY_H

#include "stm32f10x.h"
//#include "init.h"


void Delay(uint32_t nCount);

void SysTick_Delay_ms(uint32_t ms);
void SysTick_Delay_us(uint32_t us);




#endif
