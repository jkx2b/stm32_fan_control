#include"led.h"


void LED_Init(void)
{
	// GPIO初始化的结构体
	GPIO_InitTypeDef GPIO_InitStruct;
	

	// 1、使能硬件时钟   GPIOF9的硬件时钟   AHB1
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	

	// 2、硬件配置  GPIOF9
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10 ;// 引脚
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;			 // 输出模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 // 速度
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // 推挽输出
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;		 // 无上拉下拉
	
	
	
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	
	PCout(10)=1;

	
}


//void LED_Init(void)
//{
//	// GPIO初始化的结构体
//	GPIO_InitTypeDef GPIO_InitStruct;
//	

//	// 1、使能硬件时钟   GPIOF9的硬件时钟   AHB1
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
//	

//	// 2、硬件配置  GPIOF9
//	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_8; // 引脚
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;			 // 输出模式
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 // 速度
//	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // 推挽输出
//	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;		 // 无上拉下拉
//	
//	
//	
//	GPIO_Init(GPIOF, &GPIO_InitStruct);

//	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
//	GPIO_Init(GPIOE, &GPIO_InitStruct);
//	
//	PFout(10)=1;
//	PFout(9)=1;
//	PEout(13)=1;
//	PEout(14)=1;

//	
//}

