#include"led.h"


void LED_Init(void)
{
	// GPIO��ʼ���Ľṹ��
	GPIO_InitTypeDef GPIO_InitStruct;
	

	// 1��ʹ��Ӳ��ʱ��   GPIOF9��Ӳ��ʱ��   AHB1
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	

	// 2��Ӳ������  GPIOF9
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10 ;// ����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;			 // ���ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 // �ٶ�
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // �������
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;		 // ����������
	
	
	
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	
	PCout(10)=1;

	
}


//void LED_Init(void)
//{
//	// GPIO��ʼ���Ľṹ��
//	GPIO_InitTypeDef GPIO_InitStruct;
//	

//	// 1��ʹ��Ӳ��ʱ��   GPIOF9��Ӳ��ʱ��   AHB1
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
//	

//	// 2��Ӳ������  GPIOF9
//	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_8; // ����
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;			 // ���ģʽ
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 // �ٶ�
//	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // �������
//	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;		 // ����������
//	
//	
//	
//	GPIO_Init(GPIOF, &GPIO_InitStruct);

//	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
//	GPIO_Init(GPIOE, &GPIO_InitStruct);
//	
//	PFout(10)=1;
//	PFout(9)=1;
//	PEout(13)=1;
//	PEout(14)=1;

//	
//}

