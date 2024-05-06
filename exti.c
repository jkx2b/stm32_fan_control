#include "exti.h"


//�ⲿ�ж�0��ʼ��
void EXTI0_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
//	�˿�AӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
//	SYSCFGӲ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
//	�������ŵĹ���ģʽ
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_0;		//����
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;		//����ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;	//����
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
//	���������ӵ��ⲿ�ж�
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	
//	�жϵĴ�����ʽ����ƽ���������ش���
	EXTI_InitStruct.EXTI_Line = EXTI_Line0; //�ⲿ�ж�0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; 	//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;		//�жϴ�����ʽ
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;				//	�����ⲿ�ж����������ж�����
	EXTI_Init(&EXTI_InitStruct);
	
//	���ȼ�������
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;		//�ⲿ�ж�0ͨ��	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;				//��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ж����ȼ�
	NVIC_Init(&NVIC_InitStruct);

}

//�ⲿ�ж�2��ʼ��
void EXTI2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
//	�˿�EӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
//	SYSCFGӲ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
//	�������ŵĹ���ģʽ
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_2;		//����
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;		//����ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;	//����
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
//	���������ӵ��ⲿ�ж�
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource2);
	
//	�жϵĴ�����ʽ����ƽ���������ش���
	EXTI_InitStruct.EXTI_Line = EXTI_Line2; //�ⲿ�ж�0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; 	//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;		//�жϴ�����ʽ
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;				//	�����ⲿ�ж����������ж�����
	EXTI_Init(&EXTI_InitStruct);
	
//	���ȼ�������
	NVIC_InitStruct.NVIC_IRQChannel = EXTI2_IRQn;		//�ⲿ�ж�0ͨ��	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;				//��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ж����ȼ�
	NVIC_Init(&NVIC_InitStruct);

}

//�ⲿ�ж�3��ʼ��
void EXTI3_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
//	�˿�EӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
//	SYSCFGӲ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
//	�������ŵĹ���ģʽ
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_3;		//����
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;		//����ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;	//����
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
//	���������ӵ��ⲿ�ж�
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);
	
//	�жϵĴ�����ʽ����ƽ���������ش���
	EXTI_InitStruct.EXTI_Line = EXTI_Line3; //�ⲿ�ж�0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; 	//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;		//�жϴ�����ʽ
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;				//	�����ⲿ�ж����������ж�����
	EXTI_Init(&EXTI_InitStruct);
	
//	���ȼ�������
	NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;		//�ⲿ�ж�0ͨ��	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;				//��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ж����ȼ�
	NVIC_Init(&NVIC_InitStruct);

}

//�ⲿ�ж�3��ʼ��
void EXTI4_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
//	�˿�EӲ��ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
//	SYSCFGӲ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
//	�������ŵĹ���ģʽ
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_4;		//����
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;		//����ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;	//����
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
//	���������ӵ��ⲿ�ж�
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);
	
//	�жϵĴ�����ʽ����ƽ���������ش���
	EXTI_InitStruct.EXTI_Line = EXTI_Line4; //�ⲿ�ж�0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; 	//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;		//�жϴ�����ʽ
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;				//	�����ⲿ�ж����������ж�����
	EXTI_Init(&EXTI_InitStruct);
	
//	���ȼ�������
	NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;		//�ⲿ�ж�0ͨ��	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;		//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;				//��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ж����ȼ�
	NVIC_Init(&NVIC_InitStruct);

}




////	�жϷ�����
//void EXTI0_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line0) != RESET)//��ȡ�ⲿ�ж�0
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

//		//���exti0���жϱ�־λ
//		EXTI_ClearITPendingBit(EXTI_Line0);
//	}
//}

////	�жϷ�����
//void EXTI2_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line2) != RESET)//��ȡ�ⲿ�ж�0
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
//		//���exti2���жϱ�־λ
//		EXTI_ClearITPendingBit(EXTI_Line2);
//	}
//}

//void EXTI3_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line3) != RESET)//��ȡ�ⲿ�ж�0
//	{
//		
//		PEout(13) = 0;
//		delay_ms(500);
//		
//		PEout(13) = 1;
//		
//		
//		//���exti3���жϱ�־λ
//		EXTI_ClearITPendingBit(EXTI_Line3);
//	}
//}

//void EXTI4_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line4) != RESET)//��ȡ�ⲿ�ж�0
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
//		//���exti3���жϱ�־λ
//		EXTI_ClearITPendingBit(EXTI_Line4);
//	}
//}

