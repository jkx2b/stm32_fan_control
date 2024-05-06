#include "pwm.h"


void PWM_TIM14_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//定时器14硬件时钟使能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);
	
	//GPIOF硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//PF9引脚配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			//引脚编号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//输出速度
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//推挽输出
	
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	//将PF9引脚绑定到TIM14
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource9, GPIO_AF_TIM14);

	//定时器14配置
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//计数值
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//预分频值
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	
	TIM_TimeBaseInit(TIM14, &TIM_TimeBaseStructure);
	
	//TIM14定时器通道1的输出配置
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM输出模式1，输出低电平
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//使能PWM	脉冲输出
	TIM_OCInitStructure.TIM_Pulse = 100;		//比较值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//高电平有效状态，低电平有效状态
	
	TIM_OC1Init(TIM14, &TIM_OCInitStructure);
	
	//使能定时器14工作
	TIM_Cmd(TIM14, ENABLE);
	
	
}

void PWM_TIM13_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//定时器14硬件时钟使能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13, ENABLE);
	
	//GPIOF硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//PF9引脚配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			//引脚编号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//输出速度
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//推挽输出
	
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	//将PF9引脚绑定到TIM14
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource8, GPIO_AF_TIM13);

	//定时器14配置
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//计数值
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//预分频值
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	
	TIM_TimeBaseInit(TIM13, &TIM_TimeBaseStructure);
	
	//TIM14定时器通道1的输出配置
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM输出模式1，输出低电平
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//使能PWM	脉冲输出
	TIM_OCInitStructure.TIM_Pulse = 100;		//比较值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//高电平有效状态，低电平有效状态
	
	TIM_OC1Init(TIM13, &TIM_OCInitStructure);
	
	//使能定时器14工作
	TIM_Cmd(TIM13, ENABLE);
	
	
}

void PWM_TIM1_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//定时器14硬件时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	//GPIOF硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	//PF9引脚配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;			//引脚编号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//输出速度
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//推挽输出
	
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	//将PF9引脚绑定到TIM14
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);

	//定时器14配置
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//计数值
	TIM_TimeBaseStructure.TIM_Prescaler = 16800-1;		//预分频值
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	//TIM14定时器通道1的输出配置
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM输出模式1，输出低电平
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//使能PWM	脉冲输出
	TIM_OCInitStructure.TIM_Pulse = 100;		//比较值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//高电平有效状态，低电平有效状态
	
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	
	//使能定时器14工作
	TIM_Cmd(TIM1, ENABLE);
	
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
	
}

void PWM_TIM1_Init_pa8(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//定时器14硬件时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	//GPIOF硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	//PF9引脚配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			//引脚编号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//输出速度
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//推挽输出
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//将PF9引脚绑定到TIM14
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);

	//定时器14配置
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//计数值
	TIM_TimeBaseStructure.TIM_Prescaler = 16800-1;		//预分频值
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	//TIM14定时器通道1的输出配置
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM输出模式1，输出低电平
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//使能PWM	脉冲输出
	TIM_OCInitStructure.TIM_Pulse = 100;		//比较值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;		//高电平有效状态，低电平有效状态
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	
	//使能定时器14工作
	TIM_Cmd(TIM1, ENABLE);
	
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
	
}

void PWM_TIM3_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//定时器14硬件时钟使能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//GPIOF硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	//PF9引脚配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			//引脚编号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//输出速度
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//推挽输出
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	//将PF9引脚绑定到TIM14
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);

	//定时器14配置
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//计数值
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//预分频值
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	//TIM14定时器通道1的输出配置
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM输出模式1，输出低电平
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//使能PWM	脉冲输出
	TIM_OCInitStructure.TIM_Pulse = 100;		//比较值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//高电平有效状态，低电平有效状态
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	
	//使能定时器14工作
	TIM_Cmd(TIM3, ENABLE);
	
	
}

void PWM_TIM4_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//定时器4硬件时钟使能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	//GPIOD硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	//PF9引脚配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;			//引脚编号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//输出速度
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//推挽输出
	
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	//将PF9引脚绑定到TIM14
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);

	//定时器14配置
	TIM_TimeBaseStructure.TIM_Period = 200-1;			//计数值
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//预分频值
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	//TIM14定时器通道1的输出配置
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM输出模式1，输出低电平
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//使能PWM	脉冲输出
	TIM_OCInitStructure.TIM_Pulse = 100;		//比较值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//高电平有效状态，低电平有效状态
	
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	
	//使能定时器14工作
	TIM_Cmd(TIM4, ENABLE);
	
	
}

