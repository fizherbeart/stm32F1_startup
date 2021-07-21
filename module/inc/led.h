#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"


#define LED_GPIO_PIN              GPIO_Pin_13
#define LED_GPIO_PORT             GPIOC
#define LED_GPIO_CLK              RCC_APB2Periph_GPIOC

#define LED_TOGGLE    {LED_GPIO_PORT->ODR ^= LED_GPIO_PIN;}  //��λ���


void led_init(void);


void LED_flash(void);



//ͷ�ļ��ڣ� �궨�� �������� �������ĳ�ʼ���ṹ�壬�����ʼ���ṹ���Ա�Ĳ����б�����̼��⺯��������
#endif
