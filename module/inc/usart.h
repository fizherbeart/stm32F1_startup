#ifndef __USART_H
#define __USART_H


#include "stm32f10x.h"



void USART1_Config(void);
void Usart_SendByte(USART_TypeDef* pUSARTx, uint8_t data);
void Usart_SendHalfWord(USART_TypeDef* pUSARTx, uint16_t data);
void Usart_SendArray(USART_TypeDef* pUSARTx, uint8_t *array,uint8_t num);
void Usart_SendStr(USART_TypeDef* pUSARTx, uint8_t *str);


#endif
