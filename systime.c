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

//ϵͳ�δ�ʱ��
//��ʱ1ms����
void delay_ms(uint16_t i)
{
	while(i--)
	{
		SysTick->CTRL = 0; 			//�ر�ϵͳ��ʱ��
		SysTick->LOAD = 168000-1;		//����ֵ��װ��
		SysTick->VAL = 0; 			//�����ǰֵ�ͼ�����־
		SysTick->CTRL = 5; 			//ʹ�ܶ�ʱ����д����ƺ�״̬�Ĵ���
		while ((SysTick->CTRL & 0x00010000)==0);//�ȴ�����ֵ��0���������ü�����־������ֵ��װ��
	}	
	SysTick->CTRL = 0; 			//�ر�ϵͳ��ʱ��
}

//��ʱ1us����
void delay_us(uint16_t i)
{
	while(i--)
	{
		SysTick->CTRL = 0; 			//�ر�ϵͳ��ʱ��
		SysTick->LOAD = 168-1;		//����ֵ��װ��
		SysTick->VAL = 0; 			//�����ǰֵ�ͼ�����־
		SysTick->CTRL = 5; 			//ʹ�ܶ�ʱ����д����ƺ�״̬�Ĵ���
		while ((SysTick->CTRL & 0x00010000)==0);//�ȴ�����ֵ��0���������ü�����־������ֵ��װ��
	}	
	SysTick->CTRL = 0; 			//�ر�ϵͳ��ʱ��
}

//��ʱ1s����
void delay_s(uint16_t i)
{
	delay_ms(i*1000);
}


/*
//SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
//��ʱ1ms����
void delay_ms(uint16_t i)
{
	while(i--)
	{
		SysTick->CTRL = 0; 			//�ر�ϵͳ��ʱ��
		SysTick->LOAD = 21000-1;		//����ֵ��װ��
		SysTick->VAL = 0; 			//�����ǰֵ�ͼ�����־
		SysTick->CTRL = 1; 			//ʹ�ܶ�ʱ����д����ƺ�״̬�Ĵ���
		while ((SysTick->CTRL & 0x00010000)==0);//�ȴ�����ֵ��0���������ü�����־������ֵ��װ��
	}	
	SysTick->CTRL = 0; 			//�ر�ϵͳ��ʱ��
}

//��ʱ1us����
void delay_us(uint16_t i)
{
	while(i--)
	{
		SysTick->CTRL = 0; 			//�ر�ϵͳ��ʱ��
		SysTick->LOAD = 21-1;		//����ֵ��װ��
		SysTick->VAL = 0; 			//�����ǰֵ�ͼ�����־
		SysTick->CTRL = 1; 			//ʹ�ܶ�ʱ����д����ƺ�״̬�Ĵ���
		while ((SysTick->CTRL & 0x00010000)==0);//�ȴ�����ֵ��0���������ü�����־������ֵ��װ��
	}	
	SysTick->CTRL = 0; 			//�ر�ϵͳ��ʱ��
}

//��ʱ1s����
void delay_s(uint16_t i)
{
	delay_ms(i*1000);
}
*/

