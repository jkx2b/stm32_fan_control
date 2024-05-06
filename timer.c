#include "timer.h"

//定时器3初始化
void TIME3_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//1、使能硬件时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//2、硬件配置
	TIM_TimeBaseInitStruct.TIM_Period = (10000-1);		//计数周期值
	TIM_TimeBaseInitStruct.TIM_Prescaler = 8400-1;		//预分频值
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;		//向上计数

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);
	
	//配置定时器3中断触发方式，时间更新
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	//中断，中断优先级   抢占优先级和响应优先级
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;		//外部中断2通道	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;				//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//使能中断优先级
	NVIC_Init(&NVIC_InitStruct);
	
	//使能定时器工作
	TIM_Cmd(TIM3, ENABLE);
	
}

//定时器1初始化
void TIME1_Init()
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//1、使能硬件时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	//2、硬件配置
	TIM_TimeBaseInitStruct.TIM_Period = (10000-1)/2;		//计数周期值
	TIM_TimeBaseInitStruct.TIM_Prescaler = 16800-1;		//预分频值
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;		//向上计数

	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStruct);
	
	//配置定时器1中断触发方式，时间更新
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	
	//中断，中断优先级   抢占优先级和响应优先级
	NVIC_InitStruct.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;		//外部中断1通道	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;				//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//使能中断优先级
	NVIC_Init(&NVIC_InitStruct);
	
	//使能定时器工作
	TIM_Cmd(TIM1, ENABLE);
	
}


