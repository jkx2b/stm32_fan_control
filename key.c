#include"key.h"


void KEY_Init(void)
{
	// GPIO初始化的结构体
	GPIO_InitTypeDef GPIO_InitStruct;
	

	// 1、使能硬件时钟   GPIOF9的硬件时钟   AHB1
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0; // 引脚
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;			 // 输出模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 // 速度
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // 推挽输出
	//GPIO_InitStruct1.GPIO_PuPd = GPIO_PuPd_UP;		 // 上拉
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;		 // 下拉
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	
}

void PA8_Init(void)
{
	// GPIO初始化的结构体
	GPIO_InitTypeDef GPIO_InitStruct;
	

	// 1、使能硬件时钟   GPIOF9的硬件时钟   AHB1
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8; // 引脚
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;			 // 输出模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 // 速度
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // 推挽输出
	//GPIO_InitStruct1.GPIO_PuPd = GPIO_PuPd_UP;		 // 上拉
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;		 // 下拉
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9; // 引脚
	GPIO_Init(GPIOG, &GPIO_InitStruct);
	
}

