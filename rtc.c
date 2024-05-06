#include "rtc.h"


void rtc_init(void)
{
	RTC_DateTypeDef RTC_DateStructure;
	RTC_InitTypeDef RTC_InitStructure;
	RTC_TimeTypeDef RTC_TimeStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	/* ʹ��RTCӲ��ʱ�� */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	
	/* ����ʹ��RTC */
	PWR_BackupAccessCmd(ENABLE);
	
	/* ʹ��LSE��Ϊʱ�� */
	RCC_LSEConfig(RCC_LSE_ON);
	
	/* �ȴ�LSE��Ч */  
	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
	{
	}
	
	/* ѡ��RTC��Ϊʱ��Դ */
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	
	/* ʹ��RTCӲ��ʱ�� */
	RCC_RTCCLKCmd(ENABLE);
	
	/* �ȴ�RTC APB�Ĵ������� */
	RTC_WaitForSynchro();
	
	/* ����RTC���첽��Ƶ��ͬ����Ƶ��Сʱ�� */
	RTC_InitStructure.RTC_AsynchPrediv = 0x7F;				//�첽��Ƶ
	RTC_InitStructure.RTC_SynchPrediv = 0xFF;				//ͬ����Ƶ
	RTC_InitStructure.RTC_HourFormat = RTC_HourFormat_24;	//24Сʱ��
	RTC_Init(&RTC_InitStructure);
	
	/* ����ʱ�� */
	RTC_TimeStructure.RTC_H12     = RTC_H12_PM;	//AM����  PM����
	RTC_TimeStructure.RTC_Hours   = 0x17;
	RTC_TimeStructure.RTC_Minutes = 0x00;
	RTC_TimeStructure.RTC_Seconds = 0x00; 
	RTC_SetTime(RTC_Format_BCD, &RTC_TimeStructure);   
	
	/* ��������: Friday January 11th 2013 */
	RTC_DateStructure.RTC_Year = 0x23;
	RTC_DateStructure.RTC_Month = RTC_Month_October;
	RTC_DateStructure.RTC_Date = 0x26;
	RTC_DateStructure.RTC_WeekDay = RTC_Weekday_Thursday;
	RTC_SetDate(RTC_Format_BCD, &RTC_DateStructure);
	
	/* ʧ�ܻ��ѹ��� */
	RTC_WakeUpCmd(DISABLE);
	
	/* ����RTC���Ѽ�����ʱ�� */
	RTC_WakeUpClockConfig(RTC_WakeUpClock_CK_SPRE_16bits);
	
	//���û��Ѽ�����Ϊ�Զ�����
	RTC_SetWakeUpCounter(0);
	
	/* ʹ��RTC�����ж����� */
	RTC_ITConfig(RTC_IT_WUT, ENABLE);
	
	/* ʹ�ܻ��ѹ��� */
	RTC_WakeUpCmd(ENABLE);
	
	/* ʹ��RTC�ж� */
	RTC_ClearITPendingBit(RTC_IT_WUT);
	EXTI_ClearITPendingBit(EXTI_Line22);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line22;		//�ж���22
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж�ģʽ
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;//�жϴ�����ʽ  ����
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;//ʹ���ж�
	EXTI_Init(&EXTI_InitStructure);
	
	/* ʹ��RTCʵʱʱ�ӵ��ж�ͨ�� */
	NVIC_InitStructure.NVIC_IRQChannel = RTC_WKUP_IRQn;//RTC�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//��Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ж�
	NVIC_Init(&NVIC_InitStructure);

}

void init_rtc(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	/* ʹ��RTCӲ��ʱ�� */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	
	/* ����ʹ��RTC */
	PWR_BackupAccessCmd(ENABLE);
	
	/* ʹ��LSE��Ϊʱ�� */
	RCC_LSEConfig(RCC_LSE_ON);
	
	/* �ȴ�LSE��Ч */  
	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
	{
	}
	
	/* ѡ��RTC��Ϊʱ��Դ */
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	
	/* ʹ��RTCӲ��ʱ�� */
	RCC_RTCCLKCmd(ENABLE);
	
	/* �ȴ�RTC APB�Ĵ������� */
	RTC_WaitForSynchro();
	
	RTC_ClearITPendingBit(RTC_IT_WUT);
	EXTI_ClearITPendingBit(EXTI_Line22);
	
	/* ʧ�ܻ��ѹ��� */
	RTC_WakeUpCmd(DISABLE);
	
	/* ����RTC���Ѽ�����ʱ�� */
	RTC_WakeUpClockConfig(RTC_WakeUpClock_CK_SPRE_16bits);
	
	//���û��Ѽ�����Ϊ�Զ�����
	RTC_SetWakeUpCounter(0);
	
	/* ʹ��RTC�����ж����� */
	RTC_ITConfig(RTC_IT_WUT, ENABLE);
	
	/* ʹ�ܻ��ѹ��� */
	RTC_WakeUpCmd(ENABLE);
	
	/* ʹ��RTC�ж� */
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line22;		//�ж���22
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж�ģʽ
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;//�жϴ�����ʽ  ����
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;//ʹ���ж�
	EXTI_Init(&EXTI_InitStructure);
	
	/* ʹ��RTCʵʱʱ�ӵ��ж�ͨ�� */
	NVIC_InitStructure.NVIC_IRQChannel = RTC_WKUP_IRQn;//RTC�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//��Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ж�
	NVIC_Init(&NVIC_InitStructure);

}

void alarm_init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	RTC_AlarmTypeDef RTC_AlarmStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//����A�ر�
	RTC_AlarmCmd(RTC_Alarm_A, DISABLE);
	
	/* �������� */
	
	//ָ������ʲôʱ����Ч
#if 0	
	//ָ��ÿ����Ч
	RTC_AlarmStructure.RTC_AlarmMask = RTC_AlarmMask_DateWeekDay;
//	RTC_AlarmStructure.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_WeekDay;	//ָ�����ڼ���Ч
//	RTC_AlarmStructure.RTC_AlarmDateWeekDay = RTC_Weekday_Monday;

#endif	

#if 1	
	//ָ��ĳһ��
	RTC_AlarmStructure.RTC_AlarmMask = RTC_AlarmMask_None ;
	RTC_AlarmStructure.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_Date;	//ָ����һ����Ч
	RTC_AlarmStructure.RTC_AlarmDateWeekDay = 0x26;								//д����Ч������
	
#endif	

#if 0	
	//ָ��ĳһ�����ڼ�
	RTC_AlarmStructure.RTC_AlarmMask = DateWeekDay ;
	RTC_AlarmStructure.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_WeekDay;		//ָ�����ڼ���Ч
	RTC_AlarmStructure.RTC_AlarmDateWeekDay = RTC_Weekday_Thursday;

#endif	

	RTC_AlarmStructure.RTC_AlarmTime.RTC_H12 = RTC_H12_PM;
	RTC_AlarmStructure.RTC_AlarmTime.RTC_Hours = 0x17;
	RTC_AlarmStructure.RTC_AlarmTime.RTC_Minutes =0x00;
	RTC_AlarmStructure.RTC_AlarmTime.RTC_Seconds =0x30;
	RTC_SetAlarm(RTC_Format_BCD, RTC_Alarm_A, &RTC_AlarmStructure);

	//����Aʹ��
	RTC_AlarmCmd(RTC_Alarm_A, ENABLE);
	
	EXTI_ClearITPendingBit(EXTI_Line17);
	RTC_ClearITPendingBit(RTC_IT_ALRA);
	
	/* �ж���17������ */
	EXTI_InitStructure.EXTI_Line = EXTI_Line17;						//�ж�17
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//�ж�ģʽ
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;		//��������Ч
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	//ʹ���ж�
	EXTI_Init(&EXTI_InitStructure);
	
	/* ���������ж����ȼ� */
	NVIC_InitStructure.NVIC_IRQChannel = RTC_Alarm_IRQn;		//�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	//��Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	//ʹ���ж�
	NVIC_Init(&NVIC_InitStructure);
	
	
	
	/* ʹ�������ж� */
	RTC_ITConfig(RTC_IT_ALRA, ENABLE);
	

}

 



void print_date(void)
{
	RTC_DateTypeDef RTC_DateStruct;
	//��ӡRTCʱ�ӵ����ڸ�ʱ��
	RTC_GetDate(RTC_Format_BCD, &RTC_DateStruct);
	printf("20%02x-%02x-%02x ����%x\r\n", RTC_DateStruct.RTC_Year, RTC_DateStruct.RTC_Month, RTC_DateStruct.RTC_Date, RTC_DateStruct.RTC_WeekDay);
}

void print_time(void)
{
	RTC_TimeTypeDef RTC_TimeStruct;
	RTC_GetTime(RTC_Format_BCD, &RTC_TimeStruct);
	printf("%02x:%02x:%02x\r\n", RTC_TimeStruct.RTC_Hours, RTC_TimeStruct.RTC_Minutes, RTC_TimeStruct.RTC_Seconds);
}



//void RTC_Alarm_IRQHandler(void)
//{
//	if(RTC_GetITStatus(RTC_IT_ALRA) == SET)//�ж���û���жϲ���
//	{
//		
//		PFout(8)=1;
//		delay_s(1);
//		PFout(8)=0;
//		printf("naozhong\r\n");
//		//����жϱ�־λ
//		RTC_ClearITPendingBit(RTC_IT_ALRA);
//		EXTI_ClearITPendingBit(EXTI_Line17);
//	}
//}




////RTC�жϷ�����
//void RTC_WKUP_IRQHandler(void)
//{
//	if(RTC_GetITStatus(RTC_IT_WUT) == SET)//�ж���û���жϲ���
//	{
//		
//		rtc_flag = 1;	
//		
//		//����жϱ�־λ
//		RTC_ClearITPendingBit(RTC_IT_WUT);
//		EXTI_ClearITPendingBit(EXTI_Line22);
//	}
//}

