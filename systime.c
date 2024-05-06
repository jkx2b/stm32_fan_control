#include "systime.h"


void delay(void)
{
	volatile int i = 1000;
	while(i--)
	{
		volatile int j = 10000;
		while(j--)
		{
		}
	}
}

//系统滴答时钟
//延时1ms函数
void delay_ms(uint16_t i)
{
	while(i--)
	{
		SysTick->CTRL = 0; 			//关闭系统定时器
		SysTick->LOAD = 168000-1;		//计数值重装载
		SysTick->VAL = 0; 			//清除当前值和计数标志
		SysTick->CTRL = 5; 			//使能定时器，写入控制和状态寄存器
		while ((SysTick->CTRL & 0x00010000)==0);//等待计数值到0，重新设置计数标志跟计数值重装载
	}	
	SysTick->CTRL = 0; 			//关闭系统定时器
}

//延时1us函数
void delay_us(uint16_t i)
{
	while(i--)
	{
		SysTick->CTRL = 0; 			//关闭系统定时器
		SysTick->LOAD = 168-1;		//计数值重装载
		SysTick->VAL = 0; 			//清除当前值和计数标志
		SysTick->CTRL = 5; 			//使能定时器，写入控制和状态寄存器
		while ((SysTick->CTRL & 0x00010000)==0);//等待计数值到0，重新设置计数标志跟计数值重装载
	}	
	SysTick->CTRL = 0; 			//关闭系统定时器
}

//延时1s函数
void delay_s(uint16_t i)
{
	delay_ms(i*1000);
}


/*
//SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
//延时1ms函数
void delay_ms(uint16_t i)
{
	while(i--)
	{
		SysTick->CTRL = 0; 			//关闭系统定时器
		SysTick->LOAD = 21000-1;		//计数值重装载
		SysTick->VAL = 0; 			//清除当前值和计数标志
		SysTick->CTRL = 1; 			//使能定时器，写入控制和状态寄存器
		while ((SysTick->CTRL & 0x00010000)==0);//等待计数值到0，重新设置计数标志跟计数值重装载
	}	
	SysTick->CTRL = 0; 			//关闭系统定时器
}

//延时1us函数
void delay_us(uint16_t i)
{
	while(i--)
	{
		SysTick->CTRL = 0; 			//关闭系统定时器
		SysTick->LOAD = 21-1;		//计数值重装载
		SysTick->VAL = 0; 			//清除当前值和计数标志
		SysTick->CTRL = 1; 			//使能定时器，写入控制和状态寄存器
		while ((SysTick->CTRL & 0x00010000)==0);//等待计数值到0，重新设置计数标志跟计数值重装载
	}	
	SysTick->CTRL = 0; 			//关闭系统定时器
}

//延时1s函数
void delay_s(uint16_t i)
{
	delay_ms(i*1000);
}
*/

