#include "usart.h"
#include "stdio.h"
#include "string.h"


u16 USART_RX_STA=0;       //����״̬���	  
u16 USART_RX_LEN=0;
u16 USART_STA=0;
u8 USART_RX_BUF[USART_REC_LEN];     //���ջ���,���USART_REC_LEN���ֽ�.




void USART1_Init(uint32_t bps)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//ʹ��GPIOA��Ӳ��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	/* ʹ�ܴ���1Ӳ��ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	/* GPIOA9��10�������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* ����GPIOA9 GPIOA10����Ϊ����1 */ 
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	//��ʼ�����ڲ����ʣ�����λ��ֹͣλ��У��λ������
	USART_InitStructure.USART_BaudRate = bps;			//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;	//����λ8bit
	USART_InitStructure.USART_StopBits = USART_StopBits_1;	//ֹͣλ1λ
	USART_InitStructure.USART_Parity = USART_Parity_No;	//����żУ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//��Ӳ������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�����ڷ������ݣ���������
	USART_Init(USART1, &USART_InitStructure);
	
	//�����ж�
	//���ô���1�жϵĴ�����ʽ
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	//���ô����ж�
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;		//����1���ж�	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;		//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;				//��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ж����ȼ�
	NVIC_Init(&NVIC_InitStruct);
	
	//ʹ�ܴ���1��ʼ����
	USART_Cmd(USART1, ENABLE);
}

void USART2_Init(uint32_t bps)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//ʹ��GPIOA��Ӳ��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	/* ʹ�ܴ���2Ӳ��ʱ�� */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	/* GPIOA2��3�������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* ����GPIOA2 GPIOA3����Ϊ����2 */ 
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	
	//��ʼ�����ڲ����ʣ�����λ��ֹͣλ��У��λ������
	USART_InitStructure.USART_BaudRate = bps;										//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;						//����λ8bit
	USART_InitStructure.USART_StopBits = USART_StopBits_1;							//ֹͣλ1λ
	USART_InitStructure.USART_Parity = USART_Parity_No;								//����żУ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//��Ӳ������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//�����ڷ������ݣ���������
	USART_Init(USART2, &USART_InitStructure);
	
	//�����ж�
	//���ô���1�жϵĴ�����ʽ
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	
	//���ô����ж�
	NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;		//����2���ж�	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;		//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;				//��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ж����ȼ�
	NVIC_Init(&NVIC_InitStruct);
	
	//ʹ�ܴ���2��ʼ����
	USART_Cmd(USART2, ENABLE);
}

void USART3_Init(uint32_t bps)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//ʹ��GPIOA��Ӳ��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	/* ʹ�ܴ���3Ӳ��ʱ�� */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
	/* GPIOA2��3�������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* ����GPIOA2 GPIOA3����Ϊ����2 */ 
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
	
	//��ʼ�����ڲ����ʣ�����λ��ֹͣλ��У��λ������
	USART_InitStructure.USART_BaudRate = bps;										//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;						//����λ8bit
	USART_InitStructure.USART_StopBits = USART_StopBits_1;							//ֹͣλ1λ
	USART_InitStructure.USART_Parity = USART_Parity_No;								//����żУ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//��Ӳ������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//�����ڷ������ݣ���������
	USART_Init(USART3, &USART_InitStructure);
	
	//�����ж�
	//���ô���1�жϵĴ�����ʽ
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	
	//���ô����ж�
	NVIC_InitStruct.NVIC_IRQChannel = USART3_IRQn;		//����2���ж�	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;		//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;				//��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ж����ȼ�
	NVIC_Init(&NVIC_InitStruct);
	
	//ʹ�ܴ���3��ʼ����
	USART_Cmd(USART3, ENABLE);
}

void USART3_SendData(u8 data)
{
	while((USART3->SR&0X40)==0); 
	USART3->DR = data;
}

//����3���жϷ�����
void USART3_IRQHandler(void)
{
	
	u8 Res;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) == SET)//�ж������жϲ���   ���жϲ�����ʾ��������
	{
		//printf("fan=%d\r\n",Res);
		Res =USART_ReceiveData(USART3);	//��ȡ���յ�������
		if((USART_RX_STA&0x8000)==0)//����δ���
		{
			if(Res==0XFE)//���յ�����ͷ
			{
				USART_STA=1;
				USART_RX_LEN=0;
			}
		  if(USART_STA)
			{
				USART_RX_BUF[USART_RX_LEN]=Res;
				USART_RX_LEN++;
				if(USART_RX_LEN>8)//����8λ���ݽ������
				{
					USART_STA=0;
					USART_RX_STA|=0x8000;//���������
				}
			}
		}   		
		
		//����жϱ�־λ
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
	}
}


void send_char(uint16_t c)
{
	USART_SendData(USART1, c);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void send_str(char *str)
{
	while(*str!='\0')
	{
		send_char(*str);
		str++;
	}
}

void send2_char(uint16_t c)
{
	USART_SendData(USART2, c);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}

void send2_str(char *str)
{
	while(*str!='\0')
	{
		send2_char(*str);
		str++;
	}
}

void send3_char(uint16_t c)
{
	USART_SendData(USART3, c);
	while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
}

void send3_str(char *str)
{
	while(*str!='\0')
	{
		send3_char(*str);
		str++;
	}
}

