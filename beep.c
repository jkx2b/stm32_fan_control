#include"beep.h"

void BEEP_Init(void)
{
	// GPIO��ʼ���Ľṹ��
	GPIO_InitTypeDef GPIO_InitStruct;
	

	// 1��ʹ��Ӳ��ʱ��   GPIOF9��Ӳ��ʱ��   AHB1
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	

	// 2��Ӳ������  GPIOF9
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8; // ����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;			 // ���ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 // �ٶ�
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // �������
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;		 // ����������
	
	
	
	GPIO_Init(GPIOF, &GPIO_InitStruct);

	
}
