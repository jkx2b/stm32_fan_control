#include"key.h"


void KEY_Init(void)
{
	// GPIO��ʼ���Ľṹ��
	GPIO_InitTypeDef GPIO_InitStruct;
	

	// 1��ʹ��Ӳ��ʱ��   GPIOF9��Ӳ��ʱ��   AHB1
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0; // ����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;			 // ���ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 // �ٶ�
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // �������
	//GPIO_InitStruct1.GPIO_PuPd = GPIO_PuPd_UP;		 // ����
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;		 // ����
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	
}

void PA8_Init(void)
{
	// GPIO��ʼ���Ľṹ��
	GPIO_InitTypeDef GPIO_InitStruct;
	

	// 1��ʹ��Ӳ��ʱ��   GPIOF9��Ӳ��ʱ��   AHB1
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8; // ����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;			 // ���ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 // �ٶ�
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // �������
	//GPIO_InitStruct1.GPIO_PuPd = GPIO_PuPd_UP;		 // ����
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;		 // ����
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9; // ����
	GPIO_Init(GPIOG, &GPIO_InitStruct);
	
}

