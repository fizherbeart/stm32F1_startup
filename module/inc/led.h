#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"


#define LED_GPIO_PIN              GPIO_Pin_13
#define LED_GPIO_PORT             GPIOC
#define LED_GPIO_CLK              RCC_APB2Periph_GPIOC

#define LED_TOGGLE    {LED_GPIO_PORT->ODR ^= LED_GPIO_PIN;}  //按位异或


void led_init(void);


void LED_flash(void);



//头文件内： 宏定义 函数定义 存放外设的初始化结构体，外设初始化结构体成员的参数列表，外设固件库函数的声明
#endif
