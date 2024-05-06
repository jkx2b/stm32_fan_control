#include "timer.h"

//��ʱ��3��ʼ��
void TIME3_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//1��ʹ��Ӳ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//2��Ӳ������
	TIM_TimeBaseInitStruct.TIM_Period = (10000-1);		//��������ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler = 8400-1;		//Ԥ��Ƶֵ
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;		//���ϼ���

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);
	
	//���ö�ʱ��3�жϴ�����ʽ��ʱ�����
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	//�жϣ��ж����ȼ�   ��ռ���ȼ�����Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;		//�ⲿ�ж�2ͨ��	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;				//��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ж����ȼ�
	NVIC_Init(&NVIC_InitStruct);
	
	//ʹ�ܶ�ʱ������
	TIM_Cmd(TIM3, ENABLE);
	
}

//��ʱ��1��ʼ��
void TIME1_Init()
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//1��ʹ��Ӳ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	//2��Ӳ������
	TIM_TimeBaseInitStruct.TIM_Period = (10000-1)/2;		//��������ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler = 16800-1;		//Ԥ��Ƶֵ
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;		//���ϼ���

	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStruct);
	
	//���ö�ʱ��1�жϴ�����ʽ��ʱ�����
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	
	//�жϣ��ж����ȼ�   ��ռ���ȼ�����Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;		//�ⲿ�ж�1ͨ��	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;				//��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ж����ȼ�
	NVIC_Init(&NVIC_InitStruct);
	
	//ʹ�ܶ�ʱ������
	TIM_Cmd(TIM1, ENABLE);
	
}


