#ifndef __SYSCLK_H
#define __SYSCLK_H

#include "stm32f10x.h"

void HSE_SetSysClk( uint32_t RCC_PLLMul_x );
void HSI_SetSysClk( uint32_t RCC_PLLMul_x );





#endif //__SYSCLK_H
