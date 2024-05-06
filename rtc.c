#include "rtc.h"


void rtc_init(void)
{
	RTC_DateTypeDef RTC_DateStructure;
	RTC_InitTypeDef RTC_InitStructure;
	RTC_TimeTypeDef RTC_TimeStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	/* 使能RTC硬件时钟 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	
	/* 允许使用RTC */
	PWR_BackupAccessCmd(ENABLE);
	
	/* 使能LSE作为时钟 */
	RCC_LSEConfig(RCC_LSE_ON);
	
	/* 等待LSE有效 */  
	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
	{
	}
	
	/* 选择RTC作为时钟源 */
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	
	/* 使能RTC硬件时钟 */
	RCC_RTCCLKCmd(ENABLE);
	
	/* 等待RTC APB寄存器就绪 */
	RTC_WaitForSynchro();
	
	/* 配置RTC的异步分频，同步分频，小时制 */
	RTC_InitStructure.RTC_AsynchPrediv = 0x7F;				//异步分频
	RTC_InitStructure.RTC_SynchPrediv = 0xFF;				//同步分频
	RTC_InitStructure.RTC_HourFormat = RTC_HourFormat_24;	//24小时制
	RTC_Init(&RTC_InitStructure);
	
	/* 设置时间 */
	RTC_TimeStructure.RTC_H12     = RTC_H12_PM;	//AM上午  PM下午
	RTC_TimeStructure.RTC_Hours   = 0x17;
	RTC_TimeStructure.RTC_Minutes = 0x00;
	RTC_TimeStructure.RTC_Seconds = 0x00; 
	RTC_SetTime(RTC_Format_BCD, &RTC_TimeStructure);   
	
	/* 设置日期: Friday January 11th 2013 */
	RTC_DateStructure.RTC_Year = 0x23;
	RTC_DateStructure.RTC_Month = RTC_Month_October;
	RTC_DateStructure.RTC_Date = 0x26;
	RTC_DateStructure.RTC_WeekDay = RTC_Weekday_Thursday;
	RTC_SetDate(RTC_Format_BCD, &RTC_DateStructure);
	
	/* 失能唤醒功能 */
	RTC_WakeUpCmd(DISABLE);
	
	/* 配置RTC唤醒计数器时钟 */
	RTC_WakeUpClockConfig(RTC_WakeUpClock_CK_SPRE_16bits);
	
	//设置唤醒计数器为自动重载
	RTC_SetWakeUpCounter(0);
	
	/* 使能RTC唤醒中断配置 */
	RTC_ITConfig(RTC_IT_WUT, ENABLE);
	
	/* 使能唤醒功能 */
	RTC_WakeUpCmd(ENABLE);
	
	/* 使能RTC中断 */
	RTC_ClearITPendingBit(RTC_IT_WUT);
	EXTI_ClearITPendingBit(EXTI_Line22);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line22;		//中断线22
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;//中断触发方式  上升
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;//使能中断
	EXTI_Init(&EXTI_InitStructure);
	
	/* 使能RTC实时时钟的中断通道 */
	NVIC_InitStructure.NVIC_IRQChannel = RTC_WKUP_IRQn;//RTC中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能中断
	NVIC_Init(&NVIC_InitStructure);

}

void init_rtc(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	/* 使能RTC硬件时钟 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	
	/* 允许使用RTC */
	PWR_BackupAccessCmd(ENABLE);
	
	/* 使能LSE作为时钟 */
	RCC_LSEConfig(RCC_LSE_ON);
	
	/* 等待LSE有效 */  
	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
	{
	}
	
	/* 选择RTC作为时钟源 */
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	
	/* 使能RTC硬件时钟 */
	RCC_RTCCLKCmd(ENABLE);
	
	/* 等待RTC APB寄存器就绪 */
	RTC_WaitForSynchro();
	
	RTC_ClearITPendingBit(RTC_IT_WUT);
	EXTI_ClearITPendingBit(EXTI_Line22);
	
	/* 失能唤醒功能 */
	RTC_WakeUpCmd(DISABLE);
	
	/* 配置RTC唤醒计数器时钟 */
	RTC_WakeUpClockConfig(RTC_WakeUpClock_CK_SPRE_16bits);
	
	//设置唤醒计数器为自动重载
	RTC_SetWakeUpCounter(0);
	
	/* 使能RTC唤醒中断配置 */
	RTC_ITConfig(RTC_IT_WUT, ENABLE);
	
	/* 使能唤醒功能 */
	RTC_WakeUpCmd(ENABLE);
	
	/* 使能RTC中断 */
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line22;		//中断线22
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;//中断触发方式  上升
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;//使能中断
	EXTI_Init(&EXTI_InitStructure);
	
	/* 使能RTC实时时钟的中断通道 */
	NVIC_InitStructure.NVIC_IRQChannel = RTC_WKUP_IRQn;//RTC中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能中断
	NVIC_Init(&NVIC_InitStructure);

}

void alarm_init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	RTC_AlarmTypeDef RTC_AlarmStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//闹钟A关闭
	RTC_AlarmCmd(RTC_Alarm_A, DISABLE);
	
	/* 设置闹钟 */
	
	//指定闹钟什么时间有效
#if 0	
	//指定每天有效
	RTC_AlarmStructure.RTC_AlarmMask = RTC_AlarmMask_DateWeekDay;
//	RTC_AlarmStructure.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_WeekDay;	//指定星期几有效
//	RTC_AlarmStructure.RTC_AlarmDateWeekDay = RTC_Weekday_Monday;

#endif	

#if 1	
	//指定某一天
	RTC_AlarmStructure.RTC_AlarmMask = RTC_AlarmMask_None ;
	RTC_AlarmStructure.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_Date;	//指定那一天有效
	RTC_AlarmStructure.RTC_AlarmDateWeekDay = 0x26;								//写下生效的日期
	
#endif	

#if 0	
	//指定某一个星期几
	RTC_AlarmStructure.RTC_AlarmMask = DateWeekDay ;
	RTC_AlarmStructure.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_WeekDay;		//指定星期几有效
	RTC_AlarmStructure.RTC_AlarmDateWeekDay = RTC_Weekday_Thursday;

#endif	

	RTC_AlarmStructure.RTC_AlarmTime.RTC_H12 = RTC_H12_PM;
	RTC_AlarmStructure.RTC_AlarmTime.RTC_Hours = 0x17;
	RTC_AlarmStructure.RTC_AlarmTime.RTC_Minutes =0x00;
	RTC_AlarmStructure.RTC_AlarmTime.RTC_Seconds =0x30;
	RTC_SetAlarm(RTC_Format_BCD, RTC_Alarm_A, &RTC_AlarmStructure);

	//闹钟A使能
	RTC_AlarmCmd(RTC_Alarm_A, ENABLE);
	
	EXTI_ClearITPendingBit(EXTI_Line17);
	RTC_ClearITPendingBit(RTC_IT_ALRA);
	
	/* 中断线17的配置 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line17;						//中断17
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;		//上升沿有效
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	//使能中断
	EXTI_Init(&EXTI_InitStructure);
	
	/* 配置闹钟中断优先级 */
	NVIC_InitStructure.NVIC_IRQChannel = RTC_Alarm_IRQn;		//中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	//响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	//使能中断
	NVIC_Init(&NVIC_InitStructure);
	
	
	
	/* 使能闹钟中断 */
	RTC_ITConfig(RTC_IT_ALRA, ENABLE);
	

}

 



void print_date(void)
{
	RTC_DateTypeDef RTC_DateStruct;
	//打印RTC时钟的日期跟时间
	RTC_GetDate(RTC_Format_BCD, &RTC_DateStruct);
	printf("20%02x-%02x-%02x 星期%x\r\n", RTC_DateStruct.RTC_Year, RTC_DateStruct.RTC_Month, RTC_DateStruct.RTC_Date, RTC_DateStruct.RTC_WeekDay);
}

void print_time(void)
{
	RTC_TimeTypeDef RTC_TimeStruct;
	RTC_GetTime(RTC_Format_BCD, &RTC_TimeStruct);
	printf("%02x:%02x:%02x\r\n", RTC_TimeStruct.RTC_Hours, RTC_TimeStruct.RTC_Minutes, RTC_TimeStruct.RTC_Seconds);
}



//void RTC_Alarm_IRQHandler(void)
//{
//	if(RTC_GetITStatus(RTC_IT_ALRA) == SET)//判断有没有中断产生
//	{
//		
//		PFout(8)=1;
//		delay_s(1);
//		PFout(8)=0;
//		printf("naozhong\r\n");
//		//清空中断标志位
//		RTC_ClearITPendingBit(RTC_IT_ALRA);
//		EXTI_ClearITPendingBit(EXTI_Line17);
//	}
//}




////RTC中断服务函数
//void RTC_WKUP_IRQHandler(void)
//{
//	if(RTC_GetITStatus(RTC_IT_WUT) == SET)//判断有没有中断产生
//	{
//		
//		rtc_flag = 1;	
//		
//		//清空中断标志位
//		RTC_ClearITPendingBit(RTC_IT_WUT);
//		EXTI_ClearITPendingBit(EXTI_Line22);
//	}
//}

