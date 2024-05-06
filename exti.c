#include "exti.h"


//外部中断0初始化
void EXTI0_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
//	端口A硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
//	SYSCFG硬件时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
//	配置引脚的工作模式
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_0;		//引脚
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;		//输入模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	//速度
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;	//下拉
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
//	将引脚连接到外部中断
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	
//	中断的触发方式：电平触发，边沿触发
	EXTI_InitStruct.EXTI_Line = EXTI_Line0; //外部中断0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; 	//中断模式
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;		//中断触发方式
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;				//	允许外部中断引脚申请中断请求
	EXTI_Init(&EXTI_InitStruct);
	
//	优先级的配置
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;		//外部中断0通道	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;				//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//使能中断优先级
	NVIC_Init(&NVIC_InitStruct);

}

//外部中断2初始化
void EXTI2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
//	端口E硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
//	SYSCFG硬件时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
//	配置引脚的工作模式
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_2;		//引脚
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;		//输入模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	//速度
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;	//下拉
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
//	将引脚连接到外部中断
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource2);
	
//	中断的触发方式：电平触发，边沿触发
	EXTI_InitStruct.EXTI_Line = EXTI_Line2; //外部中断0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; 	//中断模式
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;		//中断触发方式
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;				//	允许外部中断引脚申请中断请求
	EXTI_Init(&EXTI_InitStruct);
	
//	优先级的配置
	NVIC_InitStruct.NVIC_IRQChannel = EXTI2_IRQn;		//外部中断0通道	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;				//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//使能中断优先级
	NVIC_Init(&NVIC_InitStruct);

}

//外部中断3初始化
void EXTI3_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
//	端口E硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
//	SYSCFG硬件时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
//	配置引脚的工作模式
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_3;		//引脚
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;		//输入模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	//速度
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;	//下拉
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
//	将引脚连接到外部中断
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);
	
//	中断的触发方式：电平触发，边沿触发
	EXTI_InitStruct.EXTI_Line = EXTI_Line3; //外部中断0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; 	//中断模式
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;		//中断触发方式
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;				//	允许外部中断引脚申请中断请求
	EXTI_Init(&EXTI_InitStruct);
	
//	优先级的配置
	NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;		//外部中断0通道	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;				//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//使能中断优先级
	NVIC_Init(&NVIC_InitStruct);

}

//外部中断3初始化
void EXTI4_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
//	端口E硬件时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
//	SYSCFG硬件时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
//	配置引脚的工作模式
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_4;		//引脚
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;		//输入模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	//速度
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;	//下拉
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
//	将引脚连接到外部中断
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);
	
//	中断的触发方式：电平触发，边沿触发
	EXTI_InitStruct.EXTI_Line = EXTI_Line4; //外部中断0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; 	//中断模式
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;		//中断触发方式
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;				//	允许外部中断引脚申请中断请求
	EXTI_Init(&EXTI_InitStruct);
	
//	优先级的配置
	NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;		//外部中断0通道	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;				//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//使能中断优先级
	NVIC_Init(&NVIC_InitStruct);

}




////	中断服务函数
//void EXTI0_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line0) != RESET)//获取外部中断0
//	{
//		PFout(8)=1;
//		PFout(9) = 0;
//		delay_ms(250);
//		PFout(8)=0;
//		PFout(9) = 1;
//		delay_ms(250);
//		PFout(8)=1;
//		PFout(9) = 0;
//		delay_ms(250);
//		PFout(8)=0;
//		PFout(9) = 1;
//		delay_ms(250);

//		//清除exti0的中断标志位
//		EXTI_ClearITPendingBit(EXTI_Line0);
//	}
//}

////	中断服务函数
//void EXTI2_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line2) != RESET)//获取外部中断0
//	{
//		
//		PFout(10) = 0;
//		delay_ms(500);
//		PFout(10) = 1;
//		delay_ms(500);
//		PFout(10) = 0;
//		delay_ms(500);
//		PFout(10) = 1;
//		delay_ms(500);
//		
//		
//		//清除exti2的中断标志位
//		EXTI_ClearITPendingBit(EXTI_Line2);
//	}
//}

//void EXTI3_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line3) != RESET)//获取外部中断0
//	{
//		
//		PEout(13) = 0;
//		delay_ms(500);
//		
//		PEout(13) = 1;
//		
//		
//		//清除exti3的中断标志位
//		EXTI_ClearITPendingBit(EXTI_Line3);
//	}
//}

//void EXTI4_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line4) != RESET)//获取外部中断0
//	{
//		PFout(8)=1;
//		PEout(14) = 0;
//		delay_ms(1000);
//		PFout(8)=0;
//		PEout(14) = 1;
//		delay_ms(1000);
//		PFout(8)=1;
//		PEout(14) = 0;
//		delay_ms(1000);
//		PFout(8)=0;
//		PEout(14) = 1;
//		delay_ms(1000);
//		
//		//清除exti3的中断标志位
//		EXTI_ClearITPendingBit(EXTI_Line4);
//	}
//}

