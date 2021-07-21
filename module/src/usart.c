#include "usart.h"


void USART1_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStrue;
	USART_InitTypeDef USART_InitStrue;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//串口时钟使能
	
	
    GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP;  
    GPIO_InitStrue.GPIO_Pin=GPIO_Pin_9;  
    GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;  
    GPIO_Init(GPIOA,&GPIO_InitStrue);  
     
    GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;  
    GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10;  
    GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;  
    GPIO_Init(GPIOA,&GPIO_InitStrue); 
	 
	  USART_InitStrue.USART_BaudRate=9600; 
    USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None; 
    USART_InitStrue.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;  
    USART_InitStrue.USART_Parity=USART_Parity_No;  
    USART_InitStrue.USART_StopBits=USART_StopBits_1;  
    USART_InitStrue.USART_WordLength=USART_WordLength_8b;   
	  USART_Init(USART1,&USART_InitStrue);
 
    USART_Cmd(USART1,ENABLE);//使能串口1  
		//USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//开启接收中断
}

/* 发送一个字节 */
void Usart_SendByte(USART_TypeDef* pUSARTx, uint8_t data)
{
	USART_SendData(pUSARTx, data);
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET );
}

/* 发送两个字节的数据 */
void Usart_SendHalfWord(USART_TypeDef* pUSARTx, uint16_t data)
{
	uint8_t temp_h,temp_l;
	
	temp_h = (data&0xff00) >> 8 ;
	temp_l = data&0xff;
	
	USART_SendData(pUSARTx, temp_h);
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET );
	
	USART_SendData(pUSARTx, temp_l);
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET );
}

/* 发送8位数据的数组 */
void Usart_SendArray(USART_TypeDef* pUSARTx, uint8_t *array,uint8_t num)
{
	uint8_t i;
	for( i=0; i<num; i++ )
  {
		Usart_SendByte(pUSARTx, array[i]);
	}
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET );
}

/* 发送字符串 */
void Usart_SendStr(USART_TypeDef* pUSARTx, uint8_t *str)
{
	uint8_t i=0;
	do
  {
		Usart_SendByte(pUSARTx, *(str+i));
		i++;
	}while(*(str+i) != '\0');
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET );
}

///重定向c库函数printf到串口，重定向后可使用printf函数
//int fputc(int ch, FILE *f)
//{
//		/* 发送一个字节数据到串口 */
//		USART_SendData(USART1, (uint8_t) ch);
//		
//		/* 等待发送完毕 */
//		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);		
//	
//		return (ch);
//}

///重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数
//int fgetc(FILE *f)
//{
//		/* 等待串口输入数据 */
//		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

//		return (int)USART_ReceiveData(USART1);
//}



//void USART1_IRQHandler(void)  

//{  
//     u16 res =0;  
//     if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)  
// {  
//     res= USART_ReceiveData(USART1); 	 
//     USART_SendData(USART1,res);
//  }  
//}

