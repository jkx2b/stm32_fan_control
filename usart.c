#include "usart.h"
#include "stdio.h"
#include "string.h"


u16 USART_RX_STA=0;       //接收状态标记	  
u16 USART_RX_LEN=0;
u16 USART_STA=0;
u8 USART_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.




void USART1_Init(uint32_t bps)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//使能GPIOA的硬件时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	/* 使能串口1硬件时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	/* GPIOA9，10引脚配置 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* 复用GPIOA9 GPIOA10引脚为串口1 */ 
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	//初始化串口波特率，数据位，停止位，校验位，流控
	USART_InitStructure.USART_BaudRate = bps;			//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;	//数据位8bit
	USART_InitStructure.USART_StopBits = USART_StopBits_1;	//停止位1位
	USART_InitStructure.USART_Parity = USART_Parity_No;	//无奇偶校验
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//无硬件流控
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//允许串口发送数据，接收数据
	USART_Init(USART1, &USART_InitStructure);
	
	//串口中断
	//配置串口1中断的触发方式
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	//配置串口中断
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;		//串口1的中断	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;		//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;				//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//使能中断优先级
	NVIC_Init(&NVIC_InitStruct);
	
	//使能串口1开始工作
	USART_Cmd(USART1, ENABLE);
}

void USART2_Init(uint32_t bps)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//使能GPIOA的硬件时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	/* 使能串口2硬件时钟 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	/* GPIOA2，3引脚配置 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* 复用GPIOA2 GPIOA3引脚为串口2 */ 
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	
	//初始化串口波特率，数据位，停止位，校验位，流控
	USART_InitStructure.USART_BaudRate = bps;										//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;						//数据位8bit
	USART_InitStructure.USART_StopBits = USART_StopBits_1;							//停止位1位
	USART_InitStructure.USART_Parity = USART_Parity_No;								//无奇偶校验
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//无硬件流控
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//允许串口发送数据，接收数据
	USART_Init(USART2, &USART_InitStructure);
	
	//串口中断
	//配置串口1中断的触发方式
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	
	//配置串口中断
	NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;		//串口2的中断	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;		//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;				//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//使能中断优先级
	NVIC_Init(&NVIC_InitStruct);
	
	//使能串口2开始工作
	USART_Cmd(USART2, ENABLE);
}

void USART3_Init(uint32_t bps)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//使能GPIOA的硬件时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	/* 使能串口3硬件时钟 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
	/* GPIOA2，3引脚配置 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* 复用GPIOA2 GPIOA3引脚为串口2 */ 
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
	
	//初始化串口波特率，数据位，停止位，校验位，流控
	USART_InitStructure.USART_BaudRate = bps;										//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;						//数据位8bit
	USART_InitStructure.USART_StopBits = USART_StopBits_1;							//停止位1位
	USART_InitStructure.USART_Parity = USART_Parity_No;								//无奇偶校验
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//无硬件流控
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//允许串口发送数据，接收数据
	USART_Init(USART3, &USART_InitStructure);
	
	//串口中断
	//配置串口1中断的触发方式
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	
	//配置串口中断
	NVIC_InitStruct.NVIC_IRQChannel = USART3_IRQn;		//串口2的中断	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;		//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;				//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//使能中断优先级
	NVIC_Init(&NVIC_InitStruct);
	
	//使能串口3开始工作
	USART_Cmd(USART3, ENABLE);
}

void USART3_SendData(u8 data)
{
	while((USART3->SR&0X40)==0); 
	USART3->DR = data;
}

//串口3的中断服务函数
void USART3_IRQHandler(void)
{
	
	u8 Res;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) == SET)//判断有无中断产生   有中断产生表示接收数据
	{
		//printf("fan=%d\r\n",Res);
		Res =USART_ReceiveData(USART3);	//读取接收到的数据
		if((USART_RX_STA&0x8000)==0)//接收未完成
		{
			if(Res==0XFE)//接收到命令头
			{
				USART_STA=1;
				USART_RX_LEN=0;
			}
		  if(USART_STA)
			{
				USART_RX_BUF[USART_RX_LEN]=Res;
				USART_RX_LEN++;
				if(USART_RX_LEN>8)//接收8位数据接收完毕
				{
					USART_STA=0;
					USART_RX_STA|=0x8000;//接收已完成
				}
			}
		}   		
		
		//清除中断标志位
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
	}
}


void send_char(uint16_t c)
{
	USART_SendData(USART1, c);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void send_str(char *str)
{
	while(*str!='\0')
	{
		send_char(*str);
		str++;
	}
}

void send2_char(uint16_t c)
{
	USART_SendData(USART2, c);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}

void send2_str(char *str)
{
	while(*str!='\0')
	{
		send2_char(*str);
		str++;
	}
}

void send3_char(uint16_t c)
{
	USART_SendData(USART3, c);
	while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
}

void send3_str(char *str)
{
	while(*str!='\0')
	{
		send3_char(*str);
		str++;
	}
}

