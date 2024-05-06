#include "pwm.h"


void PWM_TIM14_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʱ��14Ӳ��ʱ��ʹ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);
	
	//GPIOFӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//PF9��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			//���ű��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�������
	
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	//��PF9���Ű󶨵�TIM14
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource9, GPIO_AF_TIM14);

	//��ʱ��14����
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	
	TIM_TimeBaseInit(TIM14, &TIM_TimeBaseStructure);
	
	//TIM14��ʱ��ͨ��1���������
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM���ģʽ1������͵�ƽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//ʹ��PWM	�������
	TIM_OCInitStructure.TIM_Pulse = 100;		//�Ƚ�ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//�ߵ�ƽ��Ч״̬���͵�ƽ��Ч״̬
	
	TIM_OC1Init(TIM14, &TIM_OCInitStructure);
	
	//ʹ�ܶ�ʱ��14����
	TIM_Cmd(TIM14, ENABLE);
	
	
}

void PWM_TIM13_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʱ��14Ӳ��ʱ��ʹ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13, ENABLE);
	
	//GPIOFӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//PF9��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			//���ű��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�������
	
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	//��PF9���Ű󶨵�TIM14
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource8, GPIO_AF_TIM13);

	//��ʱ��14����
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	
	TIM_TimeBaseInit(TIM13, &TIM_TimeBaseStructure);
	
	//TIM14��ʱ��ͨ��1���������
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM���ģʽ1������͵�ƽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//ʹ��PWM	�������
	TIM_OCInitStructure.TIM_Pulse = 100;		//�Ƚ�ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//�ߵ�ƽ��Ч״̬���͵�ƽ��Ч״̬
	
	TIM_OC1Init(TIM13, &TIM_OCInitStructure);
	
	//ʹ�ܶ�ʱ��14����
	TIM_Cmd(TIM13, ENABLE);
	
	
}

void PWM_TIM1_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʱ��14Ӳ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	//GPIOFӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	//PF9��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;			//���ű��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�������
	
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	//��PF9���Ű󶨵�TIM14
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);

	//��ʱ��14����
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 16800-1;		//Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	//TIM14��ʱ��ͨ��1���������
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM���ģʽ1������͵�ƽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//ʹ��PWM	�������
	TIM_OCInitStructure.TIM_Pulse = 100;		//�Ƚ�ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//�ߵ�ƽ��Ч״̬���͵�ƽ��Ч״̬
	
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	
	//ʹ�ܶ�ʱ��14����
	TIM_Cmd(TIM1, ENABLE);
	
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
	
}

void PWM_TIM1_Init_pa8(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʱ��14Ӳ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	//GPIOFӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	//PF9��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			//���ű��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�������
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//��PF9���Ű󶨵�TIM14
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);

	//��ʱ��14����
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 16800-1;		//Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	//TIM14��ʱ��ͨ��1���������
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM���ģʽ1������͵�ƽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//ʹ��PWM	�������
	TIM_OCInitStructure.TIM_Pulse = 100;		//�Ƚ�ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;		//�ߵ�ƽ��Ч״̬���͵�ƽ��Ч״̬
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	
	//ʹ�ܶ�ʱ��14����
	TIM_Cmd(TIM1, ENABLE);
	
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
	
}

void PWM_TIM3_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʱ��14Ӳ��ʱ��ʹ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//GPIOFӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	//PF9��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			//���ű��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�������
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	//��PF9���Ű󶨵�TIM14
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);

	//��ʱ��14����
	TIM_TimeBaseStructure.TIM_Period = 100-1;			//����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	//TIM14��ʱ��ͨ��1���������
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM���ģʽ1������͵�ƽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//ʹ��PWM	�������
	TIM_OCInitStructure.TIM_Pulse = 100;		//�Ƚ�ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//�ߵ�ƽ��Ч״̬���͵�ƽ��Ч״̬
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	
	//ʹ�ܶ�ʱ��14����
	TIM_Cmd(TIM3, ENABLE);
	
	
}

void PWM_TIM4_Init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʱ��4Ӳ��ʱ��ʹ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	//GPIODӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	//PF9��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;			//���ű��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�������
	
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	//��PF9���Ű󶨵�TIM14
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);

	//��ʱ��14����
	TIM_TimeBaseStructure.TIM_Period = 200-1;			//����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	//TIM14��ʱ��ͨ��1���������
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//PWM���ģʽ1������͵�ƽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//ʹ��PWM	�������
	TIM_OCInitStructure.TIM_Pulse = 100;		//�Ƚ�ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//�ߵ�ƽ��Ч״̬���͵�ƽ��Ч״̬
	
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	
	//ʹ�ܶ�ʱ��14����
	TIM_Cmd(TIM4, ENABLE);
	
	
}

